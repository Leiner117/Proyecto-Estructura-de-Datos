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

    rainList = rainList->addRain("001","p1",001,rainList);
    rainList = rainList->addRain("002","p2",002,rainList);
    rainList->printRainList(rainList);


    return 0;
}
