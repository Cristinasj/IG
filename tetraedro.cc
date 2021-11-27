#include "aux.h"
#include "malla.h"
#include "tetraedro.h"

Tetraedro::Tetraedro()
{
   float lado = 100.0; 

   // inicializar la tabla de vértices
	
	v.push_back(TuplaG3<float>(lado/2,0,cos(60.0*PI/180)*lado));
	v.push_back(TuplaG3<float>(-lado/2,0,cos(60.0*PI/180)*lado));
	v.push_back(TuplaG3<float>(0,0,-lado));
	v.push_back(TuplaG3<float>(0,lado,0));
	
   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
	 f.push_back(TuplaG3<unsigned>(0, 2, 1));
	 f.push_back(TuplaG3<unsigned>(0, 1, 3));
	 f.push_back(TuplaG3<unsigned>(2, 0, 3));
	 f.push_back(TuplaG3<unsigned>(1, 2, 3));

	// Inicializar el array de colores para los vértices 
    
}

