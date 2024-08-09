#include <iostream>
using namespace std;

int main ()
{
	int a, b, average;
	
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	
	average = (a + b)/2;
	cout << "Average (Implicitely type casted) = " << average;
	
	return 0;
}
