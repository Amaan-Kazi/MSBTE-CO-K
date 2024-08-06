#include <iostream>
using namespace std;

int a = 10;

int main ()
{
	int a = 5;
	
	cout << "Local a: " << a << endl;
	cout << "Gloal a: " << ::a;
	
	return 0;
}
