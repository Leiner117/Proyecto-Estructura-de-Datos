#include "Place.h"
#include "TimeRegis.h"
#include <string>
#include <iostream>
using namespace std;

/*
    Autor: Karina Urbina
    Iniciado: 12/09/2022
    Ultima modificacion: 7/10/2022

*/

/**
 * Esta función es un constructor que inicializa el nombre, población, metros cuadrados, next y timeRegiSublist de un
 * objeto Place.
 *
 * Args:
 *   n (string): nombre del lugar
 *   p (int): población
 *   meters (float): los metros cuadrados del lugar
 */
Place::Place(string n,int p,float meters){

    setName(n);
    setPopulation(p);
    setSquareMeters(meters);
    next= NULL;
    timeRegiSublist=NULL;

}



/**
 * Esta función establece el nombre del lugar.
 *
 * Args:
 *   n (string): El nombre del lugar.
 */
void Place::setName(string n){
    name=n;
}

/**
 *
 * Esta función establece la población del objeto Place.
 *
 * Args:
 *   p (int): La población del lugar
 */
void Place::setPopulation(int p){
    population= p;
}

/**
 * Esta función establece lo metros cuadrados de un lugar.
 *
 * Args:
 *   meters (float): Los metros cuadrados del lugar.
 */
void Place::setSquareMeters(float meters){
    squareMeters= meters;
}


/**
 * Esta función devuelve el nombre del Lugar.
 *
 * Returns:
 *   El nombre del lugar.
 */
string Place::getName(){
    return name;
}

/**
 * Funcion que devuelve la población del lugar.
 *
 * Returns:
 *   La población del lugar.
 */
int Place::getPopulation(){
    return population;
}

/**
 * Esta función devuelve los metros cuadrados del lugar
 *
 * Returns:
 *   Los metros cuadrados del lugar.
 */
float Place::getSquareMeters(){
    return squareMeters;
}

//************************** Funciones de la lista ******************


/**
 * Añade un nuevo lugar a la lista de lugares
 *
 * Args:
 *   n (string): Nombre del lugar
 *   p (int): Poblacion del lugar
 *   meters (float): Metros cuadrados del lugar .
 *   placeList (Place): Lista de lugares
 *
 * Returns:
 *   Lista de lugares.
 */
Place* Place::add(string n,int p,float meters,Place* placeList){

    if(searchPlace(n,placeList)==NULL){

        Place* newNodo = new Place(n,p,meters);

        if(placeList == NULL){
            placeList = newNodo;
            newNodo->next = placeList;
        }
        else{
            newNodo->next =placeList;
            Place* temp = placeList;
            while(temp->next != placeList)
                temp = temp->next;
            temp->next = newNodo;
            placeList = newNodo;
        }
        cout << "\n\t\t-- LOS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE LUGARES --"<<endl;
    }
    else{
        cout<<"\n\t+++ Advertencia: El nombre ingresado ya esta en la lista +++\n";
    }
    return placeList;
}


/**
 * Modifica un lugar en la lista
 *
 * Args:
 *   data (string): El nombre del lugar que desea modificar.
 *   n (string): Nuevo nombre del lugar
 *   p (int): Nueva poblacion
 *   m (float): Nuevos metros cuadrados
 *   placeList (Place): Lista de lugares
 *
 * Returns:
 *   La lista de lugares
 */
Place* Place::modify(string data, string n,int p, float m,Place*placeList){

     if(searchPlace(n,placeList)==NULL){
        if(placeList== NULL)
            cout<<"\n\tLA LISTA DE LUGARES ESTA VACIA";
        else{
            Place*temp = placeList;
            while (temp != NULL){
                if(temp->getName() == data){
                    temp->setName(n);
                    temp->setPopulation(p);
                    temp->setSquareMeters(m);
                    return placeList;//me salgo de la fucnion
                }
                temp = temp->next;
            }
            cout<<"\n\tNO SE ENCONTRO EL DATO";
        }
    }
    else{
        cout<<"\n+++ Advertencia: El nombre ingresado ya existe en la lista +++\n";
    }
    return placeList;
}


/**
 * Funcion que elimina un lugar de la lista de lugares
 *
 * Args:
 *   n (string): El nombre del lugar que se va a eliminar.
 *   placeList (Place): La lista de lugares.
 *
 * Returns:
 *   Lista de lugares.
 */
Place* deletePlace(string n,Place* placeList){

    if(placeList == NULL)
        cout<<"\nLista vacia, no se puede borrar....";
    else{
        if(placeList->getName() == n){//es el primero de la lista
            placeList= placeList->next;
        }
        else{
            Place* current = placeList;
            Place *temp = NULL;
            while((current!= NULL) && (current->getName()!=n)){
                temp = current;
                current = current->next;
            }
            if(current == NULL)
                cout<<"\nNo se encontro el nodo";
            else
                temp->next = current->next;
        }
    }
    return placeList;
}


/**
 * Esta función busca un lugar en la lista de lugares
 *
 * Args:
 *   n (string): El nombre del lugar que desea buscar.
 *   placeList (Place): La lista de lugares
 *
 * Returns:
 *   El lugar en la lista de punteros si encuentra el lugar o null si no lo encuentra
 */
Place* Place::searchPlace(string n, Place* placeList){

     Place *temp;
     if(placeList != NULL){
          temp = placeList;
          do{
               if(temp->getName() == n){
                   return temp;
               }
               else{
                   temp = temp->next;
               }
          }while(temp!= placeList);
     }
     else
        return NULL;
}



/**
 * Imprime la lista de lugares
 *
 * Args:
 *   placeList (Place): Lista de lugares
 */
void Place:: print(Place* placeList){

    if(placeList== NULL)
        cout<<"\n\t-- LA LISTA DE LUGARES ESTA VACIA --\n";
    else{
        Place*temp = placeList;
        cout<<"\n\t   =========================================\n";
        cout<<"\t   ||          LISTA DE LUGARES           ||\n";
        cout<<"\t   =========================================\n";
        do{
            cout<<"\n\t________________________________________________\n";
            cout<<"\n\tNOMBRE: "<<temp->getName()<<endl;
            cout<<"\n\tPOBLACION: "<<temp->getPopulation()<<endl;
            cout<<"\n\tMETROS CUADRADOS: "<<temp->getSquareMeters()<<endl;
            temp= temp->next;
        } while(temp!= placeList);
    }
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}


/**
 * Crea una lista de lugares y la retorna.
 *
 * Args:
 *   placeList (Place): La lista de lugares.
 *
 * Returns:
 *   Lista de lugares.
 */
Place* Place::dataLoad(Place* placeList){

    placeList=add("San Carlos",163745,3347.98,placeList);
    placeList=add("Upala",43953,1.581,placeList);
    placeList=add("Naranjo",42713,126.6,placeList);
    placeList=add("Liberia",4548,23265.6,placeList);
    placeList=add("Palmares",34716,38.06,placeList);
    placeList=add("Escazu",56509,34.49,placeList);
    placeList=add("Los Chiles",23735,504.2,placeList);
    placeList=add("Grecia",13262,3221.6,placeList);
    placeList=add("Sarapiqui",57147,2140.54,placeList);
    placeList=add("Talamanca",30712,504.2,placeList);
    placeList=add("Guatuso",15508,1580.67,placeList);

    return placeList;

}

//---------------------------------SUBLISTA DE REGISTROS DEL TIEMPO----------------------------

/**
 * *Funcion que enlaza registros del tiempo con un lugar determinado
 *
 * Args:
 *   namePlace (string): Nombre del lugar
 *   date (long int): Fecha del registro del tiempo
 *   timeList (TimeRegis): Lista de registros del tiempo
 *   placeList (Place): Lista de lugares
 *
 * Returns:
 *   Sublista de registros tiempo de un lugar.
 */
NodoSubTime* Place::linkendTimePlace(string namePlace, long int date,TimeRegis* timeList,Place* placeList){

    Place* plc = plc->searchPlace(namePlace,placeList);
    TimeRegis* timeR = timeR->searchTime(date,timeList);

    if(plc == NULL){
        cout<<"\n\tNO EXISTE EL LUGAR"<<endl;
        return NULL;
    }
    if(timeR == NULL){
        cout<<"\n\tNO EXISTE EL REGISTRO DEL TIEMPO"<<endl;
        return NULL;
    }

    NodoSubTime* newNodo = new NodoSubTime();
    if (plc->timeRegiSublist == NULL){
        plc->timeRegiSublist = newNodo;
        newNodo->linkTime = timeR;
    }
    else if (date<plc->timeRegiSublist->linkTime->getDateR()){
        newNodo->linkTime = timeR;
        newNodo->next = plc->timeRegiSublist;
        plc->timeRegiSublist = newNodo;
    }else{
        newNodo->linkTime = timeR;
        NodoSubTime*temp = plc->timeRegiSublist;
        NodoSubTime*ant;
        while((temp!=NULL)&&(date>temp->linkTime->getDateR())){
            ant = temp;
            temp = temp->next;
        }
        ant->next = newNodo;
        if (temp != NULL){
            newNodo->next = temp;
        }
    }
    return plc->timeRegiSublist;
}



/**
 * Esta función imprime los registros del tiempo de un lugar.
 *
 * Args:
 *   namePlace (string): Nombre del lugar
 *   placeList (Place): Lista de lugares
 *
 */
void Place::printSubTimePlace(string namePlace,Place* placeList){

    Place * plc = plc->searchPlace(namePlace,placeList);

    if(plc == NULL){
        cout<<"\n\tNO EXISTE EL LUGAR";
        return;
    }
    else{
        NodoSubTime* temSub = plc->timeRegiSublist;
        if(temSub==NULL){
            cout<<"\n\t"<<plc->getName()<<" no tiene registros del tiempo\n";
        }
        else{
            cout<<"\n\t   =========================================\n";
            cout<<"\t   ||   Registros del tiempo en "<<plc->getName()<<"   ||\n";
            cout<<"\t   =========================================\n";
            while(temSub != NULL){
                cout<<"\n\t________________________________________________\n";
                cout<<"\n\tFECHA: "<<temSub->linkTime->dateToString(temSub->linkTime->unixDateToDate(temSub->linkTime->getDateR()));
                cout<<"\n\tPRECIPITACION: "<<temSub->linkTime->getPrecip();
                cout<<"\n\tTEMPERATURA MINIMA: "<<temSub->linkTime->getMinTemp();
                cout<<"\n\tTEMPERATURA MAXIMA: "<<temSub->linkTime->getMaxTemp();
                cout<<"\n\tDIRECCION DEL VIENTO: "<<temSub->linkTime->getWinDirec();
                cout<<"\n\tVELOCIDAD DEL VIENTO: "<<temSub->linkTime->getWinPsd();
                cout<<"\n\tHUMEDAD: "<<temSub->linkTime->getHumidity();
                if (temSub->linkTime->getRained()==true){
                    cout<<"\n\tLLUVIA: SI";
                }
                else{
                    cout<<"\n\tLLUVIA: NO";
                }

                temSub = temSub->next;

            }
            cout<<"\n\t________________________________________________\n";
        }

    }
}




/**
 * Imprime la precipitación media mensual de un año determinado
 *
 * Args:
 *   year (int): El año en el que desea ver la precipitación mensual promedio de un lugar.
 *   namePlace (string): El nombre del lugar.
 *   placeList (Place): lista de lugares
 */
void Place::monthlyRain(int year,string namePlace,Place* placeList){

    string months[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    int month =0;
    int days = 0;

    Place* plc = plc->searchPlace(namePlace,placeList);
    NodoSubTime*time = plc->timeRegiSublist;

    float totalPrecip = 0;

        cout<<"\n\t   =========================================\n";
        cout<<"\t   ||   PRECIPITACION MENSUAL PROMEDIO    ||\n";
        cout<<"\t   ||         "<<plc->getName()<<" "<<year<<"             ||\n";
        cout<<"\t   =========================================\n";

    while (time !=  NULL){

        if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_year == year){

            if (time->linkTime->getRained()){

                month = time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon;

                if(time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon==time->linkTime->next->unixDateToDate(time->linkTime->next->getDateR())->tm_mon){

                    totalPrecip = totalPrecip + time->linkTime->getPrecip();
                    days++;
                }
                else{
                    totalPrecip = totalPrecip + time->linkTime->getPrecip();
                    days++;
                    cout<<"\n\t________________________________________________\n";
                    cout<<"\n\tMES: "<<months[month-1]<<endl;
                    cout<<"\n\tPRECIPITACION PROMEDIO: "<<(totalPrecip/days)<<endl;
                    totalPrecip=0;
                    days=0;
                }
            }
        }
        time = time->next;
    }
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}

/**
 * Imprime el porcentaje de cada condicion climatica por cada mes de un año dado
 *
 * Args:
 *   year (int): El año que desea imprimir el porcentaje de la condicion climatica.
 *   namePlace (string): El nombre del lugar.
 *   pList (Place): Lista de lugares
 */
void Place::printPercentageRain(int year,string namePlace,Place*pList){
    string months[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    int month =0;
    int cont = 0;
    float promExtremeRain = 0, promRainy = 0,promNormal = 0,promDry = 0,promExtremeDry = 0;
    Place*place = pList->searchPlace(namePlace,pList);
    NodoSubTime*timeList = place->timeRegiSublist;
    cout<<"\n\t   =============================================\n";
    cout<<"\t   || Clasificacion de lluvia para "<<place->getName()+" ||\n";
    cout<<"\t   =============================================\n";
    while (timeList !=  NULL){
        if (timeList->linkTime->unixDateToDate(timeList->linkTime->getDateR())->tm_year == year){
            if (timeList->linkTime->getRained()){
                if (month == 0){
                    month = timeList->linkTime->unixDateToDate(timeList->linkTime->getDateR())->tm_mon;
                }

                if((month != timeList->linkTime->unixDateToDate(timeList->linkTime->getDateR())->tm_mon)||timeList->next==NULL){
                    int flag = 1;
                    while(flag !=0){
                        if(flag ==2){
                            NodoSubRain*rainList= timeList->linkTime->rainSublist;
                            cont = 0;
                            promExtremeDry = 0;
                            promDry = 0;
                            promNormal = 0;
                            promRainy = 0;
                            promExtremeRain = 0;
                            if (rainList != NULL){
                                cont++;
                                if (rainList->linkRain->getName() == "Extremo lluvioso"){
                                    promExtremeRain++;
                                }
                                else if (rainList->linkRain->getName() == "Extremo seco"){
                                    promExtremeDry++;
                                }
                                else if (rainList->linkRain->getName() == "Seco"){
                                    promDry++;
                                }
                                else if (rainList->linkRain->getName() == "Normal"){
                                    promNormal++;
                                }
                                else if (rainList->linkRain->getName() == "Lluvioso"){
                                    promRainy++;
                                }
                            }
                        }
                        cout<<"\n\t________________________________________________\n";
                        cout<<"\n\tMES: "<<months[month-1]<<endl;
                        cout<<"\n\tEXTREMO LLUVIOSO: "<<(promExtremeRain*100)/cont<<"%"<<endl;
                        cout<<"\n\tLLUVIOSO: "<<(promRainy*100)/cont<<"%"<<endl;
                        cout<<"\n\tNORMAL: "<<(promNormal*100)/cont<<"%"<<endl;
                        cout<<"\n\tSECO: "<<(promDry*100)/cont<<"%"<<endl;
                        cout<<"\n\tEXTREMO SECO : "<<(promExtremeDry*100)/cont<<"%"<<endl;
                        month = timeList->linkTime->unixDateToDate(timeList->linkTime->getDateR())->tm_mon;
                        if(timeList->next != NULL){
                            if( (timeList->next->linkTime->next->unixDateToDate(timeList->linkTime->getDateR())->tm_mon!=timeList->linkTime->next->unixDateToDate(timeList->linkTime->getDateR())->tm_mon)&&flag ==1){
                                flag = flag+1;
                            }
                            else{
                                flag = 0;
                            }
                        }
                        else{
                            if (flag == 1){
                                flag = flag+1;
                            }
                            else{
                                flag = 0;
                            }

                        }
                    }
                    flag = 1;
                    cont = 0;
                    promExtremeDry = 0;
                    promDry = 0;
                    promNormal = 0;
                    promRainy = 0;
                    promExtremeRain = 0;

                }

                NodoSubRain*rainList= timeList->linkTime->rainSublist;
                if (rainList != NULL){
                    cont++;
                    if (rainList->linkRain->getName() == "Extremo lluvioso"){
                        promExtremeRain++;
                    }
                    else if (rainList->linkRain->getName() == "Extremo seco"){
                        promExtremeDry++;
                    }
                    else if (rainList->linkRain->getName() == "Seco"){
                        promDry++;
                    }
                    else if (rainList->linkRain->getName() == "Normal"){
                        promNormal++;
                    }
                    else if (rainList->linkRain->getName() == "Lluvioso"){
                        promRainy++;
                    }
                }


            }
        }
        timeList = timeList->next;
    }
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}


/**
 * Lista simple que almacena los extremos del clima
 * @property {int} month - Mes del año
 * @property {int} extremeRain - Mayor cantidad de lluvia en un mes
 * @property {int} extremeDry - Mayor cantidad de extremos secos en un mes
 * @property {tempList} next - Puntero al siguiente nodo en la lista
 */
struct tempList{
    int month;
    int extremeRain;
    int extremeDry;
    tempList*next = NULL;
    tempList(int m,int rain,int dry){
        month = m;
        extremeRain = rain;
        extremeDry = dry;
        next = NULL;
    }
};

/**
 * Esta función busca un mes en la lista y devuelve el puntero al nodo si lo encuentra
 *
 * Args:
 *   list1 (tempList): Lista que desea buscar
 *   month (int): Mes que desea buscar
 *
 * Returns:
 *   Lista con los extremos del clima
 */


/**
 * Imprime la cantidad de extremos del clima de lugar determinado para un año especifico.
 *
 * Args:
 *   placeName (string): El nombre del lugar que desea buscar.
 *   year (int): El año en el que se desea buscar los extremos del clima.
 *   pList (Place): Lista de lugares
 */
void Place::monthlyRainfallExtremes(string placeName,int year,Place*pList){

    Place*localPlace = pList->searchPlace(placeName,pList);
    NodoSubTime*listTime = localPlace->timeRegiSublist;

    int month = 0;
    int extremeRain = 0;
    int extremeDry = 0;
    tempList*finalList = NULL;
    bool flag = false;

    while(listTime != NULL){
        tm*date1 = listTime->linkTime->unixDateToDate(listTime->linkTime->getDateR());
        if(date1->tm_year== year){
            if (listTime->linkTime->getRained()){
                int localMonth = date1->tm_mon;
                NodoSubTime*tmpList = listTime;
                while(tmpList !=NULL){
                    if(tmpList->linkTime->unixDateToDate(tmpList->linkTime->getDateR())->tm_year == year){
                        if(localMonth == tmpList->linkTime->unixDateToDate(tmpList->linkTime->getDateR())->tm_mon){
                            if(tmpList->linkTime->getRained()){

                                    if(tmpList->linkTime->rainSublist->linkRain->getName() == "Extremo lluvioso"){
                                        extremeRain++;
                                 }
                                    if(tmpList->linkTime->rainSublist->linkRain->getName() == "Extremo Seco"){
                                        extremeDry++;
                                }
                            }
                        }
                    }
                    tmpList = tmpList->next;
                }
                tempList*newMonth = new tempList(localMonth, extremeRain, extremeDry);
                if(finalList == NULL){
                    finalList = newMonth;
                    extremeRain = 0;
                    extremeDry = 0;
                }else{
                    newMonth->next = finalList;
                    finalList = newMonth;
                    extremeRain = 0;
                    extremeDry = 0;
                }
            }
        }
        listTime = listTime->next;
    }
    tempList*finalRain = NULL;
    tempList*finalDry = NULL;
    tempList*tempList = finalList;
    while(finalList!=NULL){
        if (finalRain == NULL && finalDry == NULL){
            finalRain = finalList;
            finalDry = finalList;
        }
        if (finalRain->extremeDry < finalList->extremeRain){
            finalRain = finalList;
        }
        if (finalDry->extremeDry < finalList->extremeDry){
            finalDry = finalList;
        }
        finalList = finalList->next;
    }
    bool flagRain = false,flagDry = false;

    cout<<"\n\t   =========================================\n";
    cout<<"\t   ||   MESES CON MAS EXTREMOS DEL CLIMA    ||\n";
    cout<<"\t   =========================================\n";
   while(tempList !=NULL){

       if(finalRain->extremeRain>0){
           if (finalRain->extremeRain == tempList->extremeRain){
               cout<<"\n\t________________________________________________\n";
               cout<<"\tMES: "<<tempList->month<<endl;
               cout<<"\tEXTREMOS LLUVIOSOS: "<<tempList->extremeRain;
               cout<<"\n\t________________________________________________\n";
                flagRain = true;
           }
       }

       if(finalDry->extremeDry>0){
           if(finalDry->extremeDry == tempList->extremeDry){
               cout<<"\n\t________________________________________________\n";
               cout<<"\tMES: "<<tempList->month<<endl;
               cout<<"\tEXTREMOS SECOS: "<<tempList->extremeDry;
               cout<<"\n\t________________________________________________\n";
               flagDry = true;
           }
       }
       tempList = tempList->next;

   }
   if(!flagRain){
       cout<<"\n\tNO HAY REGISTRO DE EXTREMOS LLUVIOSOS"<<endl;

   }
   if(!flagDry){
       cout<<"\n\tNO HAY REGISTRO DE EXTREMOS SECOS"<<endl;
   }
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}




/**
 * Imprime el número de días de lluvia en un año determinado para un lugar especifico
 *
 * Args:
 *   year (int): El año que desea buscar.
 *   namePlace (string): El nombre del lugar que desea buscar.
 *   pList (Place): Lista de lugares
 */
void Place::printRainyDays(int year,string namePlace,Place*pList){
    string months[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    int month =0;
    int days = 0;

    Place* plc = plc->searchPlace(namePlace,pList);
    NodoSubTime*time = plc->timeRegiSublist;

    cout<<"\n\n\t   =============================================\n";
    cout<<"\t   ||      Dias lluviosos en "<<plc->getName()+"       ||\n";
    cout<<"\t   =============================================\n";

    while (time !=  NULL){

        if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_year == year){
            if (time->linkTime->getRained()){
                if (month == 0) {
                    month = time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon;
                    //days++;
                }
                if(month == time->linkTime->next->unixDateToDate(time->linkTime->getDateR())->tm_mon){
                    days++;

                }if((month != time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon)||time->next==NULL){
                    int flag = 1;
                    while(flag !=0){
                        cout<<"\n\t________________________________________________\n";
                        cout<<"\n\tMES: "<<months[month-1]<<endl;
                        cout<<"\n\tDIAS LLUVIOSOS: "<<days<<endl;
                        int month1 = month;
                        month = time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon;
                        days = 1;
                        if(time->next != NULL){
                            if( (time->next->linkTime->next->unixDateToDate(time->linkTime->getDateR())->tm_mon!=time->linkTime->next->unixDateToDate(time->linkTime->getDateR())->tm_mon)&&flag ==1){
                                flag = flag+1;
                            }
                            else{
                                flag = 0;
                            }
                        }else{
                            if(month != month1){
                                if (flag == 1){
                                    flag = flag+1;
                                }
                                else{
                                    flag = 0;
                                }
                            }
                            else{
                                flag = 0;
                            }
                        }
                    }
                    flag = 1;

                }
            }
        }
        time = time->next;
    }
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}

/**
 * Busca la temperatura máxima y mínima de un año determinado en un lugar determinado
 *
 * Args:
 *   year (int): El año que desea buscar.
 *   namePlace (string): El nombre del lugar que desea buscar.
 *   placeList (Place): Lista de lugares
 */
void Place::extremeTemp(int year,string namePlace,Place*placeList){
    Place*place = placeList->searchPlace(namePlace,placeList);
    NodoSubTime*timeList = place->timeRegiSublist;
    int month = 0;
    float temp1 = 0,temp2 = 0;
    while(timeList != NULL){
        if(timeList->linkTime->getRained()){
            tm*date = timeList->linkTime->unixDateToDate(timeList->linkTime->getDateR());
            if(date->tm_year == year){

                month = date->tm_mon;
                NodoSubTime*tempList = timeList;
                while(tempList !=NULL){
                    tm*date2 = tempList->linkTime->unixDateToDate(tempList->linkTime->getDateR());
                    if(timeList->linkTime->getRained()){
                        if(date->tm_year==year){
                            if(date->tm_mon>=date2->tm_mon){
                                if(date->tm_mon == date2->tm_mon){
                                    if(temp1 ==0 && temp2 == 0){
                                        temp1 = tempList->linkTime->getMaxTemp();
                                        temp2 = tempList->linkTime->getMinTemp();

                                    }else{
                                        if(temp1 < tempList->linkTime->getMaxTemp()){
                                            temp1 = tempList->linkTime->getMaxTemp();
                                        }
                                        if(temp2 < tempList->linkTime->getMinTemp()){
                                            temp2 = tempList->linkTime->getMinTemp();
                                        }
                                    }
                                }else{
                                    if(date->tm_mon < date2->tm_mon){
                                        break;
                                    }
                                }
                            }

                        }
                    }
                    tempList = tempList->next;
                }
            }
        }
        if(month !=0){
            cout<<month<<endl;
            cout<<"TEMPERATURA MAXIMA: "<<temp1<<endl;
            cout<<"TEMPERATURA MINIMA: "<<temp2<<endl;
        }

        timeList = timeList->next;
    }
}


