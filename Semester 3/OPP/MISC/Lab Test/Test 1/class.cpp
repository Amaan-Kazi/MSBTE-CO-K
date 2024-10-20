#include <iostream>
using namespace std;

class Student {
	public:
		int rollNo;
		string name;
	private:
		int marks;
	public:
		int setData(int inputRollNo, string inputName, int inputMarks)
		{
			rollNo = inputRollNo;
			name = inputName;
			marks = inputMarks;
		}
		void displayData()
		{
			cout << "RollNo: " << rollNo << endl;
			cout << "Name: " << name << endl;
			cout << "Marks: " << marks << endl;
		}
};

int main ()
{
	Student s1;
	
	s1.setData(1, "Student 1", 95);
	s1.displayData();
	
	return 0;
}
