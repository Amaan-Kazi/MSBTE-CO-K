#include <stdio.h>
#include <iostream>

using namespace std;

int main ()
{
	int x = 5;
	float y;
	
	// Explicite type casting
	cout << "Value of x (int): ";
	cin >> x;
	
	y = (float)x/2;
	cout << "y = x / 2 \n";
	cout << y << " = " << x << " / 2";
	
	return 0;
}
