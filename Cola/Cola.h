/*
 * Cola.h
 *
 *  Created on: 6 de abr. de 2016
 *      Author: Alex Andre
 */

#ifndef COLA_H_
#define COLA_H_



#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

template<class T>
class Nodo{
public:
	T Dato;
	Nodo<T> *sig;

    Nodo(T D)
    {
       Dato = D;
       sig =0;
    }
};


template<class T>
class Cola {
public:
	Cola(){
			Head=Last=0;
			Tam = 0;
		}
	Nodo<T> *Head;
	Nodo<T> *Last;

	int Tam;

	bool isLasty(){
			if(Head==0)
				return true;
			else
				return false;
		}
	int tamanio(){
		return Tam;
	}

	void Encolar(T d){
		Nodo<T> *Nuevo = new Nodo<T> (d);
		if(Head == 0){
			Head = Nuevo;
			Tam = 1;}
		else{
			Last->sig=Nuevo;

			Tam++;
		}
		Last = Nuevo;
	}

	T Top(){
		return Head->Dato;
	}

	void Desencolar(){
		if(isLasty())
			cout<<"Vacio"<<endl;
		else
		{
			Nodo<T> *Tmp = Head;
			Head = Head->sig;
			delete Tmp;

			Tam--;
		}
	}
	void Show(){
		Nodo<T>*Tmp=Head;
		while(Tmp !=0){
			cout<<Tmp->Dato<<endl;
			Tmp=Tmp->sig;
		}
	}


	void printDot(const char* p){
		ofstream file(p);
		Nodo<T>*Tmp=Head;
		file<<"digraph {"<<endl;
		while(Tmp->sig != 0){
			file<<Tmp->Dato<<"->";
			Tmp = Tmp->sig;
		}
		file<<Tmp->Dato<<endl;
		file<<" }"<<endl;
 	}
};






#endif /* COLA_H_ */
