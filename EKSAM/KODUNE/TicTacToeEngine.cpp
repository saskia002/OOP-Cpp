#include <iostream>
#include <string>
#include "Player.cpp"
#include "GameBoard.cpp"

using namespace std;

class TicTacToeEngine : public IGameEngine {
private:
    IGameBoard* gameBoard;
    IPlayer* player;
    IPlayer* enemy;

    int gameSteps = 5;

    void enemyMove() {
        if (gameSteps > 0) {
			bool enemyValidRoll = false;

			while (!enemyValidRoll) {
				getEnemy()->newRandomPos();
				//cout << checkIfValidMove(getEnemy()) << endl;
				enemyValidRoll = false;

				if (checkIfValidMove(getEnemy())) {
					placeOnBoard(getEnemy()->getX(), getEnemy()->getY(), 2);
					enemyValidRoll = true;
				}
			}
		}
    }

    bool treeInRow(string givenSymbol) {
        int symbol = (givenSymbol == "o") ? 1 : 2;
        bool hasWon = false;

        int** board = gameBoard->getBoard();

        if (board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) {
            hasWon = true;
        } else if (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) {
            hasWon = true;
        } else if (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol) {
            hasWon = true;
        } else if (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) {
            hasWon = true;
        } else if (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) {
            hasWon = true;
        } else if (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol) {
            hasWon = true;
        } else if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
            hasWon = true;
        } else if (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol) {
            hasWon = true;
        } else {
            hasWon = false;
        }

        return hasWon;
	}


    IPlayer* getPlayer() { return player; }
    IPlayer* getEnemy() { return enemy; }
    IGameBoard* getBoard() { return gameBoard; }

    bool checkIfValidMove(IPlayer* p) {
        if (gameBoard->getBoard()[p->getX()][p->getY()] == 0) {
            return true;
        } else {
            return false;
        }
    }

    void placeOnBoard(int boardX, int boardY, int playerSymbol)  {
        gameBoard->setBoard(boardX, boardY, playerSymbol);
    }

public:
    TicTacToeEngine() {
        player = new Player();
        enemy = new Player();
        gameBoard = GameBoard::getInstance();
    }
    ~TicTacToeEngine() {
        delete this;
    }

    void init() {
        cout << "\nTrips traps trull:" << endl;
        cout << "Arvuti vs Sina!" << endl;
        cout << "\nArvuti - x" << endl;
        cout << "Sina - o" << endl;
        gameBoard->reset();
	    gameBoard->print();
        gameSteps = 5;
    }

    void playerMove() {
		bool playerValidRoll = false;
        string inputKeyBoard;

		while (!playerValidRoll) {
			bool inputStatus = false;

			while (!inputStatus) {
				cout << "Vali kuhu panna laual: ";
				cin >> inputKeyBoard;
				//getline(cin, inputKeyBoard);

				if (inputKeyBoard.size() == 2) {
					inputStatus = true;
					if (inputKeyBoard[0] == 'A' || inputKeyBoard[0] == 'a') {
						getPlayer()->setX(0);
						playerValidRoll = true;
					} else if (inputKeyBoard[0] == 'B' || inputKeyBoard[0] == 'b') {
						getPlayer()->setX(1);
						playerValidRoll = true;
					} else if (inputKeyBoard[0] == 'C' || inputKeyBoard[0] == 'c') {
						getPlayer()->setX(2);
						playerValidRoll = true;
					} else {
						playerValidRoll = false;
					}

					if (inputKeyBoard[1] == '1') {
						getPlayer()->setY(0);
						playerValidRoll = true;
					} else if (inputKeyBoard[1] == '2') {
						getPlayer()->setY(1);
						playerValidRoll = true;
					} else if (inputKeyBoard[1] == '3') {
						getPlayer()->setY(2);
						playerValidRoll = true;
					} else {
						playerValidRoll = false;
					}

					if (!playerValidRoll) {
						inputStatus = false;
						cout << "\nSisend peab olema kas ABC, 123!" << endl;
					}
				} else {
					cout << "\nSisend peab olema 2 tähe märki!" << endl;
				}
			}

			//cout << checkIfValidMove(getPlayer()) << endl;
			if (checkIfValidMove(getPlayer())) {
				playerValidRoll = true;
				placeOnBoard(getPlayer()->getX(), getPlayer()->getY(), 1);
                enemyMove();
                gameSteps--;
                gameBoard->print();
                return;
			} else {
				cout << "\nSisestatud koht on juba võetud!" << endl;
			}
		}
    }

    bool checkIfHasWon() {
		if (treeInRow("x")) {
			cout << "Arvuti võitis!" << endl;
			return true;
		} else if (treeInRow("o")) {
			cout << "Sina võitsid!" << endl;
			return true;
		} else if (gameSteps == 0 && !treeInRow("o") && !treeInRow("x")) {
			cout << "Viik!" << endl;
			return false;
		}
    }
};
