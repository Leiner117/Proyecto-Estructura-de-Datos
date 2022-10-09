#include "Region.h"
#include "Place.h"
#include <string>
#include <iostream>
#include <map>
#include "TimeRegis.h"
using namespace std;


/*
    Autor: Karina Urbina
    Iniciado: 12/09/2022
    Ultima modificacion: 8/10/2022

*/


/**
 * Constructor de la clase region
 * Args:
 *   id (string): El id de la región.
 *   n (string): nombre de la región
 *   l (string): Ubicación
 */
Region::Region(string id,string n, string l){

    setIdRegion(id);
    setName(n);
    setLocacion(l);
    next=NULL;
    placeSublist=NULL;

}

//------------------- Metodos set-----------------------------------------
/**
 * Establece la identificacion de la region
 *
 * Args:
 *   id (string): El id de la región.
 */
void Region::setIdRegion(string id){
   idRegion = id;
}

/**
 * Esta función establece el nombre de la región.
 *
 * Args:
 *   n (string): El nombre de la región.
 */
void Region::setName(string n){
    name= n;
}

/**
 * Esta función establece la ubicación de la región.
 *
 * Args:
 *   l (string): ubicación
 */
void Region::setLocacion(string l){
    location= l;
}

//------------------- Metodos get-----------------------------------------
/**
 * Retorna la identificacion de la region
 *
 * Returns:
 *   Se devuelve el idRegion.
 */
string Region::getIdRegion(){
    return idRegion;
}

/**
 * Esta función devuelve el nombre de la región.
 *
 * Returns:
 *   El nombre de la región.
 */
string Region::getName(){
    return name;
}

/**
 * Esta función devuelve la ubicación de la región.
 *
 * Returns:
 *   La ubicación de la región.
 */
string Region::getLocation(){
    return location;
}

//************************** Funciones de la lista ******************

/**
 * Agrega una nueva region a la lista de regiones
 *
 * Args:
 *   id (string): la identificación de la región
 *   n (string): nombre de la región
 *   l (string): es la lista de regiones
 *   regionList (Region): es la lista de regiones
 */
Region* Region::add(string id,string n,string l,Region* regionList){

   // bool duplicate=validate(id,regionList);
    if(searchRegion(id,regionList)==NULL){

        Region* newNodo = new Region(id,n,l);
        newNodo->next = regionList;//se enlaza, conoce la direccion el inicio de la lista
        regionList = newNodo;
        cout << "\n\t\t-- SUS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE REGIONES --"<<endl;
    }
    else
        cout<<"\n\t\t+++ ERROR: EL NOMBRE INGRESADO YA SE ENCUENTRA EN LA LISTA +++\n";

    return regionList;

}



/**
 * Borra una region en especifico de la lista de regiones
 *
 * Args:
 *   id (string): El id de la región que se va a eliminar.
 *   regionList (Region): Esta es la lista de regiones.
 *
 * Returns:
 *   la lista de regiones.
 */
Region* Region::deleteRegion(string id,Region* regionList){

    if(regionList == NULL)
        cout<<"\n\tNO EXISTEN REGIONES REGISTRADAS... ";
    else{
        if(regionList->idRegion == id){//es el primero de la lista
            regionList= regionList->next;
        }
        else{
            Region* current = regionList;
            Region *temp = NULL;
            while((current!= NULL) && (current->idRegion!=id)){
                temp = current;
                current = current->next;
                cout<<"\n\tLA REGION SE BORRO CORECCTAMENTE";
            }
            if(current == NULL)
                cout<<"\n\tNO SE ENCONTRO LA REGION A ELIMINAR";
            else
                temp->next = current->next;
        }
    }
    return regionList;
}

/**
 * Modifica los datos de una region en especifico
 *
 * Args:
 *   data (string): el id de la región a modificar
 *   id (string): el id de la región a modificar
 *   n (string): nombre de la región
 *   l (string): ubicación
 *   regionList (Region): es la lista de regiones
 *
 * Returns:
 *   la lista de regiones.
 */
Region* Region::modify(string data, string id,string n, string l,Region* regionList){

    if(searchRegion(id,regionList)==NULL){
          if(regionList== NULL)
              cout<<"\n\tNO EXISTEN REGIONES REGISTRADAS... ";
        else{
            Region*temp = regionList;
            while (temp != NULL){
                if(temp->getIdRegion() == data){

                    temp->setIdRegion(id);
                    temp->setName(n);
                    temp->setLocacion(l);
                    cout<<"\n\tLA REGION SE MODIFICO CORRECTAMENTE";
                    return regionList;
                }
                temp = temp->next;
            }
            cout<<"\n\tLA REGION SOLICITADA NO SE ENCUENTRA REGISTRADA.";
        }

    }
    else{
        cout<<"\n+++ ADVERTENCIA: EL NOMBRE INGRESADO YA SE ENCUENTRA REGISTRADO +++\n";
    }
    return regionList;
}


/**
 * Busca una region en especifico en la lista de regiones
 *
 * Args:
 *   id (string): el id de la región que queremos buscar
 *   regionList (Region): es la lista de regiones
 *
 * Returns:
 *   La región con la identificación que se pasó.
 */
Region*Region::searchRegion(string id,Region*regionList){
    Region*temp =regionList;
    while(temp != NULL){

        if (temp->getIdRegion()==id){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}



/**
 * Imprime la lista de regiones
 *
 * Args:
 *   regionList (Region): es la lista de regiones
 */
void Region:: print(Region* regionList){

    if(regionList == NULL)
        cout<<"\n\t-- LA LISTA DE REGIONES ESTA VACIA --\n";
    else{
        cout<<"\n\t   =========================================\n";
        cout<<"\t   ||          LISTA DE REGIONES          ||\n";
        cout<<"\t   =========================================\n";
        Region*temp = regionList;
        while(temp != NULL){
            cout<<"\n\t________________________________________________\n";
            cout<<"\n\tID: "<<temp->getIdRegion()<<endl;
            cout<<"\n\tNOMBRE: "<<temp->getName()<<endl;
            cout<<"\n\tUBICACION: "<<temp->getLocation()<<endl;
            temp = temp->next;
        }
    }
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}

/**
 * Esta función agrega las regiones a la lista de regiones.
 *
 * Args:
 *   regionList (Region): La lista de regiones.
 *
 * Returns:
 *   Se devuelve regionList.
 */
Region* Region::dataLoad(Region* regionList){



    regionList=add("C","Caribe","Limon",regionList);
    regionList=add("PC","Pacifico Central","Puntarenas",regionList);
    regionList=add("T","Talamanca","Limon",regionList);
    regionList=add("UC","Upala y los Chiles","Alajuela",regionList);
    regionList=add("VC","Valle Central","San Jose",regionList);
    regionList=add("PN","Peninsula de Nicoya","Guanacaste",regionList);
    regionList=add("PS","Pacifico Sur","Puntarenas",regionList);
    regionList=add("NA","Norte Alta","Alajuela",regionList);
    regionList=add("CGT","Cordillera de Guanacaste y Tilaran","Guanacaste",regionList);
    regionList=add("CS","Caribe Sur","Limon",regionList);


    return regionList;
}
//---------------------------------SUBLISTA DE LUGARES----------------------------

/**
 * Relaciona el lugar con la region
 *
 * Args:
 *   idRegion (string): La identificación de la región a la que desea vincular el lugar.
 *   namePlace (string): nombre del lugar a vincular
 *   placeList (Place): es un puntero al primer nodo de la lista de lugares
 *   regionList (Region): es la lista de regiones
 */
NodoSubPlace* Region::linkendPlaceRegion(string idRegion, string namePlace,Place* placeList,Region* regionList){

    Region* reg = reg->searchRegion(idRegion,regionList);
    Place* plc = plc->searchPlace(namePlace,placeList);

    if(plc == NULL){
        cout<<"\n\tNO EXISTE EL LUGAR";
        return NULL;
    }
    if(reg == NULL){
        cout<<"\n\tNO EXISTE LA REGION";
        return NULL;
    }

    NodoSubPlace* newNodo = new NodoSubPlace();
    newNodo->linkPlace = plc;
    newNodo->next = reg->placeSublist;
    reg->placeSublist = newNodo;
    return reg->placeSublist;

}



/**
 * Imprime la sublista de lugares de una región
 *
 * Args:
 *   id (string): es el id de la región
 *   regionList (Region): es la lista de regiones
 */
void Region::printSublistPlace(string id,Region* regionList){

    Region * reg =reg->searchRegion(id,regionList);

    if(reg == NULL){
        cout<<"\n\tNO EXISTE LA REGION";
        return;
    }
    else{
        NodoSubPlace* temSub = reg->placeSublist;
        if(temSub==NULL){
            cout<<"\n\t"<<reg->getName()<<"NO TIENE LUGARES REGISTRADOS\n";
        }
        else{
            cout<<"\n\t   =========================================\n";
            cout<<"\t   ||   Lugares de la Region "<<reg->getName()<<"   ||\n";
            cout<<"\t   =========================================\n";
            NodoSubPlace* temSub = reg->placeSublist;

            while(temSub != NULL){
                cout<<"\n\t________________________________________________\n";
                cout<<"\n\tNOMBRE: "<<temSub->linkPlace->getName();
                cout<<"\n\tPOBLACION: "<<temSub->linkPlace->getPopulation();
                cout<<"\n\tSUPERFICIE: "<<temSub->linkPlace->getSquareMeters();
                temSub = temSub->next;

            }
            cout<<"\n\t________________________________________________\n";
        }
    }

}


/**
 * Esta función imprime el promedio de las variables climáticas en una región en un período determinado.
 *
 * Args:
 *   idReg (string): El id de la región
 *   year1 (int): el primer año a considerar
 *   year2 (int): el año para terminar la búsqueda
 *   listReg (Region): es la lista de regiones
 */
void Region::printVarWeather(string idReg,int year1, int year2,Region*listReg){
    float promPreci, promMaxTemp,promMinTemp,promDayRain;
    //int contPreci,contMaxTemp,contMinTemp,contDayRain,contDays;
    int cont = 0;

    Region*reg = searchRegion(idReg, listReg);
    NodoSubPlace*subList =reg->placeSublist;
    while (subList != NULL){
        if (subList->linkPlace->timeRegiSublist != NULL){
            NodoSubTime* timeList= subList->linkPlace->timeRegiSublist;
            string name = subList->linkPlace->getName();
            while(timeList != NULL){
                if (timeList->linkTime->unixDateToDate(timeList->linkTime->getDateR())->tm_year >= year1 && timeList->linkTime->unixDateToDate(timeList->linkTime->getDateR())->tm_year <= year2){

                    promPreci = promPreci+ timeList->linkTime->getPrecip();
                    promMaxTemp = promMaxTemp + timeList->linkTime->getMaxTemp();
                    promMinTemp = promMinTemp + timeList->linkTime->getMinTemp();
                    if (timeList->linkTime->getRained() == true){
                        promDayRain++;
                    }
                    cont++;
                }
                timeList = timeList->next;
            }

        }
        subList = subList->next;

    }

    cout<<"\n\t   =========================================================================\n";
    cout<<"\t   ||    PROMEDIO DE LAS VARIABLES CLIMATOLOGICAS EN " <<reg->getName()<<"           ||\n";
    cout<< "           ||                    En el periodo de "<<year1<<" a "<<year2<<"                     ||\n";
    cout<<"\t   =========================================================================\n";

    cout<<"\n\t________________________________________________\n";
    cout<< "\n\tPROMEDIO DE PRECIPITACION: "<<(promPreci*cont)/100<<endl;
    cout<< "\n\tPROMEDIO DE MAXIMA TEMPERATURA: "<<(promMaxTemp*cont)/100<<endl;
    cout<< "\n\tPROMEDIO DE MINIMA TEMPERATURA: "<<(promMinTemp*cont)/100<<endl;
    cout<< "\n\tPROMEDIO DE DIAS DE LLUVIA: "<< (float)(promDayRain*cont)/100<<endl;
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPRECIONE CUALQUIER TECLA PARA CONTINUAR...";
    cin.ignore();
    cin.get();

}



/**
 * Calcula la precipitación media mensual de una región en un año determinado
 *
 * Args:
 *   year (int): El año que desea buscar.
 *   id (string): Id de la región
 *   regionList (Region): Puntero a la primera región de la lista
 */
void Region::monthlyRain(int year,string id,Region* regionList){
    system("cls");

    string months[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    map <string, float> precipMonth;
    int month =0;
    int days = 0;
    float totalPrecip=0;
    int cont=0;

    Region* reg = reg->searchRegion(id,regionList);
    NodoSubTime*time;

        cout<<"\n\t   =========================================\n";
        cout<<"\t   ||   PRECIPITACION MENSUAL PROMEDIO    ||\n";
        cout<<"\t   ||          "<<reg->getName()<<" "<<year<<"            ||\n";
        cout<<"\t   =========================================\n";

    while(reg->placeSublist!=NULL){

        time= reg->placeSublist->linkPlace->timeRegiSublist;

        if(time==NULL){

            cout<<"\n"<<reg->placeSublist->linkPlace->getName()<<" NO TIENE REGISTROS DEL TIEMPO EN ESTA FECHA"<<endl;
        }
        else{

            while(time!=NULL){

                if(time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_year == year){

                    if(time->linkTime->getRained()){

                        month = time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon;

                        if(time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon==time->linkTime->next->unixDateToDate(time->linkTime->next->getDateR())->tm_mon){
                            totalPrecip = totalPrecip + time->linkTime->getPrecip();
                            days++;
                        }
                        else{
                            totalPrecip = totalPrecip + time->linkTime->getPrecip();
                            days++;
                            precipMonth[months[month-1]] = precipMonth[months[month-1]]+(totalPrecip/days);
                            cont++;
                        }
                    }
                }
                time=time->next;
                totalPrecip=0;
                days=0;

            }
        }
        reg->placeSublist= reg->placeSublist->next;
    }

    if(reg->placeSublist==NULL){

        while(month>0){

            cout<<"\n\t________________________________________________\n";
            cout<<"\n\tMES: "<<months[month-1]<<endl;
            cout<<"\n\tPRECIPITACION PROMEDIO: "<<precipMonth[months[month-1]]/cont<<endl;
            month--;

        }
    }
}
