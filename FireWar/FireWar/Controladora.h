#pragma once
#ifndef __Driver_H__
#define __Driver_H__
#include"CEscenario.h"
#include"CJugador.h"
#include"CMODPLAY.h"
#include "CList_Life.h"
#include "CList_Enemigos.h"
#include "Clist_Bala.h"
#include "Save.h"


class CDriver
{
private:
	CEscenario * objEscenario;
	Cjugador *objJugador;
    Life<Vida> *Lista_vidas;
	CList_Enemigos<CEnemigo> *Lista_Enemigos;
	Save *objGuardar;

public:
	CDriver() {
		objJugador = new Cjugador();
		objEscenario = new CEscenario();
		Lista_vidas = new Life<Vida>();
		objGuardar = new Save();
		Lista_Enemigos = new CList_Enemigos<CEnemigo>();
		
		
		

		//agregar vidas a la lista
		int y = 15;
		for (int i = 0; i < objJugador->Retornar_vida(); i++)
		{
			Vida*obj = new Vida();
			obj->Cambiar_x(860);
			obj->Cambiar_ancho(50);
			obj->Cambiar_alto(50);
			obj->Cambiar_y(y);
			Lista_vidas->addend(obj);
			y += 55;
		}

		//agregamos enemigos a la lista
		for (int i = 0; i < 2; i++)
		{
			CEnemigo*nuevo = new CEnemigo();
			nuevo->Cambiar_tipo(2);
			CEnemigo*nuevo2 = new CEnemigo();
			nuevo2->Cambiar_tipo(1);
			nuevo->Cambiar_Direccion(Aba);
			nuevo2->Cambiar_Direccion(Der);
			Lista_Enemigos->addend(nuevo);
			Lista_Enemigos->addend(nuevo2);
		}


	}
	~CDriver() {}
	void CambiarNivel()
	{
		objEscenario->generaMatriz();
	}
	
	void dibujar(Graphics^g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpDestruible, Bitmap^bmpjugador, Bitmap ^vida, Bitmap ^bmpslime, Bitmap ^bmpbala)
	{
		objEscenario->PintarBase(g, bmpBase);
		objEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);

		if (objJugador->Retornar_vida() > 0)
		{
			objJugador->Mover_Jugador();
			objJugador->Dibujar_Jugador(g, bmpjugador, objEscenario->getMatriz());
		}

		Lista_vidas->Mostrar_objetos(g, vida);
		

		Lista_Enemigos->Mostrar_Enemigos(g, bmpslime, objEscenario->getMatriz());
		
		objJugador->retornar_Lista_Balas()->Mostrar_Balas(g, bmpbala, objEscenario->getMatriz());


		for (int i = 0; i < objJugador->retornar_Lista_Balas()->Tamano(); i++)
		{
			for (int j = 0; j < Lista_Enemigos->Tamano(); j++)
			{
				if (Colision_de_Enemigos_Bala(objJugador->retornar_Lista_Balas()->getAt(i), Lista_Enemigos->getAt(j)))
				{
					objJugador->retornar_Lista_Balas()->getAt(i)->Cambiar_desaparecer(true);
					Lista_Enemigos->getAt(j)->Cambiar_vida(Lista_Enemigos->getAt(j)->Retornar_vida()-1);
				}
			}
		}

		if (objJugador->Retornar_vida() > 0)
		{
			for (int j = 0; j < Lista_Enemigos->Tamano(); j++)
			{
				if (Colision_de_Personaje_Enemigo(GetJugador(), Lista_Enemigos->getAt(j)))
				{
					objJugador->Cambiar_x(50);
					objJugador->Cambiar_y(50);
					Lista_vidas->getAt(Lista_vidas->Tamano() - 1)->Cambiar_desaparecer(true);
					objJugador->Cambiar_vida(objJugador->Retornar_vida() - 1);
					
				}
			}
		}
		Lista_vidas->Eliminar_Elementos();
		
	}
	Cjugador *GetJugador()
	{
		return objJugador;
	}

	bool Colision_de_Enemigos_Bala(CBase * obj1, CBase * obj2)
	{

		System::Drawing::Rectangle Canon1 = System::Drawing::Rectangle(obj1->Retornar_x(), obj1->Retornar_y(), 25, 25);
		System::Drawing::Rectangle Canon2 = System::Drawing::Rectangle(obj2->Retornar_x(), obj2->Retornar_y(), 50, 50);

		return Canon1.IntersectsWith(Canon2);
	}

	

	bool Colision_de_Personaje_Enemigo(CBase * obj1, CBase * obj2)
	{
		System::Drawing::Rectangle Canon1 = System::Drawing::Rectangle(obj1->Retornar_x(), obj1->Retornar_y(), 51, 51);
		System::Drawing::Rectangle Canon2 = System::Drawing::Rectangle(obj2->Retornar_x(), obj2->Retornar_y(), 50, 50);

		return Canon1.IntersectsWith(Canon2);
	}

	void Guardar_Informacion()
	{
		objGuardar->Guardar_Data(objJugador,objEscenario,Lista_Enemigos,Lista_vidas);
	}
};

#endif
