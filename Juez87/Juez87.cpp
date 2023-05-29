
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>

#include "set_eda87.h"

bool resuelveCaso() {
    int N, M, num, lower, upper;
    std::cin >> N >> M;

    if (!std::cin)  // fin de la entrada
        return false; 

    set<int> conjunto;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        conjunto.insert(num);
    }

    for (int i = 0; i < M; i++) {
        std::cin >> lower >> upper;
        num = conjunto.count_interval(lower, upper);
        std::cout << num << '\n';
    }
    std::cout << "---\n";

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
