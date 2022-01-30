#include "luz.h"

void Luz::activar () {
    glEnable(GL_LIGHTNING); 
    glEnable(id); 
}

void Luz::desactivar() {
    glDisable(GL_LIGHTNING); 
}
