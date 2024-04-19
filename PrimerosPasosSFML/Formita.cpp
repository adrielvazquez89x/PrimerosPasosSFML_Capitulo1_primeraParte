#include "Formita.h"

Formita::Formita()
{
	_forma.setFillColor(sf::Color::Red);
	_forma.setRadius(40);
	_forma.setPosition(10, 10);
}

sf::CircleShape& Formita::getFormita()
{
	return _forma;
}
