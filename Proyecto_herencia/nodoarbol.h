//definicion de libreria nodoarbol
#ifndef NODOARBOL_H_
#define NODOARBOL_H_
//declaracion de libreria standards
#include <iostream>

//declaracion de clase con atributos un tipo T elemento y un apuntador a H.izquierdo y Hno.Derecho
template <class T>
class nodoarbol
{
	private:
		//atributos
		T elem;
		nodoarbol<T> *HI,*HD;
	public:
		//Constructores y destructores
		nodoarbol<T>();
		nodoarbol<T>(T e);
		nodoarbol<T>(T e,nodoarbol<T> *hijoI,nodoarbol<T> *herD);
		//~nodoarbol<T>();
		
		//consultores
		T getelemento();
		nodoarbol<T>* gethijoizquierdo();
		nodoarbol<T>* gethermanoderecho();
		bool vacio();
		
		//modificadores
		void setelemento(T e);
		void sethijoizquierdo(nodoarbol<T> *p);
		void sethermanoderecho(nodoarbol<T> *p);
		void conectar(nodoarbol<T>& nhi,nodoarbol<T>& nhd);
		
};//f_class

template <class T>
bool nodoarbol<T>::vacio()
{
	return((HI==NULL)&&(HD==NULL));	
}

template <class T>
nodoarbol<T>::nodoarbol()
{
	HI=NULL;
	HD=NULL;
}

template <class T>
nodoarbol<T>::nodoarbol(T e)
{
	HI=NULL;
	HD=NULL;
	elem=e;
}

template <class T>
nodoarbol<T>::nodoarbol(T e,nodoarbol<T> *hijoI,nodoarbol<T> *herD)
{
	elem=e;
	HI=hijoI;
	HD=herD;
}

template <class T>
T nodoarbol<T>::getelemento()
{
	return elem;
}

template <class T>
nodoarbol<T>* nodoarbol<T>:: gethijoizquierdo()
{
	return HI;
}

template <class T>
nodoarbol<T>* nodoarbol<T>:: gethermanoderecho()
{
	return HD;
}

template <class T>
void nodoarbol<T>::setelemento(T e)
{
	elem=e;
}

template <class T>
void nodoarbol<T>::sethijoizquierdo(nodoarbol<T> *p)
{
	HI=p;
}

template <class T>
void nodoarbol<T>::sethermanoderecho(nodoarbol<T> *p)
{
	HD=p;
}


template<class T>
void nodoarbol<T>::conectar(nodoarbol<T>& nhi,nodoarbol<T>& nhd)
{
	nodoarbol<T> *p;
	//if(!nhi.vacio())
	//{
		p=new nodoarbol<T>(nhi.getelemento(),nhi.gethijoizquierdo(),nhi.gethermanoderecho());
		HI=p;
	//}
	//else
	//	HI=NULL;
	//if(!nhd.vacio())
	//{
		p=new nodoarbol<T>(nhd.getelemento(),nhd.gethijoizquierdo(),nhd.gethermanoderecho());
		HD=p;
	//}
	//else
	//	HD=NULL;
}

#endif
