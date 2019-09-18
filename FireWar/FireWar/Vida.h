#include "CBase.h"
#ifndef __CVIDA_H__
#define __CVIDA_H__

class Vida : public CBase 
{


public:
	Vida() {}
	~Vida() {}


	void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Image ^img)
	{
		g->DrawImage(img, x, y, ancho, alto);
	}

};





#endif
