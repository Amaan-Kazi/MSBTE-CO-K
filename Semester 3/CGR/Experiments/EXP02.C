#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void main ()
{
	int x1, y1, x2, y2, length, dx, dy, i, n = 0, textY;
	float xin, yin, xi, yi;
	float xArr[1000], yArr[1000];

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

	if (dx >= dy)
		length = dx;
	else
		length = dy;

	xin = dx/length;
	yin = dy/length;

	printf("dx = %d, dy = %d, length = %d, xin = %f, yin = %f", dx, dy, length, xin, yin);

	getch();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	xi = x1 + 0.5;
	yi = y1 + 0.5;
	putpixel(xi, yi, 7);

	for (i = 0; i < length; i++)
	{
		xi += xin;
		yi += yin;

		xArr[i] = xi;
		yArr[i] = yi;

		putpixel(xi, yi, 7);

		n++;
		delay(5);
	}

	getch();

	printf("i \t plot \t xi \t yi \n");
	for (i = 0; i < n; i++)
	{
		printf("%d \t (%.2f, %.2f) \t %.2f \t %.2f \n", i, xArr[i], yArr[i], xArr[i], yArr[i]);
	}

	getch();
	closegraph();
}
