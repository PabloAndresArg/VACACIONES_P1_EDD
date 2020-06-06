#include "Matriz_dispersa.h"
#include<string>
#include"nMatrix.h"
#include"Rep.h"
#include<iostream>
#include<fstream>

																	// GENERANDO LAS FILAS Y COLUMNAS NUEVAS
nMatrix* Matriz_dispersa::generaFila(string empresaNueva) {
	this->contadorFilas++;
	nMatrix* NUEVA_FILA = new nMatrix(empresaNueva, "-1");
	nMatrix* aux = this->root;
	while (aux->getDown() != NULL) {
		aux = aux->getDown();
	}
	NUEVA_FILA->setPos_x(-1);
	NUEVA_FILA->setPos_y(this->contadorFilas);
	NUEVA_FILA->setArriba(aux);
	aux->setAbajo(NUEVA_FILA);
	return NUEVA_FILA;
}


nMatrix* Matriz_dispersa::generaColumna(string depNuevo) {
	this->contadorColumnas++;
	nMatrix* NUEVA_COLUMNA = new nMatrix("-1", depNuevo);
	nMatrix* aux = this->root;
	while (aux->getDer() != NULL) {
		aux = aux->getDer();
	}
	NUEVA_COLUMNA->setPos_x(this->contadorColumnas);
	NUEVA_COLUMNA->setPos_y(-1);
	NUEVA_COLUMNA->setIzq(aux);
	aux->setDerecha(NUEVA_COLUMNA);
	return NUEVA_COLUMNA;
}





																				// VERIFICANDO SI EXISTE 
nMatrix* Matriz_dispersa::existeColumna(string departamento) { 
	// O O O O O O O O     estoy viendo aca columnas  
	//O
	//O
	nMatrix* aux = this->root;
	while (aux != NULL) {

		if (aux->getDepartamento().compare(departamento) == 0) {
			return aux; // si existe
		}
		aux = aux->getDer();
	}
	if (aux == NULL) {
		return NULL;
	}
}

nMatrix* Matriz_dispersa::existeFIla(string empresa) {
	// O O O 
	//O
	//O
	//O
	//O
	//estoy viendo FILAS 
	nMatrix* aux = this->root;
	while (aux != NULL) {
		if (aux->getEmpresa().compare(empresa) == 0) {
			return aux; // si existe
		}
		aux = aux->getDown();
	}
	if (aux == NULL) {
		return NULL;
	}

}













void Matriz_dispersa::add(string empresa_fila, string departamento_col, string usuario) {

		nMatrix* nuevo_nodo = new nMatrix(empresa_fila, departamento_col, usuario);
		nMatrix* cabecera_columna_depa = existeColumna(departamento_col);// cabeceras  hacia abajo 
		nMatrix* cabeceraFila_empresa = existeFIla(empresa_fila);// cabecera hacia derecha
		int caso = 0;

		if (cabecera_columna_depa == NULL && cabeceraFila_empresa == NULL) {// caso 1 
			cabecera_columna_depa = this->generaColumna(departamento_col);
			cabeceraFila_empresa = this->generaFila(empresa_fila);
		}
		else if (cabecera_columna_depa == NULL && cabeceraFila_empresa != NULL) { // caso 2 
			cabecera_columna_depa = this->generaColumna(departamento_col);


		}
		else if (cabecera_columna_depa != NULL && cabeceraFila_empresa == NULL) { // case3
			cabeceraFila_empresa = this->generaFila(empresa_fila);

		}
		else if (cabecera_columna_depa != NULL && cabeceraFila_empresa != NULL) {// case4

		}

		nuevo_nodo = this->actualizaPosiciones(nuevo_nodo, cabeceraFila_empresa, cabecera_columna_depa);
		// DATOS DEL NODO QUE SE VA  A INSERTAR
		cout << "nuevo: " << nuevo_nodo->getUsuario() << "(" << nuevo_nodo->getEmpresa() << "," << nuevo_nodo->getDepartamento() << ")" << "POSICION:" << "[" << nuevo_nodo->getPos_x() << "," << nuevo_nodo->getPos_y() << "]" << endl;






							// LISTA DOBLE DE DEPARTAMENTO - COLUMNA 

		if (cabecera_columna_depa->getDown() == NULL) {//inserta al inicio
			cabecera_columna_depa->setAbajo(nuevo_nodo);
			nuevo_nodo->setArriba(cabecera_columna_depa);
		}
		else if (cabecera_columna_depa->getDown() != NULL && cabeceraFila_empresa->getDown() == NULL) { // inserto al final  
			nMatrix* aux = cabecera_columna_depa;
			while (aux->getDown() != NULL) {
				aux = aux->getDown();
			}
			// sale le ultimo nodo 
			aux->setAbajo(nuevo_nodo);
			nuevo_nodo->setArriba(aux);
		}
		else if (cabecera_columna_depa->getDown() != NULL && cabeceraFila_empresa->getDown() != NULL) {// va en medio de los nodos 
			// ESTO ES LO QUE NO FUNCIONA , si intento manipular mi NODO ACA 
			nMatrix* aux = cabecera_columna_depa;
			nMatrix* ant = new nMatrix("","");
			aux = aux->getDown();
			while (aux != NULL)
			{
				ant = aux;
				if (aux->getPos_x() == nuevo_nodo->getPos_x())
				{// sobreescribe
					aux->setPos_y(nuevo_nodo->getPos_y());
					aux->setUsuario(nuevo_nodo->getUsuario());
					cout << "retorna de una ";
					break; 
				}
				else if (aux->getPos_x() > nuevo_nodo->getPos_x())
				{
					cout << "sii va antes de un nodo " << endl;
					nuevo_nodo->setAbajo(aux);
					aux->getUp()->setAbajo(nuevo_nodo);
					nuevo_nodo->setArriba(aux->getUp());
					aux->setArriba(nuevo_nodo);
					cout << "NOMBRE DEL NUEVO NODO: " << nuevo_nodo->getUsuario() << endl;
					cout << "nombre del nodo de abajo " << nuevo_nodo->getDown()->getUsuario() << endl;
					break; 
				}
				aux = aux->getDown();
			}

			if (aux == NULL)
			{
				cout << "INSERTA AL FINAL " << endl;
				ant->setAbajo(nuevo_nodo);
				nuevo_nodo->setArriba(ant);
			}
			cout << "--------------------------------------------------------------------" << endl;
			// aca adentro todo bien no mas sale del if pierde sus punteros :''''( 
		}// fin insercion 







									// LISTA DOBLE DE EMPRESA - FILA 

		if (cabeceraFila_empresa->getDer() == NULL) {// inserta al inicio 
			cabeceraFila_empresa->setDerecha(nuevo_nodo);
			nuevo_nodo->setIzq(cabeceraFila_empresa);
		}
		else if (cabeceraFila_empresa->getDer() != NULL && cabecera_columna_depa->getDer() == NULL) {// inserta al final 
			nMatrix* ax = cabeceraFila_empresa;
			while (ax->getDer() != NULL) {
				ax = ax->getDer();
			}
			ax->setDerecha(nuevo_nodo);
			nuevo_nodo->setIzq(ax);
		}
		else {

		}


		if (cabeceraFila_empresa != NULL && cabecera_columna_depa != NULL) {
			// si siguien NULO algo malo paso :v 
		}
		else

		{
			cout << "error";
		}

		cout << endl; cout << endl; cout << endl;






}



nMatrix* Matriz_dispersa::actualizaPosiciones(nMatrix*nuevo_nodo , nMatrix* fil_empresa , nMatrix* col_departamento) {
	nuevo_nodo->setPos_x(fil_empresa->getPos_y());
	nuevo_nodo->setPos_y(col_departamento->getPos_x());
	return nuevo_nodo;
}







void Matriz_dispersa::getGraphviz() {
		Rep* llama = new  Rep();
		llama->graphMatrix(this->root);
}





																				// INSERCIONES ORDENADAS 

nMatrix* Matriz_dispersa::insertarOrdenadoFila(nMatrix* nuevo, nMatrix* Cabecera_fila) {
	bool bandera = false;
	nMatrix* temp = new nMatrix("temp", "temp");
	temp = Cabecera_fila;
	while (true)
	{
		if (temp->getPos_y() == nuevo->getPos_y())
		{// sobreescribe
			temp->setPos_x(nuevo->getPos_x());
			temp->setUsuario(nuevo->getUsuario());
			return temp;
		}
		else if (temp->getPos_y() > nuevo->getPos_y())
		{
			//Al nuevo lo inserto antes que temp
			bandera = true;
			break;
		}
		if (temp->getDown() != NULL) //Me permite mover hasta que no sea nulo
		{
			temp = temp->getDown();
		}
		else //Quiere decir que el que sigue es nulo, nunca cambió la bandera, entonces inserto después de temp
		{
			break;
		}
	}

	if (bandera)
	{
		//Caso antes de un nodo 
		nuevo->setAbajo(temp);
		temp->getUp()->setAbajo(nuevo);
		nuevo->setArriba(temp->getUp());
		temp->setArriba(nuevo);
	}
	else
	{// after de un node :v 
		temp->setAbajo(nuevo);
		nuevo->setArriba(temp);
	}
	cout << "nuevo: " << nuevo->getUsuario() << "(" << nuevo->getEmpresa() << "," << nuevo->getDepartamento() << ")" << "POSICION:" << "[" << nuevo->getPos_x() << "," << nuevo->getPos_y() << "]"<< endl;
	cout << "NODO DE ABAJO: " << nuevo->getDown()->getPos_x() <<"," << nuevo->getDown()->getPos_y()<<endl;
	return nuevo;

}

nMatrix* Matriz_dispersa::insertarOrdenandoColumna(nMatrix* nuevo, nMatrix* cabeza_columna) {
	bool bandera = false;
	nMatrix* temp = new nMatrix("temp", "temp");
	temp = cabeza_columna;
	while (true)
	{
		if (temp->getPos_x() == nuevo->getPos_x()) //Solo sobreescribo el temporal
		{
			temp->setPos_y(nuevo->getPos_y());
			temp->setUsuario(nuevo->getUsuario());

			return temp; //Retorno puntero
		}
		else if (nuevo->getPos_x() < temp->getPos_x()) //Al nuevo lo inserto antes que temp
		{
			bandera = true;
			break;
		}
		if (temp->getDer() != NULL)
		{
			temp = temp->getDer();
		}
		else //Quiere decir que el que sigue es nulo, nunca cambió la bandera, entonces inserto después de temp
		{
			break;
		}
	}

	if (bandera)
	{// inserte antes de..
		nuevo->setDerecha(temp);
		temp->getIzq()->setDerecha(nuevo);
		nuevo->setIzq(temp->getIzq());
		temp->setIzq(nuevo);
	}
	else
	{
		temp->setDerecha(nuevo);
		nuevo->setIzq(temp);
	}
	cout << "nuevo: " << nuevo->getUsuario() << "("<<nuevo->getEmpresa()<<","<<nuevo->getDepartamento()<<")" << "POSICION:" <<"["<<nuevo->getPos_x()<<","<<nuevo->getPos_y()<<"]"<< endl; 
	cout << "NODO DE DER: " << nuevo->getDer()->getPos_x() << "," << nuevo->getDer()->getPos_y() << endl;
	return nuevo;

}