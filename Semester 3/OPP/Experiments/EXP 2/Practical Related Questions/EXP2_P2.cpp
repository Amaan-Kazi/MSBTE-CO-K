#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int rate = 412345, period = 35, year = 2024;
	
	cout << "Rate \t = " << setw(6) << setfill(' ') << rate << endl;
	cout << "Period \t = " << setw(6) << setfill(' ') << period << endl;
	cout << "Year \t = " << setw(6) << setfill(' ') << year << endl;
	
	return 0;
}
