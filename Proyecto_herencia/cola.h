#ifndef COLA_H_
#define COLA_H_
#include "nodo.h"
#include <iostream>

template <class T>
class cola
{
	private:
		nodo<T> *frente,*final;
	public:
		cola<T>();
		bool esVacia();
		void encolar(T e);
		void desencolar();
		T obtenerFrente();
		//~cola<T>();
};

template <class T>
cola<T>::cola()
{
	frente=NULL;
	final=NULL;
}

template <class T>
bool cola<T>::esVacia()
{
	return (frente==NULL);
}

template <class T>
void cola<T>::encolar(T e)
{
	nodo<T> *nuevo;
	nuevo = new nodo<T>;
	nuevo->modificarelemento(e);
	if(frente==NULL)
		frente=nuevo;
	else
		final->modificarsiguiente(nuevo);
	final=nuevo;
}

template <class T>
void cola<T>::desencolar()
{
		nodo<T> *aux;
		aux=frente;
		frente=frente->siguiente();
		delete [] aux;
}

template <class T>
T cola<T>::obtenerFrente()
{
	return (frente->obtenerelemento());
}

#endif