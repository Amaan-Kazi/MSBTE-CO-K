#include <iostream>
using namespace std;

int x;

int main ()
{
	bool a = true;
	int x = 10;
	cout << "Global x: " << ::x << endl;
	cout << "Local x: " << x;
	cout << "a: " << a;
	return 0;
}
