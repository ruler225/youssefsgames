#include<SFML\Graphics.hpp>	//SFML Graphics Library
#include"other_functions.h" //This is where I am keeping my other functions

//Entry point for program
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game", sf::Style::Close);	//Create an 800 by 600 window, make the title "Game", and give it a titlebar
	
	//Game loop
	while (window.isOpen()) {
		sf::Event event;	//create an event object to process events

		windowtasks(window, event);

	//Create a square and adjust its properties

	sf::RectangleShape square;
	sf::Vector2f squaresize(32, 32);
	square.setSize(squaresize);
	square.setPosition(400, 300);
	square.setFillColor(sf::Color::Black);
	window.draw(square);


	//Display objects to the window
	window.display();
	window.clear(sf::Color::Blue);
	

}
}