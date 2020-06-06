#pragma once
#include<iostream>
#include<string>
#include"Usuario.h"
using namespace std;
class nMatrix {
private:
	int pos_x;
	int pos_y;
	nMatrix* izq, * der, * down, * up , * front, * behind;
	string empresa; // EJE Y 
	string departamento; // EJE X 
	string  user;
public:

	nMatrix(string empresa_, string departamento_, string  nombre) {
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
		this->user = nombre;
	}

	inline nMatrix(string empresa_, string departamento_) {
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


	inline void setFront(nMatrix* Front_) { this->front = Front_; }
	inline nMatrix* getFront() { return this->front; }
	//behind
	inline void setBehind(nMatrix* Behind_) { this->behind = Behind_; }
	inline nMatrix* getBehind() { return this->behind; }
	// empresa		X	
	inline void setEmpresa(string e) { this->empresa = e; }
	inline string getEmpresa() { return this->empresa; }
	// departamento		Y 
	inline void setDepartamento(string d) { this->departamento = d; }
	inline string getDepartamento() { return this->departamento; }

	inline nMatrix* getIzq() {
		return this->izq;
	}
	inline nMatrix* getDer() {
		return this->der;
	}

	inline nMatrix* getUp() {
		return this->up;
	}
	inline nMatrix* getDown() {
		return this->down;
	}

	inline void setIzq(nMatrix* izq_) {
		this->izq = izq_;
	}

	inline void setDerecha(nMatrix* der_) {
		this->der = der_;
	}

	inline void setArriba(nMatrix* up_) {
		this->up = up_;
	}

	inline void setAbajo(nMatrix* down_) {
		this->down = down_;
	}





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

	inline string getUsuario() {
		return this->user; 
	}
	inline void setUsuario(string user)
	{
		this->user = user; 
	}


};