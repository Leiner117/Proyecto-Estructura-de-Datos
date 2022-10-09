#include "People.h"
#include "TimeRegis.h"
#include <string>
#include <iostream>

/*
 Creado: 16/09/2022 ultima mod: 08/10/2022
 Autor: Leiner Alvarado
 */

using namespace std;


/**
 * Esta función es un constructor de la clase Personas. Inicializa las variables de la clase.
 *
 * Args:
 *   n (string): nombre de la persona
 *   id (string): la identificación de la persona
 *   age (short): la edad de la persona
 *   place (string): el lugar de residencia
 *   year (string): el año de ingreso de la persona
 */
People::People(string n,string id,short age,string place,string year)
{
    setName(n);
    setId(id);
    setAge(age);
    setPlaceResidence(place);
    setYearIncome(year);
    next=NULL;
    timeSublist=NULL;

}


/**
 * Esta función establece el nombre de la persona.
 *
 * Args:
 *   n (string): el nombre de la persona
 */
void People::setName(string n){
    name = n;
}

/**
 * Esta función establece la identificación de la persona.
 *
 * Args:
 *   i (string): La identificación de la persona
 */
void People::setId(string i){
    id = i;
}

/**
 * La función asigna a la variable edad, la edad de la persona.
 *
 * Args:
 *   ag (short): La edad de la persona.
 */
void People::setAge(short ag){
    age = ag;
}

/**
 * Esta función establece el lugar de residencia de la persona.
 *
 * Args:
 *   place (string): El lugar de residencia de la persona.
 */
void People::setPlaceResidence(string place){
    placeResidence = place;
}

/**
 * Esta función asigna a la variable yearIncome el parámetro de year.
 *
 * Args:
 *   year (string): el año de ingreso de la persona
 */
void People::setYearIncome(string year){
    yearIncome = year;
}

//Getters

/**
 * Esta función devuelve el id de la persona.
 *
 * Returns:
 *   La identificación de la persona.
 */
string People::getId(){
    return id;
}
/**
 * Esta función devuelve el nombre de la persona.
 *
 * Returns:
 *   El nombre de la persona.
 */
string People::getName(){
    return name;
}

/**
 * Esta función devuelve el valor de la edad
 *
 * Returns:
 *   La edad de la persona.
 */
short People::getAge(){
    return age;
}

/**
 * Esta función devuelve el lugar de residencia de la persona.
 *
 * Returns:
 *   El lugar de residencia de la persona.
 */
string People::getPlaceResidence(){
    return placeResidence;
}

/**
 * Esta función devuelve el año de ingreso de la persona.
 *
 * Returns:
 *   Se devuelve la variable yearIncome.
 */
string People::getYearIncome(){
    return yearIncome;
}

// Funciones


/**
 * Agrega una nueva persona a la lista de personas
 *
 * Args:
 *   name (string): Nombre de la persona.
 *   id (string): Identificacion de la persona a agregar.
 *   age (short): Edad de la persona.
 *   place (string): Lugar donde vive la persona.
 *   year (string): Año en el que la persona ingresa.
 *   peopleList (People): Lista de personas.
 *
 * Returns:
 *   la lista de personas.
 */
People*People::addPeople(string name,string id,short age,string place,string year,People*peopleList){

  if (searchPeople(peopleList,id) == NULL){
      People*newPeople = new People(name,id,age,place,year);
        if(peopleList == NULL)
            peopleList = newPeople;
        else if(name <= peopleList->getName()){//inserta al inicio
            newPeople->next = peopleList;
            peopleList->pre = newPeople;
            peopleList = newPeople;
        }
        else{//es en medio o al final de la lista
            People* temp = peopleList;
            People*previ;
            while((temp!= NULL) &&(name>temp->getName())){
                previ = temp;
                temp = temp->next;

            }
            previ->next = newPeople;
            newPeople->pre = previ;
            if(temp != NULL)
                newPeople->next = temp;

        }
        cout << "\n\t\t-- SUS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE PERSONAS --"<<endl;
    }
    else{
        cout<<"\n\t\t+++ ERROR: EL ID INGRESADO YA SE ENCUENTRA EN LA LISTA +++\n";

    }
    return peopleList;
}



/**
 * Esta función imprime la lista de personas
 *
 * Args:
 *   pList (People): es la lista de personas
 */
void People::printPeopleList(People*pList){

    if(pList == NULL){
        cout<< "\n\t-- LA LISTA DE PERSONA ESTA VACIA --\n";
    }
    else{
        People*temp = pList;
        cout<<"\n\t   =========================================\n";
        cout<<"\t   ||          LISTA DE PERSONAS          ||\n";
        cout<<"\t   =========================================\n";
        while(temp != NULL){
            cout<<"\n\t________________________________________________\n";
            cout<<"\n\tNOMBRE: "<<temp->getName()<<endl;
            cout<<"\n\tCEDULA: "<<temp->getId()<<endl;
            cout<<"\n\tRESIDENCIA: "<<temp->getPlaceResidence()<<endl;
            cout<<"\n\tYEAR DE INGRESO: "<<temp->getYearIncome()<<endl;
            temp = temp->next;
        }
    }
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();
}


/**
 * Esta función busca una persona en la lista de personas
 *
 * Args:
 *   pList (People): La lista de personas para buscar.
 *   id (string): el id de la persona que se quiere buscar
 *
 * Returns:
 *   Un puntero a un objeto Personas.
 */
People*People::searchPeople(People*pList,string id){

    if(pList == NULL){
        return NULL;
    }
    People*temp = pList;
    while(temp != NULL){
        if(temp->getId() == id){

            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


/**
 * Funcion que elimina una persona de la lista de personas
 *
 * Args:
 *   pList (People): la lista de personas
 *   id (string): la identificación de las personas que desea eliminar
 *
 * Returns:
 *   El puntero al encabezado de la lista.
 */
People*People::deletePeople(People*pList,string id){

    People*dPeople = searchPeople(pList,id);

    if(dPeople == NULL){
        return pList;
    }
    else{
        if(dPeople == pList){
            pList = pList->next;
            if(pList != NULL){
                pList->pre = NULL;
            }
        }
        else{
            dPeople->pre->next = dPeople->next;
            if(dPeople->next != NULL){
                dPeople->next->pre = dPeople->pre;
                }
            }
    }
    return pList;
}

/**
 * Modifica el nombre de una persona en la lista
 *
 * Args:
 *   id (string): la identificación de las personas que desea modificar
 *   newName (string): el nuevo nombre de la persona
 *   pList (People): la lista de personas
 */
void People::modName(string id,string newName,People*pList){
    People*people = searchPeople(pList,id);
    people->setName(newName);

}

/**
 * Modifica el id de una persona en la lista
 *
 * Args:
 *   id (string): el id de la persona que se quiere modificar
 *   newId (string): la nueva identificación de la persona
 *   pList (People): la lista de personas
 */
void People::modId(string id,string newId,People*pList){
    People*people = searchPeople(pList,id);
    people->setId(newId);
}

/**
 * Funcion que modifica la edad de una persona
 *
 * Args:
 *   id (string): el id de la persona que se quiere modificar
 *   newAge (short): la nueva edad de la persona
 *   pList (People): la lista de personas
 */
void People::modAge(string id,short newAge,People*pList){
    People*people = searchPeople(pList,id);
    people->setAge(newAge);
}

/**
 * Modifica el lugar de residencia de una persona
 *
 * Args:
 *   id (string): El id de la persona que se quiere modificar.
 *   newPlace (string): el nuevo lugar de residencia
 *   pList (People): la lista de personas
 */
void People::modPlaceResidence(string id,string newPlace,People*pList){
    People*people = searchPeople(pList,id);
    people->setPlaceResidence(newPlace);
}


/**
 * Esta función se utiliza para modificar el año de ingreso de una persona
 *
 * Args:
 *   id (string): el id de la persona que se quiere modificar
 *   newYear (string): nuevo año de ingreso
 *   pList (People): lista de personas
 */
void People::modYearIncome(string id,string newYear,People*pList){
    People*people = searchPeople(pList,id);
    people->setYearIncome(newYear);
}


/**
 * Carga una lista de personas y la retorna.
 *
 * Args:
 *   peopleList (People): La lista de personas a las que se agregará.
 *
 * Returns:
 *   La lista de personas.
 */
People* People::dataLoad(People* peopleList){

    peopleList=addPeople("Ernesto","202201",15,"Upala","2020",peopleList);
    peopleList=addPeople("Maria","202202",17,"La Tigra","2012",peopleList);
    peopleList=addPeople("Adrian","202203",23,"Santa Clara","2010",peopleList);
    peopleList=addPeople("Leiner","202204",20,"Bajo Rodriguez","2022",peopleList);
    peopleList=addPeople("Sara","202205",39,"Ciudad Quesada","2021",peopleList);
    peopleList=addPeople("Tommy","202206",57,"Los Chiles","2019",peopleList);
    peopleList=addPeople("Karina","202207",18,"Los Angeles","2022",peopleList);
    peopleList=addPeople("Alex","202208",25,"Moravia","2013",peopleList);
    peopleList=addPeople("Rose","202209",41,"Coronado","2015",peopleList);
    peopleList=addPeople("Ana","2022010",70,"San Miguel","2004",peopleList);

    return peopleList;
}



//---------------------------------SUBLISTA DE LUGARES----------------------------

/**
 * *Relaciona un lugar con una persona*
 *
 * Args:
 *   idPerson (string): El ID de la persona que desea vincular a la hora.
 *   dateR (long int): es la fecha del registro
 *   timeList (TimeRegis): es una lista de objetos TimeRegis
 *   peopleList (People): es una lista de personas
 */
NodoSubTime* People::linkendTimePeople(string idPerson, long int dateR,TimeRegis* timeList,People* peopleList){

    People* pers = pers->searchPeople(peopleList,idPerson);
    TimeRegis* timeR = timeR->searchTime(dateR,timeList);

    if(pers == NULL){
        cout<<"\n\tNO EXISTE LA PERSONA";
        return NULL;
    }
    if(timeR == NULL){
        cout<<"\n\tNO HAY REGISTRO EN ESA FECHA";
        return NULL ;
    }

    NodoSubTime* newNodo = new NodoSubTime();
    newNodo->linkTime = timeR;// se enlaza con el curso
    newNodo->next = pers->timeSublist;
    pers->timeSublist = newNodo;
    return pers->timeSublist;
}


/**
 * Devuelve el tamaño de la lista.
 *
 * Args:
 *   a (NodoSubTime): El cabeza de lista
 *
 * Returns:
 *   El tamaño de la lista.
 */
int People::getSize(NodoSubTime* a)
{
    int sz = 0;
    while (a != NULL) {
        a = a->next;
        sz++;
    }
    return sz;
}


/**
 * Es una función que obtiene el tamaño de la sublista de una persona y luego la compara con el tamaño de la sublista de la
 * siguiente persona, hasta que encuentrar a la persona con la sublista más grande.
 *
 * Args:
 *   peopleList (People): es la lista de personas
 */

void* People::getSizeSublist(People* peopleList){

    People * pers= peopleList;
    People * cont= pers;
    NodoSubTime* temp1 = NULL;//pers->timeSublist;
    NodoSubTime* temp2 = NULL;//pers->next->timeSublist;

    int a, b = 0;
    while((pers!= NULL)&&(pers->next!= NULL)){

        temp1=cont->timeSublist;
        temp2=pers->next->timeSublist;

        a=getSize(temp1);
        b=getSize(temp2);

        if(a>b){ // A > B
           pers=pers->next;
        }
        else{ //B > A
            pers=pers->next;
            cont=pers;
        }
    }
    cout<<"\n\t\t"<<cont->getName()<<" ES LA PERSONA CON MAS REGISTROS DEL TIEMPO\n";
}



/**
 * Imprime la sublista de una persona
 *
 * Args:
 *   id (string): El id de la persona que se quiere imprimir la sublista.
 *   peopleList (People): es la lista de personas
 *
 * Returns:
 *   un puntero al primer nodo de la lista.
 */
void People::printSublistTime(string id,People* peopleList){

    People * pers = pers->searchPeople(peopleList,id);

    if(pers == NULL){
        cout<<"\n\tNO EXISTE LA PERSONA";
        return;
    }
    else{
        NodoSubTime* temSub = pers->timeSublist;
        if(temSub==NULL){
            cout<<"\n\t"<<pers->getName()<<" NO TIENE REGISTROS DEL TIEMPO\n";
        }
        else{
            cout<<"\n\t   =========================================\n";
            cout<<"\t   ||   Tiempos registrados por "<<pers->getName()<<"   ||\n";
            cout<<"\t   =========================================\n";
            while(temSub != NULL){
                cout<<"\n\t________________________________________________\n";
                cout<<"\n\tFECHA: "<<temSub->linkTime->dateToString(temSub->linkTime->unixDateToDate(temSub->linkTime->getDateR()));
                cout<<"\n\tPRECIPITACION: "<<temSub->linkTime->getPrecip();
                cout<<"\n\tTEMPERATURA MINIMA: "<<temSub->linkTime->getMinTemp();
                cout<<"\n\tTEMPERATURA MAXIMA: "<<temSub->linkTime->getMaxTemp();
                cout<<"\n\tDIRECCION DEL VIENTO: "<<temSub->linkTime->getWinDirec();
                cout<<"\n\tVELOCIDAD DEL VIENTO: "<<temSub->linkTime->getWinPsd();
                cout<<"\n\tHUMEDAD: "<<temSub->linkTime->getHumidity();
                if (temSub->linkTime->getRained()==true){
                    cout<<"\n\tLLUVIA: SI";
                }
                else{
                    cout<<"\n\tLLUVIA: NO";
                }

                temSub = temSub->next;

            }
            cout<<"\n\t________________________________________________\n";
        }

    }

}





