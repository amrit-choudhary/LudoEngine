#pragma once

#include "Models.h"

namespace LudoEngine {

	class LudoManager
	{
	public:
		unsigned char turnID;
		unsigned int turnCounter;

		const unsigned char* paths[4] =
		{
			bottomLeftPath,
			topLeftPath,
			topRightPath,
			bottomRightPath
		};

		Peg* pegs[16] = {};
		bool safeCells[77] = {};

		TurnReport turnReport;

		void Init();
		void PlayTurn();
		unsigned char RollDice();
		unsigned char PickPeg();
		void PassTurn();

		LudoManager();
	};
}
