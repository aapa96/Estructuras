/*
 * Lista.cpp
 *
 *  Created on: 6 de abr. de 2016
 *      Author: Alex Andre
 */



#include "Lista.h"
#include <stdlib.h>



node::node(int v){
	valor = v;
	sig =0;
}
int node::getDato(){
	return valor;
}

node* node::getSig(){
	return sig;
}
void node::setNext(node* nuevo){
	sig = nuevo;
}




lista::lista(){
	head = 0;
	tama = 0;
}


void lista::agregar(int a){
	node* nuevo =new node(a);
	if(head == 0){
		head = nuevo;
		tama = 1;}
	else{

		node * ptemp = head;
		while(ptemp->sig!=0){
			ptemp=ptemp->sig;
		}
		ptemp->setNext(nuevo);
		tama ++;


	}

}



void lista::show(){
	if(head == 0) cout<<"Lista vacia"<<endl;

	else{
		node* tmp = head;
		while(tmp->sig!=0){

			cout<<tmp->getDato()<<endl;
			tmp = tmp->sig;

		}
		cout<<tmp->getDato()<<endl;
	}
}

void lista::printDot(const char* p){
	ofstream file(p);
	node* tmp=head;
	file<<"digraph {"<<endl;

	while(tmp -> sig != 0){
		file<<tmp->getDato()<<"->";
		tmp = tmp->sig;
	}
	file<<tmp->getDato()<<endl;
	for(int i = 0;i<20;i++){
		file<<i<<" [shape=box,sides=1,peripheries=2,color=indigo,style=dotted];"<<endl;
	}
	file<<" }"<<endl;
}


int lista::tam(){
	return tama;
}

void lista::borrar(int a){
	if(head == 0) cout<<"Lista vacia"<<endl;
	else{

		node *tmp1 = head;
		node *tmp2 = 0;

		while(tmp1 != 0 && tmp2->getDato()!= a){
			tmp2 = tmp1;
			tmp1 = tmp1->sig;

		}
		if(tmp1==0){
			cout<<"Nodo no encontrado"<<endl;
		}
		else{
			tmp2->sig = tmp1->sig;

		}
		delete tmp1;



	}

}


