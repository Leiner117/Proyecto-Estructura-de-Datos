#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>

using namespace std;

/*
 Creado: 16/09/2022 ultima mod: 16/09/2022
 Autor: Leiner Alvarado
 */
class People
{
    public:


        //Contructor
        People(string,string,short,string,string);

        //Funciones
        void print();
         //Setters
        void setName(string);
        void setId(string);
        void setAge(short);
        void setPlaceResidence(string);
        void setYearIncome(string);
         //Getters
        string getName();
        string getId();
        short getAge();
        string getPlaceResidence();
        string getYearIncome();


        //Funciones
        People* addPeople(string,string,short,string,string,People*);//Agregar nodo persona a la lista
        People* searchPeople(People*,string);//Busca un nodo especifico en la lista
        void printPeopleList(People*);// Imprime la lista
        People* deletePeople(People*,string);// Elimina un nodo de la lista



        People*next;
        People*pre;
    private:
            //Atributos
            string name;// Nombre
            string id;// Cedula
            short age;// edad
            string placeResidence;// Lugar de residencia
            string yearIncome;// Año ingreso





};

#endif // PEOPLE_H
