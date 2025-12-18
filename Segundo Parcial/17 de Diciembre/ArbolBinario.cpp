#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* izq;
    Nodo* dere;
    Nodo* padre;
};

Nodo* crearNodo(int , Nodo* );
void insertar(Nodo*&, int , Nodo* );
void mostrar(Nodo* , int );
bool buscar(Nodo* , int );
void preOrden(Nodo* );
void inOrden(Nodo* );
void posOrden(Nodo* );
Nodo* minimo(Nodo* );
void destruirNodo(Nodo* );
void eliminarNodo(Nodo* );
void eliminar(Nodo*&, int );


int main(){
    Nodo* arbol = nullptr;
    int opcion;
    int dato;
    int contador = 0;
    int n;
    for(auto a: {10, 5, 15, 3, 7, 12, 18}){
        insertar(arbol,a,nullptr);
    }

    do{
        cout<< "\nIngrese una opcion\n";
        cout<< "1. Ingresar datos al arbol\n";
        cout<< "2. Mostrar datos al arbol\n";
        cout<< "3. Buscar elemento en el arbol\n";
        cout<< "4. Imprimir datos en pre orden\n";
        cout<< "5. Imprimir datos en in orden\n";
        cout<< "6. Imprimir datos en pos orden\n";
        cout<< "7. Eliminar nodo del arbol \n";
        cout<< "8. Salir\n";
        cin>>opcion;
        switch(opcion){
            case 1:
            int parada;
                do{
                    cout<< "Ingresar un dato: ";
                    cin>>dato;
                    insertar(arbol,dato,nullptr);
                    cout<< "Ingrese 1 para seguir ingresando 0 para salir: ";
                    cin>> parada;   
                }while(parada!=0);   
            break;
            case 2:
                mostrar(arbol,contador);
            break;
            case 3:
                cout<< "Ingrese el numero a buscar: ";
                cin>>n;
                if(buscar(arbol,n)==true){
                    cout<<"Elemento encontrado\n";
                }else{
                    cout<<"No encontrado\n";
                }
            break;
            case 4:
                preOrden(arbol);
            break;
            case 5:
                inOrden(arbol);
            break;
            case 6:
                posOrden(arbol);
            break;
            case 7:
                int numero;
                cout<< "Digite el numero a eliminar: ";
                cin>>numero;
                eliminar(arbol,numero);
            break;
            default:
                return 0;
        }
    }while(opcion!=8);
    return 0;
}

Nodo* crearNodo(int n, Nodo* padre){
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->dere = nullptr;
    nuevo->izq = nullptr;
    nuevo->padre = padre;

    return nuevo;
}

void insertar(Nodo*& arbol, int n, Nodo* padre){
    if(arbol==nullptr){
        Nodo* nuevo = crearNodo(n,padre);
        arbol = nuevo;
    }else{
        int valorRaiz = arbol->dato;
        if(n<valorRaiz){
            insertar(arbol->izq,n,arbol);
        }else{
            insertar(arbol->dere,n,arbol);
        }
    }
}

void mostrar(Nodo* arbol, int contador){
    if(arbol==nullptr){
        return;
    }else{
        mostrar(arbol->dere,contador+1);
        for(int i=0; i<contador; i++){
            cout<< "   ";
        }
        cout<<arbol->dato<<endl;
        mostrar(arbol->izq,contador+1);

    }
}

bool buscar(Nodo* arbol, int n){
    if(arbol==nullptr) return false;
    else if(arbol->dato==n){
        return true;
    }else if(n<arbol->dato){
        return buscar(arbol->izq,n);
    }else{
        return buscar(arbol->dere,n);
    }
}

void preOrden(Nodo* arbol){
    if(arbol==nullptr){
        return;
    }else{
        cout<<arbol->dato<<"->";
        preOrden(arbol->izq);
        preOrden(arbol->dere);
    }
}

void inOrden(Nodo* arbol){
    if(arbol==nullptr){
        return;
    }else{
        inOrden(arbol->izq);
        cout<<arbol->dato<<"->";
        inOrden(arbol->dere);
    }
}

void posOrden(Nodo* arbol){
    if(arbol==nullptr){
        return;
    }else{
        posOrden(arbol->izq);
        posOrden(arbol->dere);
        cout<<arbol->dato<<"->";
    }
}

Nodo* minimo(Nodo* arbol){ // determinar el valor maz izquierdo posible 
    if(arbol==nullptr){
        return nullptr;
    }else if (arbol->izq){
        return minimo(arbol->izq);
    }else{
        return arbol;
    }
}

void remplazar(Nodo* arbol, Nodo* nuevoNodo){
    if(arbol->padre){
        if(arbol->dato == arbol->padre->izq->dato){
            arbol->padre->izq = nuevoNodo;
        }else if(arbol->dato == arbol->padre->dere->dato){
            arbol->padre->dere = nuevoNodo;
        }
    }
    if(nuevoNodo){
        nuevoNodo->padre = arbol->padre;
    }
}

void destruirNodo(Nodo* nodo){
    nodo->izq = nullptr;
    nodo->dere = nullptr;
    delete nodo;
}
void eliminarNodo(Nodo* nodoEliminar){
    if(nodoEliminar->izq && nodoEliminar->dere){ //eliminar si tiene dos hijos 
        Nodo* menor = minimo(nodoEliminar->dere);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }else if(nodoEliminar->izq){ // eliminar si solo tiene un hijo 
        remplazar(nodoEliminar,nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }else if(nodoEliminar->dere){
        remplazar(nodoEliminar,nodoEliminar->dere);
        destruirNodo(nodoEliminar);
    }else{ //no tiene hijos
        remplazar(nodoEliminar,nullptr);
        destruirNodo(nodoEliminar);
    }

}

void eliminar(Nodo*& arbol,int n){
    if(arbol==nullptr){
        return;
    }else if(n<arbol->dato){
        eliminar(arbol->izq,n);
    }else if(n>arbol->dato){
        eliminar(arbol->dere,n);
    }else{
        eliminarNodo(arbol); //arbol tiene la posicion del nodo en el que bamos luego de los if

    }
}