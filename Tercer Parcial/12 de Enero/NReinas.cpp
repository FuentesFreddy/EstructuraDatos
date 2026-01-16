#include <iostream>
using namespace std;

const int N =8;
int tablero[N];

bool esSeguro(int fila, int columna){
	for(int i=0;i<fila;i++){
		if(tablero[i]==columna || tablero[i]-i==columna-fila || tablero[i]+i==columna+fila) return false;
	}
	return true;
}

void resolverReinas(int fila){
	if(fila==N){
		for(int i=0; i<N; i++){
			cout<< tablero[i]<<" ";
		}
		cout<< endl;
		return;
	}
	
	for(int col=0; col<N; col++){
		if(esSeguro(fila,col)){
			tablero[fila]= col;
			resolverReinas(fila+1);
		}
	}
}

int main(){
	resolverReinas(0);
	return 0;
}


