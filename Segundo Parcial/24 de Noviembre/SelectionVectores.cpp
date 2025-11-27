#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef int Codigo;
typedef string Descripcion;
typedef string Categoria;
typedef double Peso;
typedef double Precio;
struct Producto{
    Codigo id;
    Descripcion descripcion;
    Peso peso;
    Categoria tipo;
    Precio valor;
};

void ingresar(vector<Producto> &productos){ //Trabaja sobre el vector odiginal para que no se destruya
    int respuesta;
    do{
        Producto objAux;
        cout<< "Ingrese el id del producto: ";
        cin>> objAux.id;
        cin.ignore();
        cout<< "Ingrese la descripcion del producto: ";
        getline(cin,objAux.descripcion);
        cout<< "ngrese el tipo (CATEGORIA) de producto: ";
        getline(cin,objAux.tipo);
        cout<< "Ingrese el peso del producto: ";
        cin>> objAux.peso;
        cout<< "Ingrese el precio del producto: ";
        cin>> objAux.valor;
        //Ingresamos objAux a funcion rellenar vector
        productos.push_back(objAux);
        cout<< "Desea ingresar mas? Ingrese 1(SI) o O(NO): \n";
        cin>> respuesta;
    }while(respuesta == 1);
}

void mostrarProductos(const vector<Producto>& productos){
    cout<< "############################################################################\n";
    cout<<setw(16)<<"Codigo"<<setw(16)<< "Descripcion"<<setw(16)<< "Categoria"<<setw(16)<< "Peso"<<setw(16)<< "Precio\n";
    for(const auto& prod : productos){ //prod es de tipo cualquiera por referencia osea que no es copia y no puede modificar por el const osea solo lee
        cout<<setw(16)<< prod.id<<setw(16)<<prod.descripcion<<setw(16)<<prod.tipo<<setw(16)<<prod.peso<<setw(16)<<prod.valor<<endl;
    }
}

void selectionSort(vector<Producto>& productos, int n){
    for(int i=0; i<n-1; i++){
        int minimo = i;
        int comparaciones = 0;
        for(int j= i+1; j<n; j++){
            if(productos[j].tipo<productos[minimo].tipo){
                minimo = j;
            }else if(productos[j].tipo==productos[minimo].tipo){
                if(productos[j].valor<productos[minimo].valor){
                    minimo = j;
                }else if(productos[j].valor==productos[minimo].valor){
                    if(productos[j].peso<productos[minimo].peso){
                        minimo = j;
                    }
                }
            }
            comparaciones++; // Se incrementa una vez haya terminado la cascada de comparaciones 
        }
        cout<< "comparaciones: "<< comparaciones<<endl;
        cout<< "Minimo en posicion: "<< minimo<<endl;
        if(i==minimo) cout<< "No hubo cambio\n"; 
        if(i<minimo) cout<< "Hubo cambio\n"; // minimo se debio aver actualizado o no 
        swap(productos[i],productos[minimo]);
        cout<<endl;
        mostrarProductos(productos);// mostramos la lista despues de cada pasada o mejor dicho de cada intercambio
    }
}

int main() {
    // Inicialización manual del vector con 20 productos
    // Orden: {id, descripcion, peso, tipo, valor}
    vector<Producto> productos = {
        {101, "Leche Entera", 1.0, "Lacteos", 1.20},
        {102, "Yogurt Fresa", 0.15, "Lacteos", 0.80},
        {103, "Queso Gouda", 0.5, "Lacteos", 5.50},
        {104, "Mantequilla", 0.2, "Lacteos", 2.50}, // Mismo tipo
        {105, "Leche Descremada", 1.0, "Lacteos", 1.20}, // Mismo precio que la Entera -> Desempate por peso (igual peso, orden original)
        
        {201, "Manzana Roja", 0.2, "Frutas", 0.50},
        {202, "Banana", 0.15, "Frutas", 0.30},
        {203, "Uvas", 0.5, "Frutas", 2.00},
        {204, "Sandia", 3.0, "Frutas", 3.00},
        {205, "Manzana Verde", 0.2, "Frutas", 0.50}, // Igual precio/peso que Roja -> orden original

        {301, "Carne Molida", 1.0, "Carnes", 8.00},
        {302, "Pollo Entero", 2.5, "Carnes", 6.50},
        {303, "Chuleta Cerdo", 1.0, "Carnes", 7.00},
        {304, "Bistec Res", 0.5, "Carnes", 8.00}, // Mismo precio que Molida -> Desempate por peso
        
        {401, "Zanahoria", 1.0, "Verduras", 1.00},
        {402, "Lechuga", 0.3, "Verduras", 0.80},
        {403, "Papa", 5.0, "Verduras", 4.00},
        {404, "Tomate", 1.0, "Verduras", 1.50},
        {405, "Cebolla", 1.0, "Verduras", 1.00}, // Mismo precio que Zanahoria -> Desempate por peso (igual peso)

        {501, "Arroz", 1.0, "Granos", 1.10}
    };

    int n = productos.size();

    cout << "--- LISTA ORIGINAL ---" << endl;
    mostrarProductos(productos);
    cout << endl << "--- INICIO DEL SELECTION SORT ---" << endl;

    selectionSort(productos, n);

    cout << "--- LISTA FINAL ORDENADA ---" << endl;
    mostrarProductos(productos);

    return 0;
}