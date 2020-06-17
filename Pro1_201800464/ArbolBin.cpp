#include "ArbolBin.h"
#include"Estatic.h"
#include"Navl.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include"Rep.h"
#include<time.h>
#include<Windows.h>
using namespace std;



void ArbolBin:: add_Activo(string nom_, string descripcion_, bool disp) {
    string  id_act = this->generarId(); 
    while (yaExisteEl_id(id_act) || Estatica::CONTROL_IDS->yaExisteEl_id(id_act)) {
        id_act = this->generarId();;
    }
    cout << "ID GENERADO: " + id_act << endl;
    Estatica::CONTROL_IDS->add(new Navl(new Act(id_act, nom_, descripcion_, disp)));
   // Estatica::CATALOGO->getGraphviz(); 
    this->add(new Navl(new Act(id_act , nom_ , descripcion_ , disp))); 
}

void ArbolBin::add(Navl* nuevo) { // todo los nombre que agregue deben de ir en minusculas :o 
    if (this->raiz == NULL) {
        this->raiz = nuevo;
    }
    else {
       this->raiz = recursive_add(this->raiz, nuevo);
    }
}

Navl* ArbolBin::recursive_add(Navl* actual, Navl* nuevo) {
    if ((compararAlfabeticamente(actual->acti->id_activ, nuevo->acti->id_activ)) == 1) {
        if (actual->iz != NULL) {
            actual->iz = recursive_add(actual->iz, nuevo);
        }
        else {
            actual->iz = nuevo;
        }
    }
    else if ((compararAlfabeticamente(actual->acti->id_activ, nuevo->acti->id_activ)) == 0) {

        if (actual->de != NULL) {
            actual->de = recursive_add(actual->de, nuevo);
        }
        else {
            actual->de = nuevo;
        }
    }
    else {
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << "REPETIDO: " + nuevo->acti->id_activ << endl; // no lo inserta 
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    }
    // PARTE DEL AVL PARA BALANCEAR MI ARBOL BINARIO 

    actual->set_Mayor_Altura(GET_Al(actual->de), GET_Al(actual->iz));



    int fact = GET_MI_FE(actual);
   // this->dame_la_altura_y_balance(actual);// solo imprime mis datos de informacion 
    if (fact == -2 && GET_MI_FE(actual->iz) == -1) {// si es -2 fijo tengo hijo izquierdo entonces pregunto 
       // cout << "rotacion simple a la derecha :)" << endl;
        actual = rot_s_derecha(actual);
    }
    else if (fact == 2 && GET_MI_FE(actual->de) == 1) {
        //cout << "rotacion simple a la izquierda :)" << endl;
        actual = rot_s_izquierda(actual);
    }
    else if (fact == 2 && GET_MI_FE(actual->de) == -1) {
       // cout << "rotacion doble a la derecha , izquierda :)" << endl;
        /*      X fe == 2
                        X fe == -1
                    X
        */
        actual->de = rot_s_derecha(actual->de); // es como mas externa por eso se manda el derecho 
        actual = rot_s_izquierda(actual);// esta es mas directa porque el arbol ya esta asi , entonces lo que retorna ya es la nueva raiz 
        /*
                X fe == 2
                    X fe == 1
                        X
        */
    }
    else if (fact == -2 && GET_MI_FE(actual->iz) == 1) {
       // cout << "rotacion doble izquierda , derecha :)" << endl;
        /*     9 fe == -2
        2 fe == +1
              5 fe == 0 
        */
        actual->iz = rot_s_izquierda(actual->iz); // es como mas externa por eso se manda el IZquierdo
        actual = rot_s_derecha(actual);//mas directa , entonces lo que retorna ya es la nueva raiz 
         
        /*      X
            X
        X
        */
    }
   

    return actual; 

}



int ArbolBin::compararAlfabeticamente(string p1, string p2) {
    if (p1.compare(p2) == 0) {
        return 2;
    }
    else {
        string palabraOrdenada = "";
        int repeticiones = 0, p1_size, p2_size;
        p1_size = (int)p1.size();
        p2_size = (int)p2.size();
        if (p1_size > p2_size) {
            repeticiones = (int)p2.size();
            palabraOrdenada = p2;
        }
        else if (p2_size > p1_size) {
            repeticiones = (int)p1.size();
            palabraOrdenada = p1;
        }
        else { // si son iguales en longitud 
            repeticiones = (int)p1.size();
        }


        for (int i = 0; i < repeticiones; i++) {
            char letra1 = p1[i];
            char letra2 = p2[i];
            if (letra1 == letra2) {
            }
            else if (letra2 > letra1) { // palabra 1 va antes que palabra 2 
                palabraOrdenada = p1;
                return 0;
            }
            else if (letra1 > letra2) {
                palabraOrdenada = p2;
                return 1;
            }
        }
        // caso en que la similitud es muy grande y no hay mas letras para comparar , se determina por la LONGITUD 

        int logitud_raiz = (int)p1.size();
        int logitud_nuevo = (int)p2.size();
        if (logitud_raiz > logitud_nuevo) {
            return 1; // lo inserto a la izq
        }
        else {
            return 0;
        }

        return 1;// analizar este paso
    }
}


void ArbolBin::recorrido_inOrder() {
    cout << "------ LISTA DE IDS --------";
    cout << endl;
    if (this->raiz != NULL) {
        recursive_inOrder(this->raiz);
    }
    else {
        std::cout << "ARBOL VACIO" << endl;
    }
    std::cout << endl;
}

void ArbolBin::recursive_inOrder(Navl* actual) {
    if (actual->iz != NULL) {
        recursive_inOrder(actual->iz);
    }

    cout << actual->acti->id_activ << "  ";

    if (actual->de != NULL) {
        recursive_inOrder(actual->de);
    }
}



Navl* ArbolBin::getNodoMinimo(Navl* node) { //le mando un nodo que va ser recorrido para encontrar su menor
    Navl* recorredor = node;
    while (recorredor->iz != NULL) {
        recorredor = recorredor->iz;
    }
    Navl* Nodo_Mas_a_la_izquierda = recorredor;


    return Nodo_Mas_a_la_izquierda;

}

void ArbolBin::eliminar(string id) {
    this->raiz = eliminarRecursivo(this->raiz, id);
    Estatica::CONTROL_IDS->eliminarRecursivo(CONTROL_IDS->getRoot(), id);
}




Navl* ArbolBin::eliminarRecursivo(Navl* raiz, string id) {
    if (raiz == NULL) { // la llave para salir de la recursividad es que mi raiz sea NULL 
        return raiz;
    }

    int res = this->compararAlfabeticamente(raiz->acti->id_activ, id);

    switch (res) {
    case 1:// 1 lo uso para saber si id1 es mayor a id2
        raiz->iz = this->eliminarRecursivo(raiz->iz, id);
        break;
    case 0: // 0 para saber si id1 es menor a id2 (segundo parametro)
        raiz->de = this->eliminarRecursivo(raiz->de, id);
        break;
    default:
        // AQUI ES YA ASEGURO HABER ENCONTRADO EL NODO CON EL MISMO ID
        if ((raiz->iz == NULL) || (raiz->de == NULL)) { // si uno de los dos de sus punteros es null entonces se puede reemplazar 
            Navl* revisar = NULL;

            if (revisar == raiz->iz) revisar = raiz->de;
            else  revisar = raiz->iz;

            if (revisar == NULL) raiz = NULL;// HoJa , solo la borrar directo 
            else raiz = revisar;//reemplaza 
            
          //  cout << "Activo eliminado :D" << endl;// si llega aca se que se va eliminar  
        }
        else {
            Navl* DATOS_MENOR = this->getNodoMinimo(raiz->de); // menor de lOs mayores 
            raiz->acti->setTodoEl_objeto(DATOS_MENOR->acti->id_activ, DATOS_MENOR->acti->nombre, DATOS_MENOR->acti->descripcion , DATOS_MENOR->acti->dispo);// reemplazo el objeto o llave depende de que necesite  porque esta subiendo el MENOR DE LOS MAYORES 
            raiz->de = eliminarRecursivo(raiz->de, DATOS_MENOR->acti->id_activ);// le mando la parte derecha porque ahora en mi arbol hay simultaneamente dos nodos con el mimso Identificador y mando a eliminar el menor de los mayores que es una simple HOJA
        }
        break;
    }


    if (raiz == NULL) return raiz;// cuando se elimina la hoja puede dar null pointer si baja por eso se retorna de una vez 

    int fact = GET_MI_FE(raiz);

    if (fact == -2 && GET_MI_FE(raiz->iz) == -1) {// si es -2 fijo tengo hijo izquierdo entonces pregunto 
       // cout << "rotacion simple a la derecha :)" << endl;
        raiz = rot_s_derecha(raiz);
    }
    else if (fact == 2 && GET_MI_FE(raiz->de) == 1) {
      //  cout << "rotacion simple a la izquierda :)" << endl;
        raiz = rot_s_izquierda(raiz);
    }
    else if (fact == 2 && GET_MI_FE(raiz->de) == -1) {
      //  cout << "rotacion doble a la derecha , izquierda :)" << endl;
        /*      X fe == 2
                        X fe == -1
                    X
        */
        raiz->de = rot_s_derecha(raiz->de); // es como mas externa por eso se manda el derecho 
        raiz = rot_s_izquierda(raiz);// esta es mas directa porque el arbol ya esta asi , entonces lo que retorna ya es la nueva raiz 
        /*
                X fe == 2
                    X fe == 1
                        X
        */
    }
    else if (fact == -2 && GET_MI_FE(raiz->iz) == 1) {
       // cout << "rotacion doble izquierda , derecha :)" << endl;
        /*     9 fe == -2
        2 fe == +1
              5 fe == 0
        */
        raiz->iz = rot_s_izquierda(raiz->iz); // es como mas externa por eso se manda el IZquierdo
        raiz = rot_s_derecha(raiz);//mas directa , entonces lo que retorna ya es la nueva raiz 

        /*      X
            X
        X
        */
    }


    return raiz; // retorna las raices temporales que no estan vacias para no perder el arbol 
}




void  ArbolBin::getGraphviz() {
    if (this->getRoot() != NULL) {
        this->Graph = "";
        this->Graph += "digraph ARBOL_201800464 { rankdir=TB;\n label = \" ARBOL AVL \"charset = latin1; style = filled;bgcolor = white;color = lightgrey; \n ";
        this->Graph += "node[fillcolor = black , fontcolor = white , color = chartreuse1 ,style = filled,  shape = record];\n";
        getGraphviz(this->raiz);
        Rep* llama = new Rep(); 
        llama->graficaArbol(Graph);
    }
    else {
        cout << "arbol vacio :( " << endl; 
    }

    
}
string ArbolBin:: getGraphvizRepUsuarios(string nombreUsuario , int ind) {

    if (this->getRoot() != NULL) {
        this->Graph = "";
        this->Graph += "subgraph cluster_"+to_string(ind)+" { rankdir=TB;\n label = \"Usuario: "+ nombreUsuario +" \"charset = latin1; style = filled;bgcolor = white;color = lightgrey; \n ";
        this->Graph += "node[fillcolor = black , fontcolor = white , color = chartreuse1 ,style = filled,  shape = record];\n";
        getGraphviz(this->raiz);
        this->Graph += "}";
        return Graph;
    }
    else {
        cout << "arbol vacio :( " << endl;
        return "";
    }
}


void ArbolBin::getGraphviz(Navl* R_actual) {
    if (R_actual->acti->dispo) {
     this->Graph += "" + R_actual->acti->id_activ + "[label = \" <C0>|" + "ID:  " + R_actual->acti->id_activ + "\\nNombre:  " + R_actual->acti->nombre + "|<C1>" + "\" ];   \n ";
    }
    else {
        this->Graph += "" + R_actual->acti->id_activ + "[label = \" <C0>|" + "ID:  " + R_actual->acti->id_activ + "\\nNombre:  " + R_actual->acti->nombre + "|<C1>" + "\" , color = red];   \n ";
    }
    
    if (R_actual->iz != NULL) {
        this->Graph += R_actual->acti->id_activ + ":C0->" + R_actual->iz->acti->id_activ + " [arrowhead = none color = black];   \n ";
        getGraphviz(R_actual->iz);
    }

    if (R_actual->de != NULL) {
        this->Graph += R_actual->acti->id_activ + ":C1->" + R_actual->de->acti->id_activ + " [arrowhead = none color = black];   \n ";
        getGraphviz(R_actual->de);
    }
}


Navl* ArbolBin:: buscar(string id) {
    if (this->raiz == NULL) {
        cout << "arbol vacio :)" << endl; 
    }
    else {
        return buscarRecursivo(this->raiz , id);
    }
}
Navl* ArbolBin :: buscarRecursivo(Navl* actual, string id) {

    if (actual == NULL) return actual;

    if (this->compararAlfabeticamente(actual->acti->id_activ , id) == 2) return actual; // lo encuentra 

    if (this->compararAlfabeticamente(actual->acti->id_activ , id ) == 1) return buscarRecursivo(actual->iz, id);

    if (this->compararAlfabeticamente(actual->acti->id_activ, id) == 0) return buscarRecursivo(actual->de, id);
}




string ArbolBin::generarId() {
    Sleep(850);
    string id_alfa = "";
    srand(time(NULL));
    int aleatorio = 0;
    for (int x = 0; x < 15; x++) {
        aleatorio = rand() % rand() % (25 - 0 + 1) + 0;

        if (x == 0 || x == 14) {
            id_alfa += getLetra(aleatorio);
        }
        else if (aleatorio >= 10) {
            id_alfa += getLetra(aleatorio);
        }
        else {
            id_alfa += std::to_string(aleatorio);
        }
    }
    return id_alfa;
}

bool ArbolBin::yaExisteEl_id(string id_alfanumerico) {
    if (this->getRoot() == NULL) {
        return false;
    }
    Navl* aux_ = this->buscar(id_alfanumerico);
    if (aux_ != NULL) {
        return true; 
    }
    return false;
}


string ArbolBin::getLetra(int n) {
    string letra = "";
    if (n == 10) {
        letra = "a";
    }
    else if (n == 11) {
        letra = "x";
    }
    else if (n == 12) {
        letra = "z";
    }
    else if (n == 13) {
        letra = "b";
    }
    else if (n == 14) {
        letra = "y";
    }
    else if (n == 15) {
        letra = "d";
    }
    else if (n == 16)
    {
        letra = "e";
    }
    else if (n == 17) {
        letra = "w";
    }
    else if (n == 18) {
        letra = "i";
    }
    else if (n == 19) {
        letra = "u";
    }
    else if (n == 20) {
        letra = "j";

    }
    else if (n == 21) {
        letra = "r";
    }
    else if (n == 22) {
        letra = "t";
    }
    else if (n == 23) {
        letra = "q";
    }
    else if (n == 23) {
        letra = "o";
    }
    else if (n == 24) {
        letra = "s";
    }
    else {
        letra = "v";
    }


    return letra;
}








/*
                                 IMPLEMENTACION PARA EL AVL 

*/




int ArbolBin :: GET_MI_FE(Navl* padre) { // si es -  mi desequilibrio esta a la izquierda si es + mi desequilibrio esta a la derecha 
    if (padre == NULL) return 0;
    else return ( GET_Al(padre->de) - GET_Al(padre->iz) ); // me baso en derecha menos izquierda 
}

int ArbolBin::GET_Al(Navl* hijo) {
    if (hijo != NULL) return hijo->al;
    else  return 0;
   
}

void ArbolBin::dame_la_altura_y_balance(Navl* nodoPrueba) {
    if (nodoPrueba != NULL)     cout << "ID: " << nodoPrueba->acti->id_activ << endl;
    else cout << "nodo NULL" << endl;
    

    cout << "altura :" << GET_Al(nodoPrueba) << endl;
    cout << " FE: " << GET_MI_FE(nodoPrueba) << endl; 
}



Navl* ArbolBin:: rot_s_derecha(Navl* pivote_menos_2) { // OJO SIEMPRE VA TENER HIJO IZQUIERDO 
    Navl* antes_hijo_izquierdo = pivote_menos_2->iz;
    pivote_menos_2->iz = antes_hijo_izquierdo->de; // lo derecho de mi hijo anterior izz
    antes_hijo_izquierdo->de = pivote_menos_2; // el pivote menos 2 deja de SER LA RAIZ Y AHORA LO ES EL HIJO IZQUIEDO
   
  
    // actualiza las  alturas de mi pivote y del que antes era su hijo izquierdo  
    pivote_menos_2->set_Mayor_Altura(  GET_Al(pivote_menos_2->de), GET_Al(pivote_menos_2->iz)  );// indiferente el orden en que mande las alturas igual  le asigna el mayor
    antes_hijo_izquierdo->set_Mayor_Altura(GET_Al(antes_hijo_izquierdo->de), GET_Al(antes_hijo_izquierdo->iz));
    /*
    dame_la_altura_y_balance(pivote_menos_2);
    dame_la_altura_y_balance(antes_hijo_izquierdo);
    */
    
    return antes_hijo_izquierdo; // retorno la nueva root 
}



Navl* ArbolBin::rot_s_izquierda(Navl* pivote_menos_2) {// siempre tendre hijo derecho :D
    Navl* antes_hijo_derecho = pivote_menos_2->de; 
    pivote_menos_2->de = antes_hijo_derecho->iz;
    antes_hijo_derecho->iz = pivote_menos_2; // pivote deja de ser root porque ahora sube el hijo derecho 
   
    pivote_menos_2->set_Mayor_Altura(GET_Al(pivote_menos_2->de), GET_Al(pivote_menos_2->iz));// indiferente el orden en que mande las alturas igual  le asigna el mayor
    antes_hijo_derecho->set_Mayor_Altura(GET_Al(antes_hijo_derecho->de), GET_Al(antes_hijo_derecho->iz));

  /*  dame_la_altura_y_balance(pivote_menos_2);
    dame_la_altura_y_balance(antes_hijo_derecho);*/
    return antes_hijo_derecho;
}











/*
                         PARA LA LOGICA 

*/

void ArbolBin::mostrar_activos() {
    cout << "********************* LISTADO DE ACTIVOS ******************************" << endl;
    if (this->getRoot() == NULL ) {
        cout << "POR EL MOMENTO NO HAY ACTIVOS" << endl; 
    }
    else {
        mostrar_activos(this->raiz);
    } 
    cout << endl; 
    cout << "***********************************************************************" << endl;
}
void ArbolBin ::  mostrar_activos(Navl* actual) {
    if (actual->iz != NULL) {
        mostrar_activos(actual->iz);
    }
    if (actual->acti->dispo) {
        cout << "ID: " << actual->acti->id_activ << "  NOMBRE: " << actual->acti->nombre << " Descripcion: " << actual->acti->descripcion << endl;
    }
   
    if (actual->de != NULL) {
        mostrar_activos(actual->de);
    }
}



CatalogoLsimple* ArbolBin:: recolectaPro(CatalogoLsimple* CATALOGO, string nombreUser, string empresa, string departamento) {
    if (this->raiz != NULL) {
        CATALOGO = recolectaProRecursivo(this->raiz, CATALOGO,  nombreUser,  empresa,  departamento);
    }
    return CATALOGO;
}

CatalogoLsimple* ArbolBin :: recolectaProRecursivo(Navl* actual, CatalogoLsimple* CATALOGO, string nombreUser, string empresa, string departamento) {
    if (actual->iz != NULL) {
       CATALOGO = recolectaProRecursivo(actual->iz, CATALOGO, nombreUser, empresa, departamento);
    }

    if (actual->acti->dispo == true) {
        CATALOGO->agregaProducto(nombreUser, empresa, departamento, actual->acti->id_activ, actual->acti->nombre, actual->acti->descripcion);
    }
  
    if (actual->de != NULL) {
        CATALOGO = recolectaProRecursivo(actual->de, CATALOGO, nombreUser, empresa, departamento);
    }
    return CATALOGO; 
}