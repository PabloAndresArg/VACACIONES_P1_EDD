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

void CatalogoLsimple:: MostrarCATALOGO() {
	NodoProducto* nav = this->cab; 
	while (nav != NULL) {
		cout << "°°° ID: "<<nav->producto->id_activo <<" Nombre: " <<nav->producto->nombre <<" Descripcion: "<<nav->producto->descripcion<<endl; 
		nav = nav->next;
	}
}