#pragma once
#include<iostream>
#include<string>
#include"Act.h"
using namespace std;
class Navl
{
public:
	Navl* iz;
	Navl* de;
	Act* acti;
	int al; 
	inline Navl(Act* activo_) {
		this->acti = activo_;
		this->iz = NULL;
		this->de = NULL;
		this->al = 1; // la altura es igual a 1 por defecto segun https://www.cs.usfca.edu/~galles/visualization/AVLtree.html una herrmienta para visualizar le AVL 
	}


	

	inline void set_Mayor_Altura(int altura_hijo1 , int altura_hijo2) {// la unica vez que me pondre a cambiar alturas sera cuando este escogiendo al mayor de los valores 
		// de las alturas de mis hijos 
		if (altura_hijo1 < altura_hijo2) {
			this->al = altura_hijo2 + 1 ;
		}
		else {
			this->al = altura_hijo1 + 1 ;
		}
	}
	
};
