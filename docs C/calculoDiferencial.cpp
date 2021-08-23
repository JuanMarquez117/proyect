#include<iosteam>
using namespace std;

int main(void){
	menu();
}

void menu(){
	do{
		cout<<"Teclee la opcion que requiera: \n";
		cout<<"1. Inecuaciones.\n";
		cout<<"\n0. Salir\n";
		switch(opc){
			case 1:
				inecuaciones();
				break;
			case 0:
				break;
			default:
				cout<<"Esa opcion no existe.\n";
				break;
		}
	}while(opc!=0);
}
