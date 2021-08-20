//matematicas basicas
#include<iostream>
using namespace std;
#include<locale.h>
#include<stdlib.h>
#include"matematicaBasica.h"

//pritotipos de funciones.
void vMenu();

//variables globales.
bool bValido = false;

int main(void){
	setlocale(LC_ALL,"");
	vMenu();
}

//funciones
void vMenu(){
	bool bSalir = false;
	int iOpcion = 0;
	char cOpcion[2];
	do{
		system("cls");
		cout<<"\t\t\t\t\t\tMatemática Básica.\n";
		cout<<"Teclee la opción que necesita:\n";
		cout<<"1. Suma de numeros.\n";
		cout<<"2. Comparación de números.\n";
		cout<<"3. Área de un cuadrado-rectangulo.\n";
		cout<<"4. Multiplicación de dos números.\n";
		cout<<"5. División de dos números.\n";
		cout<<"6. Obtener porcentaje. (Regla de tres)\n";
		cout<<"7. Teorema de pitagoras.\n";
		cout<<"8. Área de un trapecio.\n";
		cout<<"9. Factorización de un número.\n";
		cout<<"\n0. Salir.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vSuma(); break;
			case 2: vComparacionNumero(); break;
			case 3: vAreaRectangulo(); break;
			case 4: vMultiplicacion(); break;
			case 5: vDivision(); break;
			case 6: vPorcentajeReglaTres(); break;
			case 7: vTeoremaPitagoras(); break;
			case 8: vAreaTrapecio(); break;
			case 9: vFactorizacion(); break;
			case 0: bSalir = true; break;
			default:
				cout<<"Opción Invalida, Intente de nuevo.\n\n";
				break;
		}
		system("pause");
	}while(iOpcion!=0);
}
