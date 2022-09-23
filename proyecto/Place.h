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
        bool validate(string,Place*);
        Place* add(string,int,float,Place*);
        Place* modify(string,string,int,float,Place*);
        Place* deletePlace(string,Place*);
        Place* deleteAllPlace(Place*);
        Place* searchPlace(string, Place*);
        void print(Place*);
        void askData();
        Place* dataLoad(Place*);

        //Puntero
        Place * next;

    private:

        string name;
        int population;
        float squareMeters;
};


#endif // PLACE_H

