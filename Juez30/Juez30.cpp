
// Javier Lobillo Olmedo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


#include "hashmap_eda.h"  // propios o los de las estructuras de datos de clase


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   
    unordered_map<std::string, int> miDiccionario;

    std::string clave, linea1, linea2;
    unsigned int valor;
    std::vector<std::string> menos, asterisco, mas;


    getline(std::cin, linea1);
    getline(std::cin, linea2);
    std::stringstream ss1(linea1);
    std::stringstream ss2(linea2);

    while (ss1 >> clave) {
        ss1 >> valor;
        miDiccionario[clave] = valor;
    }
    
    while (ss2 >> clave) {
        ss2 >> valor;
        if (!miDiccionario.count(clave))
            mas.push_back(clave);
        else {
            if (miDiccionario[clave] != valor)
                asterisco.push_back(clave);

            miDiccionario.erase(clave);
        }


    }
   
    for (auto const& cv : miDiccionario)
        menos.push_back(cv.clave);
    


    std::sort(menos.begin(), menos.end());
    std::sort(asterisco.begin(), asterisco.end());
    std::sort(mas.begin(), mas.end());

    if (menos.empty() && asterisco.empty() && mas.empty()) {
        std::cout << "Sin cambios \n";
    }
    else {
        if (!mas.empty()) {
            std::cout << "+ ";
            for (std::string s : mas)
                std::cout << s + " ";
            std::cout << "\n";
        }
        if (!menos.empty()) {
            std::cout << "- ";
            for (std::string s : menos)
                std::cout << s + " ";
            std::cout << "\n";
        }
        if (!asterisco.empty()) {
            std::cout << "* ";
            for (std::string s : asterisco)
                std::cout << s + " ";
            std::cout << "\n";
        }

    }

    std::cout << "---\n";
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   std::string basura;
   int numCasos;
   std::cin >> numCasos;
   std::getline(std::cin, basura);

   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
