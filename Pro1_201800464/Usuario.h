#pragma once
#include<string>
#include<iostream>
using namespace std; 
class Usuario
{
private: 
	string nom; 
	string empresa; 
	string nombreCompleto; 
	string departamento;
	
public: 
	Usuario(string nom_) {
		this->nom = nom_;
	}

	string getNomUser() {
		return this->nom;
	}

};

