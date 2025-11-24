/*PUNTEROS
Almacenan dereccion en memoria de un tipo de dato T 
	Declaracion T* nombrePuntero;
Los doble punteros guardan la direccion de otra variable puntero
	Declaracion: T** doblePuntero;
Graficamente son una flecha -> al objeto que apunta

La desreferencia 
	*p=5
	Se debe desreferenciar para poder asignar un valor 
	p (direccion en memoria donde se guardo 5)
	*p (valor 5 introducido en la direccion de memtoria de p)
	
Operador & complemento de *; devuelve la direccion de una variable que se debe asignar a T*
	&c 
	tenemos la direccion de memoria de c
	*&c=5 guardamos un valor en c
Nullptr 
	*p
	da error al ejecutar si desreferencimos un p que apunta a nullptr
Desreferenciar *p equivale a p->
Funciones de punteros
	Se pasa la ditreccion por valor o referencia 
	Por valor: Realiza una copia del puntero 
*/
#include <iostream>
using namespace std;

void ejer1(){
	// 1. Declarar e inicializar el puntero.
	// Asignamos una nueva dirección de memoria para el double.
	double* pf = new double;
	
	// 2. Ahora sí, desreferenciamos (escribimos en la memoria asignada).
	*pf = 2.0;
	
	// 3. Imprimimos el VALOR que hay en esa dirección.
	cout << "Valor almacenado: " << *pf << endl;

	// 4. Liberamos la memoria (buena práctica).
	delete pf; 
	
	// Nota: Si solo quieres imprimir la DIRECCIÓN, sería: cout << pf;
}

void ejer2(){
	char c;
	int i=1;
	char* pchar= &c; //el puntero pchar recibe la direccion en memoria donde se guardo c
	int *pint, *qint;
	
	*&c='N'; // se asigna N en la direccion de memoria de c
	pint=qint= &i; // se asigna la direccion de memoria de i tanto a pint como a qint
	*pint=2; // se asigna 2 a la direccion de memoria de pint
	if(*qint != 1) { // si dos != uno
		*pchar = 'S'; //Cambia el valor ingresado en la direccion de pchar que es la misma que c
	}
	cout<< "Se ha cambiado *qint? : "<< c<< *pchar <<endl;
	cout<< pint<<endl;
	cout<< qint<<endl;
	cout<< &i<<endl; // misma direccion de memoria
}

void ejer3(){
	int tamanio;
	cout<< "Ingrese el tamaño de los vectores: ";
	cin>> tamanio;
	double m[tamanio];
	double* vectorP[tamanio];
	double* aux;
	
	for(int i=0; i<tamanio; i++){
		cout<< "Ingrese el elemento " << i+1 << " : \n";
		cin>> m[i];
	
	}
	for(int i=0; i<tamanio; i++){
		vectorP[i] = &m[i]; //Asignamos la direccion de memoria de cada elemento al vecotor de punteros  
	}
	
	for(int j=0; j<tamanio-1; j++){ //Por definicion necesito N-1 pasadas para ordenar un tamaño N 
		for(int i=0; i<tamanio-1; i++)//tamanio-1-j para ignorar las pasadas ya ordenadas
			if(*vectorP[i+1]<*vectorP[i]){ //Ejecuta si el valor siguiente es menor que el anterior 
				aux = vectorP[i]; //aux tiene la direccion del mayor(anterior)
				vectorP[i] = vectorP[i+1];//mayor(anterior) tiene la direccion del menor(siguiente)
				vectorP[i+1] = aux;//menor(siguiente) tiene la direccion de aux(mayor)
			}
	}
	
	// 4. IMPRESIÓN DEL RESULTADO (Recorriendo los punteros ordenados)
	cout << "\n--- Vector Original (m) ---\n";
	for(int i=0; i<tamanio; i++){
		cout << m[i] << " ";
	}
    
	cout << "\n--- Vector Ordenado (via punteros) ---\n";
	for(int i=0; i<tamanio; i++){
		// Imprimimos el valor (usando *) al que apunta el puntero ahora ordenado.
		cout << *vectorP[i] << " ";
	}
	cout << endl;
}

void ejer4(){
	struct SA;
	struct SB; //decalracion adelanteada
	struct SC;
	struct SD;
	
	struct SA{
		int dato; SB* p1;
	};
	struct SB{
		int dato; SA* p1; SC* p2;
	};
	struct SC{
		SA* p1; SB* p2; SD* p3;
	};
	struct SD{
		int* p1; SB* p2;
	};
	
	SA a;
	SB b;
	SC c;
	SD d;
	int dato;
	
	a.dato = b.dato = dato = 0;
	a.p1 = &b;
	b.p1 = &a;
	b.p2 = &c;
	c.p1 = b.p1; //osea c.p1 puntero que apunta a a
	c.p2 = &(*a.p1); // c.p2 puntero que apunta a b
	c.p3 = &d; //c.p3 puntero que apunta a d
	d.p1 = &dato; //d.p1 puntero que apunta a direccion de dato 
	d.p2 = &(*(c.p1)->p1);//puntero p2 recepta la direccion de memoria del valor que se guarda en p1
	*(d.p1) =9; //Se guarda 9 en puntero p1 de d 
	(*(b.p2)->p1).dato = 1; //p2 se desreferencia y guarda direccion de p1 que a su vez se desreferencia y accede a dato y guarda 1
	(((b.p2)->p3->p2)->p1)->dato = 7; // Nose cual es el error
	*((*((*(c.p3->p2)).p2->p3)).p1) = (*(b.p2)).p1->dato+5; // Nose cual es el error
	cout << "a.dat=" << a.dato << " b.dat=" << b.dato << " dat=" << dato << endl;
}

void ejer5PasoporValor(int* p){//el puntero p recibe la copia de direccion de q(osea 1)
	*p = 0; //se asiga 0 a la direccion de memoria COPIA
	cout<< "La direccion de p es: "<<p<<endl;
	p = nullptr;//se modifica la direccion de la copia p pero no del original q
	//cout<< "La direccion de p es: "<<*p<<endl; //No se puede acceder a un elemento de un puntero que apunta a nullptr 
}

class Ejer6{
	public:
		int dato;
		int* puntero;
	public:
		void hacerCero(Ejer6 p){
			p.dato = 0;
			*p.puntero = 0;
		}
		void imprimirOriginal(){
			cout<< "\nDato: "<< dato<<endl;
			cout<< "Puntero: "<< *puntero<<endl;
		}
};
int main(){
	ejer1();
	ejer2();
	ejer3();
	//ejer4();
	
	//EJjercicio 5
	int a=1;
	int* q = &a; // recibe el puntero q la direccion en memoria de a(osea 1)
	cout<< "a con direccion : "<< &a<<endl;
	cout<< "q con direccion : "<< q<<endl;
	ejer5PasoporValor(q); //mandamos la direccion de 1 a la funcion
	cout<< "ahora a y q con direccion : "<<&a<< " "<<q;
	
	//Ejercicio 6
	int numero=1;
	Ejer6 seis = {1,&numero};
	cout <<"\n *p.puntero: "<<*seis.puntero<<endl;
	seis.hacerCero(seis);
	seis.imprimirOriginal();
	return 0;
}
