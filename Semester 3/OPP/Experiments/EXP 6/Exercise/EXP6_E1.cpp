#include <iostream>
using namespace std;

class Number {
    private:
        double n1;
        double n2;

    public:
        inline void setValues(double x, double y)
		{
            n1 = x;
            n2 = y;
        }

        inline double add()
		{
            return n1 + n2;
        }

        inline double subtract()
		{
            return n1 - n2;
        }

        inline double multiply()
		{
            return n1 * n2;
        }

        inline double divide()
		{
            return n1 / n2;
        }
};

int main()
{
    Number num;
    double a, b;

    cout << "Num1: ";
    cin >> a;
    cout << "Num2: ";
    cin >> b;

    num.setValues(a, b);

    cout << "Addition: " << num.add() << endl;
    cout << "Subtraction: " << num.subtract() << endl;
    cout << "Multiplication: " << num.multiply() << endl;
    cout << "Division: " << num.divide() << endl;

    return 0;
}
