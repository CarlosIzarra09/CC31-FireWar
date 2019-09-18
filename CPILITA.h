#include<string>
#include <iostream>

using namespace std;

template<class T>
class Pila {
private:
	class Nodo {
	public:
		T info;
		Nodo *sig;
	};

	Nodo *raiz;
public:
	Pila();
	~Pila();
	void insertar(T x);
	int extraer();
	void imprimir();
	class Iterador {
		NODO* aux;

	public:
		Iterador(NODO* aux = nullptr) : aux(aux) {}
		void operator ++ () { aux = aux->next; }
		bool operator != (Iterador it) { return aux != it.aux; }
		int operator* () { return aux->element; }
	};

};
template<typename T>
Pila::Pila()
{
	raiz = NULL;
}
template<typename T>
void Pila::insertar(T x)
{
	Nodo *nuevo;
	nuevo = new Nodo();
	nuevo->info = x;
	if (raiz == NULL)
	{
		raiz = nuevo;
		nuevo->sig = NULL;
	}
	else
	{
		nuevo->sig = raiz;
		raiz = nuevo;
	}
}
template<typename T>
void Pila::imprimir()
{
	Nodo *reco = raiz;
	cout << "Listado de todos los elementos de la pila.\n";
	while (reco != NULL)
	{
		cout << reco->info << "-";
		reco = reco->sig;
	}
	cout << "\n";
}
template<typename T>
int Pila::extraer()
{
	if (raiz != NULL)
	{
		int informacion = raiz->info;
		Nodo *bor = raiz;
		raiz = raiz->sig;
		delete bor;
		return informacion;
	}
	else
	{
		return -1;
	}
}
template<typename T>
Pila::~Pila()
{
	Nodo *reco = raiz;
	Nodo *bor;
	while (reco != NULL)
	{
		bor = reco;
		reco = reco->sig;
		delete bor;
	}
}

