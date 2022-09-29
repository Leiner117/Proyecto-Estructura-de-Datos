#ifndef RAIN_H
#define RAIN_H
#include <string>

/*
 Creado: 16/09/2022 ultima mod: 19/09/2022
 Autor: Leiner Alvarado
 */
using namespace std;

class Rain
{
    public:
        //Constructor
        Rain(string,string,int);

        //Setters
        void setRainCode(string);
        void setName(string);
        void setAverageRange(int);

        //Getters
        string getName();
        string getRainCode();
        int getAverageRange();


        //Funciones

        Rain*addRain(string,string,int,Rain*);//Agregar nodo lluvia a la lista
        void printRainList(Rain*);//Imprimir la lista lluvia
        Rain*searchRain(Rain*,string);// Buscar nodo lluvia en la lista
        void modRainCode(Rain*,string,string);//Modificar atributo lluvia
        void modName(Rain*,string,string);// Modificar atributo nombre
        void modAverageRange(Rain*,int,string);//Modificar atributo Rango promedio
        void deleteRain(Rain*,string);//

        Rain* dataLoad(Rain*);
        Rain* next;// Siguiente

    private:

        //Atributos
        string rainCode;// Codigo de la lluvia
        string name;// Nombre
        int averageRange;// Rango promedio en mm

};

#endif // RAIN_H
