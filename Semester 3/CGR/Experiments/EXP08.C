#include <graphics.h>
#include <conio.h>
#include <math.h>

void rotate_square(int x[], int y[], int xc, int yc, float angle) {
	float rad = angle * (3.14159 / 180); // Convert angle to radians
	int x_new, y_new;
	int i;

	for (i = 0; i < 4; i++) {
		x_new = xc + (x[i] - xc) * cos(rad) - (y[i] - yc) * sin(rad);
		y_new = yc + (x[i] - xc) * sin(rad) + (y[i] - yc) * cos(rad);
		x[i] = x_new;
		y[i] = y_new;
	}
}

int main() {
	int gd = DETECT, gm;

	int x[] = {100, 200, 200, 100}; // X coordinates of the square
	int y[] = {100, 100, 200, 200}; // Y coordinates of the square
	int xc = 150, yc = 150;         // Center of the square
	float angle = 45;               // Rotation angle in degrees

	clrscr();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	setcolor(WHITE);
	rectangle(x[0], y[0], x[2], y[2]); // Original square

	rotate_square(x, y, xc, yc, angle); // Rotate the square

	closegraph();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	setcolor(YELLOW);
	line(x[0], y[0], x[1], y[1]); // Draw the rotated square
	line(x[1], y[1], x[2], y[2]);
	line(x[2], y[2], x[3], y[3]);
	line(x[3], y[3], x[0], y[0]);

	getch();
	getch();
	closegraph();
	return 0;
}

