#ifndef __POWER_H__
#define __POWER_H__
#include"CEscenario.h"
enum Estado{normal,explosion,desparecer};
class CPower
{
public:
	CPower(int x, int y)
	{
		this->x = x;
		this->y = y;
		estado = Estado::normal;


		ancho = 66 / 3;
		alto = 24;


		anchoex = 80/4;
		altoex = 160 / 8;
		indiceEX = 0;
		indiceEY = 0;

		indiceX = 0;
		timepo_de_espera = 0;
	}
	~CPower() {}
	bool validarLugar(int xjuga, int yjuga, int **matriz)
	{
		if (matriz[yjuga / 50][xjuga / 50] == 0 || matriz[yjuga / 50][xjuga / 50] == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void dibujarPoder(Graphics^g, Bitmap^bmpPoder, int xjuga, int yjuga, int **matriz) {
		if (validarLugar(xjuga,yjuga,matriz) == true)
		{
			Rectangle PorcionUsar = Rectangle(indiceX *ancho, 0, ancho, alto);
			Rectangle aumento = Rectangle(x, y, 40, 40);
			g->DrawImage(bmpPoder, aumento, PorcionUsar, GraphicsUnit::Pixel);
		}
		if (timepo_de_espera == 6)
		{
			estado = Estado::explosion;
		}
	}
	void animar()
	{
		if (indiceX >= 0 && indiceX < 2)
		{
			indiceX++;
		}
		else
		{
			timepo_de_espera++;
			indiceX = 0;
		}
	}
	void DibujarExplosion(Graphics ^g, Bitmap ^bmpExplosionCentro, int **matriz) {

		Rectangle porcionUsarCentro = Rectangle(indiceEX*anchoex, indiceEY*altoex, anchoex, altoex); // indiceY=0
		Rectangle centro = Rectangle(x, y, 50, 50);
		g->DrawImage(bmpExplosionCentro, centro, porcionUsarCentro, GraphicsUnit::Pixel);
		if (matriz[y / 50][(x - 50) / 50] != 1) {
			Rectangle porcionUsarIzquierda = Rectangle(indiceEX*anchoex, indiceEY + 2 * altoex, anchoex, altoex); //indiceY = 2
			Rectangle izquierda = Rectangle(x - 50, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, izquierda, porcionUsarIzquierda, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x - 50) / 50] == 3) { matriz[y / 50][(x - 50) / 50] = 2; }
		}


		if (matriz[y / 50][(x + 50) / 50] != 1) {
			Rectangle porcionUsarDerecha = Rectangle(indiceEX*anchoex, indiceEY + 4 * altoex, anchoex, altoex); //indiceY = 4
			Rectangle derecha = Rectangle(x + 50, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, derecha, porcionUsarDerecha, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x + 50) / 50] == 3) { matriz[y / 50][(x + 50) / 50] = 2; }

		}
		if (matriz[y / 50][(x + 50) / 50] != 1) {
			Rectangle porcionUsarPuntaDerecha = Rectangle(indiceEX*anchoex, indiceEY + 3 * altoex, anchoex, altoex); //indiceY = 3
			Rectangle Puntaderecha = Rectangle(x + 100, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, Puntaderecha, porcionUsarPuntaDerecha, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x + 100) / 50] == 3 && matriz[y / 50][(x + 50) / 50] != 1)
			{

				matriz[y / 50][(x + 100) / 50] = 2;
			}
		}

		if (matriz[y / 50][(x - 50) / 50] != 1) {
			Rectangle porcionUsarPuntaIzquierda = Rectangle(indiceEX*anchoex, indiceEY + 1 * altoex, anchoex, altoex); //indiceY = 1
			Rectangle Puntaizquierda = Rectangle(x - 100, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, Puntaizquierda, porcionUsarPuntaIzquierda, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x - 100) / 50] == 3 && matriz[y / 50][(x - 50) / 50] != 1)
			{
				matriz[y / 50][(x - 100) / 50] = 2;
			}
		}

		Rectangle porcionUsarVerticales = Rectangle(indiceEX*anchoex, indiceEY + 6 * altoex, anchoex, altoex); //indiceY = 1
		Rectangle VerticalSuperior = Rectangle(x, y - 50, 50, 50);
		Rectangle VerticalInferior = Rectangle(x, y + 50, 50, 50);

		if (matriz[(y - 50) / 50][x / 50] != 1) { g->DrawImage(bmpExplosionCentro, VerticalSuperior, porcionUsarVerticales, GraphicsUnit::Pixel); }
		if (matriz[(y - 50) / 50][x / 50] == 3) { matriz[(y - 50) / 50][x / 50] = 2; }
		if (matriz[(y + 50) / 50][x / 50] != 1) { g->DrawImage(bmpExplosionCentro, VerticalInferior, porcionUsarVerticales, GraphicsUnit::Pixel); }
		if (matriz[(y + 50) / 50][x / 50] == 3) { matriz[(y + 50) / 50][x / 50] = 2; }


		if (matriz[(y - 50) / 50][x / 50] != 1) {
			Rectangle porcionUsarPuntaSuperior = Rectangle(indiceEX*anchoex, indiceEY + 5 * altoex, anchoex, altoex); //indiceY = 5
			Rectangle PuntaSuperior = Rectangle(x, y - 100, 50, 50);
			g->DrawImage(bmpExplosionCentro, PuntaSuperior, porcionUsarPuntaSuperior, GraphicsUnit::Pixel);

			if (matriz[(y - 100) / 50][x / 50] == 3 && matriz[(y - 50) / 50][x / 50] != 1) { matriz[(y - 100) / 50][x / 50] = 2; }
		}


		if (matriz[(y + 50) / 50][x / 50] != 1) {
			Rectangle porcionUsarPuntaInferior = Rectangle(indiceEX*anchoex, indiceEY + 7 * altoex, anchoex, altoex); //indiceY = 7
			Rectangle PuntaInferior = Rectangle(x, y + 100, 50, 50);
			g->DrawImage(bmpExplosionCentro, PuntaInferior, porcionUsarPuntaInferior, GraphicsUnit::Pixel);
			if (matriz[(y + 100) / 50][x / 50] == 3 && matriz[(y + 50) / 50][x / 50] != 1) {
				matriz[(y + 100) / 50][x / 50] = 2;
			}
		}
	}
	void animarexplosion()
	{
		if (indiceEX >= 0 && indiceEX < 3)
			indiceEX++;
		else
		{
			estado = Estado::desparecer;
		}
	
	}
	Estado getEstado()
	{
		return estado;
	}

private:
	int indiceEX;
	int indiceEY;
	int altoex;
	int anchoex;


private://Datos de bomba
	int x;
	int y;
	int ancho;
	int alto;
	int indiceX;
	int dx;
	int dy;
	int timepo_de_espera;
	Estado estado;
};


#endif // !__POWER_H__

