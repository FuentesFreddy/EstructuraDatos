/*
ARBOL BST
Con menu interactivo usando clase
*/

#include <iostream>
using namespace std;

class BST {
private:
    struct Nodo {
        int dato;
        Nodo* izq;
        Nodo* der;

        Nodo(int v) : dato(v), izq(nullptr), der(nullptr) {}
    };

    Nodo* raiz;

    // =======================
    // Métodos internos
    // =======================
    Nodo* insertar(Nodo* r, int valor) {
        if (!r) return new Nodo(valor);

        if (valor < r->dato)
            r->izq = insertar(r->izq, valor);
        else if (valor > r->dato)
            r->der = insertar(r->der, valor);

        return r;
    }

    bool buscar(Nodo* r, int valor) const {
        if (!r) return false;
        if (valor == r->dato) return true;
        if (valor < r->dato) return buscar(r->izq, valor);
        return buscar(r->der, valor);
    }

    Nodo* minimo(Nodo* r) {
        while (r->izq) r = r->izq;
        return r;
    }

    Nodo* eliminar(Nodo* r, int valor) {
        if (!r) return r;

        if (valor < r->dato)
            r->izq = eliminar(r->izq, valor);
        else if (valor > r->dato)
            r->der = eliminar(r->der, valor);
        else {
            if (!r->izq) {
                Nodo* temp = r->der;
                delete r;
                return temp;
            }
            if (!r->der) {
                Nodo* temp = r->izq;
                delete r;
                return temp;
            }

            Nodo* temp = minimo(r->der);
            r->dato = temp->dato;
            r->der = eliminar(r->der, temp->dato);
        }
        return r;
    }

    void preorden(Nodo* r) const {
        if (!r) return;
        cout << r->dato << " ";
        preorden(r->izq);
        preorden(r->der);
    }

    void inorden(Nodo* r) const {
        if (!r) return;
        inorden(r->izq);
        cout << r->dato << " ";
        inorden(r->der);
    }

    void postorden(Nodo* r) const {
        if (!r) return;
        postorden(r->izq);
        postorden(r->der);
        cout << r->dato << " ";
    }

    void imprimirArbol(Nodo* r, int espacio, int inc = 5) const {
        if (!r) return;

        espacio += inc;
        imprimirArbol(r->der, espacio);

        cout << endl;
        for (int i = inc; i < espacio; i++) cout << " ";
        cout << r->dato;

        imprimirArbol(r->izq, espacio);
    }

    void liberar(Nodo* r) {
        if (!r) return;
        liberar(r->izq);
        liberar(r->der);
        delete r;
    }

public:
    BST() : raiz(nullptr) {}
    ~BST() { liberar(raiz); }

    // =======================
    // Interfaz pública
    // =======================
    void insertar(int valor) { raiz = insertar(raiz, valor); }
    bool buscar(int valor) const { return buscar(raiz, valor); }
    void eliminar(int valor) { raiz = eliminar(raiz, valor); }

    void mostrarArbol() const { imprimirArbol(raiz, 0); }

    void mostrarRecorridos() const {
        cout << "Preorden: ";
        preorden(raiz);
        cout << "\nInorden: ";
        inorden(raiz);
        cout << "\nPostorden: ";
        postorden(raiz);
        cout << endl;
    }
};

// =======================
// Programa principal
// =======================
int main() {
    BST arbol;
    int opcion, valor;

    do {
        cout << "\n===== MENU BST =====\n";
        cout << "1. Insertar valor\n";
        cout << "2. Buscar valor\n";
        cout << "3. Eliminar valor\n";
        cout << "4. Mostrar arbol\n";
        cout << "5. Mostrar recorridos\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                arbol.insertar(valor);
                break;

            case 2:
                cout << "Ingrese valor: ";
                cin >> valor;
                cout << (arbol.buscar(valor) ? "Encontrado\n" : "No encontrado\n");
                break;

            case 3:
                cout << "Ingrese valor: ";
                cin >> valor;
                arbol.eliminar(valor);
                break;

            case 4:
                cout << "\nArbol graficamente:\n";
                arbol.mostrarArbol();
                cout << endl;
                break;

            case 5:
                arbol.mostrarRecorridos();
                break;

            case 0:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 0);

    return 0;
}
