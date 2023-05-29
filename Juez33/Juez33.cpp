
//Javier Lobillo Olmedo

#include <iostream>
#include <fstream>


#include "hashmap_eda.h"  // propios o los de las estructuras de datos de clase

using namespace std;

struct info_problema {
    bool resuelto = false;
    int fallos = 0;
};

struct info_equipo {
    int resueltos = 0;
    int tiempo = 0;
    unordered_map<std::string, info_problema> problemas;
};

struct resultado {
    string nombre;
    int num_prob_res;
    int tiempo;

    bool operator<(resultado const& r) const {
        return num_prob_res > r.num_prob_res ||
            (num_prob_res == r.num_prob_res && tiempo < r.tiempo) ||
            (num_prob_res == r.num_prob_res && tiempo == r.tiempo && nombre < r.nombre);
    }
};

void resuelveCaso() {
    
    string equipo, problema, result;
    int tiempo;
    unordered_map<string, info_equipo> equipos;

    while (cin >> equipo, equipo != "FIN") {
        cin >> problema >> tiempo >> result;

        auto& inf_eq = equipos[equipo];
        auto& inf_pr = inf_eq.problemas[problema];
        if (!inf_pr.resuelto) {
            if (result == "AC") {
                inf_pr.resuelto = true;
                ++inf_eq.resueltos;
                inf_eq.tiempo += tiempo + inf_pr.fallos * 20;
            }
            else
                ++inf_pr.fallos;
        }
    }
    
    vector<resultado> resultados;
    for (auto const& eq : equipos)
        resultados.push_back({ eq.clave, eq.valor.resueltos, eq.valor.tiempo });
    sort(resultados.begin(), resultados.end());

    for (auto const& r : resultados) 
        cout << r.nombre << " " << r.num_prob_res << " " << r.tiempo << "\n";
    
    cout << "---\n";

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
