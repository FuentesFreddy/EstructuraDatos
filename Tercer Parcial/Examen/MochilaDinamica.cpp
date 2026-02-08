#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Elemento {
    int id;
    int valor;
    int peso;
};

// Matriz global para memorización: memo[indice][capacidad]
// Almacena los resultados de subproblemas ya resueltos [cite: 370, 575]
int memo[100][1000]; 

int resolverMochila(vector<Elemento>& elementos, int capacidad, int indice) {
    // Casos Base: No hay más espacio o se acabaron los objetos [cite: 187]
    if (capacidad == 0 || indice == elementos.size()) {
        return 0;
    }

    // Si ya calculamos este subproblema, devolvemos el valor guardado [cite: 391]
    if (memo[indice][capacidad] != -1) {
        return memo[indice][capacidad];
    }

    // Opción A: No incluir el objeto actual
    int beneficioSin = resolverMochila(elementos, capacidad, indice + 1);

    // Opción B: Incluir el objeto actual (si cabe)
    int beneficioCon = 0;
    if (elementos[indice].peso <= capacidad) {
        beneficioCon = elementos[indice].valor + 
                       resolverMochila(elementos, capacidad - elementos[indice].peso, indice + 1);
    }

    // Guardamos y devolvemos el valor máximo entre ambas opciones [cite: 578]
    return memo[indice][capacidad] = max(beneficioSin, beneficioCon);
}

int main() {
    int n, capacidadMax;
    cout << "Limite de peso de la mochila: ";
    cin >> capacidadMax;
    cout << "Numero de elementos disponibles: ";
    cin >> n;

    vector<Elemento> elementos(n);
    for (int i = 0; i < n; i++) {
        elementos[i].id = i + 1;
        cout << "Elemento " << i + 1 << " (Valor Peso): ";
        cin >> elementos[i].valor >> elementos[i].peso;
    }

    // Inicializamos la matriz de memoria con -1 (indica no calculado)
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 1000; j++)
            memo[i][j] = -1;

    int valorMaximo = resolverMochila(elementos, capacidadMax, 0);

    cout << "\n--- Resultados ---" << endl;
    cout << "Valor total obtenido: " << valorMaximo << endl;

    return 0;
}
