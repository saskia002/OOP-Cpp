using namespace std;

class Player : public IPlayer {
private:
    int playerX, playerY;
public:
    Player() {}
    ~Player() {
        delete this;
    }

    int* getPlayerPos() {
        static int playerPos[2] = { playerX, playerY };
        return playerPos;
    }

    void setPlayerPos(int playerNewX, int playerNewY) {
        playerX = playerNewX;
        playerY = playerNewY;
    }

    int getX() { return playerX; }
    int getY() { return playerY; }
    void setX(int playerNewX) { playerX = playerNewX; }
    void setY(int playerNewY) { playerY = playerNewY; }

    Player* X(int playerNewX) {
        this->playerX = playerNewX;
        return this;
    }

    Player* Y(int playerNewY) {
        this->playerY = playerNewY;
        return this;
    }

    void newRandomPos() {
        playerX = rand() % 3;
        playerY = rand() % 3;
    }

};