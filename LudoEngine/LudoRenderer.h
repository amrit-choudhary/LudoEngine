#pragma once

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "LudoEngine/LudoManager.h"

class LudoRenderer
{

public:
	LudoEngine::LudoManager* ludoManager;

	void Init();
	int Update();
	int Exit();
private:
	SDL_Event event;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* cellTex = NULL;
	SDL_Texture* cellDarkTex = NULL;
	SDL_Texture* bottomLeftPegTex = NULL;
	SDL_Texture* topLeftPegTex = NULL;
	SDL_Texture* topRightPegTex = NULL;
	SDL_Texture* bottomRightPegTex = NULL;

	TTF_Font *font = NULL;
	SDL_Color textColor{ 74, 77,255, 255 };
	SDL_Surface* textSurface;
	SDL_Texture* textTexture;
	SDL_Rect textRect{ 0, 0, 0, 0 };

	SDL_Window* window = NULL;

	int cellSize = 30;
	SDL_Point gridSize{ 32, -32 };
	SDL_Point origin{ 330, 560 };
	SDL_Point pegSize{ 20, 25 };
	SDL_Point pegOffset{ 5, 2 };

	SDL_Rect cellRect{ 360, 360, cellSize, cellSize };
	SDL_Rect pegRect{ 360, 360, pegSize.x, pegSize.y };

	SDL_Point coords[77] =
	{
		// Outer Path (0 -> 51)
		SDL_Point{0, 1}, SDL_Point{0, 2}, SDL_Point{0, 3}, SDL_Point{0, 4}, SDL_Point{0, 5},
		SDL_Point{-1, 6}, SDL_Point{-2, 6},  SDL_Point{-3, 6}, SDL_Point{-4, 6}, SDL_Point{-5, 6}, SDL_Point{-6, 6},
		SDL_Point{-6, 7}, SDL_Point{-6, 8},
		SDL_Point{-5, 8}, SDL_Point{-4, 8}, SDL_Point{-3, 8}, SDL_Point{-2, 8}, SDL_Point{-1, 8},
		SDL_Point{0, 9}, SDL_Point{0, 10}, SDL_Point{0, 11}, SDL_Point{0, 12}, SDL_Point{0, 13}, SDL_Point{0, 14},
		SDL_Point{1, 14}, SDL_Point{2, 14},
		SDL_Point{2, 13}, SDL_Point{2, 12}, SDL_Point{2, 11}, SDL_Point{2, 10}, SDL_Point{2, 9},
		SDL_Point{3, 8}, SDL_Point{4, 8}, SDL_Point{5, 8}, SDL_Point{6, 8}, SDL_Point{7, 8}, SDL_Point{8, 8},
		SDL_Point{8, 7}, SDL_Point{8, 6},
		SDL_Point{7, 6}, SDL_Point{6, 6}, SDL_Point{5, 6}, SDL_Point{4, 6}, SDL_Point{3, 6},
		SDL_Point{2, 5}, SDL_Point{2, 4}, SDL_Point{2, 3}, SDL_Point{2, 2}, SDL_Point{2, 1}, SDL_Point{2, 0},
		SDL_Point{1, 0}, SDL_Point{0, 0},

		// Home Safe Paths (52 -> 71)
		SDL_Point{1, 1}, SDL_Point{1, 2}, SDL_Point{1, 3}, SDL_Point{1, 4}, SDL_Point{1, 5},
		SDL_Point{-5, 7}, SDL_Point{-4, 7}, SDL_Point{-3, 7}, SDL_Point{-2, 7}, SDL_Point{-1, 7},
		SDL_Point{1, 13}, SDL_Point{1, 12}, SDL_Point{1, 11}, SDL_Point{1, 10}, SDL_Point{1, 9},
		SDL_Point{7, 7}, SDL_Point{6, 7}, SDL_Point{5, 7}, SDL_Point{4, 7}, SDL_Point{3, 7},

		// Goal
		SDL_Point{1, 7},

		// Home
		SDL_Point{-1, 1}, SDL_Point{-5, 9}, SDL_Point{3, 13}, SDL_Point{7, 5}
	};
};
