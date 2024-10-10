#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void main ()
{
	int gd = DETECT, gm;
	int r, xi, yi, d, x, y, n = 0, i, j;
	int xA[8][1000], yA[8][1000];
	clrscr();

	printf("x: ");
	scanf("%d", &xi);
	printf("y: ");
	scanf("%d", &yi);

	printf("Radius: ");
	scanf("%d", &r);

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	// Bresenham's Circle Drawing Algorithm (8 way symmetry)
	d = 3 - (2 * r);
	x = 0;
	y = r;

	do {
		// 8 Way Symmetry
		putpixel(xi+x, yi+y, 1);
		xA[0][n] = 0+x;
		yA[0][n] = 0+y;

		putpixel(xi+y, yi+x, 2);
		xA[1][n] = 0+y;
		yA[2][n] = 0+x;

		putpixel(xi-y, yi+x, 3);
		xA[2][n] = 0-y;
		yA[2][n] = 0+x;

		putpixel(xi+x, yi-y, 4);
		xA[3][n] = 0+x;
		yA[3][n] = 0-y;

		putpixel(xi-x, yi-y, 5);
		xA[4][n] = 0-x;
		yA[4][n] = 0-y;

		putpixel(xi-y, yi-x, 6);
		xA[5][n] = 0-y;
		yA[5][n] = 0-x;

		putpixel(xi+y, yi-x, 7);
		xA[6][n] = 0+y;
		yA[6][n] = 0-x;

		putpixel(xi-x, yi+y, 8);
		xA[7][n] = 0-x;
		yA[7][n] = 0+y;

		if (d < 0)
		{
			d = d + (4 * x) + 6;
		}
		else
		{
			d = d + (4 * (x - y)) + 10;
			y = y - 1;
		}

		x = x + 1;
		n++;
		delay(20);
	} while (x <= y);

	getch();
	closegraph();

	for (i = 0; i < n; i++)
	{
		//printf("%03d | ", i);
		for (j = 0; j < 8; j++)
		{
			printf("%03d,%03d | ", xA[j][i], yA[j][i]);
		}
		printf("\n");

		delay(10);
	}

	getch();
}
