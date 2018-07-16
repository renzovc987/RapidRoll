#include "Tiempo.h"
#include <string>
#include <iostream>
#include <sstream>
#define to_string( x ) static_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
Tiempo::Tiempo()
{
    segundos=0;
    minutos=0;

}
string Tiempo::getTime(){
    string aux="";
    if(minutos<=9){
        aux=aux+"0";
    }
    aux+=to_string(minutos);
    aux+=" : ";
    if(segundos<=9){
        aux=aux+"0";
    }
    aux+=to_string(segundos);

    return aux;
}

void Tiempo::sumarTime(float time){
    if(time>segundos){

    }

}
