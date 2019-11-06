#include "Pila.h"
#include "PilaN.h"
#include <iostream>
using namespace std;

//Constructor de la Pila
Pila::Pila()
{
	cima = NULL;
    tamano = 0;
} 

Pila::~Pila()
{
	while(cima) desapilar();
}

//Métodos
void Pila::apilar(char c)//Meter elemento en la Pila
{
	pNodo nuevo; //Var aux para manipular el nuevo nodo
	nuevo = new Nodo(c, cima);//Se crea un nodo nuevo
	cima = nuevo;//El comienzo de la pila es el nuevo nodo
    tamano ++;
}

void Pila::desapilar()
{
	pNodo nodo; //Var aux para manipular el nodo
	char c; //Var aux para el retorno del valor del nodo
	if(!cima) return ; // Si no hay nodos en la pila se devuelve 0	
	nodo = cima;// Nodo apunta al primer elemento de la pila
	cima= nodo->siguiente;//Se asigna a pila toda la pila menos el primer elemento
	c = nodo->valor;//Se guarda el retorno del valor del nodo
	delete nodo;//Se borra el nodo
    tamano --;
}

void Pila::mostrar(){
	pNodo aux = cima;
	cout<<"PILA CHAR: ";
	while (aux)
	{
		cout << "..>" << aux->valor ;
		aux = aux->siguiente;
	}
	cout << endl;
}	

char Pila::verCima(){
	return cima->valor;
}

bool Pila::esVacia(){ 
	if(cima==NULL) 
		return true;
	else 
		return false;
}

int Pila::evaluarExpresionInfija(string str){
	
	//PRUEBA
	Pila pcar;
	PilaN pnum;
	char aux, operador;
	int var1, var2, suma;
	bool control=false;
	
	//cout << "LONGITUD STR: " << str.length() << "\n";
	//cout << "CADENA INTRODUCIDA: "<< str << ": \n";
	for (int i=0; i<str.length(); i++){ //str.size()
		aux=str[i];
		//cout << aux << "\n";
		switch(aux){
			case '(' :
				pcar.apilar(aux);
				control=false;
				break;
			case '/' :
				pcar.apilar(aux);
				control=false;
				break;
			case '+' :
				pcar.apilar(aux);
				control=false;
				break;
			case '*' :
				pcar.apilar(aux);
				control=false;
				break;
			case '-' :
				pcar.apilar(aux);
				control=false;
				break;
			case ')' :
				control=false;
				//cout << "PAR CERRADO, OPERACION: \n";
				var1 = pnum.verCima(); //Cogemos el primer valor
				//pnum.mostrar();
				//cout << "VAR1: " << var1 << "\n";
				pnum.desapilar();
				var2 = pnum.verCima();
				//pnum.mostrar();
				//cout << "VAR2: " << var2 << "\n";
				pnum.desapilar();
				operador = pcar.verCima();
				//pcar.mostrar();
				//cout << "OPERADOR: " << operador << "\n";
				pcar.desapilar();
				pcar.desapilar(); //Desapilamos par abierto
				switch(operador){
					case '*':
						suma=var2*var1;
						pnum.apilar(suma);
						//cout << "RESULTADO: " << suma << "\n";
						//pnum.mostrar();
						break;
					case '+':
						suma=var2+var1;
						pnum.apilar(suma);
						//cout << "RESULTADO: " << suma << "\n";
						//pnum.mostrar();
						break;
					case '-':
						suma=var2-var1;
						pnum.apilar(suma);
						//cout << "RESULTADO: " << suma << "\n";
						//pnum.mostrar();
						break;
					case '/':
						suma=var2/var1;
						pnum.apilar(suma);
						//cout << "RESULTADO: " << suma << "\n";
						//pnum.mostrar();
						break;
					default:
						//cout << "EL OPERADOR SE HA SALIDO POR DEFAULT";
						
						break;
				}
				break;
			default :
				if(control==true){
					int n3;
					n3=((pnum.verCima())*10)+aux-48;
					pnum.desapilar();
					pnum.apilar(n3);
				}else{
					pnum.apilar(aux-48); //Al transformar a int tenemos que restarle el codigo asci (48) para equivalencia con numeros
				}
				control=true; 
				break;
			}
	}//FIN DEL BUCLE FOR
	//cout << "PILA CAR: ";
	//pcar.mostrar();
	//cout << "PILA NUM: ";
	//pnum.mostrar();
	
	return pnum.verCima();
} //fin evaluarExpresionInfija();

int Pila:: evaluar_expresionInfija2(string expresion)
{
    bool inicio = false;
    int indice = 0;
    while (indice<expresion.size()){
        char c = expresion[indice];
        indice ++;
            if (c == ')'){
               sumaresta();
            }
            else if (!inicio || (c== '*') || (c== '/') || (c== '-') || (c== '+') || (c == '(')){
                apilar(c);
					if (c != '('){
						inicio = true;
					}else{
						inicio = false;
					}
				}else {
                char anterior = verCima();
                desapilar();
                //Hago la multiplicación o la divisón
                if (anterior == '*' || anterior == '/'){
                    int a = verCima()-'0';
                    desapilar();
                    int b = c -'0';
                    int resultado = operacion(a,b,anterior);
                    apilar(resultado + '0');
                //Hago la suma o la resta
                }else if (anterior == '+'|| anterior == '-'){
                    apilar(anterior);
                    apilar(c);
                //Si el siguiente caracter es un numero en string
                }/*else {
                    apilar(anterior+c);
                }*/
            }
        }
    sumaresta();
    return verCima()-'0';
}   

void Pila::sumaresta(){
    Pila paux;
    while (!esVacia() && verCima()!='('){
        paux.apilar(verCima());
        desapilar();
    }
    if (!esVacia()){
        desapilar();
    }
    while (paux.tamano > 1){
        int a = paux.verCima()-'0';
        paux.desapilar();
        char operador = paux.verCima();
        paux.desapilar();
        int b = paux.verCima()-'0';
        paux.desapilar();
        int resultado = operacion(a,b,operador);
        paux.apilar(resultado+'0');
    }
    char resultado = paux.verCima();
    paux.desapilar();
    apilar(resultado);
}


int Pila::tam(){
    return tamano;
}