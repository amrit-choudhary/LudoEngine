#pragma once

#include "Models.h"

namespace LudoEngine {

	class LudoManager
	{
	public:
		uint8 turnID;
		unsigned int turnCounter;

		const uint8* paths[4] =
		{
			bottomLeftPath,
			topLeftPath,
			topRightPath,
			bottomRightPath
		};

		Peg* pegs[pegsCount] = {};
		bool safeCells[77] = {};

		TurnReport turnReport;

		void Init();
		uint8 PlayTurn();
		uint8 RollDice();
		uint8 PickPeg(uint8 turnID, uint8 diceRoll);
		uint8 PassTurn();
		
		bool RuleLeaveHome(uint8 pegIndex, uint8 diceRoll);
		bool RuleGoalPath(uint8 pegIndex, uint8 diceRoll);
		void CheckKill(uint8 pegIndex);
		uint8 GetCellIndex(uint8 pegIndex);
		void SendPegHome(uint8 pegIndex);
		bool CheckGameComplete();

		LudoManager();
	};
}
