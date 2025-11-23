#include "graphics.h"
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0, y0, x1, y1;
    printf("Enter x0 y0 x1 y1: ");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);

    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    if (steps == 0)
    {
        putpixel(x0, y0, WHITE);
    }
    else
    {
        double xincr = (double)dx / (double)steps;
        double yincr = (double)dy / (double)steps;
        double x = x0, y = y0;
        for (int i = 0; i <= steps; ++i)
        {
            putpixel((int)round(x), (int)round(y), WHITE);
            x += xincr;
            y += yincr;
        }
    }

    getch();
    closegraph();
    return 0;
}
