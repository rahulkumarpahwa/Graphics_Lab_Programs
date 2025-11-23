#include "graphics.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int x, y, r, dy, color;
} Bubble;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int maxx = getmaxx(), maxy = getmaxy();
    srand(time(NULL));
    const int N = 8;
    Bubble b[N];
    for (int i = 0; i < N; i++)
    {
        b[i].r = 20 + rand() % 20;
        b[i].x = 50 + i * 80;
        b[i].y = 50 + rand() % 100;
        b[i].dy = 2 + rand() % 4;
        b[i].color = rand() % 15 + 1;
    }
    while (!kbhit())
    {
        cleardevice();
        for (int i = 0; i < N; i++)
        {
            setcolor(b[i].color);
            setfillstyle(SOLID_FILL, b[i].color);
            circle(b[i].x, b[i].y, b[i].r);
            floodfill(b[i].x, b[i].y, b[i].color);
            b[i].y += b[i].dy;
            if (b[i].y + b[i].r >= maxy - 20)
            {
                b[i].y = maxy - 20 - b[i].r;
                b[i].dy = -b[i].dy;
            }
            if (b[i].y - b[i].r <= 20)
            {
                b[i].y = 20 + b[i].r;
                b[i].dy = -b[i].dy;
            }
        }
        delay(50);
    }
    getch();
    closegraph();
    return 0;
}
