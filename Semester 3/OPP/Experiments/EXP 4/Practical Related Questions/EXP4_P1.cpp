#include <iostream>
using namespace std;

class Room {
    private:
        double length;
        double breadth;
        double height;

    public:
        void setDimensions(double l, double b, double h)
		{
            length = l;
            breadth = b;
            height = h;
        }

        double calculateArea()
		{
            return length * breadth;
        }

        double calculateVolume()
		{
            return length * breadth * height;
        }
};

int main()
{
    Room room;
    double length, breadth, height;

    cout << "Length: ";
    cin >> length;
    cout << "Breadth: ";
    cin >> breadth;
    cout << "Height: ";
    cin >> height;

    room.setDimensions(length, breadth, height);

    cout << "Area: " << room.calculateArea() << endl;
    cout << "Volume: " << room.calculateVolume() << endl;

    return 0;
}
