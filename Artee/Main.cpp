#include "Precomp.h"

int main(int argc, char* args[])
{
	SDL_SetMainReady();

	bool quit = false;

	SDL_Window *window = NULL;
	SDL_Surface *surface = NULL;

	Renderer r = Renderer();

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Could not initialize SDL. SDL Error %s\n", SDL_GetError());
		return 1;
	}
	
	window = SDL_CreateWindow("Artee", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created. SDL Error %s\n", SDL_GetError());
		return 2;
	}

	surface = SDL_GetWindowSurface(window);
	if (surface == NULL)
	{
		printf("Surface could not be retrieved. SDL Error %s\n", SDL_GetError());
		return 3;
	}

	uint32_t *framebuffer = static_cast<uint32_t *>(surface->pixels);

	while (!quit)
	{
		uint32_t start = SDL_GetTicks();
		r.renderFrame();

		SDL_LockSurface(surface);
		r.getOutput(framebuffer, surface->format);
		SDL_UnlockSurface(surface);
		SDL_UpdateWindowSurface(window);

		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		uint32_t end = SDL_GetTicks();
		float fps = 1000.f / float(end - start);
		SDL_SetWindowTitle(window, ("Artee FPS: " + std::to_string(fps) + " (" + std::to_string(end - start) + "ms)").c_str());
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}