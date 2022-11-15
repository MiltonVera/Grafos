#include <iostream>

#include "Grafo.h"
//#include "Grafod.h"
#include "Grafow.h"


using namespace std;

int main() { 
  //-----Inicializar los grafos

  //Grafo normal
  Grafo grafoNormal = Grafo(5);
  //Grafo Dirigido


  //Grafo normal
    grafoNormal.Agregar(0,1);
    grafoNormal.Agregar(0,2);
    grafoNormal.Agregar(0,4);
    grafoNormal.Agregar(1,2);
    grafoNormal.Agregar(2,0);
    grafoNormal.Agregar(2,3);
    grafoNormal.Agregar(3,4);
    grafoNormal.Agregar(4,3);
  

    grafoNormal.Mostrar();

    cout<<"BFS del grafo normal"<<endl;
    grafoNormal.BFS(0);
    cout<<"DFS del grafo normal"<<endl;
    grafoNormal.DFS();
  
  // Grafo Con Peso Dirigido
  Grafow grafoPonderadoDirigido = Grafow(5);
  //A = 0, B = 1, C = 2, D = 3 , E = 4
  //Basado en el grafo de la presentación de Dijkstra
  
  grafoPonderadoDirigido.crear(0,1,4);
  grafoPonderadoDirigido.crear(0,2,2);
  
  grafoPonderadoDirigido.crear(1,2,3);
  grafoPonderadoDirigido.crear(1,3,2);
  grafoPonderadoDirigido.crear(1,4,3);
  
  grafoPonderadoDirigido.crear(2,1,1);
  grafoPonderadoDirigido.crear(2,3,4);
  grafoPonderadoDirigido.crear(2,4,5);
  
  grafoPonderadoDirigido.crear(4,3,1);

  grafoPonderadoDirigido.mostrar();

 
  //-----Demostracion function isTree(Jose Marentes)

  //-----Demostracion de funciones DFS y BFS(Tadeo Barrera)
  cout<<"BFS del grafo normal"<<endl;
  grafoNormal.BFS(0);
  cout<<"DFS del grafo normal"<<endl;
  grafoNormal.DFS();
  //-----Demostracion de Orden Topologico(Ramón Danzos)

  //-----Demostracion de Dijkstra(Milton Vera)
  
  grafoPonderadoDirigido.dijkstra(0);
  // Resultado igual que en el ejercicio (0,3,2,5,6)

  
  //-----Demostracion de Prim(Jesus Daniel)

  //-----Demostracion de Kruskal(Luis Perez)
  
  grafoPonderadoDirigido.kruskal();


  //----Mini-investigacion ¿Que son ciclo euleriano y hamiltoniano?
  
  
}