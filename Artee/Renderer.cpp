#include "Precomp.h"

Renderer::Renderer()
{
	// Prepare buffers
	outBuffer = new uint32_t[SCREEN_WIDTH * SCREEN_HEIGHT];
	vecBuffer = new vec3[SCREEN_WIDTH * SCREEN_HEIGHT];

	// Prepare Tiles
	Tile t;
	for (unsigned y = 0; y < SCREEN_HEIGHT; y += TILE_SIZE)
	{
		for (unsigned x = 0; x < SCREEN_WIDTH; x += TILE_SIZE)
		{
			t.x = x;
			t.y = y;
			tiles.push_back(t);
		}
	}
}


Renderer::~Renderer()
{
	delete[] vecBuffer;
	vecBuffer = nullptr;
	delete[] outBuffer;
	outBuffer = nullptr;

	tiles.clear();
}

void Renderer::renderFrame()
{
#pragma omp parallel for
	for (int t = 0; t < tiles.size(); t++)
	{
		for (unsigned y = tiles[t].y; y < tiles[t].y + TILE_SIZE; y++)
		{
			for (unsigned x = tiles[t].x; x < tiles[t].x + TILE_SIZE; x++)
			{
				if (y < SCREEN_HEIGHT && x < SCREEN_WIDTH)
				{
					vecBuffer[y * SCREEN_WIDTH + x] = vec3(float(y) / float(SCREEN_HEIGHT), float(x) / float(SCREEN_WIDTH), 0.f);
				}
			}
		}
	}
}

void Renderer::getOutput(uint32_t* framebuffer, SDL_PixelFormat *format)
{
#pragma omp parallel for
	for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++)
	{
		uint32_t r = vecBuffer[i].x * 255;
		uint32_t g = vecBuffer[i].y * 255;
		uint32_t b = vecBuffer[i].z * 255;
		uint32_t a = 255;

		framebuffer[i] = SDL_MapRGBA(format, r, g, b, a);
	}
}
