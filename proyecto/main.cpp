#include <iostream>
#include <ctime>

/* Iniciado: 12/09/2022 Ultima modificacion:
    Autor: Kari Urbina

*/

using namespace std;

//Registro del Tiempo -> SUBLISTA DEL TIEMPO
struct TimeRegis{

    string registrationDate;
    int precipitation;
    float maxTemperature;
    float minTemperature;
    int windSpeed;
    int windDirection;
    int humidity;
    bool yesRained=false;

    TimeRegis* next;

    //Constructor de Registro Tiempo
    TimeRegis(string dateR,int precip,float maxTemp, float minTemp,int winSpd, int windDirec,int humidity,bool rained){

    registrationDate = dateR;
    precipitation = precip;
    maxTemperature = maxTemp;
    maxTemperature = minTemp;
    windSpeed = winSpd;
    windDirection = windDirec;
    humidity = humidity;
    yesRained = rained;

    }



} * TimeRegisList;


//Lugar -> LISTA CIRCULAR
struct Place {
    string name;
    string population;
    float squareMeters;

    Place * next;
    //Constructor de Lugar
    Place( string n,string p,float meters){
    name = n ;
    population = p;
    squareMeters = meters;

    }

} * placeList;

//Region -> LISTA SIMPLE
struct Region {

    string idRegion;
    string name;
    string location;

    Region * next;

    //Constructor de Region
    Region(string id,string n, string l){
    idRegion = id;
    name = n;
    location = l;

    }

} *regionList;




int main()
{
    cout << "ESTO ES UNA PRUEBA!" << endl;
    return 0;
}
