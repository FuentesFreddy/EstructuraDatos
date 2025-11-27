#include <iostream>
#include <string>
using namespace std;

struct Nodo{
    int id;
    Nodo* next;
};

void listaSimple(Nodo*& cabeza, int n){
    Nodo* nuevoNodo = new Nodo(); //puntero tiene direccion de nevo nodo 
    nuevoNodo->id = n;
    nuevoNodo->next = cabeza;
    cabeza = nuevoNodo;
}

void mostrarLista(Nodo*& cabeza){
    Nodo* exp = cabeza;
    while(exp!=nullptr){
        cout<< exp->id<<" ";
        exp = exp->next;
    }
    cout<<endl;
}

int tamanioLista(Nodo*& cabeza){
    int contador = 0;
    Nodo* actual = cabeza; //el nodo actuial apunta al principio
    while(actual!=nullptr){
        contador++;
        actual = actual->next;
    }
    return contador;
}

void insertion(Nodo*& cabeza){
    Nodo* clave = cabeza->next; // clave apunta al nodo siguiente 
    Nodo* ultOrdenado = cabeza; // ult apunta al primer nodo porque es el unico ordenado a la izquierda 
    int comparaciones = 0;
    while(clave!=nullptr){
        if(ultOrdenado->id<=clave->id){ //caso facil
            ultOrdenado = clave;
            clave = clave->next;
        }else if(clave->id<cabeza->id){
            ultOrdenado->next = clave->next; // clave se desconecta de la lista
            clave->next = cabeza; // el puntero de clave apunta a lo que apunta cabeza 
            cabeza = clave; // cabeza es clave 
            clave = ultOrdenado->next;
        }else{ // clave se inserta en un lugar intermedio
            Nodo* anterior = cabeza;
            Nodo* temp = cabeza->next;
            while(temp->id<clave->id){ // iterar para ubicar punteros correctamente
                anterior = temp; // anterior le esta siguiendo a temp
                temp = temp->next; //temporal apunta a siguiente
                comparaciones++;
            } // tem es mayor que clave y anterior es menor que clave (clave va en medio)
            ultOrdenado->next = clave->next; 
            clave->next = temp; 
            anterior->next = clave;
            clave = ultOrdenado->next;
        }
        mostrarLista(cabeza);
        cout<<endl;
    }
}

int main() {
    Nodo* cabeza = nullptr;
    
    // Lista de 20 números aleatorios
    int datos[] = {45, 12, 8, 33, 1, 99, 2, 15, 7, 22, 60, 4, 19, 88, 5, 10, 3, 25, 14, 6};
    
    // Insertamos en la lista (quedarán en orden inverso al array, pero sigue siendo aleatorio)
    for(int i = 0; i < 20; i++) {
        listaSimple(cabeza, datos[i]);
    }

    cout << "Lista Inicial Desordenada: ";
    mostrarLista(cabeza);
    cout << "\n\n";

    insertion(cabeza);

    return 0;
}