#include "PilaN.h"
#include <iostream>
using namespace std;

PilaN::PilaN()
{
	cima = NULL;
}

PilaN::~PilaN()
{
		while(cima) desapilar();
}

//Métodos
void PilaN::apilar(int v)//Meter elemento en la Pila
{
	pNodon nuevo; //Var aux para manipular el nuevo nodo
	nuevo = new NodoN(v, cima);//Se crea un nodo nuevo
	cima = nuevo;//El comienzo de la pila es el nuevo nodo
}

void PilaN::desapilar()
{
	pNodon nodo; //Var aux para manipular el nodo
	int v; //Var aux para el retorno del valor del nodo
	if(!cima) return ; // Si no hay nodos en la pila se devuelve 0	
	nodo = cima;// Nodo apunta al primer elemento de la pila
	cima= nodo->siguiente;//Se asigna a pila toda la pila menos el primer elemento
	v = nodo->valor;//Se guarda el retorno del valor del nodo
	delete nodo;//Se borra el nodo
}

void PilaN::mostrar(){
	pNodon aux = cima;
	cout<<"PILA NUM: ";
	while (aux)
	{
		cout << "..>" << aux->valor ;
		aux = aux->siguiente;
	}
	cout << endl;
}	

int PilaN::verCima(){
	return cima->valor;
}

bool PilaN::esVacia(){ 
	if(cima==NULL) 
		return true;
	else 
		return false;
}