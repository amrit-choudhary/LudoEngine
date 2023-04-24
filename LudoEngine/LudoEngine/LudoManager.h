#pragma once

#include "Models.h"

namespace LudoEngine {

	class LudoManager
	{
	public:
		unsigned char turnID;
		unsigned int turnCounter;

		Peg* pegs[16];

		void PlayTurn();
		unsigned char RollDice();
		unsigned char PickPeg();
		void PassTurn();

		LudoManager();
	};
}
