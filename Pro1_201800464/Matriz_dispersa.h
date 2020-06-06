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
	nMatrix* heredarPunteros(nMatrix* , nMatrix*);
	
	
	
	// ------- buscar en el CUBO :'v 
	nMatrix * BuscarNodo(string empresa, string dep , string nombreUser);
	nMatrix* isInsercion3D(string empresa, string dep);
	void imprimirFondo(nMatrix*);



	void getGraphviz();
	void add(string dep_fila, string  emp_col, Usuario* usuario);
};

