#include <iostream>
#include "People.h"
#include "Rain.h"
using namespace std;

/*
Creado:12/09/2022 Ultima mod: 16/09/2022
Autor: Leiner Alvarado
*/

Rain*rainList;


int main()
{
    Rain*r1 = new Rain("001","011",001);
    Rain*r2 = new Rain("002","012",001);
    rainList = rainList->addRain(r1,rainList);
    rainList = rainList->addRain(r2,rainList);
    rainList->printRainList(rainList);

    rainList->

    return 0;
}
