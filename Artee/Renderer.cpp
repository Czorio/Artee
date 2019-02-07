#include "Precomp.h"

Renderer::Renderer()
{
	// Prepare buffers
	outBuffer = new unsigned char[SCREEN_WIDTH * SCREEN_HEIGHT * 4];
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
	// Preparation for MT
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

const unsigned char * Renderer::getOutput()
{
	for (unsigned i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i += 4)
	{
		outBuffer[i] = vecBuffer[i / 4].x * 255;
		outBuffer[i + 1] = vecBuffer[i / 4].y * 255;
		outBuffer[i + 2] = vecBuffer[i / 4].z * 255;
		outBuffer[i + 3] = 255;
	}

	return outBuffer;
}
