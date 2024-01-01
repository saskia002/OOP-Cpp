#include "TicTacToeEngine.cpp"

enum class EngineType {
	TIC_TAC_TOE,
};

class EngineFactory {
private:
	static EngineFactory* instance;

	EngineFactory() {}

public:

	IGameEngine* createEngine(EngineType type) {
		switch (type) {
			case EngineType::TIC_TAC_TOE:
				return new TicTacToeEngine();
			default:
				return nullptr;
		}
	}

	static EngineFactory* getInstance() {
		if (instance == NULL) {
			instance = new EngineFactory();
		}
		return instance;
	}
};