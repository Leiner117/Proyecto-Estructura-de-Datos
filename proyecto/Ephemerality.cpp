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

/**
 * Esta función busca una efímera en la lista de efímera basada en la fecha
 *
 * Args:
 *   date (long int): La fecha de lo efímero que quieres buscar.
 *   eList (Ephemerality): La lista de lo efímero
 *
 * Returns:
 *   Un puntero al objeto Ephemeraality que tiene la fecha en que se pasó.
 */
Ephemerality*Ephemerality::searchEphemerality(long int date,Ephemerality*eList){
    if(eList == NULL){
        return NULL;
    }
    Ephemerality*temp = eList;
    while(temp != NULL){
        if(temp->getDate() == date){

            return temp;
        }
        temp = temp->next;
    }
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

Ephemerality* Ephemerality::dataLoad(Ephemerality*eList){
    eList = eList->addEphemerality("Sol",1663999200,18900,65700,eList);//24 / 09 / 2022
    eList = eList->addEphemerality("Sol",1664344800,19200,63900,eList);//28 / 09 / 2022
    eList = eList->addEphemerality("Sol",1662012000,19800,65640,eList);//01 / 09 / 2022
    eList = eList->addEphemerality("Sol",1662098400,20700,62100,eList);//02 / 09 / 2022
    eList = eList->addEphemerality("Sol",1662184800,21300,66300,eList);//03 / 09 / 2022
    eList = eList->addEphemerality("Sol",1658815200,21300,66300,eList);//26 / 07 / 2022
    eList = eList->addEphemerality("Sol",1627279200,21300,66300,eList);//26 / 07 / 2021

    return eList;

}
/*
    retorna el ano de la fecha
*/

tm* Ephemerality::unixDateToDate(long int seconds){
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
    long int unixtime;
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
/*
Imprime la lista de efimeridad
*/
void Ephemerality::printEphemeralityList(Ephemerality*eList){
    if(eList == NULL){
        cout<< "\nLista Doble vacia..\n";

    }
    else{
        Ephemerality*temp = eList;
        cout<<"\n\t   =========================================\n";
        cout<<"\t   ||        Lista de Efimeridad          ||\n";
        cout<<"\t   =========================================\n";
        //cout<< "Lista de efimeridad"<<endl;
        //cout<<"*******************************"<<endl;
        while(temp != NULL){
            cout<<"\n\t________________________________________________\n";
            cout<<"\n\tNOMBRE: "<<temp->getName()<<endl;
            struct tm*date = unixDateToDate(temp->getDate());
            string ans = dateToString(date);
            cout<<"\n\tFECHA: "<<ans<<endl;
            cout<<"\n\tHORA DE SALIDA: "<<temp->secondsToTime(temp->getDepartureTime())<<endl;
            cout<<"\n\tHORA DE OCULTAMIENTO: "<<temp->secondsToTime(temp->getHideTime())<<endl;

            temp = temp->next;
        }
    }
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPresione cualquier tecla para regresar al menu...";
    cin.ignore();
    cin.get();

}

string Ephemerality::dateToString(tm*date){
    string ans = "";
    ans += to_string(date->tm_mday);
    ans += "/";
    ans += to_string(date->tm_mon);
    ans += "/";
    ans += to_string(date->tm_year);
    return ans;
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
/*
Se encarga de imprimir las dos fechas con la mayor diferencia de la salida del sol
*/
 void Ephemerality::diffDepartureTime(int year,Ephemerality*eList){


    int diff,diff2;
    struct tm*date;
    string finalDate2;
    string finalDate;
    short flag = 2;
    if (eList != NULL){
        while (flag != 0){
            Ephemerality*temp = eList;
            while(temp !=NULL){
                date = temp->unixDateToDate(temp->getDate());
                int localDiff;
                if (date->tm_year == year){

                    localDiff = (temp->getHideTime()-temp->getDepartureTime())/60;
                }
                if (flag == 2){


                    if (localDiff > diff){
                        diff = localDiff;
                        finalDate = dateToString(date);

                    }

                }
                else{
                    if ((localDiff > diff2 )&& (localDiff != diff)){
                        diff2 = localDiff;
                        finalDate2 = dateToString(date);
                    }
                }
            temp = temp->next;
            }
            flag = flag-1;

        }
        cout<<"Las fechas con mayor diferencia son: "<<finalDate<<" con "<<diff<<" minutos"<<" , "<<finalDate2<<" con "<<diff2<<" minutos"<<endl;

    }


 }
 /*
 Reporte de efimeridad por a�o
 */
 void Ephemerality::timeReportYear(Ephemerality*eList,int year){
    string months[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

    short flag = 1;
    bool flag2 = false;
    struct tm*date;
    int month;
    Ephemerality*temp = eList;


    cout<<"*******************************"<<endl;
    while (temp != NULL){

        date = unixDateToDate(temp->getDate());
        if (date->tm_year == year){


            if (month != date->tm_mon){
                cout<<"MES: "<<months[(date->tm_mon)-1]<<endl;
                cout<<"*******************************"<<endl;
                month = date->tm_mon;

            }

            cout<<"HORA DE SALIDA: "<<secondsToTime(temp->getDepartureTime())<<endl;
            cout<< "HORA DE OCULTAMIENTO: "<<secondsToTime(temp->getHideTime())<<endl;
            cout<<"*******************************"<<endl;

            }
            temp = temp->next;
        }



 }
/*
 * Se encarga de imprimir el dia que el sol salio mas temprano y el dia que se oculto mas tarde
 * */
 void Ephemerality::earlyDeparLateHide(Ephemerality*elist){
     Ephemerality*temp = elist;
    int departureTime = 0,hideTime = 0;
    Ephemerality*selectTemp;
    Ephemerality*selectTemp2;
     while (temp != NULL){
        if (temp->getDepartureTime()<=departureTime || departureTime == 0) {

            departureTime = temp->getDepartureTime();
            selectTemp = temp;

            if (temp->getHideTime() >= hideTime) {
                hideTime = temp->getHideTime();
                selectTemp2 = temp;
            }

        }
        temp = temp->next;
     }
     Ephemerality*tempList = elist;
    Ephemerality*tempList2 = elist;
    cout<<"Los dias con la salida del Sol mas temprana son: "<<endl;
     while(tempList != NULL){
         if (tempList->getDepartureTime() == selectTemp->getDepartureTime()){
             cout<<dateToString(unixDateToDate(tempList->getDate()))<<endl;
         }

         tempList = tempList->next;
     }
     cout<<"Los dias con el ocultamiento del Sol mas tarde son: "<<endl;
     while (tempList2 != NULL){
         if (tempList2->getHideTime() == selectTemp2->getHideTime()){
             cout<<dateToString(unixDateToDate(tempList2->getDate()))<<endl;
         }
         tempList2 = tempList2->next;
     }



 }









