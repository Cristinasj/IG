#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "tetraedro.h"
#include "esfera.h"
#include "cilindro.h"
#include "cono.h"
#include "objply.h"
#include "objrevolucion.h"
#include "luzDireccional.h"
#include "luzPosicional.h"
#include "humanoide.h"
#include "materiales.h"

class Escena
{

   private:
   Cubo * cubo; 
   Esfera * esfera; 
   Cabeza * cabeza; 
   Materiales materiales; 
   
 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)

       // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection( const float ratio_xy );
	void change_observer();



   void clear_window();

   menu modoMenu=NADA;
   // Objetos de la escena
   Ejes ejes;
	// objetovisible objetoActivo = CUBO;
   modovisualizacion modoVisualizar = ILUMINACION;
   int modoDibujar = 1; // 1 clásico 2 diferido  
   seleccionangulo seleccionAngulo = ALFA; 
   variacionangulo variacionAngulo = INCREMENTA; 
   int camaraSeleccionada = 0; 


   
   LuzPosicional * luzPosicional = nullptr; 
   LuzDireccional * luzDireccional = nullptr; 

   public:

   Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );

};
#endif
