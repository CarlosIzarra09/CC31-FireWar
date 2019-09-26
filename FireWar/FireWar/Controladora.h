#pragma once
#ifndef __Driver_H__
#define __Driver_H__
#include"CEscenario.h"
#include"CJugador.h"
#include"CMODPLAY.h"
#include "CList_Life.h"
#include "CList_Enemigos.h"

class CDriver
{
private:
	CEscenario * objEscenario;
	Cjugador *objJugador;
    Life<Vida> *Lista_vidas;
	CList_Enemigos<CEnemigo> *Lista_Enemigos;
	
	
	//ListBombas *olistboma;
	short contvidas = 2;
	short eenemigos = 2;
public:
	CDriver() {
		objJugador = new Cjugador();
		objEscenario = new CEscenario();
		Lista_vidas = new Life<Vida>();
		Lista_vidas->Agregar_objetos();
		Lista_Enemigos = new CList_Enemigos<CEnemigo>();
		Lista_Enemigos->Crear_Enemigos();
		

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
	void dibujar(Graphics^g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpDestruible, Bitmap^bmpjugador, Bitmap ^vida, Bitmap ^bmpslime)
	{
		objEscenario->PintarBase(g, bmpBase);
		objEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);

		objJugador->Mover_Jugador();
		objJugador->Dibujar_Jugador(g, bmpjugador, objEscenario->getMatriz());
		Lista_vidas->Mostrar_objetos(g, vida);
		
		Lista_Enemigos->Mostrar_Enemigos(g, bmpslime, objEscenario->getMatriz());

		//olistboma->dibujar_una_bomba(g, bmpbomba, bmpExplosion, oJugador->getX(), oJugador->gety(), obEs->getMatriz());
	}
	Cjugador *getoJugador()
	{
		return objJugador;
	}



};

#endif
