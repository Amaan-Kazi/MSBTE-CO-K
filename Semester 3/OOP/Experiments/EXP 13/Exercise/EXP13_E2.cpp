#include <iostream>
using namespace std;

class Staff {
public:
    int code;
    string name;

    void input() {
        cout << "Enter staff code: ";
        cin >> code;
        cin.ignore();
        cout << "Enter staff name: ";
        getline(cin, name);
    }

    void display() const {
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
    }
};

class Teacher : public Staff {
public:
    string subject;
    string publication;

    void input() {
        Staff::input();
        cout << "Enter subject: ";
        getline(cin, subject);
        cout << "Enter publication: ";
        getline(cin, publication);
    }

    void display() const {
        Staff::display();
        cout << "Subject: " << subject << endl;
        cout << "Publication: " << publication << endl;
    }
};

class Officer : public Staff {
public:
    int grade;

    void input() {
        Staff::input();
        cout << "Enter grade: ";
        cin >> grade;
        cin.ignore();
    }

    void display() const {
        Staff::display();
        cout << "Grade: " << grade << endl;
    }
};

class Typist : public Staff {
public:
    float speed;

    void input() {
        Staff::input();
        cout << "Enter typing speed: ";
        cin >> speed;
        cin.ignore();
    }

    void display() const {
        Staff::display();
        cout << "Typing Speed: " << speed << " words per minute" << endl;
    }
};

class Regular : public Typist {
public:
    int wages2;

    void input() {
        Typist::input();
        cout << "Enter regular wages: ";
        cin >> wages2;
        cin.ignore();
    }

    void display() const {
        Typist::display();
        cout << "Regular Wages: " << wages2 << endl;
    }
};

class Casual : public Typist {
public:
    float wages;

    void input() {
        Typist::input();
        cout << "Enter casual wages: ";
        cin >> wages;
        cin.ignore();
    }

    void display() const {
        Typist::display();
        cout << "Casual Wages: " << wages << endl;
    }
};

int main() {
    Teacher t1;
    Officer o1;
    Regular r1;
    Casual c1;

    cout << "Enter details for Teacher:" << endl;
    t1.input();
    cout << "\nDetails of Teacher:" << endl;
    t1.display();

    cout << "\nEnter details for Officer:" << endl;
    o1.input();
    cout << "\nDetails of Officer:" << endl;
    o1.display();

    cout << "\nEnter details for Regular Typist:" << endl;
    r1.input();
    cout << "\nDetails of Regular Typist:" << endl;
    r1.display();

    cout << "\nEnter details for Casual Typist:" << endl;
    c1.input();
    cout << "\nDetails of Casual Typist:" << endl;
    c1.display();

    return 0;
}

