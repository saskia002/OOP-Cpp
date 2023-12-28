#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "IGameEngine.cpp"
#include "GameEngine.cpp"

using namespace std;


void init() {
	cout << "\nTrips traps trull:" << endl;
	cout << "Arvuti vs Sina!" << endl;
	cout << "\nArvuti - x" << endl;
	cout << "Sina - o" << endl;
}

int main() {
    IGameEngine* engine = new GameEngine();

	init();

	string inputKeyBoard;
	engine->newGameBoard();
	engine->printBoard();

	int gameSteps = 5;
	bool gameStatus = true;
	bool inputStatus = false;

	// Main loop.
	while (gameStatus) {
		gameSteps--;

		// Mängija
		bool playerValidRoll = false;
		while (!playerValidRoll) {
			inputStatus = false;

			while (!inputStatus) {
				cout << "Vali kuhu panna laual: ";
				cin >> inputKeyBoard;
				//getline(cin, inputKeyBoard);

				if (inputKeyBoard.size() == 2) {
					inputStatus = true;
					if (inputKeyBoard[0] == 'A' || inputKeyBoard[0] == 'a') {
						engine->getPlayer()->setX(0);
						playerValidRoll = true;
					} else if (inputKeyBoard[0] == 'B' || inputKeyBoard[0] == 'b') {
						engine->getPlayer()->setX(1);
						playerValidRoll = true;
					} else if (inputKeyBoard[0] == 'C' || inputKeyBoard[0] == 'c') {
						engine->getPlayer()->setX(2);
						playerValidRoll = true;
					} else {
						playerValidRoll = false;
					}

					if (inputKeyBoard[1] == '1') {
						engine->getPlayer()->setY(0);
						playerValidRoll = true;
					} else if (inputKeyBoard[1] == '2') {
						engine->getPlayer()->setY(1);
						playerValidRoll = true;
					} else if (inputKeyBoard[1] == '3') {
						engine->getPlayer()->setY(2);
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

			cout << engine->checkGameBoard(engine->getPlayer()) << endl;
			if (engine->checkGameBoard(engine->getPlayer())) {
				playerValidRoll = true;
				engine->placeOnGameBoard(engine->getPlayer()->getX(), engine->getPlayer()->getY(), 1); // o => 1; x=> 2;
			} else {
				cout << "\nSisestatud koht on juba võetud!" << endl;
			}
		}

		// Arvuti.
		if (gameSteps > 0) {
			bool enemyValidRoll = false;

			while (!enemyValidRoll) {
				engine->getEnemy()->newRandomPos();
				cout << engine->checkGameBoard(engine->getEnemy()) << endl;
				enemyValidRoll = false;

				if (engine->checkGameBoard(engine->getEnemy())) {
					engine->placeOnGameBoard(engine->getEnemy()->getX(), engine->getEnemy()->getY(), 2);
					enemyValidRoll = true;
				}
			}
		}


		engine->printBoard();

		// Kas on keegi võitnud.
		if (engine->threeInRow("x")) {
			cout << "Arvuti võitis!" << endl;
			gameStatus = false;
		} else if (engine->threeInRow("o")) {
			cout << "Sina võitsid!" << endl;
			gameStatus = false;
		} else if (gameSteps == 0 && !engine->threeInRow("o") && !engine->threeInRow("x")) {
			cout << "Viik!" << endl;
			gameStatus = false;
		}

		while (!gameStatus || gameSteps == 0) {
			cout << "\nKas soovid uuesti mängida:" << endl;
			cout << "Y - jah" << endl;
			cout << "N - ei" << endl;
			//getline(cin, inputKeyBoard);
			cin >> inputKeyBoard;
			if (inputKeyBoard.size() > 0 && (inputKeyBoard[0] == 'Y' || inputKeyBoard[0] == 'y')) {
				gameStatus = true;
				gameSteps = 5;
				init();
				engine->newGameBoard();
				engine->printBoard();
			} else {
				gameStatus = false;
				break;
			}
		}
	}
	delete engine;
	return 0;
}
