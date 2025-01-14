#include <iostream>
using namespace std;

class Sum {
    public:
    int add(int a, int b){
        return a+b;
    }

    double add(double a,double b)
    {
        return a+b;
    }
};

int main ()
{
    Sum s1;

    int A;
    int B;

    float C;
    float D;

    cout<<"Enter A: ";
    cin>>A;
    cout<<"Enter B: ";
    cin>>B;

    cout << "Sum: " << s1.add(A, B) << endl;

    cout << "Enter C: ";
    cin >> C;
    cout << "Enter D: ";
    cin >> D;

    cout << "Sum: " << s1.add(C, D) << endl;

    return 0;
}