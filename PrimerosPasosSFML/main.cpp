#include <iostream>
#include <SFML/Graphics.hpp>
#include "Formita.h"

using namespace std;

int main() {

	sf::VideoMode modo(600, 600);
	//is Valid, es un método para saber si la resolución que usamos es compatible con el fullscreen de nuestro monitor.
	bool valid = modo.isValid();
	//acá da Falso, porque 600x600 no es.
	cout << valid << endl;

	modo.width = 1920;
	modo.height = 1080;
	//Pero acá si da verdadero.
	valid = modo.isValid();
	cout << valid << endl;

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktop, "Ventana de prueba", sf::Style::Titlebar | sf::Style::Close);

	Formita circulo;
	sf::RectangleShape rectangulo(sf::Vector2f(50, 50));
	rectangulo.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event evento;

		while (window.pollEvent(evento))
		{
			switch (evento.type)
			{
			case sf::Event::EventType::Closed:
				window.close();
				break;

			case sf::Event::EventType::KeyPressed:
				if (evento.key.code == sf::Keyboard::Key::Escape)
					window.close();
				break;
			default:
				break;
			}

			// RENDER CYCLE
			window.clear(sf::Color::Black);

			window.draw(circulo.getFormita());
			window.draw(rectangulo);

			// RENDER OBJECTS
			window.display();

		}

		//Acá termina el while principal
	}


	return 0;
}