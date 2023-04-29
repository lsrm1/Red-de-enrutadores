#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void way(char router,map<char, map<char, int>> &red, char origen, char destino, int &costo, vector<char> &ruta ){

    map<char, int>:: iterator m;
    map<char, int>:: iterator p;
    vector<char>:: iterator f;

    char _router;


    for (m = red[router].begin() ;  m != red[router].end(); m++){

        f = find(ruta.begin(), ruta.end(), m ->first);

        if ( f == ruta.end() ){

            p = red[ m -> first ].find(destino);

            if ( p != red[ m-> first ].end()){


                ruta.push_back( m -> first);
                ruta.push_back( p -> first);

                costo += m -> second;
                costo += p -> second;


            }

            else{

                costo += m -> second;
                _router = m -> first;
                ruta.push_back( m -> first);
                way( _router ,red, origen, destino, costo, ruta);

            }

        }
    }
}


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
    map<char, map<char, int>> mapared;

    public:
    Red();

    void agregarouter( char id, map<char, int> tabla ){
        mapared.insert(pair< char, map<char, int> >(id,tabla));
    }

    void conectar(char id, char _id,int costo){

        mapared[id].insert(pair<char,int>(_id,costo));
        mapared[_id].insert(pair<char,int>(id,costo));;
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

    }while(rep == 'y');*/

int main(){
    int costo = 0;
    vector<char> ruta;
    char origen = 'A';
    char destino = 'C';
    char router ;
    vector <int> allway ;
    vector <vector<char>> allruta;
    map<char, map<char, int>> red;
    int minimo = 1000;


    red.insert(make_pair('A', map<char, int> {make_pair('A', 0)}));
    red['A'].insert(pair<char,int>('B', 4));
    red['A'].insert(pair<char,int>('C', 10));
    //red['A'].insert(pair<char,int>('E', 15));
    red['A'].insert(pair<char,int>('F', 5));
    red.insert(make_pair('B', map<char,int> {make_pair('B', 0)}));
    red['B'].insert(pair<char,int>('A', 4));
    //red['B'].insert(pair<char,int>('C', 6));
    red['B'].insert(pair<char,int>('E', 1));
    red.insert(make_pair('C', map<char, int> {make_pair('C', 0)}));
    //red['C'].insert(pair<char,int>('B', 6));
    red['C'].insert(pair<char,int>('A', 10));
    red['C'].insert(pair<char,int>('E', 2));
     red['C'].insert(pair<char,int>('F', 1));
    red.insert(make_pair('E', map<char, int> {make_pair('E', 0)}));
    //red['E'].insert(pair<char,int>('A', 10));
    //red['E'].insert(pair<char,int>('C', 2));
    red['E'].insert(pair<char,int>('B', 1));
     red['E'].insert(pair<char,int>('F', 1));
    red.insert(make_pair('F', map<char, int> {make_pair('F', 0)}));
    red['F'].insert(pair<char,int>('A', 5));
    red['F'].insert(pair<char,int>('C', 1));
    red['F'].insert(pair<char,int>('E', 1));



   map<char, int>:: iterator i;
   map<char, int>:: iterator it;
   vector<char>:: iterator fi;


    it = red[origen].find(destino);



    if ( it != red[origen].end()){

        ruta.push_back(origen);
        ruta.push_back(destino);
        allway.push_back(it -> second);
        allruta.push_back(ruta);

    }

    ruta.clear();
    ruta.push_back(origen);


    for (it = red[origen].begin() ;  it != red[origen].end(); it++){

        fi= find(ruta.begin(), ruta.end(), it ->first);

        if ( fi == ruta.end() ){

           i = red[ it-> first ].find(destino);

            if ( i != red[ it-> first ].end()){

                ruta.push_back( it-> first);
                ruta.push_back( i-> first);

                costo = it -> second;
                costo += i -> second;

                allway.push_back(costo);
                allruta.push_back(ruta);

            }

            else{

                costo = it -> second;
                router = it -> first;
                ruta.push_back( it-> first);

                way(router,red, origen, destino, costo, ruta );

                allway.push_back(costo);
                allruta.push_back(ruta);

            }


        }

    }

    for (int l = 0 ; l < allway.size() ; l++){

        if(allway[l] < minimo){

         minimo = allway[l];
         ruta = allruta[l];

        }

    }


  return 0;
}
