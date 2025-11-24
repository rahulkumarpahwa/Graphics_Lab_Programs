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
    
    // Calculate the number of steps (max of the dx or dy)
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
    // Calculate increment in x and y for each step
    float x_inc = (float)dx / steps;
    float y_inc = (float)dy / steps;
    
    // Start from (x0, y0)
    float x = x0;
    float y = y0;
    
    // Draw the line
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), YELLOW);
        x += x_inc;
        y += y_inc;
    }
}

int main() {
    int gdriver = DETECT, gmode;
    
    // Initialize graphics mode
    initgraph(&gdriver, &gmode, "");
    
    // Clear screen
    cleardevice();
    
    dda_line(50, 50, 300, 300);   
    
    outtextxy(10, getmaxy() -20, "Press any key to QUIT!");
    
    getch();
    closegraph();
    
    return 0;
}
