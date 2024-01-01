#include <iostream>
#include <string>

using namespace std;

class IGameBoard {
private:
 	virtual string convertToString(int number) = 0;
public:
	static IGameBoard* instance;
	virtual void reset() = 0;
	virtual int** getBoard() = 0;
	virtual void setBoard(int boardX, int boardY, int playerSymbol) = 0;
	virtual void print() = 0;
};