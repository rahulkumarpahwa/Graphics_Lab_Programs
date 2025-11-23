#include "graphics.h"
#include <conio.h>
#include <stdio.h>

void translate_point(int x, int y, int tx, int ty, int *rx, int *ry)
{
    *rx = x + tx;
    *ry = y + ty;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x, y, tx, ty;
    printf("Enter point x y and translation tx ty: ");
    if (scanf("%d %d %d %d", &x, &y, &tx, &ty) != 4)
    {
        closegraph();
        return 0;
    }
    int rx, ry;
    translate_point(x, y, tx, ty, &rx, &ry);
    putpixel(x, y, RED);
    putpixel(rx, ry, GREEN);
    line(x, y, rx, ry);
    getch();
    closegraph();
    return 0;
}
