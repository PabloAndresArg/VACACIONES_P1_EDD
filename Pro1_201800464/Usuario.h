#pragma once
#include<string>
#include<iostream>
#include<vector>
#include"Act.h"
using namespace std; 
class Usuario
{
private: 
	string nomUser; 
	string nombreCompleto; 
	string pass;
	vector<Act> vector_de_nodos;
	
public: 
	Usuario(string nom_ , string nombreCOm_ , string pass_ ) {
		this->nomUser = nom_;
		this->nombreCompleto = nombreCOm_;
		this->pass = pass_;

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

