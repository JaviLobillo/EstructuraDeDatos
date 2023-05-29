#pragma once

#ifndef queue10_h
#define queue10_h

#include <iostream>
#include "queue_eda.h"


template <class T>
class queue10 : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void insertar(int P, queue10 & lista2) {
		Nodo* iterator = queue<T>::prim;
		Nodo* sig;
		if (P > 0) {
			for (int i = 0; i < P - 1; i++)
				iterator = iterator->sig;

			sig = iterator->sig;
			iterator->sig = lista2.queue<T>::prim;
		}
		else {
			sig = queue<T>::prim;
			queue<T>::prim = lista2.queue<T>::prim;
		}

		lista2.queue<T>::ult->sig = sig;

		queue<T>::nelems += lista2.queue<T>::nelems;

		lista2.queue<T>::prim = nullptr;
		lista2.queue<T>::ult = nullptr;
		lista2.queue<T>::nelems = 0;

	}

	void print() {
		Nodo* iterator = queue<T>::prim;
		while (iterator != nullptr) {
			std::cout << iterator->elem << " ";
			iterator = iterator->sig;
		}
		std::cout << "\n";
	}
};
#endif // !queue_h

