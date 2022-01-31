#include "luz.h"

void Luz::activar () {
    glEnable(GL_LIGHTING); 
    glEnable(id); 
    // Configurar los parámetros en función del valor actual de las variables de instancia que describen dicha fuente
    glLightfv(id,GL_AMBIENT,colorAmbiente); 
    glLightfv(id, GL_DIFFUSE, colorDifuso); 
    glLightfv(id, GL_SPECULAR, colorEspecular); 
    glLightfv(id, GL_POSITION, posicion); 
}

void Luz::desactivar() {
    glDisable(GL_LIGHTING); 
}
