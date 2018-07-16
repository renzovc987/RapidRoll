#pragma once
#include <SFML/Graphics.hpp>

class Vida
{
public:
	Vida();

	void show(sf::RenderWindow& window);
    void setX(float X);
	void subPointPlayer();
	void addPointPlayer();
	int getVida();

private:
	int points_player;
	sf::RectangleShape vid[9];
	sf::Texture t_cora;


}; // class Vida
