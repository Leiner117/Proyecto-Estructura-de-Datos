#include <iostream>

using namespace std;

/*
Creado:12/09/2022 Ultima mod: 12/09/2022
Autor: Leiner Alvarado
*/


/*
Estructura persona
*/
struct People{

    string name;// Nombre
    string id;// Cedula
    short age;// edad
    string placeResidence;// Lugar de residencia
    string yearIncome;// Año ingreso
    People*next;// Siguiente
    People*pre;// Anterior


    People(string n,ide,ag,place,year){
        name = n;
        id = ide;
        age = ag;
        placeResidence = place;
        yearIncome = year;
        next = NULL;
        pre = NULL;

    }

}*peopleList;//Lista de personas






/*
Estructura de Lluvia
*/
struct Rain{
    string rainCode;// Codigo de la lluvia
    string name;// Nombre
    int averageRange;// Rango promedio en mm
    Rain*next;// Siguiente

    Rain(string rainC,string n, int average){
        rainCode = rainC;
        name = n;
        averageRange = average;
        next = NULL;

    }

}rainList;// Lista de lluvia

/*
Estructura de Efimeridad
*/
struct Ephemerality{
    string name;// Nombre
    string date;// Fecha
    string departureTime;// Hora de Salida
    string hideTime;// Hora de ocultamiento
    Ephemerality*next;// Siguiente
    Ephemerality*pre;// Anterior

    Ephemerality(string n,string d,string departure,string hide){

        name = n;
        date = d;
        departureTime = departure;
        hideTime = hide;
    }

}*ephemeralityList;// Lista Efimeridad







int main()
{

    return 0;
}
