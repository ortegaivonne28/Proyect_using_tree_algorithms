#ifndef PILA_H_
#define PILA_H_
#include "nodo.h"
#include <iostream>

template <class T>
class pila
{
	private:
		nodo<T> *tope;
	public:
		pila<T>();
		bool esVacia();
		void apilar(T e);
		void desapilar();
		T topee();
	//	~pila<T>();
	
};

template <class T>
pila<T>::pila()
{
	tope=NULL;
}

template <class T>
bool pila<T>::esVacia()
{
	return (tope==NULL);
}

template <class T>
void pila<T>::apilar(T e)
{
	nodo<T> *nuevo;
	nuevo = new nodo<T>;
	nuevo->modificarelemento(e);
	nuevo->modificarsiguiente(tope);
	tope=nuevo;
}

template <class T>
void pila<T>::desapilar()
{
	nodo<T> *aux;
	aux=tope;
	tope=tope->siguiente();
	delete [] aux;
}

template <class T>
T pila<T>::topee()
{
	return (tope->obtenerelemento());
}

#endif