#include<iostream>
using namespace std;

class subtraction {
	public:
		int num;
		
		subtraction(int x)
		{
			num = x;
		}
		
		friend int operator-(subtraction &num1, subtraction &num2)
		{
			return num1.num + num2.num;
		}
}; 

int main ()
{
	int a1, b1;
	
	cout << "A: ";
	cin >> a1;
	cout << "B: ";
	cin >> b1;
	
	subtraction a(a1);
	subtraction b(b1);
	
	cout << "A -(overloaded to +) B = " << a-b << endl;
	return 0;
}
