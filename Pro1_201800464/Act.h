#pragma once
#include<iostream>
#include<string>
using namespace std; 
class Act
{
public: 
	string id_activ;
	string nombre; 
	string descripcion; 
	bool dispo; 
	inline Act(string id_activ) {
		this->id_activ = id_activ;
		this->nombre = "PRUEBA";
		this->descripcion = "";
		this->dispo = "";
	}
	inline Act(string id_, string nom_, string descripcion_, bool disp) {
		this->id_activ = id_;
		this->nombre = nom_;
		this->descripcion = descripcion_;
		this->dispo = disp;
	}



	inline void  setTodoEl_objeto(string id_, string nom_, string descripcion_, bool disp) { this->id_activ = id_; this->nombre = nom_; this->descripcion = descripcion_; this->dispo = disp;  }


};

