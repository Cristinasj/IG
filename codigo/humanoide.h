#ifndef HUMANOIDE
#define HUMANOIDE 
#include "cubo.h"
#include "tetraedro.h"
#include "esfera.h"
#include "materiales.h"

class Cabeza {
private: 
    Cubo * coletaDer; 
    Cubo * coletaIzq; 
    Esfera * craneo; 
    Tetraedro * nariz;
    Materiales materiales; 
public: 
    Cabeza(); 
    void dibujar(); 
}; 

class Brazo {
private: 
    Cubo * hombro; 
    Cubo * guante; 
    float anguloCodo = 0.0;  // Entre 0 y 90 
    Materiales materiales; 
public: 
    Brazo();
    void modificarGiroCodo(float incremeneto);  
    void dibujar(); 
}; 

class Pierna {
private: 
    Cubo * muslo; 
    Cubo * bota; 
    Materiales materiales; 
public: 
    Pierna(); 
    void dibujar(); 
}; 

class Cuerpo {
private: 
    Cubo * camiseta; 
    Cubo * falda; 
    Materiales materiales; 
public: 
    Cuerpo(); 
    void dibujar(); 
}; 

class Humanoide {
private: 
    Cabeza * cabeza; 
    Cuerpo * cuerpo; 
    Brazo * brazoDerecho; 
    Brazo * brazoIzquierdo; 
    Pierna * piernaDerecha; 
    Pierna * piernaIzquierda; 
    float anguloHombroDerecho = 0.0; // Entre 0 y 90
    float anguloHombroIzquierdo = 0.0; // Entre 0 y 90 
    float alturaCabeza = 0.0; // Entre 0 y -20
public: 
    Humanoide(); 
    void dibujar(); 
    void modificarGiroHombroDerecho(float incremento);
    void modificarGiroHombroIzquierdo(float incremento); 
    void modificarGiroCodoDerecho(float incremento); 
    void modificarGiroCodoIzquierdo(float incremento); 
    void modificarAlturaCabeza(float incremento);  
}; 

#endif