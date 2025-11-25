#include <iostream>
using namespace std;

class Coche{
    private:
        string nombre;
        int codigo;
        double precio;
    public:
        Coche(string nombre, int codigo, double precio){
            this->nombre = nombre;
            this->codigo = codigo;
            this->precio = precio;
        }
        void insertion(Coche* cochePuntero[], int n){
            for(int i=1; i<n; i++){
                Coche* clave = cochePuntero[i];
                int j = i-1;
                while(j>=0 && cochePuntero[j]->precio > clave->precio){
                    cochePuntero[j+1] = cochePuntero[j];
                    j--;
                }
                cochePuntero[j+1] = clave;
            }
        }

        void mapear(Coche cocheObjeto[],Coche* cochePuntero[], int n){
            for(int i=0; i<n; i++){
                cochePuntero[i] = &cocheObjeto[i];
            }
        }

        void mostrar(Coche* coche[],int n){
            cout<< "Nombre\t\t"<<"Codigo\t\t"<<"Precio\t\t\n";
            for(int i=0; i<n; i++){
                cout<< coche[i]->nombre<<"\t\t"<<coche[i]->codigo<<"\t\t"<<coche[i]->precio<<endl;
            }
        }
};

int main(){
    Coche coches []= {
        {"AUDI",001,565.01}, {"KIA",002,73456.04}, {"FERRA",003,2.018}, {"TOYO",004,0.01}
    };
    int n = sizeof(coches)/sizeof(Coche);
    Coche* punteroCoche[n];
    coches->mapear(coches,punteroCoche,n);
    coches->mostrar(punteroCoche,n);
    coches->insertion(punteroCoche,n);
    cout<<endl;
    coches->mostrar(punteroCoche,n);
}

