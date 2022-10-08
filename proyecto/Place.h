#ifndef PLACE_H
#define PLACE_H
#include <string>
#include "TimeRegis.h"
#include "People.h"

using namespace std;

/*
    Autor: Karina Urbina
    Iniciado: 12/09/2022
    Ultima modificacion: 7/10/2022

*/

//Clase que contiene los atributos y métodos de los lugares.
class Place
{
    public:

        //Constructor
        Place(string, int, float);

        //Setters
        void setName(string);
        void setPopulation(int);
        void setSquareMeters(float);
        void setTimeRegis(TimeRegis*);
        //Getters
        string getName();
        int getPopulation();
        float getSquareMeters();
        TimeRegis*getTimeRegis();

        //Metodos

        Place* add(string,int,float,Place*);
        Place* modify(string,string,int,float,Place*);
        Place* deletePlace(string,Place*);
        Place* searchPlace(string, Place*);
        void print(Place*);
        Place* dataLoad(Place*);
        void printRainyDays(int ,string,Place*);
        void printPercentageRain(int ,string ,Place*);
        void monthlyRainfallExtremes(string ,int ,Place*);
        //Metodos de sublista
        NodoSubTime* linkendTimePlace(string, long int,TimeRegis*,Place*);
        void printSubTimePlace(string ,Place*);
        void extremeTemp(int,string,Place*);
        void monthlyRain(int,string,Place* );




        Place * next  = NULL;
        class NodoSubTime* timeRegiSublist = NULL;




    private:

        string name;
        int population;
        float squareMeters;

};



#endif // PLACE_H

