#include <iostream>
using namespace std;

class Example {
	int sum;
	
	public:
		int a;
		int b;
	
	public:
		void displaySum(int inputA, int inputB)
		{
			a = inputA;
			b = inputB;
			sum = a + b;
			
			cout << a << " + " << b  << " = " << sum << endl;
		}
};

int main ()
{
	Example e1;
	
	e1.displaySum(5, 27);
	return 0;
}
