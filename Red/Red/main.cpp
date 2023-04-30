#include <iostream>
#include <map>

using namespace std;

class Router{

   public:
    map <char,int> tabla;

    public:
    Router(char,int);

};

Router :: Router( char id,  int costo ){
    tabla.insert (pair <char,int> (id,costo) );
}

class Red{

    public:

    map<char, map<char, int>> mapared;

    public:

    void agregarouter( ){

        char rep = 'y';
        char id ;

        cout<< "Agrega ID de los enrutadores\n";

        do{

            cout<<"ID: ";cin>> id;

            Router router = Router(id,0);
            mapared.insert(pair< char, map<char, int> >(id,router.tabla));

            cout<<"Agregar otro enrutador ?(y/n) : ";cin>>rep;

        }while(rep == 'y');


    }

    void conectar(){

        char id;
        char _id;
        int costo;
        char rep = 'y';

        do{

            cout<< "Conexiones...\nID: "; cin>>id;
            cout<<"Conectar al ID: ";cin>>_id;
            cout<<"Costo de la conexion: "; cin>> costo;

            mapared[id].insert(pair<char,int>(_id,costo));
            mapared[_id].insert(pair<char,int>(id,costo));

            cout<<"Agregar otro conexion?: ";cin>>rep;

        }while(rep == 'y');


    }

    void modifcosto (){

        char id;
        char _id;
        int newcosto;

        cout<<"ID: "; cin>>id;
        cout<<"Modicar costo con el  ID: ";cin>>_id;
        cout<<"Nuevo costo de la conexion: "; cin>> newcosto;

        mapared[id][_id] = newcosto;
        mapared[_id][id] = newcosto;
    }

    void removerouter (){

        char id;

        cout<<"ID del enrutador a remover: "; cin>>id;


        mapared.erase(id);

        map<char, map<char, int>>:: iterator it;

        for (it = mapared.begin() ;  it != mapared.end(); it++){

            mapared [ it -> first ].erase(id);

        }
    }
};

void menuprincipal(int &menu){

    cout<<"____________________________________________________";
    cout<<"\nMENU PRINCIPAL\n";
    cout<<"\n1. Crear red \n2. Modificar red\n3. Buscar “El mejor camino” \n4. Salir\n\nSelecciona:";
    cout<<"____________________________________________________";
    cin>>menu;
}


int main()
{

    int menu = 0;
    int opcion = 0;

    bool ejecutar = true;
    Red red;

    while (ejecutar){

        menuprincipal(menu);

        if (menu == 1){

            red.agregarouter( );
            red.conectar();

        }

        if (menu == 2){

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

        if (menu == 3){




        }



    }

    return 0;
 }
