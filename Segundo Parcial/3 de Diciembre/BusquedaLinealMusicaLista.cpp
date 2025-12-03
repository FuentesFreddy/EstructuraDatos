#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef unsigned int Reproduccion;
typedef std::string Nombre;
struct Cancion{
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
    void agregarLista(){
        Nodo<Cancion>* nuevo = new Nodo<Cancion>();
        cout << "Ingrese el nombre de la cancion: ";
        cin.ignore();
        getline(cin,nuevo->dato.nombreCancion);
        cout << "inrgrese el numero de reproducciones: ";
        cin >> nuevo->dato.numReproduccion;
        nuevo->sig = nullptr;

        if(inicio == nullptr){
            inicio = nuevo;
        } else{
            Nodo<Cancion>* aux = inicio;
            while(aux->sig != nullptr ){
                aux = aux->sig;
            }
            aux->sig = nuevo;
        }
    }

    void mostrarDatos(){
        if(inicio == nullptr){
            cout << "La lista esta vacia" << endl;
            return;
        }

        Nodo<Cancion>* aux = inicio;
        int contador = 1;
        
        cout << "\n========== LISTA DE CANCIONES ==========\n" << endl;
        while(aux != nullptr){
            cout << "Cancion #" << contador << endl;
            cout << "Nombre: " << aux->dato.nombreCancion << endl;
            cout << "Reproducciones: " << aux->dato.numReproduccion << endl;
            cout << "----------------------------------------" << endl;
            aux = aux->sig;
            contador++;
        }
    }

        void reproducirCancion(const string& nombre){
        Nodo<Cancion>* aux = inicio;
        bool encontrado = false;
        int contador =0;
        while(aux != nullptr && encontrado== false){
            if(aux->dato.nombreCancion == nombre){
                aux->dato.numReproduccion++;
                cout << "\nReproduciendo: " << aux->dato.nombreCancion << endl;
                cout << "Reproducciones totales: " << aux->dato.numReproduccion << endl;
                encontrado = true;
                break;
            }
            contador++;
            aux = aux->sig;
        }

        if(encontrado) cout<< "Cancion encontrada en posicion "<< contador-2<< endl;
        
        if(!encontrado){
            cout << "Cancion no encontrada." << endl;
        }
    }

    void ordenarPoNombre(){
        if(inicio == nullptr || inicio->sig == nullptr) return;
        bool intercambio;
        do{
            intercambio = false;
            Nodo<Cancion>* actual = inicio;
            while(actual->sig != nullptr){
                if(actual->dato.nombreCancion > actual->sig->dato.nombreCancion){
                    Cancion temp = actual->dato;
                    actual->dato = actual->sig->dato;
                    actual->sig->dato = temp;
                    intercambio = true;
                }
                actual = actual->sig;
            }
        }while(intercambio);

        cout << "Lista Ordenada Por Nombre." << endl;
    }

    void ordenarPorReproducciones(){
        if(inicio == nullptr || inicio->sig == nullptr) return;
        bool intercambio;
        do{
            intercambio = false;
            Nodo<Cancion>* actual = inicio;
            while(actual->sig != nullptr){
                if(actual->dato.numReproduccion < actual->sig->dato.numReproduccion){
                    Cancion temp = actual->dato;
                    actual->dato = actual->sig->dato;
                    actual->sig->dato = temp;
                    intercambio = true;
                }
                actual = actual->sig;
            }
        }while(intercambio);

        cout << "Lista Ordenada Por Reproduccciones(Mayor a Menor)." << endl;
    }

    void guardarEnArchivo(){
        ofstream archivo("playlist.txt");
        
        if(!archivo.is_open()){
            cout << "Error al abrir el archivo para guardar." << endl;
            return;
        }
        
        Nodo<Cancion>* aux = inicio;
        while(aux != nullptr){
            archivo << aux->dato.nombreCancion << endl;
            archivo << aux->dato.numReproduccion << endl;
            aux = aux->sig;
        }
        
        archivo.close();
    }

    void cargarDesdeArchivo(){
        ifstream archivo("playlist.txt");
        
        if(!archivo.is_open()){
            return; // Si no existe el archivo, simplemente inicia vacío
        }
        
        string nombre;
        Reproduccion reproducciones;
        
        while(getline(archivo, nombre)){
            if(archivo >> reproducciones){
                archivo.ignore(); // Ignorar el salto de línea después del número
                
                Nodo<Cancion>* nuevo = new Nodo<Cancion>();
                nuevo->dato.nombreCancion = nombre;
                nuevo->dato.numReproduccion = reproducciones;
                nuevo->sig = nullptr;
                
                if(inicio == nullptr){
                    inicio = nuevo;
                } else{
                    Nodo<Cancion>* aux = inicio;
                    while(aux->sig != nullptr){
                        aux = aux->sig;
                    }
                    aux->sig = nuevo;
                }
            }
        }
        
        archivo.close();
    }
};



void importarArchivo(){

}
int main(){
    Lista playlist;
    playlist.cargarDesdeArchivo();
    int opcion;
    string nombreCancion;

    do{
    cout << "\n========== MENU ==========\n";
        cout << "1. Agregar cancion\n";
        cout << "2. Mostrar todas las canciones\n";
        cout << "3. Reproducir cancion\n";
        cout << "4. Ordenar por nombre\n";
        cout << "5. Ordenar por reproducciones\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion){
            case 1:
                playlist.agregarLista();
                playlist.guardarEnArchivo();
                break;
            case 2:
                playlist.mostrarDatos();
                playlist.guardarEnArchivo();
                break;
            case 3:
                cout << "Ingrese el nombre de la cancion a reproducir: ";
                cin.ignore();
                getline(cin, nombreCancion);
                playlist.reproducirCancion(nombreCancion);
                break;
            case 4:
                playlist.ordenarPoNombre();
                playlist.guardarEnArchivo();
                break;
            case 5:
                playlist.ordenarPorReproducciones();
                playlist.guardarEnArchivo();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while(opcion != 6 );
    
    return 0;
}