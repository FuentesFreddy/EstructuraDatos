#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main(){
	vector<int> numeros = {5, 10, 15, 20};
	
	try{
		for(int i=0; i<= numeros.size(); i++){
			cout<< ""
		}
	}catch(const std::out_of_range& e){
		cout<< "Error: "<< e.what()<< endl;
	}
	return 0;
}

