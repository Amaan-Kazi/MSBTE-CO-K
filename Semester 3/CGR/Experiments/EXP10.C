#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main ()
{
	int x1, x2, y1, y2, depth, tx, ty, sx, sy, input = -1;
	int gd = DETECT, gm;

	clrscr();

	printf("x1: ");
	scanf("%d",&x1);

	printf("y1: ");
	scanf("%d",&y1);

	printf("x2: ");
	scanf("%d",&x2);

	printf("y2: ");
	scanf("%d",&y2);

	printf("depth: ");
	scanf("%d", &depth);

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	setfillstyle(0,6);
	bar3d(x1, y1, x2, y2, depth, 1);

	getch();
	closegraph();

	while (1)
	{
		clrscr();
		printf("Operation \n");
		printf("0. Exit \n");
		printf("1. Translate \n");
		printf("2. Scale \n");
		printf("Input: ");
		scanf("%d", &input);

		switch (input)
		{
			case 0:
				exit(1);
				break;
			case 1:
				printf("Translate x: ");
				scanf("%d",&tx);

				printf("Translate y: ");
				scanf("%d",&ty);

				initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

				setfillstyle(11, 6);
				bar3d(x1+tx, y1+ty, x2+tx, y2+ty, depth, 1);

				getch();
				closegraph();
				break;
			case 2:
				printf("Scaling Factor x: ");
				scanf("%d",&sx);

				printf("Scaling Factor y: ");
				scanf("%d",&sy);

				initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

				setfillstyle(11, 6);
				bar3d(x1, y1, x2 * sx, y2 * sy, depth, 1);

				getch();
				closegraph();
				break;
			default:
				break;
		}
	}
}