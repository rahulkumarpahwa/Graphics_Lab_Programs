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
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int x = x0;
    int y = y0;
    while (1)
    {
        putpixel(x, y, WHITE);
        if (x == x1 && y == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
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
    outtextxy(max_x / 2 - 120, 20, "Bresenham Line Drawing Algorithm");
    setcolor(WHITE);
    bresenham_line(50, 50, 300, 300);
    setcolor(RED);
    bresenham_line(400, 100, 600, 300);
    setcolor(GREEN);
    bresenham_line(100, 200, 500, 200);
    setcolor(CYAN);
    bresenham_line(200, 100, 200, 400);
    setcolor(MAGENTA);
    bresenham_line(50, 400, 600, 100);
    setcolor(LIGHTBLUE);
    bresenham_line(600, 400, 100, 100);
    setcolor(YELLOW);
    outtextxy(20, max_y - 40, "Press any key to exit...");
    getch();
    closegraph();
    return 0;
}
