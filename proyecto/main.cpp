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

int main()
{


    string n;
    int p;
    float mc;

    cout<<"Agregue el nombre del lugar: ";
    getline(cin>>ws, n);
    cout<<"\nAgregue la poblacion del lugar: ";
    cin>>p;
    cout<<"\nAgregue los metros cuadrados del lugar: ";
    cin>>mc;

    placeList=placeList->add(n,p,mc,placeList);

    //placeList->dataLoad(placeList);
    //cout<<placeList;
    placeList->printPlaceList(placeList);




    //cout<<->getName();
    cout << "ESTO ES UNA PRUEBA!" << endl;

    return 0;
}
