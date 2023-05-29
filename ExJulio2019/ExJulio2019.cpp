
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>

#include "bintree_eda.h"

std::pair<int, int> numNodosSumativos(bintree<int> const &arbol) { //num, suma
    if (arbol.empty())
        return { 0, 0 };
    std::pair<int, int> ret;

    if (arbol.left().empty() && arbol.right().empty()) {
        ret.first = 0;
        ret.second = arbol.root();
    }
    else if (!arbol.left().empty() && arbol.right().empty()) {
        auto izq = numNodosSumativos(arbol.left());
        ret.first = izq.first;
        if (arbol.root() == izq.second)
            ret.first++;
        ret.second = arbol.root() + izq.second;
    }
    else if (arbol.left().empty() && !arbol.right().empty()) {
        auto der = numNodosSumativos(arbol.right());
        ret.first = der.first;
        if (arbol.root() == der.second)
            ret.first++;
        ret.second = arbol.root() + der.second;
    }
    else if (!arbol.left().empty() && !arbol.right().empty()) {
        auto izq = numNodosSumativos(arbol.left());
        auto der = numNodosSumativos(arbol.right());
        
        ret.first = izq.first + der.first;
        if(arbol.root() == izq.second + der.second)
            ret.first++;

        ret.second = arbol.root() + izq.second + der.second;
    }

    return ret;
}

bool resuelveCaso() {
    auto arbol = leerArbol(-1);

    if (arbol.empty())  // fin de la entrada
        return false;

    auto res = numNodosSumativos(arbol);
    std::cout << res.first << '\n';

    return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
