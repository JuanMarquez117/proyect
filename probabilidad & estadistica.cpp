#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include"libreria.h"
using namespace std;

//variables globales
int tamanio = 50; //tamaño del vector
int i,j;  //iteradores.
int longitudMayor;
int cantidadDeGrupos = 1;

//prototipos de funcion.
void lecturaDeDatos();
void salidaDeDatos();
void sacarMedia();
void sacarMediana();
void sacarModa();
void sacarVarianza();
void sacarDesviacionEstandar();
void sacarRango();

struct cuadroDeDatos{
	string nombre;
	float dato[50];  //vector para los datos.
	float media;
	float mediana;
	float moda;
	float varianza;
	float desviacionEstandar;
	float rango;
	int longitud;	//logitud usada total del vector dato[].
}grupo[10];

//funcion principal.
int main(void){
	cout<<"Este programa calcula las tablas de probabilidad y estadistica.\n";
	cout<<"media (promedio), mediana, moda, varianza, desviacion estandar y rango\n\n\n";
	lecturaDeDatos();
	sacarMedia();
	sacarVarianza();
	sacarDesviacionEstandar();
	salidaDeDatos();
}

//declaraciones de funciones.
void lecturaDeDatos(){
	fflush(stdin);
	cout<<"Teclee la cantidad de grupos a calcular: ";cin>>cantidadDeGrupos;	
		for(j=0;j<cantidadDeGrupos;j++){
			fflush(stdin);
			cout<<"Escriba el nombre del grupo: ";
			getline(cin,grupo[j].nombre);
		}
	for(i=0;i<cantidadDeGrupos;i++){
		fflush(stdin);
		grupo[i].longitud = 0;
		cout<<"Teclee los datos para "<<grupo[i].nombre<<" (0 para terminar):\n";
		for(j=0;j<tamanio;j++){  //lectura de datos float.
			grupo[i].dato[j] = 0;
			cin>>grupo[i].dato[j];
			grupo[i].longitud+=1;
			if(grupo[i].dato[j]==0){ //0 para terminar (y no contar el 0).
				grupo[i].longitud--;
				break;
			}
			if(longitudMayor<grupo[i].longitud){		
				longitudMayor = grupo[i].longitud;
			}
		}
	}
}

void salidaDeDatos(){
	for(i=0;i<cantidadDeGrupos;i++){
		
		cout<<"media "<<grupo[i].nombre<<": "<<grupo[i].media<<"\n";
		cout<<"varianza "<<grupo[i].nombre<<": "<<grupo[i].varianza<<"\n";
		cout<<"desviacion estandar "<<grupo[i].nombre<<": "<<grupo[i].desviacionEstandar<<"\n";
		cout<<"\n";	
	}
}

void sacarMedia(){
	float suma;
	for(i=0;i<cantidadDeGrupos;i++){
		suma = 0;
		for(j=0;j<longitudMayor;j++){
			suma += grupo[i].dato[j];
		}
	grupo[i].media = suma/grupo[i].longitud;
	}
}

void sacarVarianza(){
	float suma;
	for(i=0;i<cantidadDeGrupos;i++){
		suma = 0;
		for(j=0;j<grupo[i].longitud;j++){
			suma += pow(grupo[i].dato[j]-grupo[i].media,2);
		}
	grupo[i].varianza = suma/(grupo[i].longitud-1);
	}
}

void sacarDesviacionEstandar(){
	for(i=0;i<cantidadDeGrupos;i++){
		grupo[i].desviacionEstandar = sqrt(grupo[i].varianza);
	}
}

