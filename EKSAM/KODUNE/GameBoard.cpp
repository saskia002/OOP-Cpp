#include <iostream>
#include <string>

using namespace std;

class GameBoard : public IGameBoard {
private:

	int** gameBoard;
	string* terminalGameBoard;

 	string convertToString(int number)  {
        if (number == 1) {
            return "o";
        } else if (number == 2) {
            return "x";
        } else if (number == 0) {
            return " ";
        } else {
            return "?";
        }
    }
	GameBoard() {
        gameBoard = new int*[3];
        for (int i = 0; i < 3; ++i) { gameBoard[i] = new int[3]; }
        reset();
	}

	~GameBoard() {
		for (int i = 0; i < 3; ++i) { delete[] gameBoard[i]; }
		delete[] gameBoard;
		delete this;
	}

public:

    static IGameBoard* instance;

    static IGameBoard* getInstance() {
        if (instance == NULL) {
            instance = new GameBoard();
        }
        return instance;
    }

	void reset() {
		for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                gameBoard[i][j] = 0;
            }
        }
	}

	int** getBoard() { return gameBoard; }

	void setBoard(int boardX, int boardY, int playerSymbol) {
		gameBoard[boardX][boardY] = playerSymbol;
	}

	void print() {
        terminalGameBoard = new string[8];
        terminalGameBoard[0] = "";
        terminalGameBoard[1] = "| y/x | A | B | C |";
        terminalGameBoard[2] = "|-----|---|---|---|";
        terminalGameBoard[3] = "|  1  | " + convertToString(gameBoard[0][0]) + " | " + convertToString(gameBoard[1][0]) + " | " + convertToString(gameBoard[2][0]) + " |";
        terminalGameBoard[4] = "|  2  | " + convertToString(gameBoard[0][1]) + " | " + convertToString(gameBoard[1][1]) + " | " + convertToString(gameBoard[2][1]) + " |";
        terminalGameBoard[5] = "|  3  | " + convertToString(gameBoard[0][2]) + " | " + convertToString(gameBoard[1][2]) + " | " + convertToString(gameBoard[2][2]) + " |";
        terminalGameBoard[6] = "|-----|---|---|---|";
        terminalGameBoard[7] = "";

        for (int i = 0; i < 8; ++i) {
            cout << terminalGameBoard[i] << endl;
        }
    }

};


//IGameBoard* GameBoard::instance = NULL;