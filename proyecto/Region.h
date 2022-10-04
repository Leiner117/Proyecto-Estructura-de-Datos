#ifndef REGION_H
#define REGION_H
#include <string>
#include "Place.h"
using namespace std;


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
        //void dataLoadSublist(Region*);

        void MonthlyRain(int ,Region* );

        //Puntero
        Region * next = NULL;
        class NodoSubPlace* placeSublist = NULL;

    private:

        string idRegion;
        string name;
        string location;
};

class NodoSubPlace{ //sublista de lugares para una region
    public:
        NodoSubPlace* next = NULL;
        Place* linkPlace = NULL;
};

#endif // REGION_H


