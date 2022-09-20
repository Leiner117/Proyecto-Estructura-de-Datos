#include "People.h"
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

    People*newPeople = new People(name,id,age,place,year);

    newPeople-> next = peopleList;
    if(peopleList!= NULL){
        peopleList->pre = newPeople;
    }
    peopleList = newPeople;
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



