#pragma once
#include<iostream>
#include<string>
#include"nMatrix.h"
using namespace std;
class Matriz_dispersa
{
private:
	nMatrix* root;
	int contadorFilas = -1;
	int contadorColumnas = -1;
public: 
	Matriz_dispersa() {
		this->root = new nMatrix("-1" , "-1");
		this->root->setDepartamento("-1");
		this->root->setEmpresa("-1");
		this->root->setPos_x(-1);
		this->root->setPos_y(-1);
	}
	inline nMatrix* getRoot() {
		return this->root;
	}
	//-------------------------					     SOLO PARA VER SI EXISTE 
	nMatrix* existeColumna(string);
	nMatrix* existeFIla(string);
	//-------------------------

	//-------------------------						GENERADOR DE COLUMNAS Y FILAS 
	nMatrix* generaColumna(string);
	nMatrix* generaFila(string);


	//---- update positions 
	nMatrix* actualizaPosiciones(nMatrix* , nMatrix*, nMatrix*);

	//-------------------------						INSERTA ORDENADO 
	nMatrix* insertarOrdenadoFila(nMatrix*, nMatrix*);
	nMatrix* insertarOrdenandoColumna(nMatrix*, nMatrix*);



	void getGraphviz();
	void add(string dep_fila, string  emp_col, string usuario);
};

