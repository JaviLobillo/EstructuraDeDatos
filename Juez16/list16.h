#pragma once

#ifndef list16_h
#define list16_h

#include <iostream>
#include "list_eda.h"

template <class T>
class list16 : public list<T> {
	using Nodo = typename list<T>::Nodo;
public:
	template <class Predicate>
	void remove_if(Predicate pred) {
		Nodo* it = this->fantasma->sig;
		while (it != this->fantasma) {
			if (pred(it->elem)) {
				Nodo* sig = it->sig;
				this->borra_elem(it);
				it = sig;
			}
			else it = it->sig;
		}
	}

	void write(std::ostream & salida = std::cout) {
		Nodo* it = this->fantasma->sig;

		while (it != this->fantasma) {
			salida << it->elem << '\n';
			it = it->sig;
		}
		std::cout << "---\n";
	}
};

#endif // !list16_h
