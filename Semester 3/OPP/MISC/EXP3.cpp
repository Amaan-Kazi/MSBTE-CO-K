#include <stdio.h>
#include <iostream>

using namespace std;

int main ()
{
	int x = 15;
	float m = 2.1, y;
	
	// Implicite type casting
	cout << "Value of x (int): ";
	cin >> x;
	cout << "Value of m (float): ";
	cin >> m;
	
	y = m * x;
	cout << "y = m * x (implicit type casting) \n";
	cout << y << " = " << m << " * " << x;
	
	return 0;
}
