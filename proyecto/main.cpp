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


Place* placeList;// Lista Lugares
Region* regionList;// Lista region
TimeRegis* timeList;// Lista registro del tiempo
Rain* rainList;// lista LLuvia
People* peopleList;// Lista Personas
Ephemerality* ephemeralityList;//Lista efimeridad


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


    cout << "ESTO ES UNA PRUEBA!" << endl;
    peopleList = peopleList->dataLoad(peopleList);
    People*persona = peopleList->searchPeople(peopleList,"2022437759");
    peopleList->printPeopleList(peopleList);
    ephemeralityList = ephemeralityList->dataload(ephemeralityList);
    ephemeralityList->printEphemeralityList(ephemeralityList);

    ephemeralityList->diffDepartureTime(2022,ephemeralityList);
    ephemeralityList->timeReportYear(ephemeralityList,2022);
    ephemeralityList->earlyDeparLateHide(ephemeralityList);
    //persona->setTimeSublist(timeList->add("2022/09/23",001,12.11,12.12,20,23,22,false,persona->getTimeSubList()));
    //persona->setTimeSublist(timeList->add("2022/09/24",001,0.11,14.12,20,23,22,true,persona->getTimeSubList()));
    //timeList->print(persona->getTimeSubList());

    return 0;
}
