#include<iostream.h>
#include<stdio.h>
#include<conio.h>

void main()
{
	clrscr();
	int *n = new int;
	*n = 10;

	cout << "the number is:" << *n << endl;
	delete n;
	cout << "the number again is " << *n;

	getch();
}