#pragma once
#ifndef __Driver_H__
#define __Driver_H__
#include"CEscenario.h"
#include"CJugador.h"
#include"CMODPLAY.h"
#include "CList_Life.h"
#include "CList_Enemigos.h"
#include "CPERSONAJE.h"
class CDriver
{
private:
	CEscenario * objEscenario;
	Cjugador *objJugador;
//	Life *Lista_vidas;
	//CList_Enemigos *Lista_Enemigos;
	ListaSimple<CPersonaje>*vidas;
	//ListaSimple<Cenemy>*enemigos;
	//ListBombas *olistboma;
	short contvidas = 2;
	short eenemigos = 2;
public:
	CDriver() {
		objEscenario = new CEscenario();
		//Lista_vidas = new Life();
		objJugador = new Cjugador();
		//Lista_vidas->Agregar_objetos();
		vidas = new ListaSimple<CPersonaje>();
		//Lista_Enemigos = new CList_Enemigos();
		//Lista_Enemigos->Crear_Enemigos();
		
	
	int y = 15;
		for (int i = 0; i < contvidas; i++)
		{
			this->vidas->addend(CPersonaje(860, y, 50, 50, 1, 1, 0, 0));
			y += 55;
		}
	/*	for (int i = 0; i < eenemigos; i++)
		{
			this->enemigos->addend(Cenemy());
		}*/

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
	void dibujar(Graphics^g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpDestruible, Bitmap^bmpjugador, Bitmap ^vida)
	{
		objEscenario->PintarBase(g, bmpBase);
		objEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);

		objJugador->Mover_Jugador();
		objJugador->Dibujar_Jugador(g, bmpjugador, objEscenario->getMatriz());
		//Lista_vidas->Mostrar_objetos(g, vida);
		for (short i = 0; i < contvidas; i++) {
			vidas->getAt(i).dibujar(g, vida);
		}
		/*for (int i = 0; i < eenemigos; i++)
		{
			enemigos->getAt(i).Dibujar(g, bmpSlime, objEscenario->getMatriz());
			enemigos->getAt(i).animar();
		}*/
	
			


		//Lista_Enemigos->Mostrar_Enemigos(g, bmpSlime, objEscenario->getMatriz());

		//olistboma->dibujar_una_bomba(g, bmpbomba, bmpExplosion, oJugador->getX(), oJugador->gety(), obEs->getMatriz());
	}
	Cjugador *getoJugador()
	{
		return objJugador;
	}



};

#endif
