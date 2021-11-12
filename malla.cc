#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************

// Creación de las tablas VBO 
GLuint CrearVBO (GLuint tipo_vbo, GLuint tamanio_bytes, 
                  GLvoid * puntero_ram) {
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
   // .....
   // Activar VBO de vértices
   // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~glBindBuffer(GL_ARRAY_BUFFER, id_vbo_ver);
   // Especifica formato y offset (=0)
   glBindBuffer (GL_ARRAY_BUFFER, 0);
   // Desactivar VBO de vértices
   glBindBuffer(GL_ARRAY_BUFFER, 0);
   // Habilitar tabla de vértices
   glEnableClientState(GL_VERTEX_ARRAY);
   // Visualizar triángulos con glDrawElements (puntero a tabla == 0)
   // Activar VBO de triángulos
   // ~~~~~~~ glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri);
   glDrawElements(GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0);
   
}
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw(int modo)
{
   // completar .....(práctica 1)
   switch(modo) {
      case 1: 
         draw_ModoInmediato(); 
      break; 
      case 2:
         std::cout << "Entras en modo diferido" << std::endl;
         draw_ModoDiferido();   
      break; 
   }

}
