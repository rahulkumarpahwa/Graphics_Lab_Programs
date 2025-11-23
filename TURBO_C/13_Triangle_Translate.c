#include <graphics.h>
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
    int x1, y1, x2, y2, x3, y3, tx, ty;
    printf("Enter triangle points x1 y1 x2 y2 x3 y3 and translation tx ty: ");
    if (scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &tx, &ty) != 8)
    {
        closegraph();
        return 0;
    }
    int rx1, ry1, rx2, ry2, rx3, ry3;
    translate_point(x1, y1, tx, ty, &rx1, &ry1);
    translate_point(x2, y2, tx, ty, &rx2, &ry2);
    translate_point(x3, y3, tx, ty, &rx3, &ry3);
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    setcolor(GREEN);
    line(rx1, ry1, rx2, ry2);
    line(rx2, ry2, rx3, ry3);
    line(rx3, ry3, rx1, ry1);
    getch();
    closegraph();
    return 0;
}
