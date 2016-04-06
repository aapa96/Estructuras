/*
 * Lista.h
 *
 *  Created on: 6 de abr. de 2016
 *      Author: Alex Andre
 */

#ifndef LISTA_H_
#define LISTA_H_



#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

template<class T>
class Nodo{
public:
	T Dato;
	Nodo<T> *sig;
	Nodo<T> *ant;

	Nodo(T A){
		Dato=A;
		sig = ant = 0;
	}
};


template<class T>
class Lista {
public:
	Lista(){Head=Cola=0;};

	Nodo<T> *Head;
	Nodo<T> *Cola;
	int Tam;

	Nodo<T>* Primero(){
		return Head;
	}
	Nodo<T>* Ultima(){
		Nodo<T>*Tmp=Head;
		if(Head != 0){
			while(Tmp->sig)
				Tmp =Tmp->sig;
		}
		return Tmp;
	}
	int tamanio(){
		return Tam;
	}

	void Insert(T a){
		Nodo<T>*Nuevo=new Nodo<T>(a);
		Nodo<T>*Tmp = Ultima();
		if(Head==0){
			Head = Nuevo;
			Tam = 1;}
		else{
			Tmp->sig = Nuevo;
			Nuevo->ant =Tmp;
			Tam++;
		}
	}

	void Show(){

		Nodo<T>*Tmp=Head;
		if(Head!=0){
			while(Tmp){
				cout<<Tmp->Dato<<endl;
				Tmp = Tmp->sig;
			}
		}
	}

	void Showrevez(){

		Nodo<T>*Tmp=Ultima();
		if(Head!=0){
			while(Tmp){
				cout<<Tmp->Dato<<endl;
				Tmp = Tmp->ant;
			}
		}
	}

	void printDot(const char* p){
		ofstream file(p);
		//Nodo<T>* tmp=Primero();
		Nodo<T>* tmp2=Ultima();
		file<<"digraph {"<<endl;

		while(tmp2->ant != 0){
			file<<tmp2->Dato<<"->"<<tmp2->ant->Dato<<endl;
			file<<tmp2->ant->Dato<<"->"<<tmp2->Dato<<endl;
			tmp2 = tmp2->ant;
		}

		file<<" }"<<endl;
	}
};


#endif /* LISTA_H_ */
