
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#define MAX_NUMBER_OF_ITEMS 3
#include <string.h>
#include <vector>

using namespace std;
using namespace sf;

class Menu
{
    int instruction;
    std::vector<class observer*>observerList;
public:
	Menu(float width, float height,char *a,char *b,char *c,int p,int p1,int s,int s1,int t,int t1);
	~Menu();
    sf::Vector2i posicion_mouse;
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	void procesarmouse(sf::RenderWindow &window);
	void cerrar(sf::RenderWindow &window);
	void off(sf::Music &music);
	void onn(sf::Music &music);
	void Invocador(string a,Menu menu,sf::RenderWindow &window,sf::Music &music);
	int GetPressedItem() { return selectedItemIndex; }
	sf::FloatRect get_bound(int a) {
		return menu[a].getGlobalBounds();
    //
	}
	int getinstruction()
        {
                return instruction;
        }

        void setinstruction(int newinstruction)
        {
                instruction =newinstruction;
                notify();
        }
        void attach(observer *obs)
        {
                observerList.push_back(obs);
        }

        void detach(observer *obs)
        {
                observerList.erase(std::remove(observerList.begin(),observerList.end(),obs),observerList.end());

        }
        void notify();

    //

private:
	int selectedItemIndex;
	sf::Font font;
	//sf::Text menu[MAX_NUMBER_OF_ITEMS];
	vector <Text> menu;


};
class observer
{
        Menu *_menu;
        public:
        observer(Menu *menu)
        {
                _menu=menu;
                _menu->attach(this);
        }
        virtual void update()=0;
        protected :
        Menu* getMenu()
        {
                return _menu;
        }
};

class GameObserver:public observer
{
        public: GameObserver(Menu *menu):observer(menu){}
                void update()
                {
                        int inst = getMenu()->getinstruction();
                        if(inst==1)
                        {
                                std::cout<<"Option Button Pressed"<<"\n";
                        }
                        else if(inst<0)
                        {
                                std::cout<<"Play Button Pressed"<<"\n";
                        }
                        else if(inst==0)
                        {
                                std::cout<<"Credits Button Pressed"<<"\n";
                        }
                        else if(inst==2)
                        {
                                std::cout<<"Sound Button Pressed"<<"\n";
                        }
                         else if(inst==3)
                        {
                                std::cout<<"Sound ON Button Pressed"<<"\n";
                        }
                        else if(inst==4)
                        {
                                std::cout<<"Sound OFF Button Pressed"<<"\n";
                        }
                           else if(inst==5)
                        {
                                std::cout<<"Return Button Pressed"<<"\n";
                        }
                         else if(inst==8)
                        {
                                std::cout<<"Exit Button Pressed"<<"\n";
                        }


                }

};

