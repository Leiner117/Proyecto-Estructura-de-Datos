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

    if (searchEphemerality(name,elist)==NULL){


        Ephemerality*newEphemerality = new Ephemerality(name,date,departureTime,hideTime);

        newEphemerality-> next = elist;
        if(elist!= NULL){
            elist->pre = newEphemerality;
        }
        elist = newEphemerality;
    }
    else{
        cout<< "La efimeridad ya estaba registrada";
    }
    return elist;
}

/*
Funcion buscar efimeridad
Retorna el nodo de efimeridad solicitado
*/

Ephemerality*Ephemerality::searchEphemerality(string date,Ephemerality*eList){
    if(eList == NULL){
        cout<< "\nlista Vacia...\n";
        return NULL;
    }
    Ephemerality*temp = eList;
    while(temp != NULL){
        if(temp->getDate() == date){

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
Ephemerality*Ephemerality::deleteEphemerality(string date,Ephemerality*eList){

    Ephemerality*dEphemerality = searchEphemerality(date,eList);
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
/*
Funcion modificar nombre
Se encarga de modificar el nombre de la efimeridad
*/
void Ephemerality::modName(Ephemerality*eList,string date,string newName){
    if (searchEphemerality(newName,eList) == NULL){

       Ephemerality*ephemerality = searchEphemerality(date,eList);
       ephemerality->setName(newName);
    }
}
/*
Funcion modificar fecha
Se encarga de modificar la fecha de la efimeridad
*/
void Ephemerality::modDate(Ephemerality*eList,string date,string newDate){

    Ephemerality*ephemerality = searchEphemerality(date,eList);
    ephemerality->setDate(newDate);
}

/*
Funcion modificar hora de ocultamiento
Se encarga de modificar la hora de ocultamiento de la efimeridad
*/

void Ephemerality::modHideTime(Ephemerality*eList,string date,string newHideTime){
    Ephemerality*ephemerality = searchEphemerality(date,eList);
    ephemerality->setHideTime(newHideTime);
}


/*
Funcion modificar hora de salida
Se encarga de modificar la hora de salida de la efimeridad
*/

void Ephemerality::modDepartureTime(Ephemerality*eList,string date,string newDepartureTime){
    Ephemerality*ephemerality = searchEphemerality(date,eList);
    ephemerality->setDepartureTime(newDepartureTime);

}

//Cargar datos quemados
Ephemerality* Ephemerality::dataLoad(Ephemerality* ephemeralityList){

    //Datos preestablecidos en lista lugar
    ephemeralityList=addEphemerality("Sol","15/09/2022","5:54","16:00",ephemeralityList);
    ephemeralityList=addEphemerality("Sol","15/09/2022","5:17","16:39",ephemeralityList);
    ephemeralityList=addEphemerality("Sol","17/09/2022","5:56","17:17",ephemeralityList);
    ephemeralityList=addEphemerality("Sol","18/09/2022","6:00","16:11",ephemeralityList);
    ephemeralityList=addEphemerality("Sol","19/09/2022","5:59","15:32",ephemeralityList);
    ephemeralityList=addEphemerality("Sol","20/09/2022","4:24","16:10",ephemeralityList);
    ephemeralityList=addEphemerality("Sol","21/09/2022","5:21","17:00",ephemeralityList);
    ephemeralityList=addEphemerality("Sol","22/09/2022","5:30","16:15",ephemeralityList);
    ephemeralityList=addEphemerality("Sol","23/09/2022","6:01","15:22",ephemeralityList);
    ephemeralityList=addEphemerality("Sol","24/09/2022","4:54","16:27",ephemeralityList);



    cout<<"\n---Se cargaron los datos correctamente---\n";


    return ephemeralityList;

}



