#pragma once
#ifndef __Driver_H__
#define __Driver_H__
#include"CEscenario.h"
#include"Cjugador.h"
#include"CMODPLAY.h"
#include "CList_Life.h"
class CDriver
{
public:
	CDriver() {
		obEs = new CEsenario();
		Lista_vidas = new Life();
		oJugador = new Cjugador(50, 50);
		Lista_vidas->Agregar_objetos();
	}
	~CDriver() {}
	void CambiarNivel()
	{
		obEs->generaMatriz();
	}
	/*void add_bomba()
	{
		olistboma->crear_bomba(oJugador->getX(), oJugador->gety());
	}*/
	void dibujar(Graphics^g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpDestruible, Bitmap^bmpjugador, Image ^vida)
	{
		obEs->PintarBase(g, bmpBase);
		obEs->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpjugador, obEs->getMatriz());
		Lista_vidas->Mostrar_objetos(g, vida);
		//olistboma->dibujar_una_bomba(g, bmpbomba, bmpExplosion, oJugador->getX(), oJugador->gety(), obEs->getMatriz());
	}
	Cjugador *getoJugador()
	{
		return oJugador;
	}
private:
	CEsenario * obEs;
	Cjugador *oJugador;
	Life *Lista_vidas;
	//ListBombas *olistboma;
};

#endif
