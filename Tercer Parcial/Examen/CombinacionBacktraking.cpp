#include <iostream>
#include <vector>

using namespace std;

// Función de Backtracking para encontrar combinaciones que sumen S
void encontrarCombinaciones(int n, int objetivo, int sumaActual, int inicio, vector<int>& combinacion, int& contador) {
    // 1. Verificar si la solución es válida y completa [cite: 788-789, 834-836]
    if (sumaActual == objetivo) {
        cout << "{ ";
        for (int num : combinacion) cout << num << " ";
        cout << "}" << endl;
        contador++;
        return;
    }

    // 2. Explorar cada opción posible (números del 'inicio' al 'n') [cite: 817, 838]
    for (int i = inicio; i <= n; i++) {
        
        // PODA: Si sumar 'i' excede el objetivo, no seguimos por esta rama [cite: 760, 771]
        if (sumaActual + i > objetivo) continue;

        // 3. Agregar opción válida [cite: 819, 842]
        combinacion.push_back(i);

        // 4. Explorar recursivamente el siguiente paso [cite: 820, 844]
        // Pasamos 'i + 1' para no repetir el mismo número [cite: 890]
        encontrarCombinaciones(n, objetivo, sumaActual + i, i + 1, combinacion, contador);

        // 5. Retroceder (Quitar la opción) para probar otra alternativa [cite: 821, 848]
        combinacion.pop_back(); 
    }
}

int main() {
    int n, S;
    cout << "Ingrese el valor maximo (n): ";
    cin >> n;
    cout << "Ingrese el valor objetivo (S): ";
    cin >> S;

    vector<int> combinacion;
    int totalEncontradas = 0;

    cout << "\nCombinaciones validas:\n";
    encontrarCombinaciones(n, S, 0, 1, combinacion, totalEncontradas);

    cout << "\nTotal de combinaciones que cumplen la condicion: " << totalEncontradas << endl;

    return 0;
}
