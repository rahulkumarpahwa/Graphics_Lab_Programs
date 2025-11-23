#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void rotate_point(double xc, double yc, double x, double y, double angle_deg, double *rx, double *ry)
{
    double angle = angle_deg * M_PI / 180.0;
    double s = sin(angle), c = cos(angle);
    double tx = x - xc;
    double ty = y - yc;
    double nx = tx * c - ty * s;
    double ny = tx * s + ty * c;
    *rx = nx + xc;
    *ry = ny + yc;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    double x1, y1, x2, y2, x3, y3, xc, yc, angle;
    printf("Enter triangle points x1 y1 x2 y2 x3 y3 and center xc yc and angle: ");
    if (scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &xc, &yc, &angle) != 9)
    {
        closegraph();
        return 0;
    }
    double rx1, ry1, rx2, ry2, rx3, ry3;
    rotate_point(xc, yc, x1, y1, angle, &rx1, &ry1);
    rotate_point(xc, yc, x2, y2, angle, &rx2, &ry2);
    rotate_point(xc, yc, x3, y3, angle, &rx3, &ry3);
    setcolor(WHITE);
    line((int)round(x1), (int)round(y1), (int)round(x2), (int)round(y2));
    line((int)round(x2), (int)round(y2), (int)round(x3), (int)round(y3));
    line((int)round(x3), (int)round(y3), (int)round(x1), (int)round(y1));
    setcolor(GREEN);
    line((int)round(rx1), (int)round(ry1), (int)round(rx2), (int)round(ry2));
    line((int)round(rx2), (int)round(ry2), (int)round(rx3), (int)round(ry3));
    line((int)round(rx3), (int)round(ry3), (int)round(rx1), (int)round(ry1));
    getch();
    closegraph();
    return 0;
}
