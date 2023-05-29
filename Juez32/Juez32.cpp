
// Javier Lobillo



#include <iostream>
#include <fstream>
#include <vector>


#include "hashmap_eda.h"  // propios o los de las estructuras de datos de clase
#include "set_eda.h"

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string deporte, alumno;
    std::cin >> deporte;
    if (!std::cin)  
        return false;
   
    unordered_map<std::string, set<std::string>> deportes;
    unordered_map<std::string, std::string> alumnos;

    deportes.insert({deporte, {} });

    while (std::cin >> alumno && alumno != "_FIN_") {
        if (isupper(alumno[0])) {
            deporte = alumno;
            deportes.insert({ deporte, {} });
        }
        else {

            auto nuevo = alumnos.insert({ alumno, deporte });
            auto it = alumnos[alumno];

            if (nuevo)
                deportes[deporte].insert(alumno);
            else
                if (it != deporte)
                    deportes[it].erase(alumno);
        }
    }
    
    std::vector<std::pair<std::string, int>> resumen;
    for (auto const& aux : deportes)
        resumen.push_back({ aux.clave, aux.valor.size() });

    sort(resumen.begin(), resumen.end(),
        [](std::pair<std::string, int> const& a, std::pair<std::string, int> const& b) {
            return (a.second > b.second) ||
                (a.second == b.second && a.first < b.first);
        }
        );

    for (auto& par : resumen)
        std::cout << par.first << " " << par.second << "\n";
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
