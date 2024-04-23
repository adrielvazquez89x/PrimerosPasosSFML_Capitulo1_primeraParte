#include <iostream>
#include <SFML/Graphics.hpp>
#include "Formita.h"

using namespace std;

void initShape(sf::RectangleShape& shape, sf::Vector2f const& pos, sf::Color const& color)
{
    shape.setFillColor(color);
    shape.setPosition(pos);
    shape.setOrigin(shape.getSize() * 0.5f); // el centro del rectángulo.-
}

int main() {
    sf::RenderWindow window(sf::VideoMode(480,180), "Ventana de prueba");
    window.setFramerateLimit(60);

    Formita circulo;
    sf::RectangleShape rectangulo(sf::Vector2f(50, 50));

    sf::Vector2f startPos = sf::Vector2f(50, 50); //Posición inicial
    sf::RectangleShape playerRect(sf::Vector2f(50, 50)); //Rectangulo del jugador
    initShape(playerRect, startPos, sf::Color::Green); //"Inicializamos"

    sf::RectangleShape targetRect(sf::Vector2f(50, 50));
    initShape(targetRect, sf::Vector2f(400, 50), sf::Color::Blue);

    sf::RectangleShape badRect(sf::Vector2f(50, 100));
    initShape(badRect, sf::Vector2f(250, 50), sf::Color::Red);


    rectangulo.setFillColor(sf::Color::Green);
    rectangulo.setPosition(100, 50); // Posición visible inicial
    bool moving = false;
    while (window.isOpen())
    {
        sf::Event evento;
        while (window.pollEvent(evento))
        {
            
            if (evento.type == sf::Event::Closed)
                window.close();

            if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape)
                window.close();

            /*
            if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::D)
                moving = true;
            if (evento.type == sf::Event::EventType::KeyReleased && evento.key.code == sf::Keyboard::D)
                moving = false;
              
              */
            //movimientos
            playerRect.move(10, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                playerRect.move(0, 10);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                playerRect.move(0, -10);
            //Target reached
            if (playerRect.getGlobalBounds().intersects(targetRect.getGlobalBounds()))
                window.close();
            //Bad intersect
            if (playerRect.getGlobalBounds().intersects(badRect.getGlobalBounds()))
                playerRect.setPosition(startPos);
        }

        // Actualización de lógica
        

        // Ciclo de renderización
        window.clear(sf::Color::Black);
        // Descomenta la siguiente línea si circulo está correctamente definido y Formita tiene el método getFormita
        // window.draw(circulo.getFormita()); 
        window.draw(playerRect);
        window.draw(badRect);
        window.draw(targetRect);
        window.display();
    }

    return 0;
}