#include "LudoEngine/LudoManager.h"
#include "LudoRenderer.h"

int main(int argc, char** argv) {
	LudoEngine::LudoManager ludoManager;
	LudoRenderer ludoRenderer;
	ludoRenderer.ludoManager = &ludoManager;
	int result = 0;
	
	ludoManager.Init();
	ludoRenderer.Init();
	
	while (1) {
		ludoManager.PlayTurn();
		result = ludoRenderer.Update();
		
		if (result == 1) break;
	}

	int exitCode = ludoRenderer.Exit();
	return exitCode;
}