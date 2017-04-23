#ifndef NODO_H_
#define NODO_H_


template<class T>
class nodo
{
	//Atributos
	private:
		T elem;
		nodo<T> *prox;
		
	//Metodos
	public:
		nodo<T>();
		//Constructor por parametros
		nodo<T>(T e);	
		nodo<T>(nodo<T>* apunt);
		nodo<T>(T e, nodo<T>* apunt);
		T obtenerelemento();
		nodo<T>* siguiente();
		void modificarsiguiente(nodo<T>* sig);
		void modificarelemento(T e);
		
	



};	//fin clase


template<class T>
nodo<T>::nodo()
{
	//elem();
	prox=NULL;
}//fin constructor

template<class T>
nodo<T>::nodo(T e)
{
	elem=e;
}//fin constructor

template<class T>
nodo<T>::nodo(nodo<T>* apunt)
{
	
	prox=apunt;
}


template<class T>
nodo<T>::nodo(T e, nodo<T>* apunt)
{
	
	elem=e;
	prox=apunt;
	
}


template<class T>
T nodo<T>::obtenerelemento()
{
	return elem;

}	//fin func

template<class T>
nodo<T>* nodo<T>::siguiente()
{
	return prox;
}//fin func

template <class T>
void nodo<T>::modificarsiguiente(nodo<T>* sig)
{
	prox=sig;
}//fin void

template<class T>
void nodo<T>::modificarelemento(T e)
{
	elem=e;
}//fin void

#endif



