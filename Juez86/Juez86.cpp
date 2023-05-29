
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

#include "bintree_eda.h"


void resuelveCaso() {
    auto arbol = leerArbol(-1);
    std::vector<int> perfil;

    if (!arbol.empty()) {
        std::queue<bintree<int>> cola;
        cola.push(arbol);
        int nivel = 0, act = 1, sig = 0;

        while (!cola.empty()) {
            auto a = cola.front();
            cola.pop();
            --act;

            if (nivel == perfil.size())
                perfil.push_back(a.root());
            if (!a.left().empty()) {
                cola.push(a.left());
                ++sig;
            }
            if (!a.right().empty()) {
                cola.push(a.right());
                ++sig;
            }

            if (act == 0) {
                ++nivel;
                act = sig;
                sig = 0;
            }
        }
    }

    for (auto & n : perfil)
        std::cout << n << ' ';

    std::cout << '\n';
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
