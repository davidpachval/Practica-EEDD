#include "PilaArbol.h"

PilaArbol::PilaArbol()
{
	cima = NULL;
}

PilaArbol::~PilaArbol()
{
}

void PilaArbol::apilar(NodoArbol p){
	pNodoPilaArbol n;
	n = new NodoPilaArbol(p, cima);
	cima=n;
}
void PilaArbol::desapilar(){
	pNodoPilaArbol nodo;
	
	NodoArbol c; //Var aux para el retorno del valor del nodo
	if(!cima) return ; // Si no hay nodos en la pila se devuelve 0	
	nodo = cima;// Nodo apunta al primer elemento de la pila
	cima= nodo->siguiente;//Se asigna a pila toda la pila menos el primer elemento
	c = nodo->nodo;//Se guarda el retorno del valor del nodo
	delete nodo;//Se borra el nodo
}

bool PilaArbol::esVacia(){ 
	if(cima==NULL) 
		return true;
	else 
		return false;
}
NodoArbol PilaArbol::verCima(){
	return cima->nodo;
}