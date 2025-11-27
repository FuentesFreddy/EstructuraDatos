#include <iostream>
using namespace std;

void insertion(int vector[],int n){
    for(int i=1; i<n ; i++){ // hasta n porque debe iterar todos los elementos 
        int clave = vector[i]; //clave es el valor actual
        int j = i-1; //j se ubica una posicion antes del elemento clave para iterar
        while(j>=0 && vector[j]>clave){ //repetir hasta que llegue al inicio del vector y la posicion izquierda sea mayor que el actual
            vector[j+1] = vector[j]; //hacemos hueco
            j--; //recorro hacia atras
        }
        vector[j+1] = clave;
    }
}

void mostrar(int vector[],int n){
    for(int i=0; i<n; i++){
        cout<< vector[i]<<" ";
    }
}

int main(){
    int vector[] = {1,2,3,5,5,79,0,5,87,6,1,74,9,54,32,4,96,25,5,6,2,9,87,25,1,6,85,0};
    int n = sizeof(vector)/sizeof(int);
    mostrar(vector,n);
    insertion(vector,n);
    cout<<endl;
    mostrar(vector,n);
}