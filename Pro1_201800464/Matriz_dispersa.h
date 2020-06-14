#pragma once
#include<iostream>
#include<string>
#include"nMatrix.h"
#include"CatalogoLsimple.h"
using namespace std;
class Matriz_dispersa
{
private:
	nMatrix* root;
	int contadorFilas = -1;
	int contadorColumnas = -1;
public: 
	Matriz_dispersa() {
		this->root = new nMatrix("-1" , "-1");
		this->root->setDepartamento("-1");
		this->root->setEmpresa("-1");
		this->root->setPos_x(-1);
		this->root->setPos_y(-1);
	}
	inline nMatrix* getRoot() {
		return this->root;
	}
	//-------------------------					     SOLO PARA VER SI EXISTE 
	nMatrix* existeColumna(string);
	nMatrix* existeFIla(string);
	//-------------------------

	//-------------------------						GENERADOR DE COLUMNAS Y FILAS 
	nMatrix* generaColumna(string);
	nMatrix* generaFila(string);


	//---- update positions 
	nMatrix* actualizaPosiciones(nMatrix* , nMatrix*, nMatrix*);
	nMatrix* heredarPunteros(nMatrix* , nMatrix*);
	
	
	
	// ------- buscar en el CUBO :'v 
	void modificarUsuario(string dep_fila, string  emp_col, Usuario* usuario);// enviando 
	nMatrix* BuscarNodo(string empresa, string dep, string nombreUser);// recibiendo 
	nMatrix* isInsercion3D(string empresa, string dep);
	bool UsuarioRepetido(nMatrix* cordenada ,string nombre);
	void eliminarInterno(string empresa, string dep, string nombreUser);
	nMatrix* reemplazarCara(nMatrix* adelante, nMatrix* atras);


	// aux visuales nada mas 
	void imprimirFondo(nMatrix*);
	void imprimirSolo3D();

	// grafo
	void getGraphviz();


	// agregar 
	void add(string empresa_fila, string  dep, Usuario* usuario);


	// reportes 
	void reporteEmpresa(string empresa_fila);
	void reporteDepartamento(string departamento_colum);

	// para mostrar el catalogo 

	CatalogoLsimple* recolectaProductos(CatalogoLsimple* CATALOGO);

};

