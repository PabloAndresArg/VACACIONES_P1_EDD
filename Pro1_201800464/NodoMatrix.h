#pragma once
#include<iostream>
#include<string>
#include"Usuario.h"
using namespace std; 
// ES UN CUBO 


/*

				IGNORAR ESTE NODO 
	*/
class NodoMatrix {
private: 
	int pos_x;
	int pos_y;
	NodoMatrix* der; 
	NodoMatrix* izq;
	NodoMatrix* up; 
	NodoMatrix* down; 
	NodoMatrix* front; 
	NodoMatrix* behind;
	string empresa; // EJE Y 
	string departamento; // EJE X 
	string  user; 
public:
	
	inline NodoMatrix() {
		this->der = NULL; 
		this->izq = NULL; 
		this->up = NULL; 
		this->down = NULL; 
		this->front = NULL; 
		this->behind = NULL; 
		this->empresa = "NULL"; 
		this->departamento = "NULL"; 
		this->pos_x = -1;
		this->pos_y = -1;
		this->user = ""; 
	}

	inline NodoMatrix( string empresa_ , string departamento_, Usuario  u ) {
		this->der = NULL;
		this->izq = NULL;
		this->up = NULL;
		this->down = NULL;
		this->front = NULL;
		this->behind = NULL;
		this->empresa = empresa_;
		this->departamento = departamento_;
		this->pos_x = -1;
		this->pos_y = -1;
		this->user = u.getNomUser(); 
	}
	inline NodoMatrix( string empresa_ , string departamento_ ) {
		this->der = NULL;
		this->izq = NULL;
		this->up = NULL;
		this->down = NULL;
		this->front = NULL;
		this->behind = NULL;
		this->empresa = empresa_;
		this->departamento = departamento_;
		this->pos_x = -1;
		this->pos_y = -1;
		this->user = "";
	}




	/*    SETTER AND GETTERS COMO EN JAVA   */

	//der 
	inline void setDer(NodoMatrix* der_) {this->der = der_;}
	inline NodoMatrix* getDer() {return this->der;}
	//izq
	inline void setIzq(NodoMatrix* izq_) { this->izq = izq_; }
	inline NodoMatrix* getIzq() { return this->izq; }
	//up
	inline void setUp(NodoMatrix* Up_) { this->up = Up_; }
	inline NodoMatrix* getUp() { return this->up; }
	//down
	inline void setDown(NodoMatrix* Down_) { this->down = Down_; }
	inline NodoMatrix* getDown() { return this->down;  }
	//front
	inline void setFront(NodoMatrix* Front_) { this->front = Front_; }
	inline NodoMatrix* getFront() { return this->front; }
	//behind
	inline void setBehind(NodoMatrix* Behind_) { this->behind = Behind_; }
	inline NodoMatrix* getBehind() { return this->behind; }
	// empresa		X	
	inline void setEmpresa(string e) { this->empresa = e;  }
	inline string getEmpresa() { return this->empresa;  }
	// departamento		Y 
	inline void setDepartamento(string d) { this->departamento = d;  }
	inline string getDepartamento() { return this->departamento; }
	// usuario 
	inline string getUsuario() {   return this->user; }
	inline void setUsuario(string u) { this->user = u; }


	/* PARA  ORDENAR EN LA INSERCION DE ANTES DE UN NODO INTERIOR DE LA MATRIX */
	inline int getPos_x() {
		return this->pos_x;
	}

	inline int getPos_y() {
		return this->pos_y;
	}

	inline void setPos_x(int x_) {
		this->pos_x = x_;
	}

	inline void setPos_y(int y_) {
		this->pos_y = y_;
	}

};
