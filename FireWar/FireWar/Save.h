#ifndef _SAVE_H_
#define _SAVE_H_
#include <iostream>
#include <fstream>
#include <string>

#include "CJugador.h"
#include "CList_Enemigos.h"
#include "CList_Life.h"
#include "CEscenario.h"
#include "CEnemigo_1.h"
#include "Vida.h"

using namespace std;

class Save
{
private:


public:
	Save() {}
	~Save() {}
	void Guardar_Data(Cjugador*objJU,CEscenario*objEscenario,CList_Enemigos<CEnemigo>*objListaEnemigos,Life<Vida>*objListaVida)
	{
		ofstream file("Partida_guardada.txt");
		ofstream file2("Matriz_Mapa.txt");
		if (file.is_open() && file2.is_open())
		{
			file << "Informacion personaje" << endl;
			file << objJU->Retornar_x() << endl;
			file << objJU->Retornar_y() << endl;
			file << objJU->Retornar_ancho() << endl;
			file << objJU->Retornar_alto() << endl;
			file << objJU->Retornar_dx() << endl;
			file << objJU->Retornar_dy() << endl;
			file << objJU->Retornar_vida() << endl;
			file << "Informacion sobre la lista de Enemigos" << endl;
			for (int i = 0; i < objListaEnemigos->Tamano(); i++)
			{
				file << "Enemigo Nro " << i+1 << endl;
				file << objListaEnemigos->getAt(i)->Retornar_x() << endl;
				file << objListaEnemigos->getAt(i)->Retornar_y() << endl;
				file << objListaEnemigos->getAt(i)->Retornar_ancho() << endl;
				file << objListaEnemigos->getAt(i)->Retornar_alto() << endl;
				file << objListaEnemigos->getAt(i)->Retornar_dx() << endl;
				file << objListaEnemigos->getAt(i)->Retornar_dy() << endl;
				file << objListaEnemigos->getAt(i)->Retornar_tipo() << endl;
				file << objListaEnemigos->getAt(i)->Retornar_vida() << endl;
			}	
			file << "Informacion sobre la lista de vidas" << endl;
			for (int i = 0; i < objListaVida->Tamano(); i++)
			{
				file << objListaEnemigos->getAt(i)->Retornar_x() << endl;
				file << objListaEnemigos->getAt(i)->Retornar_y() << endl;
				file << objListaEnemigos->getAt(i)->Retornar_ancho() << endl;
				file << objListaEnemigos->getAt(i)->Retornar_alto() << endl;
			}
			
			file2 << "Mapa completo" << endl;
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 17; j++)
				{
					file2 << objEscenario->getMatriz()[i][j];
				}
				file2 << endl;
			}

		}
	}


};




#endif // !_SAVE_H_

