

#include <iostream>
#include"Init.h"
#include"Usuario.h"
#include "MatrixDis.h"
#include"Matriz_dispersa.h"
using namespace std;

/*
        
                            MI CLASE PRINCIPAL -> PABLO ANDRES ARGUETA HERNANDEZ 201800464

*/

int main()
{
    //iniciar(); 
   
  /*
    MatrixDis* m = new MatrixDis(); 
    Usuario* use = new Usuario("pablo"); 
    Usuario* use2 = new Usuario("val");
    Usuario* use3 = new Usuario("peco");
    Usuario* use4 = new Usuario("Espino");
    Usuario* use5 = new Usuario("Rambo");
    m->add("MAX", "SOLOLA", use5);
    m->add("adidas", "REU", use);
    m->add("adidas", "HUEHUETENANGO", use2);
    m->add("ESTANCIA", "HUEHUETENANGO", use3);
    m->add("MAX", "REU", use4);
    //m->add("adidas", "SOLOLA", use3);
    m->imprimirMatriz(); 
    m->getGraphviz(); */


    
    Matriz_dispersa* matrix = new Matriz_dispersa(); 
    matrix->add("adidas", "SOLOLA", "peco");
    matrix->add("adidas", "REU", "val");
    matrix->add("adidas", "HUEHUETENANGO", "Espino");
    matrix->add("ESTANCIA", "HUEHUETENANGO", "Rambo");

    matrix->add("MAX", "REU", "Espino");

    matrix->add("MAX", "SOLOLA", "pablo");
    matrix->getGraphviz();
   

    system("pause");
}
