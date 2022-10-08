#ifndef REGION_H
#define REGION_H
#include <string>
#include "Place.h"
using namespace std;

/*
    Autor: Karina Urbina
    Iniciado: 12/09/2022
    Ultima modificacion: 7/10/2022

*/

//Clase que contiene los atributos y métodos de las regiones.
class Region
{
    public:

        //Constructor
        Region(string, string, string);

        //Setters
        void setIdRegion(string);
        void setName(string);
        void setLocacion(string);
        void setPlaceList(Place*);

        //Getters
        string getIdRegion();
        string getName();
        string getLocation();
        class NodoSubPlace* getPlaceList();

        //Metodos
        bool validate(string,Region*);
        Region* add(string,string,string,Region*);
        Region* deleteRegion(string,Region*);
        Region* deleteAllRegion(Region*);
        Region* modify(string,string,string, string,Region*);
        Region* searchRegion(string,Region*);
        void print(Region*);
        Region* dataLoad(Region*);
        void printVarWeather(string ,int , int ,Region*);
        //Metodos de sublista
        NodoSubPlace* linkendPlaceRegion(string,string,Place*,Region*);
        void printSublistPlace(string,Region*);


        void monthlyRain(int ,string,Region* );

        //Puntero
        Region * next = NULL;
        class NodoSubPlace* placeSublist = NULL;

    private:

        string idRegion;
        string name;
        string location;
};

//Una sublista de lugares para una región.
class NodoSubPlace{
    public:
        NodoSubPlace* next = NULL;
        Place* linkPlace = NULL;
};

#endif // REGION_H


