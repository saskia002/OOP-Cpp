#include <iostream>
#include <string>
#include "Player.cpp"

using namespace std;

class GameEngine : public IGameEngine {
private:
    int** gameBoard;
    string* terminalGameBoard;
    IPlayer* player;
    IPlayer* enemy;
public:
    GameEngine() {
        player = new Player();
        enemy = new Player();
        gameBoard = new int*[3];
        for (int i = 0; i < 3; ++i) { gameBoard[i] = new int[3]; }
    }
    ~GameEngine() {
        delete player;
        delete enemy;
        for (int i = 0; i < 3; ++i) { delete[] gameBoard[i]; }
        delete[] gameBoard;
    }

    IPlayer* getPlayer() { return player; }
    IPlayer* getEnemy() { return enemy; }

    // Game board
    void newGameBoard()  {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                gameBoard[i][j] = 0;
            }
        }
    }

    bool checkGameBoard(IPlayer* p) {
        if (gameBoard[p->getX()][p->getY()] == 0) {
            return true;
        } else {
            return false;
        }
    }

    void printBoard() {
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

    void placeOnGameBoard(int boardX, int boardY, int playerSymbol)  {
        gameBoard[boardX][boardY] = playerSymbol;
    }

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

    // Winner determination
    bool threeInRow(string givenSymbol)  {
        int symbol = (givenSymbol == "o") ? 1 : 2;

        bool hasWon = false;
        if (gameBoard[0][0] == symbol && gameBoard[0][1] == symbol && gameBoard[0][2] == symbol) {
            hasWon = true;
        } else if (gameBoard[1][0] == symbol && gameBoard[1][1] == symbol && gameBoard[1][2] == symbol) {
            hasWon = true;
        } else if (gameBoard[2][0] == symbol && gameBoard[2][1] == symbol && gameBoard[2][2] == symbol) {
            hasWon = true;
        } else if (gameBoard[0][0] == symbol && gameBoard[1][0] == symbol && gameBoard[2][0] == symbol) {
            hasWon = true;
        } else if (gameBoard[0][1] == symbol && gameBoard[1][1] == symbol && gameBoard[2][1] == symbol) {
            hasWon = true;
        } else if (gameBoard[0][2] == symbol && gameBoard[1][2] == symbol && gameBoard[2][2] == symbol) {
            hasWon = true;
        } else if (gameBoard[0][0] == symbol && gameBoard[1][1] == symbol && gameBoard[2][2] == symbol) {
            hasWon = true;
        } else if (gameBoard[2][0] == symbol && gameBoard[1][1] == symbol && gameBoard[0][2] == symbol) {
            hasWon = true;
        } else {
            hasWon = false;
        }
        return hasWon;
    }
};
