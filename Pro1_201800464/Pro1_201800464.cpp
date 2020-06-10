

#include <iostream>
#include"Init.h"
#include"Usuario.h"
#include"Matriz_dispersa.h"
#include "Transa.h"
#include"CircularDobleTransacciones.h"
#include<string.h>
#include<stdio.h>
#include"Navl.h"
#include"ArbolBin.h"
#include"Act.h"

using namespace std;

/*
        
                            MI CLASE PRINCIPAL -> PABLO ANDRES ARGUETA HERNANDEZ 201800464

*/

int main()
{
  

    

    
    ArbolBin* arb = new ArbolBin();

    Navl* n1 = new Navl(new Act("1")); 
    Navl* n2 = new Navl(new Act("2"));
    Navl* n3 = new Navl(new Act("3"));
    Navl* n4 = new Navl(new Act("4"));
    Navl* n5 = new Navl(new Act("5"));
    Navl* n9 = new Navl(new Act("9"));
    arb->add(n2);
    arb->add(n1);
    system("cls");
    arb->add(n3);
    arb->add(n5);
    arb->eliminar("1");

    /*arb->add_Activo("CARRO", "PA JUAGAR HOT WHEELS", true);
    arb->add_Activo("MOTO", "PA JUAGAR HOT WHEELS", true);
    arb->add_Activo("AVION", "PA JUAGAR HOT WHEELS", true);*/

    arb->getGraphviz();



    /*
    arb->recorrido_inOrder();

    Navl* buscar = arb->buscar("B301B");
    if (buscar != NULL) {
        cout << "lo encontro" << endl; 
        buscar->acti->id_activ = "A301X";
    }
    



    */
    
    //iniciar(); 
    /*
    CircularDobleTransacciones* cir = new CircularDobleTransacciones(); 
    Transa* n1 = new Transa();
    Transa* n2 = new Transa();
    Transa* n3 = new Transa();
    cir->add(n1);
    cir->add(n2);
    cir->add(n3);
    cir->imprimeparaAdelnate(); 
    cir->imprimeparaAtras();
    cir->getGraphviz(); 
    
    






   

    Usuario* u1 = new Usuario("peco", "Pablo andres Arguerta Hernandez" , "contra");
    Usuario* u2 = new Usuario("val", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u3 = new Usuario("Espino", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u4 = new Usuario("Rambo", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u5 = new Usuario("pio", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u6 = new Usuario("ALI", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u7 = new Usuario("simon", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u9 = new Usuario("Ronaldo", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u10 = new Usuario("pablo", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u11 = new Usuario("JESUS", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u12 = new Usuario("CARLOS", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u13 = new Usuario("LIO", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u14 = new Usuario("PEDROO", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u15 = new Usuario("VALERIA", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u16 = new Usuario("ANA", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u17 = new Usuario("JUANA", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u18 = new Usuario("DENVER", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u19 = new Usuario("MILY", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u20 = new Usuario("MOLY", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u8 = new Usuario("MARTIN", "Pablo andres Arguerta Hernandez", "contra");
    Usuario* u100 = new Usuario("MERLIN", "Pz", "constra");
    Matriz_dispersa* matrix = new Matriz_dispersa(); 
    matrix->add("adidas", "SOLOLA", u1);
    matrix->add("adidas", "REU", u2);
    matrix->add("adidas", "HUEHUETENANGO", u3);
    matrix->add("ESTANCIA", "HUEHUETENANGO",u4);
    matrix->add("BURGER" , "PETEN" , u5);
    matrix->add("CAMPERO" , "PETEN", u6);
    matrix->add("MACDONALS", "PETEN", u7);
    matrix->add("FIFA", "REU", u9);
    matrix->add("MAX", "SOLOLA", u10);
    matrix->add("MAX", "PETEN", u11);
    matrix->add("BURGER", "HUEHUETENANGO", u12);
    matrix->add("MAX", "HUEHUETENANGO", u13);
    matrix->add("FIFA", "REU", u15);
    matrix->add("FIFA", "REU", u16);
    matrix->add("FIFA", "REU", u17);
    matrix->add("MAX", "SOLOLA", u18);
    matrix->add("CAMPERO", "PETEN", u19);
    matrix->add("CAMPERO", "PETEN", u20);
    matrix->add("BURGER", "HUEHUETENANGO", u8);
    matrix->add("BURGER", "HUEHUETENANGO", u8);
    matrix->add("CAN", "KUN", u100);
    matrix->eliminarInterno("CAN", "KUN", "MERLIN");

    matrix->eliminarInterno("MAX", "SOLOLA", "pablo");
    matrix->eliminarInterno("FIFA", "REU", "Ronaldo");
    matrix->eliminarInterno("FIFA", "REU", "VALERIA");
    matrix->eliminarInterno("FIFA", "REU", "ANA");
    matrix->eliminarInterno("adidas", "SOLOLA", "peco");
    matrix->eliminarInterno("adidas", "HUEHUETENANGO", "Espino");
   // matrix->eliminarInterno("MAX", "HUEHUETENANGO", "LIO");
 
  //  matrix->eliminarInterno("CAMPERO", "PETEN", "MOLY");
   
  

  

    /*
    nMatrix* busqueda = new nMatrix("a", "a" , u1);
    busqueda = matrix->BuscarNodo("MACDONALS","PETEN" , "simon");
    if (busqueda != NULL ) {
        cout << "ENCONTRO A :   " << busqueda->getUsuario()->getNomUser() << "nombre:"<< busqueda->getUsuario()->getNombreCompleto() << endl;
    }
    else {
        cout << "el elemento no se encontro " << endl; 
    }
    busqueda->getUsuario()->setNombreCompleto("PANCHO LUIS DOMINGUEZ :V");

    if (busqueda != NULL) {
        cout << "ENCONTRO A :   " << busqueda->getUsuario()->getNomUser() << "nombre:" << busqueda->getUsuario()->getNombreCompleto() << endl;
    }
    else {
        cout << "el elemento no se encontro " << endl;
    }
      matrix->getGraphviz();
    matrix->imprimirSolo3D();
    */
  
  

    system("pause");
}
