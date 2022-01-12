#ifndef CONO_H
#define CONO_H
#include "objrevolucion.h"

class Cono : public ObjRevolucion {

private: 
    float altura; 
    float radio; 

public: 
    Cono(int num_vert_perfil = 2, int num_instancias_perfil = 20, float h = 5.0, float r = 1.0); 

}; 



#endif 
