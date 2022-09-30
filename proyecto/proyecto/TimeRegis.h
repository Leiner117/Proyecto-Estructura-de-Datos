#ifndef TIMEREGIS_H
#define TIMEREGIS_H
#include <string>
#include "Rain.h"
using namespace std;

// Aquí se declaran las variables,constantes y las funciones

class TimeRegis
{
    public:

        //Constructor
        TimeRegis(string, int, float, float, int , int, int, bool);

        //Setters
        void setDateR(string);
        void setPrecip(int);
        void setMaxTemp(float);
        void setMinTemp(float);
        void setWinPsd(int);
        void setWinDirec(int);
        void setHumidity(int);
        void setRained(bool);
        void setRainList(Rain*);

        //Getters
        string getDateR();
        int getPrecip();
        float getMaxTemp();
        float getMinTemp();
        int getWinPsd();
        int getWinDirec();
        int getHumidity();
        bool getRained();
        class NodoSubRain* getRainList();

        //Metodos
        bool validate(string , TimeRegis* );
        TimeRegis* add(string ,int ,float ,float ,int , int ,int ,bool , TimeRegis* );
        TimeRegis* deleteTime(string ,TimeRegis* );
        TimeRegis* deleteAllTime(TimeRegis* );
        TimeRegis* modify(string,string ,int ,float ,float ,int , int ,int ,bool , TimeRegis* );
        TimeRegis* searchTime(string , TimeRegis* );
        void print(TimeRegis* );
        TimeRegis* dataLoad(TimeRegis* );

        //Metodos de sublista

        NodoSubRain* linkendRainTime(string, string,Rain*,TimeRegis*);
        void printSubRain(string,TimeRegis*);


        //Puntero
        TimeRegis* next;
        class NodoSubRain* rainSublist;

    private:

        string registrationDate;
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

