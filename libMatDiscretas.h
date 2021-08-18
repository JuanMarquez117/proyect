//libreria matem�ticas discretas
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
		cout<<"Teclee la opci�n que requiera: \n";
		cout<<"1. Sumas de n�meros binarios.\n";
		cout<<"\n2. Regresar al men� anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vSumasSistemas(2); break;
			case 2: bSalir = true; break;
			default: cout<<"Esa opci�n no existe, ingrese un n�mero del men�.\n";
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
	cout<<"Teclee la cantidad de n�meros a sumar: ";cin>>iCantidad;
	cNumero = (char**)malloc(iCantidad*sizeof(char*));
	for(i = 0;i<iCantidad;i++){
		cNumero[i] = (char*)malloc(sizeof(char));
		while(true){                      //valida los n�meros de acuerdo al sistema num�rico
			cout<<"Teclee el numero: "; cin>>cNum;
			if(vValidacionNumero(limite,&cNum[0])==true){
//				iNumero.push_back(iNum);  //introduce el numero validado en el sistema a utilizar en un vector
				break;
			}
			else{
				cout<<"INTRODUZCA UN N�MERO CON BASE "<<limite<<".\n";
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
