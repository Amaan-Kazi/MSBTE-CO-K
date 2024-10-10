#include <iostream>
using namespace std;

class Staff {
    private:
        string name;
        double basicSalary;
        double DA;
        double HRA;
        double grossSalary;

    public:
        void acceptData()
		{
            cout << "Enter staff name: ";
            getline(cin, name);
            cout << "Basic Salary: ";
            cin >> basicSalary;
            
            DA = 0.745 * basicSalary;
            HRA = 0.30 * basicSalary;
            
            grossSalary = basicSalary + DA + HRA;
        }

        void displayData()
		{
            cout << "Staff Name: " << name << endl;
            cout << "Basic Salary: " << basicSalary << endl;
            cout << "DA (Dearness Allowance): " << DA << endl;
            cout << "HRA (House Rent Allowance): " << HRA << endl;
            cout << "Gross Salary: " << grossSalary << endl;
        }
};

int main()
{
    Staff s1;
    
    s1.acceptData();
    s1.displayData();

    return 0;
}
