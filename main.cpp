#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#define MAX_NUMBER_OF_ITEMS 3
#include <string.h>
#include "Menu.h"
#include "Juego.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Rapid Roll");
	Menu menu(window.getSize().x, window.getSize().y,"Play","Options","Exit",240, 402,217, 463,240, 525);
	//
    Menu*menup = &menu; //subject
    GameObserver gameobs(menup);
	//
	sf::Texture texture_back;
	sf::Sprite background;
	texture_back.loadFromFile("menuima.png");
	background.setTexture(texture_back);
	sf::Music music;
	music.openFromFile("sounds/song.wav");
	music.setLoop(true);
	menu.Invocador("onn",menu,window,music);


	while (window.isOpen())
	{

		menu.procesarmouse(window);
		sf::Event event;

		while (window.pollEvent(event))
		{


			switch (event.type)
			{
			// Aqui agregas lo que quieres que haga
			case sf::Event::MouseButtonPressed:

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//Repites esto en todas tus condiciones y en el get_boun( ) le pones como parametro la opcion
					sf::FloatRect bound_mouse(sf::Vector2f(menu.posicion_mouse), { 32,32 });
					if (menu.get_bound(0).intersects(bound_mouse)) {
						//condicion cuando haga play
						//window.close();
						menup->setinstruction(-1);
						menu.Invocador("cerrar",menu,window,music);
						menu.Invocador("off",menu,window,music);
						Juego game1({1300,700},"RapidRoll");
					}
					if (menu.get_bound(1).intersects(bound_mouse)) {
						//condcion cuando haga option
						menup->setinstruction(1);
						sf::RenderWindow window1(sf::VideoMode(600, 600), "Rapid Roll");
                        Menu menu1(window1.getSize().x, window1.getSize().y,"Sound","Credits","Return",227, 402,220, 463,227, 525);
                        sf::Texture texture_back1;
                        sf::Sprite background1;
                        texture_back1.loadFromFile("menuima.png");
                        background1.setTexture(texture_back1);

						while (window1.isOpen())
                        {
                            menu.procesarmouse(window1);
                            sf::Event event1;

                            while (window1.pollEvent(event1))
                            {
                            switch (event1.type)
                            {
                                case sf::Event::MouseButtonPressed:

                                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            sf::FloatRect bound_mouse(sf::Vector2f(menu.posicion_mouse), { 32,32 });
                            if (menu1.get_bound(0).intersects(bound_mouse)) {

                                menup->setinstruction(2);
                                sf::RenderWindow window2(sf::VideoMode(600, 600), "Rapid Roll");
                                Menu menu2(window2.getSize().x, window2.getSize().y,"ON","OFF","Return",245, 402,240, 463,227, 525);
                                sf::Texture texture_back2;
                                sf::Sprite background2;
                                texture_back2.loadFromFile("menuima.png");
                                background2.setTexture(texture_back2);


                                while (window2.isOpen())
                                {
                                    menu2.procesarmouse(window2);
                                    sf::Event event2;

                                    while (window2.pollEvent(event2))
                                    {
                                    switch (event2.type)
                                    {
                                        case sf::Event::MouseButtonPressed:

                                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                                {
                                    sf::FloatRect bound_mouse(sf::Vector2f(menu2.posicion_mouse), { 20,20 });
                                    if (menu2.get_bound(0).intersects(bound_mouse)) { menup->setinstruction(3);music.openFromFile("sounds/song.wav");
                                        music.setLoop(true);
                                       menu2.Invocador("onn",menu2,window2,music);}
                                    else if (menu2.get_bound(1).intersects(bound_mouse)) { menup->setinstruction(4);menu2.Invocador("off",menu2,window2,music);}
                                    else if (menu2.get_bound(2).intersects(bound_mouse)) { menup->setinstruction(5);menu2.Invocador("cerrar",menu2,window2,music);}


                            }
                                    }
                                    }
                                    window2.clear();
                                    window2.draw(background2);
                                    menu2.draw(window2);
                                    window2.display();
                                }
                            }

                            if(menu1.get_bound(1).intersects(bound_mouse)){
                                menup->setinstruction(0);
                                sf::RenderWindow window4(sf::VideoMode(728, 577), "SFML WORK!");
                                    sf::Texture texture_back;
                                    sf::Sprite background;
                                    texture_back.loadFromFile("img/creditos.png");
                                    background.setTexture(texture_back);
                                    	while (window4.isOpen())
                                    {
                                        sf::Event evento;
                                        while (window4.pollEvent(evento))
                                        {
                                            if (evento.type == sf::Event::Closed)
                                            menu1.Invocador("cerrar",menu1,window4,music);
                                        }

                                        window4.clear();
                                        window4.draw(background);
                                        window4.display();


                                    }
                                        break;
                            }
                            if(menu1.get_bound(2).intersects(bound_mouse)){
                                menup->setinstruction(5);
                                menu1.Invocador("cerrar",menu1,window1,music);
                            }
                        }
                            }
                            }
                            window1.clear();
                            window1.draw(background1);
                            menu1.draw(window1);
                            window1.display();
                        }




					}
					if (menu.get_bound(2).intersects(bound_mouse)) {
						menup->setinstruction(8);
						menu.Invocador("cerrar",menu,window,music);
					}
				}


			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:

					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;



				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						menup->setinstruction(-1);
						window.close();
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}

					break;
				}

				break;


			case sf::Event::Closed:
				window.close();

				break;



			}
		}
		//menu.procesarmouse(window);
		window.clear();
		window.draw(background);
		menu.draw(window);


		window.display();
	}
}



