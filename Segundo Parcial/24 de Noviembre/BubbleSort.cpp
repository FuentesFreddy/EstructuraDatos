#include <iostream>
using namespace std;

void Burbuja(int vector[],int n){
    for(int i=0; i<n- 1; i++){
        bool intercambio = false;
        for(int j=0; j<n-1-i; j++){
            if(vector[j]>vector[j+1]){
                swap(vector[j],vector[j+1]);
                intercambio = true;
            }
        }
        if(!intercambio) break;
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
    cout<<"\nArreglo ordenado \n";
    Burbuja(vector,n);
    mostrar(vector,n);
    return 0;
}