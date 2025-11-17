#include <stdio.h>
#include <conio.h>
#include "graphics.h"

// 1. Subroutine Definition
// Draws an ring with red on the border and black at the center.
void draw_red_ring(int x, int y, int outer_radius, int inner_radius)
{
    setcolor(RED);
    circle(x, y, outer_radius);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x, y, RED);

    // Draw the inner circle
    setcolor(BLACK);
    circle(x, y, inner_radius);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x, y, BLACK);
}

int main()
{
    // Graphics initialization variables
    int gd = DETECT, gm;
    char path[] = ""; // Adjust this path if necessary

    // Initialize the graphics mode
    initgraph(&gd, &gm, path);

    // Error checking for initialization
    if (graphresult() != grOk)
    {
        printf("Graphics initialization failed. Error: %d\n", graphresult());
        getch();
        return 1;
    }

    // 2. Subroutine Call
    // Draw a ring centered at (320, 240) with outer radius 100 and inner radius 70.
    // The center (320, 240) is typically the center of a 640x480 screen.
    draw_red_ring(320, 240, 100, 70);

    // Display message and wait
    setcolor(WHITE); // Set text color
    outtextxy(10, getmaxy() - 20, "Red Ring Drawn. Press any key to exit...");

    getch();      // Wait for a key press
    closegraph(); // Close graphics mode

    return 0;
}