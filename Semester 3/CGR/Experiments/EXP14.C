#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#define round(a) ((int)(a + 0.5))

int k;
float clipWindowXMin, clipWindowYMin, clipWindowXMax, clipWindowYMax, arr[20], slope;

void clipLeft(float x1, float y1, float x2, float y2) {
    if (x2 - x1) slope = (y2 - y1) / (x2 - x1);
    if (x1 >= clipWindowXMin && x2 >= clipWindowXMin) {
        arr[k] = x2;
        arr[k + 1] = y2;
        k += 2;
    }
    if (x1 < clipWindowXMin && x2 >= clipWindowXMin) {
        arr[k] = clipWindowXMin;
        arr[k + 1] = y1 + slope * (clipWindowXMin - x1);
        arr[k + 2] = x2;
        arr[k + 3] = y2;
        k += 4;
    }
    if (x1 >= clipWindowXMin && x2 < clipWindowXMin) {
        arr[k] = clipWindowXMin;
        arr[k + 1] = y1 + slope * (clipWindowXMin - x1);
        k += 2;
    }
}

void clipTop(float x1, float y1, float x2, float y2) {
    if (y2 - y1) slope = (x2 - x1) / (y2 - y1);
    if (y1 <= clipWindowYMax && y2 <= clipWindowYMax) {
        arr[k] = x2;
        arr[k + 1] = y2;
        k += 2;
    }
    if (y1 > clipWindowYMax && y2 <= clipWindowYMax) {
        arr[k] = x1 + slope * (clipWindowYMax - y1);
        arr[k + 1] = clipWindowYMax;
        arr[k + 2] = x2;
        arr[k + 3] = y2;
        k += 4;
    }
    if (y1 <= clipWindowYMax && y2 > clipWindowYMax) {
        arr[k] = x1 + slope * (clipWindowYMax - y1);
        arr[k + 1] = clipWindowYMax;
        k += 2;
    }
}

void clipRight(float x1, float y1, float x2, float y2) {
    if (x2 - x1) slope = (y2 - y1) / (x2 - x1);
    if (x1 <= clipWindowXMax && x2 <= clipWindowXMax) {
        arr[k] = x2;
        arr[k + 1] = y2;
        k += 2;
    }
    if (x1 > clipWindowXMax && x2 <= clipWindowXMax) {
        arr[k] = clipWindowXMax;
        arr[k + 1] = y1 + slope * (clipWindowXMax - x1);
        arr[k + 2] = x2;
        arr[k + 3] = y2;
        k += 4;
    }
    if (x1 <= clipWindowXMax && x2 > clipWindowXMax) {
        arr[k] = clipWindowXMax;
        arr[k + 1] = y1 + slope * (clipWindowXMax - x1);
        k += 2;
    }
}

void clipBottom(float x1, float y1, float x2, float y2) {
    if (y2 - y1) slope = (x2 - x1) / (y2 - y1);
    if (y1 >= clipWindowYMin && y2 >= clipWindowYMin) {
        arr[k] = x2;
        arr[k + 1] = y2;
        k += 2;
    }
    if (y1 < clipWindowYMin && y2 >= clipWindowYMin) {
        arr[k] = x1 + slope * (clipWindowYMin - y1);
        arr[k + 1] = clipWindowYMin;
        arr[k + 2] = x2;
        arr[k + 3] = y2;
        k += 4;
    }
    if (y1 >= clipWindowYMin && y2 < clipWindowYMin) {
        arr[k] = x1 + slope * (clipWindowYMin - y1);
        arr[k + 1] = clipWindowYMin;
        k += 2;
    }
}

void main() {
    int graphicsDriver = DETECT, graphicsMode, numberOfSides, polygon[20], i;
    float startX, startY, endX, endY, polygonCoordinates[20];

    clrscr();
    printf("Coordinates of rectangular clip window:\nxmin, ymin: ");
    scanf("%f %f", &clipWindowXMin, &clipWindowYMin);
    printf("Coordinates of rectangular clip window:\nxmax, ymax: ");
    scanf("%f %f", &clipWindowXMax, &clipWindowYMax);
    
    printf("\n\nPolygon to be clipped:\nNumber of sides: ");
    scanf("%d", &numberOfSides);
    printf("Enter the coordinates: ");
    for (i = 0; i < 2 * numberOfSides; i++)
        scanf("%f", &polygonCoordinates[i]);

    polygonCoordinates[i] = polygonCoordinates[0];
    polygonCoordinates[i + 1] = polygonCoordinates[1];

    for (i = 0; i < 2 * numberOfSides + 2; i++)
        polygon[i] = round(polygonCoordinates[i]);

    initgraph(&graphicsDriver, &graphicsMode, "C:\\TC\\BGI");
    rectangle(clipWindowXMin, clipWindowYMax, clipWindowXMax, clipWindowYMin);
    
    printf("\tUNCLIPPED POLYGON");
    fillpoly(numberOfSides, polygon);
    getch();
    cleardevice();

    k = 0;
    for (i = 0; i < 2 * numberOfSides; i += 2)
        clipLeft(polygonCoordinates[i], polygonCoordinates[i + 1], polygonCoordinates[i + 2], polygonCoordinates[i + 3]);

    numberOfSides = k / 2;
    for (i = 0; i < k; i++)
        polygonCoordinates[i] = arr[i];

    polygonCoordinates[i] = polygonCoordinates[0];
    polygonCoordinates[i + 1] = polygonCoordinates[1];
    k = 0;

    for (i = 0; i < 2 * numberOfSides; i += 2)
        clipTop(polygonCoordinates[i], polygonCoordinates[i + 1], polygonCoordinates[i + 2], polygonCoordinates[i + 3]);

    numberOfSides = k / 2;
    for (i = 0; i < k; i++)
        polygonCoordinates[i] = arr[i];

    polygonCoordinates[i] = polygonCoordinates[0];
    polygonCoordinates[i + 1] = polygonCoordinates[1];
    k = 0;

    for (i = 0; i < 2 * numberOfSides; i += 2)
        clipRight(polygonCoordinates[i], polygonCoordinates[i + 1], polygonCoordinates[i + 2], polygonCoordinates[i + 3]);

    numberOfSides = k / 2;
    for (i = 0; i < k; i++)
        polygonCoordinates[i] = arr[i];

    polygonCoordinates[i] = polygonCoordinates[0];
    polygonCoordinates[i + 1] = polygonCoordinates[1];
    k = 0;

    for (i = 0; i < 2 * numberOfSides; i += 2)
        clipBottom(polygonCoordinates[i], polygonCoordinates[i + 1], polygonCoordinates[i + 2], polygonCoordinates[i + 3]);

    for (i = 0; i < k; i++)
        polygon[i] = round(arr[i]);

    if (k) {
        fillpoly(k / 2, polygon);
    }

    rectangle(clipWindowXMin, clipWindowYMax, clipWindowXMax, clipWindowYMin);
    printf("\tCLIPPED POLYGON");
    getch();
    closegraph();
}

