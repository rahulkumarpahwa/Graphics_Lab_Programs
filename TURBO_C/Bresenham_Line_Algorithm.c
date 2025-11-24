/*
 * Bresenham Line Drawing Algorithm
 */

#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void bresenham_line(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int d = (2 * dy) - dx;
    int x = x0;
    int y = y0;
    while (1)
    {
        putpixel(x, y, GREEN);
        if (x == x1 && y == y1)
            break;
        if(d<0){
            d = d + 2 * dy;
        } else {
            d = d + 2* (dy -dx);
            y++;
        }
        x++;
    }
}

int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
    cleardevice();
    bresenham_line(50, 50, 300, 300);
    outtextxy(20, getmaxy() - 40, "Press any key to exit...");
    getch();
    closegraph();
    return 0;
}
