#include <iostream>
#include <vector>
using namespace std;

vector<int> encontrarCombinacion(int parametro, vector<int>arr, int indice, int suma, vector<int>combinacion){
	
	if(parametro==suma) return combinacion;
	if(arr.size()==indice) cout<< "No hay combinacion posible!!\n";
	
	encontrarCombinacion(parametro, arr, indice+1, suma + arr[indice], combinacion);
	
	encontrarCombinacion(parametro, arr, indice+1, suma, combinacion);
}

int main(){
	vector<int>arr = {2,5,4};
	encontrarCombinacion(10,arr,0,0);
	return 0;
}




#include <iostream>
#include <vector>

using namespace std;

// Usamos "vector<int>&" (paso por referencia) para que todas las llamadas 
// compartan el mismo vector y sea más eficiente [cite: 93-96].
bool encontrarCombinacion(int parametro, vector<int>& arr, int indice, int suma, vector<int>& combinacion) {
    
    // 1. CASO BASE: Verificar si cumple la condición [cite: 122-124].
    if (suma == parametro) {
        return true; // ¡Solución encontrada! 
    }

    // 2. CASO BASE: Si llegamos al final sin éxito [cite: 131-135].
    if (indice == arr.size()) {
        return false;
    }

    // --- OPCIÓN A: INCLUIR el elemento actual ---
    // Generamos una posible solución agregando el número [cite: 120-121].
    combinacion.push_back(arr[indice]); 
    
    // Verificamos si este camino nos lleva a la meta.
    if (encontrarCombinacion(parametro, arr, indice + 1, suma + arr[indice], combinacion)) {
        return true; 
    }

    // --- PASO DE "DESHACER" (Backtracking) ---
    // Si el camino de arriba no funcionó, quitamos el último elemento 
    // para "limpiar" el vector antes de probar la siguiente posibilidad .
    combinacion.pop_back();

    // --- OPCIÓN B: NO INCLUIR el elemento actual ---
    // Probamos la siguiente posibilidad sin sumar el número actual [cite: 129-130].
    return encontrarCombinacion(parametro, arr, indice + 1, suma, combinacion);
}

int main() {
    vector<int> arr = {2, 5, 4, 8};
    int meta = 10;
    vector<int> resultado;

    // Llamada inicial
    if (encontrarCombinacion(meta, arr, 0, 0, resultado)) {
        cout << "Combinacion encontrada: ";
        for (int n : resultado) cout << n << " ";
        cout << endl;
    } else {
        cout << "No hay combinacion posible en este espacio de busqueda." << endl;
    }

    return 0;
}
