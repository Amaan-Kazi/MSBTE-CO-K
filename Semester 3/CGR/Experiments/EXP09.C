#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void reflect_rectangle(int x[], int y[], int type) {
    int i;
    for (i = 0; i < 4; i++) {
        if (type == 1) { // Reflection about X-axis
            y[i] = -y[i];
        }
        else if (type == 2) { // Reflection about Y-axis
            x[i] = -x[i];
        }
    }
}

void shear_rectangle(int x[], int y[], int shx, int shy) {
    int i;
    for (i = 0; i < 4; i++) {
        x[i] = x[i] + shx * y[i]; // Shear along X-axis
        y[i] = y[i] + shy * x[i]; // Shear along Y-axis
    }
}

void draw_rectangle(int x[], int y[], int mid_x, int mid_y) {
    int i;
    int tx[4], ty[4]; // Declare transformed coordinates at the start
    for (i = 0; i < 4; i++) {
        tx[i] = x[i] + mid_x;
        ty[i] = mid_y - y[i]; // Flip Y-axis
    }
    rectangle(tx[0], ty[0], tx[2], ty[2]);
}

void main() {
    int gd = DETECT, gm;
    int i, shx, shy;
    int mid_x, mid_y;
    
    int x[4], y[4]; // Declare arrays at the start
    int x_reflect_x[4], y_reflect_x[4];
    int x_reflect_y[4], y_reflect_y[4];
    int x_shear[4], y_shear[4];
    
    x[0] = 50; x[1] = 150; x[2] = 150; x[3] = 50;
    y[0] = 50; y[1] = 50; y[2] = 100; y[3] = 100;
    
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    mid_x = getmaxx() / 2;
    mid_y = getmaxy() / 2;
    
    line(mid_x, 0, mid_x, getmaxy()); // Y-axis
    line(0, mid_y, getmaxx(), mid_y); // X-axis
    
    setcolor(WHITE);
    draw_rectangle(x, y, mid_x, mid_y); // Draw original rectangle
    
    // Reflection about the X-axis
    for (i = 0; i < 4; i++) {
        x_reflect_x[i] = x[i];
        y_reflect_x[i] = y[i];
    }
    reflect_rectangle(x_reflect_x, y_reflect_x, 1);
    setcolor(YELLOW);
    draw_rectangle(x_reflect_x, y_reflect_x, mid_x, mid_y);
    
    // Reflection about the Y-axis
    for (i = 0; i < 4; i++) {
        x_reflect_y[i] = x[i];
        y_reflect_y[i] = y[i];
    }
    reflect_rectangle(x_reflect_y, y_reflect_y, 2);
    setcolor(GREEN);
    draw_rectangle(x_reflect_y, y_reflect_y, mid_x, mid_y);
    
    // Shearing
    for (i = 0; i < 4; i++) {
        x_shear[i] = x[i];
        y_shear[i] = y[i];
    }
    shx = 1;
    shy = 0;
    shear_rectangle(x_shear, y_shear, shx, shy);
    setcolor(RED);
    draw_rectangle(x_shear, y_shear, mid_x, mid_y);

	getch();
    getch();
    closegraph();
}

