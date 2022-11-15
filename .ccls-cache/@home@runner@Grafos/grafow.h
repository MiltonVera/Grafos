#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Nodo
{
    public:
    int peso,destino;
    Nodo(int dest,int weight)
    {
        this->destino = dest;
        this->peso = weight;
    }

};

class GrafoPonderado 
{
    int V;
    list<Nodo*>*adj;
    public:
        GrafoPonderado(int V) 
        {
            this->V = V;
            this->adj = new list<Nodo*>[this->V];
        }
        void crear(int origen,int destino,int peso)
        {
            if(origen>=this->V || destino>=this->V)
            {
                return;
            }
            this->adj[origen].push_back(new Nodo(destino,peso));
            this->adj[destino].push_back(new Nodo(origen,peso));
        }
        void eliminar(int origen,int destino)
        {
            if(origen>=this->V || destino>=this->V)
            {
                return;
            }
            for(auto itr=this->adj[origen].begin();itr!=this->adj[origen].end();itr++)
            {
                if((*itr)->destino==destino)
                {
                    this->adj[origen].erase(itr);
                }
            }
            for(auto itr=this->adj[destino].begin();itr!=this->adj[destino].end();itr++)
            {
                if((*itr)->destino==origen)
                {
                    this->adj[destino].erase(itr);
                }
            }

        }
        // Imprimir
        void Mostrar()
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

