#pragma once
class Renderer
{
public:
	Renderer();
	~Renderer();

	void renderFrame();
	void getOutput(uint32_t *framebuffer, SDL_PixelFormat *format);

private:
	std::vector<Tile> tiles;

	// Output
	vec3 *vecBuffer;
	uint32_t *outBuffer;
};

