#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

ifstream userFile;
ifstream adminAccessFile;
ifstream userAccessFile;
ifstream guestAccessFile;

class Account
{
    public:
    string name;
    string email;
    string password;
    string accessLevel;
    
    void greet();
};

class User : public Account
{
	public:
    User(string n, string e, string p)
	{
        name = n;
        email = e;
        password = p;
        accessLevel = "user";
    }
};

class Admin : public Account
{
	public:
    Admin(string n, string e, string p)
	{
        name = n;
        email = e;
        password = p;
        accessLevel = "admin";
    }
};

class Guest : public Account
{
	public:
    Guest(string n, string e, string p)
	{
        name = n;
        email = e;
        password = p;
        accessLevel = "guest";
    }
};

vector<Admin> Admins;
vector<User> Users;
vector<Guest> Guests;

void getAccounts()
{
    userFile.open("users.csv");
    if (!userFile.is_open())
	{
        cerr << "Error opening user file!" << endl;
        return;
    }
    
    string line;
    while (getline(userFile, line))
	{
        stringstream ss(line);
        string name, email, password, accessLevel;

        if (getline(ss, name, ',') && getline(ss, email, ',') && getline(ss, password, ',') && getline(ss, accessLevel))
		{
			if (accessLevel == "admin")
			{
				Admins.push_back(Admin(name, email, password));
			}
			else if (accessLevel == "user")
			{
				Users.push_back(User(name, email, password));
			}
			else if (accessLevel == "guest")
			{
				Guests.push_back(Guest(name, email, password));
			}
        }
    }
    userFile.close();
}


void readAccessFile(string al)
{
	adminAccessFile.open("data/admin.txt");
	userAccessFile.open("data/user.txt");
	guestAccessFile.open("data/guest.txt");
	
	cout << endl << al << " access file:" << endl;
	
	if (al == "admin")
	{
		std::string line;
    	while (std::getline(adminAccessFile, line)) {
        	std::cout << line << std::endl;
    	}
    	
    	cout << endl << "user access file:" << endl;
    	while (std::getline(userAccessFile, line)) {
        	std::cout << line << std::endl;
    	}
    	
    	cout << endl << "guest access file:" << endl;
    	while (std::getline(guestAccessFile, line)) {
        	std::cout << line << std::endl;
    	}
	}
	else if (al == "user")
	{
		std::string line;
    	while (std::getline(userAccessFile, line)) {
        	std::cout << line << std::endl;
    	}
	}
	else if (al == "guest")
	{
		std::string line;
    	while (std::getline(guestAccessFile, line)) {
        	std::cout << line << std::endl;
    	}
	}
	
	adminAccessFile.close();
	userAccessFile.close();
	guestAccessFile.close();
}


void displayAccounts()
{
	cout << endl << "Admins" << endl;
    for (size_t i = 0; i < Admins.size(); ++i)
	{
        cout << "Name: " << Admins[i].name << " | Email: " << Admins[i].email << endl;
    }
    
    cout << endl << "Users" << endl;
    for (size_t i = 0; i < Users.size(); ++i)
	{
        cout << "Name: " << Users[i].name << " | Email: " << Users[i].email << endl;
    }	
	
	cout << endl << "Guests" << endl;
    for (size_t i = 0; i < Guests.size(); ++i)
	{
        cout << "Name: " << Guests[i].name << " | Email: " << Guests[i].email << endl;
    }
}

string login(const string& email, const string& password)
{
    for (size_t i = 0; i < Users.size(); ++i)
	{
        if (Users[i].email == email && Users[i].password == password)
		{
            return "user";
        }
        else if (Admins[i].email == email && Admins[i].password == password)
		{
            return "admin";
        }
        else if (Guests[i].email == email && Guests[i].password == password)
		{
            return "guest";
        }
    }
    return "none";
}


void registerUser(const string& name, const string& email, const string& password)
{
	string accessLevel = "user";
    Users.push_back(User(name, email, password));
    ofstream outFile("users.csv", ios::app);
    
    if (outFile.is_open())
	{
        outFile << name << "," << email << "," << password << "," << accessLevel << endl;
        outFile.close();
    }
	else
	{
        cerr << "Error opening user file for writing!" << endl;
    }
}

inline void clearScreen()
{
    system("cls");
}

int main()
{
    getAccounts();
	string accessLevel;

    int input;
    bool authenticated = false;
    
    while (!authenticated)
	{
        clearScreen();
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
            case 1: {
                string email, password;
                
                cout << "Email: ";
                cin.ignore();
                getline(cin, email);
                cout << "Password: ";
                getline(cin, password);

				string level = login(email, password);

                if (level == "none")
				{
                    cout << "Invalid email or password!" << endl;
                }
				else
				{
                    cout << "Successfully Logged In" << endl;
                    accessLevel = level;
                    authenticated = true;
                }
                break;
            }
            case 2: {
                string name, email, password;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Email: ";
                getline(cin, email);
                cout << "Password: ";
                getline(cin, password);

                registerUser(name, email, password);
                cout << "Registration successful!" << endl;
                
                accessLevel = "user";
                authenticated = true;
				break;
            }
            case 3:
                displayAccounts();
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
        }

        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
    }

	clearScreen();
	cout << "Authenticated" << endl;
	
	readAccessFile(accessLevel);
	
    return 0;
}

