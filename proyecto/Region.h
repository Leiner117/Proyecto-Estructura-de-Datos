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
        void add(string,string,string);
        void deleteRegion(string,Region* regionList);
        void modify(string,string,string,string,Region* regionList);
        Region* searchRegion(string,Region* regionList);
        void dataLoad();
        void displayRegionList();

        //Puntero
        Region * next;

    private:

        string idRegion;
        string name;
        string location;

};

#endif // REGION_H


