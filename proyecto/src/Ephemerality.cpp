#include "Ephemerality.h"
#include <string>
#include <iostream>
/*
 Creado: 16/09/2022 ultima mod: 16/09/2022
 Autor: Leiner Alvarado
 */

using namespace std;
//Constructor
Ephemerality::Ephemerality(string n,string d,string departure,string hide)
{
    setName(n);
    setDate(d);
    setDepartureTime(departure);
    setHideTime(hide);
}

//Setters
void Ephemerality::setName(string n){
    name = n;
}
void Ephemerality::setDate(string d){
    date = d;
}
void Ephemerality::setDepartureTime(string time){
    departureTime = time;
}
void Ephemerality::setHideTime(string time){
    hideTime = time;

}

//Getters
string Ephemerality::getName(){
    return name;
}
string Ephemerality::getDate(){
    return date;
}
string Ephemerality::getDepartureTime(){
    return departureTime;
}
string Ephemerality::getHideTime(){
    return hideTime;
}

//Funciones

/*
Funcion agregar efimeridad
Agrega nodos efimeridad a la lista doble
*/
Ephemerality*Ephemerality::addEphemerality(string name,string date,string departureTime,string hideTime,Ephemerality*elist){
    Ephemerality*newEphemerality = new Ephemerality(name,date,departureTime,hideTime);

    newEphemerality-> next = elist;
    if(elist!= NULL){
        elist->pre = newEphemerality;
    }
    elist = newEphemerality;
    return elist;
}

/*
Funcion buscar efimeridad
Retorna el nodo de efimeridad solicitado
*/

Ephemerality*Ephemerality::searchEphemerality(string name,Ephemerality*eList){
    if(eList == NULL){
        cout<< "\nlista Vacia...\n";
        return NULL;
    }
    Ephemerality*temp = eList;
    while(temp != NULL){
        if(temp->getName() == name){

            return temp;
        }
        temp = temp->next;
    }
    cout<< "\nNo encontrado en la lista doble";
    return NULL;
}

/*
Funcion borrar efimeridad
Borra de la lista doble el nodo solicitado
*/
Ephemerality*Ephemerality::deleteEphemerality(string name,Ephemerality*eList){

    Ephemerality*dEphemerality = searchEphemerality(name,eList);
    if(dEphemerality == NULL){
        cout<< "\n No se puede borrar \n";
        return eList;
    }
    else{
        if(dEphemerality == eList){
            eList = eList->next;
            if(eList != NULL){
                eList->pre = NULL;
            }
        }
        else{
            dEphemerality->pre->next = dEphemerality->next;
            if(dEphemerality->next != NULL){
                dEphemerality->next->pre = dEphemerality->pre;
                }
            }

    }
    cout<< "\n Se puede borrar \n";
    return eList;
}




