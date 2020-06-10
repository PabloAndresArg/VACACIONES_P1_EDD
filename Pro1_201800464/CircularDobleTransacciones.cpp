#include "CircularDobleTransacciones.h"
#include<iostream>
#include<string>
#include"NodoDobleC.h"
#include"Rep.h"
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
using namespace std; 



void CircularDobleTransacciones::add(Transa * nuevaTr) {
	NodoDobleC* nuevo = new NodoDobleC();
	nuevo->tra = nuevaTr;
	if (this->inicio == NULL) {
		this->inicio = nuevo;
		this->ultimo = nuevo;
		this->inicio->sig = nuevo;
		this->ultimo->sig = nuevo;
		this->tamanio++;
	}
	else { // insercion al final 
		nuevo->ant = this->ultimo;
		this->ultimo->sig = nuevo;
		this->ultimo = nuevo; // refrescamos cual es el ultimo ahora 

		this->ultimo->sig = this->inicio;
		this->inicio->ant = this->ultimo;
		this->tamanio++;
	}
}


void CircularDobleTransacciones::imprimeparaAdelnate() {
	cout << "XXXXXXXXXXXXXXXXXXXX TRANSACCIONES XXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	if (this->inicio != NULL) {
		NodoDobleC* aux = this->ultimo;
		int numeral = 1;
		int formato = 0;
		for (int i = this->tamanio; i > 0; i--)
		{
			cout << numeral << "."  << aux->tra->getId_tra()<< "     ";
			numeral++;
			formato++;
			if (formato == 5) {
				cout << endl;
				formato = 0;
			}
			aux = aux->ant;
		}
		cout << endl;
	}
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
}

void CircularDobleTransacciones::imprimeparaAtras() {
	if (this->ultimo != NULL) {
		NodoDobleC* aux = this->ultimo;
		do {
			cout << aux->tra->getId_tra();
			aux = aux->ant;
		} while (aux != this->ultimo && aux != NULL);
		cout << endl;
	}

}


void CircularDobleTransacciones::getGraphviz() {
	Rep* llama = new Rep();
	llama->DobleCircular(this->inicio, this->ultimo, this->tamanio);
}



int CircularDobleTransacciones::compararAlfabeticamente(string p1, string p2) {
	if (p1.compare(p2) == 0) {
		return 2;
	}
	else {
		string palabraOrdenada = "";
		int repeticiones = 0, p1_size, p2_size;
		p1_size = (int)p1.size();
		p2_size = (int)p2.size();
		if (p1_size > p2_size) {
			repeticiones = (int)p2.size();
			palabraOrdenada = p2;
		}
		else if (p2_size > p1_size) {
			repeticiones = (int)p1.size();
			palabraOrdenada = p1;
		}
		else { // si son iguales en longitud 
			repeticiones = (int)p1.size();
		}


		for (int i = 0; i < repeticiones; i++) {
			char letra1 = p1[i];
			char letra2 = p2[i];
			if (letra1 == letra2) {
			}
			else if (letra2 > letra1) { // palabra 1 va antes que palabra 2 
				palabraOrdenada = p1;
				return 0;
			}
			else if (letra1 > letra2) {
				palabraOrdenada = p2;
				return 1;
			}
		}
		// caso en que la similitud es muy grande y no hay mas letras para comparar , se determina por la LONGITUD 

		int logitud_raiz = (int)p1.size();
		int logitud_nuevo = (int)p2.size();
		if (logitud_raiz > logitud_nuevo) {
			return 1; // lo inserto a la izq
		}
		else {
			return 0;
		}

		return 1;// analizar este paso
	}
}


string CircularDobleTransacciones:: generarId() {
	Sleep(850);
	string id_alfa = ""; 
	srand(time(NULL));
	int aleatorio = 0;
	for (int x = 0; x < 15; x++) {
		aleatorio = rand() % rand() % (25 - 0 + 1) + 0;
	
		if (x == 0 || x == 14) {
			id_alfa += getLetra(aleatorio);
		}
		else if (aleatorio >= 10) {
			id_alfa += getLetra(aleatorio);
		}
		else {
			id_alfa += std::to_string(aleatorio);
		}
	}
	return id_alfa;
}

bool CircularDobleTransacciones:: yaExisteEl_id(string id_alfanumerico) {
	return true;
}

string CircularDobleTransacciones::getLetra(int n ) {
	string letra = "";
	if (n == 10) {
		letra = "a";
	}
	else if (n == 11) {
		letra = "x";
	}
	else if (n == 12) {
		letra = "z";
	}
	else if (n == 13) {
		letra = "b";
	}
	else if (n == 14) {
		letra = "y";
	}
	else if (n == 15) {
		letra = "d";
	}
	else if(n == 16)
	{
		letra = "e";
	}
	else if (n == 17) {
		letra = "w";
	}
	else if (n == 18) {
		letra = "i";
	}
	else if (n == 19) {
		letra = "u";
	}
	else if (n == 20) {
		letra = "j";

	}
	else if (n == 21) {
		letra = "r";
	}
	else if (n == 22) {
		letra = "t";
	}
	else if(n == 23){
		letra = "q";
	}
	else if (n == 23) {
		letra = "o";
	}
	else if (n == 24) {
		letra = "s";
	}
	else {
		letra = "v"; 
	}
	

	return letra;
}