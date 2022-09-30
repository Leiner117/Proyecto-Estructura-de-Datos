#include "Place.h"
#include "TimeRegis.h"
#include <string>
#include <iostream>
using namespace std;


Place::Place(string n,int p,float meters){

    setName(n);
    setPopulation(p);
    setSquareMeters(meters);
    next= NULL;

}


//------------------- Metodos set-----------------------------------------
void Place::setName(string n){
    name=n;
}

void Place::setPopulation(int p){
    population= p;
}

void Place::setSquareMeters(float meters){
    squareMeters= meters;
}
/*void Place::setTimeRegis(TimeRegis*newList){
    timeRegSublist = newList;
}*/



//------------------- Metodos get-----------------------------------------
string Place::getName(){
    return name;
}

int Place::getPopulation(){
    return population;
}

float Place::getSquareMeters(){
    return squareMeters;
}

/*TimeRegis* Place::getTimeRegis(){
    return timeRegSublist;
}*/





//************************** Funciones de la lista ******************


//Verifica si el elemento a agregar ya existe en la lista
bool Place::validate(string n,Place* placeList){

    if(placeList == NULL)
        return false;
    else{
        if(placeList->getName() == n){//es el primero de la lista
            return true;
        }
        else{
            Place*temp = placeList;
            do{
                if (placeList->getName() != n)
                    temp= temp->next;
            } while(temp!= placeList);
            return false;
        }
    }
}

//Agregar al Inicio
Place* Place::add(string n,int p,float meters,Place* placeList){

    bool duplicate= validate(n,placeList);

    if(duplicate==NULL){

        Place* newNodo = new Place(n,p,meters);

        if(placeList == NULL){
            placeList = newNodo;
            newNodo->next = placeList;
        }
        else{

            newNodo->next =placeList;
            //buscar el ultimo para que apunte al nuevo nodo
            Place* temp = placeList;
            while(temp->next != placeList)
                temp = temp->next;

            temp->next = newNodo;
            placeList = newNodo;

        }
    }
    else{
        cout<<"\n+++ Advertencia: El nombre ingresado ya esta en la lista +++\n";
    }
    return placeList;
}

//Modificar
Place* Place::modify(string data, string n,int p, float m,Place*placeList){

    bool duplicate= validate(n,placeList);

     if(duplicate==NULL){
        if(placeList== NULL)
            cout<<"\nLa lista no tiene datos.....";
        else{
            Place*temp = placeList;
            while (temp != NULL){
                if(temp->getName() == data){
                    temp->setName(n);
                    temp->setPopulation(p);
                    temp->setSquareMeters(m);
                    cout<<"\nSe modifico correctamente";
                    return placeList;//me salgo de la fucnion
                }
                temp = temp->next;
            }
            cout<<"\nNO se encontro el dato.";
        }
    }
    else{
        cout<<"\n+++ Advertencia: El nombre ingresado ya existe en la lista +++\n";
    }
    return placeList;
}

//Borra UN ELEMENTO de la lista
Place* deletePlace(string n,Place* placeList){
    if(placeList == NULL)
        cout<<"\nLista vacia, no se puede borrar....";
    else{
        if(placeList->getName() == n){//es el primero de la lista
            placeList= placeList->next;
        }
        else{
            Place* current = placeList;
            Place *temp = NULL;
            while((current!= NULL) && (current->getName()!=n)){
                temp = current;
                current = current->next;
            }
            if(current == NULL)
                cout<<"\nNo se encontro el nodo";
            else
                temp->next = current->next;
        }
    }
    return placeList;
}

//Borra toda la lista
Place* deleteAllPlace(Place* placeList) {
    if(placeList != NULL) {
        Place *temp, *current;
        current = placeList->next;
        while(current != placeList) {
            temp = current->next;
            free(current);
            current = temp;
        }
        free(placeList);
        placeList = NULL;
    }
    cout<<"Todos los nodos han sido eliminados correctamente.\n";
    return placeList;
}


//Buscar Nodo Place


Place* Place::searchPlace(string n, Place* placeList){
     Place *temp;
     if(placeList !=NULL){
          temp = placeList;

          do
          {
               if(temp->getName() == n)
               {
                   return temp;
               }
               else
               {
                   temp = temp->next;
               }
          }while(temp!=placeList);

          //cout<<"\n\n\Lugar no encontrado..!"<<endl;

     }
     else
        return NULL;
         cout<<"\n\n\tLista vacia...!"<<endl;
}


//Imprime la lista completa
void Place:: print(Place* placeList){

    if(placeList== NULL)
        cout<<"\nLista circular vacia......\n";
    else{
        Place*temp = placeList;
        do{
            cout<<temp->getName()<<" | "<<temp->getPopulation()<<" | "<<temp->getSquareMeters()<<endl;
            temp= temp->next;
        } while(temp!= placeList);

    }
}

//Se reciben datos de entrada
void Place::askData(){

    string n;
    int p;
    float mc;

    cout<<"\nIngrese el nombre del lugar: ";
    getline(cin>>ws, n);
    cout<<"\nIngrese la poblacion total del lugar: ";
    cin>>p;
    cout<<"\nIngrese los metros cuadrados del lugar: ";
    cin>>mc;

 }

//Cargar datos quemados
Place* Place::dataLoad(Place* placeList){

    //Datos preestablecidos en lista lugar
    placeList=add("San Carlos",163745,3347.98,placeList);
    placeList=add("Upala",43953,1.581,placeList);
    placeList=add("Naranjo",42713,126.6,placeList);
    placeList=add("Naranjo",4548,23265.6,placeList);
    placeList=add("Palmares",34716,38.06,placeList);
    placeList=add("Escazu",56509,34.49,placeList);
    placeList=add("Los Chiles",23735,504.2,placeList);
    placeList=add("Grecia",13262,3221.6,placeList);
    placeList=add("Sarapiqui",57147,2140.54,placeList);
    placeList=add("Talamanca",30712,504.2,placeList);
    placeList=add("Guatuso",15508,1580.67,placeList);

    cout<<"\n---Se cargaron los datos correctamente---\n";

    return placeList;

}

//---------------------------------SUBLISTA DE REGISTROS DEL TIEMPO----------------------------

NodoSubTime* Place::linkendTimePlace(string namePlace, long int date,TimeRegis* timeList,Place* placeList){

    Place* plc = plc->searchPlace(namePlace,placeList);
    TimeRegis* timeR = timeR->searchTime(date,timeList);

    if(plc == NULL){
        cout<<"\nNo existe el lugar";
        return NULL;
    }
    if(timeR == NULL){
        cout<<"\nNo existe el registro del tiempo";
        return NULL;
    }

    NodoSubTime* newNodo = new NodoSubTime();
    newNodo->linkTime = timeR;// se enlaza con el curso
    newNodo->next = plc->timeRegiSublist;
    plc->timeRegiSublist = newNodo;

    return plc->timeRegiSublist;

}




void Place::printSubTimePlace(string n,Place* placeList){
    Place * plc = plc->searchPlace(n,placeList);
    if(plc == NULL){
        cout<<"\nNo existe el lugar";
        return;
    }
    //Grafica de  los resultados a imprimir
    system("cls");
    cout<<"\n\t   =========================================\n";
    cout<<"\t   ||   Registros del tiempo en el Lugar "<<plc->getName()<<"   ||\n";
    cout<<"\t   =========================================\n";
    NodoSubTime* temSub = plc->timeRegiSublist;

    while(temSub != NULL){

        if(temSub->linkTime->getDateR()!=0){
            cout<<"\n\t________________________________________________\n";
            cout<<"\n\tFECHA: "<<temSub->linkTime->getDateR();
            cout<<"\n\tPRECIPITACION: "<<temSub->linkTime->getPrecip();
            cout<<"\n\tTEMPERATURA MINIMA: "<<temSub->linkTime->getMinTemp();
            cout<<"\n\tTEMPERATURA MAXIMA: "<<temSub->linkTime->getMaxTemp();
            cout<<"\n\tDIRECCION DEL VIENTO: "<<temSub->linkTime->getWinDirec();
            cout<<"\n\tVELOCIDAD DEL VIENTO: "<<temSub->linkTime->getWinPsd();
            cout<<"\n\tHUMEDAD: "<<temSub->linkTime->getHumidity();
            if (temSub->linkTime->getRained()==true)
                cout<<"\n\tLLUVIA: SI";
            else
                cout<<"\n\tLLUVIA: NO";
            temSub = temSub->next;
        }
        else{
            break;
        }
    };
    cout<<"\n\t________________________________________________\n";

}




