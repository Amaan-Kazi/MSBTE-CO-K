#include <iostream>
using namespace std;

int main ()
{
	int *x = new int;
	
	cout << "Value of x: ";
	cin >> *x;
	
	cout << "Value = " << *x << endl << "Address = " << x;
	
	delete x;
	return 0;
}
