#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
	string line;
	
	fstream sourceFile;
	fstream destinationFile;
	
	sourceFile.open("../source.txt");
	destinationFile.open("../destination.txt");
	
	if (!sourceFile || !destinationFile)
	{
		cerr << "Error opening Source or Destination file" << endl;
		return 1;
	}
	
	sourceFile.clear();
	sourceFile.seekg(0);
	
	destinationFile.clear();
	destinationFile.seekg(0);
	
	cout << "Source File:" << endl;
	while (getline(sourceFile, line))
	{
		cout << line << endl;
		destinationFile << line << endl;
	}
	
	sourceFile.clear();
	sourceFile.seekg(0);
	
	destinationFile.clear();
	destinationFile.seekg(0);
	
	cout << "\nDestination File:" << endl;
	while (getline(sourceFile, line))
	{
		cout << line << endl;
	}
	return 0;
}
