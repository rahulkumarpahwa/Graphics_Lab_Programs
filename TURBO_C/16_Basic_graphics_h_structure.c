#include <graphics.h>
#include <conio.h>
#include <stdio.h>

/*
 * Basic `graphics.h` program structure template
 */

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    if (graphresult() != grOk)
    {
        printf("Graphics initialization failed\n");
        return -1;
    }
    setbkcolor(BLACK);
    cleardevice();
    setcolor(WHITE);
    outtextxy(50, 50, "Basic graphics.h program structure\nPress any key to exit...");
    getch();
    closegraph();
    return 0;
}
