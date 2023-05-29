
// Javier Lobillo

#include <iostream>
#include <fstream>

#include "set_eda85.h"

bool resuelveCaso() {
    int N, M, num;
    set<int> conjunto;
    std::cin >> N;

    if (N == 0)
        return false;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        conjunto.insert(num);
    }

    std::pair<bool, int> sol;
    std::cin >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> num;
        sol = conjunto.lower_bound(num);
        if (sol.first)
            std::cout << sol.second << '\n';
        else std::cout << "NO HAY\n";
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
