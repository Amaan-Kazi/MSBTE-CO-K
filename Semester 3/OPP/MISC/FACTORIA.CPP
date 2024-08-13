#include <stdio.h>
#include <conio.h>
#include <iostream.h>

int factorial(int num)
{
	if (num == 0)
	{
		return 1;
	}
	return num * factorial (num-1);
}

int main ()
{
	clrscr();
	int num = 5;

	cout << "Enter the number to find factorial of: ";
	cin >> num;
	cout << "factorial of " << num << " is " << factorial(num);

	getch();
	return 0;
}