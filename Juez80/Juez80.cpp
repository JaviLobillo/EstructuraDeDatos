
// Javier Lobillo

#include <iostream>
#include <fstream>
#include <algorithm>

#include "bintree_eda.h"

using info = std::pair<bool, int>;

info esGenealogico(bintree<int> const & miArbol) {
    if (miArbol.empty())
        return { true, 0 };

    info ret;

    if (!miArbol.left().empty() && !miArbol.right().empty()) {
        info izq = esGenealogico(miArbol.left());
        info der = esGenealogico(miArbol.right());

        ret.first = izq.first && der.first && (miArbol.root() >= miArbol.left().root() + 18) &&(miArbol.left().root() >=  miArbol.right().root() + 2);
        ret.second = std::max(izq.second, der.second) + 1;
    }
    else if (!miArbol.left().empty() && miArbol.right().empty()) {
        info izq = esGenealogico(miArbol.left());

        ret.first = izq.first && (miArbol.root() >= miArbol.left().root() + 18);
        ret.second = izq.second + 1;
    }
    else if (miArbol.left().empty() && !miArbol.right().empty()) {
        ret = { false, 0 };
    }
    else {
        ret = { true, 1 };
    }

    return ret;
}

void resuelveCaso() {
    auto miArbol = leerArbol(-1);

    info loEs = esGenealogico(miArbol);

    if (loEs.first)
        std::cout << "SI " << loEs.second << "\n";
    else std::cout << "NO" << "\n";

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
