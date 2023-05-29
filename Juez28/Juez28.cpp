
// Javier Lobillo Olmedo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>


#include "treemap_eda.h"  // propios o los de las estructuras de datos de clase



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    
   
    int num;
    std::cin >> num;

    std::string basura;
    std::getline(std::cin, basura);

    if (num == 0)  // fin de la entrada
        return false;

    map<std::string, int> miTablita;

    for (int i = 0; i < num; i++) {
        std::string nombre, resultado;

        std::getline(std::cin, nombre);
        std::getline(std::cin, resultado);

        int nota = resultado == "CORRECTO" ? 1 : -1;

        miTablita[nombre] += nota;


    }
    
    for (auto const & alumno : miTablita)
        if (alumno.valor != 0)
            std::cout << alumno.clave << ", " << alumno.valor << "\n";

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
