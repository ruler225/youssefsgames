#pragma once
#ifndef OTHER_FUNCTIONS_H
#define OTHER_FUNCTIONS_H

#include<SFML/Graphics.hpp>


void windowtasks(sf::RenderWindow& window, sf::Event& event);

//I'm not currently using this class, but I might in the future (or not)
//For now, I'm just working on it, practicing my class-making skills, and see if this becomes something useful
class gameobject {
private:
	int x = 0;
	int y = 0;
public:
	void position(int x, int y) {
		gameobject::x = x;
		gameobject::y = y;
	}



};

#endif