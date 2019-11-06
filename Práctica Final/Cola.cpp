#include "Cola.h"
//#include "ColaN.h"
#include <Pila.h>
#include <PilaN.h>
#include <iostream>
using namespace std;

Cola::Cola()
{
	primero=NULL;
	ultimo=NULL;
}

Cola::~Cola()
{
	while(primero){
		desencolar();
	}
}

void Cola::encolar(char c){
	pNodo nuevo;
	nuevo = new Nodo(c);
	if (ultimo)
		ultimo->siguiente=nuevo;
	ultimo=nuevo;
	if (!primero)
		primero = nuevo;
}

void Cola::desencolar(){
	pNodo nodo;
	nodo = primero;
	primero = nodo->siguiente;
	delete nodo;
	if (!primero)
		ultimo=NULL;
}

char Cola::verPrimero(){
	pNodo nodo = primero;
	return char(nodo->valor);
}
void Cola::mostrar(){
	pNodo aux = primero;
	cout << "Cola: ";
	while (aux){
		cout << " ..> " << aux->valor;
		aux = aux->siguiente;
	}
	cout << endl;
}

bool Cola::esVacia(){ 
	if(primero==NULL) 
		return true;
	else 
		return false;
}


void Cola::expresionInfijaAExpresionPostfija(string strc){
	Pila pcar;
	char aux;
	
	for(int i=0; i<strc.length();i++){
		aux = strc[i];
		//cout<<"VALOR: " << aux <<"\n";
		switch(aux){
			case '(' :
				pcar.apilar(aux);
				//cout << "-ALMACENA\n";
				break;
			case ')' :
                while (pcar.verCima() != '(') {
                    char elemento = pcar.verCima();
                    pcar.desapilar();
                    // TODO encolar sobre esta cola, no aux
                    //caux.encolar(elemento);}
                    encolar(elemento);
                }
                pcar.desapilar();
                break;               
				//cout << "--INICIA EL ALGORITMO: \n";
				/*if(cnum.esVacia()){
					//cout << "1. COLA DE NUMEROS VACIA EN PAR CERRADO";
					caux.encolar(pcar.verCima());
					pcar.desapilar();
				} else{
					//cout << "2. COLA CON NUMEROS EN PAR CERRADO";
					while(!cnum.esVacia()){
						caux.encolar(cnum.verPrimero()+48); //añadimos a la cola final nuestro numero
						cnum.desencolar(); //desencolamos el numero de cnum
					}
					caux.encolar(pcar.verCima()); //añadimos el operador a la cola final
					pcar.desapilar(); //desapilamos el operador
				}
				pcar.desapilar(); //Desapilamos el parentesis abierto
				//SI HAY DOS NUMEROS EN LA COLA
				break;*/
			case '/' :
				pcar.apilar(aux);
				//cout << "-ALMACENA\n";
				break;
			case '+' :
				pcar.apilar(aux);
				//cout << "-ALMACENA\n";
				break;
			case '*' :
				pcar.apilar(aux);
				//cout << "-ALMACENA\n";
				break;
			case '-' :
				pcar.apilar(aux);
				//cout << "-ALMACENA\n";
				break;
			default : //vamos a tratar en default el que aparezca un caracter numérico
                // TODO encolar sobre esta cola, no aux
				//caux.encolar(aux); //Añadimos el numero a la cola 
                encolar(aux); //Añadimos el numero a la cola 
				//cout << "-ALMACENA NUMERO\n";
				break;
		}//FIN SWITCH
		//MOSTRAR LAS DOS COLAS
		//cout << "--PILA DE OPERADORES: ";
		//pcar.mostrar();
		//cout << "COLA DE NUMEROS: ";
		//cnum.mostrar();
		//cout << "COLA FINAL A DEVOLVER: ";
		//caux.mostrar();
	} //FIN FOR
    // TODO ahora es void, no hay return
    //return caux;
}


int Cola::evaluar_expresionPosfija(){
    PilaN pilaaux;
    while (! esVacia()){
        char c = verPrimero();
        desencolar();
        if (c == '/' || c== '*' || c =='+' || c == '-' ){
           int numero2 = pilaaux.verCima();
           pilaaux.desapilar();
           int numero1 = pilaaux.verCima();
           pilaaux.desapilar();
           int resultado;
           if (c == '/'){
               resultado = numero1 / numero2;
           }else if (c == '*'){
                resultado = numero1 * numero2;
           }else if (c == '+'){
                resultado = numero1 + numero2;
           }else
                resultado = numero1 - numero2;
            pilaaux.apilar(resultado);
        }else
            pilaaux.apilar(c-'0');
        }
int resultado = pilaaux.verCima();
return resultado;
}

void Cola::transformar(string s){
	for(int i=0;i<s.length();i++){
		encolar(s[i]);
	}
}

string Cola::leerCola(){
	string s;
	pNodo aux = primero;
	while (aux){
		s = s+  aux->valor;
		aux = aux->siguiente;
	}
	return s;
}