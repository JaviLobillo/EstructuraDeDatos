
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <list>

#include "carnet_puntos2.h"  // propios o los de las estructuras de datos de clase

// O(N) donde N es el numero de entradas


bool resuelveCaso() {
    std::string operacion, dni;
    int puntos, resultado;
    carnet_puntos miTabla;

    std::cin >> operacion;
       
    if (!std::cin)  // fin de la entrada
        return false;

    while (operacion != "FIN") {
        if (operacion == "nuevo") {
            std::cin >> dni;
            try {
                miTabla.nuevo(dni);
            }
            catch (const std::domain_error& e) {
                std::cout << "ERROR: " << e.what() << "\n";
            }

        }
        else if (operacion == "quitar") {
            std::cin >> dni >> puntos;
            try {
                miTabla.quitar(dni, puntos);
            }
            catch (const std::domain_error& e) {
                std::cout << "ERROR: " << e.what() << "\n";
            }
        }
        else if (operacion == "consultar") {
            std::cin >> dni;
            try {
                resultado = miTabla.consultar(dni);
                std::cout << "Puntos de " << dni << ": " << resultado << "\n";
            }
            catch (const std::domain_error& e) {
                std::cout << "ERROR: " << e.what() << "\n";
            }
        }
        else if (operacion == "cuantos_con_puntos") {
            std::cin >> puntos;
            try {
                resultado = miTabla.cuantos_con_puntos(puntos);
                std::cout << "Con " << puntos << " puntos hay " << resultado << "\n";
            }
            catch (const std::domain_error& e) {
                std::cout << "ERROR: " << e.what() << "\n";
            }
        }
        else if (operacion == "recuperar") {
            std::cin >> dni >> puntos;
            try {
                miTabla.recuperar(dni, puntos);
            }
            catch (const std::domain_error& e) {
                std::cout << "ERROR: " << e.what() << "\n";
            }
        }
        else if (operacion == "lista_por_puntos") {
            std::cin >> puntos;
            try {
                std::list<std::string> miLista = miTabla.lista_por_puntos(puntos);
                std::cout << "Tienen " << puntos << " puntos:";
                for (auto const & d : miLista) {
                    std::cout << " " << d;
                }
                std::cout << "\n";
            }
            catch (const std::domain_error& e) {
                std::cout << "ERROR: " << e.what() << "\n";
            }
        }
        std::cin.ignore();
        std::cin >> operacion;
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
