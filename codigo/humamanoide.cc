#include "aux.h"
#include "humanoide.h"

Humanoide::Humanoide() {
    cabeza = new Cabeza(); 
    cuerpo = new Cuerpo; 
    brazoDerecho = new Brazo(); 
    brazoIzquierdo = new Brazo();
    piernaDerecha = new Pierna(); 
    piernaIzquierda = new Pierna();  

}

void Humanoide::dibujar() {
    glPushMatrix();
        glTranslatef(0.0, movimientoCabeza, 0.0); 
        glTranslatef(0.0, 275.0, 0.0); 
        cabeza->dibujar();
    glPopMatrix();
    glPushMatrix(); 
        glTranslatef(0.0,100.0,0.0);
        cuerpo->dibujar();  
    glPopMatrix();   
    glPushMatrix();
        brazoDerecho->dibujar();  
    glPopMatrix(); 
}

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

Cuerpo::Cuerpo() {
    camiseta = new Cubo(); 
    camiseta->setMaterial(materiales.camiseta); 
    falda = new Cubo(); 
    falda->setMaterial(materiales.negro); 
}

void Cuerpo::dibujar(){
    glPushMatrix(); 
        glTranslatef(0,25.0,0);
        glScalef(4.0, 4.0, 1.0); 
        glTranslatef(0.0,12.5,0.0);  
        camiseta->draw(); 
    glPopMatrix(); 
    glPushMatrix(); 
        glScalef(4.0,1.0,1.0); 
        glTranslatef(0,12.5,0);
        falda->draw(); 
    glPopMatrix(); 
}

Brazo::Brazo() {
    hombro = new Cubo(); 
    guante = new Cubo(); 
}

void Brazo::dibujar() {

}

Pierna::Pierna() {
    muslo = new Cubo(); 
    bota = new Cubo(); 
}

void Pierna::dibujar() {
    
}