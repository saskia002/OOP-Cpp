#include <string>
#include "IPlayer.cpp"
#include "IGameBoard.cpp"

using namespace std;

class IGameEngine {
private:
    virtual void enemyMove() = 0;
    virtual bool treeInRow(string givenSymbol) = 0;
    virtual IPlayer* getPlayer() = 0;
    virtual IPlayer* getEnemy() = 0;
    virtual IGameBoard* getBoard() = 0;
    virtual bool checkIfValidMove(IPlayer* p) = 0;
    virtual void placeOnBoard(int boardX, int boardY, int playerSymbol) = 0;
public:
    virtual bool checkIfHasWon() = 0;
    virtual void playerMove() = 0;
    virtual void init() = 0;
};
