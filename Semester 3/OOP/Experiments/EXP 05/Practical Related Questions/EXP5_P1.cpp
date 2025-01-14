#include <iostream>
using namespace std;

class Circle {
    private:
        double radius;
        double area;

    public:
        void read()
		{
		    cout << "Radius: ";
		    cin >> radius;
		}
		
        void compute()
		{
    		area = 3.14159 * radius * radius;
		}
		
        void display();
};

void Circle::display()
{
    cout << "\nRadius: " << radius << endl << "Area: " << area << endl;
}

int main()
{
    Circle c;

    c.read();
    c.compute();
    c.display();

    return 0;
}
