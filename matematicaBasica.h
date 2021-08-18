/*MATEMATICAS BÁSICAS*/
#include<iostream>
using namespace std;
#include<locale.h>
#include<stdlib.h>
#include<cmath>

void vHipotenusaPitagoras();
void vCatetoPitagoras();

void vSuma(){
	setlocale(LC_ALL,"");
	float fSuma = 0;
	float fNumero = 0; 
	int iLongitud = 0;
	cout<<"Teclee la cantidad de numeros a sumar:\n";cin>>iLongitud;
	cout<<"Teclee los números: \n";
	for(int i = 0;i<iLongitud;i++){
		cin>>fNumero;
		fSuma += fNumero;
	}
	cout<<"El total de la suma es: "<<fSuma<<"\n";
}

void vComparacionNumero(){
	float fNum1 = 0;
	float fNum2 = 0;
	cout<<"Teclee el primer número: ";cin>>fNum1;
	cout<<"Teclee el segundo número: ";cin>>fNum2;
	if(fNum1>fNum2){
		cout<<"El número "<<fNum1<<" es mayor que "<<fNum2<<" por "<<fNum1-fNum2<<" unidades.\n";
	}
	else if(fNum1<fNum2){
		cout<<"El número "<<fNum2<<" es mayor que "<<fNum1<<" por "<<fNum2-fNum1<<" unidades.\n";
	}
	else{	
	cout<<"Los números son iguales.\n";
	}
}

void vAreaRectangulo(){
	float fBase,fAltura;
	cout<<"Teclee la base: ";cin>>fBase;
	cout<<"Teclee la altura: ";cin>>fAltura;
	cout<<"El área de la figura es: "<<fBase*fAltura<<" unidades.\n";
}

void vMultiplicacion(){
	float fMultiplicacion = 1;
	float fNumero = 0; 
	int iLongitud = 0;
	cout<<"Teclee la cantidad de numeros a multiplicar:\n";cin>>iLongitud;
	cout<<"Teclee los números: \n";
	for(int i = 0;i<iLongitud;i++){
		cin>>fNumero;
		fMultiplicacion *= fNumero;
	}
	cout<<"El total de la multiplicación es: "<<fMultiplicacion<<"\n";
}

void vDivision(){
	float fDivision = 0;
	float fNumero = 0; 
	int iLongitud = 0;
	cout<<"Teclee la cantidad de numeros a dividir:\n";cin>>iLongitud;
	cout<<"Teclee los números: \n";
	for(int i = 0;i<iLongitud;i++){
		cin>>fNumero;
		if(fNumero<=0){
			cout<<"La división no se puede efectuar. El número "<<fNumero<<" no se puede dividir.\n";
			break;
		}
		if(fDivision==0){
			fDivision = fNumero;
		}
		else{
			fDivision /= fNumero;
		}
	}
	cout<<"El total de la división es: "<<fDivision<<"\n";
}

void vPorcentajeReglaTres(){
	float fTotal = 0,fCantidad = 0,fPorcentaje = 0;
	cout<<"Teclee el total de las unidades: ";cin>>fTotal;
	cout<<"Teclee la cantidad que requiere convertir en porcentaje: ";cin>>fCantidad;
	fPorcentaje = (100/fTotal)*fCantidad;
	cout<<"El porcentaje correspondiente es: "<<fPorcentaje<<" %.\n";
}

void vTeoremaPitagoras(){
	bool bSalir = false;
	int iOpcion = 0;
	char cOpcion[2];
	do{
		system("cls");
		cout<<"Teclee la opción que requiere: \n";
		cout<<"1. Obtener la hipotenusa a partir de los catetos.\n";
		cout<<"2. Obtener el cateto opuesto a partir de la hipotenusa y el cateto adyacente.\n";
		cout<<"\n3. Regresar al menú anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vHipotenusaPitagoras(); break;
			case 2: vCatetoPitagoras(); break;
			case 3: bSalir = true; break;
			default: cout<<"Esa opción no existe.\n"; break;
		}
		system("pause");
	}while(bSalir==false);
}

void vHipotenusaPitagoras(){
	float fCatetoOpuesto = 0,fCatetoAdyacente = 0;
	cout<<"Teclee la longitud de ambos catetos: ";cin>>fCatetoOpuesto>>fCatetoAdyacente;
	float hipotenusa = sqrt((pow(fCatetoOpuesto,2))+(pow(fCatetoAdyacente,2)));
	cout<<"La hipotenusa resultante es: "<<hipotenusa<<" unidades.\n";
}

void vCatetoPitagoras(){
	float fCateto = 0,fHipotenusa = 0;
	cout<<"Teclee la longitud del cateto: ";cin>>fCateto;
	cout<<" teclee la longitud de la hipotenusa: ";cin>>fHipotenusa;
	float fCatetoResultante = sqrt((pow(fHipotenusa,2))-(pow(fCateto,2)));
	cout<<"El cateto resultante es: "<<fCatetoResultante<<" unidades.\n";
}

void vAreaTrapecio(){
	float fBaseMayor = 0,fBaseMenor = 0, fAltura = 0;
	cout<<"Teclee la longitud de la base mayor: ";cin>>fBaseMayor;
	cout<<"Teclee la longitud de la base menor: ";cin>>fBaseMenor;
	cout<<"Teclee la longitud de la altura: ";cin>>fAltura;
	float fArea = ((fBaseMayor+fBaseMenor)*fAltura)/2;
	cout<<"El área del trapecio es: "<<fArea<<" unidades cuadradas.\n";
}

void vFactorizacion(){
	/*
	bool bSalir = false;
	int iNumero = 0;
	int i = 1;
	cout<<"Teclee el número a factorizar: ";cin>>iNumero;
	while(i<iNumero){
		iNumero /= i;
		if(i==1){
			continue;
		}
	}*/
}

