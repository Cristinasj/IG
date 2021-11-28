#ifndef ESFERA_H
#define ESFERA_H
#include "objrevolucion.h"

class Esfera: public  ObjRevolucion {

private: 
    float radio; 

public: 
    Esfera(int num_vert_perfil = 10, int num_instancias_perfil = 20, float r = 1.0); 

}; 

#endif 