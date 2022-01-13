#include "cubo.h"
#include "tetraedro.h"
#include "esfera.h"

class Humanoide {
private: 
    Cabeza cabeza; 
    Cuerpo cuerpo; 
    Brazo derecho; 
    Brazo izquierdo; 
    Pierna derecha; 
    Pierna izquierda; 
public: 
    Humanoide(); 
    void dibujar(); 
}; 

class Cabeza {
private: 
    Cubo coletaDer; 
    Cubo coletaIzq; 
    Esfera craneo; 
    Tetraedro nariz;
public: 
    Cabeza(); 
    void dibujar; 
}; 

class Brazo {
private: 
    Cubo hombro; 
    Cubo guante; 
public: 
    Brazo(); 
    void dibujar; 
}; 

class Pierna {
private: 
    Cubo muslo; 
    Cubo bota; 
public: 
    Pierna(); 
    void dibujar; 
}; 

class Cuerpo {
private: 
    Cubo camiseta; 
    Cubo falda; 
public: 
    Cuerpo(); 
    void dibujar; 
}; 