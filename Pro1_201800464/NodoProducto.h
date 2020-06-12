#pragma once
#include<iostream>
#include"Producto.h"
class NodoProducto {
public:
	NodoProducto* next;
	Producto* producto;
	inline NodoProducto(Producto* pr) {
		this->producto = pr;
		next = NULL;
	}
	inline NodoProducto() {
		next = NULL;
		this->producto =NULL;
	}
};