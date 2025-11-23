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
    int d = 3 - 2 * r;
    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        if (d < 0)
            d = d + 4 * x + 6;
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
    initgraph(&gdriver, &gmode, "");
    int max_x = getmaxx();
    int max_y = getmaxy();
    cleardevice();
    setcolor(YELLOW);
    outtextxy(max_x / 2 - 100, 20, "Midpoint Circle Drawing Algorithm");
    setcolor(WHITE);
    midpoint_circle(max_x / 2, max_y / 2, 50);
    setcolor(RED);
    midpoint_circle(max_x / 2, max_y / 2, 100);
    setcolor(GREEN);
    midpoint_circle(max_x / 2, max_y / 2, 150);
    setcolor(CYAN);
    midpoint_circle(max_x / 2, max_y / 2, 200);
    setcolor(YELLOW);
    outtextxy(20, max_y - 40, "Press any key to exit...");
    getch();
    closegraph();
    return 0;
}
