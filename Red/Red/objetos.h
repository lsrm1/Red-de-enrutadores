#ifndef OBJETOS_H
#define OBJETOS_H
#include <fstream>

using namespace std;

//Router
class Router{

   public:
    map <char,int> tabla;

    public:
    Router(char,int);

};

Router :: Router( char id,  int costo ){
    tabla.insert (pair <char,int> (id,costo) );
}


//Red
class Red{

    public:
    map<char, map<char, int>> mapared;

    public:
    void agregarouter( );
    void conectar();
    void modifcosto ();
    void removerouter ();
    void cargared();
};

void Red::agregarouter( ){

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

void  Red::conectar(){

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

void  Red::modifcosto (){

    char id;
    char _id;
    int newcosto;

    cout<<"ID: "; cin>>id;
    cout<<"Modicar costo con el  ID: ";cin>>_id;
    cout<<"Nuevo costo de la conexion: "; cin>> newcosto;

    mapared[id][_id] = newcosto;
    mapared[_id][id] = newcosto;
}

void  Red::removerouter(){

    char id;

    cout<<"ID del enrutador a remover: "; cin>>id;


    mapared.erase(id);

    map<char, map<char, int>>:: iterator it;

    for (it = mapared.begin() ;  it != mapared.end(); it++){

        mapared [ it -> first ].erase(id);

    }
}

void Red::cargared(){

    char router;
    char id;
    int costo;

    ifstream archivo;
    archivo.open("red.txt");

    while(archivo.good()){

        archivo>>router;
        archivo>>id;
        archivo >> costo;

        mapared[router][id] = costo;
    }

    archivo.close();


}

#endif // OBJETOS_H
