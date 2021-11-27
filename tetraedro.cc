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
	 f.push_back(TuplaG3<unsigned>(0, 1, 2));
	 f.push_back(TuplaG3<unsigned>(0, 3, 1));
	 f.push_back(TuplaG3<unsigned>(2, 3, 0));
	 f.push_back(TuplaG3<unsigned>(1, 3, 2));

	// Inicializar los arrays de colores para los vértices 
	// Modo puntos 
	for (int i = 0; i < v.size(); i++) 
		cpuntos.push_back(Tupla3f(0.99, 0.0, 0.0));
	// Modo lineas 
	for (int i = 0; i < v.size(); i++) 
		clineas.push_back(Tupla3f(0.0, 0.99, 0.0));
	// Modo relleno  
	for (int i = 0; i < v.size(); i++) 
		crelleno.push_back(Tupla3f(0.0, 0.0, 0.99));
}

