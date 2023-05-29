
// Javier Lobillo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "bintree_eda.h"  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bintree<int>  resolver(std::vector<int> & preVector, std::vector<int> & inVector, int start, int end, int &index) {
    
    if (start > end)
        return {};
    
    int raizIndIV = 0;

    int raizPV = preVector[index++];

    for (int i = start; i <= end; i++)
        if (inVector[i] == raizPV)
            raizIndIV = i;

    auto leftPart = resolver(preVector, inVector, start, raizIndIV - 1, index);
    auto rightPart = resolver(preVector, inVector, raizIndIV + 1, end, index);

    return {leftPart, raizPV, rightPart};
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
    std::vector<int> preVector, inVector;
    std::string auxString;

    int value;
    int index = 0;

    //introducir vector en preorden
    std::getline(std::cin, auxString);
    std::stringstream ss(auxString);
    
    while (ss >> value)
        preVector.push_back(value);

    //introducir vector en inorden
    std::getline(std::cin, auxString);
    std::stringstream ss2(auxString);

    while (ss2 >> value)
        inVector.push_back(value);

   
    if (!std::cin)  // fin de la entrada
      return false;
   
    auto miArbol = resolver(preVector, inVector, 0, preVector.size() - 1, index);

    auto postVector = miArbol.postorder();
    for (int i : postVector)
        std::cout << i << " ";
    std::cout << "\n";
   
    // escribir sol
   
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
