#include "Place.h"
#include <string>
#include <iostream>
using namespace std;






Place::Place(string n,int p,float meters){

    setName(n);
    setPopulation(p);
    setSquareMeters(meters);
}

//Place* placeList; //Lista de Lugares

//------------------- Metodos set-----------------------------------------
void Place::setName(string n){
    name=n;
}

void Place::setPopulation(int p){
    population= p;
}

void Place::setSquareMeters(float meters){
    squareMeters= meters;
}

//------------------- Metodos get-----------------------------------------
string Place::getName(){
    return name;
}

int Place::getPopulation(){
    return population;
}

float Place::getSquareMeters(){
    return squareMeters;
}




//************************** Funciones de la lista ******************

//Agregar al Inicio
Place* Place::add(string n,int p,float meters,Place* placeList){

    Place* newNodo = new Place(n,p,meters);
    //cout<<placeList;

    if(placeList == NULL){
        placeList = newNodo;
        newNodo->next = placeList;
    }
    else{

        placeList->next = placeList;

        //busca el ultimo para que apunte al nuevo nodo
        Place* ptr = placeList;

        while(ptr->next != placeList)
            ptr = ptr->next;

        ptr->next = newNodo;
        placeList = newNodo;
    }
    cout<<placeList<<endl;
    return placeList;

}

//Modificar
Place* Place::modify(string key,string n, int p,float meters, Place* placeList){

    if(placeList== NULL)
        cout<<"\nLa lista no tiene datos.....";
    else{
        Place*ptr = placeList;
        while (ptr != NULL){
            if(ptr->getName() == key){
                ptr->setName(n);
                ptr->setPopulation(p);
                ptr->setSquareMeters(meters);
                return placeList;//me salgo de la fucnion
            }
            ptr = ptr->next;
        }
        cout<<"\nNO se encontro el dato";
    }
}

Place* Place::deletePlace(string n, Place* placeList){
    if(placeList == NULL)
        cout<<"\nLista vacia, no se puede borrar....";
    else{
        if(placeList->getName() == n){//es el primero de la lista
            placeList= placeList->next;
        }
        else{//es en medio o al final
            Place* ptr = placeList;
            Place *ant = NULL;
            while((ptr!= NULL) && (ptr->getName()!=n)){
                ant = ptr;
                ptr = ptr->next;
            }
            if(ptr == NULL)
                cout<<"\nNo se encontro el nodo";
            else
                ant->next = ptr->next;
        }
    }

    //Place p+(p)
    return placeList;
}


//Cargar datos quemados
Place* Place::dataLoad(Place* placeList){

    placeList = add("San Carlos",163745,3347.98,placeList);
    placeList = add("Upala",43953,1.581,placeList);
    placeList = add("Naranjo",42713,126.6,placeList);

    /*placeList=add("Palmares",34716,38.06,placeList);
    placeList=add("Escazu",56509,	34.49 ,placeList);
    placeList=add("Los Chiles",23735,504.2,placeList);
    placeList=add("Grecia",13262,3221.6,placeList);
    placeList=add("Sarapiqui",57147,2140.54,placeList);
    placeList=add("Talamanca",30712,504.2,placeList);
    placeList=add("Guatuso",15508,1580.67,placeList);
    */
    cout<<placeList<<endl;
    cout<<"\n---Se cargaron los datos correctamente---\n";
    //cout<<placeList<<endl;
    return placeList;


    //cout<<placeList<<endl;

}

//Buscar
void searchPlace(string n, Place*placeList){
    if(placeList == NULL)
        cout<<"\nLa lista esta vacia....";
    else{
        Place*ptr = placeList;
        while(ptr != NULL){
            if(ptr->getName() == n){
                cout<<"\nNodo encontrado";
                return ;
            }
            ptr = ptr->next;
        }
        cout<<"\nNo se encontro el dato";
    }
    //return NULL;
}


//Imprime la lista de punteros
void Place::printPlaceList(Place* placeList){

    if(placeList == NULL)
        cout<<"\nLista circular vacia......\n";
    else{
        Place*ptr = placeList;
        cout<<ptr->getName();
        do{
            cout<<ptr->getName()<<" | "<<ptr->getPopulation()<<" | "<<ptr->getSquareMeters()<<endl;
            ptr = ptr->next;
            //cout<<ptr->getName();
            //cout<<ptr->next<<endl;
            //cout<<"hola"<<endl;
        }while(ptr!= placeList);

    }
}




