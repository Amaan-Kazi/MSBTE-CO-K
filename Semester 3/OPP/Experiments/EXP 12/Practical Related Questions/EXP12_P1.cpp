#include <iostream>
using namespace std;

class Area {	
	public:
		float calcArea(float length, float breadth)
		{
			return length * breadth;
		}
};

class Perimeter {	
	public:
		float calcPerimeter(float length, float breadth)
		{
			return 2 * (length + breadth);
		}
};

class Rectangle : public Area, public Perimeter {
	float length;
	float breadth;
	
	public:
		void get_data()
		{
			cout << "Length: ";
			cin >> length;
			cout << "Breadth: ";
			cin >> breadth;
		}
		void display()
		{
			cout << "Area: " << calcArea(length, breadth) << endl;
			cout << "Perimeter: " << calcPerimeter(length, breadth) << endl;
		}
};

int main ()
{
	Rectangle rect;
    rect.get_data();
	rect.display();
	
	return 0;
}
