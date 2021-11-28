#include "cono.h"

Cono::Cono(int num_vert_perfil, int num_instancias_perfil, float h, float r){
    altura = h;  
    radio = r; 
    std::vector<Tupla3f> perfil_original;
    perfil_original.push_back(TuplaG3<float>(r,0,0));
    perfil_original.push_back(TuplaG3<float>(0,h,0));
    crearMalla(perfil_original, num_instancias_perfil);


}

