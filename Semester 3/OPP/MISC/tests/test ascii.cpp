#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int i;
	for (i = 0; i < 256; i++)
	{
		// print ascii
		cout << i << ". " << (char)i << endl;
	}
	return 0;
}
