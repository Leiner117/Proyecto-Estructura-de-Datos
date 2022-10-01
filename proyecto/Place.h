#ifndef PLACE_H
#define PLACE_H
#include <string>
#include "TimeRegis.h"
#include "People.h"

using namespace std;


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
        bool validate(string,Place*);
        Place* add(string,int,float,Place*);
        Place* modify(string,string,int,float,Place*);
        Place* deletePlace(string,Place*);
        Place* deleteAllPlace(Place*);
        Place* searchPlace(string, Place*);
        void print(Place*);
        void askData();
        Place* dataLoad(Place*);
        void extremeRainMonth(TimeRegis *, int, string ,Place*);


        //Metodos de sublista
        NodoSubTime* linkendTimePlace(string, long int,TimeRegis*,Place*);
        void printSubTimePlace(string ,Place*);

        //NodoSubTime* linkendTimePeople(string,string,TimeRegis*,People*);
        //void printSublistTime(string,People*);


        //Puntero
        Place * next  = NULL;
        class NodoSubTime* timeRegiSublist = NULL;
        //class NodoTimeRegis* TimeRegiSublist;

    private:

        string name;
        int population;
        float squareMeters;
        //TimeRegis* timeRegSublist; //Sublista de registro del tiempo
};

/*
class NodoTimeRegis{
    public:
        NodoTimeRegis* next;
        TimeRegis* linkTimeRegis;
};*/




#endif // PLACE_H

