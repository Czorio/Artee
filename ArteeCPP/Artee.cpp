#include "Renderer.h"
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

constexpr int IMAGEWIDTH = 1280;
constexpr int IMAGEHEIGHT = 720;

// SDL doing SDL things
#undef main
int main()
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow(
		"ArteeCPP",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		IMAGEWIDTH,
		IMAGEHEIGHT,
		SDL_WINDOW_SHOWN
	);

	SDL_Surface* surface = SDL_GetWindowSurface(window);
	auto buffer = static_cast<uint32_t*>(surface->pixels);

	Camera camera = Camera(Vec3f(-1.f, 0.f, 0.f), Vec3f(1.f, 0.f, 0.f), Vec3f(0.f, 0.f, 1.f), 1.f, 1.f, IMAGEWIDTH,
	                       IMAGEHEIGHT);
	Renderer renderer = Renderer(IMAGEWIDTH, IMAGEHEIGHT, camera);

	bool shouldStop = false;
	while (!shouldStop)
	{
		SDL_LockSurface(surface);

		renderer.renderFrame();
		renderer.getOutput(buffer);

		SDL_UnlockSurface(surface);
		SDL_UpdateWindowSurface(window);

		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				shouldStop = true;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
