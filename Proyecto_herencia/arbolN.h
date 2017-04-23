//Declaracion de clase Arbol N
#ifndef ARBOLN_H_
#define ARBOLN_H_

//declaracion de librerias y clases
#include <iostream>
#include "nodoarbol.h"
#include "lista.h"

using std::cout;

//declaracion de clase arbol N
template <class T>
class arbolN
{
	private:
		//atributos
		nodoarbol<T> *nodoraiz;
		
		//metodos privados
		void recorridopreorden(nodoarbol<T> *ptrRaiz);
		void recorridoinorden(nodoarbol<T> *ptrRaiz);
		nodoarbol<T>* copiar_nodos(nodoarbol<T>*ptr);
		void Eliminar_nodos(nodoarbol<T> *ptr);
	public:
		//metodos publicos
		//constructores y destructores
		arbolN<T>();
		arbolN<T>(T e,lista<arbolN<T> > lst);
		arbolN<T>(T e);
		~arbolN<T>(); 
		void destruir();
		nodoarbol<T> copiar();
		
		//Consultores
		bool esNulo();
		T raiz();
		lista<arbolN<T> > hijos();
		
		//Modificadores
		void insertarsubarbol(arbolN<T> arbol);
		void eliminarsubarbol(int pos);
		
		
		//Recorridos
		void preorden();
		void inorden();
		
		
		
};//f_class

template<class T>
nodoarbol<T>* arbolN<T>::copiar_nodos(nodoarbol<T>* ptr)
{
	nodoarbol<T> *nuevo;
	
	if(ptr==NULL)
	{
		return NULL;
	}else
	{
		nuevo = new nodoarbol<T>(ptr->getelemento(), copiar_nodos(ptr->gethijoizquierdo()), copiar_nodos(ptr->gethermanoderecho()));
		return nuevo;
	}//f_if-else
	
}//f_func

template <class T>
void arbolN<T>::Eliminar_nodos(nodoarbol<T> *ptr)
{
	nodoarbol<T> *aux;
	
	if(ptr!=NULL)
	{
		aux=ptr->gethijoizquierdo();
		while(aux!=NULL)
		{
			Eliminar_nodos(aux);
			aux=aux->gethermanoderecho();
		}//f_while
		delete [] ptr;
	}//f_if
	
}//f_void

template<class T>
void arbolN<T>::destruir()
{
	Eliminar_nodos(nodoraiz);
}//f_void

template <class T>
arbolN<T>::arbolN()
{
	nodoraiz=NULL;
}//f_void

template <class T>
arbolN<T>::arbolN(T e,lista<arbolN<T> > lst)
{
	nodoarbol<T> *aux;
	int i,longit;
	
	nodoraiz= new nodoarbol<T>;
	nodoraiz->setelemento(e);
	nodoraiz->sethermanoderecho(NULL);
	longit=lst.longitud();
	
	if(longit==0)
		nodoraiz->sethijoizquierdo(NULL);
	else
	{
		nodoraiz->sethijoizquierdo(lst.consultar(1).nodoraiz);
		aux=nodoraiz->gethijoizquierdo();
		for(i=2;i<=longit;i++)
		{
			aux->sethermanoderecho(lst.consultar(i).nodoraiz);
			aux=aux->gethermanoderecho();
		}//f_for
		aux->sethermanoderecho(NULL);
	}//f_else
}//f_void

template <class T>
arbolN<T>::arbolN(T e)
{
	nodoraiz= new nodoarbol<T>();
	nodoraiz->setelemento(e);
	nodoraiz->sethermanoderecho(NULL);
	nodoraiz->sethijoizquierdo(NULL);
}//f_void

template <class T>
bool arbolN<T>::esNulo()
{
	return (nodoraiz==NULL);
}//f_func

template <class T>
T arbolN<T>::raiz()
{
	return (nodoraiz->getelemento());
}//f_func

template <class T>
lista<arbolN<T> > arbolN<T>::hijos()
{
	nodoarbol<T> *aux;
	arbolN<T> arbolaux;
	lista<arbolN<T> > lst;
	
	aux=nodoraiz->gethijoizquierdo();
	while(aux!=NULL)
	{
		arbolaux.nodoraiz=aux;
		lst.insertar(arbolaux,lst,lst.longitud+1);
		aux=aux->gethermanoderecho();
	}//f_while
	
	return lst;
}//f_func

template <class T>
void arbolN<T>::eliminarsubarbol(int pos)
{
	nodoarbol<T> *aux;
	arbolN<T> subarbol;
	
	int i;
	if(pos==1)
	{
		subarbol.nodoraiz=nodoraiz->gethijoizquierdo();
		nodoraiz->sethijoizquierdo(nodoraiz->gethijoizquierdo()->gethermanoderecho());
	}//f_if
	else
	{
		aux=nodoraiz->gethijoizquierdo();
		for(i=2;i<=pos-1;i++)
		{
			aux=aux->gethermanoderecho();
		}//f_for
		subarbol.nodoraiz=aux->gethermanoderecho();
		aux->sethermanoderecho((aux->gethermanoderecho())->gethermanoderecho());
	}//f_else
	subarbol.nodoraiz.sethermanoderecho(NULL);
	
}//f_void

template <class T>
void arbolN<T>::insertarsubarbol(arbolN<T> arbol)
{
	nodoarbol<T>* aux;
	
	if(nodoraiz->gethijoizquierdo()==NULL)
		nodoraiz->sethijoizquierdo(arbol.nodoraiz);
	else
	{
		aux=nodoraiz->gethijoizquierdo();
		while(aux.gethermanoderecho()!=NULL)
		{
			aux=aux->gethermanoderecho();
		}//f_while
		aux->sethermanoderecho(arbol.nodoraiz);
	}//f_else
}//f_void

template <class T>
void arbolN<T>::preorden()
{
	recorridopreorden(nodoraiz);
}//f_void

template <class T>
void arbolN<T>::recorridopreorden(nodoarbol<T> *ptrRaiz)
{
	nodoarbol<T> *aux;
	
	if(ptrRaiz!=NULL)
	{
		cout << " " << ptrRaiz->getpeso();
		aux=ptrRaiz->gethijoizquierdo();
		while(aux!=NULL)
		{
			recorridopreorden(aux);
			aux=aux->gethermanoderecho();
		}//f_while
	}//f_if
}//f_void



template <class T>
arbolN<T>::~arbolN()
{
	destruir();
}//f_void


template <class T>
void arbolN<T>::inorden()
{
	recorridoinorden(nodoraiz);
}//f_void

template <class T>
void arbolN<T>::recorridoinorden(nodoarbol<T> *ptrRaiz)
{
	nodoarbol<T> *aux;
	
	if(ptrRaiz!=NULL)
	{
		recorridoinorden(ptrRaiz->gethijoizquierdo());
		cout << "" << nodoraiz->getelemento();
		aux=ptrRaiz->gethijoizquierdo();
		while(aux!=NULL)
		{
			recorridoinorden(aux);
			aux=aux->gethermanoderecho();
		}//f_while
	}//f_if
}//f_void

#endif
