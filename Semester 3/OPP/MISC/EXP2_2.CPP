#include <iostream.h>
#include <iomanip.h>
#include <stdio.h>
#include <conio.h>

float num;

int main ()
{
	clrscr();
	//float num;

	cout << "Enter a float" << endl;
	cin >> num;
	cout << setfill('0') << setw(6) << setprecision(2) << num;

	getch();
	return 0;
}