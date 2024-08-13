#include <stdio.h>
#include <conio.h>
#include <iostream.h>

int x = 10; // GLOBAL

void main ()
{
	clrscr();
	int x = 20; // LOCAL VARIABLE

	cout << "Local x = " << x << endl;
	cout << "Global x = " << ::x;

	getch();
}