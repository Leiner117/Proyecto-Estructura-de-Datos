#include <iostream>
#include "People.h"// Clase persona
#include "Rain.h"// Clase lluvia
#include "Ephemerality.h";// Clase efimeridad

using namespace std;

/*
Creado:12/09/2022 Ultima mod: 19/09/2022
Autor: Leiner Alvarado
*/

Rain*rainList;
People*peopleList;
Ephemerality*ephemeralityList;

int main()
{


    rainList = rainList->addRain("001","p1",001,rainList);
    rainList = rainList->addRain("002","p2",002,rainList);
    rainList->printRainList(rainList);
    peopleList = peopleList->addPeople("Leiner","2022437759",19,"Bajo","2022",peopleList);
    peopleList = peopleList->addPeople("Leiner","2022437759",19,"Bajo","2022",peopleList);
    peopleList = peopleList->addPeople("Melanie","2023437759",17,"Criques","2022",peopleList);



    peopleList->printPeopleList(peopleList);
    peopleList->modName("2022437759","Enrique",peopleList);




    peopleList->printPeopleList(peopleList);
    rainList->deleteRain(rainList,"001");
    rainList->printRainList(rainList);


    return 0;
}
