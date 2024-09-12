#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int gd = DETECT, gm;
int x1, y1, x2, y2, operation, tx, ty, a = 1;
float sx, sy;

void translate(int x1, int y1, int x2, int y2, int tx, int ty)
{
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	rectangle(x1+tx, y1+ty, x2+tx, y2+ty);
	getch();
	closegraph();
}

void scale(int x1, int y1, int x2, int y2, float sx, float sy)
{
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	rectangle(x1, y1, x2 * sx, y2 * sy);
	getch();
	closegraph();
}

void main ()
{
	clrscr();
	printf("Enter diagonal coordinates of rectangle\n");
	printf("x1: ");
	scanf("%d", &x1);
	printf("y1: ");
	scanf("%d", &y1);

	printf("x2: ");
	scanf("%d", &x2);
	printf("y2: ");
	scanf("%d", &y2);

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	rectangle(x1, y1, x2, y2);
	getch();
	closegraph();

	while(a != 0)
	{
		clrscr();

		printf("\nSelect Operation\n");
		printf("0. Exit\n");
		printf("1. Translate\n");
		printf("2. Scale\n");

		printf("input: ");
		scanf("%d", &operation);

		switch (operation)
		{
			case 0:
				a = 0;
				break;
			case 1:
				printf("Translate X: ");
				scanf("%d", &tx);
				printf("Translate Y: ");
				scanf("%d", &ty);
				translate(x1, y1, x2, y2, tx, ty);
				break;
			case 2:
				printf("Scaling Factor X: ");
				scanf("%f", &sx);
				printf("Scaling Factor Y: ");
				scanf("%f", &sy);
				scale(x1, y1, x2, y2, sx, sy);
				break;
			default:
				printf("Invalid \n");
				break;
		}
	}
}