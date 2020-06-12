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
	inline NodoDobleC() { this->tra = NULL; this->ant = NULL; this->sig = NULL; }
	inline NodoDobleC(Transa* transaccion_) { this->tra = transaccion_; this->ant = NULL; this->sig = NULL;}
};
