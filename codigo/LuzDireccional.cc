#include "luzDireccional.h"

LuzDireccional::LuzDireccional(const Tupla2f & orientacion, unsigned int idLuzOpenGL, Tupla4f ambiente, Tupla4f difuso, Tupla4f especular) {
    alpha = orientacion[0]; 
    beta = orientacion[1]; 
    id = idLuzOpenGL; 
    colorAmbiente = ambiente; 
    colorDifuso = difuso; 
    colorEspecular = especular; 
}