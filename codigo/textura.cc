#include "textura.h"

Textura::Textura(std::string archivo) {
    jpg::Imagen * pimg = new jpg::Imagen("archivo");
    width = pimg->tamX(); 
    height = pimg->tamY();
    // Paso a vector encontrado en stackoverflow 
    std::vector<unsigned char> pasoVector (pimg->leerPixels(), pimg->leerPixels() + width*height) ; 
    data = pasoVector; 
}