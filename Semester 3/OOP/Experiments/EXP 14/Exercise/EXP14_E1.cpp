#include <iostream>
using namespace std;

class Cricketer {
	protected:
		string name;
		int age;
		int totalMatches;
};

class Bowler : virtual public Cricketer {
	public:
		int totalWicketsTaken;
		float bowlingAverage;
		
		Bowler() {
		}
		Bowler (string n, int a, int tMatches, int tWicketsTaken, float bowAverage)
		{
			name = n;
			age = a;
			totalMatches = tMatches;
			totalWicketsTaken = tWicketsTaken;
			bowlingAverage = bowAverage;
		}
		
		virtual void displayDetails()
		{
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
			cout << "Total Matches: " << totalMatches << endl;
			cout << "Total Wickets Taken: " << totalWicketsTaken << endl;
			cout << "Bowling Average: " << bowlingAverage << endl << endl;
		}
};

class Batsman : virtual public Cricketer {
	public:
		int totalRuns;
		float battingAverage;
		Batsman() {
		}
		Batsman (string n, int a, int tMatches, int tRuns, float batAverage)
		{
			name = n;
			age = a;
			totalMatches = tMatches;
			totalRuns = tRuns;
			battingAverage = batAverage;
		}
		
		virtual void displayDetails()
		{
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
			cout << "Total Matches: " << totalMatches << endl;
			cout << "Total Runs: " << totalRuns << endl;
			cout << "Batting Average: " << battingAverage << endl << endl;
		}
};

class Allrounder : public Bowler, public Batsman {
	public:
		Allrounder (string n, int a, int tMatches, int tWicketsTaken, float bowAverage, int tRuns, float batAverage)
		{
			name = n;
			age = a;
			totalMatches = tMatches;
			totalWicketsTaken = tWicketsTaken;
			bowlingAverage = bowAverage;
			totalRuns = tRuns;
			battingAverage = batAverage;
		}
		
		void displayDetails()
		{
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
			cout << "Total Matches: " << totalMatches << endl;
			cout << "Total Wickets Taken: " << totalWicketsTaken << endl;
			cout << "Bowling Average: " << bowlingAverage << endl;
			cout << "Total Runs: " << totalRuns << endl;
			cout << "Batting Average: " << battingAverage << endl << endl;
		}
};

int main ()
{
	Batsman bat1("Batsman Name", 21, 64, 256, 51.2);
	Bowler bow1("Bowler Name", 24, 73, 32, 36.8);
	Allrounder all1("All Rounder Name", 22, 38, 5, 12.5, 130, 18.3);
	
	bat1.displayDetails();
	bow1.displayDetails();
	all1.displayDetails();
	
	return 0;
}
