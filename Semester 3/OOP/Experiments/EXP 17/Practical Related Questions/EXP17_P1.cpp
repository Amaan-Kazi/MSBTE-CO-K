#include <iostream>
using namespace std;

class Polygon {
	public:
		float width;
		float height;
		
		virtual float area() =0;
};

class rectangle : public Polygon {
	public:
		rectangle(float w, float h)
		{
			width = w;
			height = h;
		}
		float area()
		{
			return width * height;
		}
};

class triangle : public Polygon {
	public:
		triangle(float w, float h)
		{
			width = w;
			height = h;
		}
		float area()
		{
			return 0.5 * width * height;
		}
};

int main ()
{
	rectangle r1(50, 20);
	triangle t1(15, 20);
	
	Polygon *ptr;
	
	ptr = &r1;
	cout << "Rectangle Area: " << ptr->area() << endl;
	
	ptr = &t1;
	cout << "Triangle Area: " << ptr->area() << endl;
	
	return 0;
}
