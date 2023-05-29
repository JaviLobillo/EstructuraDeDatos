
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <algorithm>

#include "bintree_eda.h"  // propios o los de las estructuras de datos de clase

//O(N) siendo N el numero de nodos del árbol, ya que recorre cada nodo una sola vez, pasando de nodo a nodo de forma recursiva.

using mayor = int;
using menor = int;
using info = std::pair<bool, std::pair<mayor, menor>>;

info esDeBusqueda(bintree<int> const & miArbol) {
    info infoIzq;
    info infoDer;
    info ret;

    if (miArbol.empty())
        ret = { true, { 0, 0 } };

    else if (miArbol.left().empty() && miArbol.right().empty())
        ret = { true, { miArbol.root(), miArbol.root() } };

    else if (!miArbol.left().empty() && miArbol.right().empty()) {
        infoIzq = esDeBusqueda(miArbol.left());
        ret = { infoIzq.first && infoIzq.second.first < miArbol.root(),
            { std::max(infoIzq.second.first, miArbol.root()), std::min(infoIzq.second.second, miArbol.root())} 
        };
    }
    else if (miArbol.left().empty() && !miArbol.right().empty()) {
        infoDer = esDeBusqueda(miArbol.right());
        ret = { infoDer.first && infoDer.second.second > miArbol.root(),
            { std::max(infoDer.second.first, miArbol.root()), std::min(infoDer.second.second, miArbol.root())}
        };
    }
    else if (!miArbol.left().empty() && !miArbol.right().empty()) {
        infoIzq = esDeBusqueda(miArbol.left());
        infoDer = esDeBusqueda(miArbol.right());

        if (infoIzq.second.first < miArbol.root() && infoDer.second.second >  miArbol.root()) {
            ret.first = infoIzq.first && infoDer.first;
        }
        else {
            ret.first = false;
        }

        ret.second = { std::max(miArbol.root(), std::max(infoIzq.second.first, infoDer.second.first)),
                        std::min(miArbol.root(), std::min(infoIzq.second.second, infoIzq.second.second)) };
        
    }

    return ret;
    
}

void resuelveCaso() {
    auto miArbol = leerArbol(-1);

    info loEs = esDeBusqueda(miArbol);

    if (loEs.first) std::cout << "SI\n";
    else std::cout << "NO\n";
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
