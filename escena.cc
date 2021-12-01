

#include "aux.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************


Escena::Escena()
{
    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;

    ejes.changeAxisSize( 5000 );

	// Crear los objetos de la escena
   cubo = new Cubo(100.0);
	tetraedro = new Tetraedro();
   cono = new Cono(); 
   esfera = new Esfera(); 
   cilindro = new Cilindro();
   doge = new ObjPLY("./plys/big_dodge");
   // lata = new ObjRevolucion("./ply/lata-pinf", 20);   

}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer
   glEnable( GL_CULL_FACE );
   glEnableClientState(GL_COLOR_ARRAY);
	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );
}



// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujar()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
    ejes.draw();
    // COMPLETAR
    //   Dibujar los diferentes elementos de la escena
    // Habrá que tener en esta primera práctica una variable que indique qué objeto se ha de visualizar
    // y hacer
    // cubo.draw()
    // o
    // tetraedro.draw()
 
   // Modo de visualizar 
   if (modoVisualizar == PUNTOS) {
      glPointSize(10); 
      glPolygonMode(GL_FRONT, GL_POINT);
   } 
   else if (modoVisualizar == LINEAS) {
      glPolygonMode(GL_FRONT, GL_LINE);
   } 
   else if (modoVisualizar == SOLIDO) {
      glPolygonMode(GL_FRONT, GL_FILL);
   } 
   else if (modoVisualizar == AJEDREZ) {
      std::cout << "TODO AJEDREZ" << std::endl; 
   }

   // Figura a dibujar 
   // Inutil a partir de la P2  
   /*
   switch (objetoActivo) {
		case CUBO: cubo->draw(modoDibujar); break;
		case TETRAEDRO: tetraedro->draw(modoDibujar); break;
	}
   */

   glPushMatrix(); 
      glTranslatef(300.0, 0, 300.0); 
      cubo->draw(modoDibujar); 
   glPopMatrix(); 
   glPushMatrix(); 
      glTranslatef(300.0,0, -300.0); 
      tetraedro->draw(modoDibujar); 
   glPopMatrix(); 
   glPushMatrix(); 
      glTranslatef(-300.0,0,-400.0); 
      esfera->draw(modoDibujar); 
   glPopMatrix(); 
   glPushMatrix(); 
      glTranslatef(-300.0,0,0); 
      cilindro->draw(modoDibujar); 
   glPopMatrix(); 
   glPushMatrix(); 
      glTranslatef(-300.0,0,400.0); 
      cono->draw(modoDibujar); 
   glPopMatrix(); 
   glPushMatrix(); 
      glTranslatef(-300.0,0,400.0); 
      glScalef(10.0,10.0,10.0); 
      doge->draw(modoDibujar); 
   glPopMatrix();
   /*
   glPushMatrix(); 
      glTranslatef(-300.0,0,400.0); 
      glScalef(10.0,10.0,10.0); 
      lata->draw(modoDibujar); 
   glPopMatrix(); 
   */ 

}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   using namespace std ;
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   bool salir=false;
   switch( toupper(tecla) )
   {
      case 'Q' :
         if (modoMenu!=NADA) {
            modoMenu=NADA;
            std::cout << "Menú reseteado" << std::endl;  
         }
         else {
            salir=true ;
         }
         break ;
      case 'O' :
         // ENTRAMOS EN MODO SELECCION DE OBJETO
         modoMenu=SELOBJETO;
         std::cout << "Modo selección de objeto" << std::endl;  
         break ;
        case 'V' :
         // ENTRAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
         modoMenu=SELVISUALIZACION;
         std::cout << "Modo selección de modo de visualización" << std::endl;  
         break ;
       case 'D' :
         // ENTRAMOS EN MODO SELECCION DE DIBUJADO
         modoMenu=SELDIBUJADO;
         std::cout << "Modo selección de dibujado. Pulse 1 o 2" << std::endl;  
         break ;
         // COMPLETAR con los diferentes opciones de teclado
      // DENTRO MODO SELECCIÓN OBJETO 
      case 'C' :
         if (modoMenu=SELOBJETO) {
            objetoActivo=CUBO;  
            std::cout << "Cubo activado" << std::endl;  
         }
      break; 
      case 'T' : 
         if (modoMenu=SELOBJETO) {
            objetoActivo=TETRAEDRO;
            std::cout << "Tetraedro activado" << std::endl;  
         }
      break;
      // DENTRO DEL MODO DE VISUALIZACIÓN 
      case 'P' : 
         if (modoMenu=SELVISUALIZACION) {
            modoVisualizar=PUNTOS; 
            std::cout << "Modo puntos activado" << std::endl;  
         }
      break; 
      case 'L' : 
         if (modoMenu=SELVISUALIZACION) {
            modoVisualizar=LINEAS;
            std::cout << "Modo lineas activado" << std::endl;  
         }
      break; 
      case 'S' : 
         if (modoMenu=SELVISUALIZACION) {
            modoVisualizar=SOLIDO; 
            std::cout << "Caso de uso ver sólido" << std::endl;  
         }
      break; 
      case 'A' :   
         if (modoMenu=SELVISUALIZACION) {
            modoVisualizar=AJEDREZ; 
            std::cout << "Modo ajedrez activado" << std::endl;  
         }
      break; 
      // DENTRO DE SELECCIÓN DE MODO DE DIBUJADO   
      case '1' : 
         if (modoMenu=SELDIBUJADO) {
            modoDibujar=1; 
            std::cout << "Modo directo" << std::endl;  
         }
      break; 
      case '2' : 
         if (modoMenu=SELDIBUJADO) {
            modoDibujar=2; 
            std::cout << "Modo diferido" << std::endl;  
         }
      break; 
   }
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         Observer_angle_y-- ;
         break;
	   case GLUT_KEY_RIGHT:
         Observer_angle_y++ ;
         break;
	   case GLUT_KEY_UP:
         Observer_angle_x-- ;
         break;
	   case GLUT_KEY_DOWN:
         Observer_angle_x++ ;
         break;
	   case GLUT_KEY_PAGE_UP:
         Observer_distance *=1.2 ;
         break;
	   case GLUT_KEY_PAGE_DOWN:
         Observer_distance /= 1.2 ;
         break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   const float wx = float(Height)*ratio_xy ;
   glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef( 0.0, 0.0, -Observer_distance );
   glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
   glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );
}
