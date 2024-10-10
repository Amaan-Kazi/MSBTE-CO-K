#include <iostream>
using namespace std;

int main ()
{
	int OPP, DSU, DMS, DTE, percentage;
	
	cout << "Enter marks" << endl;
	cout << "OPP: ";
	cin >> OPP;
	cout << "DSU: ";
	cin >> DSU;
	cout << "DMS: ";
	cin >> DMS;
	cout << "DTE: ";
	cin >> DTE;
	
	percentage = ((OPP + DSU + DMS + DTE) * 100) / 400;
	cout << "Percentage = " << percentage << "%";
	
	return 0;
}
