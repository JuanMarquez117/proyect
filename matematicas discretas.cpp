//MATEM�TICAS DISCRETAS
#include<iostream>
#include<locale.h>
#include<stdlib.h>
#include"libMatDiscretas.h"

using namespace std;

void vMenu();

int main(void){
	setlocale(LC_ALL,"");
	vMenu();
	return 0;
}

void vMenu(){
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"\t\t\t\t\t\tMatem�ticas Discretas.\n\n";
		cout<<"Teclee la opci�n que requiera: \n";
		cout<<"1. Operaciones con n�meros binarios.\n";
		cout<<"\n2. Salir.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vMenuNumerosBinarios(); break;
			case 2: bSalir = true; break;
			default: cout<<"Esa opci�n no existe, ingrese un n�mero del men�.\n";
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}
