#pragma once
#include <SFML/Graphics.hpp>

class Formita
{
private:
	sf::CircleShape _forma;

public:
	//Constructor
	Formita();

	//getter
	sf::CircleShape& getFormita();
};

