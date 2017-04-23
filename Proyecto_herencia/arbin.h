#ifndef ARBIN_H_
#define ARBIN_H_
#include "nodoarbin.h"
#include "Cola.h"
#include "Pila.h"
#include <iostream>

using std::cout;

template<class T>
class Arbin
{
	private:
		NodoArbin<T> *nodoR;
		
		NodoArbin<T>* copiar_nodos(NodoArbin<T>* ptr);//ya
		void recorridoPreorden(NodoArbin<T> *ptr);//ya
		void recorridoInorden(NodoArbin<T> *ptr);//ya
		void recorridoPostorden(NodoArbin<T> *ptr);//ya
		
		/*NodoArbin<T>* altura_nodo(NodoArbin<T>* ptr);
		int pesoNodo(NodoArbin<T>* ptr);
		bool nodoHoja(NodoArbin<T>* ptr);
		*/
	public:
		Arbin<T>();	//constructor por defecto
		Arbin<T>(T e, Arbin<T> A1, Arbin<T> A2);	//constructor por parametros
		Arbin<T>(T elem);
		//Arbin<T>(const Arbin<T> *A);	//constructor copia que invoca al copiar
		//~Arbin<T>();	//destructor que invoca a vaciar
		
		void copiar(Arbin<T> A);	//proc publico para acceder a la funcion privada copiar_nodos
		bool esNulo();	//listo
		T raiz();	//listo
		Arbin<T> hijoI();	//listo
		Arbin<T> hijoD();//listo
		
		void Preorden();//ya
		void Inorden();//ya
		void Postorden();//ya
		void Niveles();	//ya
		/*void Altura();	
		int Peso();
		bool esHoja();
		*/
		
		void vaciar();
		
};


template<class T>
Arbin<T>::Arbin()
{
	nodoR=NULL;
}//fin


template<class T>
NodoArbin<T>* Arbin<T>::copiar_nodos(NodoArbin<T>* ptr)
{
	NodoArbin<T> *nuevo;
	
	if(ptr==NULL)
	{
		return NULL;
	}else
	{
		nuevo = new NodoArbin<T>(ptr->getElemento(), copiar_nodos(ptr->getHijoI()), copiar_nodos(ptr->getHijoD()));
		return (nuevo);
	}
}//fin

template<class T>
void Arbin<T>::copiar(Arbin<T> A)
{
	nodoR=copiar_nodos(A.nodoR);
}//fin



template<class T>
Arbin<T>::Arbin(T e, Arbin<T> A1, Arbin<T> A2)
{
	Arbin<T> aux;
	
	nodoR=new NodoArbin<T>(e, NULL, NULL);
	aux.copiar(A1);
	nodoR->setHijoI(aux.nodoR);
	aux.copiar(A2);
	nodoR->setHijoD(aux.nodoR);
	aux.nodoR=NULL;
}//fin

template<class T>
Arbin<T>::Arbin(T elem)
{
	nodoR=new NodoArbin<T>(elem, NULL, NULL);
}

/*
template<class T>
Arbin<T>::Arbin(const Arbin<T> *A)
{
	if(A.nodoR==NULL)
	{
		return NULL;
	}else
	{
		copiar(*A);
	}
}
*/
/*
template<class T>
Arbin<T>::~Arbin()
{
	vaciar();
}
*/


template<class T>
void Arbin<T>::recorridoPreorden(NodoArbin<T>* ptr)
{

	
	if(ptr!=NULL)
	{
		cout<<" "<<ptr->getElemento();
		recorridoPreorden(ptr->getHijoI());
		recorridoPreorden(ptr->getHijoD());
	}
}

template<class T>
void Arbin<T>::Preorden()
{
	recorridoPreorden(nodoR);
}

template<class T>
void Arbin<T>::recorridoInorden(NodoArbin<T>* ptr)
{
	
	if(ptr!=NULL)
	{
		recorridoInorden(ptr->getHijoI());
		cout<<" "<<ptr->getElemento();
		recorridoInorden(ptr->getHijoD());
	}
}

template<class T>
void Arbin<T>::Inorden()
{
	recorridoInorden(nodoR);
}


template<class T>
void Arbin<T>::recorridoPostorden(NodoArbin<T>* ptr)
{
	
	
	if(ptr!=NULL)
	{
		recorridoPostorden(ptr->getHijoI());
		recorridoPostorden(ptr->getHijoD());
		cout<<" "<<ptr->getElemento();
	}
}


template<class T>
void Arbin<T>::Postorden()
{
	recorridoPostorden(nodoR);
}



template<class T>
void Arbin<T>::Niveles()
{
	
	Cola<NodoArbin<T>* > C;
	
	if(nodoR!=NULL)
	{
		C.Encolar(nodoR);
		while(!(C.esVacia()))
		{
		
			cout<<" "<<C.Frente()->getElemento();
			if(C.Frente()->getHijoI()!=NULL)
			{
				C.Encolar(C.Frente()->getHijoI());
			}
		
			if(C.Frente()->getHijoD()!=NULL)
			{
				C.Encolar(C.Frente()->getHijoD());
			}
		
			C.Desencolar();
		}
	}	
	
	
}


template<class T>
bool Arbin<T>::esNulo()
{
	return (nodoR=NULL);
}//fin



template<class T>
T Arbin<T>::raiz()
{
	return (nodoR->getElemento());
}//fin


template<class T>
Arbin<T> Arbin<T>::hijoI()
{
	Arbin<T> hijo, aux;
	
	aux.nodoR=nodoR->getHijoI();
	hijo.copiar(aux);
	aux.nodoR=NULL;
	return hijo;
}


template<class T>
Arbin<T> Arbin<T>::hijoD()
{
	Arbin<T>  hijo, aux;
	
	aux.nodoR=nodoR->getHijoD();
	hijo.copiar(aux);
	aux.nodoR=NULL;
	return hijo;
}


template<class T>
void Arbin<T>::vaciar()
{
	Pila<NodoArbin<T>* > P;
	NodoArbin<T> *aux;
	
	if(nodoR!=NULL)
	{
		P.Apilar(nodoR);
		while(!(P.esVacia()))
		{
			aux=P.Tope();
			P.Desapilar();
			
			if(aux->getHijoI()!=NULL)
			{
				P.Apilar(aux->getHijoI());
			}
			
			if(aux->getHijoD()!=NULL)
			{
				P.Apilar(aux->getHijoD());
			}
			delete [] aux;
		}
	}
	nodoR=NULL;
}
	


#endif

