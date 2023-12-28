#include <string>
#include "IPlayer.cpp"

using namespace std;

class IGameEngine {
public:
    virtual IPlayer* getPlayer() = 0;
    virtual IPlayer* getEnemy() = 0;
    virtual void newGameBoard() = 0;
    virtual bool checkGameBoard(IPlayer* p) = 0;
    virtual void printBoard() = 0;
    virtual void placeOnGameBoard(int boardX, int boardY, int playerSymbol) = 0;
    virtual string convertToString(int number) = 0;
    virtual bool threeInRow(string givenSymbol) = 0;
    virtual ~IGameEngine() {}
};
