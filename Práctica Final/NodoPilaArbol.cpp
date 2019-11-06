#include "NodoPilaArbol.h"

NodoPilaArbol::NodoPilaArbol(NodoArbol n, NodoPilaArbol *sig)
{
	nodo = n;
	siguiente = sig;
	
}

NodoPilaArbol::~NodoPilaArbol()
{
}

