/*
 * DDA (Digital Differential Analyzer) Line Drawing Algorithm
 */

#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<conio.h>

void dda_line(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    
    // Calculate the number of steps
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
    // Calculate increment in x and y for each step
    float x_inc = (float)dx / steps;
    float y_inc = (float)dy / steps;
    
    // Start from (x0, y0)
    float x = x0;
    float y = y0;
    
    // Draw the line
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += x_inc;
        y += y_inc;
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
    outtextxy(max_x/2 - 100, 20, "DDA Line Drawing Algorithm");
    
    // Draw multiple lines using DDA algorithm
    setcolor(WHITE);
    dda_line(50, 50, 300, 300);           // Diagonal line
    
    setcolor(RED);
    dda_line(400, 100, 600, 300);         // Another diagonal
    
    setcolor(GREEN);
    dda_line(100, 200, 500, 200);         // Horizontal line
    
    setcolor(CYAN);
    dda_line(200, 100, 200, 400);         // Vertical line
    
    setcolor(MAGENTA);
    dda_line(50, 400, 600, 100);          // Steep diagonal
    
    // Display info
    setcolor(YELLOW);
    outtextxy(20, max_y - 40, "Press any key to exit...");
    
    getch();
    closegraph();
    
    return 0;
}
