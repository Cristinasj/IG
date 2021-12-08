#include "cilindro.h"

Cilindro::Cilindro(int num_vert_perfil, int num_instancias_perfil, float h, float r){
    altura = h;  
    radio = r; 
    std::vector<Tupla3f> perfil_original;
    for (int i = 0; i <= num_vert_perfil; i++) 
        perfil_original.push_back(TuplaG3<float>(r,i*h/num_vert_perfil,0));
    crearMalla(perfil_original, num_instancias_perfil);

    for (int i=0; i < v.size(); i++)
		c.push_back(Tupla3f(0.99, 0.0, 0.0));
}