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

   // No sé donde poner esto sinceramente
   GLfloat lmodel_ambient[] = {0.2, 0.2, 0.2, 1.0};  
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient); 

   // Crear los objetos de la escena
   humanoide = new Humanoide(); 
   puerros = new Cubo(1200); 
   puerros->setTextura("puerros.jpeg"); 

   // Luces de la escena 
   Tupla3f posicion = Tupla3f(0.0, 0.0, 0.0); 
   Tupla2f orientacion = Tupla2f(0.0, 0.0); 
   Tupla4f blanco = Tupla4f(1.0, 0, 1.0, 1.0);  
   luzPosicional = new LuzPosicional(posicion, GL_LIGHT1, blanco, blanco, blanco); 
   luzDireccional = new LuzDireccional(orientacion, GL_LIGHT2, blanco, blanco, blanco); 
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
   glEnable(GL_NORMALIZE); // Evita que los escalados varien las normales 
   glEnableClientState(GL_COLOR_ARRAY);
	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );
   menuPrincipal(); 
   glEnable(GL_LIGHT0); // Defecto 
   glEnable(GL_LIGHT1); // Puntual
   glEnable(GL_LIGHT2); // Direccional  
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
   glDisable(GL_LIGHTING); 
   ejes.draw();

   if(modoVisualizar == ILUMINACION) {
      glEnable(GL_LIGHTING); 
      glEnable(GL_TEXTURE_2D); 
   }
    // COMPLETAR
    //   Dibujar los diferentes elementos de la escena
    // Habrá que tener en esta primera práctica una variable que indique qué objeto se ha de visualizar
    // y hacer
    // cubo.draw()
    // o
    // tetraedro.draw()
 
   // Modo de visualizar 
   if (modoVisualizar == PUNTOS) {
      glDisable(GL_LIGHTING); 
      glDisable(GL_TEXTURE_2D);  
      glPointSize(1); 
      glPolygonMode(GL_FRONT, GL_POINT);
   } 
   else if (modoVisualizar == LINEAS) {
      glDisable(GL_LIGHTING); 
      glDisable(GL_TEXTURE_2D);  
      glPolygonMode(GL_FRONT, GL_LINE);
   } 
   else if (modoVisualizar == SOLIDO) {
      glDisable(GL_LIGHTING); 
      glDisable(GL_TEXTURE_2D);  
      glPolygonMode(GL_FRONT, GL_FILL);
   } 
   else if (modoVisualizar == AJEDREZ) {
      glDisable(GL_LIGHTING);
      glDisable(GL_TEXTURE_2D);  
      glPolygonMode(GL_FRONT, GL_FILL);
   } 
   else if (modoVisualizar == ILUMINACION) {
      glEnable(GL_LIGHTING);
      glEnable(GL_TEXTURE_2D); 
      // glLightfv(GL_LIGHT1, GL_DIFUSE, Tupla4f)
      // glLightfv(GL_LIGHT1, GL_SPECULAR, Tupla4f)
      // glLightfv(GL_LIGHT1, GL_AMBIENT, Tupla4f)
      // glLightfv(GL_LIGHT1, GL_POSITION, Tupla4f);  
      glShadeModel(GL_SMOOTH); 
      // glShadeModel(GL_FLAT); 
   }
   /*
   // Figura a dibujar 
   // Inutil a partir de la P2  
   switch (objetoActivo) {
		case CUBO: cubo->draw(modoDibujar); break;
		case TETRAEDRO: tetraedro->draw(modoDibujar); break;
	}
   */   

   humanoide->dibujar(); 
   glPushMatrix(); 
      glTranslatef(0.0, 500.0, -1000.0); 
      puerros->draw(); 
   glPopMatrix(); 
   
}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

void Escena::menuPrincipal() {
            std::cout << std::endl << "MENU PRINCIPAL" << std::endl 
            << "Tecla V: selección de modo de visualización" << std::endl 
            << "Tecla D: selección de modo de dibujado" << std::endl
            << "Tecla T: quitar o poner tapas" << std::endl
            << "Tecla N: Opciones de la animación" << std::endl
            << "Tecla Q: salir" << std::endl;  
 
}

// Para variar los angulos de la luz direccional 
const int VARIACION = 10; 
const int VARIACION_ANIMACION = 1; 

// Letras ocupadas
// Q
// V
// D
// T
// + 
// - 
// P 
// L 
// S 
// A 
// I 
// 1 
// 2 
// < 
// > 
// F 
// B 
// = 
// . 
// N Modo animación 
// C Aumentar la altura de la cabeza 
// E Disminuir la altura de la cabeza 
// 3 Aumentar el ángulo del hombro izquierdo
// 4 Reducir el ángulo del hombro izquierdo 
// 5 Aumentar el ángulo del hombro derecho 
// 6 reducir el ángulo del hombro derecho 
// 7 Aumentar el ángulo del codo izquierdo 
// 8 Reducir el ángulo del codo izquierdo 
// 9 Aumentar el ángulo del codo derecho 
// 0 Reducir el ángulo del codo derecho 
// R Reproducción automática de la animación 

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
            menuPrincipal(); 
        }
         else {
            salir=true ;
         }
      break ;
      /*
      case 'O' :
         // ENTRAMOS EN MODO SELECCION DE OBJETO
         modoMenu=SELOBJETO;
         std::cout << "Modo selección de objeto" << std::endl;  
         break ;
      */
      case 'N' :
         std::cout << std::endl 
         << "OPCIONES DE ANIMACIÓN" << std::endl 
         << "C Aumentar la altura de la cabeza" << std::endl  
         << "E Disminuir la altura de la cabeza"  << std::endl 
         << "3 Aumentar el ángulo del hombro izquierdo"<< std::endl 
         << "4 Reducir el ángulo del hombro izquierdo" << std::endl 
         << "5 Aumentar el ángulo del hombro derecho" << std::endl 
         << "6 reducir el ángulo del hombro derecho" << std::endl 
         << "7 Aumentar el ángulo del codo izquierdo" << std::endl 
         << "8 Reducir el ángulo del codo izquierdo" << std::endl 
         << "9 Aumentar el ángulo del codo derecho" << std::endl 
         << "0 Reducir el ángulo del codo derecho" << std::endl 
         << "R Reproducción automática de la animación" << std::endl;  
      break; 
      case 'C' :
         std::cout << std::endl 
         << "Has elegido aumentar la altura de la cabeza" << std::endl << "Tecla N: volver a ver las opciones de animación" << std::endl; 
         humanoide->modificarAlturaCabeza(VARIACION_ANIMACION);  
      break; 
      case 'E' :
         std::cout << std::endl 
         << "Has elegido disminuir la altura de la cabeza" << std::endl<< "Tecla N: volver a ver las opciones de animación" << std::endl; 
         humanoide->modificarAlturaCabeza(-VARIACION_ANIMACION);  
      break; 
      case '3' :
         std::cout << std::endl 
         << "Has elegido aumentar el angulo del hombro izquierdo" << std::endl<< "Tecla N: volver a ver las opciones de animación" << std::endl; 
         humanoide->modificarGiroHombroIzquierdo(VARIACION_ANIMACION);  
      break; 
      case '4' :
         std::cout << std::endl 
         << "Has elegido disminuir el angulo del hombro izquierdo" << std::endl<< "Tecla N: volver a ver las opciones de animación" << std::endl; 
         humanoide->modificarGiroHombroIzquierdo(-VARIACION_ANIMACION);  
      break; 
      case '5' :
         std::cout << std::endl 
         << "Has elegido aumentar el ángulo del hombro derecho" << std::endl<< "Tecla N: volver a ver las opciones de animación" << std::endl; 
         humanoide->modificarGiroHombroDerecho(VARIACION_ANIMACION);  
      break; 
      case '6' :
         std::cout << std::endl 
         << "Has elegido disminuir el ángulo del hombro derecho" << std::endl<< "Tecla N: volver a ver las opciones de animación" << std::endl; 
         humanoide->modificarGiroHombroDerecho(-VARIACION_ANIMACION);  
      break; 
      case '7' :
         std::cout << std::endl 
         << "Has elegido disminuir el ángulo del codo izquierdo" << std::endl<< "Tecla N: volver a ver las opciones de animación" << std::endl; 
         humanoide->modificarGiroCodoIzquierdo(VARIACION_ANIMACION);  
      break; 
      case '8' :
         std::cout << std::endl 
         << "Has elegido aumentar el ángulo del codo izquierdo" << std::endl<< "Tecla N: volver a ver las opciones de animación" << std::endl; 
         humanoide->modificarGiroCodoIzquierdo(-VARIACION_ANIMACION);  
      break; 
      case '9' :
         std::cout << std::endl 
         << "Has elegido aumentar el ángulo del codo derecho" << std::endl<< "Tecla N: volver a ver las opciones de animación" << std::endl; 
         humanoide->modificarGiroCodoDerecho(VARIACION_ANIMACION);  
      break; 
      case '0' :
         std::cout << std::endl 
         << "Has elegido disminuir el ángulo del codo derecho" << std::endl<< "Tecla N: volver a ver las opciones de animación" << std::endl; 
         humanoide->modificarGiroCodoDerecho(-VARIACION_ANIMACION);  
      break; 
      case 'R' :
         std::cout << std::endl 
         << "Has elegido reproducción automática de la animación" << std::endl<< "Tecla N: volver a ver las opciones de animación" << std::endl; 
         animacionAutomatica = !animacionAutomatica; 
      break; 

      case 'V' :
         // ENTRAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
         modoMenu=SELVISUALIZACION;
         std::cout << std::endl << "SELECCIÓN DE MODO DE VISUALIZACIÓN" << std::endl
          << "Tecla P: Modo puntos" << std::endl 
          << "Tecla L: Modo lineas" << std::endl 
          << "Tecla S: Modo solido" << std::endl
          << "Tecla A: Modo ajedrez" << std::endl
          << "Tecla I: Modo iluminación " << std::endl 
          << "Tecla Q: volver al menu principal" << std::endl;

      break ;
      case 'D' :
         // ENTRAMOS EN MODO SELECCION DE DIBUJADO
         modoMenu=SELDIBUJADO;
         std::cout << std::endl << "SELECCIÓN DE DIBUJADO" << std::endl
          << "Tecla 1: Modo inmediato" << std::endl 
          << "Tecla 2: Modo diferido" << std::endl
          << "Tecla Q: volver al menu principal" << std::endl;

      break ;
      case 'T' : 
         // ENTRAMOS EN MODO SELECCIÓN DE TAPAS 
         modoMenu=TAPAS; 
         std::cout << std::endl << "SELECCIÓN DE TAPAS" << std::endl << "Tecla +: poner tapas" << std::endl 
         << "Tecla -: quitar tapas" << std::endl; 
   }

      // DENTRO MODO SELECCIÓN OBJETO 
      /* Inutil a partir de la práctica 2 
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
      */

     // DENTRO DEL MODO DE SELECCIÓN DE TAPAS 
   switch(toupper(tecla)) {
      case '+': 
         if (modoMenu=TAPAS) {
//            globalTapas=true; 
            std::cout << std::endl << "Ver tapas activado" << std::endl; 
         }
      break; 
      case '-': 
         if (modoMenu=TAPAS) {
//            globalTapas=false; 
            std::cout << std::endl << "Ver tapas desactivado" << std::endl; 
         }
      break;
   }

      // DENTRO DEL MODO DE VISUALIZACIÓN    
   switch( toupper(tecla) ) {
      case 'P' : 
         if (modoMenu=SELVISUALIZACION) {
            modoVisualizar=PUNTOS; 
            std::cout << std::endl << "Modo puntos activado" << std::endl;  
         }
      break; 
      case 'L' : 
         if (modoMenu=SELVISUALIZACION) {
            modoVisualizar=LINEAS;
            std::cout  << std::endl << "Modo lineas activado" << std::endl;  
         }
      break; 
      case 'S' : 
         if (modoMenu=SELVISUALIZACION) {
            modoVisualizar=SOLIDO; 
            std::cout  << std::endl << "Caso de uso ver sólido" << std::endl;  
         }
      break; 
      case 'A' :   
         if (modoMenu=SELVISUALIZACION) {
            modoVisualizar=AJEDREZ; 
            std::cout  << std::endl << "Modo ajedrez activado" << std::endl;  
         }
      break; 
      case 'I' : 
         if (modoMenu=SELVISUALIZACION) {
            modoVisualizar=ILUMINACION; 
            std::cout << std::endl << "Modo iluminacion activado"; 
            std::cout << std::endl << "Tecla º: apagar/encender la luz por defecto"; 
            std::cout << std::endl << "Tecla =: apagar/encender la luz Direccional"; 
            std::cout << std::endl << "Tecla .: apagar/encender la luz Posicional"; 
            std::cout << std::endl << "Tecla F: variación del ángulo alFa";
            std::cout << std::endl << "Tecla B: variación del ángulo Beta";
            std::cout << std::endl << "Tecla >: Incrementar el ángulo seleccionado"; 
            std::cout << std::endl << "Tecla <: Decrementar el ángulo seleccionado";
            std::cout << std::endl << "Tecla q: menu principal"; 
            std::cout << std::endl; 
         }
      break; 
 

   }
   switch( toupper(tecla) ) {
     // DENTRO DE ILUMINACIÓN 
      /*
      case 'º' : 
         if (modoVisualizar=ILUMINACION) {
            if (estaEncendida[0])
         }
      break;
      */
      case '.' :
         if (modoVisualizar=ILUMINACION) {
            if (estaEncendida[1]) {
               std::cout << std::endl << "Se apaga la luz Posicional" << std::endl; 
               glDisable(GL_LIGHT0);
               estaEncendida[0] = false; 
            }         
            else {
               std::cout << std::endl << "Se enciende la luz Posicional" << std::endl; 
               glEnable(GL_LIGHT0);
               estaEncendida[0] = true;  
            }
         } 
      break; 
      case '=' :
         if (modoVisualizar=ILUMINACION) {
            if (estaEncendida[2]) {
               std::cout << std::endl << "Se apaga la luz Direccional" << std::endl; 
               glDisable(GL_LIGHT1);
               estaEncendida[1] = false; 
            }         
            else {
               std::cout << std::endl << "Se enciende la luz Direccional" << std::endl; 
               glEnable(GL_LIGHT1);
               estaEncendida[1] = true;  
            }
         } 
      break;
 
      case '>' : 
         if (modoVisualizar=ILUMINACION) {
            variacionAngulo=INCREMENTA; 
            std::cout << std::endl << "Se incrementa el ángulo" << std::endl; 
            if (seleccionAngulo == ALFA)
               luzDireccional->variarAnguloAlpha(VARIACION); 
            else 
               luzDireccional->variarAnguloBeta(VARIACION); 
         }
      break;
      case '<' : 
         if (modoVisualizar=ILUMINACION) {
            variacionAngulo=DECREMENTA; 
            std::cout << std::endl << "Se decrementa el ángulo" << std::endl; 
            if (seleccionAngulo == ALFA)
               luzDireccional->variarAnguloAlpha(-VARIACION); 
            else 
               luzDireccional->variarAnguloBeta(-VARIACION);
         } 
      break; 
   }
   // Segundo SWITCH para que no se repitan los valores 
   switch( toupper(tecla) ) {
      // DENTRO DE SELECCIÓN DE MODO DE DIBUJADO   
      case '1' : 
         if (modoMenu=SELDIBUJADO) {
            modoDibujar=1; 
            std::cout  << std::endl << "Modo inmediato" << std::endl;  
         }
      break; 
      case '2' : 
         if (modoMenu=SELDIBUJADO) {
            modoDibujar=2; 
            std::cout  << std::endl << "Modo diferido" << std::endl;  
         }
      break; 
      // Dentro del modo de iluminación  
      // Esto da error porque A también es para ajedrez
      // Por eso he elegido F 
      case 'F' : 
         if (modoVisualizar=ILUMINACION) {
            seleccionAngulo = ALFA;  
            std::cout << std::endl << "Variación del ángulo alfa" << std::endl;
         } 
      break; 
      case 'B' : 
         if (modoVisualizar=ILUMINACION) {
            seleccionAngulo = BETA;  
            std::cout << std::endl << "Variación del ángulo beta" << std::endl; 
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

void Escena::animar() {
   if (this->animacionAutomatica)
      humanoide->animar();   
}