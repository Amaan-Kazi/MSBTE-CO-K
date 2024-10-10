#include <iostream>
using namespace std;

class Number {
    public:
        int value;
        
        friend void exchange(Number &a, Number &b);

        void display()
		{
            cout << value << endl;
        }
};

void exchange(Number &a, Number &b)
{
    int temp = a.value;
    a.value = b.value;
    b.value = temp;
}

int main()
{
    Number num1, num2;
    
    cout << "num1: ";
    cin >> num1.value;
    cout << "num2: ";
    cin >> num2.value;

    exchange(num1, num2);

    cout << "\nExchanged:" << endl;
    cout << "num1: "; num1.display();
    cout << "num2: "; num2.display();

    return 0;
}
