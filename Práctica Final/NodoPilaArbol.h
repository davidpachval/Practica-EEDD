#ifndef NODOPILAARBOL_H
#define NODOPILAARBOL_H
#include "NodoArbol.h"
#include <iostream>
using namespace std;

class NodoPilaArbol
{
private:
	NodoArbol nodo; //DUDA
	NodoPilaArbol *siguiente;
public:
	NodoPilaArbol(NodoArbol n, NodoPilaArbol *sig=NULL);
	~NodoPilaArbol();
	friend class PilaArbol;
};

typedef NodoPilaArbol *pNodoPilaArbol; 
#endif // NODOPILAARBOL_H
