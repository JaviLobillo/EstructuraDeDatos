#pragma once

#ifndef queue11_h
#define queue11_h

#include <iostream>

#include "queue_eda.h"

template <class T>
class queue11 : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void insertar(queue11 lista2) {
		Nodo* it1 = this->prim;
		Nodo* it2 = lista2.prim;
		int N = this->nelems, M = lista2.nelems;
		Nodo* act = nullptr;


		if (N) {  //si lista1 no es vacia
			if (M) {
				//primera iteracion
				if (it1->elem < it2->elem) {
					act = it1;
					it1 = it1->sig;
					N--;
				}
				else {
					act = it2;
					this->prim = act;
					it2 = it2->sig;
					M--;
				}

				while (N && M) {
					if (it1->elem < it2->elem) {
						act->sig = it1;
						act = it1;
						it1 = it1->sig;
						N--;
					}
					else {
						act->sig = it2;
						act = it2;
						it2 = it2->sig;
						M--;
					}
				}
				if (N) {
					act->sig = it1;
				}
				else {
					act->sig = it2;
					this->ult = lista2.ult;
				}

			}
		}
		else if (M) {
			this->prim = lista2.prim;
			this->ult = lista2.ult;
		}

		//actualizar nelems
		this->nelems += lista2.nelems;

		//vaciar lista2
		lista2.prim = nullptr;
		lista2.ult = nullptr;
		lista2.nelems = 0;


		/*
		Nodo* iterator1 = this->prim;
		Nodo* anteriorI1 = nullptr;
		Nodo* iterator2 = lista2.prim;
		Nodo* anteriorI2 = nullptr;
		Nodo* sigI2 = nullptr;

		if (iterator1 != nullptr) {  //si lista1 no es vacia
			while (iterator1 != nullptr && iterator2 != nullptr && iterator2->sig != nullptr) {
				anteriorI2 = iterator2;
				if (iterator2->elem <= iterator1->elem) {
					while (iterator2->sig->elem <= iterator1->elem)
						iterator2 = iterator2->sig;

					if (anteriorI1 != nullptr) anteriorI1->sig = anteriorI2;
					else  this->prim = lista2.prim;
					sigI2 = iterator2->sig;
					iterator2->sig = iterator1;
					iterator2 = sigI2;
				}
				anteriorI1 = iterator1;
				iterator1 = iterator1->sig;
			}
			if (iterator2 != nullptr && anteriorI1 != nullptr) {
				if (iterator1 != nullptr) {
					anteriorI1->sig = iterator2;
					iterator2->sig = iterator1;
				}
				else {
					anteriorI1->sig = iterator2;
					this->ult = lista2.ult;
				}
			}
		}
		else {
			this->prim = lista2.prim;
			this->ult = lista2.ult;
			this->nelems = lista2.nelems;
		}

		//actualizar nelems
		this->nelems += lista2.nelems;

		//vaciar lista2
		lista2.prim = nullptr;
		lista2.ult = nullptr;
		lista2.nelems = 0;*/
	}

	void print() {
		Nodo* iterator = this->prim;
		while (iterator != nullptr) {
			std::cout << iterator->elem << " ";
			iterator = iterator->sig;
		}
		std::cout << '\n';
	}
};

#endif // !queue11_h

