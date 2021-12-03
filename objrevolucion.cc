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
   // 1. Lectura de perfil 
   std::vector<Tupla3f> vectoresLeidos; 
   ply::read_vertices(archivo, vectoresLeidos);
   
   // 2. Generación objeto revolución
      // 1. Creación tabla vértices  
      // Búsqueda de los vértices situados en el eje Y 
   std::vector<Tupla3f> vectorEje; 
   for (int i= 0; i < v.size(); i++) {
      if (v[i](2) == 0){
         vectorEje.push_back(v[i]); 
      } else {
         v.push_back(v[i]); 
      } 
   }
         // Generar la rotación
         // Tamaño = instanciaPerfil * índicePerfil
   int numVertices = v.size();   
   for (int i = 0; i < num_instancias; i++) {
      for (int j = 0; j < numVertices; j++) {
         // Calculo del ángulo 
         float angulo = j; 
         Tupla3f vertice = Tupla3f(v[j](0)*sin(angulo), v[j](1), v[j](0)*cos(angulo));
         v.push_back(vertice);   
      }   
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
      // 3. Creación tapas 
         // Tapa superior 

         // Tapa inferior 

}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
    
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
}
