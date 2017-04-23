#ifndef NODOARBIN_H_
#define NODOARBIN_H_

template<class T>
class NodoArbin
{
	private:
		T e;
		NodoArbin<T> *hijoI, *hijoD;
	
	public:
		NodoArbin<T>();
		NodoArbin<T>(T elem);
		NodoArbin<T>(T e, NodoArbin<T>* hijoI, NodoArbin<T>* hijoD);
		
		T getElemento();
		NodoArbin<T>* getHijoI();
		NodoArbin<T>* getHijoD();
		
		void setElemento(T elem);
		void setHijoI(NodoArbin<T>* P);
		void setHijoD(NodoArbin<T>* P);
		
};

template<class T>
NodoArbin<T>::NodoArbin()
{
	hijoI=NULL;
	hijoD=NULL;
}

template<class T>
NodoArbin<T>::NodoArbin(T elem)
{
	e=elem;
	hijoI=NULL;
	hijoD=NULL;
}

template<class T>
NodoArbin<T>::NodoArbin(T elem, NodoArbin<T>* hijoIzq, NodoArbin<T>* hijoDer)
{
	e=elem;
	hijoI=hijoIzq;
	hijoD=hijoDer;
	
	
}


template<class T>
T NodoArbin<T>::getElemento()
{
	return e;
}

template<class T>
NodoArbin<T>* NodoArbin<T>::getHijoI()
{
	return hijoI;
}

template<class T>
NodoArbin<T>* NodoArbin<T>::getHijoD()
{
	return hijoD;
}

template<class T>
void NodoArbin<T>::setElemento(T elem)
{
	e=elem;
}


template<class T>
void NodoArbin<T>::setHijoI(NodoArbin<T>* P)
{
	hijoI=P;
}

template<class T>
void NodoArbin<T>::setHijoD(NodoArbin<T>* P)
{
	hijoD=P;
}




#endif
