#ifndef _CEnemigo_H_
#define _CEnemigo_H_
#include "CBase.h"
#include <ctime>
#include "CEscenario.h"

using namespace System::Drawing;
enum Situacion_Enemigo {Normal,Muerto};
enum Direccion_Enemigo{Arr,Aba,Izq,Der};
class CEnemigo :public CBase
{
private:
	int i, j;
	bool ubicado;
	Situacion_Enemigo Estado;
	Direccion_Enemigo Direc;
public:
	CEnemigo()
	{
		srand(time(NULL));
		i = rand() % 13 + 1; //13
		j = rand() % 13 + 2; //14
		x = 750;
		y = 420;
		dx = 5;
		indice_X = indice_Y = 0;
		ancho = 204 / 3;
		alto = 238 / 4;
		ubicado = false;
		Estado = Normal;
		Direc=Der;
	}
	~CEnemigo(){}

	void Ubicado_Iz_De(int **matriz)
	{
		while ((matriz[i][j-1] != 2 || matriz[i][j] != 2 || matriz[i][j + 1] != 2)&& i<14 && ubicado ==false)
		{
			j++;
			if (j == 15)
			{
				i++;
				j = 0;
			}
			if (i >= 14) break;
			x = j * 50;
			y = i * 50;
		}
	}


	void Mostrar(Graphics ^g, Image ^bmpslime, int **matriz)
	{
		Rectangle PorcionAusar = Rectangle(indice_X*ancho, indice_Y*alto, ancho, alto);
		Ubicado_Iz_De(matriz);
		switch (Direc)
		{
		case Arriba:indice_Y = 3; break;
		case Abajo:indice_Y=0; break;
		case Derecha:indice_Y=2; break;
		case Izquierda:indice_Y= 1; break;
		}

		indice_X++;
		if (indice_X == 3)
			indice_X = 0;

		
		Rectangle Aumento = Rectangle(x, y, 50, 50);
		g->DrawImage(bmpslime,Aumento,PorcionAusar,GraphicsUnit::Pixel);
		ubicado = true;
		Mover_Iz_Der(matriz);

	}

	void Mover_Iz_Der(int**matriz)
	{
		x += dx;
		if (matriz[y / 50][(x + 50) / 50] == 3 || matriz[y / 50][(x + 50) / 50] == 1)
		{
			Direc = Izq;
			dx *= -1;
		}

		if (matriz[y / 50][(x -10) / 50] == 3 || matriz[y / 50][(x -10) / 50] == 1)
		{
			Direc = Der;
			dx *= -1;
		}
	}
};




#endif // !

