using namespace std;

class IPlayer {
public:
    virtual int* getPlayerPos() = 0;
    virtual void setPlayerPos(int playerNewX, int playerNewY) = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual void setX(int playerNewX) = 0;
    virtual void setY(int playerNewY) = 0;
    virtual IPlayer* X(int playerNewX) = 0;
    virtual IPlayer* Y(int playerNewY) = 0;
    virtual void newRandomPos() = 0;
};