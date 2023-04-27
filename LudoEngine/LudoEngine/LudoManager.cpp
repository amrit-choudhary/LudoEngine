#include "LudoManager.h"
#include <cstdlib>
#include <time.h>

namespace LudoEngine {

	LudoManager::LudoManager() {
		turnID = 0;
		turnCounter = 0;
		std::srand(time(0));
	}

	void LudoManager::Init() {
		for (uint8 i = 0; i < 4; i++) {
			for (uint8 j = 0; j < 4; j++) {
				pegs[i * 4 + j] = new Peg{ i, 0 };
			}
		}

		safeCells[0] = safeCells[13] = safeCells[26] = safeCells[39] = true;
		safeCells[8] = safeCells[21] = safeCells[34] = safeCells[47] = true;

		for (int i = 52; i < 77; i++) {
			safeCells[i] = true;
		}
	}

	uint8 LudoManager::PlayTurn() {
		uint8 diceRoll = RollDice();
		uint8 pegIndex = PickPeg(turnID, diceRoll);

		if (pegIndex != UCHAR_MAX) {
			pegs[pegIndex]->steps += diceRoll;

			CheckKill(pegIndex);

			turnReport.diceRoll = diceRoll;
			turnReport.turnCounter = turnCounter;
			turnReport.turnID = turnID;
		}
		else {

		}

		return PassTurn();
	}

	bool LudoManager::RuleLeaveHome(uint8 pegIndex, uint8 diceRoll) {
		if (pegs[pegIndex]->steps == 0 && diceRoll != 6) {
			return false;
		}
		else {
			return true;
		}
	}

	bool LudoManager::RuleGoalPath(uint8 pegIndex, uint8 diceRoll) {
		if (pegs[pegIndex]->steps + diceRoll >= maxSteps) {
			return false;
		}
		else {
			return true;
		}
	}

	void LudoManager::CheckKill(uint8 pegIndex) {
		uint8 cellIndex = GetCellIndex(pegIndex);
		uint8 cornerID = pegs[pegIndex]->cornerID;
		for (int i = 0; i < pegsCount; i++) {
			if (!safeCells[cellIndex] &&
				pegs[i]->cornerID != cornerID &&
				GetCellIndex(i) == cellIndex)
			{
				SendPegHome(i);
			}
		}
	}

	uint8 LudoManager::GetCellIndex(uint8 pegIndex) {
		uint8 steps = pegs[pegIndex]->steps;
		const uint8* path = paths[pegs[pegIndex]->cornerID];
		uint8 index = path[steps];
		return index;
	}

	void LudoManager::SendPegHome(uint8 pegIndex) {
		pegs[pegIndex]->steps = 0;
	}

	uint8 LudoManager::RollDice() {
		uint8 max = 6;
		uint8 min = 1;
		uint8 randNum = std::rand() % (max - min + 1) + min;
		return randNum;
	}

	uint8 LudoManager::PickPeg(uint8 turnID, uint8 diceRoll) {
		uint8 max = 23;
		uint8 min = 0;
		uint8 randNum = std::rand() % (max - min + 1) + min;
		uint8 start = randNum * 4;

		uint8 seq[4] = {
			pegCheckSeq[start + 0],
			pegCheckSeq[start + 1],
			pegCheckSeq[start + 2],
			pegCheckSeq[start + 3],
		};

		uint8 pegIndex = UCHAR_MAX;
		for (int i = 0; i < 4; i++) {
			pegIndex = turnID * 4 + seq[i];

			bool legalMove = true;
			if (!RuleLeaveHome(pegIndex, diceRoll)) legalMove = false;
			if (!RuleGoalPath(pegIndex, diceRoll)) legalMove = false;

			if (legalMove) {
				break;
			}
			else {
				pegIndex = UCHAR_MAX;
				continue;
			}
		}

		return pegIndex;
	}

	uint8 LudoManager::PassTurn() {
		turnCounter++;
		turnID++;
		if (turnID >= 4) {
			turnID = 0;
		}

		if (CheckGameComplete()) {
			return 1;
		}
		else {
			return 0;
		}
	}

	bool LudoManager::CheckGameComplete() {
		for (int i = 0; i < pegsCount; i++) {
			if (pegs[i]->steps != maxSteps - 1) {
				return false;
			}
		}

		return true;
	}
}
