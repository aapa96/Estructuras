///*
// * Main.cpp
// *
// *  Created on: 10 de abr. de 2016
// *      Author: Alex Andre
// */
#include "arbol.h"
#include <stdlib.h>


#define Numero 6

const string Operadores[Numero] = {"+", "-", "*", "/", "%", "^"};
int Existe[Numero] = {1, 1, 2, 2, 2, 3};

// Evalua si es operador o no
bool EsOperador( const string x ){
	for(int i = 0; i<Numero;i++){
		if(Operadores[i] == x)
			return true;
	}
	return false;
}
// Evalua si existe el operador
int ExistOperador( const string  x){
	for(int i = 0;i<Numero;i++){
		if(Operadores[i] == x){
			return Existe[i];
		}
	}
	return -1;
}
int ev (){
	string Infija;
	string Postfija;
	string Aux;
	stack <string> PilaEvaluar;
	stack <double> PilaResultado;
	size_t i;
	char c;
	double A, B;


	cout << "Ingrese expresion infija: ";
	cin>>Infija;
	cout << endl;

	//Evaluar de infija a postfija
	for ( i = 0; i < Infija.size(); i++ ) {
		c = Infija[i];
		Aux.clear();
		Aux += c;


		/* es un espacio: despreciar */
		if ( c == ' ' ) continue;

		/* es un carácter numérico: pasar al posfijo */
		if ( c >= '0' && c <= '9' ) {

			Postfija = Postfija + " " + c;
			continue;
		}

		/* si se lee un operador: sacar de la pila y pasar al postfijo
		 */
		if ( EsOperador( Aux ) ) {

			while ( !PilaEvaluar.empty() && ExistOperador( PilaEvaluar.top() )
						>= ExistOperador( Aux ) ) {
				Postfija = Postfija + " " + PilaEvaluar.top();
				PilaEvaluar.pop();
			}
			PilaEvaluar.push( Aux );
			continue;
		}

		/* si se lee "(": colocar en la pila */
		if ( Aux == "(" ) {
			PilaEvaluar.push( Aux );
			continue;
		}

		/* si se lee ")": retirar de la pila hasta encontrar '(', y pasar
		 * los elementos retirados a posfijo, luego descartar el "(" */
		if ( Aux == ")" ) {
			while ( !PilaEvaluar.empty() && PilaEvaluar.top() != "(" ) {

				Postfija = Postfija + " " + PilaEvaluar.top();
				PilaEvaluar.pop();
			}
			if ( !PilaEvaluar.empty() )
				PilaEvaluar.pop();	/* descartar el "(" */
		}
	}

	/* extraer de la pila cualquier operador restante y pasarlo a la cadena posfijo */
	while ( !PilaEvaluar.empty() ) {
		Postfija = Postfija + " " + PilaEvaluar.top();
		PilaEvaluar.pop();
	}

	/* Imprimir el posfijo */
	cout << "Posfijo es: \n\t" << Postfija <<  endl;

	/// Evaluar la expresion postfija y mostrar resultado

	A = 0;

	for ( i = 0; i < Postfija.size(); i++ ) {

		c = Postfija[i];
		Aux.clear();
		Aux += c;

		/* Si lee un numero colocarlo en la pila*/
		if ( c >= '0' && c <= '9' ) {
			PilaResultado.push( c - '0' );
			continue;
		}

		//Evalua si encuentra operadores en la pila y los coloca en A y B y finalmente en el resultado
		if ( EsOperador( Aux ) ) {
			if ( !PilaResultado.empty() ) {
				B = PilaResultado.top();
				PilaResultado.pop();
			}
			else {
				//cout << "Argumentos insuficientes para '" << c << "'" << endl;
				return -1;
			}

			if ( !PilaResultado.empty() ) {
				A = PilaResultado.top();
				PilaResultado.pop();
			}
			else {
				//cout << "Argumentos insuficientes para '" << c << "'" << endl;
				return -1;
			}

			cout << "\toperar " << A << Aux << B << " = ";
			if ( Aux == "+" ) {
				A += B;
				PilaResultado.push( A );
			}
			else if ( Aux == "-" ) {
				A -= B;
				PilaResultado.push( A );
			}
			else if ( Aux == "*" ) {
				A *= B;
				PilaResultado.push( A );
			}
			else if ( Aux == "/" ) {
				A /= B;
				PilaResultado.push( A );
			}
			else if ( Aux == "%" ) {
				A = (int )A % (int )B;
				PilaResultado.push( A );
			}
			else if ( Aux == "^" ) {
				A = pow(A, B);
				PilaResultado.push( A );
			}

			cout << A << endl;
		}
	}


	//// Mostrar resultado
	if ( !PilaResultado.empty() )
		cout << endl << "El Resultado es: " << PilaResultado.top() << endl;

	return 0;
}



int main(){

//
//Arbol<char> a;
//a.Agregar('2');
//a.Agregar('5');
//a.Agregar('a');
//a.Agregar('7');
//a.Agregar('b');
//
//a.ShowA(a.Raiz);
//cout<<endl;
//a.ShowC(a.Raiz);
//a.Printdot("archivo.dot");
//system("dot -Tpng archivo.dot -o archivo.png");
//
//Arbol<string> a;
//a.Evaluar("1+5+3");
//
//Arbol<int> Arbol;
////
//Arbol.Agregar(10);
//Arbol.Agregar(4);
//Arbol.Agregar(20);
//Arbol.Agregar(5);
//Arbol.Agregar(2);
//Arbol.Agregar(3);
//Arbol.Agregar(7);
//Arbol.Agregar(25);
//Arbol.Agregar(1);
////Arbol.buscarElemento(7);
//
//
//cout<<"ShowA"<<endl;
//Arbol.ShowA(Arbol.Raiz);
//
//Arbol.borrar(10);
//
//Arbol.buscarMinimo();
//Arbol.buscarMaximo();
////Arbol.buscarElemento(10);
//cout<<"ShowA"<<endl;
//Arbol.ShowA(Arbol.Raiz);
//
//Arbol.Printdot("archivo.dot");
//system("dot -Tpng archivo.dot -o archivo.png");
//
//Arbol.evaluar();
int xd=1;

while(xd == 1){
	cout<<endl<< " 1 Evaluar" <<endl;
	cout<< " != 1 Acaba"<<endl;
	int a;
	cin>>a;
	if(a == 1)
		ev();
	else{
		cout<<"Adios "<<endl;
		xd = 0;
	}
}

return 0;

}

