#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Vida.h"
using namespace sf;
class Interfaz
{
    public:
        Vida vida;
        Interfaz(Vector2f pos,Vida vida);
        virtual ~Interfaz();
        void dibujar_interfaz(RenderWindow*ven_1,int score);
        Texture *t_barra,*t_time,*t_score,*t_barra2;
        Sprite *s_barra,*s_time,*s_score,*s_barra2;
        Text*txt_time;
        Text*txt_score;
        Font*f_time;

    private:
};

#endif // INTERFAZ_H
