#include <iostream>
#include <vector>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para inicializar la semilla de rand()
#include <algorithm> // Para swap, aunque std::swap funciona

using namespace std;

// Prototipo de la función particion
int particion(vector<int>& arr, int inicio, int final);

void quickSort(vector<int>& arr, int inicio, int final){
    if(inicio < final){
        int pivote_idx = particion(arr, inicio, final);
        quickSort(arr, inicio, pivote_idx - 1); // Mitad izquierda
        quickSort(arr, pivote_idx + 1, final); // Mitad derecha
    }
}

int particion(vector<int>& arr, int inicio, int final){
    int pivote = arr[inicio];
    int i = inicio + 1;
    for(int j = i; j <= final; j++){
        if(arr[j] < pivote){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[inicio], arr[i - 1]);
    return i - 1;
}

void ingresarAleatorio(vector<int>& arr, int cantidad){
    // Redimensionar el vector al tamaño deseado
    arr.resize(cantidad); 
    for(int i = 0; i < cantidad; i++){
        arr[i] = rand() % 100;
    }
}

void mostrar(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl; // Agregar un salto de línea al final para mejor visualización
}

int main(){
    // Inicializar la semilla para números aleatorios
    srand(time(0)); 

    vector<int> mi_vector; // Cambiado el nombre de la variable
    int num_elementos = 10000; // Reducido a 20 para que la salida sea legible

    ingresarAleatorio(mi_vector, num_elementos);
    cout << "Vector antes de ordenar:" << endl;
    mostrar(mi_vector);

    // Corregida la llamada: el índice final es size() - 1
    quickSort(mi_vector, 0, mi_vector.size() - 1); 

    cout << "Vector despues de ordenar:" << endl;
    mostrar(mi_vector);

    return 0;
}
