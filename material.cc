#include "material.h"

void Material::aplicar() {
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambiente); 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difuso); 
    glMaterialfv(GL_FRONT, GL_SPECULAR, especular); 
    glMaterialf(GL_FRONT, GL_SHININESS, brillo); 
}

Material::Material(Tupla4f mdifuso, Tupla4f mespecular, Tupla4f mambiente, float mbrillo) {
    ambiente = mambiente; 
    difuso = mdifuso; 
    especular = mespecular; 
    brillo = mbrillo; 
}