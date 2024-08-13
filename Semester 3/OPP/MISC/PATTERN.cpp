#include <stdio.h>
#include <iostream>

using namespace std;

int main ()
{
	int i, j, stars = 1, lines, spaces;
	
	cout << "Number of stars in center: ";
	cin >> lines;
	
	spaces = lines-1;
	
	for (i = 0; i < lines; i++)
	{
		for (j = 0; j < spaces; j++)
		{
			cout << " ";
		}
		for (j = 1; j < stars + 1; j++)
		{
			cout << " " << j;
			//cout << " *";
		}
		cout << endl;
		stars++;
		spaces--;
	}
	stars-=2;
	spaces+=2;
	for (i = 0; i < lines; i++)
	{
		for (j = 0; j < spaces; j++)
		{
			cout << " ";
		}
		for (j = 1; j < stars + 1; j++)
		{
			cout << " " << j;
			//cout << " *";
		}
		cout << endl;
		stars--;
		spaces++;
	}
	
	return 0;
}
