#include <iostream>
#include <vector>
#include <map>

using namespace std;

// TRUCO PRO: Creamos un alias. 
// Ahora 'Grafo' significa 'map<char, vector<char>>'
using Grafo = map<char, vector<char>>;


void conectar(Grafo& g) {
    char a, b;
    cout << "  [+] Origen -> Destino: ";
    cin >> a >> b;
    g[a].push_back(b); // Crea 'a' si no existe y le añade 'b'
    // g[b]; // Opcional: Esto crea el nodo 'b' sin conexiones para que aparezca en la lista
    cout << "  -> Conexion guardada.\n";
}

void buscar(Grafo& g) {
    char n;
    cout << "  [?] Que nodo buscas?: "; 
    cin >> n;
    // .count es O(log n), muy rapido
    if (g.count(n)) cout << "  -> El nodo '" << n << "' SI existe en el grafo.\n";
    else cout << "  -> El nodo NO existe.\n";
}

void eliminar(Grafo& g) {
    char n;
    cout << "  [-] Nodo a eliminar: "; 
    cin >> n;

    // 1. Intentamos borrar la clave principal
    if (g.erase(n)) { 
        // 2. Si existía, ahora borramos las flechas que apuntaban a él
        for (auto& par : g) {
            vector<char>& vecinos = par.second;
            // Limpieza de vector usando iteradores
            for (auto it = vecinos.begin(); it != vecinos.end(); ) {
                if (*it == n) it = vecinos.erase(it);
                else ++it;
            }
        }
        cout << "  -> Nodo y conexiones eliminados.\n";
    } else {
        cout << "  -> Nodo no encontrado.\n";
    }
}

void mostrar(const Grafo& g) {
    if (g.empty()) {
        cout << "  (El grafo esta vacio)\n";
        return;
    }
    cout << "\n  --- LISTA DE ADYACENCIA ---\n";
    

    for (auto const& par : g) {
        char nodo = par.first;                // El nodo principal (Clave)
        const vector<char>& vecinos = par.second; // Su lista de conexiones (Valor)

        cout << "  [" << nodo << "]";
        for (char v : vecinos) cout << " -> " << v;
        cout << endl;
    }
}

// --- MAIN (CONTROLADOR) ---

int main() {
    Grafo miGrafo; // Gracias al alias, esto se ve muy limpio
    int op;

    do {
        cout << "\n========== MENU GRAFO ==========\n"
             << "1. Agregar Conexion (Insertar)\n"
             << "2. Buscar Nodo\n"
             << "3. Eliminar Nodo\n"
             << "4. Mostrar Grafo\n"
             << "5. Salir\n"
             << "================================\n"
             << "Opcion: ";
        cin >> op;

        switch (op) {
            case 1: conectar(miGrafo); break;
            case 2: buscar(miGrafo); break;
            case 3: eliminar(miGrafo); break;
            case 4: mostrar(miGrafo); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (op != 5);

    return 0;
}