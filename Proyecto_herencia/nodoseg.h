#ifndef NODOSEG_H_
#define NODOSEG_H_

template<class T>
class nodoseg
{
	private:
		T e;
		int i,j;
		nodoseg<T> *hijoI, *hijoD;
	
	public:
		nodoseg<T>();
		nodoseg<T>(T elem);
		nodoseg<T>(T e, nodoseg<T>* hijoI, nodoseg<T>* hijoD);
		
		T getElemento();
		nodoseg<T>* getHijoI();
		nodoseg<T>* getHijoD();
		int geti();
		int getj();
		
		void setElemento(T elem);
		void setHijoI(nodoseg<T>* P);
		void setHijoD(nodoseg<T>* P);
		void seti(int x);
		void setj(int y);
		
};

template<class T>
nodoseg<T>::nodoseg()
{
	hijoI=NULL;
	hijoD=NULL;
}

template<class T>
nodoseg<T>::nodoseg(T elem)
{
	e=elem;
	hijoI=NULL;
	hijoD=NULL;
}

template<class T>
nodoseg<T>::nodoseg(T elem, nodoseg<T>* hijoIzq, nodoseg<T>* hijoDer)
{
	e=elem;
	hijoI=hijoIzq;
	hijoD=hijoDer;
	
	
}


template<class T>
T nodoseg<T>::getElemento()
{
	return e;
}

template<class T>
nodoseg<T>* nodoseg<T>::getHijoI()
{
	return hijoI;
}

template<class T>
nodoseg<T>* nodoseg<T>::getHijoD()
{
	return hijoD;
}

template <class T>
int nodoseg<T>::geti()
{
	return i;
}

template <class T>
int nodoseg<T>::getj()
{
	return j;
}

template<class T>
void nodoseg<T>::setElemento(T elem)
{
	e=elem;
}


template<class T>
void nodoseg<T>::setHijoI(nodoseg<T>* P)
{
	hijoI=P;
}

template<class T>
void nodoseg<T>::setHijoD(nodoseg<T>* P)
{
	hijoD=P;
}

template <class T>
void nodoseg<T>::seti(int x)
{
	i=x;
}

template <class T>
void nodoseg<T>::setj(int y)
{
	j=y;
}


#endif
