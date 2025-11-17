## command to compile:

gcc -o a.exe <filename>.c -L"C:/mingw/lib" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -lstdc++

## run:

./a.exe

## List Of Programs:

List of program for practical of graphics:

1. Line drawing algo DDA + breshman.
2. Circle drawing algos both midpoint and breshman
3. Clipping Sutherland transformation
4. Tower of hanoi
5. Bubble shot visualisation
6. Saving, loading and printing images
7. Basic graphics.h program structure
8. Drawing primitives with graphics.h such as circle(), rectangle(), line(), putpixel(), arc(), bar(), eclipse(), drawpolygon(), outtextxy(), setfillstyle(), floodfill() and setcolor(), setbkcolor().

## Note:

- make sure to include the '#include"graphics.h"' in every c program.
- add the #include<conio.h> for the getch() method.
- In case, any function which is used in the program is not declared in the custom graphics.h then we can declare it there.
- the two files: 1. winbgim.h is putted in MinGW/include/ folder and 2. libbgi.a is putted in MinGW/lib/ folder and third the custom grahics.h file is created here to get the filed compiled and executed.
