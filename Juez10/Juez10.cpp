
//Javier Lobillo Olmedo

#include <iostream>
#include <fstream>


#include "queue10.h"  // propios o los de las estructuras de datos de clase


bool resuelveCaso() {
   
    int N, num, M, P;
    queue10<int> lista1, lista2;
   
    std::cin >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    //leo lista1
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        lista1.push(num);
    }

    //leo lista2
    std::cin >> M >> P;
    for (int j = 0; j < M; j++) {
        std::cin >> num;
        lista2.push(num);
    }
    
    //resuelvo
    lista1.insertar(P, lista2);

    lista1.print();

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
