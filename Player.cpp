#include "player.h"
//#include "config.h"
#include <iostream>
using namespace sf;
using namespace std;
Player::Player(Keyboard::Key te_left,Keyboard::Key te_right,Vector2f pos):RectangleShape(){
	texture_player.loadFromFile("img/p_1.png");
	texture_player_vol.loadFromFile("img/p_1_vol.png");

	this->setTexture(&texture_player);

	this->speed = 200.0f;
	this->setSize(sf::Vector2f(80, 80));

	this->setOrigin(40, 40);

	this->te_left=te_left;
    this->te_right=te_right;
    vida.setX(pos.x);

    interfaz =new Interfaz(pos,vida);
    score=0;
}

void Player::updateHuman(sf::Time& delta,bool &caendo){
	float top = this->getGlobalBounds().top;
	float bottom = this->getGlobalBounds().top + this->getGlobalBounds().height;
	float left = this->getGlobalBounds().left;
	float right = this->getGlobalBounds().left + this->getGlobalBounds().width;

    this->move(0,delta.asSeconds() * 200.f);

	if (sf::Keyboard::isKeyPressed(te_right) && right < 1150) {
		/*if (caendo) { this->move(Vector2f(+2.0, 0.0)); }
		else { this->move(Vector2f(+15.0, 0.0)); }*/

		this->move(delta.asSeconds() * speed, 0);
        this->setTexture(&texture_player);
	}
	if (sf::Keyboard::isKeyPressed(te_left) && left > 150) {
		/*if (caendo) { this->move(Vector2f(-2.0, 0.0)); }
		else { this->move(Vector2f(-15.0, 0.0)); }*/

		this->move(-delta.asSeconds() * speed, 0);
        this->setTexture(&texture_player_vol);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && top > 0) {
		caendo = false;
		this->move(Vector2f(0.0, -delta.asSeconds() * 100.f));
	}

}

void Player::set_speed(float sp) {
	speed = sp;
}

float Player::get_speed() {
	return speed;
}

void Player::d_interfaz(RenderWindow*ven_1){
    interfaz->dibujar_interfaz(ven_1,score);
}

Vida Player::getVida(){
    return vida;
}
