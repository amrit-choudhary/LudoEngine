#include "LudoManager.h"
#include <cstdlib>

namespace LudoEngine {

	LudoManager::LudoManager() {
		turnID = 0;
		turnCounter = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				pegs[i * 4 + j] = new Peg();
				pegs[i * 4 + j]->corner = static_cast<Corner>(i);
			}
		}
	}

	void LudoManager::PlayTurn() {
		unsigned char diceRoll = RollDice();
		unsigned char pickedPeg = PickPeg();
		unsigned char pegIndex = turnID * 4 + pickedPeg;
		pegs[pegIndex]->steps += diceRoll;
		PassTurn();
	}

	unsigned char LudoManager::RollDice() {
		unsigned char max = 6;
		unsigned char min = 1;
		unsigned char randNum = std::rand() % (max - min + 1) + min;
		return randNum;
	}

	unsigned char LudoManager::PickPeg() {
		unsigned char max = 3;
		unsigned char min = 0;
		unsigned char randNum = std::rand() % (max - min + 1) + min;
		return randNum;
	}

	void LudoManager::PassTurn() {
		turnCounter++;
		turnID++;
		if (turnID >= 4) {
			turnID = 0;
		}
	}
}
