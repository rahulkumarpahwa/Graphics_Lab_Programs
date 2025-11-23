#include "graphics.h"
#include <conio.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int maxx = getmaxx(), maxy = getmaxy();
    cleardevice();
    setbkcolor(BLACK);
    cleardevice();
    setcolor(WHITE);
    outtextxy(20, 20, "Drawing Primitives Demo");
    setcolor(RED);
    circle(150, 120, 50);
    setcolor(GREEN);
    rectangle(300, 80, 450, 160);
    setcolor(CYAN);
    line(50, 220, 500, 220);
    putpixel(60, 230, WHITE);
    setcolor(YELLOW);
    arc(150, 320, 0, 180, 50);
    setcolor(MAGENTA);
    bar(300, 260, 380, 320);
    setcolor(LIGHTBLUE);
    ellipse(520, 120, 0, 360, 60, 30);
    int poly[] = {520, 240, 580, 300, 460, 300};
    drawpoly(3, poly);
    setcolor(WHITE);
    outtextxy(20, maxy - 60, "Press any key to fill shapes and exit");
    getch();
    setfillstyle(SOLID_FILL, RED);
    floodfill(150, 120, RED);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(310, 90, GREEN);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    floodfill(520, 120, LIGHTBLUE);
    getch();
    closegraph();
    return 0;
}
