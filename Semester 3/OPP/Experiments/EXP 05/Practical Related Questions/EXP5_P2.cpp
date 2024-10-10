#include <iostream>
using namespace std;

class Complex {
    private:
        double real1;
        double imaginary1;
        double real2;
        double imaginary2;

    public:
        void read()
		{
            cout << "Enter real part 1: ";
            cin >> real1;
            cout << "Enter imaginary part 1: ";
            cin >> imaginary1;
            cout << "Enter real part 2: ";
            cin >> real2;
            cout << "Enter imaginary part 2: ";
            cin >> imaginary2;
        }

        void write()
		{
            cout << "\nComplex1: " << real1 << ", " << imaginary1 << endl;
            cout << "Complex2: " << real2 << ", " << imaginary2 << endl;
        }
        
        void add()
		{
            cout << "\nSum: " << real1 + real2 << ", " << imaginary1 + imaginary2 << endl;
        }
};

int main()
{
    Complex c1;
    
    c1.read();
    c1.write();
    c1.add();

    return 0;
}

