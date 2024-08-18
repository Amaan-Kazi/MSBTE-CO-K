#include <iostream>
using namespace std;

class Numbers {
	public:
		int a;
		int b;
		
		void displayValues();
};

void Numbers::displayValues()
{
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	cout << "Sum: " << a + b;
}

int main ()
{
	Numbers n;
	
	n.a = 5;
	n.b = 10;
	
	n.displayValues();
	
	return 0;
}
