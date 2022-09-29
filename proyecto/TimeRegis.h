#ifndef TIMEREGIS_H
#define TIMEREGIS_H
#include <string>

#include "Rain.h"

#include "time.h"

using namespace std;

// Aqui se declaran las variables,constantes y las funciones

class TimeRegis
{
    public:

        //Constructor
        TimeRegis(long int, int, float, float, int , int, int, bool);

        //Setters
        void setDateR(long int);
        void setPrecip(int);
        void setMaxTemp(float);
        void setMinTemp(float);
        void setWinPsd(int);
        void setWinDirec(int);
        void setHumidity(int);
        void setRained(bool);
        void setRainList(Rain*);

        //Getters
        long int getDateR();
        int getPrecip();
        float getMaxTemp();
        float getMinTemp();
        int getWinPsd();
        int getWinDirec();
        int getHumidity();
        bool getRained();
        class NodoSubRain* getRainList();

        //Metodos
        bool validate(long int , TimeRegis* );
        TimeRegis* add(long int ,int ,float ,float ,int , int ,int ,bool , TimeRegis* );
        TimeRegis* deleteTime(long int  ,TimeRegis* );
        TimeRegis* deleteAllTime(TimeRegis* );
        TimeRegis* modify(long int,long int ,int ,float ,float ,int , int ,int ,bool , TimeRegis* );
        TimeRegis* searchTime(long int , TimeRegis* );
        void print(TimeRegis* );
        TimeRegis* dataLoad(TimeRegis* );
        


        //Metodos de sublista

        NodoSubRain* linkendRainTime(string, string,Rain*,TimeRegis*);
        void printSubRain(string,TimeRegis*);

        long int dateToUnixDate(int ,short ,short);// Convierte la fecha a UnixDate(segundos totales)
        string dateToString(tm*);// Convierte de formato fecha a string para imprimir
        tm*unixDateToDate(long int);//Convierte de formato UnixDate a estructura date

        //Puntero
        TimeRegis* next;
        class NodoSubRain* rainSublist;

    private:

        long int registrationDate;
        int precipitation;
        float maxTemperature;
        float minTemperature;
        int windSpeed;
        int windDirection;
        int humidity;
        bool yesRained=false;
        int contRegis;

};

class NodoSubRain{
    public:
        NodoSubRain* next;
        Rain* linkRain;
};




#endif // TIMEREGIS_H

