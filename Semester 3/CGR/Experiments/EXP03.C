#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void main ()
{
	int x1, y1, x2, y2, dx, dy, i, n = 0;
	int xi, yi, e;
	int xArr[1000], yArr[1000];

	int gd = DETECT, gm;
	clrscr();

	printf("Starting coordinate \nx1: ");
	scanf("%d", &x1);
	printf("y1: ");
	scanf("%d", &y1);
	printf("Ending coordinate \nx2: ");
	scanf("%d", &x2);
	printf("y2: ");
	scanf("%d", &y2);

	dx = x2 - x1;
	dy = y2 - y1;

	xi = x1;
	yi = y1;

	e = (2 * dy) - dx;

	printf("dx = %d, dy = %d, xi = %d, yi = %d", dx, dy, xi, yi);

	getch();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	for (i = 0; i < dx; i++)
	{
		putpixel(xi, yi, 7);

		while (e >= 0)
		{
			yi += 1;
			e -= 2 * dx;
		}

		xi += 1;
		e += 2 * dy;

		xArr[i] = xi;
		yArr[i] = yi;
		n++;
		delay(5);
	}

	getch();

	printf("i \t plot \n");
	for (i = 0; i < n; i++)
	{
		printf("%d \t (%d, %d) \n", i, xArr[i], yArr[i]);
	}

	getch();
	closegraph();
}
