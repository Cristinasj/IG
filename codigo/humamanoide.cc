#include "aux.h"
#include "humanoide.h"

Cabeza::Cabeza() {

    coletaDer = new Cubo();
    coletaDer->setMaterial(materiales.pelo);  
    coletaIzq = new Cubo(); 
    coletaIzq->setMaterial(materiales.pelo); 
    craneo = new Esfera();        
    craneo->setMaterial(materiales.camiseta);  
    nariz = new Tetraedro(); 
    nariz->setMaterial(materiales.piel);  
}

void Cabeza::dibujar() {
    glPushMatrix(); 
        craneo->draw();
        glPushMatrix(); 
            glTranslatef(0.0,0.0,25.0); 
            nariz->draw();
        glPopMatrix();  
        glScalef(0.5, 3.0, 0.5);
        glTranslatef(40.0,-5.0, -40.0 ); 
        coletaDer->draw();
        glTranslatef(-80.0,0.0,0.0 ); 
        coletaIzq->draw(); 
    glPopMatrix(); 
}