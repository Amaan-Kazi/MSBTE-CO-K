#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

enum AccessLevel { LEVEL1, LEVEL2, LEVEL3, LEVEL4, LEVEL5 };

class Account {
public:
    string name;
    string email;
    string password;
    AccessLevel accessLevel;

    Account(string n, string e, string p, AccessLevel level) 
        : name(n), email(e), password(p), accessLevel(level) {}
};

class User : public Account {
public:
    User(string n, string e, string p, AccessLevel level)
        : Account(n, e, p, level) {}
};

class Admin : public Account {
public:
    Admin(string n, string e, string p) : Account(n, e, p, LEVEL5) {}

    void changeAccessLevel(User& user, AccessLevel newLevel) {
        user.accessLevel = newLevel;
        cout << "Changed access level of " << user.name << " to LEVEL " << newLevel + 1 << endl;
    }
};

class AccessFileManager {
public:
    void readAccessFile(const User& user) {
        string filename = "level" + intToString(user.accessLevel + 1) + ".txt"; // e.g., level1.txt
        ifstream file(filename.c_str());
        if (!file.is_open()) {
            cerr << "Error opening access file for level " << user.accessLevel + 1 << endl;
            return;
        }
        
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    string intToString(int num) {
        stringstream ss;
        ss << num;
        return ss.str();
    }
};

vector<User> Users;

void loadUsers() {
    ifstream userFile("users.csv");
    if (!userFile.is_open()) {
        cerr << "Error opening user file!" << endl;
        return;
    }

    string line;
    while (getline(userFile, line)) {
        stringstream ss(line);
        string name, email, password;
        int level;
        if (getline(ss, name, ',') && getline(ss, email, ',') && getline(ss, password, ',') && (ss >> level)) {
            Users.push_back(User(name, email, password, static_cast<AccessLevel>(level)));
        }
    }
    userFile.close();
}

void displayAccounts() {
    for (size_t i = 0; i < Users.size(); ++i) {
        cout << "Name: " << Users[i].name << ", Email: " << Users[i].email 
             << ", Access Level: " << Users[i].accessLevel + 1 << endl;
    }
}

bool login(const string& email, const string& password) {
    for (size_t i = 0; i < Users.size(); ++i) {
        if (Users[i].email == email && Users[i].password == password) {
            return true;
        }
    }
    return false;
}

void registerUser(const string& name, const string& email, const string& password, AccessLevel level) {
    Users.push_back(User(name, email, password, level));
    ofstream outFile("users.csv", ios::app);
    if (outFile.is_open()) {
        outFile << name << "," << email << "," << password << "," << level << endl;
        outFile.close();
    } else {
        cerr << "Error opening user file for writing!" << endl;
    }
}

void clearScreen() {
    system("cls"); // Clear the console
}

int main() {
    loadUsers();
    Admin admin("Admin", "admin@example.com", "adminpass");

    int input;
    while (true) {
        clearScreen();
        cout << "0. Exit\n1. Login\n2. Register\n3. Display Accounts\n4. Change User Access Level\n5. Read Access File\nInput: ";
        cin >> input;
        cin.ignore(); // Clear the newline character

        if (input == 0) break;

        string name, email, password;
        switch (input) {
            case 1: // Login
                cout << "Enter email: ";
                getline(cin, email);
                cout << "Enter password: ";
                getline(cin, password);
                if (login(email, password)) {
                    cout << "Login successful!" << endl;
                } else {
                    cout << "Invalid email or password!" << endl;
                }
                break;

            case 2: // Register
                cout << "Name: ";
                getline(cin, name);
                cout << "Email: ";
                getline(cin, email);
                cout << "Password: ";
                getline(cin, password);
                registerUser(name, email, password, LEVEL1); // Default to LEVEL1
                cout << "Registration successful!" << endl;
                break;

            case 3: // Display Accounts
                displayAccounts();
                break;

            case 4: { // Change User Access Level
                string targetEmail;
                int newLevel;
                cout << "Enter the email of the user to change access level: ";
                getline(cin, targetEmail);
                cout << "Enter new access level (1-5): ";
                cin >> newLevel;
                cin.ignore();

                if (newLevel < 1 || newLevel > 5) {
                    cout << "Invalid access level!" << endl;
                    break;
                }

                bool found = false;
                for (size_t i = 0; i < Users.size(); ++i) {
                    if (Users[i].email == targetEmail) {
                        admin.changeAccessLevel(Users[i], static_cast<AccessLevel>(newLevel - 1));
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "User not found!" << endl;
                }
                break;
            }

            case 5: { // Read Access File
                string targetEmail;
                cout << "Enter the email of the user to read access file: ";
                getline(cin, targetEmail);

                bool found = false;
                for (size_t i = 0; i < Users.size(); ++i) {
                    if (Users[i].email == targetEmail) {
                        AccessFileManager fileManager;
                        fileManager.readAccessFile(Users[i]);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "User not found!" << endl;
                }
                break;
            }

            default:
                cout << "Invalid option!" << endl;
                break;
        }

        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}

