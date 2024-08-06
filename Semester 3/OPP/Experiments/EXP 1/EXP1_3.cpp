#include <iostream>
using namespace std;

int main ()
{
	int a, b;
	
	cout << "Value of a: ";
	cin >> a;
	
	cout << "Value of b: ";
	cin >> b;
	
	if (a > b)
		cout << "a is greater than b";
	else if (b > a)
		cout << "b is greater than a";
	else
		cout << "both numbers are equal";
	
	return 0;
}
