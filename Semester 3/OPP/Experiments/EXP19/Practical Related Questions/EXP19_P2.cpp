#include<iostream>
using namespace std;

class Number {
	public:
		int num;
		
		Number(int x)
		{
			num = x;
		}
		
		friend int operator++(Number &num1)
		{
			return num1.num -= 1;
		}
		friend int operator--(Number &num2)
		{
			return num2.num += 1;
		}
}; 

int main ()
{
	int a1, b1;
	
	cout << "A: ";
	cin >> a1;
	cout << "B: ";
	cin >> b1;
	
	Number a(a1);
	Number b(b1);
	
	cout << "A  " << ++a << endl;
	cout << "B  " << --b << endl;
	return 0;
}
