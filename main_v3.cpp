#include <iostream>

using std::cout; using std::cin;

void printBoard(const char b[9]) {
    cout << "\n";
    cout << " " << b[0] << " | " << b[1] << " | " << b[2] << "\n";
    cout << "---+---+---\n";
    cout << " " << b[3] << " | " << b[4] << " | " << b[5] << "\n";
    cout << "---+---+---\n";
    cout << " " << b[6] << " | " << b[7] << " | " << b[8] << "\n";
    cout << "\n";
    }

int getValidMove(const char board[9]) {
    int pChoice;

    while (true) {
        cout << "Enter a number (1–9) corresponding to an empty square: ";

        if (!(cin >> pChoice)) {
            cout << "\nInvalid input. Must be a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (pChoice < 1 || pChoice > 9) {
            cout << "\nNumber must be between 1 and 9.\n";
            continue;
        }

        // ✅ Only now is it safe to access board[pChoice - 1]
        if (board[pChoice - 1] != ' ') {
            cout << "\nThat square is already taken. Try another.\n";
            continue;
        }

        return pChoice; // Valid and safe
    }
}

void choiceToBoard(char b[9], int move, char playerSymbol) {
    b[move - 1] = playerSymbol;
}

bool checkWin(char b[9], char symbol) {
    return
        (b[0] == symbol && b[1] == symbol && b[2] == symbol) ||
        (b[3] == symbol && b[4] == symbol && b[5] == symbol) ||
        (b[6] == symbol && b[7] == symbol && b[8] == symbol) ||
        (b[0] == symbol && b[3] == symbol && b[6] == symbol) ||
        (b[1] == symbol && b[4] == symbol && b[7] == symbol) ||
        (b[2] == symbol && b[5] == symbol && b[8] == symbol) ||
        (b[0] == symbol && b[4] == symbol && b[8] == symbol) ||
        (b[2] == symbol && b[4] == symbol && b[6] == symbol);
    }

int main() {

    int pChoice;
    int turnNum = 1;
    bool tieCondition = false;
    bool winCondition = false;
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char playerSymbol;

    while(!tieCondition && !winCondition) { // Start game loop
        
        //printRefBoard();
        printBoard(board);

        if(turnNum % 2 == 1) {
            playerSymbol = 'X';
            cout << "Player 1, enter a number to play your turn: ";
        } else {
            playerSymbol = 'O';
            cout << "Player 2, enter a number to play your turn: ";
        }

        // Input validation
        pChoice = getValidMove(board);

        // Add choice to board after checks
        choiceToBoard(board, pChoice, playerSymbol);
        
        // Check for a win
        if(checkWin(board, playerSymbol)) {
            winCondition = true;
        }

        // Check for a tie
        if(turnNum == 10) {
            tieCondition = true;
        }

        turnNum++;

    }

    printBoard(board);
    
    // Final message
    if(tieCondition){
        cout << "It's a tie! Game over \n";
    } else {
        if(turnNum % 2 == 1) {
            cout << "Player 2 wins!\n";
        } else {
            cout << "Player 1 wins!\n";
        }
    }

    return 0;
}