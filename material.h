#ifndef MATERIAL 
#define MATERIAL 

class Material {
    public: 

    void aplicar(); 
    Material(Tupla4f ambiente, Tupla4f difuso, Tupla4f especular, float brillo); 

    private: 

    Tupla4f ambiente; 
    Tupla4f especular; 
    Tupla4f difuso; 
    float brillo; 
}; 

#endif