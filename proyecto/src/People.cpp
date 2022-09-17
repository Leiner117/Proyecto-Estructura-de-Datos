#include "People.h"
#include <string>
#include <iostream>
using namespace std;
People::People(string n,string id,short age,string place,string year)
{
    setName(n);
}

void People::setName(string n){
    name = n;
}
void People::print(){
    cout<<"Prueba";
}
People::~People()
{
    //dtor
}
