
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "bintree_eda.h"

bintree<int> arbol(std::vector<int> const & preorden, int prim, int ult) {
    bool encontrado = false;
    int cambio = prim;

    if (prim > ult) {
        return {};
    }

    for (int i = prim; i <= ult && !encontrado; i++) {
        if (preorden[i] <= preorden[prim])
            cambio = i;
        else encontrado = true;
    }
    
    auto izq = arbol(preorden, prim + 1, cambio);
    auto der = arbol(preorden, cambio + 1, ult);
    int root = preorden[prim];

    return { izq, root, der };

}

bool resuelveCaso() {
    std::string linea;
    int num;
    std::vector<int> preorden;

    getline(std::cin, linea);
   
    if (!std::cin)  // fin de la entrada
        return false;

    std::stringstream ss(linea);
   
    while (ss >> num) {
        preorden.push_back(num);
    }
    
    auto miArbol = arbol(preorden, 0, preorden.size() - 1);

    std::vector<int> postorden = miArbol.postorder();

    for (int i : postorden)
        std::cout << i << " ";
    std::cout << "\n";

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
