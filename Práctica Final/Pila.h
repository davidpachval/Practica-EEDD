#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
class Pila
{
private:
	pNodo cima;
    int tamano;
    private:
    int operacion(int a, int b, char signo)
    {
        if (signo == '+')
        {
            return a + b;
        } else if (signo == '-')
        {
            return a - b;
        } else if (signo == '*'){
            return a * b;
        } else{
            return a/b;
        }
    }
    void sumaresta ();
public:
	Pila();
	~Pila();
	void apilar(char c);
	void desapilar();
	void mostrar();
	char verCima();
	bool esVacia();
	int evaluarExpresionInfija(string str);
    int evaluar_expresionInfija2(string str);
    int tam();
};

#endif // PILA_H