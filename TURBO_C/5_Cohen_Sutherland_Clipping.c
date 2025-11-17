/*
 * Cohen-Sutherland Line Clipping Algorithm
 */

#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<conio.h>

#define INSIDE 0    // 0000
#define LEFT 1      // 0001
#define RIGHT 2     // 0010
#define BOTTOM 4    // 0100
#define TOP 8       // 1000

// Structure for line segment
typedef struct {
    int x1, y1, x2, y2;
} Line;

// Structure for clipping window
typedef struct {
    int xmin, ymin, xmax, ymax;
} Window;

// Function to compute region code
int computeCode(int x, int y, Window window) {
    int code = INSIDE;
    
    if (x < window.xmin)
        code |= LEFT;
    else if (x > window.xmax)
        code |= RIGHT;
    
    if (y < window.ymin)
        code |= BOTTOM;
    else if (y > window.ymax)
        code |= TOP;
    
    return code;
}

// Cohen-Sutherland line clipping algorithm
int cohen_sutherland(Line *line, Window window) {
    int code1 = computeCode(line->x1, line->y1, window);
    int code2 = computeCode(line->x2, line->y2, window);
    
    int accept = 0;
    
    while (1) {
        if ((code1 | code2) == 0) {
            // Both endpoints inside window
            accept = 1;
            break;
        } else if ((code1 & code2) != 0) {
            // Both endpoints outside window in same region
            break;
        } else {
            // Partial intersection
            int code_out;
            int x, y;
            
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
            
            // Find intersection point
            if (code_out & TOP) {
                x = line->x1 + (line->x2 - line->x1) * (window.ymax - line->y1) / 
                    (line->y2 - line->y1);
                y = window.ymax;
            } else if (code_out & BOTTOM) {
                x = line->x1 + (line->x2 - line->x1) * (window.ymin - line->y1) / 
                    (line->y2 - line->y1);
                y = window.ymin;
            } else if (code_out & RIGHT) {
                y = line->y1 + (line->y2 - line->y1) * (window.xmax - line->x1) / 
                    (line->x2 - line->x1);
                x = window.xmax;
            } else if (code_out & LEFT) {
                y = line->y1 + (line->y2 - line->y1) * (window.xmin - line->x1) / 
                    (line->x2 - line->x1);
                x = window.xmin;
            }
            
            // Update endpoint
            if (code_out == code1) {
                line->x1 = x;
                line->y1 = y;
                code1 = computeCode(line->x1, line->y1, window);
            } else {
                line->x2 = x;
                line->y2 = y;
                code2 = computeCode(line->x2, line->y2, window);
            }
        }
    }
    
    return accept;
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
    
    // Define clipping window
    Window window;
    window.xmin = 150;
    window.ymin = 100;
    window.xmax = 500;
    window.ymax = 400;
    
    // Draw title
    setcolor(YELLOW);
    outtextxy(max_x/2 - 150, 20, "Cohen-Sutherland Line Clipping Algorithm");
    
    // Draw clipping window
    setcolor(GREEN);
    rectangle(window.xmin, window.ymin, window.xmax, window.ymax);
    setcolor(LIGHTGREEN);
    outtextxy(window.xmin + 10, window.ymin - 20, "Clipping Window");
    
    // Define lines to be clipped
    Line lines[] = {
        {50, 150, 300, 300},        // Partially inside
        {100, 50, 400, 450},        // Crosses window
        {550, 50, 600, 400},        // Outside
        {200, 50, 400, 200},        // Partially inside
        {100, 200, 600, 250},       // Horizontal crossing
        {300, 50, 300, 450}         // Vertical crossing
    };
    
    int num_lines = 6;
    
    // Draw original lines (before clipping)
    setcolor(RED);
    outtextxy(20, 70, "Red: Original Lines");
    
    for (int i = 0; i < num_lines; i++) {
        line(lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2);
    }
    
    // Clip and draw clipped lines
    setcolor(WHITE);
    outtextxy(20, 90, "White: Clipped Lines");
    
    Line clipped_lines[] = {
        {50, 150, 300, 300},
        {100, 50, 400, 450},
        {550, 50, 600, 400},
        {200, 50, 400, 200},
        {100, 200, 600, 250},
        {300, 50, 300, 450}
    };
    
    for (int i = 0; i < num_lines; i++) {
        if (cohen_sutherland(&clipped_lines[i], window)) {
            line(clipped_lines[i].x1, clipped_lines[i].y1, 
                 clipped_lines[i].x2, clipped_lines[i].y2);
        }
    }
    
    // Display info
    setcolor(YELLOW);
    outtextxy(20, max_y - 40, "Press any key to exit...");
    
    getch();
    closegraph();
    
    return 0;
}
