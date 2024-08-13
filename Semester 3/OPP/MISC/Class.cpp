#include <stdio.h>
#include <iostream>

using namespace std;

class Car {
	public:
		string name;
		int sellingPrice;
	private:
		int costPrice;
		int profit;
		
	public:
		Car(string carName, int carSellingPrice, int carCostPrice)
		{
			name = carName;
			sellingPrice = carSellingPrice;
			costPrice = carCostPrice;
			
			profit = carSellingPrice - carCostPrice;
		}
		~Car()
		{
			cout << "Destructed Car: " << name << endl;
		}
		
		void displayDetails()
		{
			cout << "Car Name: " << name << endl;
			cout << "Car Selling Price: " << sellingPrice << endl;
			cout << "Car Cost Price: " << costPrice << endl;
			cout << "Car Profit: " << profit << endl;
		}
};

int main ()
{
	Car Toyota("Toyota Supra", 580000, 500000);
	
	Toyota.displayDetails();
	
	return 0;
}
