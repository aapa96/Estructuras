/*
 * arbol.h
 *
 *  Created on: 10 de abr. de 2016
 *      Author: Alex Andre
 */

#ifndef ARBOL_H_
#define ARBOL_H_
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Nodo
{
public:
T Dato;
Nodo<T> *Hijo[2];
Nodo(T d)
{
	Dato=d;
	Hijo[0]=Hijo[1]=0;
}
};

template<class T>
class Arbol
{
public:
Nodo<T> *Raiz;
	Arbol()
	{
		Raiz=0;
	}

	bool Buscar(T d,Nodo<T> **&p)
	{
		p=&Raiz;
		while(*p)
		{
			if((*p)->Dato==d)return true;
			p=&((*p)->Hijo[(*p)->Dato<d]);

		}
		return false;
	}

	void Agregar(T d)
	{
		Nodo<T> **q;
		if(Buscar(d,q))
			return;
		*q=new Nodo<T>(d);

	}
	void ShowA(Nodo<T> *n)
	{
		if(n!=0){
			cout<<(n->Dato)<<endl;
			ShowA( n->Hijo[0] );
			ShowA( n->Hijo[1] );
		}
	}
	void ShowB(Nodo<T> *n)
	{
		if(n!=0){

			ShowB( n->Hijo[0] );
			cout<<(n->Dato)<<endl;
			ShowB( n->Hijo[1] );
		}
	}
	void ShowC(Nodo<T> *n)
	{
		if(n!=0){

			ShowC( n->Hijo[0] );
			ShowC( n->Hijo[1] );
			cout<<(n->Dato)<<endl;
		}
	}
	void PrintDot(Nodo<T> *n, ofstream & x)
	{
		if(n!=0){
			 if(n->Hijo[0])  x<<n->Dato<<"->"<<n->Hijo[0]->Dato<<endl;
			 if(n->Hijo[1])  x<<n->Dato<<"->"<<n->Hijo[1]->Dato<<endl;
			 PrintDot(n->Hijo[0],x);
			 PrintDot(n->Hijo[1],x);
		}

	}
	void Printdot(const char *p){
		ofstream file(p);
		file<<"digraph {"<<endl;
		PrintDot(this->Raiz,file);
		file<<" }"<<endl;
	}

};



#endif /* ARBOL_H_ */
