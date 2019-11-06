#include "NodoN.h"

NodoN::NodoN(int v, NodoN *sig)
{
	valor = v;
	siguiente = sig; 
}

NodoN::~NodoN()
{
}
