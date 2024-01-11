#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "IGameEngine.cpp"
#include "EngineFactory.cpp"

// BASED ON THIS: https://github.com/saskia002/oo2022/tree/main/08_alamklassid/kodut%C3%B6%C3%B6/src

using namespace std;

EngineFactory* EngineFactory::instance = NULL;
IGameBoard* GameBoard::instance = NULL;

int main() {
    IGameEngine* engine = EngineFactory::getInstance()->createEngine(EngineType::TIC_TAC_TOE);
	string inputKeyBoard;
	bool gameStatus = true;
	engine->init();

	while (gameStatus) {
		engine->playerMove();
		gameStatus = !engine->checkIfHasWon();

		while (!gameStatus) {
			cout << "\nKas soovid uuesti mängida:" << endl;
			cout << "Y - jah" << endl;
			cout << "N - ei" << endl;
			cin >> inputKeyBoard;
			if (inputKeyBoard.size() > 0 && (inputKeyBoard[0] == 'Y' || inputKeyBoard[0] == 'y')) {
				gameStatus = true;
				engine->init();
			} else {
				gameStatus = false;
				break;
			}
		}
	}
	delete engine;
	return 0;
}
