#ifndef _Bala_H_
#define _Bala_H_
#include "CBase.h"
using namespace System::Drawing;




class CBala :public CBase
{

	
public:
	CBala() 
	{
		indice_X = indice_Y = 0;
		dx = dy = 5;
		ancho = 375 / 4;
		alto = 73;
	}
	~CBala(){}
	void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Image ^img)
	{
		Rectangle PorcionAusar = Rectangle(indice_X*ancho, indice_Y*alto, ancho, alto);

		indice_X++;
		if (indice_X == 4)
			indice_X = 0;


		
		Rectangle Aumento = Rectangle(x, y, 25, 25);
		g->DrawImage(img, Aumento, PorcionAusar, GraphicsUnit::Pixel);
	
	
	}
	void Mover() 
	{
		switch (Tipo)
		{
		case 1:y -= dy;
			break;
		case 2:y += dy;
			break;
		case 3:x -= dx;
			break;
		case 4:x += dx;
			break;
		}
	}


};





#endif // !Bala

