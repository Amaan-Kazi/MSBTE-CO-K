#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void floodFill(int x, int y, int newColor, int oldColor)
{
	if (getpixel(x, y) == oldColor)
	{
		delay(1);
		putpixel(x, y, newColor);
		floodFill(x, y+1, newColor, oldColor);
		floodFill(x+1, y, newColor, oldColor);
		floodFill(x, y-1, newColor, oldColor);
		floodFill(x-1, y, newColor, oldColor);
	}
}

void main ()
{
	int i, points, px[100], py[100], x, y;
	int gd = DETECT, gm;
	clrscr();


	printf("Points: ");
	scanf("%d", &points);

	for (i = 0; i < points; i++)
	{
		printf("\nP%d - \n", i);

		printf("x%d: ", i);
		scanf("%d", &px[i]);

		printf("y%d: ", i);
		scanf("%d", &py[i]);
	}

	printf("\nSeed Point - \n");
	printf("x: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);

	getch();
	clrscr();
	initgraph(&gd, &gm, "C:\TURBOC3\BGI\EXP5.C");

	for (i = 0; i < points-1; i++)
	{
		line(px[i], py[i], px[i+1], py[i+1]);
	}
	line(px[i], py[i], px[0], py[0]);

	floodFill(x, y, 10, 0);

	getch();
	closegraph();
}