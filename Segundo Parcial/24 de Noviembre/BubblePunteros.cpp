#include <iostream>
using namespace std;


void mapa(int n, int* vectorpunteros[], int vectorObjetos[]){
    for(int i=0 ; i<n; i++){
        vectorpunteros[i] = &vectorObjetos[i];
    }
}

void Burbuja(int* vectorpunteros[],int n){
    for(int i=0; i<n- 1; i++){
        bool intercambio = false;
        for(int j=0; j<n-1-i; j++){
            if(*vectorpunteros[j] >*vectorpunteros[j+1]){ //comparamos con * el valor al que apuntan los punteros
                swap(vectorpunteros[j],vectorpunteros[j+1]);
                intercambio = true;
            }
        }
        if(!intercambio) break;
    }
}

void mostrar(int* vector[],int n){
    for(int i=0; i<n; i++){
        cout<< *vector[i]<<" ";
    }
}

int main(){
    int vector[] = {1,2,3,5,5,79,0,5,87,6,1,74,9,54,32,4,96,25,5,6,2,9,87,25,1,6,85,0};
    int n = sizeof(vector)/sizeof(int);
    int* punteros[n];
    mapa(n,punteros,vector); //Asignamos a vector de punteros la direccion de memoria de cada valor
    cout<<"Arreglo desordenado \n";
    mostrar(punteros,n); //mostramos el areglo original
    cout<<"\nArreglo ordenado \n";
    Burbuja(punteros,n); // ordenamos las posiciones de los punteros en funcion a los valores que apuntan
    mostrar(punteros,n); //Mostramos los valores en funcion al orden de los punteros e ingresando a los valores que miran
    return 0;
}