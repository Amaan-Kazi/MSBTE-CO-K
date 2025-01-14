#include <iostream>
using namespace std;

class Parent {
public:
    int a;
    int b;

    virtual void read() {
        cout << "A: ";
        cin >> a;
        cout << "B: ";
        cin >> b;
    }

    virtual void display() {
        cout << "A: " << a << endl;
        cout << "B: " << b << endl;
    }
};

class Base : public Parent {
public:
    int c;
    int d;

    void read() override { 
        Parent::read(); 
        cout << "C: ";
        cin >> c;
        cout << "D: ";
        cin >> d;
    }

    void display() override { 
        Parent::display();
        cout << "C: " << c << endl;
        cout << "D: " << d << endl;
    }
};

int main() {
    Parent* animal = new Base(); 
    Parent* fish = new Parent(); 

    cout << endl << "Enter Animal: " << endl;
    animal->read(); 

    cout << endl << "Enter Fish: " << endl;
    fish->read(); 

    cout << endl << "Animal: " << endl;
    animal->display(); 

    cout << endl << "Fish: " << endl;
    fish->display(); 
    
    delete animal;
    delete fish;

    return 0;
}

