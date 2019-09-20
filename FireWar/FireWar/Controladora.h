#pragma once
#ifndef __Driver_H__
#define __Driver_H__
#include"CEscenario.h"
#include"CJugador.h"
#include"CMODPLAY.h"
#include "CList_Life.h"
class CDriver
{
private:
	CEscenario * objEscenario;
	Cjugador *objJugador;
	Life *Lista_vidas;
	//ListBombas *olistboma;
public:
	CDriver() {
		objEscenario = new CEscenario();
		Lista_vidas = new Life();
		objJugador = new Cjugador();
		Lista_vidas->Agregar_objetos();
	}
	~CDriver() {}
	void CambiarNivel()
	{
		objEscenario->generaMatriz();
	}
	/*void add_bomba()
	{
		olistboma->crear_bomba(oJugador->getX(), oJugador->gety());
	}*/
	void dibujar(Graphics^g, Image^bmpBase, Image^bmpSolido, Image^bmpDestruible, Image^bmpjugador, Image ^vida)
	{
		objEscenario->PintarBase(g, bmpBase);
		objEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		
		objJugador->Mover_Jugador();
		objJugador->Dibujar_Jugador(g, bmpjugador, objEscenario->getMatriz());
		Lista_vidas->Mostrar_objetos(g, vida);
		//olistboma->dibujar_una_bomba(g, bmpbomba, bmpExplosion, oJugador->getX(), oJugador->gety(), obEs->getMatriz());
	}
	Cjugador *getoJugador()
	{
		return objJugador;
	}

};

#endif
