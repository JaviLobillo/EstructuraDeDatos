
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <string>

#include "persona.h"
#include "list16.h"


bool resuelveCaso() {
    int n, min, max, edad;
    std::string nombre;
    persona nueva;
    list16<persona> miLista;

    std::cin >> n >> min >> max;

    if (n == 0 && min == 0 && max == 0)
        return false;

    for (int i = 0; i < n; i++) {
        std::cin >> nueva;
        miLista.push_back(nueva);
    }

    miLista.remove_if([min, max](persona p) {
        return min > p.get_edad() || max < p.get_edad();
        });
     
    miLista.write();
   
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
