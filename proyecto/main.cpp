#include <iostream>
#include <ctime>
#include "TimeRegis.h"
#include "Place.h"
#include "Region.h"
#include "Ephemerality.h"
#include "People.h"
#include "Rain.h"




/*
    Autor: Karina Urbina
    Iniciado: 12/09/2022
    Avance1: 16/09/2022
    Ultima modificacion:

*/



using namespace std;


Place* placeList;
Region* regionList;
TimeRegis* timeList;
Rain* rainList;
People* peopleList;
Ephemerality* ephemeralityList;

int main()
{
    cout << "-------LISTA LUGARES--------" << endl;
    placeList=placeList->dataLoad(placeList);
    placeList->print(placeList);

    cout << "\n-------LISTA REGION--------" << endl;
    regionList=regionList->dataLoad(regionList);
    regionList->print(regionList);
    cout << "\n------------------------------" << endl;
    regionList= regionList->modify("C","T","Tamarindo","LIMONADA",regionList);
    regionList->print(regionList);

    cout << "\n-------LISTA TIEMPO--------" << endl;
    timeList=timeList->dataLoad(timeList);
    timeList->print(timeList);


    cout << "ESTO ES UNA PRUEBA!" << endl;

    return 0;
}
