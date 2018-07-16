#include <vector>
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <string>
#include "Bloque.h"
#include "Vida.h"
#include <SFML/System.hpp>
#include "Tiempo.h"
#include "Player.h"
#include <iostream>
using namespace sf;
using namespace std;
class Juego
{
    private:
        //CONTROL DE JUEGO
        Music music,music2;
        bool game_over;
        //VENTANA
        RenderWindow*ven_1;
        //GRAFICOS

        Texture *t_fondo=new Texture;
        Sprite *s_fondo=new Sprite,*s_player1,*s_player2;
        Texture *t_ptr=new Texture,*t_go,*t_player1,*t_player2;
        Sprite *s_ptr=new Sprite,*s_marco,*s_barra,*s_time,*s_score,*s_barra2,*s_go;
        Color*fondo;
        Event*evento1;
        int fps;

        float tam_x,tam_y;
        //vector<int> slots_bloques= {1,1,1,1,1,1,1,1};
        //int slots_bloques[8]={0,1,1,0,1,0,0,0};
        Bloque*o_bloques[6][8];
        //int p_bloques[6][8]={{1,1,1,0,0,1,1,1},{0,1,0,0,0,1,0,0},{0,0,1,0,1,0,0,1},{0,1,0,1,0,0,0,0},{1,0,0,0,1,0,0,1},{1,1,1,1,1,1,1,1}};
        vector<vector<int> > p_bloques;

        Clock*reloj_1;
        Time *tiempo1;
        float tiempo2;
        float tiempo3;
        bool empezar;
        int personajes;
        bool caendo;
        int col;
        int minutos;
        Tiempo*time;



        Player*s_personaje=new Player(Keyboard::A,Keyboard::D,{75.0,360.0});
        Time t_jugador;
        Clock clock;

        Player*s_personaje2 = new Player(Keyboard::Left,Keyboard::Right,{1230.0,360.0});
        Time t_jugador2;
        Clock clock2;


        Ia*s_compu = new Ia({ 1230.0,360.0 });
        Time t_compu;
        Clock clock3;
        int der_izq = 0;
        Vector2f meno_dist = { 3000,0 };





    public:
        Juego(Vector2f resolucion,string titulo);
        void gameloop();
        void gameloop2();

        void c_graficos();
        void p_eventos();
        void mover_bloques();
        void crear_bloques(int a);
        void dibujar_bloques();
        void cerrar();
        void p_pos();
        void inicializar_bloques();
        void inicializar_fil(int a);
        void gravedad();

        ~Juego();

};
class Estrategia {
  public:
	virtual void InterfazAlgoritmo()=0;
};
class EstrategiaRoja: public Estrategia {
	public:
		virtual void InterfazAlgoritmo(){
           cout<<"Se creo un bloque Rojo"<<endl;
		}
};
class EstrategiaAzul: public Estrategia {
	public:
		virtual void InterfazAlgoritmo(){
            cout<<"Se creo un bloque Azul"<<endl;
		}
};
class EstrategiaVerde: public Estrategia {
	public:
		virtual void InterfazAlgoritmo(){
		    cout<<"Se creo un bloque Verde"<<endl;
		}
};
class EstrategiaVida: public Estrategia {
	public:
		virtual void InterfazAlgoritmo(){
		    cout<<"Se creo un bloque de vida"<<endl;
		}
};
class Contexto {
	private:
		Estrategia *_estrategia;
	public:
	Contexto(Estrategia *estrategia):_estrategia(estrategia){}
	void set_estrategia(Estrategia *estrategia){
	    _estrategia=estrategia;
    }
	void InterfazContexto() {
        _estrategia->InterfazAlgoritmo();
    }
};
