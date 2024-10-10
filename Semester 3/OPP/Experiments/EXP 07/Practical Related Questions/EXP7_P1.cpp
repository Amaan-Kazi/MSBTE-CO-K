#include <iostream>
using namespace std;

class Calculation {
    public:
        double num1;
        double num2;
        
        friend void add(Calculation c);
        friend void subtract(Calculation c);
        friend void multiply(Calculation c);
        friend void divide(Calculation c);
};

void add(Calculation c)
{
    cout << "Addition: " << (c.num1 + c.num2) << endl;
}

void subtract(Calculation c)
{
    cout << "Subtraction: " << (c.num1 - c.num2) << endl;
}

void multiply(Calculation c)
{
    cout << "Multiplication: " << (c.num1 * c.num2) << endl;
}

void divide(Calculation c)
{
    cout << "Division: " << (c.num1 / c.num2) << endl;
}

int main()
{
    double a, b;
    Calculation calc;

    cout << "Num2: ";
    cin >> a;
    cout << "Num1: ";
    cin >> b;

    calc.num1 = a;
    calc.num2 = b;

    add(calc);
    subtract(calc);
    multiply(calc);
    divide(calc);

    return 0;
}

