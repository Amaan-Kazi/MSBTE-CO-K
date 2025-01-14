#include<iostream>
using namespace std;

class Employee {
	public:
	int empid;
	int empcode;
		virtual void displayData()
		{
			cout << "Temp";
		}
};

class Programmer : public Employee {
	public:
		string skill;
		Programmer (int id, int code, string s)
		{
			empid = id;
			empcode = code;
			skill = s;
		}
		void displayData()
		{
			cout << "EmpId: " << empid << endl;
			cout << "EmpCode: " << empcode << endl;
			cout << "Skill: " << skill << endl;
		}
		
};

class Manager : public Employee {
	public:
		string department;
		Manager (int id, int code, string dept)
		{
			empid = id;
			empcode = code;
			department = dept;
		}
		void displayData()
		{
			cout << "EmpId: " << empid << endl;
			cout << "EmpCode: " << empcode << endl;
			cout << "Department: " << department << endl;
		}
};
    
int main ()
{
    Programmer p1(1, 1001, "Skill less");
    Manager m1(2, 1002, "No department");
    
    p1.displayData();
    m1.displayData();
    
    return 0;
}
