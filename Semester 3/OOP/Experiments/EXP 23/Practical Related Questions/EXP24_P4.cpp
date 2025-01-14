#include <iostream>
#include <cstdlib> 

int main() {
    int result = system("dir");

    if (result == -1) {
        std::cerr << "Error executing command" << std::endl;
    }

    return 0;
}

