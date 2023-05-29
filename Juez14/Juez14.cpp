
// Javier Lobillo Olmedo

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "queue_eda.h"
#include "stack_eda.h"

/*
N es el numero de caracteres de la linea O(f(n)) = O(N + iS + pS + N + N). Como iS + pS = N, O(f(n)) = O(N).
*/

bool esVocal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void meterNoVocales(queue<char> & X, stack<char> & noVocales) {
    int tam = noVocales.size();
    for (int i = 0; i < tam; i++) {
        X.push(noVocales.top());
        noVocales.pop();
    }
}


bool resuelveCaso() {
    queue<char> impares, Xprima, X;
    stack<char> pares, noVocales;
    std::string linea;
    char c2;
    int i = 1;

    //Leer X''
    getline(std::cin, linea);
    if (!std::cin)  
        return false;

    //Conseguir X' = Xprima


    for(char c : linea) {           //O(N)
        if (i % 2 == 1) //impares
            impares.push(c);
        else            //pares
            pares.push(c);
        i++;
    }

    int iS = impares.size();

    for (int i = 0; i < iS; i++) { //O(iS)
        Xprima.push(impares.front());
        impares.pop();
    }

    int pS = pares.size();

    for (int i = 0; i < pS; i++) { //O(pS)
        Xprima.push(pares.top());
        pares.pop();
    }

    //Conseguir X
    while (Xprima.size()) {         //O(N)      //En el caso peor, toda la linea está compuesta por no vocales y hay que darle la vuelta entera,                                                
        c2 = Xprima.front();                    //lo cual implicaría hacer, como mucho, N cambios más. Las sumas de las colas pequeñas que se hacen
        if (esVocal(c2)) {                      //para darle la vuelta a los no vocales es, como mucho, N.
            meterNoVocales(X, noVocales);
            X.push(c2);
        }
        else {
            noVocales.push(c2);
        }
        Xprima.pop();
    }
    
    meterNoVocales(X, noVocales);

    //salida
    int tam = X.size();
    for (int i = 0; i < tam; i++) { //O(N)
        std::cout << X.front();
        X.pop();
    }
    std::cout << '\n';


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
