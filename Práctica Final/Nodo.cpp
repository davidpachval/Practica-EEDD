#include "Nodo.h"

Nodo::Nodo(char v, Nodo *sig)
{
	valor = v;
	siguiente = sig; 
}

Nodo::~Nodo()
{
}
