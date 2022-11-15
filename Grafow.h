#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <list>

using namespace std;

// Creación de la clase Nodo la cual contiene el destino y el peso de un vertice
// a otro
class Nodo {
public:
  int peso, destino;
  Nodo(int destino, int peso) {
    this->destino = destino;
    this->peso = peso;
  }
};
//Estructura DSU para hacer el Árbol recubridor mínimo
class DSU {
  int *padre;
  int *rango;

public:
  DSU(int n) {
    padre = new int[n];
    rango = new int[n];

    //Creacion de lista con -1 y 1 de acuerdo a la cantidad de vertices
    for (int i = 0; i < n; i++) {
      padre[i] = -1;
      rango[i] = 1;
    }
  }

  // Funcion que busca el vertice para reemplazarlo en la lista de -1
  int buscar(int i) {
    if (padre[i] == -1)
      return i;

    return padre[i] = buscar(padre[i]);
  }

  //Funcion que une origen y destino para hacer el arbol mas pequeño
  void unir(int x, int y) {
    int s1 = buscar(x);
    int s2 = buscar(y);

    if (s1 != s2) {
      if (rango[s1] < rango[s2]) {
        padre[s1] = s2;
        rango[s2] += rango[s1];
      } else {
        padre[s2] = s1;
        rango[s1] += rango[s2];
      }
    }
  }
};

// Implementado usando las listas de adyacencia
class Grafow {
  // Las propiedades son la cantidad de vertices y su lista de adyacencia
  int vertices;
  list<Nodo *> *adj;

public:
  // Inicializamos la lista de adyacencia del tamaño del vertice mayor ya que
  // este define el tamaño
  Grafow(int vertices) {
    this->vertices = vertices;
    this->adj = new list<Nodo *>[this->vertices];
  }
  // Funcion que añade un vertice tomando uno de referencia
  void crear(int origen, int destino, int peso) {
    // Si el origen es mayot que la cantidad de vertices entonces esta fuera de
    // alcance
    if (origen >= this->vertices || destino >= this->vertices) {
      return;
    }
    // Aqui añadimos el nodo solo hacemos de origen a destino para que sea un
    // grafo dirigido
    this->adj[origen].push_back(new Nodo(destino, peso));
    // this->adj[destino].push_back(new Nodo(origen,peso)); Si se descomenta
    // esto ya no es dirigido
  }

  void mostrar() {
    // Recorremos la lista de adyacencia
    for (int elemento = 0; elemento < this->vertices; elemento++) {
      cout << elemento << "(";
      // Usamos la manera nueva de C++ 11 para recorrer listas y poder mostrar
      // los atributos del nodo
      for (auto const &i : this->adj[elemento]) {
        cout << "( Destino: " << i->destino << ",Peso:" << i->peso << ")->";
      }
      cout << ")\n";
    }
  }

  // Funcion que nos devuelve el nuevo minimo
  int minimo(int distancia[], bool procesado[]) {
    int Min = 99999, indice = 0;
    for (int i = 0; i < 5; i++)
      if (distancia[i] <= Min && !procesado[i]) {
        Min = distancia[i];
        indice = i;
      }
    return indice;
  }
  
//dijkstra - complejidad O((E+V) log V) 
  void dijkstra(int s) {
    // Definimos las listas necesarias para usar dijkstra
    int distancia[5];
    bool procesado[5] = {};
    // Al comienzo todas las distancias las ponemos a un numero maximo
    for (int i = 0; i < 5; i++)
      distancia[i] = 99999;
    distancia[s] = 0;

    for (int i = 0; i < 4; i++) {
      int u = minimo(distancia, procesado);
      procesado[u] = true;
      // recorremos la lista de adjacencia para aplicar dijkstra
      for (auto const &it : this->adj[u])

        if (!procesado[it->destino] && distancia[u] != 99999 &&
            distancia[it->destino] > distancia[u] + it->peso)
          distancia[it->destino] = distancia[u] + it->peso;
    }
    // imprimomos las distancias
    for (int i = 0; i < 5; i++)
      cout << i << " ---> " << distancia[i] << endl;
  }

  //Kruskal - copmlejidad de O(m log n), donde m es el número de aristas del grafo y n el número de vértices
  void kruskal() {

    int ans = 0;
    //Creacion de estructura DSU
    DSU s(vertices);

    cout << "Vertices del Árbol Recubridor Mínimo: " << endl;
    //For para poder recorrer todo el grafo
    for (int i = 0; i < vertices - 1; i++) {
      //For para aplicar al logaritmo al indice y a sus aristas
      for (auto const &it : this->adj[i]) {
        //Valores del indice y su arista
        int w = it->peso;
        int x = it->destino;
        //Estructura DSU para determinar que arista es el que menor peso tiene y no forma un ciclo para el Arbol Recubridor Minimo
        if (s.buscar(i) != s.buscar(x)) {
          s.unir(i, x);
          ans += w;
          cout << i << " -> " << x << ", Peso: " << w << endl;
        }
      }
    }

    cout << "Recubridor mínimo: " << ans;
  }
};
