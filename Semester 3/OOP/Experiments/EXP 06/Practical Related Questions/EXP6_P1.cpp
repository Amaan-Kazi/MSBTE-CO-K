#include <iostream>
using namespace std;

class Rectangle {
    private:
        double length;
        double width;

    public:
        inline void setDimensions(double l, double w)
		{
            length = l;
            width = w;
        }

        inline double calculateArea()
		{
            return length * width;
        }
};

int main()
{
    Rectangle rect;
    double l, w;

    cout << "Length: ";
    cin >> l;
    cout << "Width: ";
    cin >> w;

    rect.setDimensions(l, w);
    cout << "The area of the rectangle is: " << rect.calculateArea() << endl;

    return 0;
}
