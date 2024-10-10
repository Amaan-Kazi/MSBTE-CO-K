#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void main ()
{
	int gd = DETECT, gm;
	int x1, y1, x2, y2, x3, y3, shearX, shearY, input = -1;
	clrscr();

	printf("x1: ");
	scanf("%d", &x1);
	printf("y1: ");
	scanf("%d", &y1);

	printf("x2: ");
	scanf("%d", &x2);
	printf("y2: ");
	scanf("%d", &y2);

	printf("x3: ");
	scanf("%d", &x3);
	printf("y3: ");
	scanf("%d", &y3);

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
	getch();
	closegraph();

	while (input != 0)
	{
		clrscr();
		printf("0. Exit\n");
		printf("1. Shearing\n");
		printf("2. Reflection\n");
		printf("Input: ");
		scanf("%d", &input);

		switch (input)
		{
			case 0:
				exit(1);
				break;
			case 1:
				printf("Shear X: ");
				scanf("%d", &shearX);
				printf("Shear Y: ");
				scanf("%d", &shearY);

				x3 += shearX;
				y3 += shearY;

				initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
				line(x1, y1, x2, y2);
				line(x2, y2, x3, y3);
				line(x3, y3, x1, y1);

				getch();
				closegraph();
				break;
			case 2:
				initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
				line(x1, y1, x2, y2);
				line(x2, y2, x3, y3);
				line(x3, y3, x1, y1);

				line(x1, y1, x2, y2);
				line(x2, y2, x3, y3);
				line(x3, y3, x1, y1);

				getch();
				closegraph();
				break;
			default:
				printf("Invalid");
				break;
		}
	}
	getch();
}