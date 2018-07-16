#ifndef Ia_CPP
#define Ia_CPP


#include "Vida.h"
#include "Interfaz.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Ia : public sf::RectangleShape
{
public:

	float speed;
	Interfaz*interfaz;
	sf::Texture texture_ia;
	sf::Texture texture_ia_vol;
	bool encima=false;
    int score;
	Ia(Vector2f pos);
	//Keyboard::Key te_left,te_right;
	Vida vida;
	void updateIa(sf::Time& delta, bool &caendo, int der_izq);
	float get_speed();
	void set_speed(float sp);
	Vida getVida();
	void d_interfaz(RenderWindow*ven_1);
	void set_encima(bool a) {
		encima = a;
	}




}; // class Paddle

#endif // !Ia_CPP

