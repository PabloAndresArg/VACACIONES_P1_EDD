#pragma once
#include<string>
using namespace std; 
class Transa
{
private:  
	string id_transaccion;
	string id_activo;
	string nombreUsuario; 
	string departamento; 
	string empresa; 
	string fecha; 
	string tiempo; 

public: 
	Transa(string id_) {
		this->id_transaccion = id_;
		this->id_activo = "vacio";
		this->nombreUsuario = "vacio";
		this->departamento = "vacio";
		this->empresa = "vacio";
		this->fecha = "vacio";
		this->tiempo = "vacio";
	}

	Transa() {
		this->id_transaccion = "vacio";
		this->id_activo = "vacio";
		this->nombreUsuario = "vacio";
		this->departamento = "vacio";
		this->empresa = "vacio";
		this->fecha = "vacio";
		this->tiempo = "vacio";
	}

	Transa(string id_transaccion , string id_activo , string nombreU , string emp , string dep , string fecha, string ti) {
		this->id_transaccion = id_transaccion; 
		this->id_activo = id_activo; 
		this->nombreUsuario = nombreU;
		this->departamento = dep; 
		this->empresa = emp; 
		this->fecha = fecha; 
		this->tiempo = ti; 
	}

	Transa( string id_activo, string nombreU, string emp, string dep, string fecha, string ti) { // tendria que settar su ide desde fuera 
		this->id_activo = id_activo;
		this->nombreUsuario = nombreU;
		this->departamento = dep;
		this->empresa = emp;
		this->fecha = fecha;
		this->tiempo = ti;
	}


	inline string getId_tra() { return this->id_transaccion; }
	inline string getId_activo() { return this->id_activo; }
	inline string getNombreUsuario() { return this->nombreUsuario; }
	inline string getDepa() { return this->departamento; }
	inline string getEmpresa(){ return this->empresa; }
	inline string getFecha()  { return this->fecha; }
	inline string getTiempo() { return this->tiempo;}

	inline void setId_transaccion(string nuevoId) { this->id_transaccion = nuevoId; }



};

