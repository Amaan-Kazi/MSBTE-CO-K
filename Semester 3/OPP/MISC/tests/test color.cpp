#include <iostream> 
#include <windows.h> 
using namespace std; 

// https://www.geeksforgeeks.org/colorizing-text-and-console-background-in-c/

int main()
{ 
    // Color of the console 
    HANDLE console_color; 
    console_color = GetStdHandle(STD_OUTPUT_HANDLE); 
  
    // Print all possible color combinations of foreground and backend
    for (int P = 0; P < 256; P++) { 
  
        // P is color code of the corresponding color
        // there are 256 different combinations, 16 for every background
        SetConsoleTextAttribute(console_color, P); 
  
        // Print Statement 
        cout << P << ". Example" << endl; 
    }
    SetConsoleTextAttribute(console_color, 15); // 15 or 7 is default
  
    return 0; 
}
