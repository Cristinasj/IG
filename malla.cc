#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************

void Malla3D::calcular_normales() {
	// Se calculan las normales de las caras para usarlos más tarde en los vértices
	std::vector<Tupla3f> nc; 
	for (int i = 0; i < f.size(); i++) {
		Tupla3f p = v[f[i](0)]; 
   		Tupla3f q = v[f[i](1)]; 
   		Tupla3f r = v[f[i](2)]; 
		Tupla3f a = q - p; 
	    Tupla3f b = r - p; 
	    Tupla3f mc = a.cross(b); 
		nc.push_back(mc.normalized());  
	} 

	// Inicializar arrays de normales para los vértices 
	// Para eso se recorren las caras y se hace una acumulación de su valor en los vértices de los que es adyacente  
	// Se inicializan a 0 las normales 
	for (int i = 0; i < v.size(); i++ ) 
		n.push_back(Tupla3f(0,0,0));  
	// Acumulación del valor de la normal de las caras
	for (int i = 0; i < f.size(); i++) {
		for (int j = 0; j < 3; j++)
			n[f[i](j)] = n[f[i](j)] + nc[i];  		
	}
}

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
void Malla3D::draw_ModoInmediato() {
  // visualizar la malla usando glDrawElements
  // completar (práctica 1)
   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer(3,GL_FLOAT, 0, v.data());
   glColorPointer(3, GL_FLOAT, 0, c.data()); 
   glDrawElements(GL_TRIANGLES,3*f.size(),GL_UNSIGNED_INT, f.data());
}

void Malla3D::draw_ModoInmediato_Ajedrez() {
   // Reparto de caras en dos vectores 
   std::vector<Tupla3u> carasPares; 
   std::vector<Tupla3u> carasImpares ;
   int tam = f.size(); 
   for (int i = 0; i < tam; i+=2) {
      carasPares.push_back(f[i]);
      carasImpares.push_back(f[i+1]);  
   } 
   if (tam % 2 != 0) 
      carasPares.push_back(f[tam -1]); 

   // Creación de dos vértices de colores 
   std::vector<Tupla3f> coloresPares ; 
   for (int i = 0; i < v.size(); i++) 
      coloresPares.push_back(Tupla3f(0.99,0,0)); 
   std::vector<Tupla3f> coloresImpares ;  
   for (int i = 0; i < v.size(); i++)
      coloresImpares.push_back(Tupla3f(0,0.99,0.99)); 
   
   // Dibujado de caras pares 
   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer(3,GL_FLOAT, 0, v.data());
   glColorPointer(3, GL_FLOAT, 0, coloresPares.data()); 
   glDrawElements(GL_TRIANGLES,3*carasPares.size(),GL_UNSIGNED_INT, carasPares.data());

   // Dibujado de caras impares
   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer(3,GL_FLOAT, 0, v.data());
   glColorPointer(3, GL_FLOAT, 0, coloresImpares.data()); 
   glDrawElements(GL_TRIANGLES,3*carasImpares.size(),GL_UNSIGNED_INT, carasImpares.data());
}

// -----------------------------------------------------------------------------
// Visualización en modo diferido con 'glDrawElements' (usando VBOs)

void Malla3D::draw_ModoDiferido() {
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   if (id_vbo_ver==0)  
      id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER, v.size()*3*sizeof(float), v.data()); 
   if (id_vbo_tri==0)
      id_vbo_tri = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, f.size()*3*sizeof(int), f.data()); 
   if (id_vbo_col==0)
      id_vbo_col = CrearVBO(GL_ARRAY_BUFFER, c.size()*3*sizeof(float), c.data()); 

   // Activar VBO de vértices
   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_ver);
   glVertexPointer(3, GL_FLOAT, 0, 0); 
   glBindBuffer(GL_ARRAY_BUFFER, 0); 
   glEnableClientState(GL_VERTEX_ARRAY); 
   
   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_col);
   glColorPointer(3, GL_FLOAT, 0, 0); 
   glBindBuffer(GL_ARRAY_BUFFER, 0); 
   glEnableClientState(GL_COLOR_ARRAY); 
   
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri); 
   glDrawElements(GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0); 
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); 

   // glDisableClientState(GL_VERTEX_ARRAY); 
}

void Malla3D::draw_ModoDiferido_Ajedrez() {
         // Creación id vbo en caso de que no existan 
   if (id_vbo_ver == 0)
      id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER, v.size()*3*sizeof(float), v.data()); 
   // Reparto de caras en dos vectores 
   if (id_carasPares == 0) {
      for (int i = 0; i < f.size(); i+=2) 
         carasPares.push_back(f[i]);
      if (f.size() % 2 != 0) 
         carasPares.push_back(f[f.size() -1]); 
      id_carasPares = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, carasPares.size()*3*sizeof(int), carasPares.data()); 
   }
   if (id_carasImpares == 0){
      for (int i = 0; i < f.size(); i+=2) 
         carasImpares.push_back(f[i+1]);  
      id_carasImpares = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, carasImpares.size()*3*sizeof(int), carasImpares.data()); 
   }
   // Creación de dos vértices de colores 
   if (id_coloresPares == 0){
      for (int i = 0; i < c.size(); i++) 
         coloresPares.push_back(Tupla3f(0.99,0,0)); 
      id_coloresPares = CrearVBO(GL_ARRAY_BUFFER, v.size()*3*sizeof(float), coloresPares.data()); 
   }
   if (id_coloresImpares == 0){
      for (int i = 0; i < c.size(); i++)
         coloresImpares.push_back(Tupla3f(0,0.99,0.99)); 
      id_coloresImpares = CrearVBO(GL_ARRAY_BUFFER, v.size()*3*sizeof(float), coloresImpares.data()); 
   }

   // Dibujado en modo diferido 
   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_ver);
   glVertexPointer(3, GL_FLOAT, 0, 0); 
   glBindBuffer(GL_ARRAY_BUFFER, 0); 
   glEnableClientState(GL_VERTEX_ARRAY); 
   
   glBindBuffer(GL_ARRAY_BUFFER, id_coloresPares);
   glColorPointer(3, GL_FLOAT, 0, 0); 
   glBindBuffer(GL_ARRAY_BUFFER, 0); 
   glEnableClientState(GL_COLOR_ARRAY); 
   
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_carasPares); 
   glDrawElements(GL_TRIANGLES, 3*carasPares.size(), GL_UNSIGNED_INT, 0); 
   
   glBindBuffer(GL_ARRAY_BUFFER, id_coloresImpares);
   glColorPointer(3, GL_FLOAT, 0, 0); 
   glBindBuffer(GL_ARRAY_BUFFER, 0); 

   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_carasImpares); 
   glDrawElements(GL_TRIANGLES, 3*carasImpares.size(), GL_UNSIGNED_INT, 0); 
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); 
}

// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw(int modo, modovisualizacion visualizacion)
{
   // completar .....(práctica 1)
   if (visualizacion == AJEDREZ) {

      switch(modo) {
         case 1: 
            draw_ModoInmediato_Ajedrez(); 
         break; 
         case 2:
            draw_ModoDiferido_Ajedrez();   
         break; 
      }
   } else {
      switch(modo) {
         case 1: 
            draw_ModoInmediato(); 
         break; 
         case 2:
            draw_ModoDiferido();   
         break; 
      }
   }

}
