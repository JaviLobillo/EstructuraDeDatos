
// Javier Lobillo Olmedo (DG19)

// PROBLEMA A

/*
El orden de la solucion es lineal en el numero de nodos del arbol.
Esto es debido a que se recorren de forma recursiva todos los nodos del arbol una sola
vez en el caso peor en que todos sean zurdos o, en caso de lo que hace que un arbol no sea
zurdo se encuentre en el último nivel.
Además, los árboles se podan por los nodos que tengan hijo derecho y no izquierdo, evitando
recorrer ese hijo derecho innecesariamente, devolviendo false directamente.

Además, he utilizado un par de bool e int, en el que bool significa si es o no zurdo, 
y el int es el numero de nodos que se encuentran por debajo de uno dado, más ese
mismo nodo.
*/


#include <iostream>               
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


// Implementa aquí la función pedida. Puedes definir las funciones
// auxiliares que necesites
using info = std::pair<bool, int>;  // si es zurdo o no, y el
                                    //numero de nodos que hay por debajo del arbol en cuestion

info zurdo(bintree<char> arbol) {
    if (arbol.empty()) // caso vacío
        return { true, 0 }; //es zurdo y no tiene nodos

    if (arbol.left().empty() && arbol.right().empty()) // arbol hoja
        return { true, 1 }; //es zurdo con un nodo

    if (arbol.left().empty() && !arbol.right().empty()) // si tiene hijo derecho, pero no izquierdo
        return { false, 0 }; //no es zurdo, por lo que no importan el numero de descendientes

    if (!arbol.left().empty() && arbol.right().empty()) { // si tiene hijo izquierdo, pero no derecho
        info izq = zurdo(arbol.left());
        info ret;
        //es zurdo si su hijo izquierdo lo es
        ret.first = izq.first;
        //el numero de nodos es el de hijos por la izquierda, más el actual
        ret.second = izq.second + 1;

        return ret;
    }

    if (!arbol.left().empty() && !arbol.right().empty()) { // si tiene hijo izquierdo y derecho
        info izq = zurdo(arbol.left());
        info der = zurdo(arbol.right());
        info ret;

        //se comprueba si ambos hijos son zurdos, ademas de si mas de la mitad de sus
        //descendientes se encuentran en su hijo izquierdo, o lo que es lo mismo,
        //si el numero de nodos a partir de su hijo izquierdo es mayor que a partir del
        //derecho
        ret.first = izq.first && der.first && izq.second > der.second;
        //se suman los hijos izquierdos y los derechos, además del actual
        ret.second = izq.second + der.second + 1;  
        return ret;
    }
}


void resuelveCaso() {
   auto arbol = leerArbol('.');
   info sol = zurdo(arbol);
   if (sol.first)
      cout << "SI\n";
   else
      cout << "NO\n";
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   
   for (int i = 0; i < numCasos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   // system("PAUSE");
#endif
   return 0;
}
