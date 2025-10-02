#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// ifdef is used to check if a macro has been defined, here we are checking if platform is win32
#ifdef _WIN32
  #include <conio.h>  // for _kbhit() and _getch()
#else
  #include <unistd.h>
  #include <termios.h>
#endif


/**
 * Clears the input buffer only if it isnt empty (non blocking)
 * @attention On linux, switches to non cannonical terminal input mode to clear the buffer then switches back
 * @warning Function written by ChatGPT
*/
void clearInputBuffer() {
  #ifdef _WIN32 // Windows: remove any pending characters in stdin
    while (_kbhit()) {
      _getch(); // reads one character without blocking
    }
  #else // POSIX/Linux/WSL: remove any pending characters in stdin without blocking
    struct termios oldt, newt;
    int ch;

    // get current terminal attributes
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // disable canonical mode and echo → read character immediately without blocking
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN] = 0;   // return immediately if no input
    newt.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // read characters until buffer is empty
    while ((ch = getchar()) != '\n' &&  ch != EOF) {
      // do nothing, just discard input
    }
    clearerr(stdin); // reset the EOF flag

    // restore original terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  #endif
}

/**
 * Use for taking integer input from user
 * with built in error handling
 * @param prompt string to display to user
 * @returns Valid Integer
 */
int intInput(char *prompt) {
  clearInputBuffer();
  char buffer[65] = "\0";
  int value = 0;
  char *end;

  while (true) {
    printf("%s", prompt);

    char *input = fgets(buffer, sizeof(buffer), stdin);
    if (input == NULL) {
      printf("\nError reading input stream\n");
      clearInputBuffer();
      clearerr(stdin); // clear error flags and EOF flag
      continue;
    }
    clearInputBuffer();

    if (buffer[strlen(buffer) - 1] == '\n') buffer[strlen(buffer) - 1] = '\0';

    value = (int)strtol(buffer, &end, 10);

    if (*end != '\0') {
      printf("\nInvalid Integer\n");
      continue;
    }

    return value;
  }

  return value;
}

/**
 * Use for taking yes/no input from user
 * with built in error handling  
 * @param prompt string to display to user
 * @param defaultInput in case user presses enter without any input
 * @returns true if yes, false if no
 */
bool confirmationInput(char *prompt, bool defaultInput) {
  clearInputBuffer();

  while (true) {
    char confirmation[4] = "\0";
    printf("%s", prompt);

    char *input = fgets(confirmation, sizeof(confirmation), stdin);
    if (input == NULL) {
      // if EOF flag has been set on input stream (usually via ctrl+d)
      if (feof(stdin)) {
        printf(defaultInput == true ? "y\n" : "n\n");
        clearInputBuffer();
        return defaultInput;
      }

      // if error flags have been set on input stream
      else if (ferror(stdin)) {
        printf("\nError reading input stream\n");
        clearInputBuffer();
        clearerr(stdin); // clear error flags and EOF flag
        continue;
      }
    }
    clearInputBuffer();

    int length = strlen(confirmation);
    if (confirmation[length - 1] == '\n') {
      confirmation[length - 1] = '\0';
      length -= 1;
    }

    if (length == 0) {
      printf("\033[F"); // move cursor up one line
      printf("\r");     // move cursor to start of line
      printf("%s%s\n", prompt, defaultInput == true ? "y" : "n");
      return defaultInput;
    }

    // convert string to lowercase
    for (int i = 0; i < length; i++) confirmation[i] = tolower(confirmation[i]);

    if      (strcmp(confirmation, "y") == 0 || strcmp(confirmation, "yes") == 0) return true;
    else if (strcmp(confirmation, "n") == 0 || strcmp(confirmation, "no")  == 0) return false;
    else    printf("Input y/yes or n/no [case insensitive]\n");
  }
}
