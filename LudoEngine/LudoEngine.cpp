#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main(int argc, char** argv) {
	SDL_Event event;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* texture = NULL;
	SDL_Texture* texture2 = NULL;

	SDL_Window* window = NULL;

	SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(
		720, 720,
		0, &window, &renderer
	);

	IMG_Init(IMG_INIT_PNG);
	texture = IMG_LoadTexture(renderer, "Resources/CellBG.png");
	texture2 = IMG_LoadTexture(renderer, "Resources/blue_piece_trans.png");

	while (1) {
		SDL_Rect rect { 360, 360, 50, 50 };
		SDL_Rect rect2 { 360, 360, 30, 30 };

		SDL_RenderCopy(renderer, texture, NULL, &rect);
		SDL_RenderCopy(renderer, texture2, NULL, &rect2);
		
		
		SDL_RenderPresent(renderer);
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;
	}



	SDL_DestroyTexture(texture);
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}