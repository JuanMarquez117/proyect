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
		cout<<"\t\t\t\t\t\tMatem�tica B�sica.\n";
		cout<<"Teclee la opci�n que necesita:\n";
		cout<<"1. Suma de numeros.\n";
		cout<<"2. Comparaci�n de n�meros.\n";
		cout<<"3. �rea de un cuadrado-rectangulo.\n";
		cout<<"4. Multiplicaci�n de dos n�meros.\n";
		cout<<"5. Divisi�n de dos n�meros.\n";
		cout<<"6. Obtener porcentaje. (Regla de tres)\n";
		cout<<"7. Teorema de pitagoras.\n";
		cout<<"8. �rea de un trapecio.\n";
		cout<<"9. Factorizaci�n de un n�mero.\n";
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
				cout<<"Opci�n Invalida, Intente de nuevo.\n\n";
				break;
		}
		system("pause");
	}while(iOpcion!=0);
}
