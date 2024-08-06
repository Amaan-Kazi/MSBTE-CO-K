#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main ()
{
	int gd = DETECT, gm;
	clrscr();

	initgraph(&gd, &gm, "C://TURBOC3/BGI/ASD");

	circle(300, 200, 150);
	circle(250, 150, 35);
	circle(350, 150, 35);
	arc(300,250,180,360,50);
	line(250,250,350,250);

	getch();
	closegraph();
}
