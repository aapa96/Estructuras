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



class node{
public:


	node(int );
	int getDato();
	node *getSig();
	void setNext(node*);


	int valor;
	node *sig;


};

class lista{
public:

	lista();
	void agregar(int );
	void show();
	void borrar(int);
	int tam();

	void printDot(const char*);


	int tama;
	node *head;

};



#endif /* LISTA_H_ */
