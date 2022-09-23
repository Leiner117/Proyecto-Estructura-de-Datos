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


//Verifica si el elemento a agregar ya existe en la lista
bool TimeRegis::validate(string date, TimeRegis* timeList){
    if(timeList == NULL)
        return false;
    else{
        TimeRegis*temp = timeList;
        while(temp != NULL){
            if(temp->getDateR() == date){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
}

//Agregar al Inicio
TimeRegis* TimeRegis::add(string dateR,int precip,float maxTemp,float minTemp,int winSpd, int winDirec,int humidity,bool rained, TimeRegis* timeList){

    bool duplicate=validate(dateR,timeList);
    if(duplicate == false){

        TimeRegis* newNodo = new TimeRegis(dateR,precip,maxTemp,minTemp,winSpd,winDirec,humidity,rained);
        newNodo->next = timeList;//se enlaza, conoce la direccion el inicio de la lista
        timeList = newNodo;
    }
    else
        cout<<"\n+++ Advertencia: El nombre ingresado ya esta en la lista +++\n";

    return timeList;

}

TimeRegis* TimeRegis::modify(string date,string dateR,int precip,float maxTemp, float minTemp,int winSpd, int windDirec,int humidity,bool rained, TimeRegis* timeList){

    bool duplicate=validate(dateR,timeList);
    if(duplicate == false){
        if(timeList== NULL)
            cout<<"\nLa lista no tiene datos.....";
        else{
            TimeRegis*temp = timeList;
            while (temp != NULL){
                if(temp->getDateR() == date){
                    temp->setDateR(dateR);
                    temp->setPrecip(precip);
                    temp->setMaxTemp(maxTemp);
                    temp->setMinTemp(minTemp);
                    temp->setWinDirec(windDirec);
                    temp->setWinPsd(winSpd);
                    temp->setHumidity(humidity);
                    temp->setRained(rained);

                    cout<<"\nSe modifico correctamente";
                    return timeList;//me salgo de la fucnion
                }
                temp = temp->next;
            }
            cout<<"\nNO se encontro el dato.";
        }
    }
    else{
        cout<<"\n+++ Advertencia: El nombre ingresado ya existe en la lista +++\n";
    }
    return timeList;
}

TimeRegis*TimeRegis::deleteTime(string date, TimeRegis* timeList){
    if(timeList == NULL)
        cout<<"\nLista vacia, no se puede borrar....";
    else{
        if(timeList->getDateR() == date){//es el primero de la lista
            timeList= timeList->next;
        }
        else{
            TimeRegis* current = timeList;
            TimeRegis* temp = NULL;
            while((current!= NULL) && (current->getDateR()!=date)){
                temp = current;
                current = current->next;
                cout<<"\nSe borro correctamente";
            }
            if(current == NULL)
                cout<<"\nNo se encontro el nodo";
            else
                temp->next = current->next;
        }
    }
    return timeList;
}

//Borra toda la lista
TimeRegis* TimeRegis::deleteAllTime(TimeRegis* timeList) {
    if(timeList != NULL) {
        TimeRegis *temp, *current;
        current = timeList->next;
        while(current != timeList) {
            temp = current->next;
            free(current);
            current = temp;
        }
        free(timeList);
        timeList = NULL;
    }
    cout<<"All nodes are deleted successfully.\n";
    return timeList;
}


TimeRegis* TimeRegis::searchTime(string date, TimeRegis* timeList){
    if(timeList == NULL)
        cout<<"\nLa lista esta vacia....";
    else{
        TimeRegis*temp = timeList;
        while(temp != NULL){
            if(temp->getDateR() == date){
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
void TimeRegis:: print(TimeRegis* timeList){

    if(timeList == NULL)
        cout<<"\nLa lista esta vacia ...........\n";
    else{
        TimeRegis*temp = timeList;
        while(temp != NULL){
            cout<<temp->getDateR()<<" | "<<temp->getPrecip()<<" | "<<temp->getMaxTemp()<<" | "<<temp->getMinTemp()<<temp->getWinDirec()<<" | "<<temp->getWinPsd()<<" | "<<temp->getHumidity()<<" | "<<temp->getRained()<<endl;
            temp = temp->next;
        }
    }
}


//Cargar datos quemados
TimeRegis* TimeRegis::dataLoad(TimeRegis* timeList){

    timeList=add("01/09/2022",1245,21.4,10.4,24,89,25,true,timeList);
    timeList=add("02/09/2022",5345,25.0,11.4,29,73,26,false,timeList);
    timeList=add("03/09/2022",5571,15.9,5.6,31,69,29,true,timeList);
    timeList=add("04/09/2022",5486,12.4,6.9,6,83,21,true,timeList);
    timeList=add("05/09/2022",4911,8.8,3.8,34,70,20,false,timeList);
    timeList=add("06/09/2022",2688,17.3,11.0,27,93,19,true,timeList);
    timeList=add("07/09/2022",9875,31.5,15.3,19,60,34,false,timeList);
    timeList=add("08/09/2022",1135,20.1,14.1,13,80,2,false,timeList);
    timeList=add("09/09/2022",887,27.0,12.9,28,25,36,false,timeList);
    timeList=add("10/09/2022",235,23.3,16.5,25,60,32,true,timeList);


    cout<<"\n--- Se cargaron los datos correctamente ---\n";
    return timeList;

}






