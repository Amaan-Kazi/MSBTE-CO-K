#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>

void main() {
    int graphicsDriver = DETECT, graphicsMode;
    int controlPointsX[4], controlPointsY[4];
    int pixelX, pixelY, i;
    double t;

    initgraph(&graphicsDriver, &graphicsMode, "C:\\TC\\BGI");

    printf("Enter four control points of the Bezier curve (x1 y1 x2 y2 x3 y3 x4 y4): ");
    for (i = 0; i < 4; i++) 
        scanf("%d %d", &controlPointsX[i], &controlPointsY[i]);

    for (t = 0.0; t <= 1.0; t += 0.001) {
        pixelX = (1 - t) * (1 - t) * (1 - t) * controlPointsX[0] +
                 3 * t * (1 - t) * (1 - t) * controlPointsX[1] +
                 3 * t * t * (1 - t) * controlPointsX[2] +
                 t * t * t * controlPointsX[3];

        pixelY = (1 - t) * (1 - t) * (1 - t) * controlPointsY[0] +
                 3 * t * (1 - t) * (1 - t) * controlPointsY[1] +
                 3 * t * t * (1 - t) * controlPointsY[2] +
                 t * t * t * controlPointsY[3];

        putpixel(pixelX, pixelY, WHITE);
        delay(2);
    }

    getch();
    closegraph();
}

