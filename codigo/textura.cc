#include "textura.h"

Textura::Textura(std::string archivo) {
    jpg::Imagen * pimg = new jpg::Imagen(archivo);
    width = pimg->tamX(); 
    height = pimg->tamY();
    // Reflejo horizontal  
    for (int i = height -1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            unsigned char * d = pimg->leerPixel(j, i); 
            data.push_back(d[0]); 
            data.push_back(d[1]); 
            data.push_back(d[2]); 
        }
    }
}

void Textura::activar() {
    glEnable(GL_TEXTURE_2D); 

    if (textura_id == 0) {
        glGenTextures(1, &textura_id); 
        glBindTexture(GL_TEXTURE_2D, textura_id); 
        // Esta linea me da fallo de segmentación 
        // gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data.data());
    }
    else {
        glBindTexture(GL_TEXTURE_2D, textura_id); 
    }
}