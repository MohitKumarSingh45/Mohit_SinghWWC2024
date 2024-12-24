#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    TicTacToe();
    void play();

private:
    vector<vector<char>> board;
    char currentPlayer;

    void printBoard();
    bool isWinner();
    bool isBoardFull();
    void switchPlayer();
};

TicTacToe::TicTacToe() {
    board = vector<vector<char>>(3, vector<char>(3, ' ')); // 3x3 board initialized with spaces
    currentPlayer = 'X'; // Player X starts first
}

void TicTacToe::printBoard() {
    cout << "Current board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------\n";
    }
}

bool TicTacToe::isWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool TicTacToe::isBoardFull() {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // Found an empty cell
            }
        }
    }
    return true; // No empty cells found
}

void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch between X and O
}

void TicTacToe::play() {
    int row, col;
    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Validate input
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a winner
        if (isWinner()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for a draw
        if (isBoardFull()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }

        // Switch players
        switchPlayer();
    }
}

int main() {
    TicTacToe game;
    game.play();
    return 0;
}