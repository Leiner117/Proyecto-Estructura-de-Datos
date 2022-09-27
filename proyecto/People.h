#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>
#include "TimeRegis.h"
using namespace std;

/*
 Creado: 16/09/2022 ultima mod: 19/09/2022
 Autor: Leiner Alvarado
 */
class People
{
    public:


        //Contructor
        People(string,string,short,string,string);

        //Funciones


         //Setters
        void setName(string);
        void setId(string);
        void setAge(short);
        void setPlaceResidence(string);
        void setYearIncome(string);
        void setTimeSublist(TimeRegis*);
         //Getters
        string getName();
        string getId();
        short getAge();
        string getPlaceResidence();
        string getYearIncome();
        TimeRegis*getTimeSubList();



        //Funciones
        People*dataLoad(People*);
        People* addPeople(string,string,short,string,string,People*);//Agregar nodo persona a la lista
        People* searchPeople(People*,string);//Busca un nodo especifico en la lista
        void printPeopleList(People*);// Imprime la lista
        void modName(string,string,People*);// Modifica el nombre
        void modId(string ,string,People*);//Modifica la identificacion
        void modAge(string,short,People*);// Modifica la edad
        void modPlaceResidence(string,string,People*);// Modifica el lugar de residencia
        void modYearIncome(string,string,People*);// Modifica el ano de ingreso
        People* deletePeople(People*,string);// Elimina un nodo de la lista


        People*next = NULL;//Siguiente
        People*pre;//Anterior
    private:
            //Atributos
            string name;// Nombre
            string id;// Cedula
            short age;// edad
            string placeResidence;// Lugar de residencia
            string yearIncome;// Año ingreso
            TimeRegis*timeSublist;//Sublista de registro del tiempo




};

#endif // PEOPLE_H
