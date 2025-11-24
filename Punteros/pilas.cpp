#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int data;
	Nodo* siguiente;
};

//pila siempre tiene que apuntar a la cima 
void ingresarPila(Nodo*& pila ,int dato){
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->data = dato;
	nuevoNodo->siguiente= pila;
	pila = nuevoNodo;
}

void sacarPila(Nodo*& pila, int& n){
	Nodo* aux = pila;
	n = aux->data;
	pila = aux->siguiente;
	delete aux;
}

int main(){
	Nodo* pila = nullptr;
	int valor;
	for(int i=0 ; i<10; i++){
		cout<< "Ingrese elemento de la pila: ";
		cin>> valor;
		ingresarPila(pila,valor);
	}
	
	while (pila!=nullptr){ // mientras no sea el final d ela pila
		sacarPila(pila,valor);
		if(pila!=nullptr){
			cout<< valor << " -> ";
		}else{
			cout<< valor << "FIN"<< endl;
		}
	}
}
