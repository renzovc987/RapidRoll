#include "Juego.h"
#include "SFML\Graphics.hpp"
#include <string>
#include <SFML/System.hpp>
#include <sstream>
#include <iostream>
#define to_string( x ) static_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
using namespace std;
using namespace sf;
Juego::Juego(Vector2f resolucion ,string titulo){
    music.openFromFile("sounds/1.wav");
	music.setLoop(true);
	music.play();
	music2.openFromFile("sounds/2.wav");
    game_over=false;
    fps=60;
    fondo = new Color(240,230,140);
    evento1= new Event;
    caendo=true;
    ven_1 =new RenderWindow(VideoMode(resolucion.x,resolucion.y),titulo);
    ven_1->setFramerateLimit(fps);
    tam_x=ven_1->getSize().x;
    tam_y=ven_1->getSize().y;
    c_graficos();
    empezar=false;
    personajes=2;
    s_compu->setFillColor(Color::Red);

    //ocultar mouse
    ven_1->setMouseCursorVisible(false);

    reloj_1=new Clock;
    tiempo1=new Time;
    tiempo2=0;
    tiempo3=0;
    minutos=0;
    time=new Tiempo;
    if(personajes==2){
        s_compu->setPosition({-20.0,-20.0});
    }
    else{
        s_personaje2->setPosition({-20.0,-20.0});
    }

    p_bloques.resize(6);
    for(int i=0;i<6;i++){
        p_bloques[i].resize(8);
    }
    inicializar_bloques();
    p_bloques[0][0]=1;p_bloques[0][1]=1;p_bloques[0][2]=1;
    p_bloques[0][5]=1;p_bloques[0][6]=1;p_bloques[0][7]=1;

    gameloop();


}



void Juego::gameloop(){
    int a=0;
    while(!game_over)
    {
        t_jugador = clock.restart();
        if(personajes==2){t_jugador2 = clock2.restart();}
        else{t_compu = clock3.restart();}




		if (s_personaje->interfaz->vida.getVida() <= 0 ||s_personaje2->interfaz->vida.getVida()<= 0||s_compu->interfaz->vida.getVida()<= 0) {
			music2.setLoop(true);
            music2.play();
            music.stop();
			while(ven_1->isOpen()){
                ven_1->clear();

                if(s_personaje->score>s_personaje2->score){
                    ven_1->draw(*s_player1);
                }
                else{
                    ven_1->draw(*s_player2);
                }
                p_eventos();
                ven_1->display();
			}
		}

        *tiempo1=reloj_1->getElapsedTime();



        time->sumarTime(tiempo1->asSeconds());
        if(tiempo1->asSeconds()>1.5+tiempo2){
            empezar=true;
            if(a==6){a-=6;}
            tiempo2=tiempo1->asSeconds();
            crear_bloques(a);
            if(a==5){inicializar_fil(0);}
            else{inicializar_fil(a+1);}
            s_personaje->score+=50;
            s_personaje2->score+=50;
            s_compu->score+=50;
            a++;
        }

        //cout<<"A"<<endl;
        ven_1->clear(*fondo);
        ven_1->draw(*s_fondo);

        dibujar_bloques();
        if(empezar){
           ven_1->draw(*s_personaje);
            ven_1->draw(*s_personaje2);
            ven_1->draw(*s_compu);
            s_personaje->updateHuman(t_jugador, caendo);
            if(personajes==2){s_personaje2->updateHuman(t_jugador2, caendo);}
            else{s_compu->updateIa(t_compu, caendo, der_izq);}

        }



        //cout<<"B"<<endl;
        mover_bloques();
        //cout<<"C"<<endl;
        p_eventos();


        p_pos();

        s_personaje->d_interfaz(ven_1);
        if(personajes==2){s_personaje2->d_interfaz(ven_1);}
        else{
           s_compu->d_interfaz(ven_1);
        }

        ven_1->draw(*s_ptr);
        ven_1->display();
        //cout<<"D"<<endl;
    }





}

void Juego::p_pos(){
    if(s_personaje->getPosition().y<-30||s_personaje->getPosition().y>730){
        s_personaje->setPosition(200.0,100.0);
        s_personaje->interfaz->vida.subPointPlayer();
        s_personaje->score-=40;
    }
    if(s_personaje2->getPosition().y<-30||s_personaje2->getPosition().y>730){
        s_personaje2->setPosition(900.0,100.0);
        s_personaje2->interfaz->vida.subPointPlayer();
        s_personaje2->score-=40;
    }
    if(s_personaje->getGlobalBounds().intersects(s_personaje2->getGlobalBounds())){
        s_personaje2->interfaz->vida.subPointPlayer();
        s_personaje->interfaz->vida.subPointPlayer();
        s_personaje->setPosition(200.0,100.0);
        s_personaje2->setPosition(900.0,100.0);
    }
    if (s_compu->getPosition().y<-30 || s_compu->getPosition().y>730) {
		s_compu->setPosition(900.0, 100.0);
	}
}

void Juego::c_graficos(){

    s_personaje->setPosition({200.0,0.0});
    s_personaje2->setPosition({800.0,0.0});
    //s_personaje->setScale(80.0/t_personaje->getSize().x,80.0/t_personaje->getSize().y);

    s_compu->setPosition({ 500.0,0.0 });


    t_fondo->loadFromFile("img/f_1.jpg");
    s_fondo->setTexture(*t_fondo);

    t_player1=new Texture;
    t_player1->loadFromFile("img/f_4.png");
    s_player1 = new Sprite(*t_player1);
    s_player1->setScale(tam_x/t_player1->getSize().x,tam_y/t_player1->getSize().y);

    t_player2=new Texture;
    t_player2->loadFromFile("img/f_3.png");
    s_player2 = new Sprite(*t_player2);
    s_player2->setScale(tam_x/t_player2->getSize().x,tam_y/t_player2->getSize().y);

    //cambiar tamaño pantalla
    s_fondo->setScale((float)(ven_1->getSize().x-300.0)/t_fondo->getSize().x,(float)(ven_1->getSize().y)/t_fondo->getSize().y);
    s_fondo->move({+150,0});

    t_go=new Texture;
    t_go->loadFromFile("img/f_3.jpg");
    s_go = new Sprite(*t_go);
    s_go->setScale(tam_x/t_go->getSize().x,tam_y/t_go->getSize().y);

    t_ptr->loadFromFile("img/ptr.png");
    s_ptr->setTexture(*t_ptr);
    s_ptr->setScale(50.0/t_ptr->getSize().x,50.0/t_ptr->getSize().y);

    s_personaje2->setFillColor(sf::Color::Green);
}

void Juego::inicializar_fil(int a){
    for(int i=0;i<8;i++){
        int bloque=rand()%100+0;
        if(bloque>=30){
            p_bloques[a][i]=1;
        }
        else{
            p_bloques[a][i]=0;
        }

    }

}


void Juego::mover_bloques(){

    col=0;
    int tipo,tipo2,tipo3;
    meno_dist.x = 3000;

    for(int j=0;j<6;j++)
    {
        for(int i=0;i<8;i++)
            {
            if(p_bloques[j][i]==1&&o_bloques[j][i]!=NULL){
                o_bloques[j][i]->set_pos();
                // FloatREct recibe posicion en x ,y ,ancho,alto
                tipo=o_bloques[j][i]->interseccion(s_personaje->getGlobalBounds(),&o_bloques[j][i]);
                tipo2=o_bloques[j][i]->interseccion(s_personaje2->getGlobalBounds(),&o_bloques[j][i]);
                tipo3 = o_bloques[j][i]->interseccion(s_compu->getGlobalBounds(), &o_bloques[j][i]);
				if (o_bloques[j][i]->menor(*s_compu, der_izq).x < meno_dist.x) {
					meno_dist = o_bloques[j][i]->menor(*s_compu, der_izq);
				}

                if(tipo!=0){

                    col++;
                    if(tipo==2||tipo==3){

                        delete o_bloques[j][i];
                        o_bloques[j][i]=NULL;
                        col=0;
                        if(tipo==2){
                            s_personaje->score-=100;
                        }
                        if(tipo==3){
                            s_personaje->interfaz->vida.subPointPlayer();
                        }

                    }
                    else if(tipo==4){
                            s_personaje->score+=500;
                            o_bloques[j][i]=new Bloque_azul(o_bloques[j][i]->get_position());

                        }
                    else if(tipo==5){
                            s_personaje->interfaz->vida.addPointPlayer();
                            delete o_bloques[j][i];
                            o_bloques[j][i]=NULL;
                        }
                    else{
                        tiempo3=0;
                        if(s_personaje->getPosition().y<o_bloques[j][i]->get_position().y){
                            s_personaje->setPosition(s_personaje->getPosition().x,o_bloques[j][i]->get_position().y-60);

                        }
                    }
                }
                if(tipo2!=0){

                    col++;
                    if(tipo2==2||tipo2==3){
                        delete o_bloques[j][i];
                        o_bloques[j][i]=NULL;
                        col=0;
                        if(tipo==2){
                            s_personaje2->score-=100;
                        }
                        if(tipo2==3){
                            s_personaje2->interfaz->vida.subPointPlayer();
                        }
                    }
                    else if(tipo2==4){
                            s_personaje2->score+=500;
                            o_bloques[j][i]=new Bloque_azul(o_bloques[j][i]->get_position());

                        }
                    else if(tipo2==5){
                            s_personaje2->interfaz->vida.addPointPlayer();
                            delete o_bloques[j][i];
                            o_bloques[j][i]=NULL;
                        }
                    else{
                        tiempo3=0;
                        if(s_personaje2->getPosition().y<o_bloques[j][i]->get_position().y){
                            s_personaje2->setPosition(s_personaje2->getPosition().x,o_bloques[j][i]->get_position().y-60);

                        }
                    }
                }

                if (tipo3 != 0) {

					col++;
                    if(tipo3==2||tipo3==3){
                        delete o_bloques[j][i];
                        o_bloques[j][i]=NULL;
                        col=0;
                        if(tipo3==2){
                            s_compu->score-=100;
                        }
                        if(tipo3==3){
                            s_compu->interfaz->vida.subPointPlayer();
                        }
                    }
                    else if(tipo3==4){
                            s_compu->score+=500;
                            o_bloques[j][i]=new Bloque_azul(o_bloques[j][i]->get_position());

                        }
                    else if(tipo3==5){
                            s_compu->interfaz->vida.addPointPlayer();
                            delete o_bloques[j][i];
                            o_bloques[j][i]=NULL;
                        }
					else {
						tiempo3 = 0;
						if (s_compu->getPosition().y<o_bloques[j][i]->get_position().y) {
							s_compu->setPosition(s_compu->getPosition().x, o_bloques[j][i]->get_position().y - 60);

						}
					}
				}

                if(col>=1){caendo=false;}
                else{caendo=true;}


            }
        }
    }

	if (s_compu->getPosition().y < 300) {
		if (s_compu->getPosition().x >= 1100) {
			der_izq = -1;
		}
		else if (s_compu->getPosition().x <= 160)
			der_izq = 1;
		else if (der_izq == 0)
			der_izq = 1;
	}
	else
		der_izq = meno_dist.y;
	s_compu->move(t_compu.asSeconds() * 200.0f * der_izq, 0);


}




void Juego::p_eventos(){
	while (ven_1->pollEvent(*evento1))
	{
		switch (evento1->type)
		{
		case Event::Closed:
			exit(1);
			break;
		case Event::MouseMoved:
			s_ptr->setPosition((Vector2f)Mouse::getPosition(*ven_1));
			break;
		}
        if(Keyboard::isKeyPressed(Keyboard::Space)){
            this->cerrar();
            Juego game2({1300,700},"RapidRoll");

        }
	}

}

void Juego::crear_bloques(int f){
    EstrategiaAzul ea;
    EstrategiaRoja er;
    EstrategiaVerde ev;
    EstrategiaVida evi;
    int pro;
    for(int i=0;i<8;i++)

    {
        if(p_bloques[f][i]==1)
        {
            pro=rand()%100+0;
            if(pro<=20){
                Contexto contexto(&er);
                contexto.InterfazContexto();
                reinterpret_cast<Bloque_rojo*>(o_bloques[f][i]);
                o_bloques[f][i]=new Bloque_rojo({float(125.0*i)+62.5+150.0,float(tam_y)});
            }
            else if(pro>20&&pro<=50){
                Contexto contexto(&ev);
                contexto.InterfazContexto();
                reinterpret_cast<Bloque_verde*>(o_bloques[f][i]);
                o_bloques[f][i]=new Bloque_verde({float(125.0*i)+62.5+150.0,float(tam_y)});
            }
            else if(pro>50&&pro<=60){
                Contexto contexto(&evi);
                contexto.InterfazContexto();
                reinterpret_cast<Bloque_score*>(o_bloques[f][i]);
                o_bloques[f][i]=new Bloque_score({float(125.0*i)+62.5+150.0,float(tam_y)});
            }
            else if(pro>60&&pro<=65){
                Contexto contexto(&evi);
                contexto.InterfazContexto();
                reinterpret_cast<Bloque_vida*>(o_bloques[f][i]);
                o_bloques[f][i]=new Bloque_vida({float(125.0*i)+62.5+150.0,float(tam_y)});
            }
            else{
                Contexto contexto(&ea);
                contexto.InterfazContexto();
                reinterpret_cast<Bloque_azul*>(o_bloques[f][i]);
                o_bloques[f][i]=new Bloque_azul({float(125.0*i)+62.5+150.0,float(tam_y)});
            }


        }
        else{
            delete o_bloques[f][i];
            o_bloques[f][i]=NULL;

        }

    }
}



void Juego::dibujar_bloques(){
    for(int j=0;j<6;j++)
    {
        for(int i=0;i<8;i++)
            {

                if(o_bloques[j][i]!=NULL)
                {

                    ven_1->draw(o_bloques[j][i]->getRectangleShape());
                }
            }
    }
}


void Juego::inicializar_bloques(){
    for(int j=0;j<6;j++)
        for(int i=0;i<8;i++){o_bloques[j][i]=NULL;p_bloques[j][i]=0;}

}


void Juego::cerrar(){
    music2.stop();
    ven_1->close();

}
Juego::~Juego()
{
    delete s_personaje2;
    delete s_personaje;

    for(int j=0;j<6;j++)
        for(int i=0;i<8;i++){delete o_bloques[j][i];}

    delete t_fondo;
    delete s_go;
}
