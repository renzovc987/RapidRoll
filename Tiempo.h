#ifndef TIEMPO_H
#define TIEMPO_H
#include <string>
using namespace std;
class Tiempo
{
    private:

        int minutos;
        int segundos;
    public:
        Tiempo();
        string getTime();
        void sumarTime(float time);
};

#endif // TIEMPO_H
