#pragma once
#include<iostream>
#include<string>
#include"NodoDobleC.h"
#include"Transa.h"
using namespace std; 
class CircularDobleTransacciones
{
private: 
	NodoDobleC* inicio;
	NodoDobleC* ultimo;
	int tamanio;
public:
	CircularDobleTransacciones() { this->inicio = NULL; this->ultimo = NULL; this->tamanio = 0; };

	inline NodoDobleC* getInicio() { return this->inicio; }
	inline NodoDobleC* getUltimo() { return this->ultimo; }
	inline void vaciar() {this->inicio = NULL;this->ultimo = NULL;this->tamanio = 0;}
	
	void add(Transa * nuevaTr);
	// para verificar si mis enlaces estan bien 
	void getGraphviz();
	void imprimeparaAdelnate();
	void imprimeparaAtras();
	// metodos de ordenamiento aun faltan  y metodo para generar el id desde aca 
	int compararAlfabeticamente(string, string);// 2 == igual , 0 menor , 1 mayor 
	
	
	string generarId();
	bool yaExisteEl_id(string id_alfanumerico);
	string getLetra(int);


};

