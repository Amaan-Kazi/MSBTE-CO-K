#include <iostream>
using namespace std;

int main ()
{
	int average;
	int OPP, DMS, DSU;
	
	cout << "Enter marks" << endl;
	cout << "OPP: ";
	cin >> OPP;
	cout << "DMS: ";
	cin >> DMS;
	cout << "DSU: ";
	cin >> DSU;
	
	average = (OPP + DMS + DSU)/3;
	cout << "Average (Implicitly type casted): " << average;
	
	return 0;
}
