
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <queue>

#include "bintree_eda.h"

bool esSimetrico(bintree<char> izq, bintree<char> der) {
    if (izq.empty() && der.empty())
        return true;

    if ((izq.empty() && !der.empty()) || (!izq.empty() && der.empty()))
        return false;

    return esSimetrico(izq.left(), der.right()) && esSimetrico(izq.right(), der.left());

}

void resuelveCaso() {
    auto miArbol = leerArbol('.');

    bool loEs = esSimetrico(miArbol.left(), miArbol.right());

    if (loEs)
        std::cout << "SI" << '\n';
    else std::cout << "NO" << '\n';
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
