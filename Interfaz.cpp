#include "Interfaz.h"
#define to_string( x ) static_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
#include <sstream>

Interfaz::Interfaz(Vector2f pos,Vida vida)
{
    this->vida=vida;
    t_barra=new Texture;
    t_barra->loadFromFile("img/barra.png");
    s_barra = new Sprite(*t_barra);
    s_barra->setScale(0.5,0.5);
    s_barra->setPosition(pos);
    s_barra->setOrigin(s_barra->getTexture()->getSize().x/2,s_barra->getTexture()->getSize().y/2);

    t_barra2=new Texture;
    t_barra2->loadFromFile("img/barra.png");
    s_barra2 = new Sprite(*t_barra2);
    s_barra2->setScale(0.5,0.5);
    s_barra2->setPosition(pos);
    s_barra2->setOrigin(s_barra2->getTexture()->getSize().x/2,s_barra2->getTexture()->getSize().y/2);

    t_time=new Texture;
    t_time->loadFromFile("img/time.png");
    s_time = new Sprite(*t_time);
    s_time->setScale(0.25,0.25);
    s_time->setPosition(pos.x,pos.y+240.0);
    s_time->setOrigin(s_time->getTexture()->getSize().x/2,s_time->getTexture()->getSize().y/2);


    t_score=new Texture;
    t_score->loadFromFile("img/score.png");
    s_score = new Sprite(*t_score);
    s_score->setScale(0.25,0.25);
    s_score->setPosition(pos.x,pos.y+290.0);
    s_score->setOrigin(s_score->getTexture()->getSize().x/2,s_score->getTexture()->getSize().y/2);

    f_time=new Font();
    f_time->loadFromFile("fonts/Fluo_Gums.ttf");

    txt_time = new Text();
    txt_time->setFont(*f_time);
    txt_time->setColor(Color::Blue);
    txt_time->setPosition(pos.x-10,pos.y+233.0);
    txt_time->setOrigin(txt_time->getGlobalBounds().width/2.0,txt_time->getGlobalBounds().height/2.0);
    txt_time->setCharacterSize(10);

    txt_score = new Text();
    txt_score->setFont(*f_time);
    txt_score->setColor(Color::Blue);
    txt_score->setPosition(pos.x,pos.y+283.0);
    txt_score->setOrigin(txt_score->getGlobalBounds().width/2.0,txt_score->getGlobalBounds().height/2.0);
    txt_score->setCharacterSize(10);


}
void Interfaz::dibujar_interfaz(RenderWindow*ven_1,int score){
    ven_1->draw(*s_barra);
    vida.show(*ven_1);
    ven_1->draw(*s_barra2);

    txt_score->setString(to_string(score));
    ven_1->draw(*s_score);
    ven_1->draw(*txt_score);

    ven_1->draw(*s_time);
    ven_1->draw(*txt_time);
    ven_1->draw(*txt_score);
}

Interfaz::~Interfaz()
{
    //dtor
}
