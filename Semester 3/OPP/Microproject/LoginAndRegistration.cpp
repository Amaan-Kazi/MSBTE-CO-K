#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

ifstream userFile;

class Account
{
    public:
    string name;
    string email;
    string password;
};

class User : public Account
{
    public:
    User(string n, string e, string p, string aL)
	{
        name = n;
        email = e;
        password = p;
        accessLevel = aL
    }
};

vector<User> Users;

void getUsers()
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
        string name, email, password;

        if (getline(ss, name, ',') && getline(ss, email, ',') && getline(ss, password))
		{
            Users.push_back(User(name, email, password));
        }
    }
    userFile.close();
}

void displayAccounts()
{
    for (size_t i = 0; i < Users.size(); ++i)
	{
        cout << "Name: " << Users[i].name << " | Email: " << Users[i].email << endl;
    }
}

bool login(const string& email, const string& password)
{
    for (size_t i = 0; i < Users.size(); ++i)
	{
        if (Users[i].email == email && Users[i].password == password)
		{
            return true;
        }
    }
    return false;
}


void registerUser(const string& name, const string& email, const string& password)
{
    Users.push_back(User(name, email, password));
    ofstream outFile("users.csv", ios::app);
    
    if (outFile.is_open())
	{
        outFile << name << "," << email << "," << password << "," << << endl;
        outFile.close();
    }
	else
	{
        cerr << "Error opening user file for writing!" << endl;
    }
}

void clearScreen()
{
    system("cls");
}

int main()
{
    getUsers();

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

                if (login(email, password))
				{
                    cout << "Login successful!" << endl;
                    authenticated = true;
                }
				else
				{
                    cout << "Invalid email or password!" << endl;
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
	
	
	
    return 0;
}
