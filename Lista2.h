#pragma once

#include <iostream>
#include <string>

#include "ListaVaciaException.h"

template<class T>
class Lista2
{
private:
	int tam;
	T** Array;
	int primer, ultimo;
	bool lleno;
public:
	Lista2(int tam);
	~Lista2();
	void insertarPrincipio(T* dato);
	void eliminarPrincipio();
	void mostrar(void (*mostrarT)(T*));
	T* mayorLista(bool(*funcComp)(T*, T*));;
};

template<class T>
Lista2<T>::Lista2(int tam)
{
	primer = -1;
	ultimo = -1;
	Array = new T * [tam];
	for (int i = 0; i < tam; i++)
	{
		Array[i] = new T;
	}

	this->tam = tam;

}

template<class T>
Lista2<T>::~Lista2()
{
}

template<class T>
void Lista2<T>::insertarPrincipio(T* dato)
{
	if (primer == -1)
	{
		primer = tam/2;
		ultimo = tam/2;
		Array[primer] = dato;
	}
	else
	{
		if (primer == 0) {
			if (ultimo != tam - 1) {
				primer = tam - 1;//salto hasta el final
			}
			else {
				lleno = true;
			}
		}
		else
		{
			if (ultimo != primer - 1)
			{
				primer = primer - 1;
			}
			else
			{
				lleno = true;
			}
		}
		if (lleno != true) {
			Array[primer] = dato;
		}
	}
}

template<class T>
void Lista2<T>::eliminarPrincipio()
{
	if (primer == -1 && ultimo == -1)
	{
		throw ListaVaciaException(); //lista vacia
	}
	else
	{
		if (primer == ultimo)
		{
			primer = -1;
			ultimo = -1;
		}
		else
		{
			if (primer != tam - 1)
			{
				primer = primer + 1;
			}
			else
			{
				primer = 0;
			}
		}
	}
}

template<class T>
void Lista2<T>::mostrar(void (*mostrarT)(T*))
{
	int pos = primer;
	while (pos != ultimo) {
		(*mostrarT)(Array[pos]);
		if (pos == tam - 1)
		{
			pos = 0;
		}
		else
		{
			pos++;
		}		
	}
	if (pos == ultimo && primer != 1)
	{
		(*mostrarT)(Array[ultimo]);
	}
}

/*template<class T>
T* Lista2<T>::mayorLista(bool (*funcComp)(T*, T*))
{
	T* mayor = Array[primer];
	int i = primer + 1;
	while (i != ultimo + 1)
	{
		if ((*funcComp)(Array[i], mayor) == false)
		{
			mayor = Array[i];
		}

		if (i == tam - 1)
		{
			i = 0;
		}
		else
		{
			i++;
		}
	}
	return mayor;
}*/

