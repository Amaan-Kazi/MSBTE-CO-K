#include <iostream>
//#define REFER = 10;
using namespace std;

// reference variable
int reference = 20;

int main ()
{
	//cout << "REFER = " << REFER << endl;
	cout << "REFERENCE = " << ::reference << endl;
	return 0;
}
