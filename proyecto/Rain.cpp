#include "Rain.h"
#include <string>
#include <iostream>

/*
 Creado: 16/09/2022 ultima mod: 16/09/2022
 Autor: Leiner Alvarado
 */

using namespace std;



//Constructor

Rain::Rain(string rainCode, string name,int averageRange)
{
    setRainCode(rainCode);
    setName(name);
    setAverageRange(averageRange);
}

//Setters
void Rain::setRainCode(string code){
    rainCode = code;
}
void Rain::setName(string n){

    name = n;
}

void Rain::setAverageRange(int average){
    averageRange = average;
}

//Getters

string Rain::getRainCode(){
    return rainCode;
}

string Rain::getName(){
    return name;

}
int Rain::getAverageRange(){

    return averageRange;
}


//Funciones


/*
Funcion agregar lluvia
Se encarga de relacionar los nodos lluvia en una lista simple
*/

Rain*Rain::addRain(string code,string n,int average,Rain*oldRain){
    if (searchRain(oldRain,code)== NULL){
        Rain*newRain = new Rain(code,n,average);
        newRain->next = oldRain;
        oldRain = newRain;
    }
    else{
        cout<< "La lluvia ya existe";
    }
    return oldRain;

}

/*
Funcion Imprimir lista de Lluvia
*/
void Rain::printRainList(Rain*r){

    Rain*temp =r;
    cout<< "Lista de Lluvia"<<endl;
    cout<<"*******************************"<<endl;
    while(temp != NULL){

        cout<<temp->getRainCode()<<endl;
        cout<<temp->getName()<<endl;
        cout<<temp->getAverageRange()<<endl;
        cout<<"*******************************"<<endl;
        temp = temp->next;

    }

}

/*

Funcion buscar nodo lluvia
Se encarga de recorrer la lista de punteros y retornar el nodo buscado
*/
Rain*Rain::searchRain(Rain*rainList,string code){
    Rain*temp =rainList;
    while(temp != NULL){

        if (temp->getRainCode()==code){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


/*
Funcion borrar lluvia
Se encarga de borrar el nodo lluvia seleccionado
*/
void Rain::deleteRain(Rain*rList,string code){
        if(rList == NULL){
        cout<<"\nLista vacia...";

    }else{
        if(rList->rainCode ==code){

            rList = rList->next;
        }else{
            Rain* temp = rList;
            Rain* previ = NULL;
            while((temp!=NULL) && (temp->rainCode!=code)){
                previ = temp;
                temp = temp->next;
            }
            if(temp == NULL){
                cout<<"\nNo se encontro el nodo";
            }else{
                previ->next = temp ->next;
            }
        }
    }
}
void Rain::modName(Rain*rainList,string newName,string rainCode){
    Rain*rain = searchRain(rainList,rainCode);
    rain->setName(newName);
}

void Rain::modRainCode(Rain*rainList,string newRainCode,string rainCode){

    if (searchRain(rainList,newRainCode)== NULL){
        Rain*rain = searchRain(rainList,rainCode);
        rain->setRainCode(newRainCode);
    }
    else{
        cout<< "El codigo ya existe";
    }

}
void Rain::modAverageRange(Rain*rainList,int newAverage,string rainCode){
    Rain*rain = searchRain(rainList,rainCode);
    rain->setAverageRange(newAverage);
}




