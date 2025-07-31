#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

int main () {
    std::string initBoard = "  0 | 0 | 0 \n  ---------  \n  0 | 0 | 0  \n  ---------  \n  0 | 0 | 0  \n\n";

    for(int i = 0; i < initBoard.length(); i++) {
    if(initBoard[i] == '0') {
        cout << "0 at index " << i << "\n";
    }
}

    return 0;
}