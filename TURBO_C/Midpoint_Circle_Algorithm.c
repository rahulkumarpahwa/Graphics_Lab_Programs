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
    int d = 3 - 2 * r; // Decision parameter

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
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
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

    if (graphresult() != grOk)
    {
        printf("Graphics initialization failed\n");
        return -1;
    }

    int max_x = getmaxx();
    int max_y = getmaxy();

    // Clear screen
    cleardevice();

    // Draw title
    setcolor(YELLOW);
    outtextxy(max_x / 2 - 100, 20, "Midpoint Circle Drawing Algorithm");

    // Draw circles with different radii and colors
    setcolor(WHITE);
    midpoint_circle(max_x / 2, max_y / 2, 50);

    setcolor(RED);
    midpoint_circle(max_x / 2, max_y / 2, 100);

    setcolor(GREEN);
    midpoint_circle(max_x / 2, max_y / 2, 150);

    setcolor(CYAN);
    midpoint_circle(max_x / 2, max_y / 2, 200);

    setcolor(MAGENTA);
    midpoint_circle(150, 150, 80);

    setcolor(LIGHTBLUE);
    midpoint_circle(max_x - 150, 150, 80);

    setcolor(LIGHTGREEN);
    midpoint_circle(150, max_y - 150, 80);

    setcolor(YELLOW);
    midpoint_circle(max_x - 150, max_y - 150, 80);

    // Display info
    setcolor(YELLOW);
    outtextxy(20, max_y - 40, "Press any key to exit...");

    getch();
    closegraph();

    return 0;
}
