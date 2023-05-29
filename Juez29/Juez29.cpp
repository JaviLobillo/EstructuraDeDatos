
// Javier Lobillo Olmedo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "hashmap_eda.h"  // propios o los de las estructuras de datos de clase

using natural = unsigned int;
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    natural numeroTotalCapitulos;
    std::cin >> numeroTotalCapitulos;

    natural capituloActual, primero = 0, longitudMaxima = 0;
   
    unordered_map<natural, natural> miTablita; //capitulos y última vez que salieron
    
    for (int i = 0; i < numeroTotalCapitulos; i++) {
        std::cin >> capituloActual;

        if (miTablita.count(capituloActual) && miTablita[capituloActual] >= primero)
            primero = miTablita[capituloActual] + 1;

        miTablita[capituloActual] = i;
        longitudMaxima = std::max(longitudMaxima, i - primero + 1);
    }

    std::cout << longitudMaxima << "\n";


}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int n;
   std::cin >> n;
   for(int i = 0; i < n; i++)
       resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
