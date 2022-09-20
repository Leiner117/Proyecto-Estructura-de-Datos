#ifndef EPHEMERALITY_H
#define EPHEMERALITY_H
#include <string>

/*
 Creado: 16/09/2022 ultima mod: 19/09/2022
 Autor: Leiner Alvarado
 */

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
        //Funciones

        Ephemerality*addEphemerality(string,string,string,string,Ephemerality*);//Agrega un nodo a la lista
        Ephemerality*searchEphemerality(string,Ephemerality*);// Retorna un nodo buscado
        Ephemerality*deleteEphemerality(string,Ephemerality*);// Borra un nodo seleccionado de la lista
        void printEphemeralityList(Ephemerality*);// imprime la lista de efimeridad



    private:
        //Atributos
        string name;// Nombre
        string date;// Fecha
        string departureTime;// Hora de Salida
        string hideTime;// Hora de ocultamiento

};

#endif // EPHEMERALITY_H
