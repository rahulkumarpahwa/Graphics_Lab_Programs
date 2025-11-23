#include "graphics.h"
#include <conio.h>
#include <stdio.h>
#include <math.h>

void scale_point(int xc, int yc, int x, int y, double sx, double sy, int *sx_out, int *sy_out)
{
    double tx = x - xc;
    double ty = y - yc;
    double nx = tx * sx;
    double ny = ty * sy;
    *sx_out = (int)round(nx + xc);
    *sy_out = (int)round(ny + yc);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xc, yc, x, y;
    double sx, sy;
    printf("Enter center xc yc and point x y and scale sx sy: ");
    if (scanf("%d %d %d %d %lf %lf", &xc, &yc, &x, &y, &sx, &sy) != 6)
    {
        closegraph();
        return 0;
    }
    int rx, ry;
    scale_point(xc, yc, x, y, sx, sy, &rx, &ry);
    setcolor(WHITE);
    putpixel(x, y, RED);
    putpixel(rx, ry, GREEN);
    line(xc, yc, x, y);
    line(xc, yc, rx, ry);
    getch();
    closegraph();
    return 0;
}
