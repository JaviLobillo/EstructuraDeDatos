#pragma once

#ifndef carnet_puntos_h
#define carnet_puntos_h

#include <unordered_map>

using dni = std::string;
using puntos = int;
using conductores = int;

class  carnet_puntos {
private:
	std::unordered_map<dni, puntos> tablaD;
	std::unordered_map<puntos, conductores> tablaP;

public:
	// Constructor por defecto
	carnet_puntos() = default;

	// Constructor por copia
	carnet_puntos(const carnet_puntos&) = default;

	// Constructor poroperador =
	carnet_puntos& operator=(const carnet_puntos&) = default;


	void nuevo(dni const & d) {  //O(1)
		auto a = tablaD.insert({ d, 15 });
		if (!a.second) 
			throw std::domain_error("Conductor duplicado");
		
		auto b = tablaP.insert({ 15,1 });
		if (!b.second)
			++b.first->second;

	}

	void quitar(dni const & d, puntos const & p) { //O(1)
		auto it = tablaD.find(d);
		if (it != tablaD.end()) {
			--tablaP[it->second];
			it->second -= p;
			if (it->second < 0)
				it->second = 0;
			
			auto it2 = tablaP.find(it->second);
			if (it2 != tablaP.end())
				++it2->second;
			else tablaP.insert({it->second, 1});
		}
		else throw std::domain_error("Conductor inexistente");
	}

	int consultar(dni const& d) { //O(1)
		auto it = tablaD.find(d);
		if (it != tablaD.end())
			return it->second;
		else throw std::domain_error("Conductor inexistente");
	}

	int cuantos_con_puntos(puntos const & p) { //O(1)
		if (p >= 0 && p <= 15) {
			auto it = tablaP.find(p);
			if (it != tablaP.end())
				return it->second;
			else return 0;
		}
		else throw std::domain_error("Puntos no validos");
	}
};


#endif //carnet_puntos_h