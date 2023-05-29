#pragma once

#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <tgmath.h>

template <class T>
class complejo {
private:
	T _a, _b; //parte real, imaginaria

public:
	complejo(){}

	complejo(T a, T b) {
		_a = a;
		_b = b;
	}

	T a() const { return _a; }
	T b() const { return _b; }


	complejo operator+(complejo const & c) {
		return complejo(_a + c.a(), _b + c.b());
	}

	complejo operator*(complejo const & c) {
		return complejo(_a*c.a() - _b*c.b(), _a*c.b() + _b*c.a());
	}


	T mod() {
		return sqrt((_a*_a) + (_b*_b));
	}
};


#endif // !COMPLEJO_H
