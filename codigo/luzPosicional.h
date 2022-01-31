#ifndef POSICIONAL
#define POSICIONAL

#include "luz.h"

class LuzPosicional : public Luz {

    public: 
    LuzPosicional(Tupla3f posicion, unsigned int idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso); 
}; 

#endif