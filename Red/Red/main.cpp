#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/*class Router{
    public:
    map <char,int> tabla;

    public:
    Router(char,int);

};

Router::Router(char id, int costo){
    tabla.insert(pair<char,int>(id,costo));
}

class Red{
    public:
    map<char, map<char, int>> red;

    public:
    Red();

    void agregarouter( char id, map<char, int> tabla ){
        red.insert(pair< char, map<char, int> >(id,tabla));
    }

    void conectar(char id, char _id,int costo){

        red[id].insert(pair<char,int>(_id,costo));
        red[_id].insert(pair<char,int>(id,costo));;
    }

 };

Red::Red(){};

int main()
{
    char id ;
    char _id;
    int costo = 0;
    char rep = 'y';

    Red red = Red();
    do{
        cout<<"id: ";cin>> id;
        Router router = Router(id,costo);
        red.agregarouter( id,router.tabla );
        cout<<"Agregar otro router?: ";cin>>rep;

    }while(rep == 'y');

    do{

        cout<< "Conexiones:\nQue router va a conectar? "; cin>>id;
        cout<<"A cual router lo va a conectar: ";cin>>_id;
        cout<<"Costo de la conexion: "; cin>> costo;
        red.conectar(id,_id,costo);
        cout<<"Agregar otro conexion?: ";cin>>rep;

    }while(rep == 'y');

    cout<<red.red.size();*/

int main(){

    map<char, map<char, int>> mapmap;
    vector<int> ney ;

    // insert elements in random order
    mapmap.insert(make_pair('A', map<char, int> {make_pair('A', 0)}));
    mapmap['A'].insert(pair<char,int>('B', 4));
    mapmap['A'].insert(pair<char,int>('C', 10));
    mapmap['A'].insert(pair<char,int>('E', 15));
    mapmap.insert(make_pair('B', map<char,int> {make_pair('B', 0)}));
    mapmap['B'].insert(pair<char,int>('A', 4));
    mapmap['B'].insert(pair<char,int>('C', 6));
    mapmap['B'].insert(pair<char,int>('E', 8));
    mapmap.insert(make_pair('C', map<char, int> {make_pair('C', 0)}));
    mapmap['C'].insert(pair<char,int>('B', 6));
    mapmap['C'].insert(pair<char,int>('A', 10));
    mapmap['C'].insert(pair<char,int>('E', 2));
    mapmap.insert(make_pair('E', map<char, int> {make_pair('E', 0)}));
    mapmap['E'].insert(pair<char,int>('A', 10));
    mapmap['E'].insert(pair<char,int>('C', 2));
    mapmap['E'].insert(pair<char,int>('B', 8));

    //map<char, map<char, int>>:: iterator i;
   map<char, int>:: iterator k;

   k = mapmap['A'].find('C');

   if (k != mapmap['A'].end()){

       ney.push_back(k -> second);
   }





    //A -> C



   /* for (k = mapmap['A'].begin(); k !=  mapmap['A'].end(); k++){
        cout<<"Clave ";
        cout << k -> first<<'\n';
        cout<<"Valor;";
        cout<<k -> second<<'\n';

    }*/








/*
    for (i = mapmap.begin(); i != mapmap.end(); i++){

        cout<<"Clave Principal ";
        cout << i -> first<<'\n';


        for (k = i->second.begin(); k !=  i->second.end(); k++){
            cout<<"Clave ";
            cout << k -> first<<'\n';
            cout<<"Valor;";
            cout<<k -> second<<'\n';

        }


        cout<<endl;
    }*/






 return 0;
}
