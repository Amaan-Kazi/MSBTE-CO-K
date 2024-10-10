#include <iostream>
using namespace std;

class Mean {
    private:
        double num1;
        double num2;

    public:
        void assign(double a, double b)
		{
            num1 = a;
            num2 = b;
        }

        void displayMean()
		{
            double mean = (num1 + num2) / 2;
            cout << "The mean of " << num1 << " and " << num2 << " is " << mean << endl;
        }
};

int main()
{
    Mean meanObj;

    meanObj.assign(4, 8);
    meanObj.displayMean();

    return 0;
}
