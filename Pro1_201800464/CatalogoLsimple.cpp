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
void CatalogoLsimple::mostrarMisRentas() {
	if (this->getCabeza() != NULL) {
		NodoProducto* nav = this->cab;
		while (nav != NULL) {
			cout << "||| ID: " << nav->producto->id_activo << " Nombre: " << nav->producto->nombre << " Descripcion: " << nav->producto->descripcion << " Tiempo: " << nav->producto->timepoRenta << endl;
			nav = nav->next;
		}
	}
	else {
		cout << "No has rentado ningun Activo..." << endl; 
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

void CatalogoLsimple::devolverProducto(string id_) {

	NodoProducto* nav = this->cab;
	NodoProducto* ant = new NodoProducto();

	while (nav != NULL) {
		if (nav->producto->id_activo.compare(id_) == 0) {
			if (this->cab->producto->id_activo.compare(id_) == 0)
			{

				cout << "\neliminando la cabeza se la simple" << endl;
				if (this->cab->next == NULL) this->cab = NULL;
				else this->cab = this->cab->next;

				return;
			}
			else {
				if (nav->next != NULL)
				{
					cout << "\neliminando en medio " << endl;
					ant->next = nav->next;
					nav = NULL;
				}
				else {
					cout << "\neliminando el ultimo" << endl;
					ant->next = NULL;
					nav = NULL;
				}
			}
			return;
		}

		ant = nav;
		nav = nav->next;
	}
}



void CatalogoLsimple::mostrarMisClientes() {
	if (this->getCabeza() != NULL) {
		NodoProducto* nav = this->cab;
		while (nav != NULL) {
			cout << "||| Empresa del cliente: " << nav->producto->empresa << " Departamento donde se encuentra: " << nav->producto->departamento << endl; 
			cout << "||| Nombre del cliente: "<< nav->producto->usuario <<" ID: " << nav->producto->id_activo << " Nombre: " << nav->producto->nombre << " Descripcion: " << nav->producto->descripcion << " Tiempo: " << nav->producto->timepoRenta << endl;
			cout << endl; 
			nav = nav->next;
		}
	}
	else {
		cout << "No has rentado ningun Activo..." << endl;
	}

}