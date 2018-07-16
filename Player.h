#include "Vida.h"
#include "Interfaz.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Player : public sf::RectangleShape
{
public:

    float speed;
	Interfaz*interfaz;
	sf::Texture texture_player;
	sf::Texture texture_player_vol;
    int score;

	Player(Keyboard::Key,Keyboard::Key,Vector2f pos);
    Keyboard::Key te_left,te_right;
    Vida vida;
	void updateHuman(sf::Time& delta,bool &caendo);
	float get_speed();
	void set_speed(float sp);
    Vida getVida();
    void d_interfaz(RenderWindow*ven_1);


}; // class Paddle

