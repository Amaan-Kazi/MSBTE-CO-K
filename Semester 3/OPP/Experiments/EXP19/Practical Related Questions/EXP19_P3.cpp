#include <iostream>
using namespace std;

double area(double length, double width) {
    return length * width;
}

double area(double radius) {
    return 3.14 * radius * radius;
}

int main() {
    double length = 5.0, width = 3.0;
    double radius = 4.0;

    cout << "Area of rectangle: " << area(length, width) << endl;
    cout << "Area of circle: " << area(radius) << endl;

    return 0;
}
