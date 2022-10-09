#ifndef EPHEMERALITY_H
#define EPHEMERALITY_H
#include <string>
#include <time.h>
/*
 Creado: 16/09/2022 ultima mod: 08/10/2022
 Autor: Leiner Alvarado
 */

using namespace std;

//Clase que contiene los atributos y métodos de efimeridad.
class Ephemerality
{
    public:
        //Constructor
        Ephemerality(string,long int,int,int);

        //Setters
        void setName(string);
        void setDate(long int);
        void setDepartureTime(int);
        void setHideTime(int);
        //Getters
        string getName();
        long int getDate();
        long int getDepartureTime();
        long int getHideTime();

        Ephemerality*next = NULL;// Siguiente
        Ephemerality*pre = NULL;// Anterior
        //Funciones

        Ephemerality*addEphemerality(string,long int,int,int,Ephemerality*);//Agrega un nodo a la lista
        Ephemerality*searchEphemerality(long int,Ephemerality*);// Retorna un nodo buscado
        Ephemerality*deleteEphemerality(long int,Ephemerality*);// Borra un nodo seleccionado de la lista
        void printEphemeralityList(Ephemerality*);// imprime la lista de efimeridad

        void modName(Ephemerality*,long int,string);// Modifica el nombre de la efimeridad
        void modDate(Ephemerality*,long int,int);// Modifica la fecha
        void modDepartureTime(Ephemerality*,long int,int);// Modifica la hora de salida del sol
        void modHideTime(Ephemerality*,long int,int);// Modifica la hora de ocultamiento del sol
        Ephemerality*dataLoad(Ephemerality*);// Cargar datos predeterminados
        tm* unixDateToDate(long int);// Convierte de formado Unix timestamps a fecha
        long int dateToUnixDate(int,short,short);// Convierte la fecha en formato Unix timestamps
        void diffDepartureTime(int,Ephemerality*);// Diferencia entre las horas de salida
        int timeToSeconds(int,int);// Convierte la hora en segundos
        string secondsToTime(int);// convierte los segundos en formato de horas y minutos para imprimir
        string dateToString(tm*); // Convierte la fecha en string para imprimir
        void timeReportYear(Ephemerality*,int);// Reporte de horas de salida y ocultamiento por anos
        void earlyDeparLateHide(Ephemerality*);// Consulta de la Hora de salida mas temprana y ocultamiento mas tardio
        bool valTime(int,int,int,int);
    private:
        //Atributos
        string name;// Nombre
        long int date;// Fecha
        long int departureTime;// Hora de Salida
        long int hideTime;// Hora de ocultamiento

};

#endif // EPHEMERALITY_H
