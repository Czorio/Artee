#pragma once
class Renderer
{
public:
	Renderer();
	~Renderer();

	void renderFrame();
	const unsigned char* getOutput();

private:
	std::vector<Tile> tiles;

	// Output
	vec3 *vecBuffer;
	unsigned char *outBuffer;
};

