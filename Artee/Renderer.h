#pragma once
class Renderer
{
public:
	Renderer();
	~Renderer();

	void renderFrame();
	const unsigned char* getOutput();
};

