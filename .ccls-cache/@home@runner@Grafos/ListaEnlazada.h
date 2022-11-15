#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;


// class node: un valor y un puntero a otro nodo
class Node
{	public:

		int value;
		Node *next;
	
		Node(int value)
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

		int find(int);
		void update(int, int);

		void insertEnd(int);
		void insertFirst(int);
		bool insertAtIndex(int, int);

		void deleteFirst();
		void deleteLast();
		void deleteAtIndex(int);

};

void List::insertFirst(int newVal){
  Node *node = new Node(newVal);

  node->next = this->first;
  this->first = node;
  this->size++;
}
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
bool List::insertAtIndex(int newVal,int index){
  Node *node = new Node(newVal);
  Node *aux = this->first;
  int i = 0;

  if(index > this->size){
    cout<<"Indice mayor a numero de elementos"<<endl;
    return false;
  }
  else if(index == 0){
    this->insertFirst(newVal);
    return true;
  }
  else if(index == this->size){
    this->insertEnd(newVal);
    return true;
  }else{
    while(aux->next != NULL){
      if(i+1 == index){
        node->next = aux->next;
        aux->next = node;
        this->size++;
        
        return true;
      }
      i++;
      aux = aux->next;
    }
  }
}

void List::deleteFirst(){
  Node *aux = this->first;
  this->first = aux->next;
  delete aux;
  this->size--;
}
void List::showList(){
  Node *aux = this->first;
  cout<<"Size: "<<this->size<<endl;
  while(aux != NULL){
    cout<<aux->value<<endl;
    aux = aux->next;
  }
  cout<<endl;
}