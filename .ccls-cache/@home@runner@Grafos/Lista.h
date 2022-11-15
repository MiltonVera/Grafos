#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

#include "Nodo.h"

using namespace std;


// class node: un valor y un puntero a otro nodo
class Node
{	public:

		Nodo value;
		Node *next;
	
		Node(Nodo value)
		{	this->value = value;
			this->next = NULL;
		}

};

//  Clase lista enlazada simple: 
//	puntero al primer nodo y tamaño total
class List
{	Node *first;   // puntero al primer nodo
	int size;

	public:
		List() 
		{	first = NULL; 
			size = 0;
		}
		
		int getSize(){ return size; }
		void showList();

		void insertEnd(int);

};


void List::insertEnd(int newVal){
  Node *node = new Node(newVal);
  Node *aux;
  
  if(this->size == 0){
    this->insertFirst(newVal);
  }
  else{
    aux = this->first;
    // Recorrer la lista hasta legar al ultimo elemento, O(n)
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = node; // el ultimo elemento hacia el nodo nuevo
    this->size++;
  }
}


