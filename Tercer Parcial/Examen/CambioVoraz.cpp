#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calcularCambioVoraz(int monto, vector<int>& monedas) {

    sort(monedas.begin(), monedas.end(), greater<int>());

    int totalMonedasUsadas = 0;
    cout << "Desglose del cambio para " << monto << ":" << endl;

 
    for (int i = 0; i < monedas.size(); i++) {
        if (monto == 0) break; 

        int monedaActual = monedas[i]; 

        if (monto >= monedaActual) {

            int cantidad = monto / monedaActual; 
            

            totalMonedasUsadas += cantidad;


            monto = monto % monedaActual; 

            cout << "- Monedas de " << monedaActual << ": " << cantidad << endl;
        }
    }

  
    if (monto > 0) {
        cout << "No se pudo dar el cambio exacto. Restante: " << monto << endl;
    } else {
        cout << "Total de monedas: " << totalMonedasUsadas << endl;
    }
}

int main() {
    // Ejemplo del PDF: Sistema de monedas {1, 5, 10, 20} para un cambio de 36 [cite: 39-44].
    vector<int> denominaciones = {1, 10, 5, 20};
    int objetivo = 36;

    calcularCambioVoraz(objetivo, denominaciones);

    return 0;
}
