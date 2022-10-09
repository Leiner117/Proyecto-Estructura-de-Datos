#include <iostream>
#include <ctime>
#include <fstream>
#include "TimeRegis.h"
#include "Place.h"
#include "Region.h"
#include "Ephemerality.h"
#include "People.h"
#include "Rain.h"
#include<windows.h>

/*
    Autores: Karina Urbina y Leiner Alvarado
    Iniciado: 12/09/2022
    Ultima modificacion: 08/10/2022
*/

using namespace std;

Place* placeList;
Region* regionList;
TimeRegis* timeList;
Rain* rainList;
People* peopleList;
Ephemerality* ephemeralityList;

/**
 * Funcion que verifica si los datos de fecha son validos
 *
 * Args:
 *   day (int): Dia.
 *   month (int): Mes, especificado como un número entero entre 1 y 12 (enero = 1, febrero = 2, etc.).
 *   year (int): Año.
 *
 * Returns:
 *   Un valor booleano
 */
bool valDate(int day,int month,int year){
    bool flag = true;
    if (day > 31 || day <1){
        flag = false;
    }
    if (month > 12 || month < 1){
        flag = false;
    }
    if (year < 2000){
        flag = false;
    }
    if (!flag){
        cout<<"\n\t\tINGRESO UN DATO DE FECHA NO VALIDO! VUELVA A INTENTARLO"<<endl;
    }
    return flag;
}


/**
 * Funcion para modificar los datos de un lugar en la lista de lugares
 */
void modifyPlace(){

    string data,newPlc;
    int newPobl,newMeters;

    cout << "\n\t\tINGRESE EL NOMBRE DEL LUGAR QUE DESEA MODIFICAR: ";
    getline(cin>>ws, data);

    cout << "\n\t\tINGRESE EL NUEVO NOMBRE DEL LUGAR: ";
    getline(cin>>ws, newPlc);

    cout << "\n\t\tINGRESE LA NUEVA POBLACION DEL LUGAR: ";
    cin>>newPobl;

    cout << "\n\t\tINGRESE EL NUEVO AREA DEL LUGAR: ";
    cin>>newMeters;

    placeList=placeList->modify(data,newPlc,newPobl,newMeters,placeList);
    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();

}

/**
 * Funcion para modificar los datos de una region en la lista de regiones
 */
void modifyRegion(){

    string data,newReg,newID,newLocation;

    cout << "\n\t\tINGRESE EL CODIGO DE LA REGION QUE DESEA MODIFICAR: ";
    cin>>data;

    cout << "\n\t\tINGRESE EL NUEVO NOMBRE DE LA REGION: ";
    getline(cin>>ws, newReg);

    cout << "\n\t\tINGRESE EL NUEVO CODIGO DE LA REGION: ";
    cin>>newID;

    cout << "\n\t\tINGRESE LA NUEVA UBICACION (PROVINCIA) DE LA REGION: ";
    cin>>newLocation;

    regionList=regionList->modify( data,newID,newReg,newLocation,regionList);
    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();

}

/**
 * Funcion para modificar los datos de un registro del tiempo en la lista de registros del tiempo
 */
void modifyTimeRegis(){

    short month,day;
    long int registrationDate,dateChance;
    int precipitation,windSpeed,windDirection,humidity,year;
    float maxTemperature,minTemperature;
    bool yesRained=NULL;
    string answer;

    cout << "\n\t\tINGRESE LA FECHA DEL REGISTRO QUE DESEA MODIFICAR";
    do{
        cout << "\n\t\tDIA (dd): ";
        cin>>day;
        cout << "\t\tMES (mm): ";
        cin>>month;
        cout << "\t\tYEAR (yy): ";
        cin>>year;
    }while(!valDate(day, month, year));

    dateChance=ephemeralityList->dateToUnixDate(year,month,day);

    day=0;
    month=0;
    year=0;

    cout << "\n\t\tINGRESE LA NUEVA FECHA DEL REGISTRO";
    do{
        cout << "\n\t\tDIA (dd): ";
        cin>>day;
        cout << "\t\tMES (mm): ";
        cin>>month;
        cout << "\t\tYEAR (yy): ";
        cin>>year;
    }while(!valDate(day, month, year));

    registrationDate=ephemeralityList->dateToUnixDate(year,month,day);

    cout << "\n\t\tINGRESE LA NUEVA PRECIPITACION: ";
    cin>>precipitation;

    cout << "\n\t\tINGRESE LA NUEVA TEMPERATURA MAXIMA: ";
    cin>>maxTemperature;

    cout << "\n\t\tINGRESE LA NUEVA TEMPERATURA MINIMA ";
    cin>>minTemperature;

    cout << "\n\t\tINGRESE LA NUEVA VELOCIDAD DEL VIENTO: ";
    cin>>windSpeed;

    cout << "\n\t\tINGRESE LA NUEVA DIRECCION DEL VIENTO: ";
    cin>>windDirection;

    cout << "\n\t\tINGRESE LA NUEVA HUMEDAD RELATIVA: ";
    cin>>humidity;

    cout << "\n\t\tLLOVIO?(S/N): ";
    cin>>answer;

    if((answer=="n")||(answer=="N")){
        yesRained=false;
    }
    else if((answer=="s")||(answer=="S")){
        yesRained=true;
    }
    timeList=timeList->modify(dateChance,registrationDate,precipitation,maxTemperature,minTemperature,windSpeed,windDirection,humidity,yesRained,timeList);

    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();

}

/**
 * Funcion para modificar los datos de una efimeridad en la lista de efimeridades
 */
void modEphemerality(){
    short year = 0,month = 0,day = 0;
    string name;
    long int date;
    int departureTime = 0,hideTime = 0;
    int hour = 0,minutes = 0;
    cout << "\n\t\tINGRESE EL YEAR DE LA FECHA QUE DESEA MODIFICAR: ";
    cin>>year;
    cout << "\n\t\tINGRESE EL MES DE LA FECHA QUE DESEA MODIFICAR: ";
    cin>>month;
    cout << "\n\t\tINGRESE EL DIA DE LA FECHA QUE DESEA MODIFICAR: ";
    cin>>day;
    date = ephemeralityList->dateToUnixDate(year,month,day);
    year=0;
    month = 0;
    day = 0;
    Ephemerality*ephemerality = ephemeralityList->searchEphemerality(date,ephemeralityList);
    if(ephemerality!=NULL){
        cout << "\n\t\tINGRESE EL NUEVO YEAR DE LA FECHA QUE DESEA MODIFICAR: ";
        cin>>year;
        cout << "\n\t\tINGRESE EL NUEVO MES DE LA FECHA QUE DESEA MODIFICAR: ";
        cin>>month;
        cout << "\n\t\tINGRESE EL NUEVO MES DE LA FECHA QUE DESEA MODIFICAR: ";
        cin>>day;
        date = ephemeralityList->dateToUnixDate(year,month,day);

        if(ephemeralityList->searchEphemerality(date,ephemeralityList) == NULL){
            cout << "\n\t\tINGRESE EL NUEVO NOMBRE DE LA EFIMERIDAD: ";
            getline(cin>>ws,name);

            cout << "\n\t\tINGRESE LA NUEVA HORA DE SALIDA DEL SOL: ";
            cin>>hour;
            cout << "\n\t\tINGRESE LOS NUEVOS MINUTOS DE SALIDA DEL SOL: ";
            cin>>minutes;
            departureTime = ephemeralityList->timeToSeconds(hour,minutes);
            cout << "\n\t\tINGRESE LA NUEVA HORA DE OCULTAMIENTO DEL SOL: ";
            cin>>hour;
            cout << "\n\t\tINGRESE LOS NUEVOS MINUTOS DE OCULTAMIENTO DEL SOL: ";
            cin>>minutes;
            hideTime = ephemeralityList->timeToSeconds(hour,minutes);
            ephemerality->setDate(date);
            ephemerality->setDepartureTime(departureTime);
            ephemerality->setHideTime(hideTime);
            ephemerality->setName(name);
            cout<<"\n\t\tLA PERSONA SE MODIFICO CORRECTAMENTE";
        }else{
            cout<<"\n\t\tLA NUEVA FECHA YA SE ENCUENTRA REGISTRADA";
        }
    }
    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}

/**
 * Funcion para modificar los datos de una persona en la lista de personas
 */
void modPeople(){
    system("cls");
    string name;
    string id,newId;
    short age;
    string place;
    string yearIncome;

    cout<<"\n\t\tINGRESE LA ID DE LA PERSONA QUE DESEA MODIFICAR: ";
    getline(cin>>ws,id);
    if(peopleList->searchPeople(peopleList,id) !=NULL){
        cout << "\n\t\tINGRESE EL NUEVO NOMBRE: ";
        getline(cin>>ws,name);
        cout << "\n\t\tINGRESE LA NUEVA ID: ";
        getline(cin>>ws,newId);
        People*p1 = peopleList->searchPeople(peopleList,id);
        if(peopleList->searchPeople(peopleList,newId) == NULL){
            cout << "\n\t\tINGRESE LA NUEVA EDAD: ";
            cin>>age;
            cout << "\n\t\tINGRESE EL NUEVO LUGAR DE RESIDENCIA: ";
            getline(cin>>ws,place);
            cout << "\n\t\tINGRESE EL NUEVO YEAR DE INGRESO: ";
            getline(cin>>ws,yearIncome);
            p1->setName(name);
            p1->setId(newId);
            p1->setYearIncome(yearIncome);
            p1->setPlaceResidence(place);
            p1->setAge(age);


        }else{
            cout<<"\n\t\tLA ID INGRESADA YA SE ENCUENTRA REGISTRADA";
        }
    }else{
        cout<<"\n\tLA PERSONA INGRESADA NO ESTA EN EL REGISTRO";
    }
    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}

/**
 * Funcion para modificar los datos de una condicion climatica en la lista de lluvia
 */
void modifyRain(){
    system("cls");
    string data,nameRain,rainCode;
    int averageRange,opc;

    cout << "\n\t\tINGRESE EL CODIGO DEL ESCENARIO CLIMATICO QUE DESEA MODIFICAR: ";
    cin>>data;
    Rain*tempRain = rainList->searchRain(rainList,data);
    if(tempRain != NULL){

        cout<<"\t\t CLASIFICACION DE ESCENARIOS CLIMATICOS"<<endl;
        cout<<"\t\t  1.Extremo lluvioso "<<endl;
        cout<<"\t\t  2.Lluvioso "<<endl;
        cout<<"\t\t  3.Normal "<<endl;
        cout<<"\t\t  4.Seco "<<endl;
        cout<<"\t\t  5.Extremo seco "<<endl;
        cout<<"\t\t======================================================"<<endl;

        cout << "\n\t\tELIGA EL NUEVO ESCENARIO CLIMATICO: ";
        cin>>opc;

        if(opc ==1){
            nameRain="Extremo lluvioso";
        }else if(opc ==2){
            nameRain="Lluvioso";
        }else if(opc ==3){
            nameRain="Normal";
        }else if(opc ==4){
            nameRain="Seco";
        }else if(opc ==5){
            nameRain="Extremo seco";
        }else{
            cout<<"\n\t\tNO INGRESO UN ESCENARIO VALIDO";
        }

        if(opc >0 && opc<6){
            cout<<"\n\t\tINGRESE EL NUEVO CODIGO DE LLUVIA: ";
            cin>>rainCode;
            if(rainList->searchRain(rainList,rainCode) == NULL){
                cout<<"\n\t\tINGRESE EL RANGO PROMEDIO: ";
                cin>>averageRange;
                tempRain->modName(rainList,nameRain,data);
                tempRain->modAverageRange(rainList,averageRange,data);
                tempRain->modRainCode(rainList,rainCode,data);
            cout<<"\n\t\tLA LLUVIA SE MODIFICO CORRECTAMENTE";

            }else{
                cout<<"\n\t\tEL CODIGO DE LLUVIA YA SE ENCUENTRA REGISTRADO";
            }
        }



    }else{
        cout<<"\n\t\t EL CODIGO DE LLUVIA NO SE ENCUENTRA REGISTRADO";
    }
    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}

/**
 * Esta función se utiliza para agregar una nueva persona a la lista
 */
void userLogin(){
    system("cls");
    cout<<"\t\t======================================================"<<endl;
    cout<<"\t\t\t\t  LISTA DE PERSONAS  "<<endl;
    cout<<"\t\t======================================================"<<endl;
    cout<<endl;

    string namePerson,idPerson,residence,yearIncome;
    short age;

    cout << "\n\t\tINGRESE SU NOMBRE: ";
    getline(cin>>ws,namePerson);

    cout << "\n\t\tINGRESE SU CEDULA: ";
    cin>>idPerson;

    cout << "\n\t\tINGRESE SU EDAD: ";
    cin>>age;

    cout << "\n\t\tINGRESE SU LUGAR DE RESIDENCIA: ";
    getline(cin>>ws, residence);

    cout << "\n\t\tINGRESE EL YEAR EN EL QUE ESTA INGRESANDO: ";
    cin>>yearIncome;

    peopleList=peopleList->addPeople(namePerson,idPerson,age,residence,yearIncome,peopleList);
    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();

}

/**
 * Esta función permite al usuario agregar un nuevo lugar a la lista de lugares.
 */
void placeLogin(){
    system("cls");
    cout<<"\t\t======================================================"<<endl;
    cout<<"\t\t\t\t  LISTA DE LUGARES  "<<endl;
    cout<<"\t\t======================================================"<<endl;
    cout<<endl;

    string idRegion;
    string namePlace;
    int population;
    float area;
    bool status= true;

    while(status){

            cout << "\n\t\tINGRESE El ID DE LA REGION A LA QUE PERTENECE ESTE LUGAR: ";
            cin>>idRegion;
            Region* reg =reg->searchRegion(idRegion,regionList);

            if(reg==NULL){
                cout<<"\n\t\tEl ID no pertenece a ninguna region registrada....\n";
            }
            else{
                cout << "\n\t\tINGRESE EL NOMBRE DEL LUGAR: ";
                getline(cin>>ws, namePlace);

                cout << "\n\t\tINGRESE LA POBLACION DEL LUGAR: ";
                cin>>population;

                cout << "\n\t\tINGRESE EL AREA DEL LUGAR: ";
                cin>>area;
                status=false;

            }
    }

    placeList=placeList->add(namePlace,population,area,placeList);
    regionList->linkendPlaceRegion(idRegion,namePlace,placeList,regionList);
    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();

}

/**
 * Esta función permite al usuario agregar una nueva región a la lista de regiones
 */
void regionLogin(){
    system("cls");
    cout<<"\t\t======================================================"<<endl;
    cout<<"\t\t\t\t  LISTA DE REGIONES  "<<endl;
    cout<<"\t\t======================================================"<<endl;
    cout<<endl;
    string nameRegion,idRegion,location;

    cout << "\n\t\tINGRESE EL NOMBRE DE LA REGION: ";
    getline(cin>>ws, nameRegion);

    cout << "\n\t\tINGRESE EL CODIGO DE LA REGION: ";
    cin>>idRegion;

    cout << "\n\t\tINGRESE LA UBICACION(PROVINCIA): ";
    cin>>location;

    regionList=regionList->add(idRegion,nameRegion,location,regionList);
    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}

/**
 * Esta función permite al usuario agregar un nuevo escenario de lluvia a la lista
 */
void rainLogin(){
    system("cls");
    cout<<"\t\t======================================================"<<endl;
    cout<<"\t\t\t\t  LISTA DE LLUVIAS  "<<endl;
    cout<<"\t\t======================================================"<<endl;
    cout<<endl;
    cout<<"\t\t CLASIFICACION DE ESCENARIOS CLIMATICOS"<<endl;
    cout<<"\t\t  1.Extremo lluvioso "<<endl;
    cout<<"\t\t  2.Lluvioso "<<endl;
    cout<<"\t\t  3.Normal "<<endl;
    cout<<"\t\t  4.Seco "<<endl;
    cout<<"\t\t  5.Extremo seco "<<endl;
    cout<<"\t\t======================================================"<<endl;

    string nameRain,rainCode;
    int averageRange,opc;

    cout << "\n\t\tELIGA UN ESCENARIO CLIMATICO: ";
    cin>>opc;

    switch(opc){

        case 1:
            nameRain="Extremo lluvioso";
        case 2:
            nameRain="Lluvioso";
        case 3:
            nameRain="Normal";
        case 4:
            nameRain="Seco";
        case 5:
            nameRain="Extremo seco";
    }

    cout << "\n\t\tINGRESE UN CODIGO PARA EL ESCENARIO CLIMATICO: ";
    cin>>rainCode;

    cout << "\n\t\tINGRESE EL RANGO PROMEDIO EN MILIMEMTROS (mm): ";
    cin>>averageRange;

    rainList=rainList->addRain(rainCode,nameRain,averageRange,rainList);
    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();

}

/**
 * Funcion que permite al usario agregar una nueva efimeridad
 */
void ephemeralityLogin(){
    system("cls");
    cout<<"\t\t======================================================"<<endl;
    cout<<"\t\t\t\t  LISTA DE EFIMERIDADES    "<<endl;
    cout<<"\t\t======================================================="<<endl;
    cout<<endl;

    string nameEp;
    int hourDeparture,minutesDeparture,hourHide,minutesHide,month,day;
    long int date;
    int year,departureTime,hideTime;


    cout << "\n\t\tINGRESE EL NOMBRE DE LA EFEMERIDAD: ";
    cin>>nameEp;

    cout << "\n\t\tINGRESE LA FECHA DE LA EFEMERIADAD";

    do{
        cout << "\n\t\tDIA (dd): ";

        cin>>day;
        cout << "\t\tMES (mm): ";
        cin>>month;
        cout << "\t\tYEAR (yy): ";
        cin>>year;
    }while(!valDate(day, month, year));
    date=ephemeralityList->dateToUnixDate(year,month,day);
    do{
        cout << "\n\t\tINGRESE LA HORA DE SALIDA";

        cout << "\n\t\tHORA (24h): ";
        cin>>hourDeparture;
        cout << "\t\tMINUTOS (mm): ";
        cin>>minutesDeparture;
        cout << "\n\t\tINGRESE HORA DE OCULTAMIENTO: ";
        cout << "\n\t\tHORA (24H): ";
        cin>>hourHide;
        cout << "\t\tMINUTOS (mm): ";
        cin>>minutesHide;

    }while(!ephemeralityList->valTime(hourDeparture,minutesDeparture,hourHide,minutesHide));

    departureTime=ephemeralityList->timeToSeconds(hourDeparture,minutesDeparture);
    hideTime=ephemeralityList->timeToSeconds(hourHide,minutesHide);
    ephemeralityList=ephemeralityList->addEphemerality(nameEp,date,departureTime,hideTime,ephemeralityList);
    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();


}

/**
 * Funicon que le permite al usuario agregar nuevos registros del tiempo
 */
void timeLogin(){
    system("cls");
    cout<<"\t\t=========================================================================="<<endl;
    cout<<"\t\t\t\t  LISTA DE REGISTROS DEL TIEMPO  "<<endl;
    cout<<"\t\t=========================================================================="<<endl;
    cout<<endl;
    short month,day;
    long int registrationDate;
    int precipitation,windSpeed,windDirection,humidity,year;
    float maxTemperature,minTemperature;
    bool yesRained=NULL;
    string answer;

    cout << "\n\t\tINGRESE LA FECHA DEL REGISTRO";
    do{
        cout << "\n\t\tDIA (dd): ";
        cin>>day;
        cout << "\t\tMES (mm): ";
        cin>>month;
        cout << "\t\tYEAR (yy): ";
        cin>>year;
    }while(!valDate(day, month, year));


    registrationDate=ephemeralityList->dateToUnixDate(year,month,day);

    cout << "\n\t\tINGRESE LA PRECIPITACION: ";
    cin>>precipitation;

    cout << "\n\t\tINGRESE LA TEMPERATURA MAXIMA: ";
    cin>>maxTemperature;

    cout << "\n\t\tINGRESE LA TEMPERATURA MINIMA ";
    cin>>minTemperature;

    cout << "\n\t\tINGRESE LA VELOCIDAD DEL VIENTO: ";
    cin>>windSpeed;

    cout << "\n\t\tINGRESE LA DIRECCION DEL VIENTO: ";
    cin>>windDirection;

    cout << "\n\t\tINGRESE LA HUMEDAD RELATIVA: ";
    cin>>humidity;

    cout << "\n\t\tLLOVIO?(S/N): ";
    cin>>answer;

    if((answer=="n")||(answer=="N")){
        yesRained=false;
    }
    else if((answer=="s")||(answer=="S")){
        yesRained=true;
    }

    timeList=timeList->add(registrationDate,precipitation,maxTemperature,minTemperature,windSpeed,windDirection,humidity,yesRained,timeList);
    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();

}

/**
 * Esta función se utiliza para mostrar las opciones del menú de la sublista
 */
void optionListSublis(){
    system("cls");
    cout<<"\t\t======================================================"<<endl;
    cout<<"\t\t\t        SELECCIONE UNA LA LISTA  "<<endl;
    cout<<"\t\t======================================================"<<endl;
    cout<<endl;
    cout<<"\t\t1.LISTA DE PERSONAS\n\n";
    cout<<"\t\t2.LISTA DE LLUVIAS\n\n";
    cout<<"\t\t3.LISTA DE REGIONES\n\n";
    cout<<"\t\t4.LISTA DE LUGARES\n\n";
    cout<<"\t\t5.LISTA DE EFIMERIDAD\n\n";
    cout<<"\t\t6.LISTA DE REGISTROS DEL TIEMPO\n\n";
    cout<<"\t\t0.REGRESAR\n\n";
    cout<<"\t\t======================================================"<<endl;
}

/**
 * Esta función imprime el menú de los reportes.
 */
void reports(){
    system("cls");
    cout<<"\t\t=========================================================================="<<endl;
    cout<<"\t\t\t    REPORTES DEL SISTEMA DE REGISTRO DEL TIEMPO DIARIO   "<<endl;
    cout<<"\t\t=========================================================================="<<endl;
    cout<<endl;
    cout<<"\t\t1.MOSTRAR LA INFORMACION DE TODAS LAS LISTAS\n\n";
    cout<<"\t\t2.VER HORARIOS DE LA SALIDA Y PUESTA DEL SOL\n\n";
    cout<<"\t\t3.VER LA PRECIPITACION MENSUAL DE UN LUGAR\n\n";
    cout<<"\t\t4.VER LA PRECIPITACION MENSUAL DE UNA REGION \n\n";
    cout<<"\t\t5.VER LAS VARIABLES CLIAMATOLOGICAS DE UNA REGION\n\n";
    cout<<"\t\t6.VER LOS PERIODOS DEL CLIMA\n\n";
    cout<<"\t\t7.VER LOS PORCENTAJES DE LA CLASIFICACION DE LA LLUVIA\n\n";
    cout<<"\t\t8.VER LOS DIAS DE LLUVIA EN UN LUGAR\n\n";
    cout<<"\t\t9.VER LOS EXTREMOS DE TEMPERATURA DE UN LUGAR\n\n";
    cout<<"\t\t0.REGRESAR\n\n";

}


/**
 * Imprime un menú de las consultas.
 */
void consults(){
    system("cls");
    cout<<"\t\t=========================================================================="<<endl;
    cout<<"\t\t\t    CONSULTAS DEL SISTEMA DE REGISTRO DEL TIEMPO DIARIO   "<<endl;
    cout<<"\t\t=========================================================================="<<endl;
    cout<<endl;
    cout<<"\t\t1.VER LA FECHA CON LA SALIDA DEL SOL MAS TEMPRANO Y EL OCULTAMIENTO MAS TARDIO\n\n";
    cout<<"\t\t2.MOSTRAR LAS FECHAS CON LA MAYOR DIFERENCIA EN MIN DE LA SALIDA DE SOL\n\n";
    cout<<"\t\t3.MOSTRAR EL MES CON MAS EXTREMOS LLUVIOSOS DE UN LUGAR EN UN YEAR\n\n";
    cout<<"\t\t4.MOSTRAR LA PERSONA QUE MAS REGISTROS DEL TIEMPO TIENE\n\n";
    cout<<"\t\t0.REGRESAR\n\n";
}

/**
 * Imprime un mensaje de bienvenida al usuario y muestra el menu principal.
 */
void welcome(){
    system("cls");
    cout << "\n";
    cout << "\t\t * * *   *   *****  **    *   * * *   *****  **    *  *  *****    *****  "<< endl;
    cout << "\t\t *   *      *       * *   *   *   *  *       * *   *     *    *  *     * "<< endl;
    cout << "\t\t * * *   *  ****    *  *  *   * * *  ****    *  *  *  *  *    *  *     * "<< endl;
    cout << "\t\t *   *   *  *       *   * *   *   *  *       *   * *  *  *    *  *     * "<< endl;
    cout << "\t\t * * *   *   *****  *    **   * * *   *****  *    **  *  *****    *****  "<< endl;
    cout<<endl;
    cout<<"\t\t=========================================================================="<<endl;
    cout<<"\t\t\t\t   SISTEMA DE REGISTRO DEL TIEMPO DIARIO "<<endl;
    cout<<"\t\t=========================================================================="<<endl;
    cout<<endl;
    cout<<"\t\t1.AGREGAR EN LISTA\n\n";
    cout<<"\t\t2.MODIFICAR UN NODO DE LA LISTA\n\n";
    cout<<"\t\t3.BORRAR UN NODO ESPECIFICO DE LA LISTA \n\n";
    cout<<"\t\t4.MOSTRAR CONSULTAS\n\n";
    cout<<"\t\t5.VER REPORTES\n\n";
    cout<<"\t\t0.SALIR\n\n";
}


/**
 * Crea las sublistas y las vincula a las listas principales
 *
 * Args:
 *   place (Place): puntero a la lista de lugares
 *   region (Region): un puntero a la lista de regiones
 *   people (People): un puntero a la lista de personas
 *   time (TimeRegis): un puntero a la lista de registros del tiempo
 *   rain (Rain): un puntero a la lista de lluvia
 */
void dataLoadSublist(Place*place,Region*region,People*people,TimeRegis*time,Rain*rain){

    //Enlace de la sublista de registros del tiempo con personas
    peopleList->linkendTimePeople("202204",1662012000,time,people); // 01 / 09 / 2022-Leiner
    peopleList->linkendTimePeople("202204",1662098400,time,people); //02 / 09 / 2022-Leiner
    peopleList->linkendTimePeople("202204",1662357600,time,people); //05 / 09 / 2022-Leiner
    peopleList->linkendTimePeople("202204",1662616800,time,people); // 08 / 09 / 2022-Leiner
    peopleList->linkendTimePeople("202205",1657432800,time,people); // 10 / 07 / 2022-Sara
    peopleList->linkendTimePeople("202205",1583301600,time,people); //04 / 03 / 2020-Sara
    peopleList->linkendTimePeople("202206",1577772000,time,people); //31 / 12 / 2019-Tommy
    peopleList->linkendTimePeople("202207",1587621600,time,people); //23 / 04 / 2020-Karina
    peopleList->linkendTimePeople("202207",1598335200,time,people); // 25 / 08 / 2020-Karina
    peopleList->linkendTimePeople("202207",1607493600,time,people); //09 / 12 / 2020-Karina

    //Enlace de la sublista de lugares en regiones
    regionList->linkendPlaceRegion("NA","San Carlos",place,region);
    regionList->linkendPlaceRegion("NA","Naranjo",place,region);
    regionList->linkendPlaceRegion("NA","Palmares",place,region);
    regionList->linkendPlaceRegion("VC","Escazu",place,region);
    regionList->linkendPlaceRegion("CGT","Liberia",place,region);
    regionList->linkendPlaceRegion("UC","Guatuso",place,region);
    regionList->linkendPlaceRegion("UC","Los Chiles",place,region);
    regionList->linkendPlaceRegion("T","Talamanca",place,region);
    regionList->linkendPlaceRegion("NA","Grecia",place,region);
    regionList->linkendPlaceRegion("T","Sarapiqui",place,region);

    //Enlace de la sublista lluvia en registros del tiempo
    timeList->linkendRainTime("5",1662098400,rainList,timeList);// 02 / 09 / 2022
    timeList->linkendRainTime("1",1662703200,rainList,timeList); // 09 / 09 / 2022
    timeList->linkendRainTime("8",1662012000,rainList,timeList); //01 / 09 / 2022
    timeList->linkendRainTime("2",1662357600,rainList,timeList); //05 / 09 / 2022
    timeList->linkendRainTime("9",1581228000,rainList,timeList);//09 / 02 / 2020
    timeList->linkendRainTime("3",1583301600,rainList,timeList);// 04 / 03 / 2020
    timeList->linkendRainTime("9",1584338400,rainList,timeList); //16 / 03 / 2020
    timeList->linkendRainTime("3",1586152800,rainList,timeList);// 06 / 04 / 2020
    timeList->linkendRainTime("4",1588917600,rainList,timeList);// 08 / 05 / 2020
    timeList->linkendRainTime("1",1594533600,rainList,timeList);// 12 / 07 / 2020
    timeList->linkendRainTime("5",1598335200,rainList,timeList);// 25 / 08 / 2020
    timeList->linkendRainTime("6",1603065600,rainList,timeList);// 18 / 10 / 2020
    timeList->linkendRainTime("7",1605852000,rainList,timeList);// 20 / 11 / 2020
    timeList->linkendRainTime("10",1607493600,rainList,timeList); //09 / 12 / 2020
    timeList->linkendRainTime("10",1662444000,rainList,timeList); //
    //Enlace de la sublista registros del tiempo de lugares
    placeList->linkendTimePlace("San Carlos",1607493600,time,place); //09 / 12 / 2020
    placeList->linkendTimePlace("San Carlos",1605852000,time,place); // 20 / 11 / 2020
    placeList->linkendTimePlace("San Carlos",1603065600,time,place); // 18 / 10 / 2020
    placeList->linkendTimePlace("San Carlos",1600236000,time,place); // 16 / 09 / 2020
    placeList->linkendTimePlace("San Carlos",1598335200,time,place); // 25 / 08 / 2020
    placeList->linkendTimePlace("San Carlos",1597557600,time,place); // 16 / 08 / 2020
    placeList->linkendTimePlace("San Carlos",1596520800,time,place); // 04 / 08 / 2020
    placeList->linkendTimePlace("San Carlos",1594533600,time,place); // 12 / 07 / 2020
    placeList->linkendTimePlace("San Carlos",1657432800,time,place); // 10 / 07 / 2022
    placeList->linkendTimePlace("San Carlos",1591768800,time,place); // 10 / 06 / 2020
    placeList->linkendTimePlace("San Carlos",1588917600,time,place); // 08 / 05 / 2020
    placeList->linkendTimePlace("San Carlos",1587621600,time,place); // 23 / 04 / 2020
    placeList->linkendTimePlace("San Carlos",1586152800,time,place); // 06 / 04 / 2020
    placeList->linkendTimePlace("San Carlos",1584338400,time,place); // 16 / 03 / 2020
    placeList->linkendTimePlace("San Carlos",1583301600,time,place); // 04 / 03 / 2020
    placeList->linkendTimePlace("San Carlos",1580623200,time,place); // 02 / 02 / 2020
    placeList->linkendTimePlace("San Carlos",1581228000,time,place); // 09 / 02 / 2020
    placeList->linkendTimePlace("San Carlos",1577944800,time,place); // 02 / 01 / 2020
    placeList->linkendTimePlace("Guatuso",1662271200,time,place);//04 / 09 / 2022.
    placeList->linkendTimePlace("Guatuso",1662357600,time,place);//05 / 09 / 2022.
    placeList->linkendTimePlace("Guatuso",1662444000,time,place);//06 / 09 / 2022
    placeList->linkendTimePlace("Palmares",1662530400,time,place);//07 / 09 / 2022
    placeList->linkendTimePlace("Palmares",1662616800,time,place);//08 / 09 / 2022
    placeList->linkendTimePlace("Palmares",1662703200,time,place);//09 / 09 / 2022.
    placeList->linkendTimePlace("Naranjo",1662789600,time,place);//10 / 09 / 2022
    placeList->linkendTimePlace("Naranjo",1568095200,time,place);// 10 / 09 / 2019

}



/**
 * Función principal del programa,llama a las demás funciones y es la que se ejecuta primero.
 */
int main()
{
    int year=0;
    int year2=0;
    string plc,idReg,idPerson,idRain;
    short month=0;
    short day;
    long int registrationDate;

    char c; //OPCION DEL MENU PREINCIPAL
    char p; //OPCION DE LAS LISTAS
    char b; //OPCION DE LISTAS EN REPORTES

    //SE CARGAN DATOS A LAS LISTAS
    placeList=placeList->dataLoad(placeList);
    regionList=regionList->dataLoad(regionList);
    timeList=timeList->dataLoad(timeList);
    rainList=rainList->dataLoad(rainList);
    ephemeralityList=ephemeralityList->dataLoad(ephemeralityList);;
    peopleList=peopleList->dataLoad(peopleList);

    //SE CARGAN DATOS A LAS SUBLISTAS
    dataLoadSublist(placeList,regionList,peopleList,timeList,rainList);

    while(true){

        welcome();
        cout<<"\n\t\tELIGA UNA OPCION:";
        cin>>c;

            if(c=='1'){//AGREGAR EN LAS LISTAS

                optionListSublis();
                cout<<"\n\t\tELIGA UNA OPCION:";
                cin>>p;

                if(p=='1'){ // AGREGAR EN LISTA PERSONA
                    userLogin();
                }
                else if(p=='2'){ // AGREGAR EN LISTA LLUVIA
                    rainLogin();
                }
                else if(p=='3'){ // AGREGAR EN LISTA REGIONES
                    regionLogin();
                }
                else if(p=='4'){ // AGREGAR EN LISTA LUGARES
                    placeLogin();
                }
                else if(p=='5'){ // AGREGAR EN LISTA EFEMERIDAD
                    ephemeralityLogin();
                }
                else if(p=='6'){ // AGREGAR EN LISTA EFEMERIDAD
                    timeLogin();
                }
            }
            else if(c=='2'){//MODIFICAR EN LAS LISTA
                optionListSublis();
                cout<<"\n\t\tELIGA UNA OPCION:";
                cin>>p;

                if(p=='1'){ // MODIFICAR EN LISTA PERSONA
                    modPeople();
                }
                else if(p=='2'){ // MODIFICAR EN LISTA LLUVIA
                    modifyRain();
                }
                else if(p=='3'){ // MODIFICAR EN LISTA REGIONES
                    modifyRegion();
                }
                else if(p=='4'){ // MODIFICAR EN LISTA LUGARES
                    modifyPlace();
                }
                else if(p=='5'){ // MODIFICAR EN LISTA EFEMERIDAD
                    modEphemerality();
                }
                else if(p=='6'){ // MODIFICAR EN LISTA REGISTROS DEL TIEMPO
                    modifyTimeRegis();
                }
            }
            else if(c=='3'){//BORARR NODO EN LAS LISTAS
                optionListSublis();
                cout<<"\n\t\tELIGA UNA OPCION:";
                cin>>p;
                if(p=='1'){ // BORRAR EN LISTA PERSONA
                    cout<<"\n\t\tINGRESE EL ID DE LA PERSONA QUE DESEA ELIMINAR: ";
                    cin>>idPerson;
                    peopleList=peopleList->deletePeople(peopleList,idPerson);
                }
                else if(p=='2'){ // BORRAR EN LISTA LLUVIA
                    cout<<"\n\t\tINGRESE EL ID DEL CLIMATICO QUE DESEA ELIMINAR: ";
                    cin>>idRain;
                    rainList=rainList->deleteRain(rainList,idRain);
                }
                else if(p=='3'){ // BORRAR EN LISTA REGIONES
                    cout<<"\n\t\tINGRESE EL ID DE LA REGION QUE DESEA ELIMINAR: ";
                    cin>>idReg;
                    regionList=regionList->deleteRegion(idReg,regionList);
                }
                else if(p=='4'){ // BORRAR EN LISTA LUGARES
                    cout<<"\n\t\tINGRESE EL NOMBRE DEL LUGAR QUE DESEA ELIMINAR: ";
                    getline(cin>>ws, plc);
                    //placeList=placeList->deletePlace(plc,placeList);
                }
                else if(p=='5'){ // BORRAR EN LISTA EFEMERIDAD
                    cout << "\n\t\tINGRESE LA FECHA DE LA EFIMERIDAD QUE DESEA ELIMINAR";
                    do{
                        cout << "\n\t\tDIA (dd): ";
                        cin>>day;
                        cout << "\t\tMES (mm): ";
                        cin>>month;
                        cout << "\t\tYEAR (yy): ";
                        cin>>year;
                    }while(!valDate(day, month, year));

                    registrationDate=ephemeralityList->dateToUnixDate(year,month,day);
                    ephemeralityList=ephemeralityList->deleteEphemerality(registrationDate,ephemeralityList);
                }
                else if(p=='6'){ // BORRAR EN LISTA REGISTROS DEL TIEMPO
                    cout << "\n\t\tINGRESE LA FECHA DEL REGISTRO TIEMPO QUE DESEA ELIMINAR";
                    do{
                        cout << "\n\t\tDIA (dd): ";
                        cin>>day;
                        cout << "\t\tMES (mm): ";
                        cin>>month;
                        cout << "\t\tYEAR (yy): ";
                        cin>>year;
                    }while(!valDate(day, month, year));

                    registrationDate=timeList->dateToUnixDate(year,month,day);
                    timeList=timeList->deleteTime(registrationDate,timeList);
                }
            }
            else if(c=='4'){ //VER CONSULTAS
                consults();
                cout<<"\n\t\tELIGA UNA OPCION:";
                cin>>p;
                if(p=='1'){ // VER SALIDA MAS TEMPANA Y OSCULTAMIENTO MAS TARDIO DEL SOL
                    ephemeralityList->earlyDeparLateHide(ephemeralityList);
                }
                else if(p=='2'){ // VER DIFERENCIAS EN LA SALIDA DEL SOL

                    cout<<"\n\t\tINGRESE EL YEAR EN LA QUE DESEA VER LAS DIFERENCIAS DE FECHAS: ";
                    cin>>year;
                    ephemeralityList->diffDepartureTime(year,ephemeralityList);
                }
                else if(p=='3'){ // VER MES CON MAS EXTREMOS CLIMATICOS
                    cout<<"\n\t\tINGRESE EL NOMBRE DEL LUGAR QUE DESEA CONSULTAR: ";
                    getline(cin>>ws, plc);
                    cout<<"\n\t\tINGRESE EL YEAR QUE DESEA CONSULTAR: ";
                    cin>>year;
                    placeList->monthlyRainfallExtremes(plc,year,placeList);
                }
                else if(p=='4'){ // VER PERSONA CON MAS REGISTROS
                    peopleList->getSizeSublist(peopleList);
                    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
                    cin.ignore();
                    cin.get();
                }
            }
            else if(c=='5'){//VER REPORTES
                reports();
                cout<<"\n\t\tELIGA UNA OPCION:";
                cin>>p;
                if(p=='1'){ // MOSTRAR TODAS LAS LISTAS
                    optionListSublis();
                    cout<<"\n\t\tELIGA UNA OPCION:";
                    cin>>b;
                    if(b=='1'){ // IMPRIME LA LISTA PERSONA
                        system("cls");
                        peopleList->printPeopleList(peopleList);
                    }
                    else if(b=='2'){ // IMPRIME LA LISTA LLUVIA
                        system("cls");
                        rainList->printRainList(rainList);
                    }
                    else if(b=='3'){ // IMPRIME LA LISTA REGIONES
                        system("cls");
                        regionList->print(regionList);
                    }
                    else if(b=='4'){ // IMPRIME LA LISTA LUGARES
                        system("cls");
                        placeList->print(placeList);
                    }
                    else if(b=='5'){ // IMPRIME LA LISTA EFEMERIDAD
                            system("cls");
                        ephemeralityList->printEphemeralityList(ephemeralityList);
                    }
                    else if(b=='6'){ // IMPRIME LA LISTA DE REGISTROS DEL TIEMPO
                        system("cls");
                        timeList->print(timeList);
                    }
                }
                else if(p=='2'){//HORARIOS DE LA SALIDA Y PUESTA DEL SOL
                    cout<<"\n\t\tINGRESE EL YEAR QUE DESEA CONSULTAR: ";
                    cin>>year;
                    ephemeralityList->timeReportYear(ephemeralityList,year);
                }
                else if(p=='3'){// PRECIPITACION MENSUAL DE UN LUGAR
                    cout<<"\n\t\tINGRESE EL NOMBRE DEL LUGAR QUE DESEA CONSULTAR: ";
                    getline(cin>>ws, plc);
                    cout<<"\n\t\tINGRESE EL YEAR QUE DESEA CONSULTAR: ";
                    cin>>year;
                    placeList->monthlyRain(year,plc,placeList);
                }
                else if(p=='4'){// PRECIPITACION MENSUAL DE UN LUGAR
                    cout<<"\n\t\tINGRESE EL ID DE LA REGION QUE DESEA CONSULTAR: ";
                    getline(cin>>ws, idReg);
                    cout<<"\n\t\tINGRESE EL YEAR QUE DESEA CONSULTAR: ";
                    cin>>year;
                    regionList->monthlyRain(year,idReg,regionList);

                }
                else if(p=='5'){// VARIABLES CLIAMATOLOGICAS DE UNA REGION
                    cout<<"\n\t\tINGRESE EL ID DE LA REGION QUE DESEA CONSULTAR: ";
                    getline(cin>>ws, idReg);
                    cout<<"\n\t\tINGRESE EL YEAR QUE INICIA EL RANGO: ";
                    cin>>year;
                    cout<<"\n\t\tINGRESE EL YEAR QUE FINALIZA EL RANGO: ";
                    cin>>year2;
                    regionList->printVarWeather(idReg,year,year2,regionList);
                }
                else if(p=='6'){// PERIODOS DEL CLIMA
                    system("cls");
                    cout<<"\n\t\tESTA FUNCION POR EL MOMENTO NO ESTA DISPONIBLE :)\n";
                    cout<<"\n\t\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
                    cin.ignore();
                    cin.get();
                }
                else if(p=='7'){ //LOS PORCENTAJES DE LA CLASIFICACION DE LA LLUVIA
                    cout<<"\n\t\tINGRESE EL NOMBRE DEL LUGAR QUE DESEA CONSULTAR: ";
                    getline(cin>>ws, plc);
                    cout<<"\n\t\tINGRESE EL YEAR QUE DESEA CONSULTAR: ";
                    cin>>year;
                    placeList->printPercentageRain(year,plc,placeList);
                }
                else if(p=='8'){ // DIAS DE LLUVIA EN UN LUGAR
                    cout<<"\n\t\tINGRESE EL NOMBRE DEL LUGAR QUE DESEA CONSULTAR: ";
                    getline(cin>>ws, plc);
                    cout<<"\n\t\tINGRESE EL YEAR QUE DESEA CONSULTAR: ";
                    cin>>year;
                    placeList->printRainyDays(year,plc,placeList);

                }
                else if(p=='9'){//EXTREMOS DE TEMPERATURA DE UN LUGAR
                    cout<<"\n\t\tINGRESE EL NOMBRE DEL LUGAR QUE DESEA CONSULTAR: ";
                    getline(cin>>ws, plc);
                    cout<<"\n\t\tINGRESE EL YEAR QUE DESEA CONSULTAR: ";
                    cin>>year;
                    placeList->extremeTemp(year,plc,placeList);
                }
            }

            else if(c=='0'){ //SALIR
                system("cls");
                cout << "\n\t\t       GRACIAS POR USAR ESTE SISTEMA"<<endl;
                cout <<endl;
                cout <<"\n\t\t   PROYECTO 1  ESTRUCTURAS DIAMICAS LINEALES\n";
                cout<<"\n\t\t\t   =========================================\n";
                cout<<"\n\t\t\t   MIEMBROS DEL GRUPO (DESARROLLADORES)";
                cout << "\n\n";
                cout << "\n\t\t\t   NOMBRE                        CARNET\n\n";
                cout << "\n\t\t\t   1. lEINER ALVARADO           2022437759\n\n";
                cout << "\n\t\t\t   2. KARINA URBINA             2022038549\n\n";
                cout<<"\n\t\t\t   =========================================\n";
                cout<<"\n\t\t\t   START DATE: 12/09/2022\n";
                cout<<"\n\t\t\t   END DATE: 08/10/2022 ";
                cout << "\n\n";
                break;

            }

            year=0;
            year2=0;
            plc= "";
            idReg= "";
            idPerson= "";
            idRain= "";
            month=0;
            day=0;
            registrationDate=0;
        }

    return 0;

}
