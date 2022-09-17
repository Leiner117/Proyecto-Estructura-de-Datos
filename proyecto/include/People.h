#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>
using namespace std;
class People
{
    public:
        string name;// Nombre
        string id;// Cedula
        short age;// edad
        string placeResidence;// Lugar de residencia
        string yearIncome;// Año ingreso
        void setName(string);
        People(string,string,short,string,string);
        void print();
        virtual ~People();


};

#endif // PEOPLE_H
