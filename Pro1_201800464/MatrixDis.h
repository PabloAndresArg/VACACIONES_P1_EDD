#pragma once
#include<iostream>
#include<string>
#include"NodoMatrix.h"
using namespace std;

class MatrixDis
{
private: 
	NodoMatrix* root; 
	int contadorFilas = -1; 
	int contadorColumnas = -1; 
public:

	MatrixDis() {
		this->root = new NodoMatrix();
		this->root->setDepartamento("-1");
		this->root->setEmpresa("-1");
		this->root->setPos_x(-1);
		this->root->setPos_y(-1); 
		this->root->setUsuario("AKDLJFALS");
	}


	NodoMatrix* buscarFilaPrincipal(string empresa); // retorna null si no existe 
	NodoMatrix* buscarColumnaPrincipal(string departamento); // retorna null si no existe


	NodoMatrix* crearColumnaAlFinal(string empresaNueva);
	NodoMatrix* crearFilaAlFinal(string departamentoNuevo);
	
	NodoMatrix* ordenarColumna(NodoMatrix* nuevo_nodo , NodoMatrix* aux);
	NodoMatrix* ordenarFila(NodoMatrix* nuevo_nodo, NodoMatrix* aux);
	void add(string dep_fila, string  emp_col , Usuario * user );


	/*METODOS PARA PROBAR LA ESTRUCTURA*/
	void imprimirMatriz();
	void getGraphviz(); 

};



















