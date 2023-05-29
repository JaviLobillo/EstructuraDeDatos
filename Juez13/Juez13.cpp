
// Javier Lobillo Olmedo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "queue_eda.h"
#include "stack_eda.h"

/*Vemos que N = nS + pS, donde N es el numero total de elementos int de la cola, nS es el numero de elementos negativos y pS es el numero de
elementos positivos. Por tanto, el coste es igual a N + nS + pS = N + N, por lo que O(N + N) = O(N)
*/

bool resuelveCaso() {
    int N, num, nS, pS;
    stack<int> negativos;
    queue<int> positivos;

    std::cin >> N;
    if (N == 0)
        return false;
   
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        if (num >= 0)
            positivos.push(num);
        else negativos.push(num);
    }

    nS = negativos.size();
    for (int j = 0; j < nS; j++) {
        num = negativos.top();
        std::cout << num << " ";
        negativos.pop();
    }

    pS = positivos.size();
    for (int k = 0; k < pS; k++) {
        num = positivos.front();
        std::cout << num << " ";
        positivos.pop();
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
