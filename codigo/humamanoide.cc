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
        glTranslatef(0.0, alturaCabeza, 0.0); 
        glTranslatef(0.0, 250.0, 0.0); 
        cabeza->dibujar();
    glPopMatrix();
    glPushMatrix(); 
        glTranslatef(0.0,100.0,0.0);
        cuerpo->dibujar();  
    glPopMatrix();   
    glPushMatrix();
        glRotatef(anguloHombroIzquierdo, 0.0,1.0,0.0);
        glTranslatef(50.0,200.0,0.0);  
        brazoIzquierdo->dibujar(); 
    glPopMatrix(); 
    glPushMatrix();
        glRotatef(anguloHombroDerecho, 0.0,1.0,0.0);
        glRotatef(180,0.0,1.0,0.0); 
        glTranslatef(50.0,200.0,0.0);  
        brazoDerecho->dibujar(); 
    glPopMatrix(); 
    piernaDerecha->dibujar(); 
    glPushMatrix(); 
        glRotatef(180, 0.0, 1.0, 0.0); 
        piernaIzquierda->dibujar(); 
    glPopMatrix(); 
}

void Humanoide::modificarAlturaCabeza(float incremento) {
    alturaCabeza += incremento; 
    if (alturaCabeza > 0.0)
        alturaCabeza = 0; 
    if (alturaCabeza < -20.0)
        alturaCabeza = -20; 
}

void Humanoide::modificarGiroCodoDerecho(float incremento) {
    brazoDerecho->modificarGiroCodo(incremento); 
}

void Brazo::modificarGiroCodo(float incremento) {
    anguloCodo += incremento; 
    if (anguloCodo > 90)
        anguloCodo = 90; 
    if (anguloCodo < 0)
        anguloCodo = 0; 
}

void Humanoide::modificarGiroCodoIzquierdo(float incremento) {
    brazoIzquierdo->modificarGiroCodo(incremento); 
}

void Humanoide::modificarGiroHombroDerecho(float incremento) {
    anguloHombroDerecho += incremento; 
    if (anguloHombroDerecho > 90) 
        anguloHombroDerecho = 90;
    if (anguloHombroDerecho < 0) 
        anguloHombroDerecho = 0; 
}

void Humanoide::modificarGiroHombroIzquierdo(float incremento) {
    anguloHombroIzquierdo += incremento; 
    if (anguloHombroIzquierdo > 90) 
        anguloHombroIzquierdo = 90;
    if (anguloHombroIzquierdo < 0) 
        anguloHombroIzquierdo = 0; 
}

Cabeza::Cabeza() {

    coletaDer = new Cubo();
    coletaDer->setMaterial(materiales.pelo);  
    coletaIzq = new Cubo(); 
    coletaIzq->setMaterial(materiales.pelo); 
    craneo = new Esfera();        
    craneo->setMaterial(materiales.piel);  
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
        glScalef(0.5, 7.0, 0.5);
        glTranslatef(40.0,-10.0, -40.0 ); 
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
    hombro->setMaterial(materiales.piel); 
    guante = new Cubo(); 
    guante->setMaterial(materiales.negro); 
}

void Brazo::dibujar() {
    glPushMatrix();
        glScalef(2.0,1.0,1.0); 
        glTranslatef(12.5,12.5,0.0); 
        hombro->draw(); 
    glPopMatrix();
    glPushMatrix();  
        glRotatef(anguloCodo, 0.0, 1.0, 0.0);
        glTranslatef(50.0,0.0,0.0); 
        glScalef(3.0,1.0,1.0); 
        glTranslatef(12.5,12.5,0.0); 
        guante->draw(); 
    glPopMatrix(); 
}

Pierna::Pierna() {
    muslo = new Cubo();
    muslo->setMaterial(materiales.piel);  
    bota = new Cubo(); 
    bota->setMaterial(materiales.negro); 
}

void Pierna::dibujar() {
    glPushMatrix();
        glScalef(38.0/25.0, 1.0, 1.0); 
        glTranslatef(20, 75, 0); 
        glTranslatef(0.0,12.5,0.0); 
        muslo->draw(); 
    glPopMatrix(); 
    glPushMatrix(); 
        glScalef(38.0/25.0, 3.0, 1.0); 
        glTranslatef(20.0,0.0, 0.0);  
        glTranslatef(0.0,12.5,0.0); 
        bota->draw(); 
    glPopMatrix();  
}