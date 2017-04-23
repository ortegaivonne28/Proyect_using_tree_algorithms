///////////////////////////////////
//	Realizado por:				///
//	-Ortega Ivonne CI: 20.699.413//
//	-Zerpa Carlos CI: 20.513.226//
//////////////////////////////////

//Declaracion de librerias standards y clases
#include <iostream>
#include "arbolNN.h"
#include "arbolseg.h"
#include <fstream>


using std::cin;
using std::cout;

//proc para inicilizar los arreglos 
void inicializar(long long int E[], long long int L[], long long int H[])
{
	int i;
	
	for(i=1;i<=10000;i++)
	{
		E[i]=-1;
		L[i]=-1;
		H[i]=-1;
	}
}

//principal
int main()
{
	//declaracion de archivos de entrada y salida
	ifstream entrada("EntradaProyecto.in");
	ofstream salida("SalidaProyecto.out");
	
	//declaracion de variables a usar en el codigo
	long long int n=0,i=0,niveles=0,j=0,medidas=0,aux_i=0,aux_j=0,camino=0;
	long long int E[10000];	//arreglo E con todos los nodos visitados en el tour euler
	long long int L[10000];	//arreglo L con todos los niveles de los nodos visitados en el tour euler
	long long int H[10000];	//arreglo H con los indices de las primera ocurrencias del nodo i en el vecto E
	long long int pesos[10000];	//arreglo para almacenar los pesos
	
	
	inicializar(E, L, H);	//procedimiento que inicializa los vectores en -1 para poder realizar el tour euleriano
	
	if(!entrada.good())	//verifica si el archivo de entrada fue abierto exitosamente
		cout<<"No se pudo abrir correctamente el archivo"<<endl;
		
		
	entrada >> n;	//lectura de entero N que va de 1<=N<=1000 nodos
	//cin>>n;
	n--;	//Decrementar el n para que no haga el recorrido la lectura las n veces sino n-1
	niveles=2;	//inicializacion de variables niveles
	entrada >> i >>j;	//lectura de nodo Ai y peso Pi
	//cin>>i>>j;
	
	//Declaracion de arbol NN
	arbolNN<long long int> arbol(i);
	arbol.insertarHijo(i,niveles,pesos,j);////operacion en el se va insertando los hijos
	while(niveles<=n)	//ciclo para terminar de crear e insertar hijos al arbol
	{
		entrada>>i>>j;
		//cin>>i>>j;
		niveles++;
		arbol.insertarHijo(i,niveles,pesos,j);
	}
	arbol.tour(E,L,H);	//operacion donde se ejecuta el tour euler
	
	//declaracion de arbol de segmento
	arbolseg<long long int> segmento(L);
	
	//cin>>n;
	entrada >> n;//lectura de cant de consultas
	while(n>0)//ciclo para realizar las consultas
	{
		camino=0;
		//medidas=0;
		//cin>>n;
		entrada>>aux_i>>aux_j;	//lectura de vertice 'a' y vertice 'b'
		n--;
		i=H[aux_i];//Ubicacion de vertice a en arreglo H
		j=H[aux_j];//Ubicacion de vertice b en arreglo H
		if(i>j)
		{
			j=j+i;
			i=j-i;
			j=j-i;
		}
		niveles=segmento.consultaMenorRango(i,j,L);//Aplicacion de la consultamenorrango
		niveles=E[niveles];//ubicacion de el CMR en el vector E
		i=aux_i;
		j=aux_j;
		//calculos del peso del camino
		camino=((pesos[i])+(pesos[j]));
		camino=camino-(2*(pesos[niveles]));
		if(camino<0)
			camino=camino*(-1);
		
		//salida del camino
		salida<<camino<<" ";
		//cout<<camino<<" ";
	}	
	//cierre de archivos
	entrada.close();
	salida.close();
	return 0;
}
