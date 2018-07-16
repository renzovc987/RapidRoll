#include "Menu.h"


Menu::Menu(float width, float height,char *a,char *b,char *c,int p,int p1,int s,int s1,int t,int t1)
{
    menu.resize(3);

	if (!font.loadFromFile("fonts/arial.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Black);
	menu[0].setString(a);
	menu[0].setPosition(sf::Vector2f(p, p1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString(b);
	menu[1].setPosition(sf::Vector2f(s, s1));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString(c);
	menu[2].setPosition(sf::Vector2f(t,t1));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}
void Menu::procesarmouse(sf::RenderWindow &window) {
	posicion_mouse = sf::Mouse::getPosition(window);
	posicion_mouse = (sf::Vector2i)window.mapPixelToCoords(posicion_mouse);


}
void Menu::notify()
{
        if(observerList.empty())
                return;
        for(int i=0;i< observerList.size(); ++i)
        {
                observerList[i]-> update();
        }
}
void Menu::cerrar(sf::RenderWindow &window){

    window.close();

}

void Menu::off(sf::Music &music){
    music.stop();
}
void Menu::onn(sf::Music &music){
    music.play();
}

void Menu::Invocador(string key,Menu menu,sf::RenderWindow &window,sf::Music &music){
    if(key=="cerrar"){
            menu.cerrar(window);}
    else if(key=="onn"){
        menu.onn(music);
    }
    else if(key=="off"){
        menu.off(music);
    }

}
