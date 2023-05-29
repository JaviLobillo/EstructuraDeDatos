
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <algorithm>

#include "bintree_eda.h"

std::pair<int, int> caminoPar(bintree<int> arbol) { // max, actual
    if (arbol.empty())
        return { 0, 0 };

    if (arbol.left().empty() && arbol.right().empty()) {
        if (arbol.root() % 2 == 0) //par
            return { 1, 1 };
        else return { 0, 0 }; //impar
    }

    std::pair<int, int> ret;

    if (!arbol.left().empty() && arbol.right().empty()) {
        auto izq = caminoPar(arbol.left());

        if (arbol.root() % 2 == 0) {  //par
            ret.second = izq.second + 1;
            ret.first = std::max(izq.first, ret.second);
        }
        else {  //impar
            ret.first = izq.first;
            ret.second = 0;
        }
    }

    else if (arbol.left().empty() && !arbol.right().empty()) {
        auto der = caminoPar(arbol.right());

        if (arbol.root() % 2 == 0) {  //par
            ret.second = der.second + 1;
            ret.first = std::max(der.first, ret.second);
        }
        else {  //impar
            ret.first = der.first;
            ret.second = 0;
        }
    }
    else if (!arbol.left().empty() && !arbol.right().empty()) {
        auto izq = caminoPar(arbol.left());
        auto der = caminoPar(arbol.right());

        if (arbol.root() % 2 == 0) { //par
            ret.second = std::max(izq.second, der.second) + 1;
            ret.first = std::max(std::max(ret.second, izq.second + der.second + 1), std::max(izq.first, der.first));
        }
        else { //impar
            ret.first = std::max(izq.first, der.first);
            ret.second = 0;
        }
    }

    return ret;
}

void resuelveCaso() {
    auto arbol = leerArbol(-1);
    auto sol = caminoPar(arbol);
    std::cout << sol.first << '\n';
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
