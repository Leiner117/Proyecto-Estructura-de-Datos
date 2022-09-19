#include "TimeRegis.h"
#include <string>
#include <iostream>
using namespace std;

//Aqui se implementan los metodos y se utilizan las variables del archivo .h

//Constructor con paramentros
TimeRegis::TimeRegis(string dateR,int precip,float maxTemp, float minTemp,int winSpd, int windDirec,int humidity,bool rained){

    setDateR(dateR);
    setPrecip(precip);
    setMaxTemp(maxTemp);
    setMinTemp(minTemp);
    setWinDirec(windDirec);
    setWinPsd(winSpd);
    setHumidity(humidity);
    setRained( rained);

    next=NULL;
}

TimeRegis* regisList;

//------------------- Metodos set-----------------------------------------
void TimeRegis::setDateR(string dateR){

    registrationDate=dateR;
}

void TimeRegis::setPrecip(int precip){

    precipitation=precip;
}

void TimeRegis::setMaxTemp(float maxTemp){

    maxTemperature=maxTemp;
}

void TimeRegis::setMinTemp(float minTemp){

    minTemperature=minTemp;
}

void TimeRegis::setWinPsd(int winSpd){

    windSpeed=winSpd;
}

void TimeRegis::setWinDirec(int winDirec){

    windDirection=winDirec;
}

void TimeRegis::setHumidity(int humidity){

    humidity= humidity;
}

void TimeRegis::setRained(bool rained){

    yesRained=rained;
}

//------------------- Metodos get-----------------------------------------
string TimeRegis::getDateR(){
    return registrationDate;
}

int TimeRegis::getPrecip(){
    return precipitation;
}

float TimeRegis::getMaxTemp(){
    return maxTemperature;
}


float TimeRegis::getMinTemp(){
    return minTemperature;
}

int TimeRegis::getWinPsd(){
    return windDirection;
}

int TimeRegis::getWinDirec(){
    return windDirection ;
}

int TimeRegis::getHumidity(){
    return humidity;
}

bool TimeRegis::getRained(){
    return yesRained;
}



//************************** Funciones de la lista ******************

//Agregar al Inicio
void TimeRegis::add(string dateR,int precip,float maxTemp,float minTemp,int winSpd, int windDirec,int humidity,bool rained){

    TimeRegis* newNodo = new TimeRegis(dateR,precip,maxTemp,minTemp,winSpd,windDirec,humidity,rained);

    if(regisList == NULL){
        regisList = newNodo;
        newNodo->next = regisList;
    }
    else{
        regisList->next = regisList;

        //busca el ultimo para que apunte al nuevo nodo
        TimeRegis* ptr = regisList;
        while(ptr->next != regisList)
            ptr = ptr->next;

        ptr->next = newNodo;
        regisList = newNodo;
    }
}

void TimeRegis::modify(string key,string dateR,int precip,float maxTemp, float minTemp,int winSpd, int windDirec,int humidity,bool rained, TimeRegis* regisList){

    if(regisList== NULL)
        cout<<"\nLa lista no tiene datos.....";
    else{
        TimeRegis*ptr = regisList;
        while (ptr != NULL){
            if(ptr->getDateR() == key){
                ptr->setDateR(dateR);
                ptr->setPrecip(precip);
                ptr->setMaxTemp(maxTemp);
                ptr->setMinTemp(minTemp);
                ptr->setWinDirec(windDirec);
                ptr->setWinPsd(windSpeed);
                ptr->setHumidity(humidity);
                ptr->setRained(rained);
                return;//me salgo de la fucnion
            }
            ptr = ptr->next;
        }
        cout<<"\nNO se encontro el dato.";
    }
}

TimeRegis*TimeRegis::deleteRegis(string key, TimeRegis* regisList){
    if(regisList == NULL)
        cout<<"\nLista vacia, no se puede borrar....";
    else{
        if(regisList->getDateR() == key){//es el primero de la lista
            regisList= regisList->next;
        }
        else{//es en medio o al final
            TimeRegis* ptr = regisList;
            TimeRegis* ant = NULL;
            while((ptr!= NULL) && (ptr->getDateR()!=key)){
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
    return regisList;
}


//Cargar datos quemados
void TimeRegis::dataLoad(){

    add("01/09/2022",1245,21.4,10.4,24,89,25,true);
    add("02/09/2022",5345,25.0,11.4,29,73,26,false);
    add("03/09/2022",5571,15.9,5.6,31,69,29,true);
    add("04/09/2022",5486,12.4,6.9,6,83,21,true);
    add("05/09/2022",4911,8.8,3.8,34,70,20,false);
    add("06/09/2022",2688,17.3,11.0,27,93,19,true);
    add("07/09/2022",9875,31.5,15.3,19,60,34,false);
    add("08/09/2022",1135,20.1,14.1,13,80,2,false);
    add("09/09/2022",887,27.0,12.9,28,25,36,false);
    add("10/09/2022",235,23.3,16.5,25,60,32,true);

}



TimeRegis* searchRegis(string dateR, TimeRegis* regisList){
    if(regisList == NULL)
        cout<<"\nLa lista esta vacia....";
    else{
        TimeRegis* ptr = regisList;
        while(ptr!= NULL){
            if(ptr->getDateR()== dateR){
                cout<<"\nNodo encontrado";
                return ptr;
            }
            ptr = ptr->next;
        }
        cout<<"\nNo se encontro el dato";
    }
    return NULL;
}

//Imprime la lista de punteros
void TimeRegis::displayTimeRegis(TimeRegis* regisList){

        if(regisList== NULL)
            cout<<"\nLista simple vacia......\n";
        else{
            TimeRegis*ptr = regisList;
            do{
                cout<<ptr->getDateR()<<" | "<<ptr->getPrecip()<<" | "<<ptr->getMaxTemp()<<" | "<<ptr->getMinTemp()<<endl;
                cout<<ptr->getWinDirec()<<" | "<<ptr->getWinPsd()<<" | "<<ptr->getHumidity()<<" | "<<ptr->getRained()<<endl;
                cout<<"\n";
                ptr= ptr->next;
            } while(ptr!= regisList);

        }
}


