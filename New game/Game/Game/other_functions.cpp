//This header file contains other functions that I may use in my main game
//instead of keeping them all on one file. This makes life much easier for me.
#include<SFML/Graphics.hpp> 
#include"other_functions.h"

//Create a function to handle essential window tasks such as closing the window, or moving the window
void windowtasks(sf::RenderWindow& window, sf::Event& event) {
	window.pollEvent(event);	//Polls window for event

	if (event.type == sf::Event::Closed)	//If the operating system requests to close the window, then,
		window.close();						//well- um, close the window, duh

	if (event.type == sf::Event::KeyPressed) {	
		if (event.key.code == sf::Keyboard::Escape) //If escape key is pressed, close the window
			window.close();
	}
}

