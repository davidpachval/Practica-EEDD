#include <stdio.h>
#include <ArbolBinario.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{	
	char opcion;
    char expresion[40] = "";
	 do {
        //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        //SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t------------------------------------------------\n";
        cout << "\t                       MENU                       \n";
        cout << "\t------------------------------------------------\n";
        //SetConsoleTextAttribute(hConsole, 2);
        cout << "\n\tA. Evaluar una expresion infija. \n";
        cout << "\tB. Evaluar una expresion infija 2.\n";
        cout << "\tC. Expresion infija a expresion postfija.\n";
        cout << "\tD. Evaluar una expresion posfija.\n";
        cout << "\tE. Evaluar si una expresion infija es correcta.\n";
        cout << "\tF. Completar parentesis de una expresion infija.\n\n";
		cout << "\t-------> PL2 <------\n\n";
		cout << "\tG. Construir arbol binario con expresion infija postfija.\n";
		cout << "\tI. Construir arbol binario de busqueda.\n\n";
        //SetConsoleTextAttribute(hConsole, 7);
        cout << "\tS.Salir del programa.\n\n";
        cout << "\tIndique la opcion deseada: ";
        cin >> opcion;
        opcion = toupper(opcion);
        system("cls");

        switch(opcion) {
		case 'G': {
			
			cout << "\n\tIntroduzca una expresion (sin espacios): "; // ((2*5)-(1*2))/(11-9))
            cin >> expresion;
			ArbolBinario ab;
			string s = expresion;
			ab.construirArbolConColaInfija(s);
			ab.Inorden();
			ab.apartado_k();
			cout << endl;
            break;
		}
		case 'I':{
			ArbolBinario ab2;
			ab2.crear_abb();
			ab2.Inorden2();
			ab2.apartado_k();
			cout << endl;
            break;
		}	
        case 'S':
            cout << "\n\tSaliendo del programa...\n";
            break;
        default:
            cout << "\n\tOpcion incorrecta!\n\n";
            break;
        }
    } while(opcion != 'S');
    return 0;
}