//Definicion de clase arbolNN que hereda de la clase arbolN//
////////////////////////////////////////////////////////////
#ifndef arbolNN_H_
#define arbolNN_H_

//Declaracion de librerias y clases utilizadas///////
#include <iostream>
#include "nodoarbol.h"
#include "lista.h"
#include "arbolN.h"
using std::cout;

//Declaracion de clase ArbolNN que hereda de arbolN<T> metodos publicos
template <class T>
class arbolNN : public arbolN<T>
{
	//atributos y metodos de tipo privados//
	private:
		//atributos
		nodoarbol<T> *nodoraiz;
		
		//metodos privados
		void nuevo(T posicion,T elemento,nodoarbol<T> *ptrRaiz,long long int vec[],long long int pesos); //metodo privado que se encarga de ir creando los nodos a partir de la lectura de los datos, recibe un apuntado a nodoarbol para irse moviendo en hijo izquierdo y hermano derecho
		void Eliminar_nodos(nodoarbol<T> *ptr);	//metodo privado para ir eliminando los nodos recibe como parametro un apuntador a nodoarbol para moverse en sus hijos
	public://metodos publicos
		
		///Constructores y destructores//
		
		//constructor por defecto
		arbolNN<T>();
		
		//constructor con un parametro: este contructor crea un arbol el cual recibe un parametro que representa el elemento que quiere almacenar en este arbol
		arbolNN<T>(T e);
		
		//destructor: invoca al proc destruir para la eliminacion de los nodos	
		~arbolNN<T>();
		
		 //este proc invoca al metodo privado Eliminar_nodos el cual se le pasa como parametro el nodoraiz
		void destruir();
		
		///Modificadores///
		
		//metodo que invoca al metodo privado nuevo para ir creando un nuevo hijo
		void insertarHijo(T posicion,T elemento,long long int vec[],long long int pesos);
		
		///	Recorridos y procesamiento de informacion//
		void tour(long long int E[],long long int L[],long long int H[]);
		/*
		 * metodo que va llenando los 3 arreglos que representan lo siguiente 
		 * E: Todos los nodos visitados durante el tour euleriano, E[i] contiene el valor del nodo procesado durante la llamada numero i de procesar(v)
		 * L: Niveles de los nodos visitados durante el tour euleriano. L[i] contiene el nivel del nodo E[i]
		 * H: Indices de las primeras ocurrencias del nodo i en el vector E
		 * En este metodo se es invocado el metodo tour Euler
		 * */
		void procesar(nodoarbol<T> *v,long long int E[],long long int L[],long long int H[],long long int x,long long int nivel);
		/*
		 * metodo que va procesando en los arreglos los datos para E, L, H, es invocado en el metodo Tour Euler
		*/
		void tourEuler(nodoarbol<T> *v,long long int E[],long long int L[],long long int H[],long long int &x,long long int nivel);
		/*	Los parametros es un apuntador a nodoarbol para moverse en vertices, los 3 arreglos E, L, H, 
		 * un entero x que indica el indice en que se esta procesando los arreglos, un entero nivel que indica el num de nivel de un vertice 
		 * En este metodo se es invocado el metodo procesar(v)
		 * */
};//f_class



template <class T>
void arbolNN<T>::Eliminar_nodos(nodoarbol<T> *ptr)	//metodo privado para eliminar nodos y poder usar el destructor 
{//inicio

	//var
	nodoarbol<T> *aux;
	
	if(ptr!=NULL)
	{
		aux=ptr->gethijoizquierdo();
		while(aux!=NULL)
		{
			Eliminar_nodos(aux);	//recursion
			aux=aux->gethermanoderecho();
		}//f_while

		delete (ptr);

	}//f_if

	ptr=NULL;

}//f_void



//metodo que llama al metodo privado nuevo() en el se va insertando los hijos
template <class T>
void arbolNN<T>::insertarHijo(T posicion,T elemento,long long int vec[],long long int pesos)
{//inicio

	nuevo(posicion,elemento,nodoraiz,vec,pesos);

}//f_void

template<class T>
void arbolNN<T>::destruir()
{//inicio

	Eliminar_nodos(nodoraiz);

}//f_void

//metodo privado para crear un nuevo hijo e insertarlo en el arbol, recibe un apuntador a nodoarbol para realizar los movimientos en el arbol hacia hijo izquierdo y hermano derecho respectivamente
//tambien recibe como parametro la posicion para verificar si el nodo no ha sido ingresado, el elemento, un vector para almacenar los pesos en cada nodo y una variable peso que da el peso de un arco
template <class T>
void arbolNN<T>::nuevo(T posicion,T elemento,nodoarbol<T> *ptrRaiz,long long int vec[],long long int pesos)
{//inicio

	//var
	nodoarbol<T> *aux,*aux_dos;
	
	if(ptrRaiz->getelemento()==posicion)
	{
		if(ptrRaiz->gethijoizquierdo()==NULL)
		{
			aux= new nodoarbol<T>;
			aux->setelemento(elemento);
			vec[elemento]=pesos+vec[ptrRaiz->getelemento()];
			ptrRaiz->sethijoizquierdo(aux);
		}//f_else
		else
		{
			if(ptrRaiz->gethijoizquierdo()->gethermanoderecho()!=NULL)
			{
				aux= new nodoarbol<T>;
				aux->setelemento(elemento);
				vec[elemento]=pesos+vec[ptrRaiz->getelemento()];
				aux->sethermanoderecho(ptrRaiz->gethijoizquierdo()->gethermanoderecho());
				ptrRaiz->gethijoizquierdo()->sethermanoderecho(aux);
			}//f_if
			else
			{
				aux= new nodoarbol<T>;
				aux->setelemento(elemento);
				vec[elemento]=pesos+vec[ptrRaiz->getelemento()];
				ptrRaiz->gethijoizquierdo()->sethermanoderecho(aux);
			}//f_else
		}//f_else
	}//f_if
	else
	{
		if(ptrRaiz->gethijoizquierdo()!=NULL)
		{
			aux_dos=ptrRaiz->gethijoizquierdo();
			nuevo(posicion,elemento,aux_dos,vec,pesos);
			if(aux_dos->gethermanoderecho()!=NULL)
			{
				while(aux_dos->gethermanoderecho()!=NULL)
				{
					nuevo(posicion,elemento,aux_dos->gethermanoderecho(),vec,pesos);
					aux_dos=aux_dos->gethermanoderecho();
				}//f_while
			}//f_if
		}//f_if
		
	}//f_else
	
}//f_void


template <class T>
arbolNN<T>::arbolNN()
{//inicio
	nodoraiz=NULL;
}//f_void


template <class T>
arbolNN<T>::arbolNN(T e)
{//inicio
	
	nodoraiz= new nodoarbol<T>();
	nodoraiz->setelemento(e);
	nodoraiz->sethermanoderecho(NULL);
	nodoraiz->sethijoizquierdo(NULL);
}//f_void



template <class T>
arbolNN<T>::~arbolNN()
{
	destruir();
}

//metodo que llama al metodo procesar para ir visitando todos los vertices del arbol e irlos procesando en los arreglos E, L, H
template <class T>
void arbolNN<T>::tourEuler(nodoarbol<T> *v,long long int E[],long long int L[],long long int H[],long long int &x,long long int nivel)
{//inicio
	
	//var
	x++;
	nodoarbol<T> *hi;
	
	procesar(v,E,L,H,x,nivel);
	if (v->gethijoizquierdo()!=NULL)
	{
		hi=v->gethijoizquierdo();
		while(hi!=NULL)
		{
			tourEuler(hi,E,L,H,x,nivel+1);
			hi=hi->gethermanoderecho();
			x++;
			procesar(v,E,L,H,x,nivel);
		}//f_while
	}//f_if
}//f_proc

//metodo que es llamado por el metodo tour euleriano donde se van procesando los datos del arbol en los 3 arreglos E, L, H
template <class T>
void arbolNN<T>::procesar(nodoarbol<T> *v,long long int E[],long long int L[],long long int H[],long long int x,long long int nivel)
{//inicio
	//var
	long long int a;

	E[x]=v->getelemento();
	L[x]=nivel;

	if(H[v->getelemento()]==-1)
		H[v->getelemento()]=x;

}//f_void

//metodo que invoca el metodo tour euler donde en el crea los 3 arreglos
template <class T>
void arbolNN<T>::tour(long long int E[],long long int L[],long long int H[])
{//inicio
	long long int a=0;
	long long int b=0;
	tourEuler(nodoraiz,E,L,H,a,b);
}//f_proc


#endif
