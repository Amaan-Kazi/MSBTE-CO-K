#include <iostream>
using namespace std;
// create array of int using new
int main ()
{
	int n, i;
	
	cout << "Enter number of elements: ";
	cin >> n;
	
	int *arr = new int[n];
	
	for (i = 0; i < n; i++)
	{
		cout << i << ". ";
		cin >> *(arr+i);
	}
	
	cout << "\nDisplaying array" << endl;
	for (i = 0; i < n; i++)
	{
		cout << i << ". " << *(arr+i) << "\t [" << arr+i << "]" << endl;
	}
	
	delete arr;
	return 0;
}
