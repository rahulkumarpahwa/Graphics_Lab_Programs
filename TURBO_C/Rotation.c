#include "graphics.h"
#include <conio.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

void rotate_point(int xc, int yc, int x, int y, double angle_deg, int *rx, int *ry)
{
    double angle = angle_deg * PI / 180.0;
    double s = sin(angle), c = cos(angle);
    double tx = x - xc;
    double ty = y - yc;
    double nx = tx * c - ty * s;
    double ny = tx * s + ty * c;
    *rx = (int)round(nx + xc);
    *ry = (int)round(ny + yc);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xc, yc, x, y;
    double angle;
    printf("Enter center xc yc and point x y and angle (deg): ");
    if (scanf("%d %d %d %d %lf", &xc, &yc, &x, &y, &angle) != 5)
    {
        closegraph();
        return 0;
    }
    int rx, ry;
    rotate_point(xc, yc, x, y, angle, &rx, &ry);
    setcolor(WHITE);
    putpixel(x, y, RED);
    putpixel(rx, ry, GREEN);
    line(xc, yc, x, y);
    line(xc, yc, rx, ry);
    getch();
    closegraph();
    return 0;
}
