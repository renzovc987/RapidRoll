#include "Bloque.h"
#include <string>
#include <stdlib.h>
#include "ia.h"
#include "SFML\Graphics.hpp"
#include <sstream>
#include <iostream>
#define to_string( x ) static_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
using namespace std;

RectangleShape Bloque::getRectangleShape(){
    return *s_bloque;

}
Vector2f Bloque::get_size(){
    Vector2f aux=(Vector2f)s_bloque->getSize();
    return aux;
}
Vector2f Bloque::get_position(){
    return s_bloque->getPosition();
}
void Bloque::set_pos()
{
    s_bloque->move(Vector2f(0.0,-2.0));
}

FloatRect Bloque::get_Global_Bound(){
    return s_bloque->getGlobalBounds();

}
Vector2f Bloque::getOrigin(){
    return s_bloque->getOrigin();
}

Vector2f Bloque_azul::menor(Ia &compu, int &der_izq) {
	float blo_y = this->get_position().y, blo_x = this->get_position().x, com_x = compu.getPosition().x;
	if (compu.getPosition().y<blo_y && blo_y < 700) {
		if (com_x > blo_x) {
			if (com_x - blo_x < 60 ) {
				return { 0, 0 };
			}
			return { com_x - blo_x, -1};
		}

		else {
			if (blo_x - com_x < 60) {
				return { 0, 0 };
			}
			return { blo_x - com_x, 1 };
		}
	}
	return { 3000,0 };
}

Bloque_azul::Bloque_azul(Vector2f posicion){
    int pro;
    string path="img/b_1.png";

    t_bloque = new Texture;
    t_bloque->loadFromFile(path);
    s_bloque = new RectangleShape({125.0,50.0});
    s_bloque->setTexture(t_bloque);

    s_bloque->setPosition(posicion);
    s_bloque->setOrigin(62.5,25.0);

}
int Bloque_azul::interseccion(FloatRect a,Bloque**b){
    FloatRect c_blo({s_bloque->getPosition().x-45,s_bloque->getPosition().y-25},{90,50});
    if(c_blo.intersects(a)){

        return 1;
    }
    return 0;



}

Bloque_verde::Bloque_verde(Vector2f posicion){
    int pro;
    string path="img/b_2.png";

    t_bloque = new Texture;
    t_bloque->loadFromFile(path);
    s_bloque = new RectangleShape({125.0,50.0});
    s_bloque->setTexture(t_bloque);

    s_bloque->setPosition(posicion);
    s_bloque->setOrigin(62.5,25.0);

}
int Bloque_verde::interseccion(FloatRect a,Bloque**b){
    FloatRect c_blo({s_bloque->getPosition().x-45,s_bloque->getPosition().y-25},{90,50});
    if(c_blo.intersects(a)){

        return 2;
    }
    return 0;


}

Bloque_rojo::Bloque_rojo(Vector2f posicion){
    int pro;
    string path="img/b_3.png";

    t_bloque = new Texture;
    t_bloque->loadFromFile(path);
    s_bloque = new RectangleShape({125.0,50.0});
    s_bloque->setTexture(t_bloque);
    s_bloque->setPosition(posicion);
    s_bloque->setOrigin(62.5,25.0);

}
int Bloque_rojo::interseccion(FloatRect a,Bloque**b){
    FloatRect c_blo({s_bloque->getPosition().x-45,s_bloque->getPosition().y-25},{90,50});
    if(c_blo.intersects(a)){

        return 3;
    }
    return 0;

}


Bloque_vida::Bloque_vida(Vector2f posicion){
    int pro;
    string path="img/item2.png";

    t_bloque = new Texture;
    t_bloque->loadFromFile(path);
    s_bloque = new RectangleShape({125.0,80.0});
    s_bloque->setTexture(t_bloque);
    s_bloque->setPosition(posicion);
    s_bloque->setOrigin(62.5,55.0);

}
int Bloque_vida::interseccion(FloatRect a,Bloque**b){
    FloatRect c_blo({s_bloque->getPosition().x-45,s_bloque->getPosition().y-25},{90,50});
    if(c_blo.intersects(a)){
        return 5;
    }
    return 0;


}
Bloque_score::Bloque_score(Vector2f posicion){
    int pro;
    string path="img/item.png";

    t_bloque = new Texture;
    t_bloque->loadFromFile(path);
    s_bloque = new RectangleShape({125.0,80.0});
    s_bloque->setTexture(t_bloque);
    s_bloque->setPosition(posicion);
    s_bloque->setOrigin(62.5,55.0);

}
int Bloque_score::interseccion(FloatRect a,Bloque**b){
    FloatRect c_blo({s_bloque->getPosition().x-45,s_bloque->getPosition().y-25},{90,50});
    if(c_blo.intersects(a)){
        return 4;
    }
    return 0;


}

