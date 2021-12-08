#include "esfera.h"

Esfera::Esfera(int num_vert_perfil, int num_instancias_perfil, float r) {
    std::vector<Tupla3f> perfil_original;
    // Mitad positiva 
    for (float angulo = 0; angulo <= PI/2; angulo+=PI/(2*num_instancias_perfil)) 
        perfil_original.push_back(TuplaG3<float>(r*sin(angulo),r*cos(angulo),0));
    // Mitad negativa
    int cant = perfil_original.size();  
    for (int i = 0; i < cant; i++) {
        TuplaG3<float> s = perfil_original[i]; 
        perfil_original.push_back(TuplaG3<float>(s(0),-s(1), 0));
    }
    crearMalla(perfil_original, num_instancias_perfil); 

    for (int i=0; i < v.size(); i++)
		c.push_back(Tupla3f(0.99, 0.0, 0.0));
} 

