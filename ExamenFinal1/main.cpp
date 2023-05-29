
// Javier Lobillo Olmedo (DG 19)

/*
Mi solución utiliza tres iteradores: uno sobre el objeto al que estoy apuntando actualmente, otro en el siguiente elemento de la cola 1, y otro en el siguiente elemento
de la cola 2. Separo mi solucion en distintos casos: si ambas colas tienen elementos, o si solo tiene elementos una de ellas, ya sea porque a la otra se le ha acabado, 
o no ha tenido desde un principio.
En el caso en que ambas tengas elementos hay que hacer saltos consecutivos de una cola a otra. Para ello utilizo una variable i para saltar entre iteracciones pares
o impares e ir saltando de una cola a la otra.

Sea N el tamaño de la primera cola, y M el tamaño de la segunda.
Mi solución tiene coste O(N+M) en el peor caso, y éste es si N = M o N = M + 1, porque tendré que recorrer ambas. Si una de las colas es vacía desde el principio,
el coste es constante. Si N > M + 1, el coste es lineal en M, o si N < M, el coste es lineal en N, ya que recorreré la cola más corta que tenga y el resto lo añadiré
en coste constante.

*/


#include <iostream>                              
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class EntremezclarListas : public deque<int> {
    using Nodo = typename deque::Nodo;
public:
   // imprime la lista
   void print(std::ostream& o = std::cout) const {
       Nodo* it = this->fantasma->sig;
       for (int i = 0; i < nelems; i++) {
           cout << it->elem << " ";
           it = it->sig;
       }
   }

   // modifica this para entremezclar sus elementos con los de other
   void entremezclar(EntremezclarListas & other) {
       Nodo* actual = this->fantasma;
       Nodo* it1 = this->fantasma->sig;
       Nodo* it2 = other.fantasma->sig;
       int N = this->size();
       int M = other.size();
       int i = 1;

       if (N) {
           if (M) {
               while (N && M) {
                   if (i % 2 == 1) {
                       actual->sig = it1;
                       it1->ant = actual;
                       it1 = it1->sig;
                       N--;
                   }
                   else if(i % 2 == 0) {
                       actual->sig = it2;
                       it2->ant = actual;
                       it2 = it2->sig;
                       M--;
                   }
                   actual = actual->sig;
                   i++;
               }
               if (N) {
                   actual->sig = it1;
                   it1->ant = actual;
               }
               else if(M){
                   actual->sig = it2;
                   it2->ant = actual;

                   this->fantasma->ant = other.fantasma->ant;
                   other.fantasma->ant->sig = this->fantasma;
               }
           }

       }
       else if(M) {
           this->fantasma->sig = other.fantasma->sig;
           other.fantasma->sig->ant = this->fantasma;
           this->fantasma->ant = other.fantasma->ant;
           other.fantasma->ant->sig = this->fantasma;
       }


       this->nelems += other.nelems;

       other.fantasma->sig = other.fantasma;
       other.fantasma->ant = other.fantasma;
       other.nelems = 0;

   }
   
};


/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, EntremezclarListas const& a) {
   a.print(o);
   return o;
}

EntremezclarListas leerLista() {
   EntremezclarListas lista;
   int n, val;
   cin >> n; // tamaño
   while (n--) {
      cin >> val;
      lista.push_back(val);
   }
   return lista;
}

void resuelveCaso() {
   auto lista1 = leerLista();
   auto lista2 = leerLista();
   
   lista1.entremezclar(lista2);
   
   cout << lista1 << '\n';
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int casos;
   cin >> casos;
   for (int i = 0; i < casos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
 //  system("PAUSE");
#endif
   return 0;
}
