#include "TimeRegis.h"
#include "Ephemerality.h"
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

//Aqui se implementan los metodos y se utilizan las variables del archivo .h

//Constructor con paramentros
TimeRegis::TimeRegis(long int dateR,int precip,float maxTemp, float minTemp,int winSpd, int windDirec,int humidity,bool rained){

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
void TimeRegis::setDateR(long int dateR){

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

void TimeRegis::setHumidity(int hum){

    humidity= hum;
}

void TimeRegis::setRained(bool rained){

    yesRained=rained;
}

//------------------- Metodos get-----------------------------------------
long int TimeRegis::getDateR(){
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
    return windSpeed;
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
bool TimeRegis::validate(long int date, TimeRegis* timeList){
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
TimeRegis* TimeRegis::add(long int dateR,int precip,float maxTemp,float minTemp,int winSpd, int winDirec,int humidity,bool rained, TimeRegis* timeList){

    bool duplicate=validate(dateR,timeList);
    if(duplicate==NULL){

        TimeRegis* newNodo = new TimeRegis(dateR,precip,maxTemp,minTemp,winSpd,winDirec,humidity,rained);
        newNodo->next = timeList;//se enlaza, conoce la direccion el inicio de la lista
        timeList = newNodo;
    }
    else
        cout<<"\n+++ Advertencia: El nombre ingresado ya esta en la lista +++\n";

    return timeList;

}

TimeRegis* TimeRegis::modify(long int date,long int dateR,int precip,float maxTemp, float minTemp,int winSpd, int windDirec,int humidity,bool rained, TimeRegis* timeList){

    bool duplicate=validate(dateR,timeList);
    if(duplicate==NULL){
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

TimeRegis*TimeRegis::deleteTime(long int date, TimeRegis* timeList){
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


TimeRegis* TimeRegis::searchTime(long int date, TimeRegis* timeList){
    if(timeList == NULL)
        cout<<"\nLa lista esta vacia....";
    else{
        TimeRegis*temp = timeList;
        while(temp != NULL){
            if(temp->getDateR() == date){
                return temp;
            }
            temp = temp->next;
        }
        //cout<<"\nNo se encontro el dato";
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
            cout<<temp->getDateR()<<" | "<<temp->getPrecip()<<" | "<<temp->getMaxTemp()<<" | "<<temp->getMinTemp()<<temp->getWinDirec()<<" | "<<temp->getWinPsd()<<" | "<<temp->getHumidity()<<" | ";
            if (temp->getRained()==true){
                cout<<"Si llovio"<<endl;
            }
            else{
                cout<<"No llovio"<<endl;
            }
            temp = temp->next;
        }
    }
}


//Cargar datos quemados
TimeRegis* TimeRegis::dataLoad(TimeRegis* timeList){

    timeList=add(1662012000,1245,21.4,10.4,24,89,25,true,timeList);
    timeList=add(1662098400,5345,25.0,11.4,29,73,26,false,timeList);
    timeList=add(1662184800,5571,15.9,5.6,31,69,29,true,timeList);
    timeList=add(1662271200,5486,12.4,6.9,6,83,21,true,timeList);
    timeList=add(1662357600,4911,8.8,3.8,34,70,20,false,timeList);
    timeList=add(1662444000,2688,17.3,11.0,27,93,19,true,timeList);
    timeList=add(1662530400,9875,31.5,15.3,19,60,34,false,timeList);
    timeList=add(1662616800,1135,20.1,14.1,13,80,2,false,timeList);
    timeList=add(1662703200,887,27.0,12.9,28,25,36,false,timeList);
    timeList=add(1662789600,235,23.3,16.5,25,60,32,true,timeList);


    cout<<"\n--- Se cargaron los datos correctamente ---\n";
    return timeList;

}

/*
Convierte la fecha a UnixDate(segundos totales)
*/
long int TimeRegis::dateToUnixDate(int year,short month,short day){
    time_t rawtime;
    struct tm*timeinfo;
    long int unixtime;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour = 0;
    timeinfo->tm_min = 0;
    timeinfo->tm_sec = 0;

    unixtime = mktime(timeinfo);
    return unixtime;
}
// Convierte de formato fecha a string para imprimir
string TimeRegis::dateToString(tm*date){
    string ans = "";
    ans += to_string(date->tm_mday);
    ans += "/";
    ans += to_string(date->tm_mon);
    ans += "/";
    ans += to_string(date->tm_year);
    return ans;
}
/*Convierte de formato UnixDate a estructura date
 * */
tm* TimeRegis::unixDateToDate(long int seconds){
    // Save the time in Human
    // readable format
    string ans = "";

    // Number of days in month
    // in normal year
    int daysOfMonth[] = { 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };

    long int currYear, daysTillNow, extraTime,
            extraDays, index, date, month,flag = 0,hours,minutes,secondss;

    // Calculate total days unix time T

    // Calculate total days unix time T
    daysTillNow = seconds / (24 * 60 * 60);
    extraTime = seconds % (24 * 60 * 60);
    currYear = 1970;

    // Calculating current year
    while (daysTillNow >= 365) {
        if (currYear % 400 == 0
            || (currYear % 4 == 0
                && currYear % 100 != 0)) {
            daysTillNow -= 366;
        }
        else {
            daysTillNow -= 365;
        }
        currYear += 1;
    }

    // Updating extradays because it
    // will give days till previous day
    // and we have include current day
    extraDays = daysTillNow + 1;

    if (currYear % 400 == 0
        || (currYear % 4 == 0
            && currYear % 100 != 0))
        flag = 1;



    // Calculating MONTH and DATE
    month = 0, index = 0;
    if (flag == 1) {
        while (true) {

            if (index == 1) {
                if (extraDays - 29 < 0)
                    break;
                month += 1;
                extraDays -= 29;
            }
            else {
                if (extraDays
                    - daysOfMonth[index]
                    < 0) {
                    break;
                }
                month += 1;
                extraDays -= daysOfMonth[index];
            }
            index += 1;
        }
    }
    else {
        while (true) {

            if (extraDays
                - daysOfMonth[index]
                < 0) {
                break;
            }
            month += 1;
            extraDays -= daysOfMonth[index];
            index += 1;
        }
    }

    // Current Month
    if (extraDays > 0) {
        month += 1;
        date = extraDays;
    }
    else {
        if (month == 2 && flag == 1)
            date = 29;
        else {
            date = daysOfMonth[month - 1];
        }
    }
    hours = extraTime / 3600;
    minutes = (extraTime % 3600) / 60;
    secondss = (extraTime % 3600) % 60;
    time_t rawtime;
    struct tm*timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = currYear;
    timeinfo->tm_mon = month;
    timeinfo->tm_mday = date;
    timeinfo->tm_hour = hours;
    timeinfo->tm_min = minutes;
    timeinfo->tm_sec = secondss;



    // Return the time
    return timeinfo;


}




//---------------------------------SUBLISTA DE LLUVIA----------------------------

NodoSubRain* TimeRegis::linkendRainTime(string idRain, long int date,Rain* rainList,TimeRegis* timeList){

    TimeRegis* time = time->searchTime(date,timeList);
    Rain* rain = rain->searchRain(rainList,idRain);

    if(time == NULL){
        cout<<"\nNo existe el registro del tiempo";
        return NULL;
    }
    if(rain == NULL){
        cout<<"\nNo existe el registrod e lluvia";
        return NULL;
    }
    NodoSubRain* newNodo = new NodoSubRain();
    newNodo->linkRain = rain;// se enlaza con el curso
    newNodo->next = time->rainSublist;
    time->rainSublist = newNodo;
    return time->rainSublist;

}














void TimeRegis::printSubRain(long int date,TimeRegis* timeList){

    TimeRegis * time =time->searchTime(date,timeList);
    if(time == NULL){
        cout<<"\n\tNo existe esta fecha en el registro\n";
        return;
    }
    else{
        NodoSubRain* temSub = time->rainSublist;
        if(temSub==NULL){
            cout<<"\n\tEn esta fecha no hay registros de lluvias.\n";
        }
        else{
            cout<<"\n\t   =========================================\n";
            cout<<"\t   ||   Historial de lluvias en "<<time->getDateR()<<"   ||\n";
            cout<<"\t   =========================================\n";
            while(temSub != NULL){
                cout<<"\n\t________________________________________________\n";
                cout<<"\n\tCODIGO: "<<temSub->linkRain->getRainCode();
                cout<<"\n\tNOMBRE: "<<temSub->linkRain->getName();
                cout<<"\n\tRANGO PROMEDIO: "<<temSub->linkRain->getAverageRange();
                temSub = temSub->next;
            }
            cout<<"\n\t________________________________________________\n";
        }
    }

}













