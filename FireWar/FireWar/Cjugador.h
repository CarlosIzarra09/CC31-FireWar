#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include"CEscenario.h"
#include "CBase.h"

using namespace System::Drawing;

enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguno };

class Cjugador :public CBase
{
protected:
	
	Direccion direcciones;
	Direccion ultima;

	Rectangle CDI;
	Rectangle CAA;


public:
	Cjugador()
	{
		//posicion
		x = 50;
		y = 50;
		//movimiento
		dx = 0;
		dy = 0;
		//sprites
		ancho = 51;
		alto = 51;
		indice_X = 0;
		indice_Y = 0;

		direcciones = Direccion::Ninguno;
		ultima = Direccion::Abajo;
	}
	~Cjugador(){}
	void setDirecciones(Direccion direcciones)
	{
		this->direcciones = direcciones;
	}

	void validarMovimiento(int **matriz)
	{
			

		int X, Y = 0;
		for (int i = 0; i < fil; i++)
		{
			X = 0;
			for (int j = 0; j < col; j++)
			{
				Rectangle c1 = Rectangle(X, Y, 50, 50);
				if (matriz[i][j] == 1||matriz[i][j] == 3)
				{
					if (CDI.IntersectsWith(c1))dx = 0;
					
					if (CAA.IntersectsWith(c1))dy = 0;
						

				}
				X += 50;
			}
			Y += 50;
		}
		
	}

	void Dibujar_Jugador(Graphics^g, Image^bmpJugador,int**matriz)
	{
		
		//Area del personaje para que no se exceda de los cubos
		CDI = Rectangle(x + 12+ dx, y + 25,(ancho-25),(alto-25));
		CAA = Rectangle(x + 12, y + 25 + dy, (ancho - 25), (alto - 25));
		//
		g->DrawRectangle(Pens::Transparent, CDI);
		g->DrawRectangle(Pens::Transparent, CAA);

		//recorre la matriz y y hace que dx y dy sean 0 si hay colision con cubos solido
		validarMovimiento(matriz);

		Rectangle PorcionAusar = Rectangle(indice_X*ancho, indice_Y*alto, ancho, alto);
		Rectangle Aumento = Rectangle(x, y, 60, 60);
		g->DrawImage(bmpJugador, Aumento, PorcionAusar, GraphicsUnit::Pixel);

		x += dx;
		y += dy;
	}
	void Mover_Jugador()
	{
		
		//direcciones == Derecha ? alto = 47 : alto=50;
		
			switch (direcciones)
			{
			case Direccion::Arriba:
				indice_Y = 3;

				indice_X++;
				if (indice_X == 4)
					indice_X = 0;

				dy = -10; dx = 0;

				ultima = Arriba;
				break;
			case Direccion::Abajo:
				indice_Y = 0;

				indice_X++;
				if (indice_X == 4)
					indice_X = 0;

				dy = 10; dx = 0;

				ultima = Abajo;
				break;
			case Direccion::Izquierda:
				indice_Y = 1;

				indice_X++;
				if (indice_X == 4)
					indice_X = 0;

				dx = -10; dy = 0;

				ultima = Izquierda;
				break;
			case Direccion::Derecha:
				indice_Y = 2;

				indice_X++;
				if (indice_X == 4)
					indice_X = 0;

				dx = 10; dy = 0;

				ultima = Derecha;
				break;
			case Ninguno:
				dx = dy = 0;
				if (ultima == Direccion::Abajo)
				{
					indice_X = 0;
					indice_Y = 0;
				}
				if (ultima == Direccion::Arriba)
				{
					indice_X = 0;
					indice_Y = 3;
				}
				if (ultima == Direccion::Derecha)
				{
					indice_X = 0;
					indice_Y = 2;
				}
				if (ultima == Direccion::Izquierda)
				{
					indice_X = 0;
					indice_Y = 1;
				}

				; break;
			}
			
	}




};

#endif // !__JUGADOR_H__


