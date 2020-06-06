

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


    
    Matriz_dispersa* matrix = new Matriz_dispersa(); 
    matrix->add("adidas", "SOLOLA", "peco");
    matrix->add("adidas", "REU", "val");
    matrix->add("adidas", "HUEHUETENANGO", "Espino");
    matrix->add("ESTANCIA", "HUEHUETENANGO", "Rambo");
    matrix->add("BURGER" , "PETEN" , "pio");
    matrix->add("CAMPERO" , "PETEN", "ALI");
    matrix->add("MACDONALS", "PETEN", "simon");
    matrix->add("FIFA", "REU", "Ronaldo");
    matrix->add("MAX", "REU", "Espino");
    matrix->add("MAX", "SOLOLA", "pablo");
    matrix->add("MAX", "PETEN", "JESUS");
    matrix->add("BURGER", "HUEHUETENANGO", "CARLOS");
    matrix->add("MAX", "HUEHUETENANGO", "LIO");
    matrix->getGraphviz();
   

    system("pause");
}
