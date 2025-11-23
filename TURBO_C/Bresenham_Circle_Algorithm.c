/*
 * Bresenham Circle Drawing Algorithm
 */

#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void bresenham_circle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;  // Decision parameter
    
    while (x <= y) {
        // Draw all 8 symmetric points
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

// Function to draw filled circle
void bresenham_filled_circle(int xc, int yc, int r, int color) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;
    
    while (x <= y) {
        // Draw horizontal lines to fill the circle
        line(xc - x, yc + y, xc + x, yc + y);
        line(xc - x, yc - y, xc + x, yc - y);
        line(xc - y, yc + x, xc + y, yc + x);
        line(xc - y, yc - x, xc + y, yc - x);
        
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main() {
    int gdriver = DETECT, gmode;
    
    // Initialize graphics mode
    initgraph(&gdriver, &gmode, "C:\\MINGW\\lib\\libbgi");
    
    if (graphresult() != grOk) {
        printf("Graphics initialization failed\n");
        return -1;
    }
    
    int max_x = getmaxx();
    int max_y = getmaxy();
    
    // Clear screen
    cleardevice();
    
    // Draw title
    setcolor(YELLOW);
    outtextxy(max_x/2 - 120, 20, "Bresenham Circle Drawing Algorithm");
    
    // Draw outlines circles
    setcolor(LIGHTCYAN);
    outtextxy(50, 70, "Outline Circles:");
    
    setcolor(WHITE);
    bresenham_circle(150, 200, 50);
    
    setcolor(RED);
    bresenham_circle(150, 200, 100);
    
    setcolor(GREEN);
    bresenham_circle(150, 200, 150);
    
    // Draw filled circles
    setcolor(LIGHTCYAN);
    outtextxy(max_x - 250, 70, "Filled Circles:");
    
    setcolor(CYAN);
    bresenham_filled_circle(max_x - 150, 150, 60, CYAN);
    
    setcolor(MAGENTA);
    bresenham_filled_circle(max_x - 150, 350, 60, MAGENTA);
    
    setcolor(LIGHTGREEN);
    bresenham_filled_circle(max_x/2, max_y - 150, 80, LIGHTGREEN);
    
    // Display info
    setcolor(YELLOW);
    outtextxy(20, max_y - 40, "Press any key to exit...");
    
    getch();
    closegraph();
    
    return 0;
}
