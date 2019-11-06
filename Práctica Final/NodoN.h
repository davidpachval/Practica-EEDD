#ifndef NODON_H
#define NODON_H
#include <iostream>
using namespace std;

class NodoN
{
private:
	int valor;
	NodoN *siguiente;

public:
    friend class PilaN; 
    friend class ColaN;
	NodoN(int v, NodoN *sig = NULL);
	~NodoN();

};

typedef NodoN *pNodon; 

#endif // NODON_H