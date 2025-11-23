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

    if (dx == 0)
    { // vertical line
        int ys = (y0 < y1) ? y0 : y1;
        int ye = (y0 < y1) ? y1 : y0;
        for (int y = ys; y <= ye; ++y)
            putpixel(x0, y, WHITE);
    }
    else if (dy == 0)
    { // horizontal
        int xs = (x0 < x1) ? x0 : x1;
        int xe = (x0 < x1) ? x1 : x0;
        for (int x = xs; x <= xe; ++x)
            putpixel(x, y0, WHITE);
    }
    else
    {
        double m = (double)dy / (double)dx;
        if (fabs(m) <= 1.0)
        {
            int xs = (x0 < x1) ? x0 : x1;
            int xe = (x0 < x1) ? x1 : x0;
            int base = (x0 < x1) ? x0 : x1;
            int otherY = (x0 < x1) ? y0 : y1;
            for (int x = xs; x <= xe; ++x)
            {
                double y = otherY + m * (x - base);
                putpixel(x, (int)round(y), WHITE);
            }
        }
        else
        {
            double invm = (double)dx / (double)dy;
            int ys = (y0 < y1) ? y0 : y1;
            int ye = (y0 < y1) ? y1 : y0;
            int baseY = (y0 < y1) ? y0 : y1;
            int otherX = (y0 < y1) ? x0 : x1;
            for (int y = ys; y <= ye; ++y)
            {
                double x = otherX + invm * (y - baseY);
                putpixel((int)round(x), y, WHITE);
            }
        }
    }

    getch();
    closegraph();
    return 0;
}
