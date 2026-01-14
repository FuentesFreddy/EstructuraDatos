#include <iostream>
#include <vector>
using namespace std;

struct Elemento{
	int ID;
	int costo;
	int beneficio;
};

void ingresarElementos(vector<Elemento>&elementos, int limite){
	bool seguir = false;
	int i=0;
	char x;
	do{
		Elemento e;
		e.ID=i+1;
		i++;
		cout<< "Ingrese el costo: ";
		cin>> e.costo;
		cout<< "Ingrese el beneficio: ";
		cin>>e.beneficio;
		cout<< "Seguir ingresando?? PRESIONE 1 TECLA: ";
		cin.get(x);
		if(x==1) seguir=true;
	}while(seguir);
}

int main(){
	
	return 0;
}
