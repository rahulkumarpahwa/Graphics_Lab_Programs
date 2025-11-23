#include <stdio.h>
#include "graphics.h"
#include <conio.h>
#include <math.h>

// Compute intersection of two lines AB and CD
int compute_intersection(double x1, double y1, double x2, double y2,
                         double x3, double y3, double x4, double y4,
                         double *ix, double *iy)
{
    // Line AB: a1*x + b1*y = c1
    double a1 = y2 - y1;
    double b1 = x1 - x2;
    double c1 = a1 * x1 + b1 * y1;

    // Line CD: a2*x + b2*y = c2
    double a2 = y4 - y3;
    double b2 = x3 - x4;
    double c2 = a2 * x3 + b2 * y3;

    // Determinant (check if lines are parallel)
    double det = a1 * b2 - a2 * b1;
    if (fabs(det) < 1e-9)
    {
        return 0; // No unique intersection
    }

    // Solve using Cramer's Rule
    *ix = (b2 * c1 - b1 * c2) / det;
    *iy = (a1 * c2 - a2 * c1) / det;

    return 1; // Intersection found
}

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    printf("Enter A(x1 y1) B(x2 y2) C(x3 y3) D(x4 y4): \n");
    if (scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != 8)
        return 0;
    double ix, iy;
    int ok = compute_intersection(x1, y1, x2, y2, x3, y3, x4, y4, &ix, &iy);
    if (!ok)
    {
        printf("Lines are parallel or coincident\n");
        return 0;
    }
    printf("Intersection at: (%f, %f)\n", ix, iy);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    line(x1, y1, x2, y2);
    line(x3, y3, x4, y4);
    putpixel((int)round(ix), (int)round(iy), GREEN);
    getch();
    closegraph();
    return 0;
}
