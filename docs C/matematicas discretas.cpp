//MATEMÁTICAS DISCRETAS
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
		cout<<"\t\t\t\t\t\tMatemáticas Discretas.\n\n";
		cout<<"Teclee la opción que requiera: \n";
		cout<<"1. Operaciones con números binarios.\n";
		cout<<"\n2. Salir.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vMenuNumerosBinarios(); break;
			case 2: bSalir = true; break;
			default: cout<<"Esa opción no existe, ingrese un número del menú.\n";
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}
