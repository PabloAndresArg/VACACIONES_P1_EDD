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













void Matriz_dispersa::add(string empresa_fila, string departamento_col, Usuario* usuario) {
		nMatrix* decision = this->isInsercion3D(empresa_fila , departamento_col);
		nMatrix* nuevo_nodo = new nMatrix(empresa_fila, departamento_col, usuario);
		if (decision == NULL) {
			cout << "insercion en 2D" << endl; 
			nMatrix* cabecera_columna_depa = existeColumna(departamento_col);
			nMatrix* cabeceraFila_empresa = existeFIla(empresa_fila);
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
			cout << "nuevo: " << nuevo_nodo->getUsuario()->getNomUser() << "(" << nuevo_nodo->getEmpresa() << "," << nuevo_nodo->getDepartamento() << ")" << "POSICION:" << "[" << nuevo_nodo->getPos_x() << "," << nuevo_nodo->getPos_y() << "]" << endl;






			// LISTA DOBLE DE DEPARTAMENTO - COLUMNA 

			if (cabecera_columna_depa->getDown() == NULL) {//inserta al inicio
				cabecera_columna_depa->setAbajo(nuevo_nodo);
				nuevo_nodo->setArriba(cabecera_columna_depa);
			}
			else if (cabecera_columna_depa->getDown() != NULL && cabeceraFila_empresa->getDown() == NULL) { // inserto al final , solo para un caso
				nMatrix* aux = cabecera_columna_depa;
				while (aux->getDown() != NULL) {
					aux = aux->getDown();
				}
				aux->setAbajo(nuevo_nodo);
				nuevo_nodo->setArriba(aux);
			}
			else if (cabecera_columna_depa->getDown() != NULL && cabeceraFila_empresa->getDown() != NULL) {// va en medio de los nodos 
				nMatrix* aux = cabecera_columna_depa;
				nMatrix* ant = new nMatrix("", "");
				aux = aux->getDown();
				while (aux != NULL)
				{
					ant = aux;
					if (aux->getPos_x() == nuevo_nodo->getPos_x())
					{// sobreescribe
						aux->setPos_y(nuevo_nodo->getPos_y());
						aux->setUsuario(nuevo_nodo->getUsuario());
						//cout << "retorna de una ";
						break;
					}
					else if (aux->getPos_x() > nuevo_nodo->getPos_x())
					{
						//insercion antes de un nodo 
						nuevo_nodo->setAbajo(aux);
						aux->getUp()->setAbajo(nuevo_nodo);
						nuevo_nodo->setArriba(aux->getUp());
						aux->setArriba(nuevo_nodo);
						//cout << "NOMBRE DEL NUEVO NODO: " << nuevo_nodo->getUsuario() << endl;
						//cout << "nombre del nodo de abajo " << nuevo_nodo->getDown()->getUsuario() << endl;
						break;
					}
					aux = aux->getDown();
				}

				if (aux == NULL)
				{
					//cout << "INSERTA AL FINAL " << endl;
					ant->setAbajo(nuevo_nodo);
					nuevo_nodo->setArriba(ant);
				}
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
				nMatrix* aux = cabeceraFila_empresa;
				nMatrix* ant = new nMatrix("", "");
				aux = aux->getDer();
				while (aux != NULL)
				{
					ant = aux;
					if (aux->getPos_y() == nuevo_nodo->getPos_y())
					{// sobreescribe
						aux->setPos_x(nuevo_nodo->getPos_x());
						aux->setUsuario(nuevo_nodo->getUsuario());
						break;
					}
					else if (aux->getPos_y() > nuevo_nodo->getPos_y())
					{//antes de 
						nuevo_nodo->setDerecha(aux);
						aux->getIzq()->setDerecha(nuevo_nodo);
						nuevo_nodo->setIzq(aux->getIzq());
						aux->setIzq(nuevo_nodo);
						//	cout << "NOMBRE DEL NUEVO NODO: " << nuevo_nodo->getUsuario() << endl;
						//	cout << "nombre del nodo de DERECHO " << nuevo_nodo->getDer()->getUsuario() << endl;
						break;
					}
					aux = aux->getDer();
				}

				if (aux == NULL)
				{
					//cout << "INSERTA AL FINAL " << endl;
					ant->setDerecha(nuevo_nodo);
					nuevo_nodo->setIzq(ant);
				}


			}


			if (cabeceraFila_empresa == NULL && cabecera_columna_depa == NULL) { cout << "error"; }
			cout << endl;



		}
		else {
     		cout << "insercion en 3D  PASA AL FONDO EL USUARIO:"<<decision->getUsuario()->getNomUser() << endl; 
			// decision puede tener sus 4 punteros entonces esos los va heredar el nuevo nodo 
			
			nuevo_nodo = heredarPunteros(nuevo_nodo, decision);// de una inserta en		3D
			this->imprimirFondo(nuevo_nodo);
		return;
		}

}

nMatrix* Matriz_dispersa::heredarPunteros(nMatrix* nuevo_nodo , nMatrix* decision) {
	// puede que sea una esquina  , o de los ultimos solo daria clavo derecha y abajo 
	decision->getUp()->setAbajo(nuevo_nodo);
	decision->getIzq()->setDerecha(nuevo_nodo);
	if (decision->getDer() != NULL) {
		decision->getDer()->setIzq(nuevo_nodo);
	}
	if (decision->getDown() != NULL) {
		decision->getDown()->setArriba(nuevo_nodo);
	}
	

	// 0 clavos 
	nuevo_nodo->setAbajo(decision->getDown());
	nuevo_nodo->setArriba(decision->getUp());
	nuevo_nodo->setIzq(decision->getIzq());
	nuevo_nodo->setDerecha(decision->getDer());
	// actualiza posiciones
	nuevo_nodo->setPos_x(decision->getPos_x());
	nuevo_nodo->setPos_y(decision->getPos_y());
	// limpieza de mi nodo que antes era la CARA 
	decision->setAbajo(NULL); 
	decision->setArriba(NULL);
	decision->setDerecha(NULL); 
	decision->setIzq(NULL);

	// insercion :O 
	nuevo_nodo->setBehind(decision);
	decision->setFront(nuevo_nodo);

	return nuevo_nodo;
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




nMatrix* Matriz_dispersa::BuscarNodo(string empresa, string departamento , string nombreUser) {
	cout << "buscando un nodo " << endl;
	nMatrix* col_principal = this->root;
	nMatrix* aux = NULL;
	while (col_principal != NULL) {

		if (col_principal->getDer() != NULL) {
			aux = col_principal->getDer();
			while (aux != NULL) {
				if (aux->getEmpresa().compare(empresa) == 0 && aux->getDepartamento().compare(departamento) == 0) {
					// OTRO WHILE PARA BUSCAR EN 3D 
					
				}
				aux = aux->getDer();
			}




		}
		col_principal = col_principal->getDown();
	}
	return NULL;
}


nMatrix* Matriz_dispersa::isInsercion3D(string empresa, string departamento) {
	nMatrix* col_principal = this->root;
	nMatrix* aux = NULL;
	while (col_principal != NULL) {

		if (col_principal->getDer() != NULL) {
			aux = col_principal->getDer(); 
			while (aux != NULL) {
				if (aux->getEmpresa().compare(empresa) == 0 && aux->getDepartamento().compare(departamento) == 0) {
					return aux;
				}
				aux = aux->getDer();
			}
		}
		col_principal = col_principal->getDown();
	}
	return NULL;
}


void Matriz_dispersa::imprimirFondo(nMatrix * cabeza) {
	cout << " USUARIOS AL FONDO " << endl;
	nMatrix* aux = cabeza; 
	while (aux != NULL) {
		cout << "USUARIO: "<<aux->getUsuario()->getNomUser()<<endl;
		aux = aux->getBehind(); 
	}
}
