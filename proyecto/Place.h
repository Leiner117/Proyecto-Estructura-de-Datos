#ifndef PLACE_H
#define PLACE_H
#include <string>
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

        //Getters
        string getName();
        int getPopulation();
        float getSquareMeters();

        //Metodos
        Place* add(string,int,float,Place* );
        Place* deletePlace(string,Place* );
        Place* modify(string,string,int,float,Place* );
        void searchPlace(string,Place*);
        Place* dataLoad(Place* );
        void printPlaceList(Place*);

        //Puntero
        Place * next;

    private:

        string name;
        int population;
        float squareMeters;
};


#endif // PLACE_H

