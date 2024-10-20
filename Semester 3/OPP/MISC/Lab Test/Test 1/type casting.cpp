#include <iostream>
using namespace std;
// Implicite and explicite
int main ()
{
	float fA, fB;
	int sum;
	char cA, cB;
	
	cout << "A: ";
	cin >> fA;
	cout << "B: ";
	cin >> fB;
	
	// Implicite type casting
	sum = fA + fB;
	cA = fA;
	cB = fB;
	
	cout << "sum (Implicitly casted to int) = " << sum << endl;
	cout << "A (Implicitly casted to char) = " << cA << endl;
	cout << "B (Implicitly casted to char) = " << cB << endl;
	
	cout << "\nExplicite type casting: " << endl;
	cout << "(int)A = " << (int)fA << endl;
	cout << "(int)B = " << (int)fB << endl;
	cout << "(char)A = " << (char)fA << endl;
	cout << "(char)B = " << (char)fB << endl;
	
	return 0;
}
