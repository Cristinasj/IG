#include "esfera.h"

Esfera::Esfera(int num_vert_perfil, int num_instancias_perfil, float r) {
    std::vector<Tupla3f> perfil_original;
    for (float angulo = -PI/2; angulo < PI/2; angulo+=180.0/num_instancias_perfil) {
        perfil_original.push_back(TuplaG3<float>(sin(angulo),cos(angulo),0));
    }
    crearMalla(perfil_original, num_instancias_perfil);


} 

