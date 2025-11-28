#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef unsigned int Id;
typedef float Promedio;
typedef string Nombre;

struct Estudiante {
    Id idEstudiante;
    Promedio promedioEstudiante;
    Nombre nombreEstudiante;
};

void mostrar(const vector<Estudiante>& v) {

    if (v.empty()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    cout << "\nId\tPromedio\tNombre\n";
    cout << "--------------------------------------\n";

    for (const auto& e : v) {
        cout << e.idEstudiante << "\t"
            << e.promedioEstudiante << "\t\t"
            << e.nombreEstudiante << "\n";
    }
}

void insertar(vector<Estudiante>& v) {
    Estudiante e;
    cout << "\nIngrese ID: ";
    cin >> e.idEstudiante;

    cout << "Ingrese promedio: ";
    cin >> e.promedioEstudiante;

    cout << "Ingrese nombre: ";
    cin.ignore();  // limpiar buffer
    getline(cin, e.nombreEstudiante);

    v.push_back(e);
    cout << "\nEstudiante agregado correctamente.\n";
}

void eliminar(vector<Estudiante>& v) {
    if (v.empty()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    Id idBuscar;
    cout << "Ingrese el ID del estudiante a eliminar: ";
    cin >> idBuscar;

    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it->idEstudiante == idBuscar) {
            v.erase(it);
            cout << "Estudiante eliminado correctamente.\n";
            return;
        }
    }

    cout << "No existe un estudiante con ese ID.\n";
}

void selectionSort(vector<Estudiante>& v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        int indiceMin = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j].promedioEstudiante < v[indiceMin].promedioEstudiante) {
                indiceMin = j;
            }
        }

        if (indiceMin != i)
            swap(v[i], v[indiceMin]);

        cout << "\nPasada " << i + 1 << ":\n";
        mostrar(v);
    }

    cout << "\nOrdenamiento finalizado.\n";
}

void guardarEnArchivo(const vector<Estudiante>& v) {
    ofstream archivo("estudiantes.txt");

    for (const auto& e : v) {
        archivo << e.idEstudiante << "\n"
                << e.promedioEstudiante << "\n"
                << e.nombreEstudiante << "\n";
    }
}

void cargarDesdeArchivo(vector<Estudiante>& v) {
    ifstream archivo("estudiantes.txt");

    if (!archivo) {
        // Archivo no existe → crearlo
        ofstream crear("estudiantes.txt");
        crear.close();
        return;
    }

    Estudiante e;

    while (archivo >> e.idEstudiante) {
        archivo >> e.promedioEstudiante;
        archivo.ignore(); // limpiar salto de línea antes del nombre
        getline(archivo, e.nombreEstudiante);

        v.push_back(e);
    }

    archivo.close();
}

int main() {
    vector<Estudiante> estudiantes;
    int opcion;

    cargarDesdeArchivo(estudiantes);

    do {
        cout << "\n============== MENÚ ==============\n";
        cout << "1. Insertar estudiante\n";
        cout << "2. Eliminar estudiante por ID\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Ordenar por promedio (Selection Sort)\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            insertar(estudiantes);
            guardarEnArchivo(estudiantes);
            break;
        case 2:
            eliminar(estudiantes);
            guardarEnArchivo(estudiantes);
            break;
        case 3:
            mostrar(estudiantes);
            break;
        case 4:
            cout << "\nLista antes del ordenamiento:\n";
            mostrar(estudiantes);
            selectionSort(estudiantes);
            cout << "\nLista despues del ordenamiento:\n";
            mostrar(estudiantes);
            guardarEnArchivo(estudiantes);
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}