#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main ()
{
	int gd = DETECT, gm;
	clrscr();

	initgraph(&gd, &gm, "C://TURBOC3/BGI/ASD2");

	// Computer
	rectangle(100, 50, 450, 250); //x1,y1,x2,y2
	rectangle(90, 40, 460, 260);
	rectangle(210,260,340,320);
	rectangle(120, 320, 430, 330);

	// Smiley Face
	circle(375, 150, 50);
	circle(350, 135, 15);
	circle(400, 135, 15);
	arc(375,175,180,360,10);
	line(365,175,385,175);

	// House

	getch();
	closegraph();
}
