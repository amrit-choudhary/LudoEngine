#include "LudoManager.h"
#include <cstdlib>

namespace LudoEngine {

	LudoManager::LudoManager() {
		turnID = 0;
		turnCounter = 0;
	}

	void LudoManager::Init() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				pegs[i * 4 + j] = new Peg();
				pegs[i * 4 + j]->corner = static_cast<Corner>(i);
			}
		}

		safeCells[0] = safeCells[13] = safeCells[26] = safeCells[39] = true;
		safeCells[8] = safeCells[21] = safeCells[34] = safeCells[47] = true;

		for (int i = 52; i < 77; i++) {
			safeCells[i] = true;
		}
	}

	void LudoManager::PlayTurn() {
		unsigned char diceRoll = RollDice();
		unsigned char pickedPeg = PickPeg();
		unsigned char pegIndex = turnID * 4 + pickedPeg;
		pegs[pegIndex]->steps += diceRoll;
		
		turnReport.diceRoll = diceRoll;
		turnReport.turnCounter = turnCounter;
		turnReport.turnID = turnID;
		
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
