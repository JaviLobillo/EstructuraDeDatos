
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>

#include "bintree_eda.h"

std::pair<int, int> tramosNavegables(bintree<int> miArbol) { // caudal, tramos
    std::pair<int, int> izq, der, ret;
    
    if (miArbol.empty() || (miArbol.left().empty() && miArbol.right().empty())) {
        return { 1, 0 };
    }

    if (!miArbol.left().empty() && miArbol.right().empty()) {
        izq = tramosNavegables(miArbol.left());
        ret.first = izq.first - miArbol.root();
        ret.second = izq.second;
    }
    else if (miArbol.left().empty() && !miArbol.right().empty()) {
        der = tramosNavegables(miArbol.right());
        ret.first = der.first - miArbol.root();
        ret.second = der.second;
    }
    else if (!miArbol.left().empty() && !miArbol.right().empty()) {
        izq = tramosNavegables(miArbol.left());
        der = tramosNavegables(miArbol.right());
        ret.first = izq.first + der.first - miArbol.root();
        ret.second = izq.second + der.second;
    }

    ret.first = ret.first >= 0 ? ret.first : 0;
    ret.second = ret.first >= 3 ? ret.second + 1 : ret.second;
    return ret;
}

void resuelveCaso() {
    auto miArbol = leerArbol(-1);

    if (miArbol.empty() || (miArbol.left().empty() && miArbol.right().empty())) {
        std::cout << 0 << '\n';
    }
    else {
        std::pair<int, int> izq = tramosNavegables(miArbol.left());
        std::pair<int, int> der = tramosNavegables(miArbol.right());

        std::cout << izq.second + der.second << '\n';
    }
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
