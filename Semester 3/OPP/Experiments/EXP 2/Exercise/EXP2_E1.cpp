#include <iostream>
using namespace std;

class student {
	public:
		string name;
		int age;
		void getDetails();
		void displayPercentage();
	private:
		float percentage;
};

void student::getDetails()
{
	cout << "Name: ";
	cin >> name;
	cout << "Age: ";
	cin >> age;
	cout << "Percentage: ";
	cin >> percentage;
}

void student::displayPercentage()
{
	cout << "Percentage: " << percentage;
}


int main ()
{
	student s1;
	
	s1.getDetails();
	s1.displayPercentage();
	
	return 0;
}
