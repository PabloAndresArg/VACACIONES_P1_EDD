#pragma once
#include<iostream>
#include<string>
using namespace std;
class Producto
{
public:
	// usuario
	string usuario;
	string empresa;
	string departamento;
	//Activo
	string id_activo;
	string nombre;
	string descripcion; 
	// SOLO METER AL CATALOGO LOS DISPONIBLES.. :D 
	inline Producto(string user, string empresa_ , string departamento_ , string id_activo_, string nombre_ , string descripcion_) {
		this->usuario = user; 
		this->empresa = empresa_; 
		this->departamento = departamento_;
		this->id_activo = id_activo_; 
		this->nombre = nombre_; 
		this->descripcion = descripcion_; 
	}
};

