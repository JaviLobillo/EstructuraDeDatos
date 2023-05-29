#pragma once

#ifndef carnet_puntos2_h
#define carnet_puntos2_h

#include <unordered_map>
#include <vector>
#include <list>
#include <utility>

using dni = std::string;
using puntos = int;
using info_dni = std::pair<puntos, std::list<dni>::iterator>; //puntos, iterator

class  carnet_puntos {
private:
	std::unordered_map<dni, info_dni> tablaD;
	std::unordered_map<puntos, std::list<dni>> tablaP;

public:
	// Constructor por defecto
	carnet_puntos() = default;

	// Constructor por copia
	carnet_puntos(const carnet_puntos&) = default;

	// Constructor poroperador =
	carnet_puntos& operator=(const carnet_puntos&) = default;


	void nuevo(dni const & d) {  //O(1)
		info_dni par;
		par.first = 15;
		auto a = tablaD.insert({ d, par });
		if (!a.second) 
			throw std::domain_error("Conductor duplicado");
		
		auto b = tablaP.insert({ 15, {} });
		b.first->second.push_front(d);
		a.first->second.second = b.first->second.begin();
	}

	void quitar(dni const & d, puntos const & p) { //O(1)
		auto it = tablaD.find(d);

		if (it != tablaD.end()) {
			auto& pts_d = it->second.first;
			auto& it_d = it->second.second;
			int pts_ant_d = pts_d;

			pts_d = pts_d - p < 0 ? 0 : pts_d - p;

			if (pts_ant_d != pts_d) {
				tablaP[pts_ant_d].erase(it_d);

				auto it2 = tablaP.find(pts_d);
				if (it2 == tablaP.end())
					tablaP.insert({ pts_d, {} });

				tablaP[pts_d].push_front(d);
				it_d = tablaP[pts_d].begin();
			}
		}
		else throw std::domain_error("Conductor inexistente");
	}

	void recuperar(dni const & d, puntos const & p) {  //O(1)
		auto it = tablaD.find(d);

		if (it != tablaD.end()) {
			auto& pts_d = it->second.first;
			auto& it_d = it->second.second;
			int pts_ant_d = pts_d;

			pts_d = pts_d + p > 15 ? 15 : pts_d + p;

			if (pts_ant_d != pts_d) {
				tablaP[pts_ant_d].erase(it_d);

				auto it2 = tablaP.find(pts_d);
				if (it2 == tablaP.end())
					tablaP.insert({ pts_d, {} });

				tablaP[pts_d].push_front(d);
				it_d = tablaP[pts_d].begin();
			}
		}
		else throw std::domain_error("Conductor inexistente");
	}

	int consultar(dni const& d) { //O(1)
		auto it = tablaD.find(d);
		if (it != tablaD.end())
			return it->second.first;
		else throw std::domain_error("Conductor inexistente");
	}

	int cuantos_con_puntos(puntos const & p) { //O(1)
		if (p >= 0 && p <= 15) {
			auto it = tablaP.find(p);
			if (it != tablaP.end())
				return it->second.size();
			else return 0;
		}
		else throw std::domain_error("Puntos no validos");
	}

	std::list<dni> lista_por_puntos(puntos const & p) {  //O(1)
		if (p >= 0 && p <= 15) {
			auto a = tablaP.find(p);
			std::list<dni> resultado = {};
			if (a != tablaP.end())
				resultado = tablaP[p];
			return resultado;
		}
		else throw std::domain_error("Puntos no validos");
	}
};


#endif //carnet_puntos_h