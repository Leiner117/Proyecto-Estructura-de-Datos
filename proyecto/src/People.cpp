#include "People.h"
#include <string>
#include <iostream>

/*
 Creado: 16/09/2022 ultima mod: 16/09/2022
 Autor: Leiner Alvarado
 */

using namespace std;

//Constructor
People::People(string n,string id,short age,string place,string year)
{
    setName(n);
    setId(id);
    setAge(age);
    setPlaceResidence(place);
    setYearIncome(year);

}
//Setters
void People::setName(string n){
    name = n;
}

void People::setId(string i){
    id = i;
}
void People::setAge(short ag){
    age = ag;
}
void People::setPlaceResidence(string place){
    placeResidence = place;
}
void People::setYearIncome(string year){

    yearIncome = year;
}

//Getters

string People::getId(){
    return id;
}
string People::getName(){
    return name;
}

short People::getAge(){
    return age;
}
string People::getPlaceResidence(){
    return placeResidence;
}

string People::getYearIncome(){
    return yearIncome;
}

// Funciones
void People::print(){
    cout<<getName();
}

