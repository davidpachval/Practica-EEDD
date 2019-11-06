#include "ArbolBinario.h"
#include "NodoArbol.h"
#include "Pila.h"
#include "PilaArbol.h"
#include "Cola.h"
#include <iostream>
using namespace std;
#include <stdio.h>
#include <cmath>

ArbolBinario::ArbolBinario()
{
	raiz = NULL;
	actual = NULL;
}

ArbolBinario::~ArbolBinario()
{
}

pNodoArbol ArbolBinario::unirArbol(pNodoArbol pi, char c, pNodoArbol pr){
	pNodoArbol p = new NodoArbol(c);
	raiz = p;
	setIzquierda(pi);
	setDerecha(pr);
}

void ArbolBinario::setIzquierda(pNodoArbol p){
	raiz->izquierda = p;
}

void ArbolBinario::setDerecha(pNodoArbol p){
	raiz->derecha = p;
}

void ArbolBinario::setIzquierdaValor(char c){ //PRUEBAS
cout <<"1 RAIZ: "<< raiz->valor;
	pNodoArbol p;
	p->valor = c;
	raiz->izquierda = p;
	cout <<"2 RAIZ: "<< raiz->valor;
}

void ArbolBinario::setDerechaValor(char c){ //PRUEBAS
	cout <<"3 RAIZ: "<< raiz->valor;
	pNodoArbol p = new NodoArbol(c);
	cout <<"valor nodo: "<< p->valor;
	raiz->derecha = p;
	cout <<"4 RAIZ: "<< raiz->valor;
}

bool ArbolBinario::esOperador(char c){
	if((c=='*') || (c=='+') || (c=='/') || (c=='-')){//Si es operador
		return true;
	}
	else
		return false;
}

void ArbolBinario::Inorden(){
	cout << "LA LECTURA EN INORDEN CON PARENTESIS ES:";
	cout << lecturaInordenConParentesis(raiz) <<"\n";
	
}

void ArbolBinario::Inorden2(){
	cout << "LA LECTURA EN INORDEN ES:";
	cout << lecturaInorden(raiz) <<"\n";
}

string ArbolBinario::lecturaInordenConParentesis(pNodoArbol p){
	if (p==NULL){ //si el nodo está vacio devuelve espacio en blanco
		return "";
	} else{ //si el nodo contiene algún valor
		if (esOperador(p->valor)){
			string v;
			v = p->valor;
			return "("+lecturaInordenConParentesis(p->izquierda)+v+lecturaInordenConParentesis(p->derecha)+")";
		} else{
			string v;
			v = p->valor;
			return v;
		}
	}
}

string ArbolBinario::lecturaInorden(pNodoArbol p){
	if (p==NULL){ //si el nodo está vacio devuelve espacio en blanco
		return "";
	} else{ //si el nodo contiene algún valor
		string a,b,c,d;
		a = "";
		c = "";
		b = p->valor;
		a = lecturaInorden(p->izquierda);
		c = lecturaInorden(p->derecha);
		d = a+b+c;
		return d;
	}
}

void ArbolBinario::construirArbolConColaInfija(string s){ //APARTADO G
	Cola c;
	c.expresionInfijaAExpresionPostfija(s);
	s = c.leerCola();
	cout << "EXPRESION POSTFIJA: "<< s << "\n";
	
	//TENEMOS STRING POSTFIJO
	pNodoArbol paux1, paux2, panterior;
	panterior = new NodoArbol('A');
	raiz=NULL;
	int contnum = 0;
	char e;
	for (int i=0; i<s.length();i++){ //RECORRER EL STRING HASTA QUE NO HAYA ELEMENTOS
		e = s[i];
		if((e=='*') || (e=='+') || (e=='/') || (e=='-')){//Si es operador
			if (paux1 && paux2){//SI, HAY DOS NUMEROS GUARDADOS SIN LINKEAR //esto pasa al principio
				if(raiz){
					panterior = new NodoArbol(e,paux1,paux2);
				}
				else{
					raiz = unirArbol(paux1, e, paux2);
				}
			}else{
				if(paux1){ //SI SOLO TENEMOS UN NUMERO Y NOS HA LLEGADO EL OPERADOR
					raiz = unirArbol(raiz,e,paux1);
				}else{
					raiz = unirArbol(raiz, e, panterior);
				}
			}
        
			paux1 = NULL;
			paux2 = NULL;
			contnum = 0;
		}   else{ //Si es numero, se guarda simplemente en paux1  y paux2 dependiendo de si llegan 1 o 2
			if(contnum == 1){ //Si hay numero antes
				paux2 = new NodoArbol(e);
				contnum++;
			}else{ //Si no ha habido numero antes
				paux1 =  new NodoArbol(e);
				contnum++;
			}
		}
	}
	cout << endl;
}

void ArbolBinario::crear_abb(){
	string s;
	s = "";
	do{
		cout << "INTRODUCE UNA EXPRESION (T para terminar): \n";
		cin >> s;
		Pila p;
		int a;
		a = p.evaluarExpresionInfija(s);
		
		//insertamos en el arbol
		if (s!="T"){
			insertar_abb(raiz, a);
		}
	} while (s!="T");
}

void ArbolBinario::insertar_abb(pNodoArbol &p, int n){
	pNodoArbol paux = new NodoArbol(n+48);
	if (p==NULL){
		p = paux;
		cout << "HA INSERTADO EN EL ARBOL BINARIO NUMERO : "<<n<<"\n";
	}else{
		int m = (p->valor)-48;
		if ( n > m ){ //INSERTO POR LADERECHA
			insertar_abb(p->derecha, n);
		} else{ //INSETRO POR LA IZQUIERDA
			insertar_abb(p->izquierda, n);
		}
	}
}


int ArbolBinario::Altura (pNodoArbol a){
    if (a == NULL){
        return 0;
    }else{
        int alturaizq = Altura(a->izq()); //Fecha porque es puntero
        int alturadcha = Altura(a->dcha());
        if (alturaizq > alturadcha ){
            return alturaizq + 1;
        }else{
            return alturadcha + 1;
        }
    }
}

int ArbolBinario::Hojas (pNodoArbol a){
    if (a == NULL){
        return 0;
    }else{
        if(a->dcha() == NULL && a->izq() == NULL){
            return 1;
        }else{
            return Hojas(a->dcha()) + Hojas(a->izq()); //Pido las hojas primero del hijo derecho luego las del hijo izquierdo y las sumo
        }
    }
}

int ArbolBinario::Nnodos (pNodoArbol a){
    if (a == NULL){
        return 0;
    }else{
        return 1 + Nnodos(a->dcha()) + Nnodos (a->izq());
    }
}

int ArbolBinario::Nnodosinterno (pNodoArbol a){
    return Nnodos(a) - Hojas(a);
}

bool ArbolBinario::esta_lleno (pNodoArbol a){
    if (Nnodos(a) == pow(2, Altura(a)-1 )){
        return true;
    }else{
        return false;
    }   
}
void ArbolBinario::apartado_k(){
	cout << "ALTURA: " << Altura(raiz)-1 << "\n";
	cout << "HOJAS: " << Hojas(raiz) << "\n";
	cout << "NUMERO DE NODOS: " << Nnodos(raiz) << "\n";
	cout << "NUMERO DE NODOS INTERNOS: " << Nnodosinterno(raiz) << "\n";
	if (esta_lleno(raiz)){
		cout << "ESTA LLENO: SI \n";
	}else{
		cout << "ESTA LLENO: NO \n";
	}
	

}
/*
void ArbolBinario::construirArbolConColaInfija2(string s){
	Cola c;
	PilaArbol p;
	c.expresionInfijaAExpresionPostfija(s);
	s = c.leerCola();
	cout << "EXPRESION POSTFIJA: "<< s << "\n";
	
	//TENEMOS STRING POSTFIJO
	pNodoArbol pauxizq, pauxder, paux;
	raiz=NULL;
	int contnum = 0;
	char e;
	for (int i=0; i<s.length();i++){ //RECORRER EL STRING HASTA QUE NO HAYA ELEMENTOS
		e = s[i];
		if (esOperador(e)){
			if (pauxizq && pauxder){
				paux = unirArbol(pauxizq, e, pauxder);
				p.apilar(paux);
			}else{
				pauxder = p.verCima();
				p.desapilar();
				pauxizq = p.verCima();
				p.desapilar();
				paux = unirArbol(pauxizq, e, pauxder);
				p.apilar(paux);
			}
			contnum = 0;
		}else{
			if(contnum == 1){ //Si hay numero antes
				pauxizq = new NodoArbol(e);
				contnum++;
			}else{ //Si no ha habido numero antes
				pauxder =  new NodoArbol(e);
				contnum++;
			}
		}
	}
	raiz = p.verCima();
}
*/