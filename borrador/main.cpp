#include <iostream>
#include <conio.h> // libreria para limpiar la consola

using namespace std;

//Borrador del proyecto

//Falta crear las sublistas y sus metodos
//Revisar si funciona la relacion de lugar y region

void menu(){

    cout << "\n\t\t\|-------------------------------------|";
	cout << "\n\t\t\|      °   Menu de Listas  °          |";
	cout << "\n\t\t\|-------------------------------------|";
	cout << "\n\t\t\| 1. Agregar                          |";
	cout << "\n\t\t\| 2. Modificar Elemento               |";
	cout << "\n\t\t\| 3. Eliminar  Elemento               |";
	cout << "\n\t\t\| 4. Eliminar Lista                   |";
	cout << "\n\t\t\| 5. Imprimir Lista                   |";
	cout << "\n\t\t\|-------------------------------------|";
	cout << "\n\nElija una opcion: ";

    //system("cls");

}


//************************************** ESTRUCTURA DE LISTA REGISTRO TIEMPO ********************************************
struct TimeRegis{

    string registrationDate;
    int precipitation;
    float maxTemperature;
    float minTemperature;
    int windSpeed;
    int windDirection;
    int humidity;
    bool yesRained=false;

    TimeRegis* next;

    //Constructor de Registro Tiempo
    TimeRegis(string dateR,int precip,float maxTemp, float minTemp,int winSpd, int windDirec,int humidity,bool rained){

    registrationDate = dateR;
    precipitation = precip;
    maxTemperature = maxTemp;
    maxTemperature = minTemp;
    windSpeed = winSpd;
    windDirection = windDirec;
    humidity = humidity;
    yesRained = rained;
    next=NULL;

    }

} * TimeRegisList;

//************************************** ESTRUCTURA DE LISTA LUGARES ****************************************************
struct Place {
    string name;
    int population;
    float squareMeters;

    Place * next;
    struct Region* linkRegion //Enlace de Region con Lugar

    //Constructor de Lugar
    Place( string n,int p,float meters){
    name = n ;
    population = p;
    squareMeters = meters;
    next=NULL;
    }
} * placeList;

//************************************** ESTRUCTURA DE LISTA REGIONES ***************************************************
struct Region {

    string idRegion;
    string name;
    string location;

    Region * next;

    //Constructor de Region
    Region(string id,string n, string l){
    idRegion = id;
    name = n;
    location = l;
    next=NULL;
    }
} *regionList;





//************************************** METODOS DE LISTA LUGAR *******************************************************

//Verifica si el elemento a agregar ya existe en la lista
bool validatePlace(string n){

    if(placeList == NULL)
        return false;
    else{
        if(placeList->name == n){//es el primero de la lista
            return true;
        }
        else{
            Place*temp = placeList;
            do{
                if (placeList->name != n)
                    temp= temp->next;
            } while(temp!= placeList);
            return false;
        }
    }
}

//Agrega al inicio de lista circular
void addPlace(string n, int p,float meters){

    bool duplicate= validatePlace(n);

    if(duplicate==false){

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
}

//Borra UN ELEMENTO de la lista
Place* deletePlace(string n){
    if(placeList == NULL)
        cout<<"\nLista vacia, no se puede borrar....";
    else{
        if(placeList->name == n){//es el primero de la lista
            placeList= placeList->next;
        }
        else{
            Place* current = placeList;
            Place *temp = NULL;
            while((current!= NULL) && (current->name!=n)){
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
void deleteAllPlace() {
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
}

//Modifica un elemento especifico de la lista
void updatePlace(string data, string n,int p, float m){

    if(placeList== NULL)
        cout<<"\nLa lista no tiene datos.....";
    else{
        Place*temp = placeList;
        while (temp != NULL){
            if(temp->name == data){
                temp->name = n;
                temp->population = p;
                temp->squareMeters = m;
                cout<<"\nSe modifico correctamente";
                return;//me salgo de la fucnion
            }
            temp = temp->next;
        }
        cout<<"\nNO se encontro el dato.";
    }
}

//Imprime la lista completa
void printPlace(){

    if(placeList== NULL)
        cout<<"\nLista circular vacia......\n";
    else{
        Place*temp = placeList;
        do{
            cout<<temp->name<<" | "<<temp->population<<" | "<<temp->squareMeters<<endl;
            temp= temp->next;
        } while(temp!= placeList);

    }
}


//Se reciben datos de entrada
 void askDataPlace(){

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


//************************************** METODOS DE LISTA REGION ****************************************************

//Verifica si el elemento a agregar ya existe en la lista
bool validateRegion(string id,string n){
    if(regionList == NULL)
        return false;
    else{
        Region*temp = regionList;
        while(temp != NULL){
            if((temp->idRegion == id)&&(temp->name == n)){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
}

//Inserta al inicio de lista simple
void addRegion(string id,string n, string l){

    bool duplicate=validateRegion(id,n);
    if(duplicate == false){

        Region* newNodo = new Region(id,n,l);
        newNodo->next = regionList;//se enlaza, conoce la direccion el inicio de la lista
        regionList = newNodo;
    }
    else
        cout<<"\n+++ Advertencia: El nombre ingresado ya esta en la lista +++\n";
}

//Borra UN ELEMENTO de la lista
Region* deleteRegion(string id){

    if(regionList == NULL)
        cout<<"\nLista vacia, no se puede borrar....";
    else{
        if(regionList->idRegion == id){//es el primero de la lista
            regionList= regionList->next;
        }
        else{
            Region* current = regionList;
            Region *temp = NULL;
            while((current!= NULL) && (current->idRegion!=id)){
                temp = current;
                current = current->next;
                cout<<"\nSe borro correctamente";
            }
            if(current == NULL)
                cout<<"\nNo se encontro el nodo";
            else
                temp->next = current->next;
        }
    }
    return regionList;
}

//Borra toda la lista
void deleteAllRegion() {
    if(regionList != NULL) {
        Region *temp, *current;
        current = regionList->next;
        while(current != regionList) {
            temp = current->next;
            free(current);
            current = temp;
        }
        free(regionList);
        regionList = NULL;
    }
    cout<<"All nodes are deleted successfully.\n";
}

//Modifica un elemento especifico de la lista
void updateRegion(string data, string id,string n, string l){

    if(regionList== NULL)
        cout<<"\nLa lista no tiene datos.....";
    else{
        Region*temp = regionList;
        while (temp != NULL){
            if(temp->idRegion == data){
                temp->idRegion = id;
                temp->name = n;
                temp->location = l;
                cout<<"\nSe modifico correctamente";
                return;//me salgo de la fucnion
            }
            temp = temp->next;
        }
        cout<<"\nNO se encontro el dato.";
    }
}

//Imprime la lista completa
void printRegion(){

    if(regionList == NULL)
        cout<<"\nLa lista esta vacia ...........\n";
    else{
        Region*temp = regionList;
        while(temp != NULL){
            cout<<"\n"<<temp->idRegion<<" | "<<temp->name<<" | "<<temp->location;
            temp = temp->next;
        }
    }
}




void dataLoad(){

    //Datos preestablecidos en lista lugar
    addPlace("San Carlos",163745,3347.98);
    addPlace("Upala",43953,1.581);
    addPlace("Naranjo",42713,126.6);
    addPlace("Naranjo",4548,23265.6);
    addPlace("Palmares",34716,38.06);
    addPlace("Escazu",56509,34.49 );
    addPlace("Los Chiles",23735,504.2);
    addPlace("Grecia",13262,3221.6);
    addPlace("Sarapiqui",57147,2140.54);
    addPlace("Talamanca",30712,504.2);
    addPlace("Guatuso",15508,1580.67);

    //Datos preestablecidos en lista region
    addRegion("C","Caribe","Limon");
    addRegion("C","Pacifico Central","Puntarenas");
    addRegion("C","Talamanca","Limon");
    addRegion("C","Upala y los Chiles","Alajuela");
    addRegion("C","Valle Central","San Jose");
    addRegion("C","Peninsula de Nicoya","Guanacaste");
    addRegion("C","Pacifico Sur","Puntarenas");
    addRegion("C","Norte Alta","Alajuela");
    addRegion("C","Cordillera de Guanacaste y Tilaran","Guanacaste");
    addRegion("C","Caribe Sur","Limon");
    addRegion("C","Caribe","Limon");

    /*
    add("01/09/2022",1245,21.4,10.4,24,89,25,true);
    add("02/09/2022",5345,25.0,11.4,29,73,26,false);
    add("03/09/2022",5571,15.9,5.6,31,69,29,true);
    add("04/09/2022",5486,12.4,6.9,6,83,21,true);
    add("05/09/2022",4911,8.8,3.8,34,70,20,false);
    add("06/09/2022",2688,17.3,11.0,27,93,19,true);
    add("07/09/2022",9875,31.5,15.3,19,60,34,false);
    add("08/09/2022",1135,20.1,14.1,13,80,2,false);
    add("09/09/2022",887,27.0,12.9,28,25,36,false);
    add("10/09/2022",235,23.3,16.5,25,60,32,true);
    */

    cout<<"\n--- Se cargaron los datos correctamente ---\n";


}







int main()
{
    //cout << "\n****************** BINEVENIDO AL REGISTRO DEL CLIMA ******************\n";
    //menu();

    dataLoad();
    printRegion();
    updatePlace("San Carlos","Los Angeles",12,13.8);

    /*printRegion();
    deleteRegion("TCA");
    printRegion();
    updateRegion("C","CA","Caribe ","limonada");
    printRegion();

    //deletePlace("San Carlos");
    updatePlace("San Carlos","Los Angeles",12,13.8);
    printPlace();
*/
    return 0;
}
