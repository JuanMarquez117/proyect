#include<iostream>
#include<cmath>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

//prototipos de funcion

float vLecturaNumero();
float fNumeroNotacion(char *,int);
void conversorNumeroNotacion();
void vMenuConversiones();
void vMenuConversionesDistancia();
void vMenuConversionesTiempo();
void vMenuConversionesPeso();
void vMenuConversionesTemperatura();
void vMenuConversionesVolumen();
void vMenuConversionesPresion();
void vMenuConversionesVelocidad();
void vDistanciaMetrosNanometros();
void vDistanciaMetrosMilimetros();
void vDistanciaMilimetrosMetros();
void vDistanciaNanometrosMetros();
void vDistanciaAngstromMetros();
void vDistanciaMillaKilometro();
void vDistanciaMillaMetro();
void vDistanciaCentimetrosMetros();
void vDistanciaKilometroMetro();
void vDistanciaMetroKilometro();
void vTiempoSegundoMinuto();
void vTiempoMinutoSegundo();
void vTiempoHoraSegundo();
void vVelocidadMIPHmps();  //milla por hora a metro por segundo
void vVelocidadHZmhz();  //hercio a megahercio
void vVelocidadTHZhz();  //terahercio a hercio
void vVelocidadHZthz();  //hercio a terahercio
void vVelocidadKmPHmps(); //conversor de kil�metros por hora a metros por segundo.
void vVelocidadMPSkmph();  //conversor de metros por segundo a kil�metros por hora.
void vPesoGramoKg();
void vPresionLibraPulgadaCuadradaATM();  //conversor de libras sobre pulgada cuadrada a atmosferas.
void vPresionLibraPulgadaCuadradaTorr();  //conversor de libras sobre pulgada cuadrada a torr.
void vPresionLibraPulgadaCuadradaPascales();  //conversor de libras sobre pulgada cuadrada a pascales.
void vPresionTorrATM();  //conversor de torrs a atmosferas.
void vPresionTorrPascales();
void vPresionPascalesKPa();  //conversor de pascales a KiloPascales.
void vPresionKPaPascales();  //conversor de KiloPascales a Pascales.
void vPresionKPaATM();  //conversor de Kilopascales a Atm�sferas.
void vPresionKPaTorr();  //conversor de Kilopascales a Torrs.
void vPresionPascalesLibraPulgadaCuadrada();  //conversor de pascales a libras por pie cuadrado.
void vPresionATMTorr();  //conversor de atmosferas a torrs.
void vPresionATMLibraplgcuadrada();  //conversor de atm�sferas a lb/plg^2(libras sobre pulgada cuadrada).
void vPresionATMPlgMercurio();  //conversor de atm�sferas a pulgadas de mercurio.
void vPresionATPKpa();  //conversor de atm�sferas a kilopascales.
void vPresionATMBars();  //conversor de atm�sferas a Bares.
void vTemperaturaCelsiusFahrenheit();
void vTemperaturaFahrenheitCelsius();
void vTemperaturaCelsiusKelvin();
void vTemperaturaKelvinCelsius();
void vTemperaturaFahrenheitKelvin();
void vTemperaturaKelvinFahrenheit();
void vVolumenKilometroCubicoLitros();
void vVolumenHectometroCubicoLitros();
void vVolumenDecametroCubicoLitros();
void vVolumenMetroCubicoLitros();
void vVolumenDecimetroCubicoLitros();  //decimetros cubicos a litros
void vVolumenCentimetroCubicoLitros();
void vVolumenCentimetroCubicoMililitros();
void vVolumenMilimetroCubicoLitros();
void vVolumenLitrosCMCubicos();

//variables globales
double nanometros = 0;
double millas = 0;
double mhz = 0;  //megahercios
double thz = 0;  //terahercios
double hz = 0;  //hercios
double angstrom = 0;
double centimetros = 0;
float fMetros = 0;
float fKilometros = 0;
float fLibras = 0;
float fTorrs = 0;
float fAtmosferas = 0;
float fPascales = 0;
float fKPa = 0;  //KiloPascales.
float fFahrenheit = 0;
float fCelsius = 0;
float fKelvin = 0;
float fLitros = 0;
float fCM3 = 0;
float fHoras = 0;
float fMinutos = 0;
float fSegundos = 0;

float vLecturaNumero(){
	char *cNumero;
	float fNumero = 0;
	cNumero = (char*)malloc(sizeof(char));
	int iLongitud = 0;
	int bandera = 0;
	fflush(stdin);
	cin>>cNumero;
	iLongitud = strlen(cNumero);
	for(int i = 0;i<iLongitud;i++){
		if(cNumero[i]=='*'){
			bandera++;
			fNumero = fNumeroNotacion(cNumero,iLongitud);
			return fNumero;
			break;
		}
	}
	if(bandera==0){
		fNumero = atof(cNumero);
		return fNumero;
	}
}

float fNumeroNotacion(char *cNumero,int iLongitud){
	float fNum = 0;
	char cNum[iLongitud];
	char cExponente[iLongitud];
	int iExponente = 0;
	for(int i = 0;i<iLongitud;i++){  //este ciclo obtiene el numero.
		if(cNumero[i]=='*'){
			break;
		}
		cNum[i] = cNumero[i];
	}
	fNum = atof(cNum);
	for(int i = 0;i<iLongitud;i++){  //este ciclo obtiene el exxponente.
		if(cNumero[i]=='^'){
			int aux = i+1;
			for(int j = 0;j<iLongitud;j++){
				if(aux>iLongitud){
					break;
				}
				cExponente[j] = cNumero[j+aux];
			}
			break;
		}
	}
	iExponente = atoi(cExponente);
	return fNum*pow(10,iExponente);
}

void conversorNumeroNotacion(){
	float num;
	int exponente= 0;
	cout<<"Teclee el numero: \n";cin>>num;
	if(num<1){
		do{
			num *= 10;
			exponente++;
		}while(num<1);
		cout<<"El numero en notacion cientifica es: ";
		cout<<num<<"*10^-"<<exponente<<"\n";
	}
	else if(num>=10){
		do{
			num /= 10;
			exponente++; 
		}while(num>10);
		cout<<"El numero en notacion cientifica es: ";
		cout<<num<<"*10^"<<exponente<<"\n";
	}
	else{
		cout<<"El numero en notacion cientifica es: ";
		cout<<num<<"*10^"<<exponente<<"\n";
	}
}

void vMenuConversiones(){
	char cOpcion[2];
	int iOpcion = 0;
	bool bSalir = false;
	do{
		system("cls");
		cout<<"Teclee La opcion de conversion que desea: \n";
		cout<<"1. N�meros a Notaci�n Cient�fica.\n";
		cout<<"2. Conversiones de distancia.\n";
		cout<<"3. Conversiones de tiempo.\n";
		cout<<"4. Conversiones de peso.\n";
		cout<<"5. Conversiones de presi�n.\n";
		cout<<"6. Conversiones de temperaturas.\n";
		cout<<"7. Conversiones de vol�men.\n";
		cout<<"8. Conversiones de velocidad.\n";
		cout<<"\n9. Regresar al men� anterior.\n ";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: conversorNumeroNotacion(); break;
			case 2: vMenuConversionesDistancia(); break;
			case 3: vMenuConversionesTiempo(); break;
			case 4: vMenuConversionesPeso(); break;
			case 5: vMenuConversionesPresion(); break;
			case 6: vMenuConversionesTemperatura(); break;
			case 7: vMenuConversionesVolumen(); break;
			case 8: vMenuConversionesVelocidad(); break;
			case 9: bSalir = true; break;
			default: cout<<"Esa opci�n no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMenuConversionesDistancia(){
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"Teclee la opci�n de conversion que requiere: \n";
		cout<<"1. Metros a Nan�metros.\n";
		cout<<"2. Metros a Mil�metros.\n";
		cout<<"3. Mil�metros a Metros.\n";
		cout<<"4. Nan�metros a Metros\n";
		cout<<"5. M�llas a Kil�metros.\n";
		cout<<"6. M�llas a Metros.\n";
		cout<<"7. Ansgtroms a Metros.\n";
		cout<<"8. Cent�metros a Metros.\n";
		cout<<"9. Kil�metros a Metros.\n";
		cout<<"10. Metros a Kil�metros.\n";
		cout<<"\n11. Regresar al men� anterior\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vDistanciaMetrosNanometros(); break;
			case 2: vDistanciaMetrosMilimetros(); break;
			case 3: vDistanciaMilimetrosMetros(); break;
			case 4: vDistanciaNanometrosMetros(); break;
			case 5: vDistanciaMillaKilometro(); break;
			case 6: vDistanciaMillaMetro(); break;
			case 7: vDistanciaAngstromMetros(); break;
			case 8: vDistanciaCentimetrosMetros(); break;
			case 9: vDistanciaKilometroMetro(); break;
			case 10: vDistanciaMetroKilometro(); break;
			case 11: bSalir = true; break;
			default: cout<<"Esa opci�n no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMenuConversionesTiempo(){
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"Teclee la opci�n de conversi�n que requiere: \n";
		cout<<"1. Segundos a Minutos.\n";
		cout<<"2. Minutos a Segundos.\n";
		cout<<"3. Horas a Segundos.\n";
		cout<<"\n4. Regresar al men� anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vTiempoSegundoMinuto(); break;
			case 2: vTiempoMinutoSegundo(); break;
			case 3: vTiempoHoraSegundo(); break; 
			case 4: bSalir = true; break;
			default: cout<<"Esa opci�n no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMenuConversionesPeso(){
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"Teclee la opci�n que requiera: \n";
		cout<<"1. Gramos a Kilogramos\n";
		cout<<"\n2. Regresar al men� anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vPesoGramoKg(); break;
			case 2: bSalir = true; break;
			default: cout<<"Esa opci�n no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMenuConversionesTemperatura(){
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"Teclee la opci�n de conversi�n que requiera: \n";
		cout<<"1. Celsius a Fahrenheit.\n";
		cout<<"2. Fahrenheit a Celsius.\n";
		cout<<"3. Celsius a Kelvin.\n";
		cout<<"4. Kelvin a Celsius.\n";
		cout<<"5. Fahrenheit a Kelvin.\n";
		cout<<"6. Kelvin a Fahrenheit.\n";
		cout<<"\n7. Regresar al men� anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vTemperaturaCelsiusFahrenheit(); break;
			case 2: vTemperaturaFahrenheitCelsius(); break;
			case 3: vTemperaturaCelsiusKelvin(); break;
			case 4: vTemperaturaKelvinCelsius(); break;
			case 5: vTemperaturaFahrenheitKelvin(); break;
			case 6: vTemperaturaKelvinFahrenheit(); break;
			case 7: bSalir = true; break;
			default: cout<<"Esa opci�n no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMenuConversionesVolumen(){
	bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"Teclee la opci�n de conversi�n que requiera: \n";
		cout<<"1. Kil�metros c�bicos a Litros.\n";
		cout<<"2. Hect�metros c�bicos a Litros.\n";
		cout<<"3. Dec�metros c�bicos a Litros.\n";
		cout<<"4. Metros c�bicos a Litros.\n";
		cout<<"5. Dec�metros c�bicos a Litros.\n";
		cout<<"6. Cent�metros c�bicos a Litros.\n";
		cout<<"7. Cent�metros C�bicos a Mililitros.\n";
		cout<<"8. Mil�metros c�bicos a Litros.\n";
		cout<<"9. Litros a Cent�metros c�bicos.\n";
		cout<<"\n10. Regresar al men� anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vVolumenKilometroCubicoLitros(); break;
			case 2: vVolumenHectometroCubicoLitros(); break;
			case 3: vVolumenDecametroCubicoLitros(); break;
			case 4: vVolumenMetroCubicoLitros(); break;
			case 5: vVolumenDecimetroCubicoLitros(); break;
			case 6: vVolumenCentimetroCubicoLitros(); break;
			case 7: vVolumenCentimetroCubicoMililitros(); break;
			case 8: vVolumenMilimetroCubicoLitros(); break;
			case 9: vVolumenLitrosCMCubicos(); break;
			case 10: bSalir = true; break;
			default: cout<<"Esa opci�n no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMenuConversionesPresion(){
	char cOpcion[2];
	int iOpcion = 0;
	bool bSalir = false;
	do{
		system("cls");
		cout<<"Teclee la opci�n de conversi�n que requiera: \n";
		cout<<"1. Libras sobre pulgada cuadrada a Atm�sferas.\n";
		cout<<"2. Libras sobre pulgada cuadrada cuadrada a Torrs.\n";
		cout<<"3. Libras sobre pulgada cuadrada a Pascales.\n";
		cout<<"4. Torrs a Atm�sferas.\n";
		cout<<"5. Torrs a Pascales.\n";
		cout<<"6. Pascales a Kilopascales(KPa).\n";
		cout<<"7. Kilopascales a Pascales.\n";
		cout<<"8. Kilopascales a Atm�sferas.\n";
		cout<<"9. Kilopascales a Torrs.\n";
		cout<<"10. Pascales a Libras sobre pulgada cuadrada.\n";
		cout<<"11. Atm�sferas a Torrs(mm Hg).\n";
		cout<<"12. Atm�sferas a Libras sobre pulgada cuadrada.\n";
		cout<<"13. Atm�sferas a Pulgadas de mercurio.\n";
		cout<<"14. Atm�sferas a Kilopascales.\n";
		cout<<"15. Atm�sferas a Bares.\n";
		cout<<"\n16. Regresar al men� anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vPresionLibraPulgadaCuadradaATM(); break;
			case 2: vPresionLibraPulgadaCuadradaTorr(); break;
			case 3: vPresionLibraPulgadaCuadradaPascales(); break;
			case 4: vPresionTorrATM(); break;
			case 5: vPresionTorrPascales(); break;
			case 6: vPresionPascalesKPa(); break;
			case 7: vPresionKPaPascales(); break;
			case 8: vPresionKPaATM(); break;
			case 9: vPresionKPaTorr(); break;
			case 10: vPresionPascalesLibraPulgadaCuadrada(); break;
			case 11: vPresionATMTorr(); break;
			case 12: vPresionATMLibraplgcuadrada(); break;
			case 13: vPresionATMPlgMercurio(); break;
			case 14: vPresionATPKpa(); break;
			case 15: vPresionATMBars(); break;
			case 16: bSalir = true; break;
			default: cout<<"Esa opci�n no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vMenuConversionesVelocidad(){
		bool bSalir = false;
	char cOpcion[2];
	int iOpcion = 0;
	do{
		system("cls");
		cout<<"Teclee la opci�n de conversi�n que requiere: \n";
		cout<<"1. M�llas por hora a Metros por segundo.\n";
		cout<<"2. Hercios a Megahercios.\n";
		cout<<"3. Terahercios a Hercios.\n";
		cout<<"4. Hercios a Terahercios.\n";
		cout<<"5. Kil�metros por hora a Metros por segundo.\n";
		cout<<"6. Metros por segundo a Kil�metros por hora.\n";
		cout<<"\n7. Regresar al men� anterior.\n";
		cin>>cOpcion;
		iOpcion = atoi(cOpcion);
		switch(iOpcion){
			case 1: vVelocidadMIPHmps(); break;
			case 2: vVelocidadHZmhz(); break;
			case 3: vVelocidadTHZhz(); break;
			case 4: vVelocidadHZthz(); break;
			case 5: vVelocidadKmPHmps(); break;
			case 6: vVelocidadMPSkmph(); break;
			case 7: bSalir = true; break;
			default: cout<<"Esa opci�n no existe.\n"; break;
		}
		if(bSalir==false)
			system("pause");
	}while(bSalir==false);
}

void vDistanciaMetrosNanometros(){
	double conversorNanometros = 1*pow(10,9);
	cout<<"Introducir el valor a convertir en metros:\n";
	fMetros = vLecturaNumero();
	nanometros = fMetros*conversorNanometros;
	cout<<"La cantidad es: "<<nanometros<<" nanometros.\n\n";
}

void vDistanciaMetrosMilimetros(){
	double milimetros=0;
	double conversorMilimetros=0;
	conversorMilimetros = 1*pow(10,3);
	cout<<"Introducir el valor a convertir en metros:\n";
	fMetros = vLecturaNumero();
	milimetros = fMetros*conversorMilimetros;
	cout<<"La cantidad es: "<<milimetros<<" milimetros.\n\n";
}

void vDistanciaMilimetrosMetros(){
	double milimetros=0;
	double conversorMetros=0;
	conversorMetros = 1*pow(10,3);
	cout<<"Introducir el valor a convertir en milimetros:\n";
	milimetros = vLecturaNumero();
	fMetros = milimetros/conversorMetros;
	cout<<"La cantidad es: "<<fMetros<<" metros.\n\n";
}

void vDistanciaNanometrosMetros(){
	double conversorMetros = 1*pow(10,9);
	cout<<"Introducir el valor a convertir en nanometros:\n";
	nanometros = vLecturaNumero();
	fMetros = nanometros/conversorMetros;
	cout<<"La cantidad es: "<<fMetros<<" metros.\n\n";
}

void vDistanciaAngstromMetros(){
	double conversorMetros = 1*pow(10,-10);
	cout<<"Cual es la cantidad de Angstrom (�A)?\n";
	angstrom = vLecturaNumero();
	fMetros = angstrom*conversorMetros;
	cout<<"La cantidad de metros es: "<<fMetros<<" metros.\n";
}

void vDistanciaMillaKilometro(){
	float kilometros;
	cout<<"Teclee la cantidad de millas: \n";
	millas = vLecturaNumero();
	kilometros = millas*1.61;
	cout<<"El resultado es "<<kilometros<<" kilometros.\n";
}

void vDistanciaMillaMetro(){
	cout<<"Teclee la cantidad de millas:\n";
	millas =  vLecturaNumero();
	fMetros =  millas*1609;
	cout<<"El resultado es "<<fMetros<<" metros.\n";
}

void vDistanciaCentimetrosMetros(){
	double conversorMetros = 1*pow(10,2);
	cout<<"Cual es la cantidad en cm?\n";
	centimetros = vLecturaNumero();
	fMetros = centimetros/conversorMetros;
	cout<<"La cantidad de metros es: "<<fMetros<<" metros.\n";
}

void vDistanciaKilometroMetro(){
	cout<<"Teclee la cantidad de kilometros:\n";
	fKilometros =  vLecturaNumero();
	fMetros =  fKilometros*1000;
	cout<<"El resultado es "<<fMetros<<" metros.\n";
}

void vDistanciaMetroKilometro(){
	cout<<"Teclee la cantidad de metros:\n";
	fMetros =  vLecturaNumero();
	fKilometros =  fMetros/1000;
	cout<<"El resultado es "<<fKilometros<<" kil�metros.\n";
}

void vTiempoSegundoMinuto(){
	cout<<"Teclee la cantidad de segundos: \n";
	fSegundos = vLecturaNumero();
	fMinutos = fSegundos/60;
	cout<<"El resultado es: "<<fMinutos<<" minutos.\n";
}

void vTiempoMinutoSegundo(){
	cout<<"Teclee la cantidad de minutos: \n";
	fMinutos = vLecturaNumero();
	fSegundos = fMinutos*60;
	cout<<"El resultado es: "<<fSegundos<<" segundos.\n";
}

void vTiempoHoraSegundo(){
	cout<<"Teclee la cantidad de horas: \n";
	fHoras = vLecturaNumero();
	fSegundos = fHoras*3600;
	cout<<"El resultado es: "<<fSegundos<<" segundos.\n";
}

void vVelocidadMIPHmps(){  //millas por hora a metros por segundo
	cout<<"Cual es la velocidad en millas por hora?\n";
	millas = vLecturaNumero();
	fMetros = (millas*1609)/3600;
	cout<<"La velocidad en metros por segundo es: "<<fMetros<<" m/s.\n\n";
}

void vVelocidadHZmhz(){  //hercios a megahercios
	double conversorMHZ = 1*pow(10,6);
	cout<<"Cual es la cantidad en hz?\n";
	hz = vLecturaNumero();
	mhz = hz/conversorMHZ;
	cout<<"La cantidad de megahercios (mHz) es: "<<mhz<<" MHz.\n";
}

void vVelocidadTHZhz(){ //terahercios a hercios
	double conversorHZ = 1*pow(10,12);
	cout<<"Cual es la cantidad en THz?\n";
	thz = vLecturaNumero();
	hz = thz*conversorHZ;
	cout<<"La cantidad de Hz es : "<<hz<<" Hz.\n";
}

void vVelocidadHZthz(){
	double conversorTHZ = 1*pow(10,12);
	cout<<"Cual es la cantidad en Hz?\n";
	hz = vLecturaNumero();
	thz = hz/conversorTHZ;
	cout<<"La cantidad de THz es: "<<thz<<" THz.\n";
}

void vVelocidadKmPHmps(){
	cout<<"�Cu�l es la velocidad en Kil�metros por segundo? ";
	fKilometros = vLecturaNumero();
	fMetros = (fKilometros*1000)/3600;
	cout<<"La velocidad en metros sobre segundo (m/s) es: "<<fMetros<<" m/s.\n";
}

void vVelocidadMPSkmph(){
	cout<<"�Cu�l es la velocidad en metros por segundo? ";
	fKilometros = vLecturaNumero();
	fMetros = (fKilometros*3600)/1000;
	cout<<"La velocidad en kil�metros por hora es: "<<fMetros<<" km/h.\n";
}

void vPesoGramoKg(){
	float gramos = 0,kilogramos = 0;
	cout<<"Cual es la cantidad de gramos?\n";
	gramos = vLecturaNumero();
	kilogramos = gramos/1000;
	cout<<"El equivalente es: "<<kilogramos<<" Kg.\n";
}

void vPresionLibraPulgadaCuadradaATM(){  //conversor de libras sobre pulgada cuadrada a atmosferas.
	cout<<"Teclee la cantidad de libras sobre pulgada cuadrada a convertir: ";cin>>fLibras;
	 fAtmosferas = fLibras*0.06805;  //14.7 es la equivalencia de libras a atmosferas.
	 cout<<"La cantidad de atmosferas equivalente es: "<<fAtmosferas<<" atmosferas.\n";
}

void vPresionLibraPulgadaCuadradaTorr(){  //conversor de libras por pie cuadrado a torr(unidad de presi�n).
	cout<<"Teclee la cantidad de libras a convertir: ";cin>>fLibras;
	fTorrs = fLibras*51.7149;  //0.359133 es el equivalente de libras por pie cuadrado a torr.
	cout<<"La cantidad de Torr equivalentes es: "<<fTorrs<<" Torr.\n";
}

void vPresionLibraPulgadaCuadradaPascales(){
	cout<<"Teclee la cantidad de libras a convertir: ";cin>>fLibras;
	fPascales = fLibras*6894.76;  //47.8803 es equivalente a un pascal.
	cout<<"La cantidad de pascales equivalente es: "<<fPascales<<" pascales.\n";
}

void vPresionTorrATM(){
	cout<<"Teclee la cantidad de torrs a convertir: ";cin>>fTorrs;
	fAtmosferas = fTorrs*0.00131579;  //0.00131579 equivale a la atmosfera.
	cout<<"La cantidad de atmosferas es: "<<fAtmosferas<<" atmosferas.\n";
}

void vPresionTorrPascales(){
	cout<<"Teclee la cantidad de torrs a convertir: ";cin>>fTorrs;
	fPascales = fTorrs*133.32;
	cout<<"La cantidad de pascales es: "<<fPascales<<" pascales.\n";
}

void vPresionPascalesKPa(){  //conversor de pascales a KiloPascales.
	cout<<"Teclee la cantidad de pascales a convertir: ";cin>>fPascales;
	fKPa = fPascales*0.001;
	cout<<"La cantidad de Kilopascales es: "<<fKPa<<" KPa.\n";
}

void vPresionKPaPascales(){
	cout<<"Teclee la cantidad de Kilopascales a convertir: ";cin>>fKPa;
	fPascales = fKPa*1000;
	cout<<"La cantidad de Pascales es: "<<fPascales<<" pascales.\n";
}

void vPresionKPaATM(){
	fflush(stdin);
	cout<<"teclee la cantidad de Kilopascales a convertir: ";cin>>fKPa;
	fAtmosferas = fKPa/101.325;
	cout<<"La cantidad de atm�sferas equvalentes es: "<<fAtmosferas<<" ATM.\n";
}

void vPresionKPaTorr(){
	fflush(stdin);
	cout<<"teclee la cantidad de Kilopascales a convertir: ";cin>>fKPa;
	fTorrs = fKPa*7.50065;
	cout<<"La cantidad de Torrs(mmHg) equvalentes es: "<<fTorrs<<" Torrs.\n";
}

void vPresionPascalesLibraPulgadaCuadrada(){  //conversor de pascales a libras por pie cuadrado
	cout<<"Teclee la cantidad de pascales a convertir: ";cin>>fPascales;
	fLibras = fPascales*0.000145;
	cout<<"La cantidad de libras sobre pulgada cuadrada es: "<<fLibras<<" libras.\n";
}

void vPresionATMTorr(){
	cout<<"Teclee la cantidad de atmosferas a convertir: ";cin>>fAtmosferas;
	fTorrs = fAtmosferas*760;
	cout<<"La cantidad de Torrs (o mm de Hg) equivalente es: "<<fTorrs<<" Torrs.\n";
}

void vPresionATMLibraplgcuadrada(){
	cout<<"teclee la cantidad de atm�sferas a convertir: ";cin>>fAtmosferas;
	fLibras = fAtmosferas*14.7;
	cout<<"La cantidad de libras sobre pulgada cuadrada es: "<<fLibras<<" li/plg^2.\n";
}

void vPresionATMPlgMercurio(){
	cout<<"Teclee la cantidad de atm�sferas a convertir: ";cin>>fAtmosferas;
	float fPlgMercurio = fAtmosferas*29.9;
	cout<<"La cantidad de pulgadas de mercurio equivalentes es: "<<fPlgMercurio<<" pulgadas de mercurio.\n";
}

void vPresionATPKpa(){
	cout<<"Teclee la cantidad de atm�sferas a convertir: ";cin>>fAtmosferas;
	fKPa = fAtmosferas*101.325;
	cout<<"La cantidad de Kilopascales equivalentes es: "<<fKPa<<" kPa.\n";
}

void vPresionATMBars(){
	cout<<"Teclee la cantidad de atm�sferas a convertir: ";cin>>fAtmosferas;
	float fBars = fAtmosferas*1.013;
	cout<<"La cantidad de Bares equivalentes es: "<<fBars<<" Bares.\n";
}

void vTemperaturaCelsiusFahrenheit(){
	cout<<"Teclee la cantidad de grados Celsius a convertir: ";cin>>fCelsius;
	fFahrenheit = (fCelsius*1.8)+32;
	cout<<"La cantidad de grados Fahrenheit equivalentes es: "<<fFahrenheit<<" �F.\n";
}

void vTemperaturaFahrenheitCelsius(){
	cout<<"Teclee la cantidad de grados Fahrenheit a convertir: ";cin>>fFahrenheit;
	fCelsius = (fFahrenheit-32)/1.8;
	cout<<"La cantidad de grados Celsius equivalentes es: "<<fCelsius<<" �C.\n";
}

void vTemperaturaCelsiusKelvin(){
	cout<<"Teclee la cantidad de grados Celsius a convertir: ";cin>>fCelsius;
	fKelvin = fCelsius + 273;
	cout<<"La cantidad de grados Kelvin equivalentes es: "<<fKelvin<<" �K.\n";
}

void vTemperaturaKelvinCelsius(){
	cout<<"Teclee la cantidad de grados Kelvin a convertir: ";cin>>fKelvin;
	fCelsius = fKelvin - 273;
	cout<<"La cantidad de grados Celsius equivalentes es: "<<fCelsius<<" �C.\n";
}

void vTemperaturaFahrenheitKelvin(){
	float aux = 5;
	aux /=9;
	cout<<"Teclee la cantidad de grados Fahrenheit a convertir: ";cin>>fFahrenheit;
	cout<<"aux: "<<aux<<endl;
	fKelvin = ((fFahrenheit-32)*aux) + 273;
	cout<<"La cantidad de grados Kelvin equivalentes es: "<<fKelvin<<" �K.\n";
}

void vTemperaturaKelvinFahrenheit(){
	cout<<"Teclee la cantidad de grados Kelvin a convertir: ";cin>>fKelvin;
	fFahrenheit = (1.8*(fKelvin-273)) + 32; //1.8 es equivalente a 9/5
	cout<<"La cantidad de grados Fahrenheit equivalentes es: "<<fFahrenheit<<" �F.\n";
}

void vVolumenKilometroCubicoLitros(){
	float fKmCubicos = 0;
	cout<<"Teclee la cantidad de kilometros c�bicos a convertir: ";cin>>fKmCubicos;
	fLitros = fKmCubicos*1000000000000;
	cout<<"La cantidad de litros equivalentes es: "<<fLitros<<" litros.\n";
}

void vVolumenHectometroCubicoLitros(){
	float fHmCubicos = 0;
	cout<<"Teclee la cantidad de hect�metros c�bicos a convertir: ";cin>>fHmCubicos;
	fLitros = fHmCubicos*1000000000;
	cout<<"La cantidad de litros equivalentes es: "<<fLitros<<" litros.\n";
}

void vVolumenDecametroCubicoLitros(){
	float fDamCubico = 0;
	cout<<"Teclee la cantidad de dec�metros a convertir: ";cin>>fDamCubico;
	fLitros = fDamCubico*1000000;
	cout<<"La cantidad de litros equivalentes es: "<<fLitros<<" litros.\n";
}

void vVolumenMetroCubicoLitros(){
	float fMCubico = 0;
	cout<<"Teclee la cantidad de metros c�bicos a convertir: ";cin>>fMCubico;
	fLitros = fMCubico*1000;
	cout<<"La cantidad de litros equivalentes es: "<<fLitros<<" litros.\n";
}

void vVolumenDecimetroCubicoLitros(){
	float fDmCubico;
	cout<<"Teclee la cantidad de dec�metros c�bicos a convertir: ";cin>>fDmCubico;
	cout<<"La cantidad de litros es equivalente a: "<<fDmCubico<<" litros.\n";
}

void vVolumenCentimetroCubicoLitros(){
	cout<<"Teclee la cantidad de cent�metros c�bicos a convertir: ";cin>>fCM3;
	fLitros = fCM3*0.001;
	cout<<"La cantidad de litros equivalentes es: "<<fLitros<<" litros.\n";
}

void vVolumenCentimetroCubicoMililitros(){
	cout<<"Teclee la cantidad de cent�metros c�bicos a convertir: ";cin>>fCM3;
	cout<<"La cantidad de mililitros es equivalente a: "<<fCM3<<" mililitros.\n";
}

void vVolumenMilimetroCubicoLitros(){
	float fMmCubico = 0;
	cout<<"Teclee la cantidad de mililitros a convertir: ";cin>>fMmCubico;
	fLitros = fMmCubico*0.000001;
	cout<<"La cantidad de litros equivalentes es: "<<fLitros<<" litros.\n";
}

void vVolumenLitrosCMCubicos(){
	cout<<"Teclee la cantidad de litros a convertir: ";cin>>fLitros;
	fCM3 = fLitros*1000;
	cout<<"La cantidad de cent�metros c�bicos es: "<<fCM3<<" cm^3.\n";
}

