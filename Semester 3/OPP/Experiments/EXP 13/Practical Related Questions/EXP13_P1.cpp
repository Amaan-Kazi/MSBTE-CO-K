#include <iostream>
using namespace std;

class Player {
	public:
		string name;
		int matches;
		
		
		virtual void display()
		{
			cout << "Temp";
		}
};

class Batsman : public Player {
	public:
		int totalScore;
		int perMatchScore;
		float average;
		
		Batsman (string n, int m, int score, int matchScore)
		{
			name = n;
			matches = m;
			totalScore = score;
			perMatchScore = matchScore;
		}
		void calculateAverage()
		{
			average = totalScore / matches;
		}
		void display()
		{
			cout << "Name: " << name << endl;
			cout << "Matches: " << matches << endl;
			cout << "totalScore: " << totalScore << endl;
			cout << "perMatchScore: " << perMatchScore << endl;
			cout << "Average: " << average << endl;
		}
};

class Bowler : public Player {
	public:
		int noOfWickets;
		
		Bowler (string n, int m, int wickets)
		{
			name = n;
			matches = m;
			noOfWickets = wickets;
		}
		void display()
		{
			cout << "Name: " << name << endl;
			cout << "Matches: " << matches << endl;
			cout << "noOfWickets: " << noOfWickets << endl;
		}
};

int main ()
{
	Batsman bat1("Amaan Kazi", 10, 200, 5);
	Bowler bow1("Shirish Shinde", 10, 2);
	
	bat1.calculateAverage();
	bat1.display();
	bow1.display();
	
	return 0;
}
