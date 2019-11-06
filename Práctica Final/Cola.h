#ifndef COLA_H
#define COLA_H
#include "Nodo.h"
class Cola
{
private:
	pNodo primero, ultimo;
public:
	Cola();
	~Cola();
	void encolar(char c);
	void desencolar(); //nos devuelve un valor,es el que ha borrado
	char verPrimero();
	void mostrar();
	bool esVacia();
	char segundoElemento(Cola c);
	void transformar(string s);
    // TODO hacer void para devolver el resultado en esta misma cola
    //Cola expresionInfijaAExpresionPostfija(string str);
	void expresionInfijaAExpresionPostfija(string str);
    int evaluar_expresionPosfija();
	string leerCola();
};

#endif // COLA_H