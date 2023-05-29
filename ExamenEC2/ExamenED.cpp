
// Enrique Carro Garrido
// Javier Lobillo Olmedo




/*
Sea S el numero de sensores. Tenemos un diccionario que asocia cada sensor (clave), con un vector
de ocasiones en el que ha sido activado (valor). Este vector va a guarar las ocasiones en que ha sido activado.

Nosotros vamos leyendo cada uno de los N avisos de forma que tomamos el sensor correcpondiente y modificamos su valor
en el diccionario. Como es un vector de horas, vamos introduciendo en el final de ese vector, la hora del
nuevo aviso.

Una vez procesada toda esta secuencia de aviso, nos realizan M preguntas. Cada pregunta está formada por el nombre del 
sensor y la i ocasión en la que ocurrió dicho aviso. La respuesta puede ser "--" en caso de que no haya ocurrido dicha ocasion, es decir,
que el tamaño del vector no haya llegado hasta ahí, o el valor de la posición i del vector.

Coste: El coste de las operaciones es lineal respecto al factor de carga (la relación entre el numero de pares clave-valor y el tamaño
del diccionario), que es constante amortizado con respecto al numero de sensores, S. Como estamos realizando N avisos y M preguntas, el coste es
N + M.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using sensor = std::string;
using info_sensor = std::vector<std::string>;

bool resuelveCaso() {
   
    int M, N;

    std::unordered_map<sensor, info_sensor> tablaS; //nombre de sensor, hora
    //Diccionario que asocia el nombre del sensor con una lista de numero de ocasiones que ha habido un aviso con la correspondiente hora
    std::cin >> N;

    if (!std::cin)  // fin de la entrada
      return false;

    std::cin >> M;

    std::string sensor;
    std::string hora;
    int momento;

    //procesar avisos
    for (int i = 0; i < N; i++) {
        std::cin >> sensor;
        std::cin >> hora;

        tablaS[sensor].push_back(hora);
    }

    //procesar preguntas
    for (int i = 0; i < M; i++) {
        std::cin >> sensor;
        std::cin >> momento;

        if (momento > tablaS[sensor].size())
            std::cout << "-- ";
        else
            std::cout << tablaS[sensor][momento-1] << " ";
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
