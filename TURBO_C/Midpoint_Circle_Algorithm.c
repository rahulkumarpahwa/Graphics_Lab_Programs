/*
 * Midpoint Circle Drawing Algorithm
 */

#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void midpoint_circle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 1- r; // Decision parameter

    while (x <= y)
    {
        // Draw all 8 symmetric points
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (d < 0)
        {
            d = d + 2 * x + 1;
        }
        else
        {
            d = d + 2 * (x - y) + 1;
            y--;
        }
        x++;
    }
}

int main()
{
    int gdriver = DETECT, gmode;

    // Initialize graphics mode
    initgraph(&gdriver, &gmode, "C:\\MINGW\\lib\\libbgi");

    int max_x = getmaxx();
    int max_y = getmaxy();

    // Clear screen
    cleardevice();

    // Draw circles with different radii and colors
    midpoint_circle(max_x / 2, max_y / 2, 50);

    // Display info
    setcolor(YELLOW);
    outtextxy(20, max_y - 40, "Press any key to exit...");

    getch();
    closegraph();

    return 0;
}
