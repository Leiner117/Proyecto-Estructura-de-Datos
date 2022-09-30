#include "People.h"
#include "TimeRegis.h"
#include <string>
#include <iostream>

/*
 Creado: 16/09/2022 ultima mod: 19/09/2022
 Autor: Leiner Alvarado
 */

using namespace std;

//Constructor
People::People(string n,string id,short age,string place,string year)
{
    setName(n);
    setId(id);
    setAge(age);
    setPlaceResidence(place);
    setYearIncome(year);
    next=NULL;
    timeSublist=NULL;

}
//Setters
void People::setName(string n){
    name = n;
}

void People::setId(string i){
    id = i;
}
void People::setAge(short ag){
    age = ag;
}
void People::setPlaceResidence(string place){
    placeResidence = place;
}
void People::setYearIncome(string year){

    yearIncome = year;
}

//Getters

string People::getId(){
    return id;
}
string People::getName(){
    return name;
}

short People::getAge(){
    return age;
}
string People::getPlaceResidence(){
    return placeResidence;
}

string People::getYearIncome(){
    return yearIncome;
}

// Funciones

/*
Funcion agregar personas
Se encarga de agregar nodos personas a la lista doble
*/
People*People::addPeople(string name,string id,short age,string place,string year,People*peopleList){

    if (searchPeople(peopleList,id)==NULL){


        People*newPeople = new People(name,id,age,place,year);

        newPeople-> next = peopleList;
        if(peopleList!= NULL){
            peopleList->pre = newPeople;
        }
        peopleList = newPeople;
    }
    else{
        cout<< "La persona ya existe";
    }
    return peopleList;
}

/*
Funcion imprimir lista personas
Recorre la lista y imprime la informacion de cada personas
*/

void People::printPeopleList(People*pList){


    if(pList == NULL){
        cout<< "\nLista Doble vacia..\n";

    }
    else{
        People*temp = pList;
        cout<< "Lista de Personas"<<endl;
        cout<<"*******************************"<<endl;
        while(temp != NULL){
            cout<<temp->getName()<<endl;
            cout<<temp->getId()<<endl;
            cout<<temp->getPlaceResidence()<<endl;
            cout<<temp->getYearIncome()<<endl;
            cout<<"*******************************"<<endl;
            temp = temp->next;
        }


    }
}

/*
Funcion buscar personas
Recorre la lista y compara el id de cada nodo, cuando encuentra en buscado lo retorna
*/
People*People::searchPeople(People*pList,string id){

    if(pList == NULL){
        cout<< "\nlista Vacia...\n";
        return NULL;
    }
    People*temp = pList;
    while(temp != NULL){
        if(temp->getId() == id){

            return temp;
        }
        temp = temp->next;
    }
    cout<< "\nNo encontrado en la lista doble";
    return NULL;
}

/*
Funcion borrar persona
Se encarga de de borrar el nodo persona seleccionado
*/
People*People::deletePeople(People*pList,string id){

    People*dPeople = searchPeople(pList,id);
    if(dPeople == NULL){
        cout<< "\n No se puede borrar \n";
        return pList;
    }
    else{
        if(dPeople == pList){
            pList = pList->next;
            if(pList != NULL){
                pList->pre = NULL;
            }
        }
        else{
            dPeople->pre->next = dPeople->next;
            if(dPeople->next != NULL){
                dPeople->next->pre = dPeople->pre;
                }
            }

    }
    cout<< "\n Se puede borrar \n";
    return pList;
}
/*
Funcion modificar nombre
Busca el nodo persona solicitado y modifica el atributo nombre
*/
void People::modName(string id,string newName,People*pList){
    People*people = searchPeople(pList,id);
    people->setName(newName);
}
/*
Funcion modificar ID
Busca el nodo persona solicitado y modifica el atributo id
*/
void People::modId(string id,string newId,People*pList){
    People*people = searchPeople(pList,id);
    people->setId(newId);
}
/*
Funcion modificar edad
Busca el nodo persona solicitado y modifica el atributo edad
*/
void People::modAge(string id,short newAge,People*pList){
    People*people = searchPeople(pList,id);
    people->setAge(newAge);
}
/*
Funcion modificar lugar de residencia
Busca el nodo persona solicitado y modifica el atributo lugar de residencia
*/
void People::modPlaceResidence(string id,string newPlace,People*pList){
    People*people = searchPeople(pList,id);
    people->setPlaceResidence(newPlace);
}
/*
Funcion modificar ano de ingreso
Busca el nodo persona solicitado y modifica el atributo ano de ingreso
*/
void People::modYearIncome(string id,string newYear,People*pList){
    People*people = searchPeople(pList,id);
    people->setYearIncome(newYear);
}

//Cargar datos quemados
People* People::dataLoad(People* peopleList){

    //Datos preestablecidos en lista lugar
    peopleList=addPeople("Ernesto","202201",15,"Upala","2020",peopleList);
    peopleList=addPeople("Maria","202202",17,"La Tigra","2012",peopleList);
    peopleList=addPeople("Adrian","202203",23,"Santa Clara","2010",peopleList);
    peopleList=addPeople("Leiner","202204",20,"Bajo Rodriguez","2022",peopleList);
    peopleList=addPeople("Sara","202205",39,"Ciudad Quesada","2021",peopleList);
    peopleList=addPeople("Tommy","202206",57,"Los Chiles","2019",peopleList);
    peopleList=addPeople("Karina","202207",18,"Los Angeles","2022",peopleList);
    peopleList=addPeople("Alex","202208",25,"Moravia","2013",peopleList);
    peopleList=addPeople("Rose","202209",41,"Coronado","2015",peopleList);
    peopleList=addPeople("Ana","2022010",70,"San Miguel","2004",peopleList);

    cout<<"\n---Se cargaron los datos correctamente---\n";

    return peopleList;

}



//---------------------------------SUBLISTA DE LUGARES----------------------------

NodoSubTime* People::linkendTimePeople(string idPerson, string dateR,TimeRegis* timeList,People* peopleList){

    People* pers = pers->searchPeople(peopleList,id);
    TimeRegis* timeR = timeR->searchTime(dateR,timeList);

    if(pers == NULL){
        cout<<"\nNo existe la persona";
        return NULL;
    }
    if(timeR == NULL){
        cout<<"\nNo hay registro en esa fecha";
        return NULL ;
    }
    NodoSubTime* newNodo = new NodoSubTime();
    newNodo->linkTime = timeR;// se enlaza con el curso
    newNodo->next = pers->timeSublist;
    pers->timeSublist = newNodo;

    return pers->timeSublist;
}


void People::printSublistTime(string id,People* peopleList){
    People * pers =pers->searchPeople(peopleList,id);
    if(pers == NULL){
        cout<<"\nNo existe la persona";
        return;
    }
    //Grafica de  los resultados a imprimir
    system("cls");
    cout<<"\n\t   =========================================\n";
    cout<<"\t   ||   Tiempos registrados por "<<pers->getName()<<"   ||\n";
    cout<<"\t   =========================================\n";

    NodoSubTime* temSub = pers->timeSublist;
    do{
        cout<<"\n\t________________________________________________\n";
        cout<<"\n\tFECHA: "<<temSub->linkTime->getDateR();
        cout<<"\n\tPRECIPITACION: "<<temSub->linkTime->getPrecip();
        cout<<"\n\tTEMPERATURA MINIMA: "<<temSub->linkTime->getMinTemp();
        cout<<"\n\tTEMPERATURA MAXIMA: "<<temSub->linkTime->getMaxTemp();
        cout<<"\n\tDIRECCION DEL VIENTO: "<<temSub->linkTime->getWinDirec();
        cout<<"\n\tVELOCIDAD DEL VIENTO: "<<temSub->linkTime->getWinPsd();
        cout<<"\n\tHUMEDAD: "<<temSub->linkTime->getHumidity();
        cout<<"\n\LLUVIA: "<<temSub->linkTime->getRained();

        temSub = temSub->next;

    }while(temSub != NULL);
    cout<<"\n\t________________________________________________\n";

}





