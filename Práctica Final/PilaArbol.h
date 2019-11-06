#ifndef PILAARBOL_H
#define PILAARBOL_H
#include "NodoPilaArbol.h"

class PilaArbol
{
private:
	pNodoPilaArbol cima;
public:
	PilaArbol();
	~PilaArbol();
	
	void apilar(NodoArbol p);
	void desapilar();
	NodoArbol verCima();
	bool esVacia();

};

#endif // PILAARBOL_H
