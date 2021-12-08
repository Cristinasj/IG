#include "aux.h"
#include "objrevolucion.h"
#include "ply_reader.h"



// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
   // completar ......(práctica 2)
   std::vector<Tupla3f> vectoresLeidos; 
   ply::read_vertices(archivo, vectoresLeidos);
   init (vectoresLeidos, num_instancias, tapa_sup, tapa_inf);  
   
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
   init (archivo, num_instancias, tapa_sup, tapa_inf);
}

void ObjRevolucion::init(std::vector<Tupla3f> perfil, int num_instancias, bool tapa_sup, bool tapa_inf) {
   // Búsqueda de los polos situados en el eje y 
   std::vector<Tupla3f> polos; 
   std::vector<Tupla3f> sinPolos; 
   if (perfil[0](0) == 0.0 && perfil[0](2) == 0.0) 
      polos.push_back(perfil[0]); 
   else 
      sinPolos.push_back(perfil[0]); 
   for (int i = 1; i < perfil.size()-1; i++)
      sinPolos.push_back(perfil[i]); 
   if (perfil[perfil.size()-1](0) == 0.0 && perfil[perfil.size()-1](2) == 0.0)
      polos.push_back(perfil[perfil.size()-1]); 
   else 
      sinPolos.push_back(perfil[perfil.size()-1]); 

   // Creación malla sin tapas
   crearMalla(sinPolos,num_instancias);

  // Creación tapas 
      // Tapa superior 

      // Tapa inferior 

   // Adición de colores 
   for (int i = 0; i < v.size(); i++)
      c.push_back(Tupla3f(0.0,0.99,0.0)); 
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
   // 1. Creación de los vértices 
   v = perfil_original; 
   int numVertices = perfil_original.size();   
   for (int i = 1; i <= num_instancias; i++) {
      // Calculo del ángulo 
      float angulo = i*2*PI/num_instancias; 
      for (int j = 0; j < numVertices; j++) 
         v.push_back(Tupla3f(v[j](0)*sin(angulo), v[j](1), v[j](0)*cos(angulo)));
   }

   // 2.  Creación caras 
   for (int i = 0; i < num_instancias; i++) {
      for (int j = 0; j < numVertices -1; j++) {
         int a = numVertices*i + j; 
         int b = numVertices*((i+1) % num_instancias) + j;
         f.push_back(Tupla3u(a, b, b + 1)); 
         f.push_back(Tupla3u(a, b + 1, a + 1));    
      }
   } 
}