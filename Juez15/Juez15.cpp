
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>

#include "queue_eda.h"
#include "deque_eda.h"

//O(f(n)) = O(N) ya que por cada uno de ls n sobres, solo se aplican
//operaciones constantes

bool resuelveCaso() {
    int n, k, num, max;
    queue<int> miCola;
    deque<int> maximos;
   
    std::cin >> n >> k;
    if (n == 0 && k == 0)
        return false;

    //primer grupo
    std::cin >> num;
    miCola.push(num);
    maximos.push_back(num);
    for (int i = 1; i < k; i++) {
        std::cin >> num;
        miCola.push(num);
        //actualizar maximos
        while (!maximos.empty() && num > maximos.back())
            maximos.pop_back();
        maximos.push_back(num);
    }
    std::cout << maximos.front() << " ";
    n -= k;

    //siguientes grupos
    while (n) {
        std::cin >> num;
        if (miCola.front() == maximos.front())
            maximos.pop_front();
        //actualizar máximos
        while (!maximos.empty() && num > maximos.back())
            maximos.pop_back();
        maximos.push_back(num);

        std::cout << maximos.front() << " ";

        miCola.pop();
        miCola.push(num);

        --n;
    }
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
