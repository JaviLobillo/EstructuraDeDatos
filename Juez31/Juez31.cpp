
//Javier Lobillo Olmedo

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


#include "treemap_eda.h" 


bool resuelveCaso() {
    int N;
    map<std::string, std::vector<int>> miDiccionario;
    std::string linea, clave;

    std::cin >> N;

    if (N == 0)
        return false;

    std::cin.ignore();

    for (int i = 1; i <= N; i++) {
        getline(std::cin, linea);
        std::stringstream ss(linea);

        while (ss >> clave) {
            if (clave.length() > 2) {
                for (char & c : clave)
                    c = tolower(c);

                std::vector<int> & apariciones = miDiccionario[clave];

                if (apariciones.empty() || apariciones.back() != i)
                    apariciones.push_back(i);

            }

        }
    }

   
    for (auto par : miDiccionario) {
        std::cout << par.clave;
        for (auto val : par.valor)
            std::cout << " " << val;

        std::cout << "\n";
        
    }

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
