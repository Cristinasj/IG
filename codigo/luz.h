#ifndef LUZ
#define LUZ

#include "aux.h"

class Luz {
    public: 

    void activar(); 
    void desactivar(); 

    protected: 

    Tupla4f posicion; 
    unsigned int id = 0; // El tipo es equivalente a glEnum
    Tupla4f colorAmbiente; 
    Tupla4f colorDifuso;
    Tupla4f colorEspecular; 
     

}; 

#endif