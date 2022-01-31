#include "luzPosicional.h"

LuzPosicional::LuzPosicional(Tupla3f posicion, unsigned int idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso) {
    this->posicion = posicion;
    id = idLuzOpenGL; 
    this->colorAmbiente = colorAmbiente; 
    this->colorEspecular = colorEspecular; 
    this->colorDifuso = colorDifuso; 

}