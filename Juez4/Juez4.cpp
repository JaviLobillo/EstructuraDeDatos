
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>

#include "polinomio.h" 


bool resuelveCaso() {
	int c, e, N, v;
	polinomio p;
   
	std::cin >> c >> e;

	if (!std::cin)
		return false;

	while (c != 0 || e != 0) {
		p.annadirTermino(c, e);
		std::cin >> c >> e;
	}

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> v;
		std::cout << p.evaluar(v) << " ";
	}

	std::cout << "\n";

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
