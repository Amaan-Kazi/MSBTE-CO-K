#include<iostream>
#include<fstream>
using namespace std;

void readfile(fstream &rf)
{
	string line;
    rf.clear();
    rf.seekg(0);

    cout << "\nContent of the file:" << endl;
    while (getline(rf, line)) {
        cout << line << endl;
    }
}

void writefile(fstream &wf)
{
	string inputData;
	wf.clear();
    wf.seekp(0, ios::end);
    cout << "Enter data to write to the file (Ctrl+z to end input):" << endl;

    while (getline(cin, inputData)) {
        wf << inputData << endl;
    }
}

int main() {
	string line;
	fstream file;
	
	file.open("../exp23.txt", ios::in | ios::out | ios::app);
	if (!file)
	{
		cerr<<"Error Opening File";
		return 1;
	}
	
	readfile(file);
	writefile(file);
	readfile(file);
	
	file.close();
	return 0;
}
