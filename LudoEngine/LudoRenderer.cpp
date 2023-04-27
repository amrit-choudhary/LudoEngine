#include "LudoRenderer.h"
#include "LudoEngine/Models.h"
#include <string>

void LudoRenderer::Init() {
	SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(
		720,
		720,
		0,
		&window,
		&renderer
	);

	IMG_Init(IMG_INIT_PNG);
	cellTex = IMG_LoadTexture(renderer, "Resources/CellBG.png");
	cellDarkTex = IMG_LoadTexture(renderer, "Resources/CellBGDark.png");

	bottomLeftPegTex = IMG_LoadTexture(renderer, "Resources/red_piece_trans.png");
	topLeftPegTex = IMG_LoadTexture(renderer, "Resources/green_piece_trans.png");
	topRightPegTex = IMG_LoadTexture(renderer, "Resources/yellow_piece_trans.png");
	bottomRightPegTex = IMG_LoadTexture(renderer, "Resources/blue_piece_trans.png");

	TTF_Init();
	font = TTF_OpenFont("Resources/ARIAL.ttf", 32);
}

int LudoRenderer::Update() {
	SDL_RenderClear(renderer);

	for (int i = 0; i < LudoEngine::cellsCount; i++) {
		cellRect.x = origin.x + coords[i].x * gridSize.x;
		cellRect.y = origin.y + coords[i].y * gridSize.y;

		if (ludoManager->safeCells[i]) {
			SDL_RenderCopy(renderer, cellDarkTex, NULL, &cellRect);
		}
		else {
			SDL_RenderCopy(renderer, cellTex, NULL, &cellRect);
		}
	}

	for (int i = 0; i < LudoEngine::pegsCount; i++) {
		int steps = ludoManager->pegs[i]->steps;
		const LudoEngine::uint8* path = ludoManager->paths[ludoManager->pegs[i]->cornerID];
		int index = path[steps];

		pegRect.x = origin.x + coords[index].x * gridSize.x + pegOffset.x;
		pegRect.y = origin.y + coords[index].y * gridSize.y + pegOffset.y;

		switch (ludoManager->pegs[i]->cornerID)
		{
		case 0:
			SDL_RenderCopy(renderer, bottomLeftPegTex, NULL, &pegRect);
			break;
		case 1:
			SDL_RenderCopy(renderer, topLeftPegTex, NULL, &pegRect);
			break;
		case 2:
			SDL_RenderCopy(renderer, topRightPegTex, NULL, &pegRect);
			break;
		case 3:
			SDL_RenderCopy(renderer, bottomRightPegTex, NULL, &pegRect);
			break;
		}
	}

	std::string turnReportText = "Turn: " + std::to_string(ludoManager->turnReport.turnCounter);
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, turnReportText.c_str(), textColor);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_Rect textRect{ 0, 0, 0 , 0 };
	SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);

	SDL_RenderPresent(renderer);

	if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
		return 1;

	SDL_Delay(16);
	return 0;
}

int LudoRenderer::Exit() {
	SDL_DestroyTexture(cellTex);
	SDL_DestroyTexture(textTexture);
	SDL_FreeSurface(textSurface);
	IMG_Quit();
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}