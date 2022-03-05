#include <iostream>
using namespace std;
#include "Lista2.h"

static void mostrarCadena(string* cadena) {
	cout << *cadena << " ";
}

int main()
{
	int tam = 5;
	Lista2<string> lista(tam);
	lista.insertarPrincipio(new string("vaca"));
	lista.insertarPrincipio(new string("puerco"));
	lista.insertarPrincipio(new string("loro"));
	lista.insertarPrincipio(new string("zorro"));
	lista.insertarPrincipio(new string("mono"));
	lista.mostrar(mostrarCadena);
	cout << endl;
	lista.eliminarPrincipio();
	lista.mostrar(mostrarCadena);
	cout << endl;
}
