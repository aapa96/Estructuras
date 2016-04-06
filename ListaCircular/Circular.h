/*
 * Circular.h
 *
 *  Created on: 6 de abr. de 2016
 *      Author: Alex Andre
 */

#ifndef CIRCULAR_H_
#define CIRCULAR_H_


#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

template<class T>
class Nodo{
public:
	T Dato;
	Nodo<T> *sig;


	Nodo(T A){
		Dato=A;
		sig = 0;
	}
};


template<class T>
class Lista {
public:
	Lista(){Head=Cola=0;Tam = 0;};

	Nodo<T> *Head;
	Nodo<T> *Cola;
	int Tam;

	int tamanio(){
		return Tam;
	}

	void Insert(T a){
		Nodo<T>*Nuevo=new Nodo<T>(a);

		if(Head==0){
			Head = Cola = Nuevo;
			Tam = 1;}
		else{
			Cola->sig = Nuevo;
			Cola = Nuevo;
			Nuevo->sig =Cola;
			Tam++;
		}
	}

	void Show(){

		Nodo<T>*Tmp=Head;
		for(int i = 0;i<tamanio();i++){
			cout<<Tmp->Dato<<endl;
			Tmp = Tmp->sig;
		}

	}


	void printDot(char* p){
		ofstream file(p);
		Nodo<T>*Tmp=Head;
		file<<"digraph {"<<endl;
		for(int i = 0;i<tamanio();i++){
			file<<Tmp->Dato<<"->";
				Tmp = Tmp->sig;
		}
		file<<Head->Dato<<endl;

		file<<" }"<<endl;
	}
};








#endif /* CIRCULAR_H_ */
