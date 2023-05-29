#pragma once

#ifndef queue12_h
#define queue12_h

#include <iostream>

#include "queue_eda.h"

template <class T>
class queue12 : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	T afortunado(T c) {
		Nodo* it = this->ult;
		this->ult->sig = this->prim;

		while (this->nelems > 1) {
			for (int i = 0; i < c; i++) it = it->sig;
			it->sig = it->sig->sig;
			this->nelems--;
		}
		this->prim = it;
		this->ult = it;
		this->ult->sig = nullptr;

		return it->elem;

	}
};

#endif // !queue12_h


