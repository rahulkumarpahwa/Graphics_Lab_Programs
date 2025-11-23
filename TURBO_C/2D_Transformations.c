/*
 * 2D Geometric Transformations
 * Includes: Translation, Rotation, Scaling, Reflection
 */

#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#define PI 3.14159265359

// Structure for a point
typedef struct
{
    float x, y;
} Point;

// Structure for a polygon
typedef struct
{
    Point vertices[10];
    int num_vertices;
} Polygon;

// Draw polygon
void draw_polygon(Polygon poly, int color)
{
    setcolor(color);
    for (int i = 0; i < poly.num_vertices; i++)
    {
        int x1 = poly.vertices[i].x;
        int y1 = poly.vertices[i].y;
        int x2 = poly.vertices[(i + 1) % poly.num_vertices].x;
        int y2 = poly.vertices[(i + 1) % poly.num_vertices].y;
        line(x1, y1, x2, y2);
    }
}

// Translation transformation
Polygon translate(Polygon poly, float tx, float ty)
{
    Polygon translated = poly;
    for (int i = 0; i < poly.num_vertices; i++)
    {
        translated.vertices[i].x = poly.vertices[i].x + tx;
        translated.vertices[i].y = poly.vertices[i].y + ty;
    }
    return translated;
}

// Scaling transformation
Polygon scale(Polygon poly, float sx, float sy, float cx, float cy)
{
    Polygon scaled = poly;
    for (int i = 0; i < poly.num_vertices; i++)
    {
        scaled.vertices[i].x = cx + (poly.vertices[i].x - cx) * sx;
        scaled.vertices[i].y = cy + (poly.vertices[i].y - cy) * sy;
    }
    return scaled;
}

// Rotation transformation (in degrees)
Polygon rotate(Polygon poly, float angle, float cx, float cy)
{
    Polygon rotated = poly;
    float rad = angle * PI / 180.0;
    float cos_a = cos(rad);
    float sin_a = sin(rad);

    for (int i = 0; i < poly.num_vertices; i++)
    {
        float x = poly.vertices[i].x - cx;
        float y = poly.vertices[i].y - cy;

        rotated.vertices[i].x = cx + (x * cos_a - y * sin_a);
        rotated.vertices[i].y = cy + (x * sin_a + y * cos_a);
    }
    return rotated;
}

// Reflection about X-axis
Polygon reflect_x(Polygon poly, float cy)
{
    Polygon reflected = poly;
    for (int i = 0; i < poly.num_vertices; i++)
    {
        reflected.vertices[i].x = poly.vertices[i].x;
        reflected.vertices[i].y = 2 * cy - poly.vertices[i].y;
    }
    return reflected;
}

// Reflection about Y-axis
Polygon reflect_y(Polygon poly, float cx)
{
    Polygon reflected = poly;
    for (int i = 0; i < poly.num_vertices; i++)
    {
        reflected.vertices[i].x = 2 * cx - poly.vertices[i].x;
        reflected.vertices[i].y = poly.vertices[i].y;
    }
    return reflected;
}

// Shearing transformation (X direction)
Polygon shear_x(Polygon poly, float shear_factor)
{
    Polygon sheared = poly;
    for (int i = 0; i < poly.num_vertices; i++)
    {
        sheared.vertices[i].x = poly.vertices[i].x + shear_factor * poly.vertices[i].y;
        sheared.vertices[i].y = poly.vertices[i].y;
    }
    return sheared;
}

int main()
{
    int gdriver = DETECT, gmode;

    // Initialize graphics mode
    initgraph(&gdriver, &gmode, "C:\\MINGW\\lib\\libbgi");

    if (graphresult() != grOk)
    {
        printf("Graphics initialization failed\n");
        return -1;
    }

    int max_x = getmaxx();
    int max_y = getmaxy();

    // Clear screen
    cleardevice();

    // Draw title
    setcolor(YELLOW);
    outtextxy(max_x / 2 - 150, 10, "2D Geometric Transformations");

    // Create a square polygon
    Polygon square;
    square.num_vertices = 4;
    square.vertices[0].x = 50;
    square.vertices[0].y = 100;
    square.vertices[1].x = 100;
    square.vertices[1].y = 100;
    square.vertices[2].x = 100;
    square.vertices[2].y = 150;
    square.vertices[3].x = 50;
    square.vertices[3].y = 150;

    // Create a triangle polygon
    Polygon triangle;
    triangle.num_vertices = 3;
    triangle.vertices[0].x = 200;
    triangle.vertices[0].y = 100;
    triangle.vertices[1].x = 250;
    triangle.vertices[1].y = 150;
    triangle.vertices[2].x = 150;
    triangle.vertices[2].y = 150;

    int y_pos = 50;

    // 1. TRANSLATION
    setcolor(LIGHTCYAN);
    outtextxy(20, y_pos, "1. TRANSLATION");
    draw_polygon(square, WHITE);

    Polygon translated = translate(square, 80, 0);
    draw_polygon(translated, GREEN);
    outtextxy(20, y_pos + 20, "White: Original, Green: Translated");

    y_pos += 80;

    // 2. SCALING
    setcolor(LIGHTCYAN);
    outtextxy(20, y_pos, "2. SCALING");

    Polygon square2 = square;
    square2.vertices[0].x = 50;
    square2.vertices[0].y = y_pos + 50;
    square2.vertices[1].x = 100;
    square2.vertices[1].y = y_pos + 50;
    square2.vertices[2].x = 100;
    square2.vertices[2].y = y_pos + 100;
    square2.vertices[3].x = 50;
    square2.vertices[3].y = y_pos + 100;

    draw_polygon(square2, WHITE);

    Polygon scaled = scale(square2, 1.5, 1.5, 75, y_pos + 75);
    draw_polygon(scaled, RED);
    outtextxy(20, y_pos + 20, "White: Original, Red: Scaled (1.5x)");

    y_pos += 130;

    // 3. ROTATION
    setcolor(LIGHTCYAN);
    outtextxy(20, y_pos, "3. ROTATION");

    Polygon square3 = square;
    square3.vertices[0].x = 50;
    square3.vertices[0].y = y_pos + 50;
    square3.vertices[1].x = 100;
    square3.vertices[1].y = y_pos + 50;
    square3.vertices[2].x = 100;
    square3.vertices[2].y = y_pos + 100;
    square3.vertices[3].x = 50;
    square3.vertices[3].y = y_pos + 100;

    draw_polygon(square3, WHITE);

    Polygon rotated = rotate(square3, 45, 75, y_pos + 75);
    draw_polygon(rotated, MAGENTA);
    outtextxy(20, y_pos + 20, "White: Original, Magenta: Rotated 45°");

    // 4. REFLECTION (X-axis)
    setcolor(LIGHTCYAN);
    outtextxy(300, 50, "4. REFLECTION X-AXIS");

    Polygon tri2 = triangle;
    tri2.vertices[0].x = 320;
    tri2.vertices[0].y = 100;
    tri2.vertices[1].x = 370;
    tri2.vertices[1].y = 150;
    tri2.vertices[2].x = 270;
    tri2.vertices[2].y = 150;

    draw_polygon(tri2, WHITE);

    Polygon reflected_x = reflect_x(tri2, 150);
    draw_polygon(reflected_x, CYAN);
    outtextxy(300, 70, "White: Original");
    outtextxy(300, 85, "Cyan: Reflected X");

    // 5. REFLECTION (Y-axis)
    setcolor(LIGHTCYAN);
    outtextxy(300, 220, "5. REFLECTION Y-AXIS");

    Polygon tri3 = triangle;
    tri3.vertices[0].x = 370;
    tri3.vertices[0].y = 270;
    tri3.vertices[1].x = 420;
    tri3.vertices[1].y = 320;
    tri3.vertices[2].x = 320;
    tri3.vertices[2].y = 320;

    draw_polygon(tri3, WHITE);

    Polygon reflected_y = reflect_y(tri3, 370);
    draw_polygon(reflected_y, LIGHTGREEN);
    outtextxy(300, 240, "White: Original");
    outtextxy(300, 255, "Green: Reflected Y");

    // 6. SHEARING
    setcolor(LIGHTCYAN);
    outtextxy(300, 390, "6. SHEARING");

    Polygon square4 = square;
    square4.vertices[0].x = 320;
    square4.vertices[0].y = 430;
    square4.vertices[1].x = 370;
    square4.vertices[1].y = 430;
    square4.vertices[2].x = 370;
    square4.vertices[2].y = 480;
    square4.vertices[3].x = 320;
    square4.vertices[3].y = 480;

    draw_polygon(square4, WHITE);

    Polygon sheared = shear_x(square4, 0.5);
    draw_polygon(sheared, YELLOW);
    outtextxy(300, 410, "White: Original");
    outtextxy(300, 425, "Yellow: Sheared");

    // Display info
    setcolor(YELLOW);
    outtextxy(20, max_y - 40, "Press any key to exit...");

    getch();
    closegraph();

    return 0;
}
