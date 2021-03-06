#include "aux.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(float lado)
{

   // inicializar la tabla de vértices
		v.push_back(TuplaG3<float>(lado/2,lado/2,lado/2));
	 	v.push_back(TuplaG3<float>(lado/2,lado/2,-lado/2));
		v.push_back(TuplaG3<float>(lado/2,-lado/2,lado/2));
		v.push_back(TuplaG3<float>(lado/2,-lado/2,-lado/2));
		v.push_back(TuplaG3<float>(-lado/2,lado/2,lado/2));
		v.push_back(TuplaG3<float>(-lado/2,lado/2,-lado/2));
		v.push_back(TuplaG3<float>(-lado/2,-lado/2,lado/2));
		v.push_back(TuplaG3<float>(-lado/2,-lado/2,-lado/2));

   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
	 f.push_back(TuplaG3<unsigned>(1, 0, 2));
	 f.push_back(TuplaG3<unsigned>(1, 2, 3));
	 f.push_back(TuplaG3<unsigned>(0, 4, 6));
	 f.push_back(TuplaG3<unsigned>(2, 0, 6));
	 f.push_back(TuplaG3<unsigned>(6, 4, 5));
	 f.push_back(TuplaG3<unsigned>(6, 5, 7));
	 f.push_back(TuplaG3<unsigned>(2, 6, 7));
	 f.push_back(TuplaG3<unsigned>(5, 1, 7));
	 f.push_back(TuplaG3<unsigned>(7, 1, 3));
	 f.push_back(TuplaG3<unsigned>(0, 5, 4));
	 f.push_back(TuplaG3<unsigned>(0, 1, 5));
	 f.push_back(TuplaG3<unsigned>(3, 2, 7));

	// Inicializar arrays de colores para los vértices 
	for (int i = 0; i < v.size(); i++) 
		c.push_back(Tupla3f(0.99, 0.0, 0.0));

	calcular_normales(); 
}
