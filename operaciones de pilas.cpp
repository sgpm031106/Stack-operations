/*
Operaciones fundamentales de pilas
Pérez Moreno Sergio Gabriel
Ingernieria en Computacion Inteligente
Estructuras computacionales
Marzo del 2022
*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <clocale>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipo de las funciones
void insertar(Nodo *&, int);
void eliminar(Nodo *&, int &);
void mostrar(Nodo *);
void crear(Nodo *&);
void vacia(Nodo *);
void buscar(Nodo *&, int);
void eliminartodo(Nodo *&, int);
void cantidad(Nodo *);
void menu();

Nodo *pila = NULL;

int main()
{
	
	setlocale(LC_ALL, "spanish");
	menu();
	
	getch();
	return 0;
}

void insertar(Nodo *&pila, int n)
{
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	nuevo->siguiente = pila;
	pila = nuevo;
	cout<<"Elemento insertado a la pila. "<<endl;
}

void eliminar(Nodo *&pila, int &n)
{
		Nodo *aux = pila;
		n = aux->dato;
		pila = aux->siguiente;
		delete aux;
}

void mostrar(Nodo *pila)
{
	Nodo *nuevo = new Nodo();
	nuevo = pila;
	if(pila != NULL)
	{
		while(nuevo != NULL)
		{
			cout<<nuevo->dato<<" - ";
			nuevo = nuevo->siguiente;
		}
	}
	else
	{
		cout<<"La pila está vacía. "<<endl;	
	}		
}

void crear(Nodo *&pila)
{
	Nodo *nuevo = new Nodo();
	cout<<"Lista creada. "<<endl;
}

void vacia(Nodo *)
{
	if(pila != NULL)
	{
		cout<<"La pila no está vacía. "<<endl;
	}
	else
	{
		cout<<"La pila está vacía. "<<endl;
	}
}

void buscar(Nodo *&pila, int n)
{
	bool found = false;
	int cont = 0;
	
	Nodo *aux = new Nodo();
	aux = pila;
	
	if(pila != NULL)
	{
		while(aux != NULL)
		{
			cont++;
			if(aux->dato == n)
			{
				cout<<"El valor está en la posicion "<<cont<<"."<<endl;
				found = true;
			}
			aux = aux->siguiente;
		}
		if(found == false)
		{
			cout<<"El elemento no está dentro de la pila. "<<endl;
		}
	}
	else
	{
		cout<<"La pila está vacia. "<<endl;
	}
}
void cantidad(Nodo *pila)
{
	Nodo  *aux;
	int cont = 0;
	if(pila != NULL)
	{
		aux = pila;
		while(aux != NULL)
		{
			aux = aux->siguiente;
			cont++;
		}
		cout<<"La pila tiene "<<cont<<" elementos. "<<endl;
	}
	else
	{
		cout<<"La pila está vacía. "<<endl; 
	}
}

void menu()
{
	int opcion, dato;
	do{
		cout<<"---MENÚ--- "<<endl;
		cout<<"1. INSERTAR. "<<endl;
		cout<<"2. SACAR. "<<endl;
		cout<<"3. MOSTRAR. "<<endl;
		cout<<"4. CREAR PILA VACÍA. "<<endl;
		cout<<"5. SABER SI LA PILA ESTÁ VACÍA. "<<endl;
		cout<<"6. BUSCAR UN ELEMENTO DE LA PILA. "<<endl;
		cout<<"7. CANTIDAD DE ELEMENTOS. "<<endl;
		cout<<"8. SALIR. "<<endl;
		cout<<"¿Qué desea hacer? ";
		cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Inserte un número: ";
				cin>>dato;
				insertar(pila, dato);
				cout<<"\n";
				break;
				
			case 2:
				cout<<"\nSacando elementos de la pila. ";
				while(pila != NULL){
					eliminar(pila, dato);
					if(pila != NULL)
					{
						cout<<dato<<",";
					}
					else
					{
						cout<<dato<<".";
					}
				}
				cout<<"\n";
				break;
				
			case 3:
				mostrar(pila);
				cout<<"\n";
				break;
			
			case 4:
				crear(pila);
				cout<<"\n";
				break;
				
			case 5:
				vacia(pila);
				cout<<"\n";
				break;
				
			case 6:
				cout<<"¿Cuál elemento desea buscar? ";
				cin>>dato;
				buscar(pila, dato);
				cout<<"\n";
				break;
				
			case 7:
				cantidad(pila);
				cout<<"\n";
				break;
			
			case 8:
				cout<<"Saliendo del programa. "<<endl;
				break;
				
			default:
				cout<<"Opción inválida, ingrese otra respuesta. "<<endl;
				break;
			}
			system("pause");
			system("cls");
		}while(opcion != 8);
}
