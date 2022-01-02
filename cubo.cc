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

	std::vector<Tupla3f> nc; 
	// Se calculan las normales de las caras para usarlos más tarde en los vértices
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
