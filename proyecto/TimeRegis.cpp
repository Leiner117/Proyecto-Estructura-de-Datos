#include "TimeRegis.h"
#include "Ephemerality.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

/*
    Autor: Karina Urbina
    Iniciado: 12/09/2022
    Ultima modificacion: 8/10/2022

*/

/**
 * Contructor de la clase Registro del tiempo
 *
 * Args:
 *   dateR (long int): La fecha del registro de tiempo.
 *   precip (int): Precipitación en mm
 *   maxTemp (float): Temperatura máxima en grados Fahrenheit
 *   minTemp (float): La temperatura mínima del día.
 *   winSpd (int): Velocidad del viento
 *   windDirec (int): La dirección de donde sopla el viento.
 *   humidity (int): La humedad del dia
 *   rained (bool): cierto si llovió ese día, falso si no llovió
 */
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
/**
 * Esta función establece la fecha de registro del objeto TimeRegis
 *
 * Args:
 *   dateR (long int): La fecha del registro.
 */
void TimeRegis::setDateR(long int dateR){

    registrationDate=dateR;
}

/**
 * Esta función establece la variable de precipitación al valor del parámetro.
 *
 * Args:
 *   precip (int): La cantidad de precipitación en el área.
 */
void TimeRegis::setPrecip(int precip){

    precipitation=precip;
}

/**
 * Esta función establece la temperatura máxima
 *
 * Args:
 *   maxTemp (float): La temperatura máxima que el sistema puede alcanzar antes de apagarse.
 */
void TimeRegis::setMaxTemp(float maxTemp){

    maxTemperature=maxTemp;
}

/**
 * Esta función establece la temperatura mínima para la clase TimeRegis
 *
 * Args:
 *   minTemp (float): La temperatura mínima que permitirá el sistema.
 */
void TimeRegis::setMinTemp(float minTemp){

    minTemperature=minTemp;
}

/**
 * Esta función establece la velocidad del viento en el valor pasado como argumento
 *
 * Args:
 *   winSpd (int): La velocidad del viento en millas por hora.
 */
void TimeRegis::setWinPsd(int winSpd){

    windSpeed=winSpd;
}

/**
 * Esta función establece la dirección del viento al valor del parámetro winDirec
 *
 * Args:
 *   winDirec (int): La dirección del viento.
 */
void TimeRegis::setWinDirec(int winDirec){

    windDirection=winDirec;
}

/**
 * Esta función establece la humedad del objeto TimeRegis
 *
 * Args:
 *   hum (int): humedad
 */
void TimeRegis::setHumidity(int hum){

    humidity= hum;
}

/**
 * Esta función establece el valor de la variable privada yesRained al valor del parámetro rained
 *
 * Args:
 *   rained (bool): Este es un valor booleano que es verdadero si llovió durante el período de tiempo y falso si no llovió.
 */
void TimeRegis::setRained(bool rained){

    yesRained=rained;
}

//------------------- Metodos get-----------------------------------------
/**
 * Esta función devuelve la fecha de registro del objeto TimeRegis.
 *
 * Returns:
 *   La fecha de registro.
 */
long int TimeRegis::getDateR(){
    return registrationDate;
}

/**
 * Esta función devuelve el valor de la precipitación.
 *
 * Returns:
 *   Se devuelve el valor de precipitación.
 */
int TimeRegis::getPrecip(){
    return precipitation;
}

/**
 * Devuelve la temperatura máxima.
 *
 * Returns:
 *   La temperatura máxima
 */
float TimeRegis::getMaxTemp(){
    return maxTemperature;
}


/**
 * Devuelve la temperatura mínima.
 *
 * Returns:
 *   La temperatura mínima.
 */
float TimeRegis::getMinTemp(){
    return minTemperature;
}

/**
 * Devuelve la velocidad del viento.
 *
 * Returns:
 *   Se está devolviendo la velocidad del viento.
 */
int TimeRegis::getWinPsd(){
    return windSpeed;
}

/**
 * Esta función devuelve la dirección del viento.
 *
 * Returns:
 *   la dirección del viento
 */
int TimeRegis::getWinDirec(){
    return windDirection ;
}

/**
 * Devuelve el valor de la humedad.
 *
 * Returns:
 *   El valor de la humedad.
 */
int TimeRegis::getHumidity(){
    return humidity;
}

/**
 * Esta función devuelve el valor de la variable privada yesRained.
 *
 * Returns:
 *   sí llovió
 */
bool TimeRegis::getRained(){
    return yesRained;
}




//************************** Funciones de la lista ******************

//Agregar al Inicio
/**
 * Agrega un nuevo nodo a la lista de registro del tiempo.
 *
 * Args:
 *   dateR (long int): Fecha del registro
 *   precip (int): Precipitación en pulgadas
 *   maxTemp (float): Temperatura máxima en grados Fahrenheit
 *   minTemp (float): Temperatura mínima en grados Fahrenheit
 *   winSpd (int): velocidad del viento
 *   winDirec (int): Dirección del viento
 *   humidity (int): El porcentaje de humedad en el aire.
 *   rained (bool): valor booleano que indica si llovió o no
 *   timeList (TimeRegis): La lista de objetos TimeRegis.
 *
 * Returns:
 *   la lista de TimeRegis.
 */
TimeRegis* TimeRegis::add(long int dateR,int precip,float maxTemp,float minTemp,int winSpd, int winDirec,int humidity,bool rained, TimeRegis* timeList){

    if (searchTime(dateR,timeList) == NULL){
        TimeRegis* newNodo = new TimeRegis(dateR,precip,maxTemp,minTemp,winSpd,winDirec,humidity,rained);
        if (timeList == NULL){
            timeList = newNodo;
        }
        else if (dateR < timeList->getDateR()){
            newNodo->next = timeList;
            timeList = newNodo;
        }
        else{
            TimeRegis*temp = timeList;
            TimeRegis*ant;
            while((temp != NULL) && (dateR>temp->getDateR())){
                ant = temp;
                temp = temp->next;
            }
            ant->next = newNodo;
            if(temp !=NULL){
                newNodo->next = temp;
            }
        }
        cout << "\n\t\t-- LOS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE REGISTROS DEL TIEMPO --"<<endl;
    }
    return timeList;

}

/**
 * Modifica los valores de un nodo del registro del tiempo
 *
 * Args:
 *   date (long int): la fecha del registro de tiempo
 *   dateR (long int): la fecha del registro
 *   precip (int): Precipitación en mm
 *   maxTemp (float): Temperatura máxima en grados Fahrenheit
 *   minTemp (float): Temperatura mínima (en grados Fahrenheit)
 *   winSpd (int): velocidad del viento
 *   windDirec (int): dirección del viento
 *   humidity (int): El porcentaje de humedad en el aire.
 *   rained (bool): booleano
 *   timeList (TimeRegis): es la lista de objetos TimeRegis
 *
 * Returns:
 *   la lista de TimeRegis.
 */
TimeRegis* TimeRegis::modify(long int date,long int dateR,int precip,float maxTemp, float minTemp,int winSpd, int windDirec,int humidity,bool rained, TimeRegis* timeList){

    if(searchTime(dateR,timeList)==NULL){
        if(timeList== NULL)
            cout<<"\n\tNO HAY REGISTROS DEL TIEMPO .....";
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

                    cout<<"\n\tSE MODIFICO CORRECTAMENTE";
                    return timeList;//me salgo de la fucnion
                }
                temp = temp->next;
            }
            cout<<"\nNO SE ENCONTRO EL DATO.";
        }
    }
    else{
        cout<<"\n+++ ADVERTENCIA: EL NOMBRE INGRESADO YA SE ENCUENTRA EN LA LISTA +++\n";
    }
    return timeList;
}

/**
 * Borra un nodo de la lista de registros del tiempo
 *
 * Args:
 *   date (long int): La fecha de la hora que desea eliminar.
 *   timeList (TimeRegis): La lista de objetos TimeRegis.
 *
 * Returns:
 *   La lista de TimeRegis modificada
 */
TimeRegis*TimeRegis::deleteTime(long int date, TimeRegis* timeList){
    if(timeList == NULL)
        cout<<"\n\t LISTA VACIA, NO SE PUEDE BORRAR....";
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
                cout<<"\n\tSE BORRO CORRECTAMENTE";
            }
            if(current == NULL)
                cout<<"\n\tNO SE ENCONTRO EL NODO";
            else
                temp->next = current->next;
        }
    }
    return timeList;
}


/**
 * Busca por fecha y retorna un nodo de la lista de registros del tiempo
 *
 * Args:
 *   date (long int): La fecha que desea buscar.
 *   timeList (TimeRegis): es la lista de objetos TimeRegis
 *
 * Returns:
 *   Un puntero a un objeto TimeRegis.
 */
TimeRegis* TimeRegis::searchTime(long int date, TimeRegis* timeList){
    if(timeList == NULL)
        return NULL;
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

/**
 * Imprime la lista de registros de tiempo
 *
 * Args:
 *   timeList (TimeRegis): La lista de registros de tiempo.
 */
void TimeRegis:: print(TimeRegis* timeList){

    if(timeList == NULL)
        cout<< "\n\t-- LA LISTA DE REGISTROS DEL TIEMPO ESTA VACIA --\n";
    else{
        TimeRegis*temp = timeList;

        cout<<"\n\t   =========================================\n";
        cout<<"\t   ||    LISTA DE REGISTROS DEL TIEMPO    ||\n";
        cout<<"\t   =========================================\n";
        while(temp != NULL){
            cout<<"\n\t________________________________________________\n";
            cout<<"\n\tFECHA: "<<temp->dateToString(unixDateToDate(temp->getDateR()))<<endl;
            cout<<"\n\tPRECIPITACION: "<<temp->getPrecip()<<endl;
            cout<<"\n\tTEMPERATURA MAXIMA: "<<temp->getMaxTemp()<<endl;
            cout<<"\n\tTEMPERATURA MINIMA: "<<temp->getMinTemp()<<endl;
            cout<<"\n\tDIRECCION DEL VIENTO: "<<temp->getWinDirec()<<endl;
            cout<<"\n\tVELOCIDAD DEL VIENTO: "<<temp->getWinPsd()<<endl;
            cout<<"\n\tHUMEDAD: "<<temp->getHumidity()<<endl;
            cout<<"\n\tLLUVIA: ";
            if (temp->getRained()==true){
                cout<<"Si"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
            temp = temp->next;
        }
    }
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}


//Cargar datos quemados
/**
 * Agrega los datos a la lista de registros del tiempo
 *
 * Args:
 *   timeList (TimeRegis): La lista de objetos TimeRegis.
 *
 * Returns:
 *   la lista de tiempos.
 */
TimeRegis* TimeRegis::dataLoad(TimeRegis* timeList){

    timeList=add(1662012000,1245,21.4,10.4,24,89,25,true,timeList);//01 / 09 / 2022.
    timeList=add(1662098400,5345,25.0,11.4,29,73,26, true,timeList);//02 / 09 / 2022.
    timeList=add(1662184800,5571,15.9,5.6,31,69,29,true,timeList);//03 / 09 / 2022
    timeList=add(1662271200,5486,12.4,6.9,6,83,21,false,timeList);//04 / 09 / 2022.
    timeList=add(1662357600,4911,8.8,3.8,34,70,20, true,timeList);//05 / 09 / 2022.
    timeList=add(1662444000,2688,17.3,11.0,27,93,19,true,timeList);//06 / 09 / 2022
    timeList=add(1662530400,9875,31.5,15.3,19,60,34,false,timeList);//07 / 09 / 2022
    timeList=add(1662616800,1135,20.1,14.1,13,80,2,false,timeList);//08 / 09 / 2022
    timeList=add(1662703200,887,27.0,12.9,28,25,36,true,timeList);//09 / 09 / 2022.
    timeList=add(1662789600,235,23.3,16.5,25,60,32,false,timeList);//10 / 09 / 2022
    timeList=add(1568095200,235,23.3,16.5,25,60,32,true,timeList);// 10 / 09 / 2019
    timeList=add(1657432800,4567,25.3,12.5,23,0,32,false,timeList); // 10 / 07 / 2022.
    timeList=add(1577772000 ,235,23.3,16.5,25,60,32,true,timeList); //31 / 12 / 2019
    timeList=add(1577944800 ,235,23.3,16.5,25,60,32,true,timeList);//02 / 01 / 2020
    timeList=add(1581228000 ,325,23.3,16.5,25,60,32,true,timeList);//09 / 02 / 2020
    timeList=add(1580623200 ,568,23.3,16.5,25,60,32,false,timeList); //09 / 02 / 2020
    timeList=add(1583301600 ,785,23.3,16.5,25,60,32,true,timeList);// 04 / 03 / 2020
    timeList=add(1584338400 ,125,23.3,16.5,25,60,32,true,timeList); //16 / 03 / 2020
    timeList=add(1587621600 ,987,23.3,16.5,25,60,32,false,timeList); //23 / 04 / 2020
    timeList=add(1586152800 ,325,23.3,16.5,25,60,32,true,timeList);// 06 / 04 / 2020
    timeList=add(1588917600 ,147,23.3,16.5,25,60,32,true,timeList);// 08 / 05 / 2020
    timeList=add(1591768800 ,298,23.3,16.5,25,60,32,false,timeList);//10 / 06 / 2020
    timeList=add(1594533600 ,345,23.3,16.5,25,60,32,true,timeList);// 12 / 07 / 2020
    timeList=add(1596520800 ,369,23.3,16.5,25,60,32,false,timeList);// 4 / 08 / 2020
    timeList=add(1597557600 ,215,23.3,16.5,25,60,32,false,timeList);// 16 / 08 / 2020
    timeList=add(1598335200 ,896,23.3,16.5,25,60,32,true,timeList);// 25 / 08 / 2020
    timeList=add(1600236000 ,612,23.3,16.5,25,60,32,false,timeList);//16 / 09 / 2020
    timeList=add(1603065600 ,100,23.3,16.5,25,60,32,true,timeList);// 18 / 10 / 2020
    timeList=add(1605852000 ,362,23.3,16.5,25,60,32,true,timeList);// 20 / 11 / 2020
    timeList=add(1607493600 ,453,23.3,16.5,25,60,32,true,timeList); //09 / 12 / 2020



    cout<<"\n\t--- SE CARGARON LOS DATOS CORRECTAMENTE ---\n";
    return timeList;

}


/**
 * Toma un año, mes y día y devuelve el número de segundos desde la época.
 *
 * Args:
 *   year (int): El año, menos 1900.
 *   month (short): El mes del año (0-11)
 *   day (short): El día del mes (1-31)
 *
 * Returns:
 *   El número de segundos desde la Época (00:00:00 UTC, 1 de enero de 1970),
 *         medida en la zona horaria local.
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

/**
 * Convierte una estructura tm en una cadena
 *
 * Args:
 *   date (tm): La fecha que se convertirá en cadena.
 *
 * Returns:
 *   Una cadena con la fecha en el formato dd/mm/yyyy
 */
string TimeRegis::dateToString(tm*date){
    string ans = "";
    ans += to_string(date->tm_mday);
    ans += "/";
    ans += to_string(date->tm_mon);
    ans += "/";
    ans += to_string(date->tm_year);
    return ans;
}



/**
 * Toma una marca de tiempo de Unix y devuelve una estructura tm con la fecha y la hora.
 *
 * Args:
 *   seconds (long int): El número de segundos desde la época.
 *
 * Returns:
 *   Una estructura tm*
 */
tm* TimeRegis::unixDateToDate(long int seconds){

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




//---------------------------------SUBLISTA DE LLUVIA----------------------------

/**
 * Enlaza el nodo de lluvia con el nodo de registro del tiempo
 *
 * Args:
 *   idRain (string): El id de la lluvia
 *   date (long int): La fecha a buscar.
 *   rainList (Rain): es una lista de objetos de lluvia
 *   timeList (TimeRegis): es la lista de tiempos
 */
NodoSubRain*TimeRegis::linkendRainTime(string idRain, long int date,Rain* rainList,TimeRegis* timeList){

    TimeRegis* time = time->searchTime(date,timeList);
    Rain* rain = rain->searchRain(rainList,idRain);

    if(time == NULL){
        cout<<"\nNO EXISTE EL REGISTRO DEL TIEMPO"<<endl;
        return NULL;
    }
    if(rain == NULL){
        cout<<"\nNO EXISTE EL REGISTRO DE LLUVIA"<<endl;
        return NULL;
    }
    NodoSubRain* newNodo = new NodoSubRain();
    newNodo->linkRain = rain;
    newNodo->next = time->rainSublist;
    time->rainSublist = newNodo;
    return time->rainSublist;

}



/**
 * Imprime la sublista de lluvia
 *
 * Args:
 *   date (long int): es la fecha en formato unix
 *   timeList (TimeRegis): es un puntero al primer nodo de la lista de tiempos.
 *
 * Returns:
 *   un puntero al primer nodo de la lista.
 */
void TimeRegis::printSubRain(long int date,TimeRegis* timeList){

    TimeRegis * time =time->searchTime(date,timeList);

    if(time == NULL){
        cout<<"\n\tNO EXISTE ESTA FECHA EN EL REGISTRO\n";
        return;
    }
    else{
        NodoSubRain* temSub = time->rainSublist;
        if(temSub==NULL){
            cout<<"\n\tEN ESTA FECHA NO HAY REGISTRO DE LLUVIA.\n";
        }
        else{
            cout<<"\n\t   =========================================\n";
            cout<<"\t   ||   HISTORIAL DE LLUVIA EN "<<time->unixDateToDate(getDateR())->tm_year<<"   ||\n";
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

/**
 * Esta función se utiliza para contar el número de días en un año que llovió
 *
 * Args:
 *   year (int): el año que desea comprobar
 *   timeList (TimeRegis): es la lista de objetos TimeRegis
 */
void TimeRegis::periodInYear(int year, TimeRegis*timeList){
    TimeRegis*tempList = timeList;
    int cont = 0;
    int day = 0;
    string rain = "";
    while(tempList !=NULL){
        tm*date = tempList->unixDateToDate(tempList->getDateR());
        if(date->tm_year == year){
            if (tempList->getRained()){
                if(day == 0){
                    day = date->tm_mday;
                    rain = tempList->rainSublist->linkRain->getName();
                }
                else if((day == date->tm_mday-1)&& (rain == tempList->rainSublist->linkRain->getName())){

                    cont++;
                    day = date->tm_mday;


                }
                else{
                    rain = "";
                    cont = 0;
                }
            }
        }
        tempList = tempList->next;
    }
}







