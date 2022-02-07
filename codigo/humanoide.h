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
    Materiales materiales; 
public: 
    Brazo(); 
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
    float movimientoCabeza = 0.0; 
    float giroAntebrazo = 0.0; 
    float giroHombro = 0.0; 
public: 
    Humanoide(); 
    void dibujar(); 
}; 

#endif