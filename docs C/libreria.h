#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<cString>
using namespace std;

//da la bienvenida a los programas.
void bienvenida(){
	cout<<"\n\t\t\t\t\t\t";
	cout<<"Bienvenido al programa.\n\n";
}

//intercambia valores numericos.
template <class T>
void intercambioValores(T &x,T &y){
	T aux=0,*punterox=&x,*punteroy=&y;
	aux=*punterox;
	*punterox=*punteroy;
	*punteroy=aux;
}

//saca factorial de un numero.
int factorial(int num){
	int resultado=1,i;
	for(i=1;i<=num;i++){
		resultado*=i;
	}
	return resultado;
}

//lleva el apuntador a las coordenadas puestas.
void gotoxy(int x,int y){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);
}

char enteroACaracter(int numero){
	return numero + '0';
}
