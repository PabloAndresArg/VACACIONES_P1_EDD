#include "CircularDobleTransacciones.h"
#include<iostream>
#include<string>
#include"NodoDobleC.h"
#include"Rep.h"
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
using namespace std; 

void CircularDobleTransacciones::add_transaccion(string id_activo, string nombreUsuario, string emp, string dep, string fecha, string ti) {
	string  id_transaccion_nueva= this->generarId();
	while (yaExisteEl_id(id_transaccion_nueva)) {
		id_transaccion_nueva = this->generarId();
	}
	cout << "ID GENERADO: " + id_transaccion_nueva << endl;
	this->add(new Transa(id_transaccion_nueva ,id_activo , nombreUsuario, emp, dep, fecha , ti));
}

void CircularDobleTransacciones::add(Transa * nuevaTr ) {
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
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	
	if (this->inicio != NULL) {
		NodoDobleC* aux = this->inicio;
		for (int i = this->tamanio; i > 0; i--)
		{
			cout << " = "  << aux->tra->getId_tra()<< "     ";
			aux = aux->sig;
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

		return 1;
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
	if (this->inicio == NULL) return false; 
	NodoDobleC* navegador = this->inicio; 
	for (int x = 0; x < this->tamanio; x++) {
		if (id_alfanumerico.compare(navegador->tra->getId_tra()) == 0 ) {
			return true; 
		}
		navegador = navegador->sig;
	}
	return false;
}

string CircularDobleTransacciones::getLetra(int n ) {
	string letra = "";
	if (n == 10) {
		letra = "v";
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
		letra = "a"; 
	}
	

	return letra;
}









/*

									 PA ORDENAR :D
*/





void CircularDobleTransacciones :: setMenor_como_primero() {
	if (this->tamanio > 1) {
		NodoDobleC* navegador = this->inicio;
		NodoDobleC* menor = this->inicio;
		do {
			if (compararAlfabeticamente(navegador->tra->getId_tra(), menor->tra->getId_tra()) == 0) menor = navegador;
			navegador = navegador->sig;
		} while (navegador != this->inicio && navegador != NULL);
		this->inicio = menor;
		//cout << "ahora el inicio es: "<<this->inicio->tra->getId_tra()<< endl;
	}
}
void CircularDobleTransacciones::setMayor_como_ultimo() {
	if (this->tamanio > 1) {
		NodoDobleC* navegador = this->ultimo;
		NodoDobleC* mayor = this->ultimo;
		do {
			if (compararAlfabeticamente(navegador->tra->getId_tra(), mayor->tra->getId_tra()) == 1) mayor = navegador;
			navegador = navegador->ant;
		} while (navegador != this->ultimo && navegador != NULL);
		this->ultimo = mayor;
		//cout << "ahora el ultimo es: " << this->ultimo->tra->getId_tra() << endl;
	}
}


void CircularDobleTransacciones::OrdenarAsc() {
	if (this->tamanio == 0) {
		return;
	}
	if (this->tamanio == 2) {
		this->setMenor_como_primero();
		this->setMayor_como_ultimo();
		return; 
	}
	else {
		this->setMenor_como_primero();
		this->setMayor_como_ultimo();
		NodoDobleC* puntero1 = this->inicio; // como mi inicio siempre es el menor es el unico nodo que no podria intercambiarse 
		NodoDobleC* puntero2 = NULL;
		puntero2 = puntero1->sig;
	
		for (int i = 0; i < this->tamanio; i++) {

		
			for (int j = 0; j < this->tamanio -1; j++) {

				if (compararAlfabeticamente(puntero2->tra->getId_tra(), puntero2->sig->tra->getId_tra()) == 1 && puntero2->sig != this->inicio) {
					/*cout << "entra a ordenar: " << puntero2->tra->getId_tra() << ">" << puntero2->sig->tra->getId_tra() << endl;
					system("pause");
					this->imprimeparaAdelnate();*/
					this->cambiarPosiciones(puntero2, puntero2->sig);
				}
				puntero2 = puntero2->sig;
			}

			puntero1 = puntero1->sig;
		}
	}
	
}

void CircularDobleTransacciones:: cambiarPosiciones(NodoDobleC * pos1, NodoDobleC * reemplazo) { // mientras no este ordenado el this->ultimo no me sirve

	NodoDobleC* anterior = pos1->ant;
	NodoDobleC* re_next = reemplazo->sig;


	pos1->sig = re_next;
	pos1->ant = reemplazo;
	reemplazo->sig = pos1;
	reemplazo->ant = anterior;
	anterior->sig = reemplazo;
	re_next->ant = pos1;
	//cout << "change" << endl;
}



void CircularDobleTransacciones::setMayor_como_inicio() {
	if (this->tamanio > 1) {
		NodoDobleC* navegador = this->ultimo;
		NodoDobleC* mayor = this->ultimo;
		do {
			if (compararAlfabeticamente(navegador->tra->getId_tra(), mayor->tra->getId_tra()) == 1) mayor = navegador;
			navegador = navegador->ant;
		} while (navegador != this->ultimo && navegador != NULL);
		this->inicio = mayor;
		//cout << "ahora el INICIO es: " << this->inicio->tra->getId_tra() << endl;
	}
}
void CircularDobleTransacciones::setMenor_como_ultimo() {
	if (this->tamanio > 1) {
		NodoDobleC* navegador = this->inicio;
		NodoDobleC* menor = this->inicio;// no importa con cula comience a navegar porque es circular igual 
		do {
			if (compararAlfabeticamente(navegador->tra->getId_tra(), menor->tra->getId_tra()) == 0) menor = navegador;
			navegador = navegador->sig;
		} while (navegador != this->inicio && navegador != NULL);
		this->ultimo = menor;
		//cout << "ahora el ULTIMO es: " << this->ultimo->tra->getId_tra() << endl;
	}
}




void CircularDobleTransacciones::OrdenarDescen() {
	if (this->tamanio == 0 ) {
		return; 
	}
	if (this->tamanio == 2) {
		this->setMayor_como_inicio();
		this->setMenor_como_ultimo();
		return;
	}
	else {
		this->setMayor_como_inicio();
		this->setMenor_como_ultimo();

		NodoDobleC* puntero1 = this->inicio; // como mi inicio siempre es el menor es el unico nodo que no podria intercambiarse , ya que lo cambie un paso atras
		NodoDobleC* puntero2 = NULL;
		puntero2 = puntero1->sig;

		for (int i = 0; i < this->tamanio; i++) {


			for (int j = 0; j < this->tamanio - 1; j++) {

				if (compararAlfabeticamente(puntero2->tra->getId_tra(), puntero2->sig->tra->getId_tra()) == 0 && puntero2->sig != this->inicio) {
					/*cout << "entra a ordenar ASc: " << puntero2->tra->getId_tra() << "<" << puntero2->sig->tra->getId_tra() << endl;
					this->imprimeparaAdelnate();
					system("pause");*/
					
					this->cambiarPosiciones(puntero2, puntero2->sig);
					
				}
				puntero2 = puntero2->sig;
			}

			puntero1 = puntero1->sig;
		}
	}

}


CircularDobleTransacciones* CircularDobleTransacciones :: reporteTransaccionesPorUsuario(string usuario, string empresa, string  depar) {
	CircularDobleTransacciones* reporte = new CircularDobleTransacciones(); 
	if (this->inicio == NULL) return reporte;
	NodoDobleC* navegador = this->inicio;
	for (int x = 0; x < this->tamanio; x++) {
		if (compararAlfabeticamente(navegador->tra->getNombreUsuario(), usuario) == 2 && navegador->tra->getDepa().compare(depar) == 0 && navegador->tra->getEmpresa().compare(empresa) == 0) {
			reporte->add(navegador->tra); 
		}
		navegador = navegador->sig;
	}
	return reporte;
}
