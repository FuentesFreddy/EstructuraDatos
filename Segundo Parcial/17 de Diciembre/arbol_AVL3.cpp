/*
ARBOL AVL

Implementación de inserción y eliminación
*/

#include <iostream>
#include <algorithm>
using namespace std;

// =======================
// Estructura del nodo
// =======================
struct Nodo
{
    int dato;
    Nodo *izq;
    Nodo *der;
    int altura;

    Nodo(int v) : dato(v), izq(nullptr), der(nullptr), altura(1) {}
};

// =======================
// Altura
// =======================
int obtenerAltura(Nodo *n)
{
    return n ? n->altura : 0;
}

// =======================
// Factor de balance
// =======================
int factorBalance(Nodo *n)
{
    return n ? obtenerAltura(n->izq) - obtenerAltura(n->der) : 0;
}

// =======================
// Rotaciones
// =======================

// Rotación LL (derecha)
Nodo *rotarDerecha(Nodo *y)
{
    Nodo *x = y->izq;
    Nodo *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = 1 + max(obtenerAltura(y->izq), obtenerAltura(y->der));
    x->altura = 1 + max(obtenerAltura(x->izq), obtenerAltura(x->der));

    return x;
}

// Rotación RR (izquierda)
Nodo *rotarIzquierda(Nodo *x)
{
    Nodo *y = x->der;
    Nodo *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = 1 + max(obtenerAltura(x->izq), obtenerAltura(x->der));
    y->altura = 1 + max(obtenerAltura(y->izq), obtenerAltura(y->der));

    return y;
}

// =======================
// Inserción AVL
// =======================
Nodo *insertar(Nodo *n, int valor)
{
    if (!n)
        return new Nodo(valor);

    if (valor < n->dato)
        n->izq = insertar(n->izq, valor);
    else if (valor > n->dato)
        n->der = insertar(n->der, valor);
    else
        return n; // no duplicados

    n->altura = 1 + max(obtenerAltura(n->izq), obtenerAltura(n->der));
    int fb = factorBalance(n);

    // Casos de rotación
    if (fb > 1 && valor < n->izq->dato)
        return rotarDerecha(n); // LL

    if (fb < -1 && valor > n->der->dato)
        return rotarIzquierda(n); // RR

    if (fb > 1 && valor > n->izq->dato)
    { // LR
        n->izq = rotarIzquierda(n->izq);
        return rotarDerecha(n);
    }

    if (fb < -1 && valor < n->der->dato)
    { // RL
        n->der = rotarDerecha(n->der);
        return rotarIzquierda(n);
    }

    return n;
}

// =======================
// Nodo mínimo (BST clásico)
// =======================
Nodo *minimo(Nodo *r)
{
    while (r->izq)
        r = r->izq;
    return r;
}

// =======================
// Eliminación AVL
// =======================
Nodo *eliminar(Nodo *r, int valor)
{
    if (!r)
        return r;

    // Paso 1: eliminación BST normal
    if (valor < r->dato)
        r->izq = eliminar(r->izq, valor);
    else if (valor > r->dato)
        r->der = eliminar(r->der, valor);
    else
    {
        // Nodo encontrado
        if (!r->izq)
        {
            Nodo *temp = r->der;
            delete r;
            return temp;
        }
        else if (!r->der)
        {
            Nodo *temp = r->izq;
            delete r;
            return temp;
        }

        Nodo *temp = minimo(r->der);
        r->dato = temp->dato;
        r->der = eliminar(r->der, temp->dato);
    }

    // Si el árbol quedó vacío
    if (!r)
        return r;

    // Paso 2: actualizar altura
    r->altura = 1 + max(obtenerAltura(r->izq), obtenerAltura(r->der));

    // Paso 3: balancear
    int fb = factorBalance(r);

    // LL
    if (fb > 1 && factorBalance(r->izq) >= 0)
        return rotarDerecha(r);

    // LR
    if (fb > 1 && factorBalance(r->izq) < 0)
    {
        r->izq = rotarIzquierda(r->izq);
        return rotarDerecha(r);
    }

    // RR
    if (fb < -1 && factorBalance(r->der) <= 0)
        return rotarIzquierda(r);

    // RL
    if (fb < -1 && factorBalance(r->der) > 0)
    {
        r->der = rotarDerecha(r->der);
        return rotarIzquierda(r);
    }

    return r;
}

// =======================
// Recorridos
// =======================
void inorden(Nodo *n)
{
    if (!n)
        return;
    inorden(n->izq);
    cout << n->dato << " ";
    inorden(n->der);
}

void preorden(Nodo *n)
{
    if (!n)
        return;
    cout << n->dato << " ";
    preorden(n->izq);
    preorden(n->der);
}

void postorden(Nodo *n)
{
    if (!n)
        return;
    postorden(n->izq);
    postorden(n->der);
    cout << n->dato << " ";
}

// =======================
// Impresión gráfica
// =======================
void imprimirArbol(Nodo *r, int espacio = 0, int incremento = 5)
{
    if (!r)
        return;

    espacio += incremento;
    imprimirArbol(r->der, espacio);

    cout << endl;
    for (int i = incremento; i < espacio; i++)
        cout << " ";
    cout << r->dato;

    imprimirArbol(r->izq, espacio);
}

// =======================
// Liberar memoria
// =======================
void liberar(Nodo *n)
{
    if (!n)
        return;
    liberar(n->izq);
    liberar(n->der);
    delete n;
}

// =======================
// Programa principal
// =======================
int main()
{
    Nodo *raiz = nullptr;

    raiz = insertar(raiz, 10);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 25);
    raiz = insertar(raiz, 5);
    raiz = insertar(raiz, 4);
    raiz = insertar(raiz, 6);
    raiz = insertar(raiz, 11);
    raiz = insertar(raiz, 7);

    cout << "AVL inicial:\n";
    imprimirArbol(raiz);

    cout << "\n\nInorden: ";
    inorden(raiz);

    cout << "\n\nEliminando 10...\n";
    raiz = eliminar(raiz, 10);

    cout << "\nAVL despues de eliminar:\n";
    imprimirArbol(raiz);

    cout << "\n\nInorden: ";
    inorden(raiz);
    cout << endl;

    liberar(raiz);
    return 0;
}
