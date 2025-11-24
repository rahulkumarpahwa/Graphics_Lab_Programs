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



int main() {
    int gdriver = DETECT, gmode;
    
    // Initialize graphics mode
    initgraph(&gdriver, &gmode, "C:\\MINGW\\lib\\libbgi");
    
    
    int max_x = getmaxx();
    int max_y = getmaxy();
    
    // Clear screen
    cleardevice();
    
    // Draw title
    setcolor(YELLOW);
    outtextxy(max_x/2 - 120, 20, "Bresenham Circle Drawing Algorithm");
    
    bresenham_circle(250, 250, 150);
    
    // Display info
    setcolor(YELLOW);
    outtextxy(20, max_y - 40, "Press any key to exit...");
    
    getch();
    closegraph();
    
    return 0;
}
