
//Javier Lobillo


#include <iostream>
#include <fstream>


#include "complejo.h" // propios o los de las estructuras de datos de clase


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    float a, b;
    int n;
    std::cin >> a >> b >> n;
   
    complejo<float> c(a, b);
    complejo<float> z_n_1(0, 0);
    complejo<float> z_n(0, 0);

    for (int i = 0; i < n && z_n.mod() <= 2; i++) {
        z_n = (z_n_1 * z_n_1) + c;
        z_n_1 = z_n;
    }
    
    if (z_n.mod() > 2)
        std::cout << "NO\n";
    else std::cout << "SI\n";

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
