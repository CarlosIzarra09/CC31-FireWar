#ifndef _CMODPLAY_H__

#define _CMODPLAY_H__
#include"CList.h"
#include"Power.h"
using namespace std;

class ListBombas
{
public:
	ListBombas()
	{
		total_Bomb = 1;
	}
	~ListBombas(){}

	void crear_bomba(int x, int y)
	{
		if (listbom->size()<total_Bomb)
		{
			this->listbom->append(new CPower(x,y));
		}
	}
	void dibujar_una_bomba(Graphics^g, Bitmap^bmpBomba,Bitmap^bmpExplosion, int xJugador, int yJugador, int**matriz)
	{
		for (int i = 0; i < listbom->size(); i++)
		{
			switch (listbom->getAt(i)->getEstado())
			{
			case Estado::normal:
				listbom->getAt(i)->dibujarPoder(g, bmpBomba, xJugador, yJugador, matriz);
				listbom->getAt(i)->getEstado();
				break;
			case Estado::explosion:
				listbom->getAt(i)->DibujarExplosion(g, bmpExplosion, matriz);
				listbom->getAt(i)->animarexplosion();
				break;
			case Estado::desparecer:
				listbom->DeletePos(i);
				break;
			}
		}
	}
private:

	ListaSimple<CPower*>*listbom;
	int total_Bomb;
};


#endif // !_CMODPLAY_H__

