#include <conio.h>
#include <iostream>
#include <vector>
using namespace std;

void busquedaBinaria(vector<int> arr, int dato){
	int sup = arr.size();
	int inf = 0;
	int mitad;
	bool bandera = false;
	
	//Busqueda bianria 
	while(inf<=sup){
		mitad = (inf+sup)/2;
		
		if(arr[mitad]==dato){
			bandera = true;
			break;
		}else if(arr[mitad]>dato){
			sup = mitad;
			mitad = (inf+sup)/2;
		}else if(arr[mitad]<dato) {
			inf = mitad;
			mitad = (inf+sup)/2;
		}
	}
	if(bandera) cout<< "El numero ha sido encontrado en la posicion: "<< mitad<<endl;
	if(!bandera) cout<< "El numero no ha sido encontrado \n";
}

int main(){
	vector<int> arr = {1,2,3,4,5,6,7,8,9};
	busquedaBinaria(arr,7);
	return 0;
}

