#pragma once

#ifndef persona_h
#define persona_h

#include <string>
#include <iostream>

class persona {
private:
	std::string nombre;
	int edad;

public:
    persona() { edad = 0; nombre = ""; }
    persona(std::string nom, int ed) { nombre = nom; edad = ed; }

    std::string get_nombre() { return nombre; }
    int get_edad() { return edad; }

    void read(std::istream & entrada) {
        entrada >> edad;
        entrada.ignore(1);
        getline(entrada, nombre);
    }

    void write(std::ostream & salida) {
        salida << nombre;
    }
};


inline std::istream & operator>>( std::istream & entrada, persona& p) {
    p.read(entrada);
    return entrada;
}

inline std::ostream& operator<<(std::ostream& salida, persona& p) {
    p.write(salida);
    return salida;
}

#endif // !persona_h
