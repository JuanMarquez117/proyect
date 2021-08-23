//libreria matemáticas discretas
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string.h>

using namespace std;

void vMenuNumerosBinarios();
void vSumasSistemas(int);
bool vValidacionNumero(int,char &);


void vMenuNumerosBinarios(){
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"Teclee la opción que requiera: \n";
		cout<<"1. Sumas de números binarios.\n";
		cout<<"\n2. Regresar al menú anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vSumasSistemas(2); break;
			case 2: bSalir = true; break;
			default: cout<<"Esa opción no existe, ingrese un número del menú.\n";
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vSumasSistemas(int limite){
	int i,iCantidad;
	char cNum[3];
	char **cNumero;
	fflush(stdin);
	cout<<"Teclee la cantidad de números a sumar: ";cin>>iCantidad;
	cNumero = (char**)malloc(iCantidad*sizeof(char*));
	for(i = 0;i<iCantidad;i++){
		cNumero[i] = (char*)malloc(sizeof(char));
		while(true){                      //valida los números de acuerdo al sistema numérico
			cout<<"Teclee el numero: "; cin>>cNum;
			if(vValidacionNumero(limite,&cNum[0])==true){
//				iNumero.push_back(iNum);  //introduce el numero validado en el sistema a utilizar en un vector
				break;
			}
			else{
				cout<<"INTRODUZCA UN NÚMERO CON BASE "<<limite<<".\n";
			}
		}
	}
}

bool vValidacionNumero(int limite,char numero){
	bool bValido = false;
	int iNum = atoi(numero);
//	while(bValido==false){
	while(true){
		if(iNum%10>=limite){
			return false;
			break;
		}
		else{
			iNum /= 10;
			if(iNum==0){
				return true;
				break;
			}
		}
	}
}
