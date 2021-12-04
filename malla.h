// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "aux.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D
{
   public:

   /* Creación VBO
      tipo vbo = vértices GL_ARRAY_BUFFER o triángulos GL_ELEMENT_ARRAY_BUFFER 
      tamaño bytes = del VBO 
      puntero ram = donde están los datos  
      devuelve = identificador VBO 
   */ 
   unsigned int CrearVBO (unsigned int tipo_vbo, unsigned int tamanio_bytes, void * puntero_ram); 

   // dibuja el objeto en modo inmediato
   void draw_ModoInmediato();
   void draw_ModoInmediato_Ajedrez(); 

   // dibuja el objeto en modo diferido (usando VBOs)
   void draw_ModoDiferido();
   void draw_ModoDiferido_Ajedrez(); 

   // función que redibuja el objeto
   // está función llama a 'draw_ModoInmediato' (modo inmediato)
   // o bien a 'draw_ModoDiferido' (modo diferido, VBOs)
   void draw(int modo, modovisualizacion modoVisualizar) ;

   protected:

   void calcular_normales() ; // calcula tabla de normales de vértices (práctica 3)

   std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3u> f ; // una terna de 3 enteros por cada cara o triángulo
   unsigned int id_vbo_ver = 0;  
   unsigned int id_vbo_tri = 0; 
   unsigned int id_vbo_col = 0; 
   unsigned int id_carasPares; 
   unsigned int id_carasImpares;  
   unsigned int id_coloresPares; 
   unsigned int id_coloresImpares; 

   // completar: tabla de colores, tabla de normales de vértices
   std::vector<Tupla3f> c ;
   // Normales 
   std::vector<Tupla3f> n ;
} ;


#endif
