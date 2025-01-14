#include <iostream>
using namespace std;

int main ()
{
	int x, a, b, c;
	
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	
	x = (-b - ( (b * b) - (4 * a * c) ) ) / (2 * a);
	cout << "x = " << x;
	
	return 0;
}
