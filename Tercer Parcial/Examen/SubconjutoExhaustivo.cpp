#include <iostream>
#include <vector>
using namespace std;

bool buscarSuma(vector<int>& nums, int objetivo, int indice, int sumaActual) {
    // 1. CASO BASE: Si la suma coincide, ¡encontramos la solución!
    if (sumaActual == objetivo) return true;

    // Si ya revisamos todos los números y no sumó el objetivo
    if (indice == nums.size()) return false;

    // 2. EXPLORACIÓN EXHAUSTIVA (Las dos opciones por cada número):
    
    // Opción A: INCLUIR el número actual en la suma
    bool incluir = buscarSuma(nums, objetivo, indice + 1, sumaActual + nums[indice]);

    // Opción B: NO INCLUIR el número actual
    bool excluir = buscarSuma(nums, objetivo, indice + 1, sumaActual);

    // Si cualquiera de las dos opciones nos lleva al éxito, devolvemos true
    return incluir || excluir;
}

int main() {
    vector<int> conjunto = {5, 2, 8};
    int meta = 10;

    if (buscarSuma(conjunto, meta, 0, 0)) {
        cout << "Existe un subconjunto que suma " << meta << endl;
    } else {
        cout << "No existe solucion en el espacio de busqueda." << endl;
    }

    return 0;
}
