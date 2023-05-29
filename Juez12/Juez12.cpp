
// Javier Lobillo Olmedo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>


#include "queue12.h" 


bool resuelveCaso() {
   
    int N, c;
    std::cin >> N >> c;
    queue12<int> miListaDeAfortunados;
   
    if (N == 0)
        return false;
    
    for (int i = 0; i < N; i++)
        miListaDeAfortunados.push(i);

    std::cout << miListaDeAfortunados.afortunado(c)+1 << "\n";

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
