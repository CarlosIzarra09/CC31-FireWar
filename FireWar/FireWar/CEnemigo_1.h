#ifndef _CEnemigo_H_
#define _CEnemigo_H_
#include "CBase.h"

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
		dx = dy = 5;
		
		indice_X = indice_Y = 0;
		ancho = 204 / 3;
		alto = 238 / 4;
		ubicado = false;
		Estado = Normal;
		
	}
	~CEnemigo(){}

	void Cambiar_Fila_Columna()
	{
		i = rand() % 13 + 1; //13
		j = rand() % 13 + 2;
	}


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

	void Ubicado_Arr_Abaj(int **matriz)
	{
		while ((matriz[i-1][j] != 2 || matriz[i][j] != 2 || matriz[i+1][j] != 2) && j < 15 && ubicado == false)
		{
			i++;
			if (i == 14)
			{
				j++;
				i = 1;
			}
			if (j >= 15)break;
			x = j * 50;
			y = i * 50;
		}
	}


	void Mostrar(Graphics ^g, Image ^bmpslime, int **matriz)
	{
		

		Rectangle PorcionAusar = Rectangle(indice_X*ancho, indice_Y*alto, ancho, alto);

		(Tipo == 1) ? Ubicado_Iz_De(matriz): Ubicado_Arr_Abaj(matriz);
		
		

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
		
		(Tipo==1)? Mover_Iz_Der(matriz): Mover_Arr_Abajo(matriz);

	}

	void Mover_Iz_Der(int**matriz)
	{
		x += dx;
		if (matriz[y / 50][(x + 50) / 50] == 3 || matriz[y / 50][(x + 50) / 50] == 1)
		{
			Direc = Izq;
			dx = -5;
		}

		if (matriz[y / 50][(x -10) / 50] == 3 || matriz[y / 50][(x -10) / 50] == 1)
		{
			Direc = Der;
			dx = 5;
		}
	}

	void Mover_Arr_Abajo(int **matriz)
	{
		y += dy;
		if (matriz[(y+50)/50][x/50] == 3 || matriz[(y+50)/50][x/50] == 1)
		{
			Direc = Arr;
			dy = -5;
		}

		if (matriz[y / 50][x / 50] == 3 || matriz[y / 50][x / 50] == 1)
		{
			Direc = Aba;
			dy = 5;
		}
	}

	void Cambiar_Direccion(Direccion_Enemigo nuevo)
	{
		Direc = nuevo;
	}

	void Cambiar_Ubicado(bool nuevo)
	{
		ubicado = nuevo;
	}
};




#endif // !

