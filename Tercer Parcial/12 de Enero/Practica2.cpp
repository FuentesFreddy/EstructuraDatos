#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Para std::swap

using namespace std;

// Función de backtracking para generar permutaciones
void generarPermutaciones(string& str, int l, int r) {
    // Caso base: si hemos llegado al final de la cadena (un nivel de profundidad completo)
    if (l == r) {
        cout << str << endl; // Imprime la permutación completa
    } else {
        // Iterar a través de los caracteres desde la posición actual 'l' hasta 'r'
        for (int i = l; i <= r; i++) {
            // 1. Elección: Intercambiar el carácter actual con el de la posición 'l'
            swap(str[l], str[i]);

            // 2. Exploración: Llamada recursiva para el resto de la cadena (desde l+1)
            generarPermutaciones(str, l + 1, r);

            // 3. Retroceso (Backtrack): Deshacer el swap para restaurar la cadena original
            // Esto permite probar otras opciones en el bucle 'for'
            swap(str[l], str[i]);
        }
    }
}

int main() {
    string cadena = "ABC";
    int n = cadena.length();
    cout << "Permutaciones de '" << cadena << "':" << endl;
    generarPermutaciones(cadena, 0, n - 1); // Iniciar desde el índice 0
    return 0;
}

