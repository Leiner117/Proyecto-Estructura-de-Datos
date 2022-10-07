#include "Region.h"
#include "Place.h"
#include <string>
#include <iostream>
#include <map>
#include "TimeRegis.h"
using namespace std;

Region::Region(string id,string n, string l){

    setIdRegion(id);
    setName(n);
    setLocacion(l);
    next=NULL;
    placeSublist=NULL;

}

//------------------- Metodos set-----------------------------------------
void Region::setIdRegion(string id){
   idRegion = id;
}

void Region::setName(string n){
    name= n;
}

void Region::setLocacion(string l){
    location= l;
}

//------------------- Metodos get-----------------------------------------
string Region::getIdRegion(){
    return idRegion;
}

string Region::getName(){
    return name;
}

string Region::getLocation(){
    return location;
}

//************************** Funciones de la lista ******************


//Verifica si el elemento a agregar ya existe en la lista
bool Region::validate(string id, Region* regionList){
    if(regionList == NULL)
        return false;
    else{
        Region*temp = regionList;
        while(temp != NULL){
            if(temp->getIdRegion() == id){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
}


//Agregar al Inicio
Region* Region::add(string id,string n,string l,Region* regionList){

   // bool duplicate=validate(id,regionList);
    if(searchRegion(id,regionList)==NULL){

        Region* newNodo = new Region(id,n,l);
        newNodo->next = regionList;//se enlaza, conoce la direccion el inicio de la lista
        regionList = newNodo;
    }
    else
        cout<<"\n+++ Advertencia: El nombre ingresado ya esta en la lista +++\n";

    return regionList;

}


//Borra UN ELEMENTO de la lista
Region* Region::deleteRegion(string id,Region* regionList){

    if(regionList == NULL)
        cout<<"\nLista vacia, no se puede borrar....";
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
                cout<<"\nSe borro correctamente";
            }
            if(current == NULL)
                cout<<"\nNo se encontro el nodo";
            else
                temp->next = current->next;
        }
    }
    return regionList;
}

//Borra toda la lista
Region* Region::deleteAllRegion(Region* regionList) {
    if(regionList != NULL) {
        Region *temp, *current;
        current = regionList->next;
        while(current != regionList) {
            temp = current->next;
            free(current);
            current = temp;
        }
        free(regionList);
        regionList = NULL;
    }
    cout<<"Todos los nodos han sido borrados exitosamente\n";
    return regionList;
}

//Modifica un elemento especifico de la lista
Region* Region::modify(string data, string id,string n, string l,Region* regionList){

    //bool duplicate=validate(id,regionList);

    if(searchRegion(id,regionList)==NULL){
          if(regionList== NULL)
            cout<<"\nLa lista no tiene datos.....";
        else{
            Region*temp = regionList;
            while (temp != NULL){
                if(temp->getIdRegion() == data){

                    temp->setIdRegion(id);
                    temp->setName(n);
                    temp->setLocacion(l);
                    cout<<"\nSe modifico correctamente";
                    return regionList;//me salgo de la fucnion
                }
                temp = temp->next;
            }
            cout<<"\nNO se encontro el dato.";
        }

    }
    else{
        cout<<"\n+++ Advertencia: El nombre ingresado ya existe en la lista +++\n";
    }
    return regionList;
}

//Buscar Nodo Region
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


//Imprime la lista completa
void Region:: print(Region* regionList){

    if(regionList == NULL)
        cout<<"\nLa lista esta vacia ...........\n";
    else{
        Region*temp = regionList;
        while(temp != NULL){
            cout<<"\n"<<temp->idRegion<<" | "<<temp->name<<" | "<<temp->location;
            temp = temp->next;
        }
    }
}

//Cargar datos quemados
Region* Region::dataLoad(Region* regionList){

    //Datos preestablecidos en lista region
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
    //regionList=add("C","Caribe","Limon",regionList);

    cout<<"\n--- Se cargaron los datos correctamente ---\n";
    return regionList;
}
//---------------------------------SUBLISTA DE LUGARES----------------------------

NodoSubPlace* Region::linkendPlaceRegion(string idRegion, string namePlace,Place* placeList,Region* regionList){

    Region* reg = reg->searchRegion(idRegion,regionList);
    Place* plc = plc->searchPlace(namePlace,placeList);

    if(plc == NULL){
        cout<<"\nNo existe el lugar";
        return NULL;
    }
    if(reg == NULL){
        cout<<"\nNo existe la region";
        return NULL;
    }

    NodoSubPlace* newNodo = new NodoSubPlace();
    newNodo->linkPlace = plc;// se enlaza con el curso
    newNodo->next = reg->placeSublist;
    reg->placeSublist = newNodo;
    return reg->placeSublist;

}


void Region::printSublistPlace(string id,Region* regionList){

    Region * reg =reg->searchRegion(id,regionList);

    if(reg == NULL){
        cout<<"\nNo existe el lugar";
        return;
    }
    else{
        NodoSubPlace* temSub = reg->placeSublist;
        if(temSub==NULL){
            cout<<"\n\t"<<reg->getName()<<" no tiene lugares registrados\n";
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
//*************NUEVO CODIGO**************
/*Se encarga de imprimir el promedio de las variables meteorologicas en un periodo especifico
 *
 * */
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
    //cout<<"*******************************"<<endl;
    cout<<"\n\t   =========================================================================\n";
    cout<<"\t   ||    Promedio de las variables climatologicas en la region "<<reg->getName()<<" ||\n";
    cout<< "           ||                    En el periodo de "<<year1<<" a "<<year2<<"                     ||\n";
    cout<<"\t   =========================================================================\n";
    //cout<< "Promedio de las variables climatologicas en la region "<<reg->getName()<<endl;
    //cout<< "En el periodo de "<<year1<<" a "<<year2<<"\n"<<endl;
    cout<<"\n\t________________________________________________\n";
    cout<< "\n\tPromedio de precipitacion: "<<(promPreci*cont)/100<<endl;
    cout<< "\n\tPromedio de Maxima temperatura: "<<(promMaxTemp*cont)/100<<endl;
    cout<< "\n\tPromedio de Minima temperatura: "<<(promMinTemp*cont)/100<<endl;
    cout<< "\n\tPromedio de dias de lluvia: "<< (float)(promDayRain*cont)/100<<endl;
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPresione cualquier tecla para regresar al menu...";
    cin.ignore();
    cin.get();

}


//New code

//Reporte imprimir la precipitaci�n mensual promedio de cada region en un a�o X.

void Region::MonthlyRain(int year,string id,Region* regionList){
    system("cls");

    string months[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    map <string, float> precipMonth;
    int month =0;
    int days = 0;
    float totalPrecip=0;

    Region* reg = reg->searchRegion(id,regionList);
    NodoSubTime*time = reg->placeSublist->linkPlace->timeRegiSublist;

        cout<<"\n\t   =========================================\n";
        cout<<"\t   ||   Precipitacion Mensual Promedio    ||\n";
        cout<<"\t   ||          "<<reg->getName()<<" "<<year<<"            ||\n";
        cout<<"\t   =========================================\n";


    while(reg->placeSublist!=NULL){

        cout<<reg->placeSublist->linkPlace->getName()<<endl;

        if(time==NULL){

            cout<<"\n"<<reg->placeSublist->linkPlace->getName()<<" no tiene registros del tiempo en esta fecha"<<endl;
        }
        else{

            while(time!=NULL){

               cout<<time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon<<endl;

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
                            precipMonth[months[month-1]] = totalPrecip/days;

                            cout<<precipMonth[months[month-1]]<<endl;
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

    if(reg->placeSublist!=NULL){

        while(month>0){
            cout<<"\n\t________________________________________________\n";
            cout<<"\n\tMes: "<<months[month-1]<<endl;
            cout<<"\n\tPrecipitacion Promedio: "<<precipMonth[months[month-1]]<<endl;
            month--;

        }
    }
}
