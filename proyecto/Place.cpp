#include "Place.h"
#include "TimeRegis.h"
#include <string>
#include <iostream>
using namespace std;


Place::Place(string n,int p,float meters){

    setName(n);
    setPopulation(p);
    setSquareMeters(meters);
    next= NULL;
    timeRegiSublist=NULL;

}


//------------------- Metodos set-----------------------------------------
void Place::setName(string n){
    name=n;
}

void Place::setPopulation(int p){
    population= p;
}

void Place::setSquareMeters(float meters){
    squareMeters= meters;
}
/*void Place::setTimeRegis(TimeRegis*newList){
    timeRegSublist = newList;
}*/



//------------------- Metodos get-----------------------------------------
string Place::getName(){
    return name;
}

int Place::getPopulation(){
    return population;
}

float Place::getSquareMeters(){
    return squareMeters;
}

/*TimeRegis* Place::getTimeRegis(){
    return timeRegSublist;
}*/





//************************** Funciones de la lista ******************


//Verifica si el elemento a agregar ya existe en la lista
bool Place::validate(string n,Place* placeList){

    if(placeList == NULL)
        return false;
    else{
        if(placeList->getName() == n){//es el primero de la lista
            return true;
        }
        else{
            Place*temp = placeList;
            do{
                if (placeList->getName() != n)
                    temp= temp->next;
            } while(temp!= placeList);
            return false;
        }
    }
}

//Agregar al Inicio
Place* Place::add(string n,int p,float meters,Place* placeList){

    bool duplicate= validate(n,placeList);

    if(duplicate==NULL){

        Place* newNodo = new Place(n,p,meters);

        if(placeList == NULL){
            placeList = newNodo;
            newNodo->next = placeList;
        }
        else{

            newNodo->next =placeList;
            //buscar el ultimo para que apunte al nuevo nodo
            Place* temp = placeList;
            while(temp->next != placeList)
                temp = temp->next;

            temp->next = newNodo;
            placeList = newNodo;

        }
    }
    else{
        cout<<"\n+++ Advertencia: El nombre ingresado ya esta en la lista +++\n";
    }
    return placeList;
}

//Modificar
Place* Place::modify(string data, string n,int p, float m,Place*placeList){

    bool duplicate= validate(n,placeList);

     if(duplicate==NULL){
        if(placeList== NULL)
            cout<<"\nLa lista no tiene datos.....";
        else{
            Place*temp = placeList;
            while (temp != NULL){
                if(temp->getName() == data){
                    temp->setName(n);
                    temp->setPopulation(p);
                    temp->setSquareMeters(m);
                    cout<<"\nSe modifico correctamente";
                    return placeList;//me salgo de la fucnion
                }
                temp = temp->next;
            }
            cout<<"\nNO se encontro el dato.";
        }
    }
    else{
        cout<<"\n+++ Advertencia: El nombre ingresado ya existe en la lista +++\n";
    }
    return placeList;
}

//Borra UN ELEMENTO de la lista
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

//Borra toda la lista
Place* deleteAllPlace(Place* placeList) {
    if(placeList != NULL) {
        Place *temp, *current;
        current = placeList->next;
        while(current != placeList) {
            temp = current->next;
            free(current);
            current = temp;
        }
        free(placeList);
        placeList = NULL;
    }
    cout<<"Todos los nodos han sido eliminados correctamente.\n";
    return placeList;
}


//Buscar Nodo Place


Place* Place::searchPlace(string n, Place* placeList){
     Place *temp;
     if(placeList !=NULL){
          temp = placeList;

          do
          {
               if(temp->getName() == n)
               {
                   return temp;
               }
               else
               {
                   temp = temp->next;
               }
          }while(temp!=placeList);

          //cout<<"\n\n\Lugar no encontrado..!"<<endl;

     }
     else
        return NULL;
         cout<<"\n\n\tLista vacia...!"<<endl;
}


//Imprime la lista completa
void Place:: print(Place* placeList){

    if(placeList== NULL)
        cout<<"\nLista circular vacia......\n";
    else{
        Place*temp = placeList;
        do{
            cout<<temp->getName()<<" | "<<temp->getPopulation()<<" | "<<temp->getSquareMeters()<<endl;
            temp= temp->next;
        } while(temp!= placeList);

    }
}

//Se reciben datos de entrada
void Place::askData(){

    string n;
    int p;
    float mc;

    cout<<"\nIngrese el nombre del lugar: ";
    getline(cin>>ws, n);
    cout<<"\nIngrese la poblacion total del lugar: ";
    cin>>p;
    cout<<"\nIngrese los metros cuadrados del lugar: ";
    cin>>mc;

 }

//Cargar datos quemados
Place* Place::dataLoad(Place* placeList){

    //Datos preestablecidos en lista lugar
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

    cout<<"\n---Se cargaron los datos correctamente---\n";

    return placeList;

}

//---------------------------------SUBLISTA DE REGISTROS DEL TIEMPO----------------------------

NodoSubTime* Place::linkendTimePlace(string namePlace, long int date,TimeRegis* timeList,Place* placeList){

    Place* plc = plc->searchPlace(namePlace,placeList);
    TimeRegis* timeR = timeR->searchTime(date,timeList);

    if(plc == NULL){
        cout<<"\nNo existe el lugar";
        return NULL;
    }
    if(timeR == NULL){
        cout<<"\nNo existe el registro del tiempo";
        return NULL;
    }

    NodoSubTime* newNodo = new NodoSubTime();
    newNodo->linkTime = timeR;// se enlaza con el curso
    newNodo->next = plc->timeRegiSublist;
    plc->timeRegiSublist = newNodo;

    return plc->timeRegiSublist;
}



void Place::printSubTimePlace(string namePlace,Place* placeList){

    Place * plc = plc->searchPlace(namePlace,placeList);

    if(plc == NULL){
        cout<<"\nNo existe el lugar";
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


//New code

//Reporte imprimir la precipitación mensual promedio de cada lugar en un año X.

void Place::MonthlyRain(int year,Place* placeList){
    system("cls");
    Place * plc = placeList;

    int totalPrecip;
        cout<<"\n\t   =========================================\n";
        cout<<"\t   ||   Precipitacion Mensual Promedio    ||\n";
        cout<<"\t   ||                 "<<year<<"                ||\n";
        cout<<"\t   =========================================\n";
    do{
        //system("cls");

        //cout<<"\n\t   =========================================\n";
        //cout<<"\t   ||   Precipitacion Mensual Promedio    ||\n";
        //cout<<"\t   ||                 "<<year<<"                ||\n";
        //cout<<"\t   =========================================\n";
        if(plc->timeRegiSublist==NULL){
            cout<<"\n\t   "<<plc->getName()<<" no tiene registros del tiempo\n";
        }
        else{
            while(plc->timeRegiSublist->linkTime!=NULL){
                if(year==plc->timeRegiSublist->linkTime->unixDateToDate(plc->timeRegiSublist->linkTime->getDateR())->tm_year){
                    totalPrecip=totalPrecip+plc->timeRegiSublist->linkTime->getPrecip();
                }
                plc->timeRegiSublist->linkTime=plc->timeRegiSublist->linkTime->next;
            }

            cout<<"\t   LUGAR: "<<plc->getName()<<"\n\t   PRECIPITACION TOTAL: "<<totalPrecip<<endl;
        }
        cout<<"\t   _________________________________________\n";
        totalPrecip=0;
        plc = plc->next;
        //cout<<"\n\t   Presione cualquier tecla para continuar...";
       // cin.ignore();
        //cin.get();
    }while(plc!=placeList);


}
// Nuevo codigo

//void printVarWeather()

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
                else if ((month != timeList->linkTime->unixDateToDate(timeList->linkTime->getDateR())->tm_mon)||timeList->next == NULL){
                    cout<<"\n\t________________________________________________\n";
                    cout<<"\n\tMes: "<<months[month-1]<<endl;
                    cout<<"\n\tExtremo lluvioso: "<<(promExtremeRain*100)/cont<<"%"<<endl;
                    cout<<"\n\tLluvioso: "<<(promRainy*100)/cont<<"%"<<endl;
                    cout<<"\n\tNormal: "<<(promNormal*100)/cont<<"%"<<endl;
                    cout<<"\n\tSeco: "<<(promDry*100)/cont<<"%"<<endl;
                    cout<<"\n\tExtremo seco: "<<(promExtremeDry*100)/cont<<"%"<<endl;
                    month = timeList->linkTime->unixDateToDate(timeList->linkTime->getDateR())->tm_mon;
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
    cout<<"\n\tPresione cualquier tecla para regresar al menu...";
    cin.ignore();
    cin.get();
}



//}
// Nuevo codigo

//void printVarWeather()

void Place::printRainyDays(int year,string namePlace,Place*pList){
    string months[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    int month =0;
    int days = 0;
    //float promExtremeRain = 0, promRainy = 0,promNormal = 0,promDry = 0,promExtremeDry = 0;
    Place* plc = plc->searchPlace(namePlace,pList);
    NodoSubTime*time = plc->timeRegiSublist;

    cout<<"\n\n\t   =============================================\n";
    cout<<"\t   ||      Dias lluviosos en "<<plc->getName()+"       ||\n";
    cout<<"\t   =============================================\n";
    while (time !=  NULL){

        if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_year == year){
            //cout<<time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_year<<endl;
            //cout<<time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon<<endl;

            if (time->linkTime->getRained()){
                days++;

                //cout<<time->linkTime->getRained()<<endl;

                if (month == 0){
                    month = time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon;
                    //cout<<month<<endl;
                }
                else if (month != time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon){
                    cout<<"\n\t________________________________________________\n";
                    cout<<"\n\tMes: "<<months[month-1]<<endl;
                    cout<<"\n\tDias lluviosos: "<<days<<endl;
                    month = time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon;
                    //cout<<month<<endl;
                    days = 0;
                }

                NodoSubRain*rainList= time->linkTime->rainSublist;
            }
        }
        time = time->next;
    }
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPresione cualquier tecla para regresar al menu...";
    cin.ignore();
    cin.get();
}


/*

int Place::countDataRepeated(string code,NodoSubRain* subRain){

    int cont;
  if(subRain!=NULL)
  {
    if(subRain->linkRain->getRainCode()=='1')
    {
       cont=1+countDataRepeated(subRain->next);
    }
    else
    {
       cont=0+countDataRepeated(subRain->Rain);
    }

  }

 return cont;
}


void Place::calcMonthRain(int year, string place,Place* placeList){

    Place* plc = plc->searchPlace(place,placeList);

    int contA,contB,contC,contD;

    if(plc->timeRegiSublist==NULL){
            cout<<"\n\t"<<plc->getName()<<" no tiene registro del tiempo\n";
    }
    else{
        NodoSubTime*time = plc->timeRegiSublist;
        while(time!=NULL){
            if(time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_year == year){

                if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==1){
                    contA=countDataRepeated(1,time->linkTime->rainSublist);
                    contB=countDataRepeated(1,time->linkTime->rainSublist);
                }
                else if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==2){
                    contC=countDataRepeated(1,time->linkTime->rainSublist);
                    contD=countDataRepeated(1,time->linkTime->rainSublist);
                }

                if(contA<contC)&&(contB<contD){

                }





                if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==3){
                    contA=countDataRepeated(1,time->linkTime->rainSublist);
                    contB=countDataRepeated(1,time->linkTime->rainSublist);
                }
                if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==4){
                    contA=countDataRepeated(1,time->linkTime->rainSublist);
                    contB=countDataRepeated(1,time->linkTime->rainSublist);
                }
                if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==5){
                    contA=countDataRepeated(1,time->linkTime->rainSublist);
                    contB=countDataRepeated(1,time->linkTime->rainSublist);
                }
                if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==6){
                    contA=countDataRepeated(1,time->linkTime->rainSublist);
                    contB=countDataRepeated(1,time->linkTime->rainSublist);
                }
                if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==7){
                    contA=countDataRepeated(1,time->linkTime->rainSublist);
                    contB=countDataRepeated(1,time->linkTime->rainSublist);
                }
                if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==8){
                    contA=countDataRepeated(1,time->linkTime->rainSublist);
                    contB=countDataRepeated(1,time->linkTime->rainSublist);
                }
                if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==5){
                    contA=countDataRepeated(1,time->linkTime->rainSublist);
                    contB=countDataRepeated(1,time->linkTime->rainSublist);
                }
                if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==6){
                    contA=countDataRepeated(1,time->linkTime->rainSublist);
                    contB=countDataRepeated(1,time->linkTime->rainSublist);
                }
                if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==7){
                    contA=countDataRepeated(1,time->linkTime->rainSublist);
                    contB=countDataRepeated(1,time->linkTime->rainSublist);
                }
                if (time->linkTime->unixDateToDate(time->linkTime->getDateR())->tm_mon ==8){
                    contA=countDataRepeated(1,time->linkTime->rainSublist);
                    contB=countDataRepeated(1,time->linkTime->rainSublist);
                }

            }


        }
    }



        else{
            while




                while(plc->timeRegiSublist!=NULL){
                    if(plc->timeRegiSublist->linkTime->unixDateToDate(plc->timeRegiSublist->linkTime->getDateR())->tm_year==year){
                                contA=


                            }
                        }






                    }
                    plc->timeRegiSublist->linkTime= plc->timeRegiSublist->linkTime->next;

                }

            }

        }
        plc=plc->next;
    }while(plc!=placeList);



    (plc!=NULL){

            if ()

            if(time->unixDateToDate(time->getDateR())->tm_year==year){


            }










    }



*/






