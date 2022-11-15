#include <list>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>


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

  //Busqueda en anchura -  complejidad de O(V+E), donde V es el numero de vertices y E el de aristas
  void BFS (int source){
    //inicializamos el vector que guarda el recorrido del grafo
    vector<bool>visited(this->V,false);
    list<int>q;
    q.push_back(source);
    visited[source] = true;

    //recorremos la lista "q" hasta que ya no haya elementos por recorrer 
    while(!q.empty()){
      source = q.front();
      q.pop_front();
      cout<<source<<" "<<endl;
  
      for(auto itr=this->adj[source].begin();itr!=this->adj[source].end(); itr++){
        if(visited[*itr]==false){
            visited[*itr] =true;
            q.push_back(*itr);
        }
      }
    }
  }

  //Busqueda en profundidad -  complejidad de O(V+E), donde V es el numero de vertices y E el de aristas
  void DFSHelper(vector<bool>& visited,int source){
    visited[source] = true;
    cout<<source<<" "<<endl;
    for(auto itr = this->adj[source].begin();itr!=this->adj[source].end();itr++){
      if(!visited[*itr]){
        //recursividad 
        DFSHelper(visited,*itr);
      }
    }
  }


  void DFS(){
    //inicializamos el vector de visitas
    vector<bool>visited(this->V,false);
    for(int v=0;v<this->V;v++){
      //recorremos el vector hasta que no queden elementos
      if(!visited[v]){
        DFSHelper(visited,v);
      }
    }
  }
  
bool isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;
    // Recur for all the vertices adjacent to this vertex
    for (auto const &i : this->adj[v])
    {
        // If an adjacent is not visited, then recur for
        // that adjacent
        if (!visited[i])
        {
           if (isCyclicUtil(i, visited, v))
              return true;
        }
 
        // If an adjacent is visited and not parent of current
        // vertex, then there is a cycle.
        else if (i != parent)
           return true;
    }
    return false;
}
 
// Returns true if the graph is a tree, else false.
bool isTree()
{
    // Mark all the vertices as not visited and not part of
    // recursion stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // The call to isCyclicUtil serves multiple purposes.
    // It returns true if graph reachable from vertex 0
    // is cyclic. It also marks all vertices reachable
    // from 0.
    if (isCyclicUtil(0, visited, -1))
             return false;
 
    // If we find a vertex which is not reachable from 0
    // (not marked by isCyclicUtil(), then we return false
    for (int u = 0; u < V; u++)
        if (!visited[u])
           return false;
 
    return true;


};