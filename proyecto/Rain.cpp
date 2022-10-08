#include "Rain.h"
#include <string>
#include <iostream>

/*
 Creado: 16/09/2022 ultima mod: 16/09/2022
 Autor: Leiner Alvarado
 */

using namespace std;

/**
 * Esta función es un constructor que inicializa el código de la lluvia, el nombre y el rango promedio de un objeto Rain.
 *
 * Args:
 *   rainCode (string): Código que se utilizará para identificar la lluvia.
 *   name (string): El nombre de la lluvia.
 *   averageRange (int): El rango promedio de la lluvia.
 */
Rain::Rain(string rainCode, string name,int averageRange)
{
    setRainCode(rainCode);
    setName(name);
    setAverageRange(averageRange);
}


/**
 * Esta función establece a la variable rainCode el valor del parámetro code.
 *
 * Args:
 *   code (string): El código para la condición climática.
 */
void Rain::setRainCode(string code){
    rainCode = code;
}

/**
 * Esta función establece el nombre del objeto Lluvia.
 *
 * Args:
 *   n (string): El nombre de la lluvia.
 */
void Rain::setName(string n){
    name = n;
}

/**
 * Esta función establece el rango promedio de la lluvia.
 *
 * Args:
 *   average (int): La cantidad promedio de lluvia que cae en un día determinado.
 */
void Rain::setAverageRange(int average){
    averageRange = average;
}



/**
 * Esta función devuelve el código de lluvia.
 *
 * Returns:
 *   Se devuelve el código de lluvia.
 */
string Rain::getRainCode(){
    return rainCode;
}

/**
 * Esta función devuelve el nombre del objeto Rain.
 *
 * Returns:
 *   El nombre de la condicion climatica.
 */
string Rain::getName(){
    return name;

}

/**
 * Esta función devuelve el rango promedio de la lluvia
 *
 * Returns:
 *   El rango promedio de la caída de lluvia.
 */
int Rain::getAverageRange(){

    return averageRange;
}


//Funciones

/**
 * Esta función agrega un elemento lluvia a la lista de lluvias
 *
 * Args:
 *   code (string): Código de la lluvia.
 *   n (string): Nombre de condicion cliamtica
 *   average (int): Promedio de la lluvia
 *   oldRain (Rain): Lista de lluvia.
 *
 * Returns:
 *   Lista de lluvia
 */
Rain*Rain::addRain(string code,string n,int average,Rain*oldRain){

    if (searchRain(oldRain,code)== NULL){
        Rain*newRain = new Rain(code,n,average);
        newRain->next = oldRain;
        oldRain = newRain;
        cout << "\n\t\t-- LOS DATOS SE HAN AGRUEGADO EXITOSAMENTE A LA LISTA DE LLUVIA -- ";
    }
    else{
        cout<< "\n\tLA LLUVIA YA ESXISTE EN LA LISTA";
    }
    return oldRain;

}


/**
 * Imprime la lista de lluvias
 *
 * Args:
 *   r (Rain): Lista de lluvias.
 */
void Rain::printRainList(Rain*r){

    if(r== NULL)
        cout<< "\n\t-- La lista de lluvias esta vacia --\n";
    else{
        Rain*temp =r;
        cout<<"\n\t   =========================================\n";
        cout<<"\t   ||          LISTA DE LLUVIAS           ||\n";
        cout<<"\t   =========================================\n";
        while(temp != NULL){
            cout<<"\n\t________________________________________________\n";
            cout<<"\n\tCODIGO: "<<temp->getRainCode()<<endl;
            cout<<"\n\tNOMBRE: "<<temp->getName()<<endl;
            cout<<"\n\tRANGO PROMEDIO: "<<temp->getAverageRange()<<endl;
            temp = temp->next;
        }
    }
    cout<<"\n\t________________________________________________\n";
    cout<<"\n\tPRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU...";
    cin.ignore();
    cin.get();

}


/**
 * Esta función busca un objeto de lluvia en la lista de lluvia
 *
 * Args:
 *   rainList (Rain): Lista de objetos de lluvia.
 *   code (string): Código de la lluvia que se quiere buscar
 *
 * Returns:
 *   Un puntero al objeto Rain que conincide con el codigo buscado.
 */
Rain*Rain::searchRain(Rain*rainList,string code){
    Rain*temp =rainList;
    while(temp != NULL){

        if (temp->getRainCode()==code){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


/**
 * *Funcion que elimina un elemento lluvia de la lista de lluvias
 *
 * Args:
 *   rList (Rain): Lista de lluvias
 *   code (string): Código de la lluvia a borrar.
 */
Rain* Rain::deleteRain(Rain*rList,string code){
        if(rList == NULL){
        cout<<"\n\tLA LISTA DE LLUVIA ESTA VACIA";

    }else{
        if(rList->rainCode ==code){

            rList = rList->next;
        }else{
            Rain* temp = rList;
            Rain* previ = NULL;
            while((temp!=NULL) && (temp->rainCode!=code)){
                previ = temp;
                temp = temp->next;
            }
            if(temp == NULL){
                cout<<"\n\tNO SE ENCONTRO EL NODO";
            }else{
                previ->next = temp ->next;
            }
        }
    }
   return rList;
}

/**
 * Modifica el nombre de un objeto de lluvia.
 *
 * Args:
 *   rainList (Rain): La lista de lluvias.
 *   newName (string): El nuevo nombre de la lluvia.
 *   rainCode (string): El código de la lluvia que se quiere modificar.
 */
void Rain::modName(Rain*rainList,string newName,string rainCode){
    Rain*rain = searchRain(rainList,rainCode);
    rain->setName(newName);
}

/**
 * Modifica el código de una condición de climatica
 *
 * Args:
 *   rainList (Rain): Lista de lluvia
 *   newRainCode (string): El nuevo código para la condición climatica.
 *   rainCode (string): El código de la condición climatica a modificar.
 */
void Rain::modRainCode(Rain*rainList,string newRainCode,string rainCode){

    if (searchRain(rainList,newRainCode)== NULL){
        Rain*rain = searchRain(rainList,rainCode);
        rain->setRainCode(newRainCode);
    }
    else{
        cout<<"\n\tEL CODIGO DE LA CONDICION CLIMATICA YA EXISTE";
    }
}
/**
 * Modifica el rango promedio de un objeto de lluvia.
 *
 * Args:
 *   rainList (Rain): La lista de lluvias.
 *   newAverage (int): el nuevo rango promedio
 *   rainCode (string): El código de la lluvia que se quiere modificar.
 */

void Rain::modAverageRange(Rain*rainList,int newAverage,string rainCode){
    Rain*rain = searchRain(rainList,rainCode);
    rain->setAverageRange(newAverage);
}


/**
 * Crea una lista de lluvia y la retorna
 *
 * Args:
 *   rainList (Rain): La lista de objetos de lluvia.
 *
 * Returns:
 *   La lista de lluvias.
 */
Rain* Rain::dataLoad(Rain* rainList){

    rainList=addRain("1","Extremo lluvioso",3347,rainList);
    rainList=addRain("2","Seco",1581,rainList);
    rainList=addRain("3","Normal",1266,rainList);
    rainList=addRain("4","Extremo lluvioso",2326,rainList);
    rainList=addRain("5","Lluvioso",3806,rainList);
    rainList=addRain("6","Normal",3449,rainList);
    rainList=addRain("7","Extremo Seco",52,rainList);
    rainList=addRain("8","Extremo lluvioso",326,rainList);
    rainList=addRain("9","Extremo lluvioso",2154,rainList);
    rainList=addRain("10","Seco",502,rainList);
    rainList=addRain("11","Lluvioso",1567,rainList);

    return rainList;
}







