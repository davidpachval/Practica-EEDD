#ifndef PILAN_H
#define PILAN_H
#include "NodoN.h"

class PilaN
{
private:
	pNodon cima;
public:
	PilaN();
	~PilaN();

	void apilar(int v);
	void desapilar();
	void mostrar();
	int verCima();
	bool esVacia();
};

#endif // PILAN_H