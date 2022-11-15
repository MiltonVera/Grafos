
#include <algorithm>
#include <iostream>
#include <list>
#include "Nodo.h"

using namespace std;


class Grafowd {
  int V;
  list<Nodo *> *adj;

public:
  Grafowd(int V) {
    this->V = V;
    this->adj = new list<Nodo *>[this->V];
  }
  void crear(int origen, int destino, int peso) {
    if (origen >= this->V || destino >= this->V) {
      return;
    }
    this->adj[origen].push_back(new Nodo(destino, peso));
  }
  // Imprimir
  void Imprimir()
        {
            for(int v=0;v<this->V;v++)
            {
                cout<<v<<"(";
                for(auto itr=this->adj[v].begin();itr!=this->adj[v].end();itr++)
                {
                    cout<<*itr<<"->";
                }
                cout<<")\n";
            }
        }

};
