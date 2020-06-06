#pragma once
#include<iostream>
#include<string>
#include"AsciiArte.h"
using namespace std;
// PROTOTIPOS PARA QUE EL ORDEN EN QUE LOS LLAME NO IMPORTE 
void iniciar();
void menu_login(); 








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
	string user = ""; 
	cout << "usuario: "; cin >> user; cout << endl; 
	string contra = ""; 
	cout << "password: "; cin >> contra; cout << endl;

	if (user.compare("admin") == 0  && contra.compare("admin") == 0  ) {
		cout << "Bienvenido Admin" << endl; 
	}

	system("pause");
}

