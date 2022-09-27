#include "Ephemerality.h"
#include <string>
#include <iostream>
#include <time.h>
/*
 Creado: 16/09/2022 ultima mod: 26/09/2022
 Autor: Leiner Alvarado
 */

using namespace std;
//Constructor
Ephemerality::Ephemerality(string n,long int d,int departure,int hide)
{
    setName(n);
    setDate(d);
    setDepartureTime(departure);
    setHideTime(hide);
}

//Setters
void Ephemerality::setName(string n){
    name = n;
}
void Ephemerality::setDate(long int d){
    date = d;
}
void Ephemerality::setDepartureTime(int time){
    departureTime = time;
}
void Ephemerality::setHideTime(int time){
    hideTime = time;

}

//Getters
string Ephemerality::getName(){
    return name;
}
long int Ephemerality::getDate(){
    return date;
}
long int Ephemerality::getDepartureTime(){
    return departureTime;
}
long int Ephemerality::getHideTime(){
    return hideTime;
}

//Funciones

/*
Funcion agregar efimeridad
Agrega nodos efimeridad a la lista doble
*/
Ephemerality*Ephemerality::addEphemerality(string name,long int date,int departureTime,int hideTime,Ephemerality*elist){

    if (searchEphemerality(date,elist)== NULL){


        Ephemerality*newEphemerality = new Ephemerality(name,date,departureTime,hideTime);
        if(elist == NULL)
            elist = newEphemerality;
        else if(date <= elist->getDate()){//inserta al inicio
            newEphemerality->next = elist;
            elist->pre = newEphemerality;
            elist = newEphemerality;
        }
        else{//es en medio o al final de la lista
            Ephemerality*temp = elist;
            Ephemerality*previ;
            while((temp!= NULL) &&(date>temp->getDate())){

                previ = temp;
                temp = temp->next;

            }
            previ->next = newEphemerality;
            newEphemerality->pre = temp;
            if(temp != NULL)
                newEphemerality->next = temp;

        }
    }
    return elist;
}

/*
Funcion buscar efimeridad
Retorna el nodo de efimeridad solicitado
*/

Ephemerality*Ephemerality::searchEphemerality(long int date,Ephemerality*eList){
    if(eList == NULL){
        cout<< "\nlista Vacia...\n";
        return NULL;
    }
    Ephemerality*temp = eList;
    while(temp != NULL){
        if(temp->getDate() == date){

            return temp;
        }
        temp = temp->next;
    }
    cout<< "\nNo encontrado en la lista doble";
    return NULL;
}

/*
Funcion borrar efimeridad
Borra de la lista doble el nodo solicitado
*/
Ephemerality*Ephemerality::deleteEphemerality(long int date,Ephemerality*eList){

    Ephemerality*dEphemerality = searchEphemerality(date,eList);
    if(dEphemerality == NULL){
        cout<< "\n No se puede borrar \n";
        return eList;
    }
    else{
        if(dEphemerality == eList){
            eList = eList->next;
            if(eList != NULL){
                eList->pre = NULL;
            }
        }
        else{
            dEphemerality->pre->next = dEphemerality->next;
            if(dEphemerality->next != NULL){
                dEphemerality->next->pre = dEphemerality->pre;
                }
            }

    }
    cout<< "\n Se puede borrar \n";
    return eList;
}
/*
Funcion modificar nombre
Se encarga de modificar el nombre de la efimeridad
*/
void Ephemerality::modName(Ephemerality*eList,long int date,string newName){
    if (searchEphemerality(date,eList) == NULL){

       Ephemerality*ephemerality = searchEphemerality(date,eList);
       ephemerality->setName(newName);
    }
}
/*
Funcion modificar fecha
Se encarga de modificar la fecha de la efimeridad
*/
void Ephemerality::modDate(Ephemerality*eList,long int date,int newDate){

    Ephemerality*ephemerality = searchEphemerality(date,eList);
    ephemerality->setDate(newDate);
}

/*
Funcion modificar hora de ocultamiento
Se encarga de modificar la hora de ocultamiento de la efimeridad
*/

void Ephemerality::modHideTime(Ephemerality*eList,long int date,int newHideTime){
    Ephemerality*ephemerality = searchEphemerality(date,eList);
    ephemerality->setHideTime(newHideTime);
}


/*
Funcion modificar hora de salida
Se encarga de modificar la hora de salida de la efimeridad
*/

void Ephemerality::modDepartureTime(Ephemerality*eList,long int date,int newDepartureTime){
    Ephemerality*ephemerality = searchEphemerality(date,eList);
    ephemerality->setDepartureTime(newDepartureTime);

}

Ephemerality* Ephemerality::dataload(Ephemerality*eList){
    eList = eList->addEphemerality("Sol",1663999200,18900,65700,eList);

    eList = eList->addEphemerality("Sol",1664344800,19200,63900,eList);

    eList = eList->addEphemerality("Sol",1662012000,19800,65640,eList);

    eList = eList->addEphemerality("Sol",1662098400,20700,62100,eList);

    eList = eList->addEphemerality("Sol",1662184800,21300,66300,eList);

    return eList;

}
/*
    retorna el año de la fecha
*/
int Ephemerality::unixDateToYear(long int seconds){
    int daysTillNow,year,flag;
    year = 1970;
    daysTillNow = seconds / (24 * 60 * 60);
    year = 1970;
    // Calculating current year
	while (daysTillNow >= 365) {
		if (year % 400 == 0
			|| (year % 4 == 0
				&& year % 100 != 0)) {
			daysTillNow -= 366;
		}
		else {
			daysTillNow -= 365;
		}
		year += 1;
	}



	if (year % 400 == 0
		|| (year % 4 == 0
			&& year % 100 != 0))
		flag = 1;
    return year;

}
string Ephemerality::unixDateToDate(long int seconds){
    // Save the time in Human
	// readable format
	string ans = "";

	// Number of days in month
	// in normal year
	int daysOfMonth[] = { 31, 28, 31, 30, 31, 30,
						31, 31, 30, 31, 30, 31 };

	long int currYear, daysTillNow, extraTime,
		extraDays, index, date, month,flag = 0;

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


	ans += to_string(date);
	ans += "/";
	ans += to_string(month);
	ans += "/";
	ans += to_string(currYear);


	// Return the time
	return ans;


}
/*
Imprime la lista de efimeridad
*/
void Ephemerality::printEphemeralityList(Ephemerality*eList){
    if(eList == NULL){
        cout<< "\nLista Doble vacia..\n";

    }
    else{
        Ephemerality*temp = eList;
        cout<< "Lista de efimeridad"<<endl;
        cout<<"*******************************"<<endl;
        while(temp != NULL){
            cout<<temp->getName()<<endl;
            cout<<unixDateToDate(temp->getDate())<<endl;
            cout<<temp->secondsToTime(temp->getDepartureTime())<<endl;
            cout<<temp->secondsToTime(temp->getHideTime())<<endl;
            cout<<"*******************************"<<endl;
            temp = temp->next;
        }


    }

}
/*
Convierte la fecha a UnixDate(segundos totales)
*/
long int Ephemerality::dateToUnixDate(int year,short month,short day){
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

/*
Convierte las horas y minutos en segundos
*/
int Ephemerality::timeToSeconds(short hour,short minutes){
    int seconds;
    hour = hour*3600;
    minutes = minutes*60;
    seconds = hour+minutes;
    return seconds;
}
/*
Convierte los minutos en la fecha
*/
string Ephemerality::secondsToTime(int seconds){
    int hours,minutes;
    string time;
    hours = (seconds/60)/60;
    minutes = (seconds/60)%60;
    time += to_string(hours);
    time += ":";
    time += to_string(minutes);
    return time;

}


