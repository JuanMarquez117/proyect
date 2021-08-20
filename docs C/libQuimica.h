#include<iostream>
#include<cmath>
#include<stdlib.h>
#include"libConversiones.h"
using namespace std;

//prototipos de funcion
void vMenuLeyBoyleMariotte();
void vMenuLeyCharles();
void vMenuMol();
void sacarLambdaFrec(); //lambda a partir de la frecuencia
void sacarLambdaFrec(float); //lambda a partir de la frecuencia con frec. parametro
void sacarLambdaMasaVel();//lambda a partir de la masa y velocidad (De Broglie)
void sacarFrecuencia();
void sacarVelocidad();
void sacarJoules();   //en cantidad de cuantos
//void sacarTiempo();
void sacarFrecuenciaTrabajo();
//void sacarFuncionDeTrabajo();
void sacarEnergiaCinetica();
void sacarDiferenciaDeEnergia();
//void sacarNivelInicialDeEnergia();
void vEnergiaMol();
void sacarLambdaJoules();  //longitud de onda a partir de la energia del foton (J)
void sacarIncertidumbrePosicion(); //principio de incertidumbre de heisenberg
void sacarIncertidumbreVelocidad(); //principio de incertidumbre de heisenberg
void sacarGramosPorMol();  //peso en gramos de un atomo o molecula
void sacarMoleculasPorGramo(); //cantidad de moleculas o atomos que hay en un gramo
void configuracionElectronica(); //afbau*/
void configuracionElectronicaKernel(int); //kernel y spin
void sacarCargaNuclearEfectiva();
void vLeyBoyleMariotteVolumen();
void vLeyBoyleMariottePresion();
void vLeyCharlesVolumen();
void vLeyCharlesTemperatura();
void vMasaMolar();
void vMolGramo();

//variables globales.
const float numeroDeAvogadro = 6.023*pow(10,23);
const float constanteDePlanck = 6.63*pow(10,-34);
//double inversaConstanteDeRydberg = 1.097*pow(10,7);  //inversa de lambda
const float constanteDeRydberg = 2.18*pow(10,-18);
float velocidad = 0;
float frecuencia = 0;
float lambda = 0;
float joules = 0;
//double tiempo = 0;
//double distancia = 0;
float trabajo = 0;
float energiaCinetica = 0;
float masa = 0;
const float pi = 3.14159;
float momento = 0;
float pesoMol = 0;
float pesoMolecula = 0;

void vMenuLeyBoyleMariotte(){
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"\t\t\t\t\t\t\tLey de Boyle-Mariotte\n";
		cout<<"\"A temperatura constante, los volúmenes ocupados por una gas son inversamente proporcionales";
		cout<<" a las presiones a las que está sometido.\"\n\n";
		cout<<"Teclee la opción que requiera: \n";
		cout<<"1. Volúmen final a partir de volúmen inicial y presión inicial-final.\n";
		cout<<"2. Presión en Torrs a partir de litros iniciales-finales y presión iniciales.\n";
		cout<<"\n3. Regresar al menú anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vLeyBoyleMariotteVolumen(); break;
			case 2: vLeyBoyleMariottePresion(); break;
			case 3: bSalir = true; break;
			default: cout<<"Esa opción no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMenuLeyCharles(){
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"\t\t\t\t\t\t\tLey de Charles.\n";
		cout<<"\"A presión constante, el volúmen de una muestra de gas es directamente proporcional a la ";
		cout<<"temperatura absoluta\".\n\n";
		cout<<"Teclee la opción que requiera: \n";
		cout<<"1. litros a partir de litros iniciales y temperatura iniciales-finales.\n";
		cout<<"2. temperatura a partir de temperatura inicial y litros iniciales-finales.\n";
		cout<<"\n3. Regresar al menú anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vLeyCharlesVolumen(); break;
			case 2: vLeyCharlesTemperatura(); break;
			case 3: bSalir = true; break;
			default: cout<<"Esa opción no existe.\n";	
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMenuMol(){
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"Teclee la opción que requiera: \n";
		cout<<"1. Energia de un mol de fotones (J).\n";
		cout<<"2. Peso en gramos de un atomo o molecula.\n";
		cout<<"3. Cantidad de atomos o moleculas por cada gramo.\n";
		cout<<"4. Masa molecular de una sustancia en gramos/mol(U.M.A.).\n";
		cout<<"5. Número de moles por cantidad de gramos de una sustancia.\n";
		cout<<"\n6. Regresar al menú anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vEnergiaMol(); break;
			case 2: sacarGramosPorMol(); break;
			case 3: sacarMoleculasPorGramo(); break;
			case 4: vMasaMolar(); break;
			case 5: vMolGramo(); break;
			case 6: bSalir = true; break;
			default: cout<<"Esa opción no existe.\n";
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void sacarLambdaFrec(){
	cout<<"Cual es la velocidad de la onda (U) en metros sobre segundo (m/s)?:\n";
	velocidad = vLecturaNumero();
	cout<<"\n";
	cout<<"Cual es la frecuencia de la onda (V) en Hz (o s^-1)? :\n";
	frecuencia = vLecturaNumero();
	cout<<"\n";
	lambda = velocidad/frecuencia;
	cout<<"El valor de lambda es: "<<lambda<<" metros.\n\n\n";
}

void sacarLambdaFrec(float Frecuencia){
	cout<<"Cual es la velocidad de la onda (U) en metros sobre segundo (m/s)?:\n";
	velocidad = vLecturaNumero();
	frecuencia = Frecuencia;
	cout<<"\n";
	lambda = velocidad/frecuencia;
	cout<<"El valor de lambda es: "<<lambda<<" metros.\n\n\n";
}

void sacarLambdaMasaVel(){
	cout<<"Cual es la cantidad de masa en Kg?:\n";
	masa = vLecturaNumero();
	cout<<"Cual es la velocidad en m/s? :\n";
	velocidad = vLecturaNumero();
	cout<<"\n";
	lambda = constanteDePlanck/(masa*velocidad);
	cout<<"El valor de lambda es: "<<lambda<<" metros.\n\n\n";
}

void sacarFrecuencia(){
	cout<<"Cual es la velocidad de la onda (U) en metros sobre segundo (m/s)?:\n";
	velocidad = vLecturaNumero();
	cout<<"\n";
	cout<<"Cual es la longitud de la onda (lambda) en metros (m)?:\n";
	lambda = vLecturaNumero();
	cout<<"\n";
	frecuencia = velocidad/lambda;
	cout<<"El valor de la frecuencia es: "<<frecuencia<<" Hz(o s^-1).\n";
}

void sacarVelocidad(){
	cout<<"Cual es la frecuencia de la onda en Hz (o s^-1)?:\n";
	frecuencia = vLecturaNumero();
	cout<<"\n";
	cout<<"Cual es la longitud de la onda en metros (m)?:\n";
	lambda = vLecturaNumero();
	cout<<"\n";
	velocidad = lambda/frecuencia;
	cout<<"El valor de velocidad es: "<<velocidad<<" m/s.\n";
}

void sacarJoules(){
	cout<<"Cual es la frecuencia de la onda en Hz (o s^-1)?:\n";
	frecuencia = vLecturaNumero();
	cout<<"\n";
	joules = constanteDePlanck*frecuencia;
	cout<<"La cantidad de energia es: "<<joules<<" joules.\n";
}

void sacarTiempo(){  //incompleto
/*	cout<<"Cual es la distancia en metros(m)?:\n";
	distancia = lecturaDeNumero();
	cout<<"\n";
	cout<<"Cual es la velocidad en metros sobre segundo (m/s)?:\n";
	velocidad = lecturaDeNumero();
	cout<<"\n";
	tiempo = distancia/velocidad;
	cout<<"El valor del tiempo es: "<<tiempo<<" segundos.\n";*/
} 

void sacarFrecuenciaTrabajo(){
	cout<<"Cual es la cantidad de energia de trabajo en Joules (W)?\n";
	trabajo = vLecturaNumero();
	frecuencia = trabajo/constanteDePlanck;
	cout<<"La frecuencia minima es: "<<frecuencia<<" Hz(o s^-1).\n";
}

void sacarEnergiaCinetica(){
	cout<<"Cual es la frecuencia del foton (v) en Hz(o s^-1)?\n";
	frecuencia = vLecturaNumero();
	cout<<"Cual es la energia de trabajo (W) en Joules?\n";
	trabajo = vLecturaNumero();
	energiaCinetica = (constanteDePlanck*frecuencia)-trabajo;
	cout<<"La energia cinetica es de: "<<energiaCinetica<<" Joules (J).\n";
}

void sacarFuncionDeTrabajo(){  //incompleto
/*	cout<<"Cual es la frecuencia del foton (v) en Hz(o s^-1)?.\n";
	frecuencia = lecturaDeNumero();
	cout<<"Cual es la energia cinetica (Ec) en Joules (J)?\n";
	energiaCinetica = lecturaDeNumero();
	trabajo = (constanteDePlanck*frecuencia)-energiaCinetica;
	cout<<"La funcion de trabajo es de: "<<trabajo<<" Joules (J).\n";*/
}

void sacarDiferenciaDeEnergia(){
	int ni;  //nivel incial del estado cuantico
	int nf;  //nivel final del estado cuantico
	float aux; //diferencia de energia
	float DE; //diferencia de energia
	cout<<"Teclee el nivel inicial del estado cuantico: ";cin>>ni;
	cout<<"Teclee el nivel final del estado cuantico: ";cin>>nf;
	if(ni>nf){
		aux = constanteDeRydberg*((1/pow(nf,2))-(1/pow(ni,2)));
		DE = abs(aux);
		cout<<"La diferencia de energia es de: "<<DE<<" Joules (J).\n";
	}
	else{
		cout<<"No funciona.\n";
	}	
}

void sacarNivelInicialDeEnergia(){  //incompleto
/*	float ni = 0;  //nivel incial del transito cuantico
	float nf = 0;  //nivel final del transito cuantico
	double aux = 0; 
	double aux2 = 0; //diferencia de energia
	double lambdaInversa = 0; //diferencia de energia
	cout<<"Teclee el nivel inicial del estado cuantico: ";cin>>ni;
	cout<<"Cual es la longitud de onda expulsada?: ";
	lambda = lecturaDeNumero();
	//despejando nf
	lambdaInversa = 1/lambda;
	cout<<"lambdaInversa: "<<lambdaInversa<<"\n";
	aux = lambdaInversa/constanteDeRydberg;		
	cout<<"lambdaInv/constR: "<<lambdaInversa/constanteDeRydberg<<"\n";		
	aux = aux-(1/ni);
	cout<<"aux: "<<aux<<"\n";
	aux2 = 1/aux;
	cout<<"aux2: "<<aux2<<"\n";
	aux = abs(aux2);
	cout<<"abs aux2: "<<aux<<"\n";
	aux2 = sqrt(aux);
	cout<<"raiz aux: "<<aux2<<"\n";
	cout<<"El valor del nivel final de energia es: "<<aux2<<".\n";
	
	if(ni>nf){
		aux = constanteDeRydberg*((1/pow(nf,2))-(1/pow(ni,2)));
		DE = abs(aux);
		cout<<"La diferencia de energia es de: "<<DE<<" Joules (J).\n";
	}
	else{
		cout<<"No funciona.\n";
	}*/
}

void vEnergiaMol(){
	cout<<"Cual es la energia del foton en Joules (J)?.\n";
	joules = vLecturaNumero();
	float fEnergiaMol = joules*numeroDeAvogadro;
	cout<<"La cantidad de energia es: "<<fEnergiaMol<<" J/mol.\n";
}

void sacarLambdaJoules(){  //lambda a partir de la energia del foton
	cout<<"Cual es la cantidad de energia el foton? (J)?\n";
	joules = vLecturaNumero();
	frecuencia = joules/constanteDePlanck;
	sacarLambdaFrec(frecuencia);
}

void sacarIncertidumbrePosicion(){  //principio de incertidumbre de heisenberg
	float porcentajeIncertidumbreVelocidad = 0;
	float diferencialVelocidad = 0;
	float incertidumbrePosicion = 0;
	float diferencialMomento = 0;
	cout<<"Cual es la masa de la particula en kg?\n";
	masa = vLecturaNumero();
	cout<<"Cual es la velocidad de la particula en m/s?\n";
	velocidad = vLecturaNumero();
	cout<<"Cual es el porcentaje de incertidumbre de la velocidad?\n";
	cout<<"Si no existe el porcentaje colocar un 0.\n";
	porcentajeIncertidumbreVelocidad = vLecturaNumero();
	cout<<"porcentajeIncertidumbreVelocidad: "<<porcentajeIncertidumbreVelocidad<<"\n";
	if(porcentajeIncertidumbreVelocidad==0){
		float incertidumbreMomento = 0;
		cout<<"Cual es el valor de la indeterminacion?\n";
		incertidumbreMomento = vLecturaNumero();
		momento = velocidad*masa;
		diferencialMomento = incertidumbreMomento*momento;	
		incertidumbrePosicion = constanteDePlanck/(4*pi*diferencialMomento);
		cout<<"La incertidumbre de la posicion de la particula es: "<<incertidumbrePosicion;
		cout<<" metros.\n";
	}
	if(porcentajeIncertidumbreVelocidad>0){
		diferencialVelocidad = (porcentajeIncertidumbreVelocidad/100)*velocidad;	
		incertidumbrePosicion = constanteDePlanck/(4*pi*masa*diferencialVelocidad);
		cout<<"La incertidumbre de la posicion de la particula es: "<<incertidumbrePosicion;
		cout<<" metros.\n";
	}
}

void sacarIncertidumbreVelocidad(){
	float incertidumbrePosicion = 0;
	float incertidumbreVelocidad = 0;
	cout<<"Cual es la masa de la particula en kg?\n";
	masa = vLecturaNumero();
	cout<<"Cual es la magnitud de incertidumbre de la posicion?\n";
	incertidumbrePosicion = vLecturaNumero();	
	incertidumbreVelocidad = constanteDePlanck/(4*pi*masa*incertidumbrePosicion);
	cout<<"La incertidumbre de la posicion de la particula es: "<<incertidumbreVelocidad;
	cout<<" metros.\n";	
}

void sacarGramosPorMol(){  //usando avogadro, obtiene el peso en gramos de una atomo o molecula
	cout<<"Cual es el peso del atomo o molecula en g/mol?\n";
	pesoMol = vLecturaNumero();
	pesoMolecula = pesoMol/numeroDeAvogadro;
	cout<<"El peso del atomo o molecula es: "<<pesoMolecula<<" g/molecula.\n";
}

void sacarMoleculasPorGramo(){  //cantidad de moleculas o atomos por cada gramo
	cout<<"Cual es el peso del atomo o molecula en g/mol(U.M.A.)?\n";
	pesoMol = vLecturaNumero();
	pesoMolecula = numeroDeAvogadro/pesoMol;
	cout<<"La cantidad de atomos o moleculas es: "<<pesoMolecula<<" moleculas/g.\n";
}

void configuracionElectronica(){
	int numeroAtomico = 0;
	int numero = 0;
	int nivelEnergia = 1;
	int numeroElectrones = 0;
	char orbital = 's';
	cout<<"\nCual es el numero atomico del elemento?\n";cin>>numero;
	numeroAtomico = numero;
	if(numeroAtomico==24||numeroAtomico==28||numeroAtomico==29||numeroAtomico==41||numeroAtomico==42
	||numeroAtomico==44||numeroAtomico==45||numeroAtomico==46||numeroAtomico==47||numeroAtomico==57
	||numeroAtomico==58||numeroAtomico==64||numeroAtomico==78||numeroAtomico==79||numeroAtomico==89
	||numeroAtomico==90||numeroAtomico==91||numeroAtomico==92||numeroAtomico==93||numeroAtomico==96
	||numeroAtomico==103){
		switch(numeroAtomico){
			case 24:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^1 3d^5\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Ar] 4s^1 3d^5\n";
				cout<<"Spin: + 1/2.\n";
				break;
			case 28:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^1 3d^9\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Ar] 4s^1 3d^9\n";
				cout<<"Spin: - 1/2.\n";
				break;
			case 29:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^1 3d^10\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Ar] 4s^1 3d^10\n";
				cout<<"Spin: - 1/2.\n";
				break;
			case 41:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^1 4d^4\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Kr] 5s^1 4d^4\n";
				cout<<"Spin: + 1/2.\n";
				break;
			case 42:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^1 4d^5\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Kr] 5s^1 4d^5\n";
				cout<<"Spin: + 1/2.\n";
				break;
			case 44:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^1 4d^7\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Kr] 5s^1 4d^7\n";
				cout<<"Spin: - 1/2.\n";
				break;
			case 45:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^1 4d^8\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Kr] 5s^1 4d^8\n";
				cout<<"Spin: - 1/2.\n";
				break;
			case 46:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||4d^10\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Kr] 4d^10\n";
				cout<<"Spin: - 1/2.\n";
				break;
			case 47:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^1 4d^10\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Kr] 5s^1 4d^10\n";
				cout<<"Spin: - 1/2.\n";
				break;
			case 57:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^2 ";
				cout<<"5d^1\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Xe] 6s^2 5d^1\n";
				cout<<"Spin: + 1/2.\n";
				break;
			case 58:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^2 ";
				cout<<"4f^1 5d^1\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Xe] 6s^2 4f^1 5d^1\n";
				cout<<"Spin: + 1/2.\n";
				break;
			case 64:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^2 ";
				cout<<"4f^7 5d^1\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Xe] 6s^2 4f^7 5d^1\n";
				cout<<"Spin: - 1/2.\n";
				break;
			case 78:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^1 ";
				cout<<"4f^14 5d^9\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Xe] 6s^1 4f^14 5d^9\n";
				cout<<"Spin: - 1/2.\n";
				break;
			case 79:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^1 ";
				cout<<"4f^14 5d^10\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Xe] 6s^1 4f^14 5d^10\n";
				cout<<"Spin: - 1/2.\n";
				break;
			case 89:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^2 ";
				cout<<"4f^14 5d^10 6p^6 ||7s^2 6d^1\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Xe] 6s^2 4f^14 5d^10 6p^6 ||7s^2 6d^1\n";
				cout<<"Spin: + 1/2.\n";
				break;
			case 90:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^2 ";
				cout<<"4f^14 5d^10 6p^6 ||7s^2 6d^2\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Xe] 6s^2 4f^14 5d^10 6p^6 ||7s^2 6d^2\n";
				cout<<"Spin: + 1/2.\n";
				break;
			case 91:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^2 ";
				cout<<"4f^14 5d^10 6p^6 ||7s^2 5f^2 6d^1\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Rn] 7s^2 5f^2 6d^1\n";
				cout<<"Spin: + 1/2.\n";
				break;
			case 92:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^2 ";
				cout<<"4f^14 5d^10 6p^6 ||7s^2 5f^3 6d^1\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Rn] 7s^2 5f^3 6d^1\n";
				cout<<"Spin: + 1/2.\n";
				break;
			case 93:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^2 ";
				cout<<"4f^14 5d^10 6p^6 ||7s^2 5f^4 6d^1\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Rn] 7s^2 5f^4 6d^1\n";
				cout<<"Spin: + 1/2.\n";
				break;
			case 96:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^2 ";
				cout<<"4f^14 5d^10 6p^6 ||7s^2 5f^7 6d^1\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Rn] 7s^2 5f^7 6d^1\n";
				cout<<"Spin: - 1/2.\n";
				break;
			case 103:
				cout<<"configuracion electronica por nivel de energia:\n";
				cout<<"||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^10 4p^6 ||5s^2 4d^10 5p^6 ||6s^2 ";
				cout<<"4f^14 5d^10 6p^6 ||7s^2 5f^14 7p^1\n";
				cout<<"configuracion electronica por kernel:\n";
				cout<<"[Rn] 7s^2 5f^14 7p^1\n";
				cout<<"Spin: + 1/2.\n";
				break;
			default:
				break;
		}
	}
	else{
		cout<<"\nConfiguracion electronica por principio de aufbau:\n";
		do{
			while(nivelEnergia>=1&&orbital=='s'&&numeroElectrones<2){
				cout<<"|";
				if(numeroAtomico==0){
					break;
				}
				numeroAtomico--;
				numeroElectrones++;
				if(numeroElectrones==2&&orbital=='s'){
					cout<<nivelEnergia<<orbital<<"^"<<numeroElectrones<<" ";
					numeroElectrones = 0;
					nivelEnergia++;
					if(nivelEnergia>6&&orbital=='s'&&numeroAtomico>0&&numeroElectrones==0){
						orbital = 'f';
						nivelEnergia--;
						break;
					}
					if(nivelEnergia>4&&orbital=='s'&&numeroAtomico>0&&numeroElectrones==0){
						orbital = 'd';
						nivelEnergia--;
						break;
					}
					if(nivelEnergia>2&&numeroAtomico>0){
						orbital = 'p';
						nivelEnergia--;		
					}
				}
			}
			while(nivelEnergia>=2&&orbital=='p'&&numeroElectrones<6){
				if(numeroAtomico==0){
					break;
				}
				numeroAtomico--;
				numeroElectrones++;
				if(numeroElectrones==6&&orbital=='p'){
					cout<<nivelEnergia<<orbital<<"^"<<numeroElectrones<<" ";
					numeroElectrones = 0;
					nivelEnergia++;
					orbital = 's';
				}
			}
			while(nivelEnergia>=4&&orbital=='d'&&numeroElectrones<10){
				nivelEnergia--;
				if(numeroAtomico==0){
					break;
				}
				numeroAtomico--;
				numeroElectrones++;
				if(numeroElectrones==10&&orbital=='d'){
					cout<<nivelEnergia<<orbital<<"^"<<numeroElectrones<<" ";
					numeroElectrones = 0;
					orbital = 'p';
				}
				nivelEnergia++;
			}
			while(nivelEnergia>=6&&orbital=='f'&&numeroElectrones<14){
				nivelEnergia = nivelEnergia-2;
				if(numeroAtomico==0){
					break;
				}
				numeroAtomico--;
				numeroElectrones++;
				if(numeroElectrones==14&&orbital=='f'){
					cout<<nivelEnergia<<orbital<<"^"<<numeroElectrones<<" ";
					numeroElectrones = 0;
					orbital = 'd';
				}
				nivelEnergia = nivelEnergia+2;
			}
			if(numeroAtomico==0){
				break;
			}
		}while(numeroAtomico!=0);
		if(numeroElectrones>0){
			cout<<nivelEnergia<<orbital<<"^"<<numeroElectrones<<" ";
		}	
		configuracionElectronicaKernel(numero);
	}
	cout<<"\n";
}

void configuracionElectronicaKernel(int numeroAtomico){
	int nivelEnergia = 1;
	int cantidadElectrones = 0;
	int numeroElectrones = 0;
	char orbital = 's';
	char spin = '+';
	string gasNoble = " ";
	if(numeroAtomico>86){
		nivelEnergia = 7;
		numeroAtomico -= 86;
		gasNoble = "[Rn] ";
	}
	else if(numeroAtomico>54){
		nivelEnergia = 6;
		numeroAtomico -= 54;
		gasNoble = "[Xe] ";
	}
	else if(numeroAtomico>36){
		nivelEnergia = 5;
		numeroAtomico -= 36;
		gasNoble = "[Kr] ";
	}
	else if(numeroAtomico>18){
		nivelEnergia = 4;
		numeroAtomico -= 18;
		gasNoble = "[Ar] ";
	}
	else if(numeroAtomico>10){
		nivelEnergia = 3;
		numeroAtomico -= 10;
		gasNoble = "[Ne] ";
	}
	else if(numeroAtomico>2){
		nivelEnergia = 2;
		numeroAtomico -= 2;
		gasNoble = "[He] ";
	}
	cout<<"\nConfiguracion electronica por kernel: \n"<<gasNoble;
	do{
		while(nivelEnergia>=1&&orbital=='s'&&numeroElectrones<2){
			if(numeroAtomico==0){
				break;
			}
			numeroAtomico--;
			numeroElectrones++;
			if(numeroElectrones==2&&orbital=='s'){
				cout<<nivelEnergia<<orbital<<"^"<<numeroElectrones<<" ";
				numeroElectrones = 0;
				nivelEnergia++;
				if(nivelEnergia>6&&orbital=='s'&&numeroAtomico>0&&numeroElectrones==0){
					orbital = 'f';
					nivelEnergia--;
					break;
				}
				if(nivelEnergia>4&&orbital=='s'&&numeroAtomico>0&&numeroElectrones==0){
					orbital = 'd';
					nivelEnergia--;
					break;
				}
				if(nivelEnergia>2&&numeroAtomico>0){
					orbital = 'p';
					nivelEnergia--;		
				}
			}
		}
		while(nivelEnergia>=2&&orbital=='p'&&numeroElectrones<6){
			if(numeroAtomico==0){
				break;
			}
			numeroAtomico--;
			numeroElectrones++;
			if(numeroElectrones==6&&orbital=='p'){
				cout<<nivelEnergia<<orbital<<"^"<<numeroElectrones<<" ";
				numeroElectrones = 0;
				nivelEnergia++;
				orbital = 's';
			}
		}
		while(nivelEnergia>=4&&orbital=='d'&&numeroElectrones<10){
			nivelEnergia--;
			if(numeroAtomico==0){
				break;
			}
			numeroAtomico--;
			numeroElectrones++;
			if(numeroElectrones==10&&orbital=='d'){
				cout<<nivelEnergia<<orbital<<"^"<<numeroElectrones<<" ";
				numeroElectrones = 0;
				orbital = 'p';
			}
			nivelEnergia++;
		}
		while(nivelEnergia>=6&&orbital=='f'&&numeroElectrones<14){
			nivelEnergia = nivelEnergia-2;
			if(numeroAtomico==0){
				break;
			}
			numeroAtomico--;
			numeroElectrones++;
			if(numeroElectrones==14&&orbital=='f'){
				cout<<nivelEnergia<<orbital<<"^"<<numeroElectrones<<" ";
				numeroElectrones = 0;
				orbital = 'd';
			}
			nivelEnergia = nivelEnergia+2;
		}
		if(numeroAtomico==0){
			break;
		}
	}while(numeroAtomico!=0);
	if(orbital=='s'){
		cantidadElectrones = 2;	
	}
	if(orbital=='p'){
		cantidadElectrones = 6;
	}
	if(orbital=='d'){
		cantidadElectrones = 10;
	}
	if(orbital=='f'){
		cantidadElectrones = 14;
	}
	if(numeroElectrones<=cantidadElectrones/2){
		spin = '+';
	}
	else{
		spin = '-';
	}
	if(numeroElectrones>0){
		cout<<nivelEnergia<<orbital<<"^"<<numeroElectrones<<" ";
		cout<<"\nSpin: "<<spin<<" 1/2.\n";
	}	
	cout<<"\n";
}

void sacarCargaNuclearEfectiva(){  //incompleto
/*	int numeroAtomico = 0;
	int numero = 0;
	int nivelEnergia = 1;
	int numeroElectrones = 0;
	char orbital = 's';
	int cantidadElectrones = 0;
	float electrones_SyP = 0;
	float electrones_DyF = 0;
	float cargaNuclearEfectiva = 0;
	float ultimoGrupo = 0;
	cout<<"\nCual es el numero atomico del elemento?: \n";cin>>numero;
	numeroAtomico = numero;
	/*if(numeroAtomico>86){
		nivelEnergia = 7;
		numeroAtomico -= 86;
	}
	else if(numeroAtomico>54){
		nivelEnergia = 6;
		numeroAtomico -= 54;
	}
	else if(numeroAtomico>36){
		nivelEnergia = 5;
		numeroAtomico -= 36;
	}
	*/
	/*else if(numeroAtomico>18){
		nivelEnergia = 4;
		numeroAtomico -= 18;
		electrones_DyF += 10;
		electrones_SyP += 8;
	}
	else if(numeroAtomico>10){
		nivelEnergia = 3;
		numeroAtomico -= 10;
		electrones_DyF += 2;
		electrones_SyP += 8;
	}
	else if(numeroAtomico>2){
		nivelEnergia = 2;
		numeroAtomico -= 2;
		electrones_SyP += 2;	
	}
	cout<<"\nCarga nuclear efectiva: \n";
	numeroAtomico--;
	do{
		if(numeroAtomico<2&&nivelEnergia==1){
			break;
		}
		while(nivelEnergia>=1&&orbital=='s'&&numeroElectrones<2){
			if(numeroAtomico==0){
				//cout<<"salida";
				break;
			}
			numeroAtomico--;
			numeroElectrones++;
			if(numeroElectrones==2&&orbital=='s'){
				ultimoGrupo += numeroElectrones;
				numeroElectrones = 0;
				//cout<<"hola"<<electrones_SyP<<numeroElectrones;
				nivelEnergia++;
				if(nivelEnergia>6&&orbital=='s'&&numeroAtomico>0&&numeroElectrones==0){
					orbital = 'f';
					nivelEnergia--;
					break;
				}
				if(nivelEnergia>4&&orbital=='s'&&numeroAtomico>0&&numeroElectrones==0){
					orbital = 'd';
					nivelEnergia--;
					ultimoGrupo -=2;
					break;
				}
				if(nivelEnergia>2&&numeroAtomico>0){
					orbital = 'p';
					nivelEnergia--;		
				}
			}
		}
		while(nivelEnergia>=2&&orbital=='p'&&numeroElectrones<6){
			if(numeroAtomico==0){
				break;
			}
			numeroAtomico--;
			numeroElectrones++;
			if(numeroElectrones==6&&orbital=='p'){
				electrones_SyP += numeroElectrones;
				numeroElectrones = 0;
				nivelEnergia++;
				orbital = 's';
			}
		}
		while(nivelEnergia>=4&&orbital=='d'&&numeroElectrones<10){
			nivelEnergia--;
			if(numeroAtomico==0){
				break;
			}
			numeroAtomico--;
			numeroElectrones++;
			if(numeroElectrones==10&&orbital=='d'){
				ultimoGrupo += numeroElectrones;
				numeroElectrones = 0;
				orbital = 'p';
			}
			nivelEnergia++;
		}  //||1s^2 ||2s^2 2p^6 ||3s^2 3p^6 ||4s^2 3d^1
		while(nivelEnergia>=6&&orbital=='f'&&numeroElectrones<14){
			nivelEnergia = nivelEnergia-2;
			if(numeroAtomico==0){
				break;
			}
			numeroAtomico--;
			numeroElectrones++;
			if(numeroElectrones==14&&orbital=='f'){
				cout<<nivelEnergia<<orbital<<"^"<<numeroElectrones<<" ";
				numeroElectrones = 0;
				orbital = 'd';
			}
			nivelEnergia = nivelEnergia+2;
		}
	}while(numeroAtomico!=0);
	/*if(orbital=='s'){
		cantidadElectrones = 2;	
	}
	if(orbital=='p'){
		cantidadElectrones = 6;
	}
	if(orbital=='d'){
		cantidadElectrones = 10;
	}
	if(orbital=='f'){
		cantidadElectrones = 14;
	}
	
	if(numeroElectrones>0){
		ultimoGrupo += numeroElectrones;
		//cout<<ultimoGrupo;
	}
	if(numeroAtomico<2&&nivelEnergia==1){
		electrones_SyP = numeroAtomico * .3;
		cargaNuclearEfectiva = numero - electrones_SyP;
	}
	else{
	cargaNuclearEfectiva = numero;
	cargaNuclearEfectiva -= electrones_DyF;
	cargaNuclearEfectiva -= electrones_SyP * .85;
	cargaNuclearEfectiva -= ultimoGrupo * .35;	
	}
	//cout<<abs(cargaNuclearEfectiva)<<"\n";	
	cout<<cargaNuclearEfectiva<<"\n";	
	cout<<"\n";*/
}

void vLeyBoyleMariotteVolumen(){
	float fPresionInicial = 0,fPresionFinal = 0,fVolumenFinal = 0,fVolumenInicial = 0;
	cout<<"Teclee la cantidad de unidades de volúmen inicial: ";cin>>fVolumenInicial;
	cout<<"Teclee la cantidad de unidades de presión inicial: ";cin>>fPresionInicial;
	cout<<"Teclee la cantidad de unidades de presión final: ";cin>>fPresionFinal;
	fVolumenFinal = (fPresionInicial*fVolumenInicial)/fPresionFinal;
	cout<<"La cantidad de volúmen final es: "<<fVolumenFinal<<" unidades de volúmen.\n";
}

void vLeyBoyleMariottePresion(){
	float fVolumenInicial = 0,fVolumenFinal = 0,fPresionInicial = 0,fPresionFinal = 0;
	cout<<"Teclee la cantidad de unidades de volúmen inicial: ";cin>>fVolumenInicial;
	cout<<"Teclee la cantidad de unidades de volúmen final ó esperado: ";cin>>fVolumenFinal;
	cout<<"Teclee la cantidad de unidades de presión inicial: ";cin>>fPresionInicial;
	fPresionFinal = (fVolumenInicial*fPresionInicial)/fVolumenFinal;
	cout<<"La cantidad de presión final es: "<<fPresionFinal<<" unidades de presión.\n";
}

void vLeyCharlesVolumen(){
	float fLitrosInicial = 0,fLitrosFinal = 0,fTemperaturaInicial = 0,fTemperaturaFinal = 0;
	cout<<"Teclee la cantidad de litros iniciales: ";cin>>fLitrosInicial;
	cout<<"Teclee la cantidad de temperatura inicial(en °C): ";cin>>fTemperaturaInicial;
	cout<<"Teclee la cantidad de temperatura final(en °C): ";cin>>fTemperaturaFinal;
	fLitrosFinal = (fTemperaturaFinal*fLitrosInicial)/fTemperaturaInicial;
	cout<<"La cantidad de volúmen final es: "<<fLitrosFinal<<" Litros.\n";
}

void vLeyCharlesTemperatura(){
	/*float fLitrosInicial = 0,fLitrosFinal = 0,fTemperaturaInicial = 0,fTemperaturaFinal = 0;
	cout<<"Teclee la cantidad de litros iniciales: ";cin>>fLitrosInicial;
	cout<<"Teclee la cantidad de litros finales ó esperados: ";cin>>fLitrosFinal;
	cout<<"Teclee la cantidad de temperatura inicial en °C: ";cin>>fTemperaturaInicial;
	fTemperaturaFinal = (fLitrosInicial*fPresionInicial)/fLitrosFinal;
	cout<<"La cantidad de temperatura final es: "<<fTemperaturaFinal<<" Torrs.\n";*/
}

void vMasaMolar(){
	int i,iNumero; //número de elementos en la molecula.
	int iCantidad;
	float fMasaElemento,fMasaMolar = 0;
	cout<<"Teclee la cantidad de elementos en la molecula: ";cin>>iNumero;
	for(i = 0;i<iNumero;i++){
		cout<<"Teclee la masa del elemento "<<i+1<<": ";cin>>fMasaElemento;
		cout<<"Teclee la cantidad de átomos del elemento "<<i+1<<" en la molécula: ";cin>>iCantidad;
		fMasaMolar += (fMasaElemento*iCantidad);
	}
	cout<<"La masa molar total es: "<<fMasaMolar<<" g/mol(U.M.A.).\n";
}

void vMolGramo(){
	float fPesoGramos = 0;
	fflush(stdin);
	cout<<"Teclee el peso en gramos de un mol de la molécula: ";cin>>pesoMolecula;
	fflush(stdin);
	cout<<"Teclee los gramos de sustancia a calcular: ";cin>>fPesoGramos;
	float fEquivalencia = fPesoGramos/pesoMolecula;
	cout<<"La equivalencia de los gramos a moles de la sustancia calculada es: "<<fEquivalencia<<" moles.\n";
}







