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
Rain*Rain::addRain(Rain*newRain,Rain*oldRain){
    newRain->next = oldRain;
    oldRain = newRain;
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
void Rain::modRainCode(Rain*rain,string newRainCode){
    rain->setRainCode(newRainCode);

}



