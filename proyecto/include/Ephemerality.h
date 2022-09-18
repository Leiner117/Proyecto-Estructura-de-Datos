#ifndef EPHEMERALITY_H
#define EPHEMERALITY_H
#include <string>

using namespace std;
class Ephemerality
{
    public:
        //Constructor
        Ephemerality(string,string,string,string);

        //Setters
        void setName(string);
        void setDate(string);
        void setDepartureTime(string);
        void setHideTime(string);
        //Getters
        string getName();
        string getDate();
        string getDepartureTime();
        string getHideTime();

        Ephemerality*next;// Siguiente
        Ephemerality*pre;// Anterior



    private:
        //Atributos
        string name;// Nombre
        string date;// Fecha
        string departureTime;// Hora de Salida
        string hideTime;// Hora de ocultamiento

};

#endif // EPHEMERALITY_H
