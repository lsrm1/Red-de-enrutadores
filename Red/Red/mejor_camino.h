#ifndef MEJOR_CAMINO_H
#define MEJOR_CAMINO_H

#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void conexiones(char router,map<char, map<char, int>> &red, char destino, int &costo,vector<char> &ruta , vector <int> & allcosto ,vector <vector<char>> &allruta ){

    map<char, int>:: iterator m;
    map<char, int>:: iterator p;
    vector<char>:: iterator f;

    char _router;
    int _costo = 0;


    for (m = red[router].begin() ;  m != red[router].end(); m++){

        f = find(ruta.begin(), ruta.end(), m ->first);

        if ( (f == ruta.end()) && (m -> first != destino)){

            p = red[ m -> first ].find(destino);
            costo += m -> second;

            ruta.push_back( m -> first);

            if ( p != red[ m-> first ].end()){

                _costo = costo;
                _costo += p -> second;

                 allcosto.push_back(_costo);
                allruta.push_back(ruta);
            }
            _router = m -> first;
            conexiones( _router ,red, destino, costo, ruta , allcosto,allruta);

        }
    }
}

void mejorcamino(char origen, char destino , map<char, map<char, int>> red){

    vector<char> ruta;
    vector <int> allcosto ;
    vector <vector<char>> allruta;

    int minimo = 0;
    int index = 0;
    int costo = 0;
    int _costo = 0;
    char router;

    map<char, int>:: iterator i;
    map<char, int>:: iterator it;

    it = red[origen].find(destino);

    if ( it != red[origen].end()){
        ruta.push_back(origen);
        allcosto.push_back(it -> second);
        allruta.push_back(ruta);
    }
    ruta.clear();

    for (it = red[origen].begin() ;  it != red[origen].end(); it++){

        ruta.push_back(origen);

       if ( ( it-> first != origen) && ( it-> first != destino)){

            ruta.push_back( it-> first);
            costo = it -> second;

            i = red[ it-> first ].find(destino);

            if ( i != red[ it-> first ].end()){

                _costo = costo;
                _costo += i -> second;

                allcosto.push_back(_costo);
                allruta.push_back(ruta);

            }
            router = it -> first;
            conexiones( router ,red,destino, costo, ruta, allcosto,allruta);

        }

       ruta.clear();

    }

    minimo =  allcosto[0];

    for (int l = 0 ; l <  allcosto.size() ; l++){

        if (allcosto[l] < minimo){

            minimo =  allcosto[l];
            index = l;
        }
    }



    cout<<"------------------------------------------------\n";
    cout<<"\nRuta: ";
    for (int l = 0 ; l < allruta[index].size();l++){

     cout<< allruta[index][l]<<"--->";

   }

    cout<< destino<<endl<<"Costo de envio: "<<minimo<<endl;

}

void menuprincipal(int &menu){
    cout<<"------------------------------------------------\n";
    cout<<"               SIMULADOR DE RED\n";
    cout<<"------------------------------------------------\n";
    cout<<"\n1. Crear red \n2. Modificar red\n3. Buscar “El mejor camino” \n4. Salir\n\n";
    cout<<"Selecciona: ";
    cin>>menu;
}

#endif // MEJOR_CAMINO_H
