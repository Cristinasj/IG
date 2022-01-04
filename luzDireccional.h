#ifndef DIRECCIONAL
#define DIRECCIONAL

#include "luz.h"

class LuzDireccional : public Luz {

    public: 
    LuzDireccional(Tupla2f direccion, unsigned int idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso); 
}; 

#endif