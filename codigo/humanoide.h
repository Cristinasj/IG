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
    Cubo hombro; 
    Cubo guante; 
public: 
    Brazo(); 
    void dibujar(); 
}; 

class Pierna {
private: 
    Cubo muslo; 
    Cubo bota; 
public: 
    Pierna(); 
    void dibujar(); 
}; 

class Cuerpo {
private: 
    Cubo camiseta; 
    Cubo falda; 
public: 
    Cuerpo(); 
    void dibujar(); 
}; 

class Humanoide {
private: 
    Cabeza cabeza; 
    Cuerpo cuerpo; 
    Brazo derecho; 
    Brazo izquierdo; 
    Pierna derecha; 
    Pierna izquierda; 
    float movimientoCabeza; 
    float giroAntebrazo; 
    float giroHombro; 
public: 
    Humanoide(); 
    void dibujar(); 
}; 

#endif