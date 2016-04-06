/*
 * Main.cpp
 *
 *  Created on: 6 de abr. de 2016
 *      Author: Alex Andre
 */



#include "Lista.h"



int main(){

	lista a;
	for(int i= 0;i<=20;i++){
		a.agregar(i);
	}
	a.show();
	//cout<<a.tam();
	a.printDot("archivo.dot");

	system("dot -Tpng archivo.dot -o archivo.png");

	return 0;
}



