#include "CatalogoLsimple.h"
#include"NodoProducto.h"
#include"Producto.h"
#include"string"
using namespace std;


void CatalogoLsimple::agregaProducto(string user, string empresa_, string departamento_, string id_activo_, string nombre_, string descripcion_) {
	NodoProducto* n = new NodoProducto( new Producto(user , empresa_ , departamento_ , id_activo_ , nombre_, descripcion_) ); 
	if (this->cab == NULL) 	this->cab = n;
	else this->ul->next = n;
	this->ul = n; // voy corriendo el puntero ultimo 
}

void CatalogoLsimple:: MostrarCATALOGO(string us, string empresa_, string dep) {
	NodoProducto* nav = this->cab; 
	while (nav != NULL) {
		
		if ((us.compare(nav->producto->usuario) == 0) && (empresa_.compare(nav->producto->empresa) == 0) && (  dep.compare(nav->producto->departamento) == 0) ) {

		}
		else {
		cout << "°°° ID: " << nav->producto->id_activo << " Nombre: " << nav->producto->nombre << " Descripcion: " << nav->producto->descripcion << endl;
		}
		nav = nav->next;
	}
}
NodoProducto* CatalogoLsimple:: buscar_del_catalogo(string id_) {
	NodoProducto* nav = this->cab;
	while (nav != NULL) {
		if (nav->producto->id_activo == id_) return nav;
		nav = nav->next;
	}
	return NULL; 
}