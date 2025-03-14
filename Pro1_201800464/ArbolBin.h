#pragma once
#include<iostream>
#include"Navl.h"
#include"Act.h"
#include"CatalogoLsimple.h"
using namespace std;
class ArbolBin
{
private:
	string Graph;
	int indice;
	Navl* raiz;
	void mostrar_activos(Navl*);
	CatalogoLsimple* recolectaProRecursivo(Navl* ,CatalogoLsimple* CATALOGO , string nombreUser, string empresa, string departamento);
public:

	ArbolBin() {
		    this->raiz = NULL;
			this->Graph = "";
			this->indice = 0; // solo si necesitara hacer recorridos
	}
	inline Navl* getRoot() { return this->raiz; };
	void add(Navl*);// le reservo memoria de un nodo antes de meterlo al arbol 
	void add_Activo(string nom_, string descripcion_, bool disp);
	Navl* recursive_add(Navl*, Navl*);// root temporal , nuevo
	int compararAlfabeticamente(string, string);// 2 == igual , 0 menor , 1 mayor 

	// para ver el resultado
	void recorrido_inOrder();
	void recursive_inOrder(Navl*);

	void eliminar(string);
	Navl* eliminarRecursivo(Navl*, string);
	Navl* getNodoMinimo(Navl*);


	//+++++++++++++++++++++++++ GRAFICAR MI ARBOL ALV 
	void getGraphviz();
	void getGraphviz(Navl*); // recolecto en preorder       raiz izq derecha 
	string getGraphvizRepUsuarios(string nombreUsuario , int indice);

	//++++++++++++++++++++++++++ BUSCAR 
	Navl* buscar(string);
	Navl* buscarRecursivo(Navl*, string);

	// para le id alfa 
	string generarId();
	bool yaExisteEl_id(string id_alfanumerico);
	string getLetra(int);


	// para calcular el balance 
	
	int GET_MI_FE(Navl* padre);
	int GET_Al(Navl*); // por si mi nodo izq , der cualquiera es null 
	void dame_la_altura_y_balance(Navl*);


	// rotaciones 
	Navl* rot_s_derecha(Navl*);
	Navl* rot_s_izquierda(Navl*); 


	void mostrar_activos();

	// recolecar productos 
	CatalogoLsimple* recolectaPro(CatalogoLsimple* CATALOGO , string nombreUser , string empresa , string departamento);

};

