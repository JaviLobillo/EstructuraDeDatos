
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>

#include "queue_eda.h"
#include "deque_eda.h"


//O(n^2) ya que el coste es c(k)=(n-k+1)(k) que alcanza su máximo en 
//k=(n+1)/2, siendo c = ((n+1)/2)^2 -> orden es O(n^2)

int masGrande(queue<int> miCola) {
    int max = 0, tam = miCola.size();
    for (int i = 0; i < tam; i++) {
        max = miCola.front() > max ? miCola.front() : max;
        miCola.pop();
    }

    return max;
}

bool resuelveCaso() {
    int n, k, num, max;
    queue<int> miCola;
    deque<int> maximos;
    
    std::cin >> n >> k;

    if (n == 0 && k == 0)
        return false;

    for (int i = 0; i < n; i++) {
        std::cin >> num;
        miCola.push(num);
        if (miCola.size() == k) {
            max = masGrande(miCola);
            std::cout << max << " ";
            miCola.pop();
        }
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
