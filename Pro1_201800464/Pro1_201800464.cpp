

#include <iostream>
#include"Init.h"
#include"Usuario.h"
#include"Matriz_dispersa.h"
using namespace std;

/*
        
                            MI CLASE PRINCIPAL -> PABLO ANDRES ARGUETA HERNANDEZ 201800464

*/

int main()
{
    //iniciar(); 


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


    matrix->eliminarInterno("MAX", "SOLOLA", "pablo");
    matrix->eliminarInterno("FIFA", "REU", "Ronaldo");
    matrix->eliminarInterno("FIFA", "REU", "VALERIA");
    matrix->eliminarInterno("FIFA", "REU", "ANA");
    cout << "----" << endl;
    matrix->eliminarInterno("adidas", "SOLOLA", "peco");
    matrix->eliminarInterno("adidas", "HUEHUETENANGO", "Espino");
   // matrix->eliminarInterno("MAX", "HUEHUETENANGO", "LIO");
    cout << "----" << endl;
 
  //  matrix->eliminarInterno("CAMPERO", "PETEN", "MOLY");
   
    matrix->getGraphviz();
    matrix->imprimirSolo3D();



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
    */
 
   

    system("pause");
}
