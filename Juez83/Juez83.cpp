
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <algorithm>

#include "bintree_eda.h"

using info = std::pair<int, int>; //altura, max

info esCompleto(bintree<char> arbol) {
    if (arbol.empty()) {
        return { 0, 0 };
    }
    info ret, izq, der;

    if (arbol.left().empty() && arbol.right().empty()) {
        return { 1, 1 };
    }
    else if (!arbol.left().empty() && arbol.right().empty()) {
        izq = esCompleto(arbol.left());
        ret.first = 1;
        ret.second = izq.second;
    }
    else if (arbol.left().empty() && !arbol.right().empty()) {
        der = esCompleto(arbol.right());
        ret.first = 1;
        ret.second = der.second;
    }

    else if (!arbol.left().empty() && !arbol.right().empty()) {
        izq = esCompleto(arbol.left());
        der = esCompleto(arbol.right());
        ret.first = std::min(izq.first, der.first) + 1;
        ret.second = std::max(std::max(izq.second, der.second), ret.first);
    }

    return ret;

}

void resuelveCaso() {
    auto arbol = leerArbol('.');

    info res = esCompleto(arbol);

    std::cout << res.second << '\n';

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
