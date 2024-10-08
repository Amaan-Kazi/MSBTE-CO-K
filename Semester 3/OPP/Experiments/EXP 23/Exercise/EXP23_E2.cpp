#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler {
private:
    fstream file;

public:    
    FileHandler(const string &filename) {
        file.open(filename.c_str(), ios::in | ios::out | ios::app);
        if (!file) {
            cerr << "Error opening file" << endl;
            exit(1);
        }

        displayContent();
        writeData();
    }
   
    ~FileHandler() {
        if (file.is_open()) {
            file.close();
        }
    }

    void displayContent() {
        string line;
        file.clear(); 
        file.seekg(0);

        cout << "\nContent of the file:" << endl;
        while (getline(file, line)) {
            cout << line << endl; 
        }
    }

    void writeData() {
        string inputData;
        file.clear(); 
        file.seekp(0, ios::end); 
        cout << "Enter data to write to the file (Ctrl+Z followed by Enter to end input):" << endl;

        while (getline(cin, inputData)) {
            file << inputData << endl; 
        }

        displayContent();
    }
};

int main()
{
    FileHandler fileHandler("../exp23.txt");
    return 0;
}
