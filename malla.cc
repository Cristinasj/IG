#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************

// Creación de las tablas VBO 
unsigned int Malla3D::CrearVBO (unsigned int tipo_vbo, unsigned int tamanio_bytes, void * puntero_ram) {
   GLuint id_vbo; 
   glGenBuffers(1, & id_vbo); 
   glBindBuffer(tipo_vbo, id_vbo); 
   glBufferData(tipo_vbo, tamanio_bytes, puntero_ram, GL_STATIC_DRAW);
   glBindBuffer(tipo_vbo, 0); 
   return id_vbo;  
}

// Visualización en modo inmediato con 'glDrawElements'

void Malla3D::draw_ModoInmediato()
{
  // visualizar la malla usando glDrawElements
  // completar (práctica 1)
   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer(3,GL_FLOAT, 0, v.data());
   glDrawElements(GL_TRIANGLES,3*f.size(),GL_UNSIGNED_INT, f.data());
}
// -----------------------------------------------------------------------------
// Visualización en modo diferido con 'glDrawElements' (usando VBOs)

void Malla3D::draw_ModoDiferido()
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   if (id_vbo_tri==0 && id_vbo_ver==0) {
      id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER, 8*3*sizeof(float), v.data()); 
      id_vbo_tri = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, 12*3*sizeof(int), f.data()); 
   }
   // Activar VBO de vértices
   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_ver);
   glVertexPointer(3, GL_FLOAT, 0, 0); 
   glBindBuffer(GL_ARRAY_BUFFER, 0); 
   glEnableClientState(GL_VERTEX_ARRAY); 
   
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri); 
   glDrawElements(GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0); 
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); 

   // glDisableClientState(GL_VERTEX_ARRAY); 
}
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw(int modo)
{
   // completar .....(práctica 1)
   glColorPointer(3, GL_FLOAT, 0, c.data()); 
   switch(modo) {
      case 1: 
         draw_ModoInmediato(); 
      break; 
      case 2TuplaG3<float>(:
         draw_ModoDiferido();   
      break; 
   }

}
