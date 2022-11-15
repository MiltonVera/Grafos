#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

class Grafod 
{
    int V;
    list<int>*adj;
    public:
        Grafod(int V) 
        {
            this->V = V;
            this->adj = new list<int>[this->V];
        }
        
        void Agregar(int origen,int destino)
        {
            if(origen>=this->V || destino>=this->V)
            {
                return;
            }
            this->adj[origen].push_back(destino);
        }

        void Quitar(int origen,int destino)
        {
            if(origen>=this->V || destino>=this->V)
            {
                return;
            }
            auto itr = find(this->adj[origen].begin(),this->adj[origen].end(),destino);
            this->adj[origen].erase(itr);
        }

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