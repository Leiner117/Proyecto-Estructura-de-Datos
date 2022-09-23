#include <iostream>
#include <ctime>
#include "TimeRegis.h"
#include "Place.h"
#include "Region.h"



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

    cout<<->getName();
    cout << "ESTO ES UNA PRUEBA!" << endl;

    return 0;
}
