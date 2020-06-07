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
	void graph3Dmatrix(nMatrix*root) {
		if (root->getDer() == NULL) {
			cout << "MATRIZ VACIA" << endl;
		}
		else {
			ofstream w;
			w.open("REPORTES\\parte3D.txt", ios::out);
			if (w.fail())
			{
				cout << "NO SE ABRE :(" << endl;
				system("pause");
				exit(1);
			}

			w <<"digraph G {\n";
			w <<"rankdir = LR;style = filled; charset = latin1;bgcolor = black; color = aliceblue;\n";
			w<<"node[fillcolor = black, fontcolor = white, color = dodgerblue1, style = filled, shape = component];\n";
			nMatrix* col_principal = root;
			nMatrix* aux = NULL;
			nMatrix* aux3D = NULL;
			int ind = 0; 
			while (col_principal != NULL) {

				if (col_principal->getDer() != NULL) {
					aux = col_principal->getDer();
					while (aux != NULL) {

						if (aux->getBehind() != NULL) {// OTRO WHILE PARA BUSCAR EN 3D 
							aux3D = aux;
							w << "subgraph cluster_"<<std::to_string(ind)<<"{";
							w<< "label = "<<"\"POSICION [ "<< aux->getEmpresa() <<"-"<< aux->getDepartamento()<<" ]\";";
							while (aux3D != NULL) {
								//nombre
								w <<"VAL_" << &*aux3D << "[label = \""<< aux3D->getUsuario()->getNomUser()<< "\" ] ;";
								//enlaces
								if (aux3D->getFront() != NULL) {
									w << "VAL_" << &*aux3D << "->" << "VAL_" << &*aux3D->getFront() << " [ arrowhead = vee ]; " << "\n";
								}
								if (aux3D->getBehind() != NULL) {
									w << "VAL_" << &*aux3D << "->" << "VAL_" << &*aux3D->getBehind() << " [ arrowhead = vee ]; " << "\n";
								}
								aux3D = aux3D->getBehind();
							}
							w << "}\n";
							ind++;
						}
						aux = aux->getDer();
					}
				}
				col_principal = col_principal->getDown();
			}
			w << "}\n";
			w.close();
			char eje[] = "dot -Tjpg REPORTES\\parte3D.txt -o REPORTES\\parte3D.jpg";
			system(eje);
			char abre[] = "REPORTES\\parte3D.jpg";
			system(abre);
		
		}
	}

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
				// Nomnbre encabezado Vertical ----------------------------------------------------------- :) 
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
						//-------------------------------------------- NOMBRES ENCABEZADOS HORIZONTALES :) 
						if (aux2->getPos_y() == -1) {// si mi pos en x es negativa en y si voy a tener algo 
							w << "VAL_" << &*aux2 << "[label=\"" << aux2->getDepartamento() << "\", group = " << to_string(aux2->getPos_x()) << ",pos = \"" << to_string(aux2->getPos_x()) << "," << to_string((-1) * (aux2->getPos_y())) << "\" ];\n";
						}
						else {
							w << "VAL_" << &*aux2 << "[ label = \"" << aux2->getUsuario()->getNomUser() << "\" ,dir=both ,fillcolor = chartreuse1, group = " << to_string(aux2->getPos_x()) << ",pos = \"" << to_string(aux2->getPos_x()) << "," << to_string((-1) * (aux2->getPos_y())) << "\" ];\n";
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
