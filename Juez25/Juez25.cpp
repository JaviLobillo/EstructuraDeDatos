
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <math.h>

#include "bintree_eda.h"


bool esPrimo(int n) { //O(1). Como mucho hará 70 operaciones, ya que n < 5000 y sqrt(5000) < 71.

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;    
}

std::pair<int, int> multiploAccesible(bintree<int> const & miArbol) {
    std::pair<int, int> resultado = { 0, 0 }, resIzq, resDer;
    
    if(!(miArbol.empty() || esPrimo(miArbol.root()))) {
        if (miArbol.root() % 7 == 0) {
            resultado.first = miArbol.root();
            resultado.second = 1;
        }
        else {
            resIzq = multiploAccesible(miArbol.left());
            resDer = multiploAccesible(miArbol.right());

            if (resIzq.second != 0 && resDer.second != 0) {
                resultado = resIzq.second <= resDer.second ? resIzq : resDer;
                resultado.second++;
            }
            else if (resIzq.second != 0) {
                resultado = resIzq;
                resultado.second++;
            }
            else if (resDer.second != 0) {
                resultado = resDer;
                resultado.second++;
            }
        }
    }
    return resultado;
}

void resuelveCaso() {
    auto miArbol = leerArbol(-1);
    std::pair<int, int> resultado = multiploAccesible(miArbol); //múltiplo, altura

    if (resultado.first != 0)
        std::cout << resultado.first << " " << resultado.second;
    else
        std::cout << "NO HAY";
    std::cout << "\n";

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
