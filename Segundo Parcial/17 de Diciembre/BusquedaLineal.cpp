#include <iostream>
#include <string>

using namespace std;

typedef unsigned int Reproduccion;
typedef std::string Nombre;

struct Cancion {
    Nombre nombreCancion;
    Reproduccion numReproduccion;
};

template <typename T>
struct Nodo {
    T dato;
    Nodo* sig;
};

class Lista {
private:
    Nodo<Cancion>* inicio = NULL;

public:
    // Mantenemos agregar para poder poblar la lista y tener algo que buscar
    void agregarCancion(string nombre, int repros) {
        Nodo<Cancion>* nuevo = new Nodo<Cancion>();
        nuevo->dato.nombreCancion = nombre;
        nuevo->dato.numReproduccion = repros;
        nuevo->sig = nullptr;

        if (inicio == nullptr) {
            inicio = nuevo;
        } else {
            Nodo<Cancion>* aux = inicio;
            while (aux->sig != nullptr) {
                aux = aux->sig;
            }
            aux->sig = nuevo;
        }
    }

    // ESTA ES LA FUNCIONALIDAD PRINCIPAL: BÚSQUEDA LINEAL
    void busquedaLineal(const string& nombreBuscada) {
        Nodo<Cancion>* aux = inicio;
        bool encontrado = false;
        int posicion = 1; // Contador para saber en qué nodo está

        // Recorremos la lista nodo por nodo (Secuencialmente)
        while (aux != nullptr) {
            
            // COMPARACIÓN (El corazón de la búsqueda)
            if (aux->dato.nombreCancion == nombreBuscada) {
                cout << "\n[EXITO] Cancion encontrada:" << endl;
                cout << " - Nombre: " << aux->dato.nombreCancion << endl;
                cout << " - Reproducciones: " << aux->dato.numReproduccion << endl;
                cout << " - Ubicacion: Nodo #" << posicion << endl;
                encontrado = true;
                break; // Terminamos el ciclo porque ya la encontramos
            }

            // Pasamos al siguiente nodo
            aux = aux->sig;
            posicion++;
        }

        if (!encontrado) {
            cout << "\n[FALLO] La cancion '" << nombreBuscada << "' no existe en la lista." << endl;
        }
    }
};

int main() {
    Lista playlist;

    // 1. Agregamos datos manualmente para probar la búsqueda
    playlist.agregarCancion("Bohemian Rhapsody", 5000);
    playlist.agregarCancion("Hotel California", 3200);
    playlist.agregarCancion("Despacito", 9000);
    playlist.agregarCancion("Imagine", 1500);

    // 2. Probamos la Búsqueda Lineal
    string busqueda;
    
    cout << "--- PRUEBA DE BUSQUEDA LINEAL ---" << endl;
    cout << "Ingrese el nombre exacto de la cancion a buscar: ";
    getline(cin, busqueda);

    playlist.busquedaLineal(busqueda);

    return 0;
}
