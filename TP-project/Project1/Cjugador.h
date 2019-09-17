#ifndef __JUGADOR_H__
#define __JUGADOR_H__
#include<iostream>
#include"CEscenario.h"
using namespace std;
using namespace System::Drawing;
enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguno };
class Cjugador
{
public:
	Cjugador(int x, int y)
	{
		//posicion
		this->x = x;
		this->y = y;
		//movimiento
		dx = 0;
		dy = 0;
		//sprites
		ancho = 50;
		alto = 50;
		indiceX = 0;
		indiceY = 0;

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
	void DibujarJugador(Graphics^g, Bitmap^bmpJugador,int**matriz)
	{
		CDI = Rectangle(x + 12+ dx, y+25,(ancho-25),(alto-25));
		CAA = Rectangle(x + 12, y + 25 + dy, (ancho - 25), (alto - 25));

		g->DrawRectangle(Pens::Transparent, CDI);
		g->DrawRectangle(Pens::Transparent, CAA);

		validarMovimiento(matriz);

		Rectangle PorcionAusar = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
		Rectangle Aumento = Rectangle(x, y, ancho, alto);
		g->DrawImage(bmpJugador, Aumento, PorcionAusar, GraphicsUnit::Pixel);
		x += dx;
		y += dy;
	}
	void moverJugador(Graphics^g, Bitmap^bmpJugador,int**matriz)
	{
		//direcciones == Derecha ? alto = 47 : alto=50;
		switch (direcciones)
		{
		case Direccion::Arriba:
			indiceY = 3;
			if (indiceX >= 1 && indiceX < 3)
				indiceX++;
			else
				indiceX = 1;
			dx = 0;
			dy = -10;
			ultima = Arriba;
			break;
		case Direccion::Abajo:
			indiceY = 0;
			if (indiceY >= 1 && indiceY < 3)
				indiceY++;
			else
				indiceX = 1;
			dx = 0;
			dy = 10;
			ultima = Abajo;
			break;
		case Direccion::Izquierda:
			indiceY = 1;
			if (indiceX >= 1 && indiceX < 3)
				indiceX++;
			else
				indiceX = 1;
			dx = -10;
			dy = 0;
			ultima = Izquierda;
			break;
		case Direccion::Derecha:
			indiceY = 2;
			if (indiceX >= 1 && indiceX < 3)
				indiceX++;
			else
				indiceX = 1;
			dx = 10;
			dy = 0;
			ultima = Derecha;
			break;
		case Ninguno:
			dx = dy = 0;
			if (ultima == Direccion::Abajo)
			{
				indiceX = 0;
				indiceY = 0;
			}
			if (ultima == Direccion::Arriba)
			{
				indiceX = 3;
				indiceY = 3;
			}
			if (ultima == Direccion::Derecha)
			{
				indiceX = 0;
				indiceY = 2;
			}
			if (ultima == Direccion::Izquierda)
			{
				indiceX = 0;
				indiceY = 1;
			}

			break;
		default:
			break;
		}
		DibujarJugador(g, bmpJugador,matriz);
	}
	int getX()
	{
		return x + 2*3;
	}
	int gety()
	{
		return y+15+dy;
	}
private:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	Direccion direcciones;
	Direccion ultima;

	Rectangle CDI;
	Rectangle CAA;

};

#endif // !__JUGADOR_H__


