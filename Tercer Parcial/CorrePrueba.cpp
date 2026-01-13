#include <iostream>
#include <vector>
using namespace std;

bool encontrarSuma(vector<int>& numeros, int objetivo, int indice, vector<int>& combinacion) {
    // 1. Casos base
    if (objetivo == 0) return true;
    if (indice == numeros.size() || objetivo < 0) return false;

    // 2. Opción A: Incluir el número actual
    combinacion.push_back(numeros[indice]); 
    if (encontrarSuma(numeros, objetivo - numeros[indice], indice + 1, combinacion)) {
        return true; 
    }

    // 3. Opción B: No incluir el número (Backtracking)
    combinacion.pop_back(); // Lo sacamos de la combinación porque no funcionó
    return encontrarSuma(numeros, objetivo, indice + 1, combinacion);
}

int main() {
    unsigned int n, objetivo;
    cout << "Introduce la cantidad de números: ";
    cin >> n;

    vector<int> numeros(n);
    cout << "Introduce los números: ";
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    cout << "Introduce el valor objetivo: ";
    cin >> objetivo;

    vector<int> resultado;
    
    // Llamada inicial
    if (encontrarSuma(numeros, objetivo, 0, resultado)) {
        cout << "¡Combinación encontrada!: ";
        for (int x : resultado) cout << x << " ";
        cout << endl;
    } else {
        cout << "No es posible formar ese valor." << endl;
    }

    return 0;
}
