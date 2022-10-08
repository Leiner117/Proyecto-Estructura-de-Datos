#include "Ephemerality.h"
#include <string>
#include <iostream>
#include <time.h>
/*
 Creado: 16/09/2022 ultima mod: 07/10/2022
 Autor: Leiner Alvarado
 */

using namespace std;
//Constructor
/**
 *Constructor de la clase efimeridad
 * Args:
 *   n (string): Nombre de lo efímero
 *   d (long int): la fecha del evento
 *   departure (int): El tiempo en segundos que el objeto desaparecerá.
 *   hide (int): el tiempo en segundos que el mensaje estará oculto
 */
Ephemerality::Ephemerality(string n,long int d,int departure,int hide)
{
    setName(n);
    setDate(d);
    setDepartureTime(departure);
    setHideTime(hide);
}

//Setters
/**
 * Esta función establece el nombre de la efimeridad.
 *
 * Args:
 *   n (string): El nombre de lo efímero.
 */
void Ephemerality::setName(string n){
    name = n;
}
/**
 * Esta función establece la fecha de efimeridad.
 *
 * Args:
 *   d (long int): La fecha de lo efímero.
 */
void Ephemerality::setDate(long int d){
    date = d;
}
/**
 * Esta función establece la hora de salida de efimeridad.
 *
 * Args:
 *   time (int): Hora.
 */
void Ephemerality::setDepartureTime(int time){
    departureTime = time;
}
/**
 * Esta función establece la hora de ocultamiento
 *
 * Args:
 *   time (int): Hora
 */
void Ephemerality::setHideTime(int time){
    hideTime = time;

}

//Getters
/**
 * Devuelve el nombre de la efimeridad.
 *
 * Returns:
 *   El nombre de la efimeridad.
 */

string Ephemerality::getName(){
    return name;
}
/**
 * Esta función devuelve la fecha de efimeridad.
 *
 * Returns:
 *   La fecha de efimeridad.
 */
long int Ephemerality::getDate(){
    return date;
}

/**
 * Esta función devuelve la hora de salida del sol de efimeridad.
 *
 * Returns:
 *   La hora de salida del sol.
 */
long int Ephemerality::getDepartureTime(){
    return departureTime;
}
/**
 * Esta función devuelve la hora de ocultamiento del sol
 *
 * Returns:
 *   Se devuelve la hora de ocultamiento .
 */
long int Ephemerality::getHideTime(){
    return hideTime;
}

//Funciones


/**
 * Añade una efimeridad a la lista de efimeridades
 *
 * Args:
 *   name (string): El nombre de la efimeridad.
 *   date (long int): La fecha de la efimeridad.
 *   departureTime (int): La hora de salida del sol.
 *   hideTime (int): La hora de ocultamiento del sol.
 *   elist (Ephemerality): La lista de efimeridad.
 *
 * Returns:
 *   La lista de efimeridad
 */
Ephemerality*Ephemerality::addEphemerality(string name,long int date,int departureTime,int hideTime,Ephemerality*elist){

    if (searchEphemerality(date,elist)== NULL){
        Ephemerality*newEphemerality = new Ephemerality(name,date,departureTime,hideTime);
        if(elist == NULL)
            elist = newEphemerality;
        else if(date <= elist->getDate()){
            newEphemerality->next = elist;
            elist->pre = newEphemerality;
            elist = newEphemerality;
        }
        else{
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
        cout << "\n\t\tLOS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE EFEMERIDAD... ";
    }
    return elist;
}

/**
 * Esta función busca una efimeridad en la lista de efimeridad basada en la fecha
 *
 * Args:
 *   date (long int): La fecha de efimeridad que quieres buscar.
 *   eList (Ephemerality): La lista de efimeridad
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


/**
 * Elimina una efimeridad de la lista
 *
 * Args:
 *   date (long int): La fecha de la efimeridad que se va a eliminar.
 *   eList (Ephemerality): La lista de efimeridad.
 *
 * Returns:
 *   La lista de efimeridad modificada.
 */
Ephemerality*Ephemerality::deleteEphemerality(long int date,Ephemerality*eList){

    Ephemerality*dEphemerality = searchEphemerality(date,eList);
    if(dEphemerality == NULL){

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

    return eList;
}

/**
 * Esta función modifica el nombre de una efimeridad
 *
 * Args:
 *   eList (Ephemerality): La lista de lo efimeridad
 *   date (long int): la fecha del efímeridaad que quieres modificar
 *   newName (string): El nuevo nombre de efimeridad.
 */
void Ephemerality::modName(Ephemerality*eList,long int date,string newName){
    if (searchEphemerality(date,eList) == NULL){

       Ephemerality*ephemerality = searchEphemerality(date,eList);
       ephemerality->setName(newName);
    }
}

/**
 * Busca una efimeridad con una fecha determinada, y si lo encuentra, cambia la fecha
 *
 * Args:
 *   eList (Ephemerality): La lista de lo efímeridad.
 *   date (long int): la fecha del efímeridad que quieres modificar
 *   newDate (int): La nueva fecha que se fijará a lo efimeridad.
 */
void Ephemerality::modDate(Ephemerality*eList,long int date,int newDate){

    Ephemerality*ephemerality = searchEphemerality(date,eList);
    if(ephemerality == NULL){
        ephemerality->setDate(newDate);
    }
    else{
        cout<<"\n\tLA FECHA YA SE ENCUENTRA REGISTRADA"<<endl;
    }
}


/**
 * Modifica el tiempo de ocultación del sol
 *
 * Args:
 *   eList (Ephemerality): La lista de efimeridad.
 *   date (long int): la fecha de efimeridad que quieres modificar
 *   newHideTime (int): Nueva hora de ocultamiento.
 */
void Ephemerality::modHideTime(Ephemerality*eList,long int date,int newHideTime){
    Ephemerality*ephemerality = searchEphemerality(date,eList);
    ephemerality->setHideTime(newHideTime);
}


/**
 * Busca una efímera en la lista de efimeridad, y luego cambia la hora de salida del sol
 *
 * Args:
 *   eList (Ephemerality): la lista de efimeridad
 *   date (long int): la fecha de salida del sol que quieres modificar
 *   newDepartureTime (int): la nueva hora de salida
 */
void Ephemerality::modDepartureTime(Ephemerality*eList,long int date,int newDepartureTime){
    Ephemerality*ephemerality = searchEphemerality(date,eList);
    ephemerality->setDepartureTime(newDepartureTime);

}

/**
 * Añade 10 efimeridades a la lista de efimeridad
 *
 * Args:
 *   eList (Ephemerality): La lista de efimeridad
 *
 * Returns:
 *   La lista de efimeridad.
 */
Ephemerality* Ephemerality::dataLoad(Ephemerality*eList){
    eList = eList->addEphemerality("Sol",1663999200,18900,65700,eList);//24 / 09 / 2022
    eList = eList->addEphemerality("Sol",1664344800,19200,63900,eList);//28 / 09 / 2022
    eList = eList->addEphemerality("Sol",1662012000,19800,65640,eList);//01 / 09 / 2022
    eList = eList->addEphemerality("Sol",1662098400,20700,62100,eList);//02 / 09 / 2022
    eList = eList->addEphemerality("Sol",1662184800,21300,66300,eList);//03 / 09 / 2022
    eList = eList->addEphemerality("Sol",1658815200,21300,66300,eList);//26 / 07 / 2022
    eList = eList->addEphemerality("Sol",1627279200,21300,66300,eList);//26 / 07 / 2021
    eList = eList->addEphemerality("Sol",1624255200,21300,66300,eList);//21 / 06 / 2021
    eList = eList->addEphemerality("Sol",1627452000,21300,66300,eList);//28 / 07 / 2021
    eList = eList->addEphemerality("Sol",1627624800,21300,66300,eList);//30 / 07 / 2021
    return eList;

}


/**
 * Toma una marca de tiempo de Unix y devuelve una estructura tm con la fecha y la hora.
 *
 * Args:
 *   seconds (long int): El número de segundos desde la época de Unix (1 de enero de 1970 00:00:00 GMT)
 *
 * Returns:
 *   Una estructura tm*
 */
tm* Ephemerality::unixDateToDate(long int seconds){

	string ans = "";


	int daysOfMonth[] = { 31, 28, 31, 30, 31, 30,
						31, 31, 30, 31, 30, 31 };

	long int currYear, daysTillNow, extraTime,
		extraDays, index, date, month,flag = 0,hours,minutes,secondss;


	daysTillNow = seconds / (24 * 60 * 60);
	extraTime = seconds % (24 * 60 * 60);
	currYear = 1970;


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

	extraDays = daysTillNow + 1;

	if (currYear % 400 == 0
		|| (currYear % 4 == 0
			&& currYear % 100 != 0))
		flag = 1;


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




	return timeinfo;


}

/**
 * Imprime la lista de efimeridad.
 *
 * Args:
 *   eList (Ephemerality): La lista de efimeridad
 */
void Ephemerality::printEphemeralityList(Ephemerality*eList){
    if(eList == NULL){
        cout<<"\n\t-- La lista de efimeridades esta vacia --\n";

    }
    else{
        Ephemerality*temp = eList;
        cout<<"\n\t   =========================================\n";
        cout<<"\t   ||        LISTA DE EFIMERIDAD          ||\n";
        cout<<"\t   =========================================\n";
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
    cout<<"\n\tPRESIONE C...";
    cin.ignore();
    cin.get();

}

/**
 * Convierte una estructura tm en una cadena
 *
 * Args:
 *   date (tm): un puntero a una estructura tm
 *
 * Returns:
 *   Una cadena que representa la fecha en formato dd/mm/yyyy
 */
string Ephemerality::dateToString(tm*date){
    string ans = "";
    ans += to_string(date->tm_mday);
    ans += "/";
    ans += to_string(date->tm_mon);
    ans += "/";
    ans += to_string(date->tm_year);
    return ans;
}

/**
 * Convierte una fecha en una marca de tiempo de Unix
 *
 * Args:
 *   year (int): El año, menos 1900.
 *   month (short): El mes del año, especificado como un número entero entre 1 y 12 (enero = 1, febrero = 2, etc.).
 *   day (short): El día del mes. Debe estar en el rango de 1 a 31.
 *
 * Returns:
 *   El número de segundos desde la época.
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


/**
 * Convierte una hora(HH:MM) en segundos
 * Args:
 *   hour (short): Horas.
 *   minutes (short):Minutos.
 *
 * Returns:
 *   El numero de segundos en el tiempo dado.
 */
int Ephemerality::timeToSeconds(short hour,short minutes){
    int seconds;
    hour = hour*3600;
    minutes = minutes*60;
    seconds = hour+minutes;
    return seconds;
}

/**
 * Toma un número entero que representa segundos y devuelve una cadena que representa el tiempo en horas y minutos
 *
 * Args:
 *   seconds (int): El número de segundos para convertir a una cadena de tiempo.
 *
 * Returns:
 *   El tiempo en horas y minutos.
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



 /**
  * Encuentra las dos fechas con mayor diferencia entre la hora de salida y la hora de ocultar
  *
  * Args:
  *   year (int): El año a buscar.
  *   eList (Ephemerality): La lista de efimeridad.
  */
 void Ephemerality::diffDepartureTime(int year,Ephemerality*eList){


    int diff,diff2;
    struct tm*date;
    string finalDate2;
    string finalDate;
    short flag = 2;
    cout<<"\n\t   =============================================\n";
    cout<<"\t   || FECHAS CON MAYOR DIFERENCIA DE HORAS ||\n";
    cout<<"\t   =============================================\n";
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
        cout<<"\n\t________________________________________________\n";
        cout<<"\n\tLAS FECHAS CON MAYOR DIFERENCIA SON: "<<finalDate<<" CON "<<diff<<" MINUTOS"<<" , "<<finalDate2<<" CON "<<diff2<<" MINUTOS"<<endl;
        cout<<"\n\t________________________________________________\n";
    }


 }


 /**
  * Imprime la hora de salida y la hora de ocultamiento del sol para cada mes del año
  *
  * Args:
  *   eList (Ephemerality): es un puntero al primer elemento de una lista enlazada de efimeridad.
  *   year (int): el año que desea informar
  */

 void Ephemerality::timeReportYear(Ephemerality*eList,int year){
    string months[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

    short flag = 1;
    bool flag2 = false;
    struct tm*date;
    int month;
    Ephemerality*temp = eList;


    cout<<"\n\t   =============================================\n";
    cout<<"\t   || HORARIO DE SALIDA Y OCULTAMIENTO DEL SOL EN "<<year<<"||\n";
    cout<<"\t   =============================================\n";
    while (temp != NULL){

        date = unixDateToDate(temp->getDate());
        if (date->tm_year == year){


            if (month != date->tm_mon){
                cout<<"\n\t________________________________________________\n";
                cout<<"\n\tMES: "<<months[(date->tm_mon)-1]<<endl;

                month = date->tm_mon;

            }

            cout<<"\n\tHORA DE SALIDA: "<<secondsToTime(temp->getDepartureTime())<<endl;
            cout<< "\n\tHORA DE OCULTAMIENTO: "<<secondsToTime(temp->getHideTime())<<endl;
            cout<<"\n\t________________________________________________\n";

            }
            temp = temp->next;
        }



 }


 /**
  * Imprime las fechas con el amanecer más temprano y el atardecer más tardío.
  *
  * Args:
  *   elist (Ephemerality): La lista de efimeridad
  */
 void Ephemerality::earlyDeparLateHide(Ephemerality*elist){
     Ephemerality*temp = elist;
    int departureTime = 0,hideTime = 0;
    Ephemerality*selectTemp;
    Ephemerality*selectTemp2;
    cout<<"\n\t   =============================================\n";
    cout<<"\t   || SALIDA DEL SOL MAS TEMPRANA Y OCULTAMIENTO MAS TARDIO ||\n";
    cout<<"\t   =============================================\n";
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
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tLOS DIAS CON LA SALIDA DEL SOL MAS TEMPRANA SON : "<<endl;
     while(tempList != NULL){
         if (tempList->getDepartureTime() == selectTemp->getDepartureTime()){
             cout<<dateToString(unixDateToDate(tempList->getDate()))<<endl;

         }


         tempList = tempList->next;
     }
      cout<<"\n\t________________________________________________\n";
     cout<<"\n\tLOS DIAS CON EL OCULTAMIENTO DEL SOL MAS TARDE : "<<endl;
     while (tempList2 != NULL){
         if (tempList2->getHideTime() == selectTemp2->getHideTime()){
             cout<<dateToString(unixDateToDate(tempList2->getDate()))<<endl;
         }
         tempList2 = tempList2->next;
     }
      cout<<"\n\t________________________________________________\n";



 }
/**
 * Esta función comprueba si la hora es válida
 *
 * Args:
 *   hourDeparture (int): la hora de salida
 *   minutesDeparture (int): minutos de salida
 *   hoursHide (int): la hora de ocultamiento
 *   minutesHide (int): minutos de ocultamiento
 *
 * Returns:
 *   un valor booleano.
 */
bool Ephemerality::valTime(int hourDeparture,int minutesDeparture,int hoursHide,int minutesHide){
     bool flag = false;
     if ((hourDeparture <=24 && hourDeparture>0)&&(hoursHide <=24 && hoursHide>0)&&(minutesDeparture <=60 && minutesDeparture >0)&&(minutesHide <=60 && minutesHide >0)){
         flag =true;

     }
     return flag;
 }








