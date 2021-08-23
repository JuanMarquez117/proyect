#include<iostream>
#include<cmath>
#include"libConversiones.h"

using namespace std;

//prototipos de funcion
void vMenuMRU(); //Movimiento Rectilineo Uniforme 
void vMenuMRUV(); //Movimiento Rectilineo Uniformemente Variado 
void vMenuCaidaLibre();
void vMRUVelocidad();  //Movimiento Rectilineo Uniforme
void vMRUDistancia();  //Movimiento Rectilineo Uniforme
void vMRUTiempo();  //Movimiento Rectilineo Uniforme
void vMRUVVelocidadFinalTiempo(); //Movimiento Rectilineo Uniformemente Variado
void vMRUVVelocidadFinalDistancia(); //Movimiento Rectilineo Uniformemente Variado
void vMRUVDistanciaAceleracion();  //Movimiento Rectilineo Uniformemente Variado
void vMRUVDistanciaVelocidadFinal();  //Movimiento Rectilineo Uniformemente Variado
void vMRUVVelocidadPromedio(); //Movimiento Rectilineo Uniformemente Variado
void vMRUVAceleracionDistancia();  //Movimiento Rectilineo Uniformemente Variado
void vMRUVAceleracionTiempo();  //Movimiento Rectilineo Uniformemente Variado
void vMRUVTiempoAceleracion(); //Movimiento Rectilineo Uniformemente Variado
void vMRUVTiempoDistancia(); //Movimiento Rectilineo Uniformemente Variado
void vMRUVVelocidadFinalVelocidadPromedio(); //Movimiento Rectilineo Uniformemente Variado
void vMRUVVelocidadInicialVelocidadFinal(); //Movimiento Rectilineo Uniformemente Variado
void vMRUVVelocidadFinalDistanciaAceleracion(); //Movimiento Rectilineo Uniformemente Variado
void vMRCLAlturaCaidaLibre(); //Movimiento Rectilineo de Caida Libre
void vMRCLVelocidadCaidaTiempo(); //Movimiento Rectilineo de Caida Libre
void vMRCLVelocidadCaidaDistancia(); //Movimiento Rectilineo de Caida Libre
void vMRCLTiempoCaidaLibre(); //Movimiento Rectilineo de Caida Libre
void vMRCLTiempoSubidaVelocidadInicial(); //Movimiento Rectilineo de Caida Libre
void vMRCLAlturaMaximaVelocidadInicial();  //Movimiento Rectilineo de Caida Libre

//variables globales
float fVelocidad = 0;
float fVelocidadInicial = 0;
float fVelocidadFinal = 0;
float fVelocidadPromedio = 0;
float fAceleracion = 0;
float fDistancia = 0;
float fTiempo = 0;
float fAltura = 0;
const float fGravedad = 9.81;

void vMenuMRU(){  
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"Utiliza solo km/h o m/s.\n\n";
		cout<<"Teclee la opción que requiera calcular: \n";
		cout<<"1. Velocidad.\n";
		cout<<"2. Distancia.\n";
		cout<<"3. Tiempo.\n";
		cout<<"\n4. Regresar al menú anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vMRUVelocidad(); break;
			case 2: vMRUDistancia(); break;
			case 3: vMRUTiempo(); break;
			case 4: bSalir = true; break;
			default: cout<<"Esa opción no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMenuMRUV(){  
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"Utiliza solo km/h o m/s.\n\n";
		cout<<"Teclee la opción que requiera calcular: \n";
		cout<<"1. Velocidad final a partir del tiempo.\n";
		cout<<"2. Velocidad final a partir de la distancia.\n";
		cout<<"3. Velocidad final a partir de la distancia (sin aceleración).\n";
		cout<<"4. Distancia a partir de la aceleración y tiempo.\n";
		cout<<"5. Distancia a partir de la velocidad final.\n";
		cout<<"6. Velocidad promedio.\n";
		cout<<"7. Aceleración a partir de la distancia.\n";
		cout<<"8. Aceleracion a partir del tiempo.\n";
		cout<<"9. Tiempo a partir de la aceleracion.\n";
		cout<<"10. Tiempo a partir de la distancia.\n";
		cout<<"11. Velocidad final a partir de la velocidad promedio.\n";
		cout<<"12. Velocidad inicial a partir de la velocidad final, aceleracion y tiempo.\n";
		cout<<"\n13. Regresar al menú anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vMRUVVelocidadFinalTiempo(); break;
			case 2: vMRUVVelocidadFinalDistancia(); break;
			case 3: vMRUVVelocidadFinalDistanciaAceleracion(); break;
			case 4: vMRUVDistanciaAceleracion(); break;
			case 5: vMRUVDistanciaVelocidadFinal(); break;
			case 6: vMRUVVelocidadPromedio(); break;
			case 7: vMRUVAceleracionDistancia(); break;
			case 8: vMRUVAceleracionTiempo(); break;
			case 9: vMRUVTiempoAceleracion(); break;
			case 10: vMRUVTiempoDistancia(); break;
			case 11: vMRUVVelocidadFinalVelocidadPromedio(); break;
			case 12: vMRUVVelocidadInicialVelocidadFinal(); break;
			case 13: bSalir = true; break;
			default: cout<<"Esa opción no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMenuCaidaLibre(){
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"Teclee la opcion que requiera calcular: \n";
		cout<<"1. Altura en caida libre.\n";
		cout<<"2. Velocidad de caida a partir del tiempo.\n";
		cout<<"3. Velocidad de caida a partir de la distancia.\n";
		cout<<"4. Tiempo de caida libre.\n";
		cout<<"5. Tiempo de subida a partir de la velocidad inicial.\n";
		cout<<"6. Altura máxima a partir de la velocidad inicial.\n";
		cout<<"\n7. Regresar al menú anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vMRCLAlturaCaidaLibre(); break;
			case 2: vMRCLVelocidadCaidaTiempo(); break;
			case 3: vMRCLVelocidadCaidaDistancia(); break;
			case 4: vMRCLTiempoCaidaLibre(); break;
			case 5: vMRCLTiempoSubidaVelocidadInicial(); break;
			case 6: vMRCLAlturaMaximaVelocidadInicial(); break;
			case 7: bSalir = true; break;
			default: cout<<"Esa opción no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMRUVelocidad(){
	fflush(stdin);
	cout<<"Teclee la cantidad de unidades de distancia: ";
	fDistancia = vLecturaNumero();
	fflush(stdin);
	cout<<"Teclee la cantidad de unidades de tiempo: ";
	fTiempo = vLecturaNumero();
	fVelocidad = fDistancia/fTiempo;
	cout<<"La velocidad promedio es: "<<fVelocidad<<" unidades de velocidad.\n";
}

void vMRUDistancia(){
	fflush(stdin);
	cout<<"Teclee la cantidad de unidades de velocidad: ";
	fVelocidad = vLecturaNumero();
	fflush(stdin);
	cout<<"Teclee la cantidad de unidades de tiempo: ";
	fTiempo = vLecturaNumero();
	fDistancia = fVelocidad*fTiempo;
	cout<<"La distancia es: "<<fDistancia<<" unidades de distancia.\n";	
}

void vMRUTiempo(){
	fflush(stdin);
	cout<<"Teclee la cantidad de unidades de distancia: ";
	fDistancia = vLecturaNumero();
	fflush(stdin);
	cout<<"Teclee la cantidad de unidades de velocidad: ";
	fVelocidad = vLecturaNumero();
	fTiempo = fDistancia/fVelocidad;
	cout<<"El tiempo es: "<<fTiempo<<" unidades de tiempo.\n";	
}

void vMRUVVelocidadFinalTiempo(){
	fflush(stdin);
	cout<<"¿Cuál es la velocidad inicial (m/s)? ";
	fVelocidadInicial = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la razón de aceleración (m/s^2)? ";
	fAceleracion = vLecturaNumero();
	fflush(stdin);
	cout<<"Teclee la cantidad de tiempo en segundos: ";
	fTiempo = vLecturaNumero();
	fVelocidadFinal = fVelocidadInicial+(fAceleracion*fTiempo);
	cout<<"La velocidad final resultante es: "<<fVelocidadFinal<<" m/s.\n";
}

void vMRUVVelocidadFinalDistancia(){
	fflush(stdin);
	cout<<"¿Cuál es la velocidad inicial (m/s)? ";
	fVelocidadInicial = vLecturaNumero();
	fflush(stdin);
	cout<<"Teclee la distancia en metros: ";
	fDistancia = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la razón de aceleración (m/s^2)? ";
	fAceleracion = vLecturaNumero();
	fVelocidadFinal = sqrt(pow(fVelocidadInicial,2)+(2*fAceleracion*fDistancia));
	cout<<"La vlocidad final resultante es: "<<fVelocidadFinal<<" m/s.\n";
}

void vMRUVDistanciaAceleracion(){
	fflush(stdin);
	cout<<"¿Cuál es la velocidad inicial (m/s)? ";
	fVelocidadInicial = vLecturaNumero();
	fflush(stdin);
	cout<<"Teclee la cantidad de tiempo es segundos: ";
	fTiempo = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la razón de aceleración (m/s^2)? ";
	fAceleracion = vLecturaNumero();
	fDistancia = (fVelocidadInicial*fTiempo)+((fAceleracion*pow(fTiempo,2))/2);
	cout<<"La distancia resultante es: "<<fDistancia<<" metros.\n";
}

void vMRUVDistanciaVelocidadFinal(){
	fflush(stdin);
	cout<<"¿Cuál es la velocidad inicial (m/s)? ";
	fVelocidadInicial = vLecturaNumero();
	fflush(stdin);
	cout<<"Teclee la cantidad de tiempo en segundos: ";
	fTiempo = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la velocidad final (m/s)? ";
	fVelocidadFinal = vLecturaNumero();
	fDistancia = ((fVelocidadInicial+fVelocidadFinal)/2)*fTiempo;
	cout<<"La distancia resultante es: "<<fDistancia<<" metros.\n";
}

void vMRUVVelocidadPromedio(){
	fflush(stdin);
	cout<<"¿Cuál es la velocidad inicial (m/s)? ";
	fVelocidadInicial = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la velocidad final (m/s)? ";
	fVelocidadFinal = vLecturaNumero();
	fVelocidad = (fVelocidadInicial+fVelocidadFinal)/2;
	cout<<"La velocidad promedio es: "<<fVelocidad<<" m/s.\n";
}

void vMRUVAceleracionDistancia(){
	fflush(stdin);
	cout<<"¿Cuál es la velocidad inicial (m/s)? ";
	fVelocidadInicial = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la velocidad final (m/s)? ";
	fVelocidadFinal = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la distancia en metros? ";
	fDistancia = vLecturaNumero();
	fAceleracion = (pow(fVelocidadFinal,2)-pow(fVelocidadInicial,2))/(fDistancia*2);
	cout<<"La aceleración resultante es: "<<fAceleracion<<" m/s^2.\n";
}

void vMRUVAceleracionTiempo(){
	fflush(stdin);
	cout<<"Cuál es la velocidad inicial (m/s? ";
	fVelocidadInicial = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la velocidad final (m/s)? ";
	fVelocidadFinal = vLecturaNumero();
	fflush(stdin);
	cout<<"Teclee el tiempo inicial en segundos: ";
	float fTiempoInicial = vLecturaNumero();
	fflush(stdin);
	cout<<"Teclee el tiempo final: ";
	float fTiempoFinal = vLecturaNumero();
	fAceleracion = (fVelocidadFinal-fVelocidadInicial)/(fTiempoFinal-fTiempoInicial);
	cout<<"La aceleración resultante es: "<<fAceleracion<<" m/s^2.\n";
}

void vMRUVTiempoAceleracion(){
	fflush(stdin);
	fVelocidadInicial = fVelocidadFinal = fAceleracion = fTiempo = 0;
	cout<<"¿Cuál es la velocidad inicial (m/s)? ";
	fVelocidadInicial = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la velocidad final (m/s)? ";
	fVelocidadFinal = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la razón de aceleración (m/s^2)? ";
	fAceleracion = vLecturaNumero();
	fTiempo = (fVelocidadFinal-fVelocidadInicial)/fAceleracion;
	cout<<"La distancia resultante es: "<<fTiempo<<" segundos.\n";
}


void vMRUVTiempoDistancia(){
	fflush(stdin);
	cout<<"¿Cuál es la velocidad inicial (m/s)? ";
	fVelocidadInicial = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la velocidad final (m/s)? ";
	fVelocidadFinal = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la distancia en metros? ";
	fDistancia = vLecturaNumero();
	fTiempo = fDistancia/((fVelocidadInicial+fVelocidadFinal)/2);
	cout<<"La distancia resultante es: "<<fTiempo<<" segundos.\n";
}

void vMRUVVelocidadFinalVelocidadPromedio(){
	fflush(stdin);
	cout<<"¿Cuál es la velocidad promedio? ";
	fVelocidadPromedio = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cual es la velocidad inicial? ";
	fVelocidadInicial = vLecturaNumero();
	fVelocidadFinal = (2*fVelocidadPromedio)-fVelocidadInicial;
	cout<<"La velocidad final es: "<<fVelocidadFinal<<" m/s.\n";
}

void vMRUVVelocidadInicialVelocidadFinal(){
	fflush(stdin);
	cout<<"¿Cuál es la velocidad final? ";
	fVelocidadFinal = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la razón de aceleración? ";
	fAceleracion = vLecturaNumero();
	fflush(stdin);
	cout<<"Teclee el tiempo en segundos: ";
	fTiempo = vLecturaNumero();
	fVelocidadInicial = fVelocidadFinal-(fAceleracion*fTiempo);
	cout<<"La velocidad inicial es: "<<fVelocidadInicial<<" m/s.\n";
}

void vMRUVVelocidadFinalDistanciaAceleracion(){
	fflush(stdin);
	cout<<"¿Cuál es la velocidad inicial? ";
	fVelocidadInicial = vLecturaNumero();
	fflush(stdin);
	cout<<"¿Cuál es la distancia en metros? ";
	fDistancia = vLecturaNumero();
	fflush(stdin);
	cout<<"Teclee el tiempo en segundos: ";
	fTiempo = vLecturaNumero();
	fVelocidadFinal = ((2*fDistancia)/fTiempo)-fVelocidadInicial;
	cout<<"La velocidad final resultante es: "<<fVelocidadFinal<<" m/s.\n";
}

void vMRCLAlturaCaidaLibre(){
	fflush(stdin);
	cout<<"Teclee la cantidad de segundos en caida libre: ";
	fTiempo = vLecturaNumero();
	fAltura = (fGravedad*pow(fTiempo,2))/2;
	cout<<"La Altura de caida es: "<<fAltura<<" metros.\n";
}

void vMRCLVelocidadCaidaTiempo(){
	fflush(stdin);
	cout<<"Teclee la cantidad de segundos en caida libre: ";
	fTiempo = vLecturaNumero();
	fVelocidadFinal = fGravedad*fTiempo;
	cout<<"La Altura de caida es: "<<fVelocidadFinal<<" m/s.\n";
}

void vMRCLVelocidadCaidaDistancia(){
	fflush(stdin);
	cout<<"Teclee la altura de caida en metros: ";
	fAltura = vLecturaNumero();
	fVelocidadFinal = sqrt(2*fGravedad*fAltura);
	cout<<"La velocidad de caida es: "<<fVelocidadFinal<<" m/s.\n";
}

void vMRCLTiempoCaidaLibre(){
	fflush(stdin);
	cout<<"Teclee la cantidad de metros en caida libre: ";
	fAltura = vLecturaNumero();
	fTiempo = sqrt((2*fAltura)/fGravedad);
	cout<<"El tiempo de caida es: "<<fTiempo<<" segundos.\n";
}

void vMRCLTiempoSubidaVelocidadInicial(){
	fflush(stdin);
	cout<<"Teclee la velocidad inicial en segundos: ";
	fVelocidadInicial = vLecturaNumero();
	fTiempo = fVelocidadInicial/fGravedad;
	cout<<"El tiempo que tarda en subir es: "<<fTiempo<<" segundos.\n";
}

void vMRCLAlturaMaximaVelocidadInicial(){
	fflush(stdin);
	cout<<"Teclee la velocidad inicial en m/s: ";
	fVelocidadInicial = vLecturaNumero();
	fAltura = (pow(fVelocidadInicial,2))/(2*fGravedad);
	cout<<"La Altura máxima es: "<<fAltura<<" metros.\n";
}


