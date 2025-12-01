#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int>& arrDere, vector<int>& arrIzq){
    vector<int> resultado; //guarda vector ordenado 
    int i = 0; // iterador izq
    int j = 0; // iterador dere
    while(arrIzq.size()>i && arrDere.size()>j){
        if(arrDere[j]>arrIzq[i]){
            resultado.push_back(arrIzq[i]);
            i++; // avanzamos uno 
        }else{
            resultado.push_back(arrDere[j]);
            j++;
        }
    }
    //elemetos sobrantes que deben posicionarse tal como estan
    while(arrIzq.size()>i){
        arrIzq.push_back(arrIzq[i]);
        i++;
    }
    while(arrDere.size()>j){
        arrDere.push_back(arrDere[j]);
        j++;
    }
    return resultado;
}


vector<int> mergeSort(vector<int>& arr){
    // definir caso baso cuando no puedes dividir mas 
    if(arr.size()==1) return arr;

    int medio = arr.size()/2;
    // del inicio mas medio posiciones; divido arreglos
    vector<int> arrIzq(arr.begin(),arr.begin()+medio);
    vector<int> arrDere(arr.begin()+medio,arr.end());

    //areglar vecotres divididos 
    arrDere = mergeSort(arrDere);
    arrIzq = mergeSort(arrIzq);
    //junto arreglos ordenados 
    return merge(arrIzq,arrDere);
}

int main() {
    vector<int> nums = {38, 27, 43, 3, 9, 82, 10};
    
    mergeSort(nums);

    cout << "Arreglo ordenado: ";
    for(auto const n : nums) {
        cout << n << " ";
    }
    return 0;
}