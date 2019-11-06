#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

class Nodo
{
private:
	char valor;
	Nodo *siguiente;

public:

	friend class Pila; 
    friend class Cola;
    friend class Lista;
	Nodo(char v, Nodo *sig = NULL);
	~Nodo();

};

typedef Nodo *pNodo; 
#endif // NODO_H