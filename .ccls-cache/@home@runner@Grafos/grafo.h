#include <bits/stdc++.h>
#include <iostream>

using namespace std;
class Grafo {
  int V;
  list<int> *adj;

public:
  Grafo(int V) {
    this->V = V;
    this->adj = new list<int>[this->V];
  }

  void Agregar(int origen, int destino) {
    if (origen >= this->V || destino >= this->V) {
      return;
    }
    this->adj[origen].push_back(destino);
    this->adj[destino].push_back(origen);
  }

  void Quitar(int source, int dest) {
    if (source >= this->V || dest >= this->V) {
      return;
    }
    auto itr = find(this->adj[source].begin(), this->adj[source].end(), dest);
    this->adj[source].erase(itr);
    auto itr1 = find(this->adj[dest].begin(), this->adj[dest].end(), source);
    this->adj[dest].erase(itr1);
  }

  void Mostrar() {
    for (int v = 0; v < this->V; v++) {
      cout << v << "(";
      for (auto itr = this->adj[v].begin(); itr != this->adj[v].end(); itr++) {
        cout << *itr << "->";
      }
      cout << ")\n";
    }
  }
};