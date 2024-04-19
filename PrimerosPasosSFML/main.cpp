#include <iostream>
#include <SFML/Graphics.hpp>
#include "Formita.h"

using namespace std;

int main() {
	/*
											 -+-+-+-+-+-+-+- CREACION DE VENTANAS -+-+-+-+-+-+-+-+-+-+-+

		De la libreria SF, objeto tipo Ventana.Con su constructor, el cual recibe parámetros : un objeto tipo VideoMode(el cual tambien
		recibe parámetros) y podemos agregar un título.
	*/

	//sf::Window window(sf::VideoMode(800, 600), "Megapanza");

	//Función para "dormir", recibe parámetro de segundos, estos una cantidad.
	// sf::sleep(sf::seconds(3));

	//La clase VideoMode contiene información del modo video de la ventana. Ancho, alto y bpm. 
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

	/*                                      -+-+-+-+-+-+-+- CREACION DE VIDEO MODE -+-+-+-+-+-+-+-+-+-+-+

	*/

	//Acá, podemos crear un modo de video, que toma el ancho de la pantalla de usuario. Por lo que veo, toma la resolucion completa.
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

	/*                                      -+-+-+-+-+-+-+- CREACION DE STYLE -+-+-+-+-+-+-+-+-+-+-+

	*/
	//El style permite poner los distintos modos de ver la ventana, por ej:
	/*
		sf::Style::None
		sf::Style::Titlebar
		sf::Style::Resize
		sf::Style::Close
		sf::Style::Fullscreen
		sf::Style::Default
	*/

	/*
		VideoMode, Titulo y Style son los parámetros necesarios para usar en un constructor de ventana.
	*/

	//Cuando queremos agregar varios estilos, "dividimos" con el pipe " | "
	sf::RenderWindow window(desktop, "Ventana de prueba", sf::Style::Titlebar | sf::Style::Close);

	/*
		+-+-+-+-++--+ MODIFICAR LA VISIBILIDAD DEL MOUSE *_*_*_*_*_**_*_*_*
	*/

	//Estoy sirve para "ocultar" el mouse por defecto. Podría servir para luego usar un cursor que nosotros queramos.
	// window.setMouseCursorVisible(false);

	


/*                                      -+-+-+-+-+-+-+-   EL GAME LOOP   -+-+-+-+-+-+-+-+-+-+-+     */
	//Importada del .h que creamos
	Formita circulo; 
	//clase que viene con la libreria
	sf::RectangleShape rectangulo(sf::Vector2f(50, 50));
	rectangulo.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		/*
		  El Game Loop tiene por lo general, 3 estapas:

		  1 - El manejador de entrada o handle input - que maneja los eventos que entran del teclado/mouse y ventana
		  2 - El update frame - Que actualiza los objetos en la escena
		  3 - El Render frame - Que renderiza o dibuja los objetos en la escena dentro de la ventana.

		*/

		/*
		|	---------------------------------- EVENT HANDLING ___________________________________________

			Los eventos se "pollean" desde la ventana mediante Window::pollEvent(sf::Event &event)
		*/



		//Por si solo, el while en el que estamos ahora no hace nada, ni si quiera podemos cerrar la ventana. Para eso, debemos configurarlo:
		//Un evento, tipo los eventos que usamos en JS o C#
		sf::Event evento;
		/*
		//Pero si quiero usar el evento asi, tampoco funciona:

		if (evento.type == sf::Event::Closed)
			window.close();

		*/
		//Hay que usar el evento dentro del pollEvent en otro while, que el pollEvent, se encarga de "escuchar" si suceden eventos.

		while (window.pollEvent(evento))
		{
			// Si el evento es de tipo 'Closed', entonces cerramos la ventana
			//if (evento.type == sf::Event::Closed)
				//window.close();

			/*
			Ahora bien, pienso yo, que la variable Evento es simplemente eso, una variable que se encarga de guardar
			los eventos que ocurran. Entonces el while procesa ese evento, que ahora es un "close". Entonces
			como ese evento es un close, se cierra la ventana.

			Estos son (creo que son todos) los eventos que puede usar una ventana:
			Event::Closed - Se dispara cuando el sistema operativo detecta que hicimos click en el botón de cerrar
			Event::Resized asociado con  Event::size - Se dispara cuando el SO, detecta que apretamos el boton de redimensonar
			Event::LostFocus
			Event::GainedFocus - Los ultimos dos eventos, se disparan cuando dejamos de hacer foco a la ventan, deduzco que es cuando
			hacemos click en otra ventana, mientras la app está abierta.

			Tenemos eventos del teclado, y eventos del mouse.
			Teclado:
			Event::KeyPressed
			Event::KeyReleased
			Event::TextEntered
			Mouse:
			Event::MouseMoved
			Event::MouseButtonPressed
			Event::MouseButtonReleased
			Event::MouseWheelMoved
			*/

			//SWITCH PARA VER ALGUNOS EVENTOS:
			//mas abajo vemos que esta variable:
			sf::String buffer;

			switch (evento.type)
			{
			case sf::Event::EventType::Closed:
				window.close();
				break;

			case sf::Event::EventType::KeyPressed:
				//Cambiar el título de la ventana cuando tocamos la barra espaciadora:
				if (evento.key.code == sf::Keyboard::Key::Space)
					window.setTitle("Opa! Apreste la barra un poquito");
				//Y ahora enter:
				if (evento.key.code == sf::Keyboard::Key::Enter)
					window.setTitle("Apa, te arrepentiste");
				break;


				/*
			case sf::Event::EventType::KeyReleased:
				if (evento.key.code == sf::Keyboard::Key::R)
					window.setTitle("Aflojaste el enter, apretaste R y soltaste.");
				if (evento.key.code == sf::Keyboard::Key::Escape)
					window.close();
				break;
				*/

				//Agregamos un evento un poco mas complejo: "TextEntered", arriba vas a ver una variable llamada buffer.
					//Ahora vamos a cambiar el títulos con una """"""combinación""""""" de teclas:
			case sf::Event::EventType::TextEntered:
				buffer += evento.text.unicode;
				break;
			case sf::Event::EventType::KeyReleased:
				if (evento.key.code == sf::Keyboard::P)
				{
					window.setTitle(buffer);
					buffer.clear();
				}
			default:
				break;
			}
			/*
				A simple vista, veo que keyPressed y KeyReleased hacen lo mismo.
				Pero Pareciera que cuando lo usamos en combinación con TextEntered tiene un comportamiento
				diferente.
			*/
			// - _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_
			// - _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_- _ -_
			// hay como un "proceso" para pode renderizar : Limpiar la pantalla, dibujar, y mostrar. (clear, draw, display)

			/*
			Another thing to note is that the canvas which we are rendering on is double buffered.
			This is very common in rendering. The way this works is quite simple—the canvas has
			two sides that you can render on. Throughout the render frame, we work only on one
			of the sides—the one which is not shown on the screen. After we inish rendering, we
			lip the canvas and show what we've done. In the next frame, we work on the other
			side of the canvas, and so on. This technique allows us to show the scene only after
			we've inished rendering it. In SFML, we lip the canvas (it's also sometimes known
			as "swap the buffers") by calling Window::display()
			*/

			// UPDATE


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