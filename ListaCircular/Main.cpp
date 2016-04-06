/*
 * Main.cpp
 *
 *  Created on: 6 de abr. de 2016
 *      Author: Alex Andre
 */



#include "Circular.h"

int main (){
	Lista<int> a;
	a.Insert(5);
	a.Insert(4);
	a.Insert(2);
	a.Insert(1);
	a.Insert(3);
	a.Insert(6);
	a.Insert(8);
	a.Insert(7);
	a.Show();
	cout<<endl;
	a.printDot("archivo.dot");
	system("dot -Tpng archivo.dot -o archivo.png");

}


