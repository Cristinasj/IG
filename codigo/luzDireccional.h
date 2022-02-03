#ifndef DIRECCIONAL
#define DIRECCIONAL

#include "luz.h"

class LuzDireccional : public Luz {
protected:
    float alpha; 
    float beta;
public: 
    LuzDireccional(const Tupla2f & orientacion, unsigned int idLuzOpenGL, Tupla4f ambiente, Tupla4f difuso, Tupla4f especular);

    void variarAnguloAlpha(float incremento); 
    void variarAnguloBeta(float incremento);  
}; 
#endif