#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;

ifstream adminFile;
ifstream userFile;
userFile.open("users.csv");
adminFile.open("admins.csv");

class Account {
	public:
		string name;
		string email;
		string password;
};

class Admin : public Account {
};

class User : public Account {
	public:
		User(string n, string e, string p)
		{
			name = n;
			email = e;
			password = p;
		}
};

std::vector<User> Users;

void getUsers()
{
	string line;
	
	while (getline(userFile, line)) {
        stringstream ss(line);
        string name, username, password;

        // Split the line by comma
        if (getline(ss, name, ',') && getline(ss, username, ',') && getline(ss, password)) {
            // Create a User object and add it to the vector
            Users.emplace_back(name, username, password);
        }
    }
}

int main ()
{
	Account a;
	int input;
	
	start:
	system("cls");
	cout << "0. Exit" << endl;
	cout << "1. Login" << endl;
	cout << "2. Register" << endl;
	cout << "3. Display Accounts" << endl;

	cout << "Input: ";
	cin >> input;
	
	switch (input)
	{
		case 0:
			return 0;
			break;
		case 1:
			cout << "ABC";
			break;
		case 2:
			cout << "ABC";
			break;
		case 3:
			cout << "ABC";
			break;
		default:
			cout << "Invalid";
			getch();
			goto start;
			break;
	}
	
	return 0;
}
