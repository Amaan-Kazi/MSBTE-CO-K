#include <iostream>
using namespace std;

class Calculate {
	public:
		static int rate;
		int principal;
		int duration;
		
		float simpleInterest;
		
		float interest()
		{
			simpleInterest = (principal * rate * duration) / 100;
			return simpleInterest;
		}
};

int Calculate::rate = 5;

int main ()
{
	Calculate c1;
	
	cout << "Enter details to find amount for rate of interest of 5%" << endl;
	cout << "Duration: ";
	cin >> c1.duration;
	cout << "Principal: ";
	cin >> c1.principal;
	
	cout << "Simple Interest: " << c1.interest();
	
	return 0;
}
