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
		if (decision == NULL) {//insercion en 2D
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
			//cout << "nuevo: " << nuevo_nodo->getUsuario()->getNomUser() << "(" << nuevo_nodo->getEmpresa() << "," << nuevo_nodo->getDepartamento() << ")" << "POSICION:" << "[" << nuevo_nodo->getPos_x() << "," << nuevo_nodo->getPos_y() << "]" << endl;






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


		}
		else {
			// decision puede tener sus 4 punteros entonces esos los va heredar el nuevo nodo 
			if (UsuarioRepetido(decision , nuevo_nodo->getUsuario()->getNomUser())) {
				cout << "ese usuario ya existe en esa posicion por tanto no sera ingresado.." << endl;
				return; 
			}
			nuevo_nodo = heredarPunteros(nuevo_nodo, decision);// de una inserta en		3D
			//this->imprimirFondo(nuevo_nodo);
		return;
		}

}

bool Matriz_dispersa::UsuarioRepetido(nMatrix* coordenada, string nombre) {
	nMatrix* aux = coordenada;
	while (aux != NULL) {
		if (aux->getUsuario()->getNomUser() == nombre ) {
			return true;
		}
		aux = aux->getBehind();
	}
	return false; 
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
nMatrix* Matriz_dispersa::reemplazarCara(nMatrix* cara, nMatrix* nuevaCara) {// muy parecido al de heredar punteros pero en este solo reemplazo NO inserto
	cara->getUp()->setAbajo(nuevaCara);
	cara->getIzq()->setDerecha(nuevaCara);
	if (cara->getDer() != NULL) {
		cara->getDer()->setIzq(nuevaCara);
	}
	if (cara->getDown() != NULL) {
		cara->getDown()->setArriba(nuevaCara);
	}
	// 0 clavos 
	nuevaCara->setAbajo(cara->getDown());
	nuevaCara->setArriba(cara->getUp());
	nuevaCara->setIzq(cara->getIzq());
	nuevaCara->setDerecha(cara->getDer());
	nuevaCara->setFront(NULL);
	// limpieza de mi nodo que antes era la CARA 
	cara = NULL; 
	return nuevaCara;
}



nMatrix* Matriz_dispersa::actualizaPosiciones(nMatrix*nuevo_nodo , nMatrix* fil_empresa , nMatrix* col_departamento) {
	nuevo_nodo->setPos_x(fil_empresa->getPos_y());
	nuevo_nodo->setPos_y(col_departamento->getPos_x());
	return nuevo_nodo;
}









void Matriz_dispersa::getGraphviz() {
		Rep* llama = new  Rep();
		llama->graphMatrix(this->root);
		llama->graph3Dmatrix(this->root);
}





void Matriz_dispersa::modificarUsuario(string empresa, string departamento , Usuario* usuarioModificado) {
	nMatrix* col_principal = this->root;
	nMatrix* aux = NULL;
	nMatrix* aux3D = NULL;
	while (col_principal != NULL) {

		if (col_principal->getDer() != NULL) {
			aux = col_principal->getDer();
			while (aux != NULL) {
				if (aux->getEmpresa().compare(empresa) == 0 && aux->getDepartamento().compare(departamento) == 0) {
					// antes de ir a buscar en 3D vere si este nodo es el que buscaba , tons PREGUNTO 
					if (aux->getUsuario()->getNomUser().compare(usuarioModificado->getNomUser()) == 0) {
						aux->setUsuario(usuarioModificado);
						return;
					}
					if (aux->getBehind() != NULL) {// buscando en 3D 
						aux3D = aux;
						while (aux3D != NULL) {
							if (aux3D->getUsuario()->getNomUser().compare(usuarioModificado->getNomUser()) == 0) {
								aux3D->setUsuario(usuarioModificado);
								return;
							}
							aux3D = aux3D->getBehind();
						}
					}
				}
				aux = aux->getDer();
			}
		}
		col_principal = col_principal->getDown();
	}

}

nMatrix* Matriz_dispersa::BuscarNodo(string empresa, string departamento , string nombreUser) {
	nMatrix* col_principal = this->root;
	nMatrix* aux = NULL;
	nMatrix* aux3D = NULL; 
	while (col_principal != NULL) {

		if (col_principal->getDer() != NULL) {
			aux = col_principal->getDer();
			while (aux != NULL) {
				if (aux->getEmpresa().compare(empresa) == 0 && aux->getDepartamento().compare(departamento) == 0) {
					// antes de ir a buscar en 3D vere si este nodo es el que buscaba , tons PREGUNTO 
					if (aux->getUsuario()->getNomUser().compare(nombreUser) == 0 ) {
						return aux;
					}
					if (aux->getBehind() != NULL) {// buscando en 3D 
						aux3D = aux; 
						while (aux3D != NULL) {
							if (aux3D->getUsuario()->getNomUser().compare(nombreUser) == 0) {
								return aux3D;
							}
							aux3D = aux3D->getBehind(); 
						}
					}
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


void Matriz_dispersa::imprimirFondo(nMatrix * cabeza) {// hacer uno parecido para buscar haber si no hay un nodo ya con el mismo nombre 
	cout << " USUARIOS AL FONDO " << endl;
	nMatrix* aux = cabeza; 
	while (aux != NULL) {
		cout << "USUARIO: "<<aux->getUsuario()->getNomUser()<<endl;
		aux = aux->getBehind(); 
	}
}

void Matriz_dispersa::imprimirSolo3D() {
	nMatrix* col_principal = this->root;
	nMatrix* aux = NULL;
	nMatrix* aux3D = NULL;
	while (col_principal != NULL) {

		if (col_principal->getDer() != NULL) {
			aux = col_principal->getDer();
			while (aux != NULL) {

					if (aux->getBehind() != NULL) {// OTRO WHILE PARA BUSCAR EN 3D 
						aux3D = aux;
						while (aux3D != NULL) {
							//cout << "POS:("<< aux3D->getEmpresa()<<" , "<< aux3D->getDepartamento()<<")"<<" contenido: "<< aux3D->getUsuario()->getNomUser() << endl;
							aux3D = aux3D->getBehind();
						}
					}
				
				aux = aux->getDer();
			}
		}
		col_principal = col_principal->getDown();
	}
}


void Matriz_dispersa::eliminarInterno(string empresa , string departamento , string nombre) {
	nMatrix* nodo_eliminar = this->BuscarNodo( empresa,  departamento, nombre);
	if (nodo_eliminar == NULL) {
		//cout << "no se puede eliminar porque no se encontro el nodo" << endl; 
		return; 
	}
	// ALGO A TENER EN CUENTA GET DERECHO Y GET ABAJO PUEDE QUE SEA NULL 
	// para eliminar uno frontal
	if (nodo_eliminar->getFront() == NULL) {

		if (nodo_eliminar->getBehind() == NULL) {
		// se elimina por completo
			//cout << "ELIMINANDO UN POSICION COMPLETA" << endl; 
			nMatrix* puntero_arriba = nodo_eliminar->getUp(); 
			nMatrix* puntero_abajo = nodo_eliminar->getDown(); 
			nMatrix* puntero_der = nodo_eliminar->getDer();
			nMatrix* puntero_izq = nodo_eliminar->getIzq();

			puntero_arriba->setAbajo(puntero_abajo);
			puntero_izq->setDerecha(puntero_der);
			if (puntero_der != NULL) {
				puntero_der->setIzq(puntero_izq);
			}
			if (puntero_abajo != NULL) {
				puntero_abajo->setArriba(puntero_arriba);
			}
			nodo_eliminar = NULL; 
		}
		else {
			//cout << "reemplazandoCara" << endl; 
			nMatrix* nuevaCara = nodo_eliminar->getBehind(); 		// solo es de subir un nodo de los de atras
			nuevaCara = this->reemplazarCara(nodo_eliminar , nuevaCara);//ya no es necesario revisar las cabeceras 
			return; 

		}

		//revisar si aun queda algo en la cabecera sino eliminarla 

		nMatrix* cabecera_columna_depa = existeColumna(departamento);
		nMatrix* cabeceraFila_empresa = existeFIla(empresa);
		if (cabeceraFila_empresa->getDer() == NULL) {
			//cout << "SE ELIMINA UNA FILA CABECERA" << endl;
			//cout << cabeceraFila_empresa->getPos_x() << "," << cabeceraFila_empresa->getPos_y() <<" "<< cabeceraFila_empresa->getEmpresa() <<endl;
			cabeceraFila_empresa->getUp()->setAbajo(NULL);
		}
		if (cabecera_columna_depa->getDown() == NULL) {
			//cout << "SE ELIMINA UNA COLUMNA CABECERA" << endl;
			cabecera_columna_depa->getIzq()->setDerecha(NULL);
		}

	}
	else {
	// uno de los de 3D
		if (nodo_eliminar->getBehind() == NULL) { // el ultimo de los 3D 
			//cout << "eliminando el ultimo en 3D" << endl; 
			nodo_eliminar->getFront()->setBehind(NULL);
			nodo_eliminar = NULL; 
		}
		else {// eliminando en Medio de los 3D 
			//cout << "eliminando uno de en  medio en 3D" << endl; 
			nMatrix * anterior = nodo_eliminar->getBehind();
			anterior->setFront(nodo_eliminar->getFront());
			nodo_eliminar->getFront()->setBehind(anterior);
			nodo_eliminar = NULL; 
		}


	}


}




void Matriz_dispersa :: reporteEmpresa(string empresa_fila) {
	nMatrix* FILA_ = existeFIla(empresa_fila);
	nMatrix * aux3D = NULL;
	if (FILA_ != NULL) {
		cout << "TRABAJANDO EN EL REPORTE DE EMPRESA...." << endl; 
		FILA_ = FILA_->getDer();// comienza desde el primer usuario 
		while (FILA_ != NULL) {
			if (FILA_->getBehind() != NULL) {// buscando en 3D 
				aux3D = FILA_;
				while (aux3D != NULL) {
					cout << "Usuario: " << aux3D->getUsuario()->getNomUser() << endl;
					aux3D->getUsuario()->getArbol_activos()->getGraphvizRepUsuarios(aux3D->getUsuario()->getNomUser());
					aux3D = aux3D->getBehind();
				}
			}
			else {
				cout << "Usuario: " << FILA_->getUsuario()->getNomUser()<<endl;
				FILA_->getUsuario()->getArbol_activos()->getGraphvizRepUsuarios(FILA_->getUsuario()->getNomUser());
			}
		FILA_ = FILA_->getDer();
		}
		
	}
	else {
		cout << "NO SE ENCONTRO ESA EMPRESA" << endl; 
	}
}

void Matriz_dispersa :: reporteDepartamento(string departamento_colum) {
	nMatrix* COL_ = existeColumna(departamento_colum);
	nMatrix* aux3D = NULL;
	if (COL_ != NULL) {
		COL_ = COL_->getDown();// comienza desde el primer usuario 
		cout << "TRABAJANDO EN EL REPORTE DE ACTIVOS EN UN DEPARTAMENTOS...." << endl;
		while (COL_ != NULL) {
			if (COL_->getBehind() != NULL) {// buscando en 3D 
				aux3D = COL_;
				while (aux3D != NULL) {
					cout << "Usuario: " << aux3D->getUsuario()->getNomUser() << endl;
					aux3D->getUsuario()->getArbol_activos()->getGraphvizRepUsuarios(aux3D->getUsuario()->getNomUser());
					aux3D = aux3D->getBehind();
				}
			}
			else {
				cout << "Usuario: " << COL_->getUsuario()->getNomUser() << endl;
				COL_->getUsuario()->getArbol_activos()->getGraphvizRepUsuarios(COL_->getUsuario()->getNomUser());
			}
			COL_ = COL_->getDown();
		}
	}
	else {
		cout << "NO SE ENCONTRO ESE DEPARTAMENTO" << endl;
	}
}











CatalogoLsimple* Matriz_dispersa::recolectaProductos(CatalogoLsimple* CATALOGO = new CatalogoLsimple()) {// punto de inicio


	nMatrix* col_principal = this->root->getDown();// que comience desde los usuarios 
	nMatrix* aux = NULL;
	nMatrix* aux3D = NULL;
	while (col_principal != NULL) {
		if (col_principal->getDer() != NULL) {
			aux = col_principal->getDer();
			while (aux != NULL) {
					if (aux->getBehind() != NULL) {// buscando en 3D 
						aux3D = aux;
						while (aux3D != NULL) {
							//cout << "Usuario: " << aux3D->getUsuario()->getNomUser() << endl;
							aux3D->getUsuario()->getArbol_activos()->recolectaPro(CATALOGO , aux3D->getUsuario()->getNomUser() , aux3D->getEmpresa() , aux3D->getDepartamento() ); // entro al arbol de cada usuario 
							aux3D = aux3D->getBehind(); 
						}
					}
					else {
						 //cout << "Usuario: " << aux->getUsuario()->getNomUser() << endl;
						 aux->getUsuario()->getArbol_activos()->recolectaPro(CATALOGO, aux->getUsuario()->getNomUser(), aux->getEmpresa(), aux->getDepartamento()); // entro al arbol de cada usuario 
					}
				aux = aux->getDer();
			}
		}
		col_principal = col_principal->getDown();
	}



	return CATALOGO;
}