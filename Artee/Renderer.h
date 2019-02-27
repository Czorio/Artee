#pragma once
/*
	Main renderer class
	Handles generating a frame and storing objects
	Uses CPU rendering
*/
class Renderer
{
public:
	Renderer();
	~Renderer();

	/*
		Renders a frame. Output is stored for later access.
	*/
	void renderFrame();

	/*
		Fills the framebuffer with the frame that was rendered during the last time renderFrame() was called.

		Input:
			uint32 * framebuffer		The framebuffer that has to be filled
			SDL_PixelFormat * format	The format that the buffer expects
	*/
	void getOutput(uint32_t *framebuffer, SDL_PixelFormat *format);

private:
	std::vector<Tile> tiles;

	// Output
	vec3 *vecBuffer;
	uint32_t *outBuffer;
};

