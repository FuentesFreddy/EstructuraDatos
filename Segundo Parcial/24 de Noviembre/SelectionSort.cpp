#include <iostream>
using namespace std;

void selection(int vector[],int n){
    for(int i =0; i<n-2; i++){
        int minimo = i; //minimo en funcion de la iteracion i
        for(int j=i+1; j<n;j++){ // j empieza despues de i osea el siguiente
            if(vector[j]<vector[minimo]){
                minimo= j;
            }
        }
        swap(vector[i],vector[minimo]);
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
    cout<< n<<"\n";
    cout<<"Arreglo desordenado \n";
    mostrar(vector,n);
    selection(vector,n); cout<<endl;
    mostrar(vector,n);
}