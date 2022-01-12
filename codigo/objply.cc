#include "objply.h"
#include "ply_reader.h"
 

// *****************************************************************************
//
// Clase ObjPLY (práctica 2)
//
// *****************************************************************************

ObjPLY::ObjPLY( const std::string & nombre_archivo )
{
   // leer la lista de caras y vértices
   ply::read( nombre_archivo, this->v, this->f );
   for (int i = 0; i < v.size(); i++) 
		c.push_back(Tupla3f(0.99, 0.0, 0.0));

	calcular_normales(); 

}


