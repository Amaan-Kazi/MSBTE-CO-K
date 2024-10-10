#include <iostream>
using namespace std;

class base {
	public:
		int a;
		int b;
		virtual void display()=0;
};

class derived : base {
	public:
		int c;
		int d;	
	
		derived (int a1, int b1, int c1, int d1){
			a=a1;
			b=b1;
			c=c1;
			d=d1;	
		}
		
		void display()
		{
			cout << "A: " << a << endl;
			cout << "B: " << b << endl;
			cout << "C: " << c << endl;
			cout << "D: " << d << endl;
		}
}; 

int main ()
{
	derived d1(5, 10, 15, 20);
	
	d1.display();
	return 0;
}
