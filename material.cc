#include "material.h"

void Material::aplicar() {
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambiente); 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difuso); 
    glMaterialfv(GL_FRONT, GL_SPECULAR, especular); 
    glMaterialf(GL_FRONT, GL_SHININESS, brillo); 
}