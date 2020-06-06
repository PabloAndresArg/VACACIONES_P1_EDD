#include "MatrixDis.h"
#include<iostream>
#include<string>
#include"NodoMatrix.h"
#include"Rep.h"
using namespace std; 




/*


											IGNORAR MI CLASE ANTERIOR no funciona :(


*/












NodoMatrix* MatrixDis::buscarFilaPrincipal(string dep) {// busco si existe adentro de mi fila principal osea LAS COLUMNAS 


	
	NodoMatrix* aux = this->root;
	while (aux != NULL  ) {

		if (aux->getDepartamento().compare(dep) == 0) {
			return aux; // si existe
		}
		aux = aux->getDer(); 
	}
	if (aux == NULL) {
		return NULL; 
	}
	
}


NodoMatrix* MatrixDis::buscarColumnaPrincipal(string empresa_) {// busco entre las FILAS 
	NodoMatrix* aux = this->root; 
	while (aux != NULL ) {
		if (aux->getEmpresa().compare(empresa_) == 0) {
			return aux; // si existe
		}
		aux = aux->getDown();
	}
	if (aux == NULL) {
		return NULL;
	}
}

NodoMatrix* MatrixDis::crearColumnaAlFinal(string depNuevo) {
	this->contadorColumnas++;
	NodoMatrix* novo =  new NodoMatrix("-1" , depNuevo);
	NodoMatrix* aux = this->root; 
	while (aux->getDer() != NULL) {
		aux = aux->getDer(); 
	}
	novo->setPos_x(this->contadorColumnas);
	novo->setPos_y(-1);
	novo->setIzq(aux);
	aux->setDer(novo);
	return novo;
	//cout << "se creo un empresa " << depNuevo << "-COL" << endl;
}

NodoMatrix* MatrixDis::crearFilaAlFinal(string empresaNueva) {
	this->contadorFilas++;
	NodoMatrix* novo = new NodoMatrix(empresaNueva,"-1");
	NodoMatrix* aux = this->root;
	while (aux->getDown() != NULL) {
		aux = aux->getDown();
	}
	novo->setPos_x(-1);
	novo->setPos_y(this->contadorFilas);
	novo->setUp(aux);
	aux->setDown(novo);
	return novo; 
	cout << "se creo un departamento " << empresaNueva << "-FILA" << endl;
}


void MatrixDis::add(string emp_fila ,  string dep_col, Usuario* user) {
	// existen 4 casos de insercion 
	NodoMatrix* col_departamento = this->buscarFilaPrincipal(dep_col);//existe columna ? 
	NodoMatrix* fil_empresa = this->buscarColumnaPrincipal(emp_fila);// existe fila ? 
	NodoMatrix* nuevo_nodo = new NodoMatrix(emp_fila, dep_col, user->getNomUser());


	
	if (fil_empresa == NULL && col_departamento == NULL ) { // caso 1 no existe ni fila ni columna 
		cout << "caso1: no existe fila ni columna" << endl; 
		fil_empresa = crearFilaAlFinal(emp_fila);
		col_departamento = crearColumnaAlFinal(dep_col);
	}
	else if (fil_empresa == NULL && col_departamento != NULL) {
		cout << "caso2: no existe fila" << endl;
		fil_empresa = crearFilaAlFinal(emp_fila);
	}
	else if (fil_empresa != NULL && col_departamento == NULL) {
		cout << "caso3: no existe columna" << endl;
		col_departamento = crearColumnaAlFinal(dep_col);
	}
	else { // existen ya ambas 
		cout << "caso4: ya existen ambas " << endl;
	}
	// ACTUALIZA LAS POSICIONES
	nuevo_nodo->setPos_x(fil_empresa->getPos_y());
	nuevo_nodo->setPos_y(col_departamento->getPos_x());


	
	cout << "NODO DEPARTAMENTO :   " << col_departamento->getDepartamento() << endl;	cout << "NODO EMPRESA:    " << fil_empresa->getEmpresa() << endl;
	
							// LISTA DOBLE DE DEPARTAMENTO - COLUMNA 
	if (col_departamento->getDown() == NULL) {//INSERTANDO EN EL INICIO DE UN ENCABEZADO
		col_departamento->setDown(nuevo_nodo);
		nuevo_nodo->setUp(col_departamento);
	}
	else if (col_departamento->getDown() != NULL && fil_empresa->getDown() == NULL) { // inserto al final  
		cout << "insercion al final en col dep " << endl;
		NodoMatrix* aux = col_departamento; 
		while (aux->getDown() != NULL) {
			aux = aux->getDown(); 
		}
		// sale le ultimo nodo 
		aux->setDown(nuevo_nodo);
		nuevo_nodo->setUp(aux);
	}
	else if(col_departamento->getDown() != NULL && fil_empresa->getDown() != NULL) {// va en medio de los nodos 
		nuevo_nodo = ordenarColumna(nuevo_nodo, col_departamento);

	}// fin insercion 
















	
							// LISTA DOBLE DE EMPRESA - FILA 
	
	if (fil_empresa->getDer() == NULL) {
		fil_empresa->setDer(nuevo_nodo);
		nuevo_nodo->setIzq(fil_empresa);
	}
	else if (fil_empresa->getDer() != NULL && col_departamento->getDer() == NULL) {
		cout << "inserta al final:" << endl; 
		NodoMatrix* ax = fil_empresa; 
		while (ax->getDer() != NULL) {
			ax = ax->getDer(); 
		}
		ax->setDer(nuevo_nodo);
		nuevo_nodo->setIzq(ax); 
	}
	else {

	}
	

	if (fil_empresa != NULL && col_departamento != NULL) {

	}
	else 
	
	{
		cout << "error";
	}
	
	cout << endl; cout << endl; cout << endl;
}

NodoMatrix* MatrixDis::ordenarColumna(NodoMatrix* nuevo_nodo, NodoMatrix* aux) {
	NodoMatrix* ant = new NodoMatrix("", "");
	aux = aux->getDer();
	while (aux != NULL)
	{
		ant = aux;
		if (aux->getPos_y() == nuevo_nodo->getPos_y())
		{// sobreescribe
			aux->setPos_x(nuevo_nodo->getPos_x());
			aux->setUsuario(nuevo_nodo->getUsuario());
			cout << "retorna de una ";
			return nuevo_nodo;
		}
		else if (aux->getPos_y() > nuevo_nodo->getPos_y())
		{
			cout << "sii va antes de un nodo " << endl;
			nuevo_nodo->setDer(aux);
			aux->getIzq()->setDer(nuevo_nodo);
			nuevo_nodo->setIzq(aux->getIzq());
			aux->setIzq(nuevo_nodo);
			cout << "NOMBRE DEL NUEVO NODO: " << nuevo_nodo->getUsuario() << endl;
			cout << "nombre del nodo de DERECHO " << nuevo_nodo->getDer()->getUsuario() << endl;
			return nuevo_nodo;
		}
		aux = aux->getDer();
	}

	if (aux == NULL)
	{
		cout << "INSERTA AL FINAL " << endl;
		ant->setDer(nuevo_nodo);
		nuevo_nodo->setIzq(ant);
		return nuevo_nodo;
	}
}


void MatrixDis::imprimirMatriz() {
	cout << endl; 

	NodoMatrix* col_principal = this->root;
	NodoMatrix* aux = NULL;
	while (col_principal != NULL) {
		if (col_principal->getPos_x() == -1 && col_principal->getPos_y() == -1) {
			cout << " ROOT		   ";
		}
		else {
			cout <<" (" << col_principal->getPos_x() << "," << col_principal->getPos_y() << ")" << col_principal->getEmpresa() <<"	   " ;
		}
		
		if (col_principal->getDer() != NULL) {
			aux = col_principal->getDer();
			while (aux != NULL) {
				if (aux->getPos_y() == -1) {
					cout << " (" << aux->getPos_x() << "," << aux->getPos_y() << ")" << aux->getDepartamento() + "	";
				}
				else {
				    cout << "  (" << aux->getPos_x() << "," << aux->getPos_y() << ")" <<aux->getUsuario() << "	";
				}

				aux = aux->getDer();
			}
		}
		cout << endl; 
		col_principal = col_principal->getDown();
	}
}

void MatrixDis::getGraphviz() {
	Rep* llama = new  Rep();
	llama->grafica_MATRIX(this->root);
}












