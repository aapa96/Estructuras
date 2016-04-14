///*
// * Main.cpp
// *
// *  Created on: 10 de abr. de 2016
// *      Author: Alex Andre
// */
#include "arbol.h"
#include <stdlib.h>

int main(){
Arbol<int> Arbol;

Arbol.Agregar(10);
Arbol.Agregar(20);
Arbol.Agregar(15);
Arbol.Agregar(5);
Arbol.Agregar(2);
Arbol.Agregar(3);
Arbol.Agregar(7);
Arbol.Agregar(25);
Arbol.Agregar(1);
cout<<"ShowA"<<endl;
Arbol.ShowA(Arbol.Raiz);
cout<<"ShowB"<<endl;
Arbol.ShowB(Arbol.Raiz);
cout<<"ShowC"<<endl;
Arbol.ShowC(Arbol.Raiz);
Arbol.Printdot("archivo.dot");
system("dot -Tpng archivo.dot -o archivo.png");
return 0;

}

