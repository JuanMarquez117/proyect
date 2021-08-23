#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<cString>
#include<locale.h>
#include"libQuimica.h"
using namespace std;

//prototipos de funcion.
void vMenuQuimica();

//void menuConversiones();

int main(void){
	setlocale(LC_ALL,"");
	vMenuQuimica();
}

//funciones.
void vMenuQuimica(){
	char cOpcion[2];
	int iOpcion = 0;
	int opc=0;
	bool bSalir = false;
	do{
		system("cls");
		cout<<"\t\t\t\t\t\tQuímica\n";
		cout<<"Teclee la opcion que necesita calcular: \n\n";
		cout<<"1. Longitud de onda (lambda) a partir de la frecuencia.\n";
		cout<<"2. Longitud de onda (lambda) a partir de la masa(Kg) y velocidad(m/s).";
		cout<<" (De Broglie)\n";
		cout<<"3. Frecuencia de la onda (V) a partir de la longitud de onda.\n";
		cout<<"4. Velocidad de desplazamimento de la onda (C).\n";
		//cout<<"5. Tiempo (t).\n";
		cout<<"6. Energia en cantidad de cuantos (J) a partir de la frecuencia.\n";
		cout<<"7. Frecuencia minima para expulsion de electrones (v).\n";
		cout<<"8. Energia cinetica de electrones expulsados (EC).\n";
		//cout<<"9. Energia de la funcion de trabajo.\n";
		cout<<"10. Diferencia de energia entre dos estados cuanticos por transferencia de ";
		cout<<"electrones.\n";
		//cout<<"11. Obtencion del nivel inicial de energia de estado cuantico.\n";
		cout<<"12. Longitud de onda a partir de la energia del foton (J).\n";
		cout<<"13. Incertidumbre en la posicion de una particula (principio de incertidumbre).\n";
		cout<<"14. Incertidumbre en la velocidad de una particula (principio de incertidumbre).\n";
		cout<<"15. Configuraciones electronicas (afbau).\n";
		cout<<"16. Carga nuclear efectiva.\n";
		cout<<"17. Ley Boyle-Mariott.\n";
		cout<<"18. Ley de Charles.\n";
		cout<<"19. Molaridad y número de Avogadro.\n";
		cout<<"20. Conversiones de medidas.\n";
		cout<<"\n21. Salir.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: sacarLambdaFrec(); break;
			case 2: sacarLambdaMasaVel(); break;
			case 3: sacarFrecuencia(); break;
			case 4: sacarVelocidad(); break;
//			case 5: sacarTiempo(); break;
			case 6: sacarJoules(); break;
			case 7: sacarFrecuenciaTrabajo(); break;
			case 8: sacarEnergiaCinetica(); break;
//			case 9: sacarFuncionDeTrabajo(); break;
			case 10: sacarDiferenciaDeEnergia(); break;
//			case 11: sacarNivelInicialDeEnergia(); break;
			case 12: sacarLambdaJoules(); break;
			case 13: sacarIncertidumbrePosicion(); break;
			case 14: sacarIncertidumbreVelocidad(); break;
			case 15: configuracionElectronica(); break;
			case 16: sacarCargaNuclearEfectiva(); break;
			case 17: vMenuLeyBoyleMariotte(); break;
			case 18: vMenuLeyCharles(); break;
			case 19: vMenuMol(); break;
			case 20: vMenuConversiones(); break;
			case 21: bSalir = true; break;
			default: cout<<"No existe esa opcion.\n\n\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

