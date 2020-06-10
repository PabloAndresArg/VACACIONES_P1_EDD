#pragma once
#include<iostream>
#include<string>
#include"Transa.h"
using namespace std;
class NodoDobleC {
public:
	Transa* tra;
	NodoDobleC* ant;
	NodoDobleC* sig;
	NodoDobleC() { this->ant = NULL; this->sig = NULL; }
	NodoDobleC(Transa* transaccion_) { this->tra = transaccion_; }
};
