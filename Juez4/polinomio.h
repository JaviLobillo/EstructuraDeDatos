#pragma once

#ifndef polinomio_h
#define polinomio_h

#include <iostream>
#include <vector>
#include <math.h>

class polinomio {
	using monomio = std::pair<int, int>;
private:
	std::vector<monomio> _polinomio;

public:
	polinomio(){}



	void annadirTermino(int const & c, int const & e) {
		monomio nuevo(c, e);
		bool insertado = false;

		for (int i = 0; i < _polinomio.size() && !insertado; i++) {
			if (e <= _polinomio[i].second) {
				if (e < _polinomio[i].second)
					_polinomio.insert(_polinomio.begin() + i, nuevo);
				else _polinomio[i].first += c;
				insertado = true;
			}
		}

		if (!insertado) {
			_polinomio.push_back(nuevo);
		}
	}

	int evaluar(int const & valor) {
		int suma = 0;
		for (int i = 0; i < _polinomio.size(); i++)
			suma += _polinomio[i].first * pow(valor, _polinomio[i].second);

		return suma;
	}


};
#endif // !polinomio_h

