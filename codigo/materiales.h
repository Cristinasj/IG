#ifndef MATERIALES 
#define MATERIALES 

#include "material.h"

// Materiales: Camiseta, negro, piel, pelo 
class Materiales {
public:
    // Solo he encontrado el color carne para RGB en enteros 
    // Material piel = Material(Tupla4f((float)255.0/255.0, (float)224.0/255.0, (float)189.0/255.0, 1.0), Tupla4f((float)255.0/255.0, (float)224.0/255.0, (float)189.0/255.0, 1.0), Tupla4f((float)255.0/255.0, (float)224.0/255.0, (float)189.0/255.0, 1.0), 0.0);
    Material piel = Material(Tupla4f(1.0, 0.0, 0.0, 1.0), Tupla4f(1.0, 0.0, 0.0, 1.0), Tupla4f(1.0, 0.0, 0.0, 1.0), 1.0); 
    // Material camiseta = Material(Tupla4f(0.5, 0.5, 0.5, 1), Tupla4f(0.5, 0.5, 0.5, 1), Tupla4f(0.5, 0.5, 0.5, 1), 1.0);
    Material camiseta = Material(Tupla4f(0.0, 1.0, 0.0, 1.0), Tupla4f(0.0, 1.0, 0.0, 1.0),Tupla4f(0.0, 1.0, 0.0, 1.0), 1.0); 
    Material negro = Material(Tupla4f(0.0, 0.0, 0.0, 1.0), Tupla4f(0.0, 0.0, 0.0, 1.0), Tupla4f(0.0, 0.0, 0.0, 1.0), 1.0); 
    // Azul 
    Material pelo = Material(Tupla4f(0.0, 0.0, 1.0, 1.0), Tupla4f(0.0, 0.0, 1.0, 1.0), Tupla4f(0.0, 0.0, 1.0, 1.0), 0.5);  


}; 
#endif 