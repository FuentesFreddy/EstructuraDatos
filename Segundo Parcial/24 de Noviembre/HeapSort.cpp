#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int mayor = i;
    int izq = 2*i + 1;
    int der = 2*i + 2;

    if (izq < n && arr[izq] > arr[mayor]) mayor = izq;
    if (der < n && arr[der] > arr[mayor]) mayor = der;

    if (mayor != i) {
        swap(arr[i], arr[mayor]);
        heapify(arr, n, mayor);
    }
}

void heapSort(int arr[], int n) {
    // Construir heap máximo
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extraer elementos del heap uno por uno
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);   // Mover raíz al final
        heapify(arr, i, 0);     // Ajustar heap
    }
}

int main() {
    int arr[] = {8, 2, 4, 9, 1};
    int n = 5;

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}