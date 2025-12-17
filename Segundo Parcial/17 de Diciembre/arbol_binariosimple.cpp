// ARBOL BINARIO SIMPLE

#include <iostream>
#include <string>
using namespace std;

// Nodo (arbol binario)
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;

    Nodo(int v) : dato(v), izq(nullptr), der(nullptr) {} 
};

// RECORRIDOS

/*
Preorden:
root -> left -> right
sirve para copiar arboles
*/

void preorden(Nodo* r) {

    //Caso base
    if (!r) return;

    cout << r->dato << " ";
    preorden(r->izq);
    preorden(r->der);
}

/*
Inorden:
left -> root -> right
sirve para ver el orden en arboles BST
*/

void inorden(Nodo* r) {

    if (!r) return;

    inorden(r->izq);
    cout << r->dato << " ";
    inorden(r->der);
}

/*
Postorden:
left -> right -> root
sirve para eliminar el arbol
*/

void postorden(Nodo* r) {

    if (!r) return;

    postorden(r->izq);
    postorden(r->der);
    cout << r->dato << " ";
}

// Impresión gráfica (se lo imprimer rotado 90 grados a la izq. por facilidad)

void imprimirArbol(Nodo* r, int espacio, int incremento = 5) {
    //Caso base
    if (!r) return;

    espacio += incremento;

    // Primero el subárbol derecho
    imprimirArbol(r->der, espacio);

    // Imprimir el nodo actual
    cout << endl;
    for (int i = incremento; i < espacio; i++)
        cout << " ";
    cout << r->dato;

    // Luego el subárbol izquierdo
    imprimirArbol(r->izq, espacio);
}

// Liberar memoria (postorden)

void liberar(Nodo* r) {
    if (!r) return;
    
    liberar(r->izq);
    liberar(r->der);
    delete r;  
}


// Programa principal

int main() {

    // Creación manual del árbol
    Nodo* raiz = new Nodo(2);
    raiz->izq = new Nodo(1);
    raiz->der = new Nodo(4);
    raiz->der->izq = new Nodo(3);
    raiz->der->der = new Nodo(5);

    /*
            2
           / \
          1   4
             / \
            3   5
    */

    cout << "Arbol graficamente:\n";
    imprimirArbol(raiz, 0);

    cout << "\n\nPreorden: ";
    preorden(raiz);

    cout << "\nInorden: ";
    inorden(raiz);

    cout << "\nPostorden: ";
    postorden(raiz);

    liberar(raiz);
    return 0;
}

