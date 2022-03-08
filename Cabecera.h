#pragma once

#include <iostream>

#include "List7.h"
using namespace std;

template<class T>
class Cabecera
{
private:
	List7<T>* lista;
	T* criterio;
public:
	Cabecera(T* nombre);
	Cabecera();
	~Cabecera();
	T* getCriterio();
	void setCriterio(T* criterio);
	List7<T>* getLista();
	void setLista(Cabecera<T>* lista);
	void aumentarEnLista(T* dato);
	//bool operator==(Cabecera* t);
};

template<class T>
Cabecera<T>::Cabecera(T* nombre)
{
	this->criterio = nombre;
	lista = new List7<T>();
}

template<class T>
Cabecera<T>::Cabecera()
{
	lista = NULL;
	criterio = NULL;
}

template<class T>
Cabecera<T>::~Cabecera()
{

}

template<class T>
T* Cabecera<T>::getCriterio()
{
	return criterio;
}

template<class T>
inline void Cabecera<T>::setCriterio(T* criterio)
{
	this->criterio = criterio;
}

template<class T>
List7<T>* Cabecera<T>::getLista()
{
	return lista;
}

template<class T>
void Cabecera<T>::setLista(Cabecera<T>* lista)
{
	this->lista = lista;
}






template<class T>
void Cabecera<T>::aumentarEnLista(T* dato)
{
	lista->insertFront(dato);
}

/*template<class T>
bool Cabecera<T>::operator==(Cabecera* t)
{
	return lista == t->getLista();
}*/





