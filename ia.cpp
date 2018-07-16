#include "ia.h"
//#include "config.h"
#include <iostream>
using namespace sf;
using namespace std;
Ia::Ia(Vector2f pos)
	: sf::RectangleShape()
{
	texture_ia.loadFromFile("img/p_1.png");
	this->setTexture(&texture_ia);

	this->speed = 200.0f;
	this->setSize(sf::Vector2f(80, 80));

	this->setOrigin(40, 40);

	vida.setX(pos.x);

	interfaz = new Interfaz(pos, vida);
}



void Ia::updateIa(sf::Time& delta, bool &caendo, int der_izq) {
	this->move(0, delta.asSeconds() * 200.f);
}

void Ia::set_speed(float sp) {
	speed = sp;
}

float Ia::get_speed() {
	return speed;
}

void Ia::d_interfaz(RenderWindow*ven_1) {
	interfaz->dibujar_interfaz(ven_1,score);
}

Vida Ia::getVida() {
	return vida;
}
