#include "SFML\Graphics.hpp"
#include "Vida.h"
#include "ia.h"
using namespace sf;
class Bloque
{
    protected:
        Texture*t_bloque;
        //Sprite s_bloque;
        RectangleShape*s_bloque;
    public:
        //Sprite getSprite();
        RectangleShape getRectangleShape();
        Vector2f get_size();
        Vector2f get_position();
        Vector2f getOrigin();
        virtual int interseccion(FloatRect a,Bloque**b)=0;
        FloatRect get_Global_Bound();
        void set_pos();

        virtual Vector2f menor(Ia &compu, int &der_izq) = 0;


};
class Bloque_azul:public Bloque{
    public:
    Bloque_azul(Vector2f posicion);
    virtual int interseccion(FloatRect a,Bloque**b);
    virtual Vector2f menor(Ia &compu, int &der_izq);

};
class Bloque_rojo:public Bloque{
    public:
    Bloque_rojo(Vector2f posicion);
    virtual int interseccion(FloatRect a,Bloque**b);
    virtual Vector2f menor(Ia &compu, int &der_izq) { return { 3000,0 }; }

};
class Bloque_verde:public Bloque{
    public:
    Bloque_verde(Vector2f posicion);
    virtual int interseccion(FloatRect a,Bloque**b);
    virtual Vector2f menor(Ia &compu, int &der_izq) { return { 3000,0 }; }

};

class Bloque_vida:public Bloque{
    public:
    Bloque_vida(Vector2f posicion);
    virtual int interseccion(FloatRect a,Bloque**b);
    virtual Vector2f menor(Ia &compu, int &der_izq) { return { 3000,0 }; }
};
class Bloque_score:public Bloque{
    public:
    Bloque_score(Vector2f posicion);
    virtual int interseccion(FloatRect a,Bloque**b);
    virtual Vector2f menor(Ia &compu, int &der_izq) { return { 3000,0 }; }
};
