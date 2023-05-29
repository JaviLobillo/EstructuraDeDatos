
// Javier Lobillo



#include <iostream>
#include <fstream>
#include "bintree_eda.h" 


template <typename T>
inline int resolver(bintree<T> arbol, int &max) {
    if (arbol.empty()) {
        max = 0;
        return 0;
    }
    
    else {
        int maxLeft, maxRight;
        int resolverLeft = resolver(arbol.left(), maxLeft);
        int resolverRight = resolver(arbol.right(), maxRight);

        max = arbol.root() + std::max(maxLeft, maxRight);

        if (arbol.root() && resolverLeft == 0 && resolverRight == 0) {
            return 1;
        }

        else
            return resolverLeft + resolverRight;

    }
}




void resuelveCaso() {
      
    auto miArbol = leerArbol(-1);
   
    int max = 0;
    std::cout << resolver(miArbol, max) << " ";
    std::cout << max << "\n";
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
