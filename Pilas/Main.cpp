/*
 * Main.cpp
 *
 *  Created on: 6 de abr. de 2016
 *      Author: Alex Andre
 */
#include "Pila.h"

int main(){

	Pila<int>  A;
	A.push(3);
	A.push(13);
	A.push(33);
	A.push(43);
	A.push(53);
	cout<<A.Top()<<endl;
	//A.Pop();
	cout<<A.Top()<<endl;
	A.printDot("archivo.dot");
	system("dot -Tpng archivo.dot -o archivo.png");
	return 0;
}

