#pragma once
#include<stdlib.h>
#include<string>
#include<string.h>
#include<fstream>

#include"nMatrix.h"
/*
author: PABLO ARGUETA 
*/
using namespace std;

class Rep {

public: 













	//OK

	void graphMatrix(nMatrix* root) {
		if (root->getDer() == NULL) {
			cout << "MATRIZ VACIA" << endl;
		}
		else {
			ofstream w;
			w.open("REPORTES\\matriz.txt", ios::out);
			if (w.fail())
			{
				cout << "NO SE ABRE :(" << endl;
				system("pause");
				exit(1);
			}
			w << "digraph G {bgcolor = black; \nnode[pin = true , shape = box, fontcolor = black  , fillcolor = gray  , width=0.7 ,style = filled] ;\ncharset = latin1;\n style = filled ;\nnodesep = 1.0;\n";
			nMatrix* aux = root;
			nMatrix* aux2 = NULL;
			while (aux != NULL) {
				if (aux->getDer() != NULL) {
					w << "VAL_" << &*aux << "->" << "VAL_" << &*aux->getDer() << " [ dir=both ,color = white]; " << "\n";
				}
				if (aux->getIzq() != NULL) {
					//w << "VAL_" << &*aux << "->" << "VAL_" << &*aux->getIzq() << " [arrowhead = empty, color = white]; " << "\n";
				}
				if (aux->getDown() != NULL) {
					w << "VAL_" << &*aux << "->" << "VAL_" << &*aux->getDown() << " [  dir=both,  color = white]; " << "\n";
				}
				if (aux->getUp() != NULL) {
					//w << "VAL_" << &*aux << "->" << "VAL_" << &*aux->getUp() << " [arrowhead = empty, color = white]; " << "\n";
				}
				// nomnbre-----------------------------------------------------------
				if (aux != root && aux->getPos_x() == -1) {
					w << "VAL_" << &*aux << "[label=\"" << aux->getEmpresa() << "\" , group = " << to_string(aux->getPos_x()) << ",pos = \"" << to_string(aux->getPos_x()) << "," << to_string((-1) * (aux->getPos_y())) << "\" ];\n";
				}
				else {
					w << "VAL_" << &*aux << "[label = \"ROOT\", group = " << to_string(aux->getPos_x()) << ",pos = \"" << to_string(aux->getPos_x()) << "," << to_string((-1) * (aux->getPos_y())) << "\" ];\n";
				}
				if (aux->getDer() != NULL)
				{
					aux2 = aux->getDer();
					while (aux2 != NULL)
					{
						if (aux2->getDer() != NULL) {
							w << "VAL_" << &*aux2 << "->" << "VAL_" << &*aux2->getDer() << " [ dir=both, color = white]; " << "\n";
						}
						if (aux2->getIzq() != NULL) {
							//	w << "VAL_" << &*aux2 << "->" << "VAL_" << &*aux2->getIzq() << " [arrowhead = empty, color = white]; " << "\n";
						}
						if (aux2->getDown() != NULL) {
							w << "VAL_" << &*aux2 << "->" << "VAL_" << &*aux2->getDown() << " [ dir=both, color = white]; " << "\n";
						}
						if (aux2->getUp() != NULL) {
							//	w << "VAL_" << &*aux2 << "->" << "VAL_" << &*aux2->getUp() << " [arrowhead = empty, color = white]; " << "\n";
						}
						//-------------------------------------------- NOMBRES
						if (aux2->getPos_y() == -1) {// si mi pos en x es negativa en y si voy a tener 
							w << "VAL_" << &*aux2 << "[label=\"" << aux2->getDepartamento() << "\", group = " << to_string(aux2->getPos_x()) << ",pos = \"" << to_string(aux2->getPos_x()) << "," << to_string((-1) * (aux2->getPos_y())) << "\" ];\n";
						}
						else {
							w << "VAL_" << &*aux2 << "[ label = \"" << aux2->getUsuario() << "\" ,dir=both ,fillcolor = chartreuse1, group = " << to_string(aux2->getPos_x()) << ",pos = \"" << to_string(aux2->getPos_x()) << "," << to_string((-1) * (aux2->getPos_y())) << "\" ];\n";
						}
						aux2 = aux2->getDer();
					}
				}
				aux = aux->getDown();
			}


			// rank
			aux = root;
			aux2 = NULL;
			while (aux != NULL) {
				w << "{rank = same; ";
				w << "VAL_" << &*aux << " ";
				if (aux->getDer() != NULL)
				{
					aux2 = aux->getDer();
					while (aux2 != NULL)
					{
						w << "VAL_" << &*aux2 << " ";
						aux2 = aux2->getDer();
					}
				}
				w << "};\n\n";
				aux = aux->getDown();
			}

			w << "}\n";
			w.close();
			char eje[] = "dot -Tjpg REPORTES\\matriz.txt -o REPORTES\\matriz.jpg";
			system(eje);
			char abre[] = "REPORTES\\matriz.jpg";
			system(abre);
		}
	}

};
