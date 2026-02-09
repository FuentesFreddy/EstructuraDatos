#include <iostream>
#include <vector>
#include <chrono> // Para medir el tiempo exacto

using namespace std;
using namespace std::chrono;

// 1. Enfoque Recursivo Simple (Complejidad Exponencial: O(2^n)) [cite: 278]
// Muy ineficiente porque recalcula subproblemas muchas veces [cite: 265, 297]
long long fiboRecursivo(int n) {
    if (n <= 1) return n;
    return fiboRecursivo(n - 1) + fiboRecursivo(n - 2);
}

// 2. Enfoque Programación Dinámica (Complejidad Lineal: O(n)) [cite: 278, 644]
// Almacena resultados en una tabla para evitar cálculos repetidos [cite: 286, 292, 298]
long long fiboDinamico(int n) {
    if (n <= 1) return n;
    vector<long long> dp(n + 1); // Tabla dp para resultados intermedios [cite: 287, 306]
    dp[0] = 0; // Caso base 1 [cite: 288, 307]
    dp[1] = 1; // Caso base 2 [cite: 308]
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // Combinación de subproblemas [cite: 290, 310]
    }
    return dp[n];
}

void medirTiempo(int n) {
    cout << "--- Analizando n = " << n << " ---" << endl;

    // Medir Dinámico
    auto start = high_resolution_clock::now();
    long long resD = fiboDinamico(n);
    auto end = high_resolution_clock::now();
    auto durationD = duration_cast<microseconds>(end - start);
    cout << "Dinamico: " << resD << " | Tiempo: " << durationD.count() << " us" << endl;

    // Medir Recursivo (Solo si n es pequeño, sino tardaria años)
    if (n <= 40) {
        start = high_resolution_clock::now();
        long long resR = fiboRecursivo(n);
        end = high_resolution_clock::now();
        auto durationR = duration_cast<microseconds>(end - start);
        cout << "Recursivo: " << resR << " | Tiempo: " << durationR.count() << " us" << endl;
    } else {
        cout << "Recursivo: Omitido (demasiado lento por complejidad exponencial)" << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el valor de n para comparar complejidad: ";
    cin >> n;
    medirTiempo(n);
    return 0;
}
