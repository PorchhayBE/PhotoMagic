/**
 * PhotoMagic.cpp - Encrypt/Decrpyt implemenation
 * 
 * Date: 02/6/2022
 * 
 * Created by: Porchhay Be
 */

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"
#include <string>

void transform(sf::Image&, FibLFSR*);

// display an encrypted coopy of the pictyre, using the LFSR
// to do the encryption
int main(int argc, char* argv[]) {
	FibLFSR seed(argv[3]);
	
	sf::Image image;
	if (!image.loadFromFile(argv[1])) {
		return -1;
	}
	
	// get size of image
	sf::Vector2u size = image.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output");

	// load image to window
	// load image to texture first
	sf::Texture textureInput;
	textureInput.loadFromImage(image);

	// load image to sprite later
	sf::Sprite spriteInput;
	spriteInput.setTexture(textureInput);

	// Encodeing/Decoding Process
	transform(image, &seed);

	sf::Texture textureOutput;
	textureOutput.loadFromImage(image);

	sf::Sprite spriteOutput;
	spriteOutput.setTexture(textureOutput);	

	while (window1.isOpen() && window2.isOpen()) {
		sf::Event event;
		while (window1.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window1.close();
		}

		while (window2.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window2.close();
			}
		}

		window1.clear();
		window1.draw(spriteInput);
		window1.display();
		window2.clear();
		window2.draw(spriteOutput);
		window2.display();
	}

	if (!image.saveToFile(argv[2])) {
		return -1;
	}

}

void transform(sf::Image& image, FibLFSR* seed) {

	// size is a pixel size of image
	sf::Vector2u size = image.getSize();
	// p is a pixelimage.getPixel (x, y);
	sf::Color p;
	for (int x = 0; x<size.x; x++) {
		for (int y = 0; y < size.y; y++)
		{
			p = image.getPixel(x, y);
			p.r = p.r ^ (seed->generate(8));
			p.g = p.g ^ (seed->generate(8));
			p.b = p.b ^ (seed->generate(8));
			image.setPixel(x, y, p);
		}
		
	}
}
