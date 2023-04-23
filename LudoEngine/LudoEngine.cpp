#include <iostream>
#include "Source/LudoManager.h"

int main()
{
	LudoEngine::LudoManager ludoManager;
	int i = 0;
	int maxTurns = 100;
	
	while (i < maxTurns) {
		i++;
		ludoManager.PlayTurn();
	}

	char c = std::cin.get();
}

