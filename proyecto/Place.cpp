#include "Place.h"
#include <string>
#include <iostream>
using namespace std;


Place::Place(string n,int p,float meters){

    setName(n);
    setPopulation(p);
    setSquareMeters(meters);
    next= NULL;
}


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


//Verifica si el elemento a agregar ya existe en la lista
bool Place::validate(string n,Place* placeList){

    if(placeList == NULL)
        return false;
    else{
        if(placeList->getName() == n){//es el primero de la lista
            return true;
        }
        else{
            Place*temp = placeList;
            do{
                if (placeList->getName() != n)
                    temp= temp->next;
            } while(temp!= placeList);
            return false;
        }
    }
}

//Agregar al Inicio
Place* Place::add(string n,int p,float meters,Place* placeList){

    bool duplicate= validate(n,placeList);

    if(duplicate==false){

        Place* newNodo = new Place(n,p,meters);

        if(placeList == NULL){
            placeList = newNodo;
            newNodo->next = placeList;
        }
        else{

            newNodo->next =placeList;
            //buscar el ultimo para que apunte al nuevo nodo
            Place* temp = placeList;
            while(temp->next != placeList)
                temp = temp->next;

            temp->next = newNodo;
            placeList = newNodo;

        }
    }
    else{
        cout<<"\n+++ Advertencia: El nombre ingresado ya esta en la lista +++\n";
    }
    return placeList;
}

//Modificar
Place* Place::modify(string data, string n,int p, float m,Place*placeList){

    bool duplicate= validate(n,placeList);

     if(duplicate == false){
        if(placeList== NULL)
            cout<<"\nLa lista no tiene datos.....";
        else{
            Place*temp = placeList;
            while (temp != NULL){
                if(temp->getName() == data){
                    temp->setName(n);
                    temp->setPopulation(p);
                    temp->setSquareMeters(m);
                    cout<<"\nSe modifico correctamente";
                    return placeList;//me salgo de la fucnion
                }
                temp = temp->next;
            }
            cout<<"\nNO se encontro el dato.";
        }
    }
    else{
        cout<<"\n+++ Advertencia: El nombre ingresado ya existe en la lista +++\n";
    }
    return placeList;
}

//Borra UN ELEMENTO de la lista
Place* deletePlace(string n,Place* placeList){
    if(placeList == NULL)
        cout<<"\nLista vacia, no se puede borrar....";
    else{
        if(placeList->getName() == n){//es el primero de la lista
            placeList= placeList->next;
        }
        else{
            Place* current = placeList;
            Place *temp = NULL;
            while((current!= NULL) && (current->getName()!=n)){
                temp = current;
                current = current->next;
            }
            if(current == NULL)
                cout<<"\nNo se encontro el nodo";
            else
                temp->next = current->next;
        }
    }
    return placeList;
}

//Borra toda la lista
Place* deleteAllPlace(Place* placeList) {
    if(placeList != NULL) {
        Place *temp, *current;
        current = placeList->next;
        while(current != placeList) {
            temp = current->next;
            free(current);
            current = temp;
        }
        free(placeList);
        placeList = NULL;
    }
    cout<<"Todos los nodos han sido eliminados correctamente.\n";
    return placeList;
}


//Buscar Nodo Place
Place* searchPlace(string n, Place* placeList){
    if(placeList == NULL)
        cout<<"\nLa lista esta vacia....";
    else{
        Place*temp = placeList;
        while(temp != NULL){
            if(temp->getName() == n){
                cout<<"\nNodo encontrado";
                return temp;
            }
            temp = temp->next;
        }
        cout<<"\nNo se encontro el dato";
    }
    return NULL;
}

//Imprime la lista completa
void Place:: print(Place* placeList){

    if(placeList== NULL)
        cout<<"\nLista circular vacia......\n";
    else{
        Place*temp = placeList;
        do{
            cout<<temp->getName()<<" | "<<temp->getPopulation()<<" | "<<temp->getSquareMeters()<<endl;
            temp= temp->next;
        } while(temp!= placeList);

    }
}

//Se reciben datos de entrada
void Place::askData(){

    string n;
    int p;
    float mc;

    cout<<"\nIngrese el nombre del lugar: ";
    getline(cin>>ws, n);
    cout<<"\nIngrese la poblacion total del lugar: ";
    cin>>p;
    cout<<"\nIngrese los metros cuadrados del lugar: ";
    cin>>mc;

 }

//Cargar datos quemados
Place* Place::dataLoad(Place* placeList){

    //Datos preestablecidos en lista lugar
    placeList=add("San Carlos",163745,3347.98,placeList);
    placeList=add("Upala",43953,1.581,placeList);
    placeList=add("Naranjo",42713,126.6,placeList);
    placeList=add("Naranjo",4548,23265.6,placeList);
    placeList=add("Palmares",34716,38.06,placeList);
    placeList=add("Escazu",56509,34.49,placeList);
    placeList=add("Los Chiles",23735,504.2,placeList);
    placeList=add("Grecia",13262,3221.6,placeList);
    placeList=add("Sarapiqui",57147,2140.54,placeList);
    placeList=add("Talamanca",30712,504.2,placeList);
    placeList=add("Guatuso",15508,1580.67,placeList);

    cout<<"\n---Se cargaron los datos correctamente---\n";

    return placeList;

}






