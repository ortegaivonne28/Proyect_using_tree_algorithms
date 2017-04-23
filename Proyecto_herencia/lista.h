/* Implementacion de lista usando templates y apuntadores*/

#ifndef LISTA_H_
#define LISTA_H_
#include <iostream>
#include "nodo.h"

using namespace std;


template<class T>
class lista
{
	//Atributos
	private:
		nodo<T> *prim;
		int longi;
	//Metodos
	public:
		lista<T>();
		lista<T>(const lista<T> &Copia);
		bool esVacia();
		void insertar(T e, int posicion);
		void eliminar(int posicion);
		int longitud();
		T consultar(int posicion);
		void Invertir();
		lista<T> Sublista(int i, int j);
		void Imprimir();
		lista<T> operator=(const lista<T> &list);
		~lista<T>();
		
};	//fin clase

template<class T>
lista<T>::lista()
{
	prim=NULL;
	longi=0;
}//fin void


template<class T>
lista<T>::lista(const lista<T> &list)	//Constructor Copia
{	
	nodo<T> *aux, *insert, *creator;
	
	longi = list.longi;
	if(list.prim != NULL){
		prim = new nodo<T> (list.prim->obtenerelemento(), NULL);
		aux = list.prim->siguiente();	
		insert = prim;
		while(aux != NULL){
			creator = new nodo<T>(aux->obtenerelemento(), NULL);
			insert->modificarsiguiente(creator);
			aux = aux->siguiente();
			insert = insert->siguiente();
		}
	}else{
		prim = NULL;
	}
}

template<class T>
bool lista<T>::esVacia()
{
	return (prim=NULL);
}//fin func

template<class T>
void lista<T>::insertar(T e, int posicion)
{
	nodo<T> *nuevo, *ant, *sig;
	int i;
	
	nuevo=new nodo<T>(e, NULL);
	
	if(posicion==1)
	{
		
		nuevo->modificarsiguiente(prim);
		prim=nuevo;
		
		
	}else
	{
		ant=prim;
		sig=ant->siguiente();
		i=2;
		
		while((i<posicion)&&(sig!=NULL))
		{
			ant=sig;
			sig=sig->siguiente();
			i++;
		}//fin while
		
		ant->modificarsiguiente(nuevo);
		nuevo->modificarsiguiente(sig);
		
		
	
	}//Fin else
	
	longi++;
}//fin void

template<class T>
void lista<T>::eliminar(int posicion)
{
	nodo<T> *ant, *act, *sig;
	int i;
	
	if(posicion==1)
	{
		act=prim;
		prim=act->siguiente();
		delete [] act;
	}else
	{
		ant=prim;
		act=ant->siguiente();
		sig=act->siguiente();
		i=2;
		
		while((i<posicion) && (sig!=NULL))
		{
			ant=act;
			act=sig;
			sig=sig->siguiente();
			i++;
			
		}//fin while
		
		if(i==posicion)
		{
			ant->modificarsiguiente(sig);
			delete [] act;
		}//fin if
		
	}//Fin if-else
	
	longi--;
}//fin void


template<class T>
int lista<T>::longitud()
{
	return longi;
}//fin func


template<class T> 
T lista<T>::consultar(int posicion)
{
	int i;
	nodo<T> *act;
	
	
		if(posicion<=longitud())
		{
			act = prim;
			
			for(i=1;i<posicion;i++)
			{
				act = act->siguiente();
			}//fin for
		
			
		}
		
		
		return act->obtenerelemento();

}	//fin func


template<class T>
void lista<T>::Invertir()
{
	nodo<T> *ant, *act, *sig;
	
	ant=NULL;
	act=prim;
	
	while(act->siguiente()!=NULL)
	{
		sig=act->siguiente();
		act->modificarsiguiente(ant);
		ant=act;
		act=sig;
		
	}//fin while
	
	prim=ant;

}//fin void


template<class T>
lista<T> lista<T>::Sublista(int i, int j)
{
	lista<T> nuevalist;
	nodo<T> *act, *nuevo, *ult;
	int k;
	
	act=prim;
	k=1;
	
	while((k<i)&&(act!=NULL))
	{
		
		act=act->siguiente();
		k++;		
	}//fin while
	
	if(act!=NULL)
	{
		nuevo=new nodo<T>(act->ObtenerElemento(), NULL);
		nuevalist.prim=nuevo;
		nuevalist.longi=1;
		ult=nuevalist.prim;
		act=act->siguiente();
		k++;
		
		while((k<=j) && (act!=NULL))
		{
			nuevo= new nodo<T>(act->ObtenerElemento(), NULL);
			ult->modificarsiguiente(nuevo);
			ult=ult->siguiente();
			nuevalist.longi++;
			act=act->siguiente();
			k++;
		}//fin while
	}//fin if
	
	return nuevalist;
}//fin func
		

template<class T>
void lista<T>::Imprimir()
{
	int i;
	
	for(i=1;i<longitud();i++)
	{
		cout<<" "<<consultar(i)<<endl;
	} //fin for
	
}//fin void


template<class T>
lista<T> lista<T>::operator=(const lista<T> &list)
{
	nodo<T> *aux, *insert, *creator;
	
	longi = list.longi;
	if(list.prim != NULL)
	{
		prim = new nodo<T> (list.prim->ObtenerElemento(), NULL);
		aux = list.prim->siguiente();	
		insert = prim;
		while(aux != NULL)
		{
			creator = new nodo<T>(aux->ObtenerElemento(), NULL);
			insert->modificarsiguiente(creator);
			aux = aux->siguiente();
			insert = insert->siguiente();
		}
	}else
	{
		prim = NULL;
	}

	


	return *this;
	
	
}


template<class T>
lista<T>::~lista()
{
	nodo<T> *act;
		
	while(prim!=NULL)
	{
		act=prim;
		prim=prim->siguiente();
		delete [] act;
		
	}//fin while

}//fin destructor

#endif
