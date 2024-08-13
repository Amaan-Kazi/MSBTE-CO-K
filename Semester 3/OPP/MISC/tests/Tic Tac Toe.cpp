#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

// Handle for color
HANDLE console_color;

void color(int colorCode)
{
	// Color of the console 
    SetConsoleTextAttribute(console_color, colorCode);
}

char grid[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int gridState[3][3] = { {0, 1, 0}, {0, 2, 0}, {0, 1, 0} };

void printGrid()
{
	int i, j;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			switch (gridState[i][j])
			{
				case 0:
					color(15);
					cout << " " << grid[i][j] << " ";
					break;
				case 1:
					color(12);
					cout << " X ";
					break;
				case 2:
					color(3);
					cout << " O ";
					break;
				default:
					break;
			}
			
		}
		cout << endl;
	}
	
	color(15);
}
void updateGrid();

int main ()
{
	int i, input;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout << "Tic Tac Toe";
	getch();
	system("cls");
	
	printGrid();
	
	while (1)
	{
		system("cls");
		color(15);
		
		cout << "0. Exit" << endl;
		cout << "1. Start Game" << endl;
		cout << "Input: ";
		cin >> input;

		if (input == 0)
		{
			break;
		}
		if (input == 1)
		{
			while (1) // Game Loop
			{
				printGrid();
			}
		}
		else
		{
			cout << "Invalid, press any key to continue";
			getch();
		}
	}	
	
	system("cls");
	color(15);
	cout << "Press any key to exit";
	getch();
	return 0;
}
