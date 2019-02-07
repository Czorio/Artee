#include "Precomp.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Artee");
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Image buffer;

	Renderer renderer;

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear window for the next frame
		window.clear(sf::Color::Black);

		renderer.renderFrame();
		buffer.create(SCREEN_WIDTH, SCREEN_HEIGHT, renderer.getOutput());
		texture.loadFromImage(buffer);
		sprite = sf::Sprite(texture);
		window.draw(sprite);
		window.display();
	}

	return 0;
}