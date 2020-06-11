#pragma once
#include"NodoProducto.h"
#include <iostream>
using namespace std; 
class CatalogoLsimple
{
private: 
	NodoProducto* cab; 
	NodoProducto* ul; 
public: 
	inline NodoProducto* getCabeza() { return this->cab; }
	inline NodoProducto* getUltimo() { return this->ul; }
	CatalogoLsimple() {
		this->cab = NULL; // cabeza o inicio 
		this->ul = NULL; // ultimo nodo 
	}
	void agregaProducto(string user, string empresa_, string departamento_, string id_activo_, string nombre_, string descripcion_);
	inline void vaciarCatalogo() { this->cab = NULL; this->ul = NULL; }
	void MostrarCATALOGO(string nombre , string empresa_ , string dep);
	NodoProducto* buscar_del_catalogo(string id_); 

};

