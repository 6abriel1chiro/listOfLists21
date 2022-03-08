#pragma once
#define MAX 100
#include <iostream>
#include <string>

#include "Cabecera.h"
#include "List7.h"
#include "emptyListException.h"

template<class T>
class ListaDeListas
{
private:
	Cabecera<T>** vec;
	int first, last;
public:
	ListaDeListas();
	~ListaDeListas();
	void addDatoEnLista(T* nombreLista, T* dato);
	//void addBack(T* dato);
	void mostrar(void (*mostrarT)(T*));
	void deleteFront();
	//void deleteBack();
	T* busquedaSecuencialRecursiva(T* dato);
	T* buscarRecursivamente(T* dato, Cabecera<T>* aux);
};

template<class T>
ListaDeListas<T>::ListaDeListas()
{
	first = -1;
	last = -1;
	vec = new Cabecera<T>*[MAX];

	for (int i = 0; i < MAX; i++)
	{
		vec[i] = new Cabecera<T>;
	}

}

template<class T>
ListaDeListas<T>::~ListaDeListas()
{
	for (int i = 0; i < MAX; i++)
	{
		delete vec[i];
	}
	delete[] vec;
}



//segunda manera
template<class T>
void ListaDeListas<T>::addDatoEnLista(T* nombreLista, T* dato)
{

	if (first == -1 && last == -1){
		first = MAX / 2;
		last = MAX / 2;
		vec[first]->setCriterio(nombreLista);
		vec[first]->getLista()->insertFront(dato);
	}
	else
	{

		
		int aux = first;
		while (nombreLista != vec[aux]->getCriterio() and aux != last) {
			if (aux == MAX - 1)
				aux = 0;
			else
				aux++;
		}
		if (nombreLista == vec[aux]->getCriterio())
			vec[aux]->getLista()->insertFront(dato);
		else 
		{
			if (first == 0) {
				if( last != MAX - 1)   
					first = MAX - 1;
				else  
					throw emptyListException(); // array_lleno
			}
			else {
				if (last != first - 1)
					first = first - 1;
				else  
					throw emptyListException(); //  array_lleno
			}


			vec[first]->setCriterio(nombreLista);
			vec[first]->getLista()->insertFront(dato);
		}
	}
}

template<class T>
void ListaDeListas<T>::mostrar(void (*mostrarT)(T*))
{

			//(*mostrarT)(recorrerLista->getNombreLista());
				//(*mostrarT)(aux->getElement());

				int aux = first;
				while (aux != last) {

					(*mostrarT)(vec[aux]->getCriterio());
					//vec[aux]->getLista()->mostrar();
					if (aux == MAX - 1)
						aux = 0;
					else
						aux++;

				}



}

template<class T>
inline void ListaDeListas<T>::deleteFront()
{
}



template<class T>
T* ListaDeListas<T>::busquedaSecuencialRecursiva(T* dato)
{
	Cabecera<T>* aux = first;
	return buscarRecursivamente(dato, aux);
}

template<class T>
T* ListaDeListas<T>::buscarRecursivamente(T* dato, Cabecera<T>* aux)
{
	/*if (aux == NULL)
	{
		return NULL;
	}
	else
	{
		if (*aux->getLista()->getfirst()->getDato() == dato)
		{
			return aux->getDato();
		}
		else
		{
			return buscarRecursivamente(dato, aux->getSiguiente());
		}
	}*/
}



