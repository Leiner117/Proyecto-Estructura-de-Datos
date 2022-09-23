#ifndef REGION_H
#define REGION_H
#include <string>
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

        //Getters
        string getIdRegion();
        string getName();
        string getLocation();

        //Metodos
        bool validate(string,Region*);
        Region* add(string,string,string,Region*);
        Region* deleteRegion(string,Region*);
        Region* deleteAllRegion(Region*);
        Region* modify(string,string,string, string,Region*);
        Region* searchRegion(string,Region*);
        void print(Region*);
        Region* dataLoad(Region*);

        //Puntero
        Region * next;

    private:

        string idRegion;
        string name;
        string location;

};

#endif // REGION_H


