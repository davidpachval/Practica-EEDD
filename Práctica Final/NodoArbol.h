#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <conio.h>
#include <iostream>
using namespace std;

class NodoArbol
{
private: 
	char valor; //El raiz
	NodoArbol *izquierda;
	NodoArbol *derecha;	
	friend class ArbolBinario;
public:
	friend class Lista;
	NodoArbol(char val=0, NodoArbol *izq = NULL, NodoArbol *der = NULL);
	~NodoArbol();
	NodoArbol* izq(); //Funciones accedentes
    NodoArbol* dcha();
};
typedef NodoArbol *pNodoArbol;

#endif // NODOARBOL_H
