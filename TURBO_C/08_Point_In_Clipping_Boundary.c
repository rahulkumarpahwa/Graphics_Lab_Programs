#include "graphics.h"
#include <conio.h>
#include <stdio.h>

int point_inside_rect(int x, int y, int xmin, int ymin, int xmax, int ymax)
{
    return (x >= xmin && x <= xmax && y >= ymin && y <= ymax);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xmin = 150, ymin = 100, xmax = 500, ymax = 400;
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(WHITE);
    outtextxy(20, 20, "Click (enter coords) to test point-in-clip (console input)");
    int x, y;
    printf("Enter point x y: ");
    if (scanf("%d %d", &x, &y) != 2)
    {
        closegraph();
        return 0;
    }
    if (point_inside_rect(x, y, xmin, ymin, xmax, ymax))
    {
        putpixel(x, y, GREEN);
        printf("Point is inside\n");
    }
    else
    {
        putpixel(x, y, RED);
        printf("Point is outside\n");
    }
    getch();
    closegraph();
    return 0;
}
