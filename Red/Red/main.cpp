#include <iostream>
#include "mejor_camino.h"
#include "objetos.h"

/*IMPORTANTE
Los ID de los enrutadores deben ser caracteres alfabeticos
El archivo que carga la red se encuentra en la carpeta build con el nombre "red.txt"*/

using namespace std;

int main()
{
    int menu = 0;
    int opcion = 0;
    char origen;
    char destino;

    bool ejecutar = true;
    Red red;

    while (ejecutar){

        menuprincipal(menu);

        if (menu == 1){ //Permite crear la red o cargar desde archivo

            cout<<"1. Crear red desde consola\n2. Cargar red desde archivo\nSelecciona: ";
            cin>>opcion;

            if (opcion == 1){
                red.agregarouter( );
                red.conectar();
            }

            if(opcion == 2){
                red.cargared();
            }

        }

        if (menu == 2){ // Modifica la red

            cout<<"1. Agregar enrutadores a la red\n2. Modificar costos de  conexion\n"
            "3. Remover enrutadores\nSelecciona: "; cin>>opcion;

            if (opcion ==  1){

                red.agregarouter( );
                red.conectar();
            }
            if (opcion ==  2){

                red.modifcosto();
            }
            if (opcion ==  3){

                red.removerouter();
            }
        }


        if (menu == 3){ //Busca el mejor camino

            cout<<"ID del enrutador origen: ";cin>>origen;
            cout<<"ID del enrutador destino: ";cin>>destino;
            mejorcamino(origen, destino,red.mapared);
        }


        if(menu == 4){
            ejecutar = false;
        }

    }

    return 0;
 }
