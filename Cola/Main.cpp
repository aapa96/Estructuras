/*
 * Main.cpp
 *
 *  Created on: 6 de abr. de 2016
 *      Author: Alex Andre
 */

#include "Cola.h"
int main(){
	Cola<int> a;
	a.Encolar(5);
	a.Encolar(4);
	a.Encolar(2);
	a.Encolar(1);
	a.Show();
	a.Desencolar();
	a.Show();
	a.printDot("archivo.dot");
	system("dot -Tpng archivo.dot -o archivo.png");
	return 0;

}


