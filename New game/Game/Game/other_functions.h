#pragma once
#ifndef OTHER_FUNCTIONS_H
#define OTHER_FUNCTIONS_H

#include<SFML/Graphics.hpp>


void windowtasks(sf::RenderWindow& window, sf::Event& event);

//I'm not currently using this class, but I might in the future (or not)
//For now, I'm just working on it, practicing my class-making skills, and see if this becomes something useful
class gameobject {
private:

	enum Shape { Square, Rectangle, Circle, Sprite };

	int x = 0;
	int y = 0;
	Shape form;
	

public:

	void position(int x, int y) {
		gameobject::x = x;
		gameobject::y = y;
	}



	//Default constructor: Accepts only one parameter. Accepts the following values:
	//Square: Makes the object a square. Default size is 32x32 pixels
	//Rectangle: Makes the object a rectangle. Default size is 32x64 pixels
	//Circle: Makes the object a circle. Default radius size is 32 pixels.
	//Sprite: Makes the object a sprite (this sprite is in the form of a 32x32 pixel square)
	gameobject(Shape shape) : form(shape) {}

	void moveup(int deltaup) {
		y -= deltaup;
	}

	void movedown(int deltadown) {
		y += deltadown;
	}

	void movesleft(int deltaleft) {
		x -= deltaleft;
	}

	void moveright(int deltaright) {
		x += deltaright;
	}







};



#endif