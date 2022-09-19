#ifndef TIMEREGIS_H
#define TIMEREGIS_H
#include <string>
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

        //Getters
        string getDateR();
        int getPrecip();
        float getMaxTemp();
        float getMinTemp();
        int getWinPsd();
        int getWinDirec();
        int getHumidity();
        bool getRained();

        //Metodos
        void add(string, int, float, float, int , int, int, bool);
        TimeRegis* deleteRegis(string,TimeRegis* regisList);
        void modify(string,string, int, float, float, int , int, int, bool,TimeRegis* regisList);
        TimeRegis* searchRegis(string, TimeRegis* regisList);
        void dataLoad();
        void displayTimeRegis(TimeRegis* regisList);

        //Puntero
        TimeRegis* next;

    private:

        string registrationDate;
        int precipitation;
        float maxTemperature;
        float minTemperature;
        int windSpeed;
        int windDirection;
        int humidity;
        bool yesRained=false;

};






#endif // TIMEREGIS_H

