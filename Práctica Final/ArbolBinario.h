#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <NodoArbol.h>
#include <Cola.h>
#include <string>
#include <string.h>

class ArbolBinario
{
private:
	pNodoArbol raiz = NULL;
	pNodoArbol actual = NULL;
	int altura;
	void podarNodo(pNodoArbol &nodo);	
public:
	ArbolBinario();
	~ArbolBinario();

	//GENERADORA
	pNodoArbol unirArbol(pNodoArbol pi, char c, pNodoArbol pr);
	
	//MODIFICADORA
	//void setRaiz(char c);
	void setIzquierda(pNodoArbol p); //recibe un nodo y lo inserta en la izquierda
	void setDerecha(pNodoArbol p);//recibe un nodo y lo inserta en la derecha
	
	//OBSERVADORAS
	bool esVacio(pNodoArbol a);
	//char verRaiz(ArbolBinario a);
	
	//EXTRAS
	void insertarRaiz(int r);
	void setDerechaValor(char c);
	void setIzquierdaValor(char c);
	bool esOperador(char c);

	
	//PRACTICA 2
	void crear_abb();
	void insertar_abb(pNodoArbol &p, int n);
	void construirArbolConColaInfija(string s);
	void construirArbolConColaInfija2(string s);
	void Inorden();
	void Inorden2();
	string lecturaInorden(pNodoArbol p);
	string lecturaInordenConParentesis(pNodoArbol p);
	int Altura (pNodoArbol a);
	int Hojas (pNodoArbol a);
	int Nnodos (pNodoArbol a);
	int Nnodosinterno (pNodoArbol a);
	bool esta_lleno (pNodoArbol a);
	void apartado_k();

};

#endif // ARBOLBINARIO_H
