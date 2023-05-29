
// Javier Lobillo Olmedo

/*
He decidido crear dos mapas, uno de estudiantes, donde aparece cada dni con el grupo al que esta asignado,
y otro de grupos, donde cada uno tiene un vector de dnis de los estudiantes de dicho grupo. En los vectores de
este segundo mapa, se van añadiendo por detrás los nuevos dnis, orden que me servirá posteriormente para la ultima operacion
de novato.
He implementado cada operacion segun me iba pidiendo el enunciado. Al utilizar unordered_map, los costes
de acceso son constantes, lo que ahorra muchas operaciones. Sin embargo, las operacion de promocionar es de coste lineal
porque necesitaba buscar la posicion del estudiante en la lista del grupo antiguo para poder eliminarlo, haciendo un recorrido
lineal por la lista.
Además, la operación de graduados tiene coste N*log(N), ya que es el coste del algoritmo que utiliza la funcion sort para ordenar
un vector.
*/

#ifndef ACADEMIACHINO
#define ACADEMIACHINO

#include <iostream>     
#include <string>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

using grupo = int; //graduados sera el grupo 7
using dni = string;
using info_grupo = vector<dni>;

class academia_chino {
private:
	unordered_map<dni, grupo> estudiantes; //mapa de dni-grupo
	unordered_map<grupo, info_grupo> grupos; //mapa de grupo-lista de alumnos en el grupo
	//como son unordered_map, todos los accesos a sus elementos serán de orden constante
public:
	void nuevo_estudiante(dni const & d, grupo const & g) { //coste constante
		auto itE = estudiantes.find(d);
		if (itE == estudiantes.end()) { //si no hay estudiante
			if (esValido(g)) { //si el grupo es valido
				//añadimos a estudiantes
				estudiantes.insert({ d, g });
				//añadimos a grupos
				auto itG = grupos.find(g);
				//comprobar si existe una lista en dicho grupo
				if (itG != grupos.end())
					itG->second.push_back(d);
				else //si no la hay, se crea
					grupos.insert({ g, {d} });
			}
			else throw domain_error("Grupo incorrecto");
		}
		else
			throw domain_error("Estudiante existente");
    }

	void promocionar(dni const & d) { //sera de orden O(N) por la busqueda en la lista
		auto itE = estudiantes.find(d);
		if (itE != estudiantes.end()) { //si existe el estudiante
			if (itE->second != 7) { // si el estudiante no esta graduado todavia
				auto itG = grupos.find(itE->second);

				//encontrar la posicion del dni a borrar en el grupo antiguo
				//esto tiene coste lineal, ya que hay que recorrer linealmente la lista de los dni del grupo dado
				bool encontrado = false;
				int pos = 0;
				for (int i = 0; i < itG->second.size() && !encontrado; i++) {
					if (d == itG->second[i]) {
						pos = i;
						encontrado = true;
					}
				}
				//borrar dni en el grupo antiguo
				itG->second.erase(itG->second.begin() + pos);

				//modificar grupo
				itE->second++;
				itG = grupos.find(itE->second);
				//comprobar si existe una lista en dicho grupo
				if (itG != grupos.end())
					itG->second.push_back(d);
				else //si no la hay, se crea
					grupos.insert({ itE->second, {d} });
			}
			else
				throw domain_error("Estudiante ya graduado");
		}
		else
			throw domain_error("Estudiante no existente");
	}

	grupo grupo_estudiante(dni const & d) const { //coste constante
		auto itE = estudiantes.find(d);
		if (itE != estudiantes.end()) { //si el estudiante existe
			if (itE->second != 7) { // si el estudiante no esta graduado
				return itE->second;
			}
			else
				throw domain_error("Estudiante ya graduado");
		}
		else
			throw domain_error("Estudiante no existente");
	}

	vector<dni> graduados() const { //tiene un orden de O(N*log(N)) por tener que ordenar la lista a devolver
		auto itG = grupos.find(7); //el iterador a la lista de graduados
		vector<dni> ret = itG->second; //la lista a devolver
		sort(ret.begin(), ret.end()); //ordena en un orden de N*log(N) en orden alfabetico, que es el orden de los strings

		return ret;
	}

	dni novato(grupo const & g) const { // coste constante
		if (esValido(g)) { //si g es un grupo valido
			auto itG = grupos.find(g);
			if (!itG->second.empty()) { //si no es vacio el vector de dicho grupo
				return itG->second.back();
			}
			else
				throw domain_error("Grupo vacio");
		}
		else
			throw domain_error("Grupo incorrecto");
	}

private:
	bool esValido(grupo const & g) const{ //ver si el grupo es 1, 2, 3, 4, 5 o 6
		return g == 1 || g == 2 || g == 3 || g == 4 || g == 5 || g == 6 /*|| g == 7 creo que no necesito esto*/;
	}
};

#endif
