#include <iostream>
using namespace std;

class Number {
    private:
        int value;

    public:
        void setValue(int v)
		{
            value = v;
        }

        int getSquare()
		{
            return value * value;
        }
};

int main()
{
    Number num;
    int x;

    cout << "Number: ";
    cin >> x;

    num.setValue(x);
    cout << "Square of " << x << " is " << num.getSquare() << endl;

    return 0;
}

