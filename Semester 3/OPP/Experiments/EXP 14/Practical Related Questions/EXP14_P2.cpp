#include <iostream>
using namespace std;

class Account {
	protected:
		int accountNumber;
		string accountHolderName;
		float balance;
};

class SavingAccount : virtual public Account {
	public:
		float interestRate;
		
		SavingAccount() {
		}
		
		SavingAccount(int aNumber, string aHolderName, float bal, float iRate)
		{
			accountNumber = aNumber;
			accountHolderName = aHolderName;
			balance = bal;
			interestRate = iRate;
		}
		
		virtual void displayDetails()
		{
			cout << "Account Number: " << accountNumber << endl;
			cout << "Account Holder Name: " << accountHolderName << endl;
			cout << "Balance: " << balance << endl;
			cout << "Interest Rate: " << interestRate << endl << endl;
		}
};

class CurrentAccount : virtual public Account {
	public:
		float overdraftLimit;
		
		CurrentAccount() {
		}
		
		CurrentAccount(int aNumber, string aHolderName, float bal, float oLimit)
		{
			accountNumber = aNumber;
			accountHolderName = aHolderName;
			balance = bal;
			overdraftLimit = oLimit;
		}
		
		virtual void displayDetails()
		{
			cout << "Account Number: " << accountNumber << endl;
			cout << "Account Holder Name: " << accountHolderName << endl;
			cout << "Balance: " << balance << endl;
			cout << "Overdraft Limit: " << overdraftLimit << endl << endl;
		}
};

class FixDepositAccount : public SavingAccount, public CurrentAccount {
	public:
		float depositTerm;
		
		FixDepositAccount(int aNumber, string aHolderName, float bal, float dTerm, float iRate, float oLimit)
		{
			accountNumber = aNumber;
			accountHolderName = aHolderName;
			balance = bal;
			depositTerm = dTerm;
			interestRate = iRate;
			overdraftLimit = oLimit;
		}
		
		void displayDetails()
		{
			cout << "Account Number: " << accountNumber << endl;
			cout << "Account Holder Name: " << accountHolderName << endl;
			cout << "Balance: " << balance << endl;
			cout << "Deposit Term: " << depositTerm << endl;
			cout << "Interest Rate: " << interestRate << endl;
			cout << "Overdraft Limit: " << overdraftLimit << endl << endl;
		}
};

int main ()
{
	SavingAccount sa1(3007432, "Saving Account Holder", 132000.04, 7.25);
	CurrentAccount ca1(2856003, "Current Account Holder", 200600.43, 25000);
	FixDepositAccount fda1(3008619, "Fix Deposit Account Holder", 380527.86, 3.5, 15.8, 20000);
	
	sa1.displayDetails();
	ca1.displayDetails();
	fda1.displayDetails();
	
	return 0;
}
