/*
 * Pila.h
 *
 *  Created on: 6 de abr. de 2016
 *      Author: Alex Andre
 */

#ifndef PILA_H_
#define PILA_H_

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

template<class T>
class Nodo{
public:
	T Dato;
	Nodo<T> *ant;

    Nodo(T D)
    {
       Dato = D;
       ant =0;
    }
};


template<class T>
class Pila {
public:
	Pila(){
			Last=0;
		}
	Nodo<T> *Last;

	int Tam;

	bool istmpy(){
			if(Last==0)
				return true;
			else
				return false;
		}
	int tamanio(){
		return Tam;
	}

	void push(T d){
		Nodo<T> *pNuevo = new Nodo<T> (d);
		if(Last == 0){
			Last = pNuevo;
			Tam = 1;}
		else{
			pNuevo->ant=Last;
			Last = pNuevo;
			Tam++;
		}
	}

	T Top(){
		return Last->Dato;
	}

	void Pop(){
		if(istmpy())
			return;
		else
		{
			Nodo<T> *tmp = Last->ant;
			delete Last;
			Last= tmp;
			Tam--;
		}
	}
	void Show(){
		Nodo<T>*Tmp=Last;
		for(int i = 0;i<tamanio();i++){
			cout<<Tmp->Dato<<endl;
			Tmp = Tmp->ant;
		}
	}


	void printDot(const char* p){
		ofstream file(p);
		Nodo<T>*Tmp=Last;
		file<<"digraph {"<<endl;
		while(Tmp->ant != 0){
			file<<Tmp->Dato<<"->";
			Tmp = Tmp->ant;
		}
		file<<Tmp->Dato<<endl;


		file<<" }"<<endl;
 	}
};



	void Evaluar(){
		string A;
		cin>>A;
		Pila<string> x;
		//string A = "Hola";
		for(unsigned i=0;i<A.size();i++){
			if(A[i] == '('){
				cout<<A[i]<<" Parentesis"<<endl;
				x.Apilar("(");
			}
			else(A[i] == ')'){
				if(x.istmpy())
					cout<<"Error"<<endl;
				else{
					cout<<"Correcto"<<endl;
					x.Desapilar();

					}
			}
		}
		x.Show();
	}


#endif /* PILA_H_ */
