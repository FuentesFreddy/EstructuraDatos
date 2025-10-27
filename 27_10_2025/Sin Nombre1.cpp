#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main(){
	vector<int> numeros = {5, 10, 15, 20};
	
	try{
		cout<< "Elemento en posicion dos: "<< numeros.at(2)<< endl;
		cout<< "Elemento en posicion diez: "<< numeros.at(10)<< endl;
	}catch(const out_of_range& e){
		cout<< "Error: "<< e.what()<< endl;
	}
	return 0;
}

