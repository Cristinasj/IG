#ifndef CILINDRO_H
#define CILINDRO_H
#include "objrevolucion.h"

class Cilindro : public ObjRevolucion {

private: 
    float altura; 
    float radio; 

public: 
    Cilindro(int num_vert_perfil = 2, int num_instancias_perfil = 20, float h = 3.0, float r = 1.0); 

}; 


#endif 