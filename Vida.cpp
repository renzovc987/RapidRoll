#include "Vida.h"
#include <sstream>
#include <iostream>
using namespace std;
Vida::Vida()
{

	points_player = 9;

	t_cora.loadFromFile("img/vida.png");


}

void Vida::subPointPlayer()
{
	vid[points_player - 1].setFillColor(sf::Color::Transparent);
	points_player--;

}
void Vida::addPointPlayer()
{
    if(points_player<9){
        vid[points_player].setFillColor(sf::Color::Red);
        vid[points_player].setTexture(&t_cora);
        points_player++;
    }


}
int Vida::getVida()
{
	return points_player;
}


void Vida::show(sf::RenderWindow& window)
{

	for (int i =0; i <points_player; i++) {
		window.draw(vid[i]);
	}

}
void Vida::setX(float X){
    float esp = 250;

	for (int i = 0; i < points_player; i++) {
		vid[i].setTexture(&t_cora);
		vid[i].setSize(sf::Vector2f(40, 36));
		vid[i].setOrigin(20.0,18.0);
		vid[i].setPosition(X+2, esp);
		esp = esp + 36;
	}
}
