#pragma once
#ifndef __Driver_H__
#define __Driver_H__
#include"CEscenario.h"
#include"Cjugador.h"
#include"CMODPLAY.h"
class CDriver
{
public:
	CDriver() {
		obEs = new CEsenario();
		oJugador = new Cjugador(50, 50);
	}
	~CDriver();
	void CambiarNivel()
	{
		obEs->generaMatriz();
	}
	/*void add_bomba()
	{
		olistboma->crear_bomba(oJugador->getX(), oJugador->gety());
	}*/
	void dibujar(Graphics^g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpDestruible, Bitmap^bmpjugador)
	{
		obEs->PintarBase(g, bmpBase);
		obEs->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpjugador, obEs->getMatriz());
		//olistboma->dibujar_una_bomba(g, bmpbomba, bmpExplosion, oJugador->getX(), oJugador->gety(), obEs->getMatriz());
	}
	Cjugador *getoJugador()
	{
		return oJugador;
	}
private:
	CEsenario * obEs;
	Cjugador *oJugador;
	//ListBombas *olistboma;
};

#endif
