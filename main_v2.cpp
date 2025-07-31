#include <iostream>

using std::cout; using std::cin;

// Game board and reference board
std::string gameBoard = "    |   |   \n  ---------  \n    |   |    \n  ---------  \n    |   |    \n\n";
std::string refBoard = "  1 | 2 | 3 \n  ---------  \n  4 | 5 | 6  \n  ---------  \n  7 | 8 | 9  \n\n";

// Creates aliases of play squares for convenience and readability (is there a way better way?)
char& sq1 = gameBoard[2];
char& sq2 = gameBoard[6];
char& sq3 = gameBoard[10];
char& sq4 = gameBoard[29];
char& sq5 = gameBoard[33];
char& sq6 = gameBoard[37];
char& sq7 = gameBoard[57];
char& sq8 = gameBoard[61];
char& sq9 = gameBoard[65];

// Creating variables
int pChoice;
int turnNum = 1;
bool tieCondition = false;
bool winCondition = false;

// Updates board based on player choice
void choiceToBoard(int num) {
    if(turnNum % 2 == 1) {
        switch(num) {
            case 1:
                sq1 = 'X';
                break;
            case 2:
                sq2 = 'X';
                break;
            case 3:
                sq3 = 'X';
                break;
            case 4:
                sq4 = 'X';
                break;
            case 5:
                sq5 = 'X';
                break;
            case 6:
                sq6 = 'X';
                break;
            case 7:
                sq7 = 'X';
                break;
            case 8:
                sq8 = 'X';
                break;
            case 9:
                sq9 = 'X';
                break;
        }
    } else {
        switch(num) {
            case 1:
                sq1 = 'O';
                break;
            case 2:
                sq2 = 'O';
                break;
            case 3:
                sq3 = 'O';
                break;
            case 4:
                sq4 = 'O';
                break;
            case 5:
                sq5 = 'O';
                break;
            case 6:
                sq6 = 'O';
                break;
            case 7:
                sq7 = 'O';
                break;
            case 8:
                sq8 = 'O';
                break;
            case 9:
                sq9 = 'O';
                break;
        }
    } cout << '\n' << gameBoard << '\n';
}

int main() {

    // Inital display
    cout << '\n' << refBoard;
    cout << gameBoard;
    
    // Game loop begins
    while(tieCondition == false && winCondition == false) {
        // Determines player turn
        if(turnNum % 2 == 0) {
            cout << "Player 2, enter a number corresponding to a square on the reference board above to play your turn: ";
        } else {
            cout << "Player 1, enter a number corresponding to a square on the reference board above to play your turn: ";
        }
        
        // Input validation
        while(!(cin >> pChoice) || pChoice > 9 || pChoice < 1) {
            cout << "Invalid input. Try again: ";
            cin.clear();
            cin.ignore(10000, '\n'); 
        }
        
        choiceToBoard(pChoice);

    // Bools representing win states (there has to be a better way lol)
    bool win1 = (sq1 == 'X' && sq2 == 'X' && sq3 == 'X')||(sq1 == 'O' && sq2 == 'O' && sq3 == 'O');
    bool win2 = (sq4 == 'X' && sq5 == 'X' && sq6 == 'X')||(sq4 == 'O' && sq5 == 'O' && sq6 == 'O');
    bool win3 = (sq7 == 'X' && sq8 == 'X' && sq9 == 'X')||(sq7 == 'O' && sq8 == 'O' && sq9 == 'O');
    bool win4 = (sq1 == 'X' && sq4 == 'X' && sq7 == 'X')||(sq1 == 'O' && sq4 == 'O' && sq7 == 'O');
    bool win5 = (sq2 == 'X' && sq5 == 'X' && sq8 == 'X')||(sq2 == 'O' && sq5 == 'O' && sq8 == 'O');
    bool win6 = (sq3 == 'X' && sq6 == 'X' && sq9 == 'X')||(sq3 == 'O' && sq6 == 'O' && sq9 == 'O');
    bool win7 = (sq1 == 'X' && sq5 == 'X' && sq9 == 'X')||(sq1 == 'O' && sq5 == 'O' && sq9 == 'O');
    bool win8 = (sq3 == 'X' && sq5 == 'X' && sq7 == 'X')||(sq3 == 'O' && sq5 == 'O' && sq7 == 'O');

    // Win and tie conditions
        if(win1 || win2 || win3 || win4 || win5 || win6 || win7 || win8) {
            winCondition = true;
        }

        if(turnNum == 9) {
            tieCondition = true;
            }
        turnNum++;
    }

    // Determining end phrase
    int playerTurn = turnNum % 2;
    if(tieCondition) {
        cout << "It's a tie! Good game. \n";
    } else if(playerTurn == 0) {
        cout << "Congratulations player 1, you win!\n";
    } else {
        cout << "Congratulations player 2, you win!\n";
    }
    
    return 0;

};