
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <queue>

#include "bintree_eda.h"

struct info {
    bool completo;
    bool semicompleto;
    int altura = 0;
};

info queEs(bintree<char> const & arbol) {
    if (arbol.empty()) {
        return { true, true, 0 };
    }

    info ret;
    auto izq = queEs(arbol.left());
    auto der = queEs(arbol.right());

    ret.completo = izq.completo && der.completo && izq.altura == der.altura;

    ret.semicompleto = ret.completo
        || izq.semicompleto && der.completo && izq.altura == der.altura + 1
        || izq.completo && der.semicompleto && izq.altura == der.altura;

    ret.altura = izq.altura + 1;

    return ret;
}

void resuelveCaso() {
    auto arbol = leerArbol('.');
    int ret = 0; //0 completo, 1 semicompleto y 2 nada
    
    info sol = queEs(arbol);

    if (sol.completo) std::cout << "COMPLETO\n";
    else if (sol.semicompleto) std::cout << "SEMICOMPLETO\n";
    else std::cout << "NADA\n";
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
