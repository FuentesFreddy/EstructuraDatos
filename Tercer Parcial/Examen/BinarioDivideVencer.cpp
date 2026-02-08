#include <iostream>
#include <vector>

using namespace std;

// Implementación de Búsqueda Binaria (Divide y Vencerás)
int busquedaBinaria(vector<int>& arr, int inicio, int fin, int objetivo) {
    // 1. Caso Base: El rango de búsqueda está vacío [cite: 187-188, 194]
    if (inicio > fin) {
        return -1; // No se encontró el elemento
    }

    // 2. Etapa de Dividir: Calculamos el punto medio [cite: 66-78]
    // Usamos esta fórmula para evitar desbordamientos de memoria
    int medio = inicio + (fin - inicio) / 2; 

    // 3. Etapa de Vencer (Resolver): 
    // Caso Base 2: ¿El elemento está justo en el medio?
    if (arr[medio] == objetivo) {
        return medio; // ¡Lo encontramos! [cite: 188]
    }

    // Decidimos qué "subproblema" resolver y descartamos la otra mitad
    if (arr[medio] > objetivo) {
        // Vencer: Buscar en la mitad izquierda
        return busquedaBinaria(arr, inicio, medio - 1, objetivo); [cite: 79]
    } else {
        // Vencer: Buscar en la mitad derecha
        return busquedaBinaria(arr, medio + 1, fin, objetivo); [cite: 79]
    }
}

int main() {
    // Nota: El arreglo DEBE estar ordenado para que funcione
    vector<int> datos = {3, 9, 10, 27, 38, 43, 82}; 
    int buscar = 43;
    int n = datos.size();

    int resultado = busquedaBinaria(datos, 0, n - 1, buscar);

    if (resultado != -1) {
        cout << "Elemento encontrado en el índice: " << resultado << endl;
    } else {
        cout << "Elemento no presente en el arreglo." << endl;
    }

    return 0;
}
