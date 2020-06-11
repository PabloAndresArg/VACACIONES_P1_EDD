#pragma once
#include<iostream>
#include<string>
#include"AsciiArte.h"
#include"Usuario.h"
#include"Matriz_dispersa.h"
#include"nMatrix.h"
#include"CircularDobleTransacciones.h"
#include"Estatic.h"

// en el catalofo solo se muestran los que estan disponibles  , asegurarme que los ids no se repitan en todos los arboles 

using namespace std;
// PROTOTIPOS PARA QUE EL ORDEN EN QUE LOS LLAME NO IMPORTE 
void iniciar();
void menu_login(); 
void menu_admin(); 
void menu_usuario(); 
//admin----------------------
void crear_usurio(); 
void eliminar_usuario();
void reporte_de_activos_de_un_usuario();
//usuarios-------------------
void agregar__Activo(); 
void eliminar__Activo(); 
void modificar__Activo();
void rentar__Activo(); 

// ESTRUCTURAS ESTATICAS 
Matriz_dispersa* MATRIX = new Matriz_dispersa(); 
CircularDobleTransacciones* CIRCULAR = new CircularDobleTransacciones(); 
nMatrix* NODO_ACTUAL; 


void cargarPrueba() {
	Usuario* pablo = new Usuario("p","p", "p");
	MATRIX->add("p", "p", pablo);
	Usuario* valeria = new Usuario("v", "v", "v");
	MATRIX->add("v", "v", valeria);
}

void iniciar() {
	while (true) {
		system("cls");
		ascii_inicio();
		cout << "Presiona 1 para ir al LOGIN" << endl;
		cout << "Presiona otra tecla para salir" << endl;
		char seleccion = ' ';
		cin >> seleccion;
		if (seleccion == '1') {
			menu_login(); 
		}
		else {
			system("cls");
			ascii_carnet(); 
			system("pause");
			exit(0);
		}
	}
}
void menu_login() {
	system("cls");
	ascii_login();
	string user = "";cout << "usuario: "; cin >> user; cout << endl; 
	string contra = ""; cout << "password: "; cin >> contra; cout << endl;

	if (user.compare("admin") == 0  && contra.compare("admin") == 0  ) {
		menu_admin();
		return; 
	}
	string emp = ""; cout << "empresa: "; cin >> emp;
	string depar = ""; cout << "departamento: "; cin >> depar;
	NODO_ACTUAL = MATRIX->BuscarNodo(emp,depar,user);
	if (NODO_ACTUAL != NULL && (NODO_ACTUAL->getUsuario()->getPass().compare(contra) == 0)  ) {
		menu_usuario();
		return; 
	}
	else {
		cout << "password incorrecto" << endl; 
	}
	system("pause");
}

void menu_admin() {
	bool estoy_en_menu = true; 
	while (estoy_en_menu) {
		system("cls");
		ascii_admin();
		// cosas de usuarios 
		cout << "0: Registrar un Usuario " << endl;
		cout << "1: Eliminar un Usuario " << endl; 
		cout << "2: Reporte Matriz Dispersa " << endl;

		//Reportes extras
		cout << "3: Reporte de activos Disponibles en una empresa" << endl;
		cout << "4: Reporte de activos Disponibles en un Departamento" << endl; 

		// transacciones 
		cout << "5: Reporte Transacciones" << endl;
		// activos de usuario , arboles 
		cout << "6: Reporte de Activos de un Usuario"<< endl;
		cout << "7: Reporte Activos Rentados de un Usuario" << endl;

		cout << "8: Ordenar Transacciones Ascendentemente" << endl; 
		cout << "9: Ordenar Transacciones Descendentemente" << endl;
		cout << "- salir con una letra" << endl;
		char seleccion = ' ';
		cin >> seleccion;
		if (seleccion == '0') {
			crear_usurio(); 
		}
		else if (seleccion == '1') {
			eliminar_usuario(); 
		}
		else if (seleccion == '2') {
			MATRIX->getGraphviz(); 
		}
		else if (seleccion == '3') {

		}
		else if (seleccion == '4') {

		}
		else if (seleccion == '5') {
			CIRCULAR->getGraphviz(); 
		}
		else if (seleccion == '6') {
			reporte_de_activos_de_un_usuario();
		}
		else if (seleccion == '7') {


		}
		else if (seleccion == '8') {
			CIRCULAR->OrdenarAsc(); 
			cout << "Ordenada Ascendentemente correctamente" << endl; 
			system("pause");
		}
		else if (seleccion == '9') {
			CIRCULAR->OrdenarDescen();
			cout << "Ordenada Descendentemente correctamente" << endl;
			system("pause");
		}
		else {
			cout <<" cerrando sesion "<< endl; 
			system("pause");
			estoy_en_menu = false;
		}
		
	}
}



void crear_usurio() {
	system("cls");
	ascii_admin();
	cout << "Ingresa Nombre de Usuario: " << endl; 
	string us; cin >> us;
	cout << "Ingresa un Password: " << endl;
	string contra; cin >> contra; 
	cout << "ingrese nombre Completo" << endl; 
	string nombreCOm; cin >> nombreCOm;
	cout << "Ingresa Empresa" << endl;
	string emp; cin >> emp;
	cout << "Ingresa Departamento" << endl;
	string depar; cin >> depar; 


	Usuario* nuevo_USuario = new Usuario(us , nombreCOm, contra);
	MATRIX->add(  emp ,  depar , nuevo_USuario);
}

void eliminar_usuario() {
	system("cls");
	ascii_admin();
	cout << "Ingresa Nombre de Usuario que desea eliminar: " << endl;
	string us; cin >> us;
	cout << "Ingresa la Empresa" << endl;
	string emp; cin >> emp;
	cout << "Ingresa el departamento" << endl;
	string depar; cin >> depar;

	MATRIX->eliminarInterno(emp , depar , us); 
}


void menu_usuario() {
	bool estoy_en_menu = true;
	while (estoy_en_menu) {
		system("cls");
		ascii_user();
		cout << "BIENVENIDO USUARIO: " << NODO_ACTUAL->getUsuario()->getNomUser() << endl;
		cout << "1: Agregar     Activo" << endl;
		cout << "2: Eliminar    Activo" << endl;
		cout << "3: Modificar   Activo" << endl;
		cout << "4: Rentar      Activo" << endl;
		cout << "5: Activos que yo tengo rentados" << endl;
		cout << "6: Activos que Otros usuarios me han rentado" << endl;
		cout << "7: cerrar sesion" << endl;
		char seleccion = ' ';
		cin >> seleccion;

		if (seleccion == '1') {
			agregar__Activo();
		}
		else if (seleccion == '2') {
			eliminar__Activo();
		}
		else if (seleccion == '3') {
			modificar__Activo(); 
		}
		else if (seleccion == '4') {
			rentar__Activo(); 
		}
		else if (seleccion == '5') {

		}
		else if (seleccion == '6') {

		}
		else if (seleccion == '7') {// exit :v
			break;
		}
		else {
			cout << "Opcion invalida..!! :D" << endl; system("pause");
		}
	}
}

void agregar__Activo() {
	system("cls");
	ascii_user();
	cout << "CREACION DE UN ACTIVO: " << endl;
	string nom;cout << "Ingresa un nombre: "<<endl;cin>>nom;
	string des; cout << "Ingresa una descripcion" << endl; cin >> des;
	NODO_ACTUAL->getUsuario()->getArbol_activos()->add_Activo(nom,des,true); 
	system("pause");
}
void eliminar__Activo() {
	system("cls");
	ascii_user();
	cout << "ELIMINACION DE UN ACTIVO: " << endl;
	NODO_ACTUAL->getUsuario()->getArbol_activos()->mostrar_activos(); 
	if (NODO_ACTUAL->getUsuario()->getArbol_activos()->getRoot() != NULL) {
		cout << "Ingresa el Id del activo: " << endl; 
		string id_a = ""; 
		cin >> id_a;
		Navl* busq = NODO_ACTUAL->getUsuario()->getArbol_activos()->buscar(id_a);
		if (busq != NULL) {
			cout << "ID: " << busq->acti->id_activ << endl;
			cout << "Nombre: " << busq->acti->nombre << endl;;
			cout << "descripcion: " << busq->acti->descripcion << endl;
			NODO_ACTUAL->getUsuario()->getArbol_activos()->eliminar(id_a);
		}
	}
	system("pause");
}
void reporte_de_activos_de_un_usuario() {
	system("cls");
	ascii_admin();
	cout << "REPORTE ACTIVOS DE UN USUARIO:" << endl;
	cout << "Ingresa Nombre de Usuario: " << endl;
	string us; cin >> us;
	cout << "Ingresa la Empresa" << endl;
	string emp; cin >> emp;
	cout << "Ingresa el departamento" << endl;
	string depar; cin >> depar;
	NODO_ACTUAL = MATRIX->BuscarNodo(emp, depar, us);
	if (NODO_ACTUAL != NULL) {
		NODO_ACTUAL->getUsuario()->getArbol_activos()->getGraphviz(); 
	}
	else {
		cout << "usuario no encontrado :(" << endl; 
		system("pause");
	}
}
void modificar__Activo() {
	system("cls");
	ascii_user();
	cout << "MODIFICACION DE UN ACTIVO: " << endl;
	NODO_ACTUAL->getUsuario()->getArbol_activos()->mostrar_activos();
	cout << "Ingresa el Id del activo: " << endl;
	string id_a = "";
	cin >> id_a;
	string nueva_des; cout << "Ingrese la nueva descripcion" << endl; cin >> nueva_des;
	Navl* busq = NODO_ACTUAL->getUsuario()->getArbol_activos()->buscar(id_a);
	if (busq != NULL) {
		busq->acti->descripcion = nueva_des;
		cout << "ID: " << busq->acti->id_activ << endl;
		cout << "Nombre: " << busq->acti->nombre << endl;;
		cout << "descripcion: " << busq->acti->descripcion << endl;
	}
	system("pause");
}



void rentar__Activo() {
	system("cls");
	ascii_user();
	cout << "CATALOGO PARA RENTAR:" << endl;
	cout << "				1. Rentar Activo" << endl; 
	cout << "				2. Regresar     " << endl;
	char seleccion = ' ';
	cin >> seleccion;

	system("pause");

}