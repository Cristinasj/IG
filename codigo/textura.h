#ifndef TEXTURA
#define TEXTURA 

#include "aux.h"
#include "jpg_imagen.hpp"

class Textura {
    unsigned int textura_id = 0; 
    std::vector<unsigned char> data; 
    int width, height; 

public: 
    Textura(std::string archivo); 
    void activar(); 
}; 

#endif