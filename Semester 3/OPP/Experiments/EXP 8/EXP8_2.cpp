#include <iostream>
using namespace std;

class Object {
	static float g[8];
	
	public:
		float m;
	
	public:
		void displayWeight()
		{
			for (int i = 0; i < 8; i++)
			{
				cout << i+1 << ". " << m * g[i] << endl;
			}
		}
};

float Object::g[8] = {
	3.61,
	8.83,
	9.8,
	3.75,
	26.0,
	11.2,
	10.5,
	13.3
};; 

int main ()
{
	Object car;
	car.m = 153;
	car.displayWeight();
	
	return 0;
}
