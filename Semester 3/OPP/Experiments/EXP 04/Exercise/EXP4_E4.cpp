#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        int rollNo;

    public:
        void acceptData()
		{
            cout << "Student Name: ";
            getline(cin, name);
            cout << "Roll Number: ";
            cin >> rollNo; 
        }

        void displayData()
		{
            cout << "Student Name: " << name << endl;
            cout << "Roll Number: " << rollNo << endl;
        }
};

int main()
{
    Student s1;

	cout << "Enter Data" << endl;
    s1.acceptData();
    
    cout << "\nDisplaying Data" << endl;
    s1.displayData();

    return 0;
}
