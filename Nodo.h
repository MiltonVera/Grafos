#ifndef NODO
#define NODO

class Nodo {
public:
  int peso, destino;
  Nodo(int destino, int peso) {
    this->destino = destino;
    this->peso = peso;
  }
};

#endif NODO