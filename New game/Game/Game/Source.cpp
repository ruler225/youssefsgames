#include<SFML\Graphics.hpp>	//SFML Graphics Library
#include<iostream>			//For writing to a console window while debugging
#include<Windows.h>			//Windows APIs used for creating the dialog boxes
#include"other_functions.h" //This is where I am keeping my other functions

//Entry point for program
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game", sf::Style::Close);	//Create an 800 by 600 window, make the title "Game", and give it a titlebar
	
	window.setFramerateLimit(60); //Limits the window to run at 60 fps in order to prevent unnecessary strain on the GPU
	//Game loop
	bool makeBigger = false;	//Boolean to control when the square gets bigger
	while (window.isOpen()) {
		sf::Event event;	//create an event object to process events

		windowtasks(window, event);

	//Create a square and adjust its properties

	
	sf::RectangleShape square;
	sf::Vector2f squaresize(32, 32);
	
	square.setFillColor(sf::Color::Black);
	//square.setPosition(400, 300);
	//if (event.type == sf::Event::MouseMoved)
	square.setPosition(sf::Mouse::getPosition(window).x - 16, sf::Mouse::getPosition(window).y - 16); //Set the position of the square equal to the coordinates of the mouse. This allows the square to follow the mouse.


	if (event.type == sf::Event::MouseButtonPressed) {	//When the mouse button is pressed, it should set makeBigger to true
		makeBigger = true;
		square.setPosition(sf::Mouse::getPosition(window).x - 20, sf::Mouse::getPosition(window).y - 20);

	}

	else if (event.type == sf::Event::MouseButtonReleased)	//When the mouse button is released, it should set makeBigger to false
		makeBigger = false;
	
	if (makeBigger)		//When makeBigger is true, the size of the square is slightly bigger.
	squaresize = sf::Vector2f(40, 40);

		square.setSize(squaresize);	
		window.draw(square);


	//Display objects to the window
	window.display();
	window.clear(sf::Color::Blue);

}
}