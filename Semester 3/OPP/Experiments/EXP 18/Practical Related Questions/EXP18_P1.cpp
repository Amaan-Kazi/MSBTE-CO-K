#include <iostream>
using namespace std;

class Exchange {
	public:		
		void interchange(int a1, int b1)
		{
			int temp;
			
			temp = a1;
			a1 = b1;
			b1 = temp;
			
			cout << "Swapped ints: " << a1 << ", " << b1 << endl;
		}
		void interchange(double c1, double d1)
		{
			double temp;
			
			temp = c1;
			c1 = d1;
			d1 = temp;
			
			cout << "Swapped floats: " << c1 << ", " << d1 << endl;
		}
		void interchange(char e1, char f1)
		{
			char temp;
			
			temp = e1;
			e1 = f1;
			f1 = temp;
			
			cout << "Swapped chars: " << e1 << ", " << f1 << endl;
		}
};

int main ()
{
	Exchange e1;
	
	e1.interchange(5, 12);
	e1.interchange(0.86, 4.91);
	e1.interchange('A', 'G');
	
	return 0;
}
