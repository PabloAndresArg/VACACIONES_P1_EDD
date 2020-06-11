#pragma once
#include<string>
#include<iostream>
#include"ArbolBin.h"
#include"Act.h"
#include"CatalogoLsimple.h"
using namespace std; 
class Usuario
{
private: 
	string nomUser; 
	string nombreCompleto; 
	string pass;
	ArbolBin* Arbol_activos;

	
	
public: 
	Usuario(string nom_ , string nombreCOm_ , string pass_ ) {
		this->nomUser = nom_;
		this->nombreCompleto = nombreCOm_;
		this->pass = pass_;
		this->Arbol_activos = new ArbolBin();
	}

	string getNomUser() {
		return this->nomUser;
	}
	string getPass() {
		return this->pass;
	}
	string getNombreCompleto() {
		return this->nombreCompleto; 
	}
	ArbolBin* getArbol_activos() {
		return this->Arbol_activos;
	}
	void setNomUser(string algo) {
		this->nomUser = algo; 
	}
	void setPass(string algo) {
		this->pass = algo;
	}
	void setNombreCompleto(string algo) {
		this->nombreCompleto = algo;
	}



};

