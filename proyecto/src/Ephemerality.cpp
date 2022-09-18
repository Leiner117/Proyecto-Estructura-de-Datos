#include "Ephemerality.h"
#include <string>


using namespace std;
//Constructor
Ephemerality::Ephemerality(string n,string d,string departure,string hide)
{
    setName(n);
    setDate(d);
    setDepartureTime(departure);
    setHideTime(hide);
}

//Setters
void Ephemerality::setName(string n){
    name = n;
}
void Ephemerality::setDate(string d){
    date = d;
}
void Ephemerality::setDepartureTime(string time){
    departureTime = time;
}
void Ephemerality::setHideTime(string time){
    hideTime = time;

}

//Getters
string Ephemerality::getName(){
    return name;
}
string Ephemerality::getDate(){
    return date;
}
string Ephemerality::getDepartureTime(){
    return departureTime;
}
string Ephemerality::getHideTime(){
    return hideTime;
}
