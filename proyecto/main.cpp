#include <iostream>
#include <ctime>
#include<fstream>
#include "TimeRegis.h"
#include "Place.h"
#include "Region.h"
#include "Ephemerality.h"
#include "People.h"
#include "Rain.h"
#include<windows.h>




/*
    Autor: Karina Urbina
    Iniciado: 12/09/2022
    Avance1: 16/09/2022
    Ultima modificacion:

*/
using namespace std;


Place* placeList;// Lista Lugares
Region* regionList;// Lista region
TimeRegis* timeList;// Lista registro del tiempo
Rain* rainList;// lista LLuvia
People* peopleList;// Lista Personas
Ephemerality* ephemeralityList;//Lista efimeridad



void options(){
    cout<<"\t\t\t=========================================================================="<<endl;
    cout<<"\t\t\t\t\t   SISTEMA DE REGISTRO DEL TIEMPO DIARIO "<<endl;
    cout<<"\t\t\t=========================================================================="<<endl;
    cout<<"\t\t\t\t1.INSERTAR DATOS EN LISTAS\n\n";
    cout<<"\t\t\t\t2.MODIFICAR LISTA\n\n";
    cout<<"\t\t\t\t3.BORRAR NODO DE LISTA\n\n";
    cout<<"\t\t\t\t4.BORRAR LISTAn\n";
    cout<<"\t\t\t\t5.IMPRIMIR LISTAS\n\n";
    cout<<"\t\t\t\t6.CONSULTAS\n\n";
    cout<<"\t\t\t\t7.REPORTES\n\n";
    cout<<"\t\t\t\t0.SALIR\n\n";
}




//Bienvenida al sistema
void welcome(){
    system("cls");
    cout << "\n\n\n";
    cout << "\t\t\t * * *   *   *****  **    *   * * *   *****  **    *  *  *****    *****  "<< endl;
    cout << "\t\t\t *   *      *       * *   *   *   *  *       * *   *     *    *  *     * "<< endl;
    cout << "\t\t\t * * *   *  ****    *  *  *   * * *  ****    *  *  *  *  *    *  *     * "<< endl;
    cout << "\t\t\t *   *   *  *       *   * *   *   *  *       *   * *  *  *    *  *     * "<< endl;
    cout << "\t\t\t * * *   *   *****  *    **   * * *   *****  *    **  *  *****    *****  "<< endl;
    cout<<endl;
    cout<<"\t\t\t=========================================================================="<<endl;
    cout<<"\t\t\t\t\t   SISTEMA DE REGISTRO DEL TIEMPO DIARIO "<<endl;
    cout<<"\t\t\t=========================================================================="<<endl;
    cout<<endl;
    cout<<"\t\t\t\t1. MENU PRINCIPAL\n\n";
    cout<<"\t\t\t\t2. SALIR\n\n";

    //cout<<"press any key to continue...";
    //cin.ignore();
    //cin.get();
}

//Imprime la sublista de lugares de una region especifica
void dataLoadSublist(Place* placeList,Region* regionList,People* peopleList,TimeRegis* timeList,Rain* rainList){

    //Datos quemados en SUBLISTA LUGAR-REGION
    regionList->linkendPlaceRegion("NA","San Carlos",placeList,regionList);
    regionList->linkendPlaceRegion("NA","Naranjo",placeList,regionList);
    regionList->linkendPlaceRegion("NA","Guatuso",placeList,regionList);

    //Datos quemados en SUBLISTA PERSONA-TIEMPO
    peopleList->linkendTimePeople("202204","01/09/2022",timeList,peopleList);
    peopleList->linkendTimePeople("202204","02/09/2022",timeList,peopleList);
    peopleList->linkendTimePeople("202204","03/09/2022",timeList,peopleList);
    peopleList->linkendTimePeople("202204","04/09/2022",timeList,peopleList);

    peopleList->linkendTimePeople("202207","05/09/2022",timeList,peopleList);
    peopleList->linkendTimePeople("202207","06/09/2022",timeList,peopleList);
    peopleList->linkendTimePeople("202207","07/09/2022",timeList,peopleList);


    //Datos quemados en SUBLISTA LUGAR-REGISTRO TIEMPO
    placeList->linkendTimePlace("San Carlos","03/09/2022",timeList,placeList);
    placeList->linkendTimePlace("San Carlos","04/09/2022",timeList,placeList);
    placeList->linkendTimePlace("San Carlos","05/09/2022",timeList,placeList);
    placeList->linkendTimePlace("San Carlos","06/09/2022",timeList,placeList);
    placeList->linkendTimePlace("San Carlos","07/09/2022",timeList,placeList);

    //Datos quemados en SUBLISTA REGISTRO TIEMPO- LLUVIA
    timeList->linkendRainTime("1","03/09/2022",rainList,timeList);
    timeList->linkendRainTime("1","04/09/2022",rainList,timeList);
    timeList->linkendRainTime("1","05/09/2022",rainList,timeList);
    timeList->linkendRainTime("1","06/09/2022",rainList,timeList);
    timeList->linkendRainTime("1","07/09/2022",rainList,timeList);
    timeList->linkendRainTime("1","08/09/2022",rainList,timeList);
}

/*
void calcPersonMostRegis(People* peopleList){




}
*/




int main()
{
    // CARGAR DATOS LISTAS
    placeList=placeList->dataLoad(placeList);
    placeList->print(placeList);

    regionList=regionList->dataLoad(regionList);
    regionList->print(regionList);


    timeList=timeList->dataLoad(timeList);
    timeList->print(timeList);// revisar

    rainList=rainList->dataLoad(rainList);
    rainList->printRainList(rainList);


    ephemeralityList=ephemeralityList->dataLoad(ephemeralityList);
    //ephemeralityList->printEphemeralityList(ephemeralityList);

    peopleList=peopleList->dataLoad(peopleList);
    peopleList->printPeopleList(peopleList);


    //CARGAR DATOS SUBLISTAS
    dataLoadSublist(placeList,regionList,peopleList,timeList,rainList);


    //regionList->printSublistPlace("NA",regionList);
    //peopleList->printSublistTime("202204",peopleList); //revisar
    //placeList->printSubTimePlace("San Carlos",placeList); //revisar(error raro)
    timeList->linkendRainTime("1","05/09/2022",rainList,timeList);

    cout << "ESTO ES UNA PRUEBA!" << endl;
    peopleList = peopleList->dataLoad(peopleList);
    People*persona = peopleList->searchPeople(peopleList,"2022437759");
    peopleList->printPeopleList(peopleList);
    ephemeralityList = ephemeralityList->dataload(ephemeralityList);
    ephemeralityList->printEphemeralityList(ephemeralityList);

    ephemeralityList->diffDepartureTime(2022,ephemeralityList);
    ephemeralityList->timeReportYear(ephemeralityList,2022);
    ephemeralityList->earlyDeparLateHide(ephemeralityList);
    //persona->setTimeSublist(timeList->add("2022/09/23",001,12.11,12.12,20,23,22,false,persona->getTimeSubList()));
    //persona->setTimeSublist(timeList->add("2022/09/24",001,0.11,14.12,20,23,22,true,persona->getTimeSubList()));
    //timeList->print(persona->getTimeSubList());


    //char c;
/*
    do{
       welcome();
       cout<<"\n\t\t\tELIGA UNA OPCION:";
       cin>>c;
       system("cls");

       switch(c)
       {
       case '1':
        {
            //linkPlaceRegion("San Carlos","Z",placeList,regionList);
            //printSublistPlace("Z",placeList);
            //Sleep(1500);
            //break;
        }
       case '2':
        {        cout << "\n\t\t       GRACIAS POR USAR ESTE SISTEMA"<<endl;
                 cout <<endl;
                 cout << "\n\t\t  PROYECTO 1  ESTRUCTURAS DIAMICAS LINEALES\n";
                 cout<<"\n\t\t\   =========================================\n";
                 cout<<"\n\t\t\   MIEMBROS DEL GRUPO (DESARROLLADORES)";
                 cout << "\n\n";
                 cout << "\n\t\t\   NOMBRE                        CARNET\n\n";
                 cout << "\n\t\t\   1. lEINER ALVARADO           202200000\n\n";
                 cout << "\n\t\t\   2. KARINA URBINA             208460025\n\n";
                 cout<<"\n\t\t\  =========================================\n";
                 cout<<"\n\t\t\   START DATE: 12/09/2022\n";
                 cout<<"\n\t\t\   END DATE: 07/10/2022 ";
                 cout << "\n\n";
        }
        }
       }while(c!='2');

*/
    return 0;

}
