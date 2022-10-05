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



/**/
/*
    Autor: Karina Urbina
    Iniciado: 12/09/2022
    Avance1: 16/09/2022
    Ultima modificacion:

*/

using namespace std;


Place* placeList;
Region* regionList;
TimeRegis* timeList;
Rain* rainList;
People* peopleList;
Ephemerality* ephemeralityList;

//new code


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
        cout<<"Formato de fecha incorrecto!."<<endl;
    }
    return flag;
}

void userLogin(){
    system("cls");
    cout<<"\t\t======================================================"<<endl;
    cout<<"\t\t\t\t  LISTA DE PERSONAS  "<<endl;
    cout<<"\t\t======================================================"<<endl;
    cout<<endl;

    string namePerson,idPerson,residence,yearIncome;
    short age;

    cout << "\n\t\tINGRESE SU NOMBRE: ";
    cin>>namePerson;

    cout << "\n\t\tINGRESE SU CEDULA: ";
    cin>>idPerson;

    cout << "\n\t\tINGRESE SU EDAD: ";
    cin>>age;

    cout << "\n\t\tINGRESE SU LUGAR DE RESIDENCIA: ";
    getline(cin>>ws, residence);

    cout << "\n\t\tINGRESE EL YEAR EN EL QUE ESTA INGRESANDO: ";
    cin>>yearIncome;

    peopleList=peopleList->addPeople(namePerson,idPerson,age,residence,yearIncome,peopleList);
    cout << "\n\t\tSUS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE PERSONAS... ";

    Sleep(3000);

}

//REGISTRO DE UN LUGAR
void placeLogin(){
    system("cls");
    cout<<"\t\t======================================================"<<endl;
    cout<<"\t\t\t\t  LISTA DE LUGARES  "<<endl;
    cout<<"\t\t======================================================"<<endl;
    cout<<endl;
    string namePlace;
    int population;
    float area;

    cout << "\n\t\tINGRESE EL NOMBRE DEL LUGAR: ";
    getline(cin>>ws, namePlace);

    cout << "\n\t\tINGRESE LA POBLACION DEL LUGAR: ";
    cin>>population;

    cout << "\n\t\tINGRESE EL AREA DEL LUGAR: ";
    cin>>area;

    placeList=placeList->add(namePlace,population,area,placeList);
    cout << "\n\t\tLOS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE LUGARES... ";

}

//REGISTRO DE UNA REGION
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
    cout << "\n\t\tLOS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE REGIONES... ";

}

//REGISTRO DE LLUVIA
void rainLogin(){
    system("cls");
    cout<<"\t\t======================================================"<<endl;
    cout<<"\t\t\t\t  LISTA DE LLUVIAS  "<<endl;
    cout<<"\t\t======================================================"<<endl;
    cout<<endl;

    string nameRain,rainCode;
    int averageRange;// Rango promedio en mm

    cout << "\n\t\tINGRESE EL NOMBRE DEL ESCENARIO CLIMATICO: ";
    cin>>nameRain;

    cout << "\n\t\tINGRESE EL CODIGO DEL ESCENARIO CLIMATICO: ";
    cin>>rainCode;

    cout << "\n\t\tINGRESE EL RANGO PROMEDIO EN MILIMEMTROS(mm): ";
    cin>>averageRange;

    rainList=rainList->addRain(rainCode,nameRain,averageRange,rainList);
    cout << "\n\t\tLOS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE LLUVIA... ";


}


//REGISTRO DE EFEMERIDAD
void ephemeralityLogin(){
    system("cls");
    cout<<"\t\t======================================================"<<endl;
    cout<<"\t\t\t\t  LISTA DE EPHEMERIDADES  "<<endl;
    cout<<"\t\t\t======================================================"<<endl;
    cout<<endl;

    string nameEp;
    short hourDeparture,minutesDeparture,hourHide,minutesHide,month,day;
    long int date;
    int year,departureTime,hideTime;


    cout << "\n\t\tINGRESE EL NOMBRE DE LA EFEMERIDAD: ";
    cin>>nameEp;

    cout << "\n\t\tINGRESE LA FECHA DE LA EFEMERIADAD";

    do{
        cout << "\n\t\tDIA: ";

        cin>>day;
        cout << "\t\tMES: ";
        cin>>month;
        cout << "\t\tYEAR: ";
        cin>>year;
    }while(!valDate(day, month, year));
    date=ephemeralityList->dateToUnixDate(year,month,day);
    do{
        cout << "\n\t\tINGRESE LA HORA DE SALIDA";

        cout << "\n\t\tHORA: ";
        cin>>hourDeparture;
        cout << "\t\tMINUTOS: ";
        cin>>minutesDeparture;
        cout << "\n\t\tINGRESE HORA DE OCULTAMIENTO: ";
        cout << "\n\t\tHORA: ";
        cin>>hourHide;
        cout << "\t\tMINUTOS: ";
        cin>>minutesHide;

    }while(ephemeralityList->valTime(hourDeparture,minutesDeparture,hourHide,minutesHide));


    departureTime=ephemeralityList->timeToSeconds(hourDeparture,minutesDeparture);



    hideTime=ephemeralityList->timeToSeconds(hourHide,minutesHide);


    ephemeralityList=ephemeralityList->addEphemerality(nameEp,date,departureTime,hideTime,ephemeralityList);
    cout << "\n\t\tLOS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE EFEMERIDAD... ";

}

//REGISTRO DEL TIEMPO/CLIMA
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

    cout << "\n\t\tINGRESE LA FECHA DEL REGISTRO";
    do{
        cout << "\n\t\tDIA: ";

        cin>>day;
        cout << "\t\tMES: ";
        cin>>month;
        cout << "\t\tYEAR: ";
        cin>>year;
    }while(!valDate(day, month, year));


    registrationDate=ephemeralityList->dateToUnixDate(year,month,day);

    cout << "\n\t\tINGRESE PRECIPITACION: ";
    cin>>precipitation;

    cout << "\n\t\tINGRESE LA TEMPERATURA MAXIMA: ";
    cin>>maxTemperature;

    cout << "\n\t\tINGRESE LA TEMPERATURA MINIMA ";
    cin>>minTemperature;

    cout << "\n\t\tINGRESE LA VELOCIDAD DEL VIENTO: ";
    cin>>windSpeed;

    cout << "\n\t\tINGRESE LA DIRECCION DEL VIENTO(Grados): ";
    cin>>windDirection;

    cout << "\n\t\tINGRESE LA HUMEDAD RELATIVA: ";
    cin>>humidity;

    cout << "\n\t\tLLOVIO?(true/false): ";
    cin>>yesRained;

    timeList=timeList->add(registrationDate,precipitation,maxTemperature,minTemperature,windSpeed,windDirection,humidity,yesRained,timeList);
    cout << "\n\t\tLOS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE REGISTORS DEL TIEMPO... ";

}


//New code

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









//Bienvenida al sistema
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
    cout<<"\t\t4.BORRAR COMPLETAMENTE UNA LISTA \n\n";
    cout<<"\t\t5.MOSTRAR CONSULTAS\n\n";
    cout<<"\t\t6.VER REPORTES\n\n";
    cout<<"\t\t0.SALIR\n\n";

    //cout<<"press any key to continue...";
    //cin.ignore();
    //cin.get();
}

//Imprime la sublista de lugares de una region especifica
void dataLoadSublist(Place*place,Region*region,People*people,TimeRegis*time,Rain*rain){

    //Datos quemados en SUBLISTA LUGAR-REGION
    regionList->linkendPlaceRegion("NA","San Carlos",place,region);
    regionList->linkendPlaceRegion("NA","Naranjo",place,region);
    regionList->linkendPlaceRegion("NA","Guatuso",place,region);
    regionList->linkendPlaceRegion("VC","Escazu",place,region);
    regionList->linkendPlaceRegion("CGT","Liberia",place,region);
    regionList->linkendPlaceRegion("UC","Guatuso",place,region);
    regionList->linkendPlaceRegion("UC","Los Chiles",place,region);
    regionList->linkendPlaceRegion("NA","Palmares",place,region);
    regionList->linkendPlaceRegion("T","Talamanca",place,region);
    //regionList->linkendPlaceRegion("NA","Guatuso",place,region);

    //Datos quemados en SUBLISTA PERSONA-TIEMPO

    //LEINER tiene 4 REGISTROS DEL TIEMPO
    peopleList->linkendTimePeople("202204",1662012000,time,people); // 01 / 09 / 2022
    peopleList->linkendTimePeople("202204",1662098400,time,people); //02 / 09 / 2022
    peopleList->linkendTimePeople("202204",1662357600,time,people); //05 / 09 / 2022
    peopleList->linkendTimePeople("202204",1662616800,time,people); // 08 / 09 / 2022

    //SARA tiene 2 REGISTROS DEL TIEMPO
    //peopleList->linkendTimePeople("202205",1662616800,time,people); // 08 / 09 / 2022
    //peopleList->linkendTimePeople("202205",1662616800,time,people); // 08 / 09 / 2022

    //TOMMY tiene 1 REGISTROS DEL TIEMPO
    //peopleList->linkendTimePeople("202206",1662616800,time,people); //08 / 09 / 2022
    //KARINA tiene 3 REGISTROS DEL TIEMPO
    peopleList->linkendTimePeople("202207",1662703200,time,people); // 09 / 09 / 2022
    peopleList->linkendTimePeople("202207",1662789600,time,people); // 10 / 09 / 2022
    peopleList->linkendTimePeople("202207",1662012000,time,people); // 01 / 09 / 2022


    //Datos quemados en SUBLISTA LUGAR-REGISTRO TIEMPO
    placeList->linkendTimePlace("San Carlos",1662357600,time,place); //05 / 09 / 2022
    placeList->linkendTimePlace("San Carlos",1662271200,time,place); //04 / 09 / 2022
    placeList->linkendTimePlace("San Carlos",1662184800,time,place); // 03 / 09 / 2022
    placeList->linkendTimePlace("San Carlos",1662098400,time,place); // 02 / 09 / 2022
    placeList->linkendTimePlace("San Carlos",1662012000,time,place); // 01 / 09 / 2022

    placeList->linkendTimePlace("San Carlos",1671688800,time,place); // 22 / 12 / 2020
    placeList->linkendTimePlace("San Carlos",1605852000,time,place); // 20 / 11 / 2020
    placeList->linkendTimePlace("San Carlos",1603065600,time,place); // 18 / 10 / 2020
    placeList->linkendTimePlace("San Carlos",1600236000,time,place); // 16 / 09 / 2020
    placeList->linkendTimePlace("San Carlos",1659592800,time,place); // 04 / 08 / 2020
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
    placeList->linkendTimePlace("San Carlos",1577772000,time,place); // 31 / 12 / 2019
    placeList->linkendTimePlace("Guatuso",1662789600,time,place); //10 / 09 / 2022
    placeList->linkendTimePlace("Guatuso",1662703200,time,place); //09 / 09 / 2022
    placeList->linkendTimePlace("Guatuso",1662616800,time,place); //08 / 09 / 2022
    placeList->linkendTimePlace("Guatuso",1662530400,time,place); //07 / 09 / 2022
    placeList->linkendTimePlace("Guatuso",1662444000,time,place); //06 / 09 / 2022


    placeList->linkendTimePlace("Naranjo",1568095200,time,placeList); //10 / 09 / 2019

    //Datos quemados en SUBLISTA REGISTRO TIEMPO- LLUVIA

    timeList->linkendRainTime("1",1662098400,rainList,time); // 02 / 09 / 2022
    timeList->linkendRainTime("3",1657432800,rainList,time); // 10 / 07 / 2022
    timeList->linkendRainTime("1",1662703200,rainList,time); //09 / 09 / 2022
    timeList->linkendRainTime("5",1662271200,rainList,time); //04 / 09 / 2022
    timeList->linkendRainTime("10",1662012000,rainList,time); //01 / 09 / 2022
    timeList->linkendRainTime("2",1662357600,rainList,time); // 05 / 09 / 2022

    //placeList->linkendTimePlace("San Carlos",1662012000,time,place);// 01 / 09 / 2022
    placeList->linkendTimePlace("Palmares",1662098400,time,place);  //02 / 09 / 2022
    placeList->linkendTimePlace("Upala",1662184800,time,place);     // 03 / 09 / 2022
    placeList->linkendTimePlace("Naranjo",1662271200,time,place);   //  04 / 09 / 2022
    placeList->linkendTimePlace("Liberia",1662357600,time,place);   // 05 / 09 / 2022
    //placeList->linkendTimePlace("San Carlos",1662444000,time,place);// 06 / 09 / 2022
    placeList->linkendTimePlace("Palmares",1662530400,time,place);  // 07 / 09 / 2022
    placeList->linkendTimePlace("Los Chiles",1662616800,time,place);// 08 / 09 / 2022
    placeList->linkendTimePlace("Guatuso",1662703200,time,place);   // 09 / 09 / 2022
    placeList->linkendTimePlace("Talamanca",1662789600,time,place); // 10 / 09 / 2022

    timeList->linkendRainTime("1",1662098400,rainList,timeList);
    timeList->linkendRainTime("3",1657432800,rainList,timeList);
    timeList->linkendRainTime("1",1662703200,rainList,timeList);
    timeList->linkendRainTime("5",1662271200,rainList,timeList);
    timeList->linkendRainTime("10",1662012000,rainList,timeList);
    timeList->linkendRainTime("2",1662357600,rainList,timeList);
    timeList->linkendRainTime("2",1672552800,rainList,time);//01/01/2023
    timeList->linkendRainTime("5",1675231200,rainList,time);//01/02/2023
    timeList->linkendRainTime("4",1690869600,rainList,time);//01/03/2023




    placeList->linkendTimePlace("Palmares",1672552800,time,place);//01/01/2023
    placeList->linkendTimePlace("Palmares",1675231200,time,place);//01/02/2023
    placeList->linkendTimePlace("Palmares",1690869600,time,place);//01/03/2023
    placeList->linkendTimePlace("Palmares",1691042400,time,place);//03/08/2023
    //placeList->linkendTimePlace("Palmares",1701756000,time,place);//05/12/2023
    //Datos quemados en SUBLISTA REGISTRO TIEMPO- LLUVIA

    /*timeList->linkendRainTime("1",1662789600,rain,time); // 10 / 09 / 2022
    timeList->linkendRainTime("1",1662444000,rain,time); // 06 / 09 / 2022
    timeList->linkendRainTime("1",1662703200,rain,time); // 09 / 09 / 2022
    timeList->linkendRainTime("1",1662098400,rain,time); // 02 / 09 / 2022
    timeList->linkendRainTime("1",1662271200,rain,time); // 04 / 09 / 2022
    timeList->linkendRainTime("1",1662357600,rain,time); // 05 / 09 / 2022
    */
    timeList->linkendRainTime("1",1662357600,rain,time); //05 / 09 / 2022
    timeList->linkendRainTime("1",1662271200,rain,time); //04 / 09 / 2022
    timeList->linkendRainTime("1",1662184800,rain,time); // 03 / 09 / 2022
    timeList->linkendRainTime("3",1662098400,rain,time); // 02 / 09 / 2022
    timeList->linkendRainTime("1",1662012000,rain,time); // 01 / 09 / 2022
    timeList->linkendRainTime("1",1577772000,rain,time); // 31 / 12 / 2019
    timeList->linkendRainTime("1",1671688800,rain,time); // 22 / 12 / 2020
    timeList->linkendRainTime("1",1605852000,rain,time); // 20 / 11 / 2020
    timeList->linkendRainTime("1",1603065600,rain,time); // 18 / 10 / 2020
    timeList->linkendRainTime("1",1600236000,rain,time); // 16 / 09 / 2020
    timeList->linkendRainTime("1",1594533600,rain,time); // 14 / 08 / 2020
    timeList->linkendRainTime("1",1594533600,rain,time); // 12 / 07 / 2020
    timeList->linkendRainTime("1",1657432800,rain,time); // 10 / 07 / 2022
    timeList->linkendRainTime("1",1591768800,rain,time); // 10 / 06 / 2020
    timeList->linkendRainTime("1",1588917600,rain,time); // 08 / 05 / 2020
    timeList->linkendRainTime("1",1587621600,rain,time); // 23 / 04 / 2020
    timeList->linkendRainTime("1",1586152800,rain,time); // 06 / 04 / 2020
    timeList->linkendRainTime("1",1584338400,rain,time); // 16 / 03 / 2020
    timeList->linkendRainTime("1",1583301600,rain,time); // 04 / 03 / 2020
    timeList->linkendRainTime("1",1580623200,rain,time); // 02 / 02 / 2020
    timeList->linkendRainTime("1",1581228000,rain,time); // 09 / 02 / 2020
    timeList->linkendRainTime("1",1577944800,rain,time); // 02 / 01 / 2020





    timeList->linkendRainTime("2",1672552800,rain,time);
    timeList->linkendRainTime("3",1675231200,rain,time);
    timeList->linkendRainTime("1",1690869600,rain,time);
    timeList->linkendRainTime("5",1701756000,rain,time);





}











int main()
{
    //SE CARGAN DATOS A LAS LISTAS

    placeList=placeList->dataLoad(placeList);
    regionList=regionList->dataLoad(regionList);
    timeList=timeList->dataLoad(timeList);
    rainList=rainList->dataLoad(rainList);
    ephemeralityList=ephemeralityList->dataLoad(ephemeralityList);;
    peopleList=peopleList->dataLoad(peopleList);

    //timeList->print(timeList);

    //SE CARGAN DATOS A LAS SUBLISTAS
    dataLoadSublist(placeList,regionList,peopleList,timeList,rainList);
    //peopleList->getSizeSublist(peopleList);
    //peopleList->printSublistTime("202206",peopleList);
   //regionList->printSublistPlace("T",regionList);
    //timeList->printSubRain(1662789600,timeList);
   //placeList->printSubTimePlace("San Carlos",placeList);
    placeList->MonthlyRain(2021,placeList);
    //regionList->MonthlyRain(2022,regionList);
    //rainList->printRainList(rainList);
    //placeList->timeRegiSublist->linkTime->printSubRain(1662789600,timeList);
    placeList->printRainyDays(2020,"San Carlos",placeList);
    //placeList->printPercentageRain(2022,"San Carlos",placeList);
    //placeList->print(placeList);
    //Region*r = regionList->searchRegion("NA",regionList);
    //r->placeSublist->linkPlace->modify("San Carlos","Santa Clara",2500,456.07,placeList);
    //placeList->print(placeList);
    placeList->printRainyDays(2023,"Palmares",placeList);
    //placeList->printPercentageRain(2023,"Palmares",placeList);
    //regionList->printVarWeather("NA",2021,2022,regionList);

    //placeList->printPercentageRain(2023,"Palmares",placeList);

    //placeList->printSubTimePlace("San Carlos",placeList);
    //placeList->monthlyRainfallExtremes("San Carlos",2022,placeList);
    //placeList->printRainyDays(2020,"San Carlos",placeList);











/*
    char c; //OPCION DEL MENU PREINCIPAL
    char p; //OPCION DE LAS LISTAS
    char b; //OPCION DE LISTAS EN REPORTES
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

            if(c=='2'){//MODIFICAR EN LAS LISTA
                optionListSublis();
                cin>>p;

            }
            else if(c=='3'){//BORARR NODO EN LAS LISTAS
                optionListSublis();
                cout<<"\n\t\tELIGA UNA OPCION:";
                cin>>p;

            }
            else if(c=='4'){ //BORRAR TODA LA LISTA
                optionListSublis();
                cout<<"\n\t\tELIGA UNA OPCION:";
                cin>>p;
            }
            else if(c=='5'){ //VER CONSULTAS
                consults();
                cout<<"\n\t\tELIGA UNA OPCION:";
                cin>>p;
                if(p=='4'){
                    peopleList->getSizeSublist(peopleList);

                }

            }
            else if(c=='6'){//VER REPORTES
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



            }
            else if(c=='0'){ //SALIR
                system("cls");
                cout << "\n\t\t       GRACIAS POR USAR ESTE SISTEMA"<<endl;
                cout <<endl;
                cout <<"\n\t\t   PROYECTO 1  ESTRUCTURAS DIAMICAS LINEALES\n";
                cout<<"\n\t\t\   =========================================\n";
                cout<<"\n\t\t\   MIEMBROS DEL GRUPO (DESARROLLADORES)";
                cout << "\n\n";
                cout << "\n\t\t\   NOMBRE                        CARNET\n\n";
                cout << "\n\t\t\   1. lEINER ALVARADO           202200000\n\n";
                cout << "\n\t\t\   2. KARINA URBINA             208460025\n\n";
                cout<<"\n\t\t\   =========================================\n";
                cout<<"\n\t\t\   START DATE: 12/09/2022\n";
                cout<<"\n\t\t\   END DATE: 07/10/2022 ";
                cout << "\n\n";
                break;

            }

        }
*/
    return 0;

}
