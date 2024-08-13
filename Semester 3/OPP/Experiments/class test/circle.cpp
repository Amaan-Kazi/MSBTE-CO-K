#include <iostream>
using namespace std;

const float pi = 3.14;

class Circle {
	float radius;
	float area;
	float perimeter;
	
	public:
		Circle(float inputRadius)
		{
			radius = inputRadius;
			area = pi*radius*radius;
			perimeter = 2*pi*radius;
		}
		void displayData()
		{
			cout << "Radius: " << radius << endl;
			cout << "Area: " << area << endl;
			cout << "Perimeter: " << perimeter << endl;
		}
};

int main ()
{
	Circle c1(7);
	Circle c2(14);
	
	cout << "Circle 1: " << endl;
	c1.displayData();
	
	cout << "Circle 2: " << endl;
	c2.displayData();
	
	return 0;
}
