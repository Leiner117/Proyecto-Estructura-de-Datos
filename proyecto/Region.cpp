#include "Region.h"
#include <string>
#include <iostream>
using namespace std;

Region::Region(string id,string n, string l){

    setIdRegion(id);
    setName(n);
    setLocacion(l);
    next=NULL;
}

Region* regionList;

//------------------- Metodos set-----------------------------------------
void Region::setIdRegion(string id){
   idRegion = id;
}

void Region::setName(string n){
    name= n;
}

void Region::setLocacion(string l){
    location= l;
}

//------------------- Metodos get-----------------------------------------
string Region::getIdRegion(){
    return idRegion;
}

string Region::getName(){
    return name;
}

string Region::getLocation(){
    return location;
}


//************************** Funciones de la lista ******************

//Agregar al Inicio
void Region::add(string id,string n,string l){

    Region* newNodo = new Region(id,n,l);

    if(regionList == NULL){
        regionList = newNodo;
        newNodo->next = regionList;
    }
    else{
        regionList->next = regionList;

        //busca el ultimo para que apunte al nuevo nodo
        Region* ptr = regionList;
        while(ptr->next != regionList)
            ptr = ptr->next;

        ptr->next = newNodo;
        regionList = newNodo;
    }
}

void Region::modify(string key,string id,string n,string l, Region* regionList){

    if(regionList== NULL)
        cout<<"\nLa lista no tiene datos.....";
    else{
        Region*ptr = regionList;
        while (ptr != NULL){
            if(ptr->getIdRegion() == key){
                ptr->setIdRegion(id);
                ptr->setName(n);
                ptr->setLocacion(l);
                return;//me salgo de la fucnion
            }
            ptr = ptr->next;
        }
        cout<<"\nNO se encontro el dato.";
    }
}

void Region::deleteRegion(string key, Region* regionList){
    if(regionList == NULL)
        cout<<"\nLista vacia, no se puede borrar....";
    else{
        if(regionList->getIdRegion() == key){//es el primero de la lista
            regionList= regionList->next;
        }
        else{//es en medio o al final
            Region* ptr = regionList;
            Region*ant = NULL;
            while((ptr!= NULL) && (ptr->getIdRegion()!=key)){
                ant = ptr;
                ptr = ptr->next;
            }
            if(ptr == NULL)
                cout<<"\nNo se encontro el nodo";
            else
                ant->next = ptr->next;
        }
    }

    //Region p+(p)
    //return regionList;
}

Region* searchRegion(string id, Region*regionList){
    if(regionList == NULL)
        cout<<"\nLa lista esta vacia....";
    else{
        Region*ptr = regionList;
        while(ptr != NULL){
            if(ptr->getIdRegion() == id){
                cout<<"\nNodo encontrado";
                return ptr;
            }
            ptr = ptr->next;
        }
        cout<<"\nNo se encontro el dato";
    }
    return NULL;
}


//Cargar datos quemados
void Region::dataLoad(){

    add("C","Caribe","Limon");
    add("C","Pacifico Central","Puntarenas");
    add("C","Talamanca","Limon");
    add("C","Upala y los Chiles","Alajuela");
    add("C","Valle Central","San Jose");
    add("C","Peninsula de Nicoya","Guanacaste");
    add("C","Pacifico Sur","Puntarenas");
    add("C","Norte Alta","Alajuela");
    add("C","Cordillera de Guanacaste y Tilaran","Guanacaste");
    add("C","Caribe Sur","Limon");

}


//Imprime la lista de punteros
void Region::displayRegionList(){

        if(regionList== NULL)
            cout<<"\nLista simple vacia......\n";
        else{
            Region*ptr = regionList;
            do{
                cout<<ptr->getIdRegion()<<" | "<<ptr->getName()<<" | "<<ptr->getLocation()<<endl;
                ptr= ptr->next;
            } while(ptr!= regionList);

        }
}

