//Definicion de clase arbol de segmento//
#ifndef ARBOLSEG_H_
#define ARBOLSEG_H_

//Declaracion de librerias standards y clases//
#include "nodoseg.h"
#include <iostream>
#include "pila.h"
using std::cout;

//Declaracion de clase arbol de segmento//
template<class T>
class arbolseg
{
	private:
		//Atributos de tipo privado de la clase//
		nodoseg<T> *nodoR;
	
	//Metodos de tipo publico de la clase//
	public:
		/// *Constructores y destructores*///
		arbolseg<T>();	//constructor por defecto
		//arbolseg<T>(long long int n,long long int vector[]);
		arbolseg<T>(long long int vector[]);//Constructor por parametros, donde es llamado el metodo crear y se le pasa el apuntador a nodoraiz de arbol de segmento//
		void vaciar();
		arbolseg<T>(T elem);
		~arbolseg<T>();	//destructor que invoca a vaciar
		void construir(nodoseg<T> *ptrRaiz,long long int vector[]);//metodo recursivo donde hace movimiento con apuntadores despues de crear un nodo de tipo arbol de segmento//
	

		///  *CONSULTAS*///
		long long int menor(long long int a,long long int b,long long int L[]);//metodo que devuelve el elemento menor del vector 'L' donde 'a' y b' representan los indices

	
		long long int CMR_recursivo(nodoseg<T> *ptrRaiz, long long int x, long long int y,long long int L[]);	//Consulta menor rango en esta funcion se utiliza un apuntador a nodo arbol de segmento para moverse sobre el arbol y recorrer hijo izquierdo e hijo derecho, recibe los indices que representarian los intervalos de las consultar y el vector L para determinar el indice de menor rango
		long long int consultaMenorRango(long long int x,long long int y,long long int L[]);//Metodo que llama al metodo recursivo que se mueve con un apuntador pasandole el apuntador a nodo raiz del arbol de segmento
};//f_class

/// ********************************************************************** ///
///								***Constructores***						   ///
/// ///////////////////////////////////////////////////////////////////// ///



template<class T>
arbolseg<T>::arbolseg()
{
	nodoR=NULL;
}//fin


template<class T>
arbolseg<T>::arbolseg(long long int vector[])
{//inicio
	//var
	long long int longitud=1,menor=-1,menoor=-1;
	nodoseg<T> *nuevo;
	
	menoor=longitud;
	menor=vector[longitud+1];
	while(vector[longitud]!=-1)
	{
		if(menor>vector[longitud])
		{
			menor=vector[longitud];
			menoor=longitud;
		}//f_if
		longitud++;
		
	}//f_while
	longitud--;
	nuevo = new nodoseg<T>;
	nodoR=nuevo;
	nodoR->setElemento(menoor);
	nodoR->seti(1);
	nodoR->setj(longitud);
	construir(nodoR,vector);
}//f_void


template <class T>
void arbolseg<T>::construir(nodoseg<T> *ptrRaiz,long long int vector[])
{//inicio
	//var
	long long int aux_i,aux_j,menor=-1,x,menoor=-1;
	nodoseg<T> *aux;
	
	if((ptrRaiz->geti())!=(ptrRaiz->getj()))
	{
		aux_i=ptrRaiz->geti();
		aux_j=ptrRaiz->getj();
		aux_j=(aux_i+aux_j)/2;
		menor=vector[aux_i];
		menoor=aux_i;
		for(x=aux_i+1;x<=aux_j;x++)
		{
			if(menor>vector[x])
			{
				menor=vector[x];
				menoor=x;
			}//f_if
		}//f_for
		aux = new nodoseg<T>;
		aux->setElemento(menoor);
		aux->seti(aux_i);
		aux->setj(aux_j);
		ptrRaiz->setHijoI(aux);
		construir(aux,vector);
		aux_j=ptrRaiz->getj();
		aux_i=ptrRaiz->geti();
		aux_i=(((aux_i+aux_j)/2)+1);
		menor=vector[aux_i];
		menoor=aux_i;
		for(x=aux_i+1;x<=aux_j;x++)
		{
			if(menor>vector[x])
			{
				menor=vector[x];
				menoor=x;
			}//f_if
		}//f_for
		aux = new nodoseg<T>;
		aux->setElemento(menoor);
		aux->seti(aux_i);
		aux->setj(aux_j);
		ptrRaiz->setHijoD(aux);
		construir(aux,vector);
		
	}//f_if
}//f_void


template<class T>
arbolseg<T>::arbolseg(T elem)
{
	nodoR=new nodoseg<T>(elem, NULL, NULL);
}

template<class T>
void arbolseg<T>::vaciar()
{
	pila<nodoseg<T>* > P;
	nodoseg<T> *aux;
	
	if(nodoR!=NULL)
	{
		P.apilar(nodoR);
		while(!(P.esVacia()))
		{
			aux=P.topee();
			P.desapilar();
			
			if(aux->getHijoI()!=NULL)
			{
				P.apilar(aux->getHijoI());
			}//f_if
			
			if(aux->getHijoD()!=NULL)
			{
				P.apilar(aux->getHijoD());
			}//f_if
			delete [] aux;
		}//f_while
	}//f_if
	nodoR=NULL;
}//f_void

template<class T>
arbolseg<T>::~arbolseg()
{
	vaciar();
}//f_void

/// *********************************************************************************************** ///
/// /////////////				***Consultas***						///////////////////////////////////
/// /////////////////////////////////////////////////////////////////////////////////////////////// ///


template <class T>
long long int arbolseg<T>::consultaMenorRango(long long int x,long long int y,long long int L[])
{
	return (CMR_recursivo(nodoR,x,y,L));
}

template <class T>
long long int arbolseg<T>::CMR_recursivo(nodoseg<T> *ptrRaiz, long long int x, long long int y,long long int L[])
{//inicio
	//var
	long long int aux_i,aux_j,a,b,z;
	
	aux_i=ptrRaiz->geti();
	aux_j=ptrRaiz->getj();
	if((aux_i==x)&&(aux_j==y))
	{
		return (ptrRaiz->getElemento());
	}//f_if
	else
	{
		if(((x<=(aux_i+aux_j)/2)&&(y>=((aux_i+aux_j)/2)+1)))
		{
			
			z=(aux_i+aux_j)/2;
			z++;
			
			return (menor((CMR_recursivo(ptrRaiz->getHijoI(),x,(aux_i+aux_j)/2,L)),(CMR_recursivo(ptrRaiz->getHijoD(),z,y,L)),L));
		}//f_if
		else
		{
			if((x<=(aux_i+aux_j)/2)&&(y<=((aux_i+aux_j)/2)+1))
			{
				return (CMR_recursivo(ptrRaiz->getHijoI(),x,y,L));
			}//f_if
			else
			{
				return (CMR_recursivo(ptrRaiz->getHijoD(),x,y,L));
			}//f_else
		}//f_else
	}//f_else
}//f_func

template <class T>
long long int arbolseg<T>::menor(long long int a,long long int b,long long int L[])
{//inicio

	if(L[a]>L[b])
		return b;
	else
		return a;
}//f_func


#endif

