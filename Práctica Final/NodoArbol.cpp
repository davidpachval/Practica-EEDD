#include "NodoArbol.h"

NodoArbol::NodoArbol(char val, NodoArbol *izq, NodoArbol *der){
	valor = val;
	izquierda = izq;
	derecha = der;
}

NodoArbol::~NodoArbol()
{
}

NodoArbol *NodoArbol::dcha(){ //Tipo, clase función
    return derecha;
}
NodoArbol *NodoArbol::izq(){
    return izquierda;
}