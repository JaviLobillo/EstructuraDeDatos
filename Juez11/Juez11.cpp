
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <sstream>

#include "queue11.h"  


void resuelveCaso() {
    queue11<int> lista1, lista2;
    int num;

    while (std::cin >> num, num != 0)
        lista1.push(num);

    while (std::cin >> num, num != 0)
        lista2.push(num);
   
    lista1.insertar(lista2);
    lista1.print();
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
