#include "luzDireccional.h"

LuzDireccional::LuzDireccional(const Tupla2f & orientacion, unsigned int idLuzOpenGL, Tupla4f ambiente, Tupla4f difuso, Tupla4f especular) {
    alpha = orientacion(0); 
    beta = orientacion(1); 
    posicionar(alpha, beta);  
    colorAmbiente = ambiente; 
    colorDifuso = difuso; 
    colorEspecular = especular; 
}

void LuzDireccional::posicionar(float alpha, float beta) {
    float radio = cos(alpha); 
    posicion(0) = radio * sin(beta); 
    posicion(1) = sin(alpha); 
    posicion(2) = radio * cos(beta); 
}

void LuzDireccional::variarAnguloAlpha(float incremento) {
    alpha += incremento; 
    posicionar(alpha, beta); 
}

void LuzDireccional::variarAnguloBeta(float incremento) {
    beta += incremento; 
    posicionar(alpha, beta); 
}