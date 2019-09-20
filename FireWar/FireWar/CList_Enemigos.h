#ifndef _Lista_Enemigos_H_
#define _Lista_Enemigos_H_
#include "CList.h"
#include "CEnemigo_1.h"
class CList_Enemigos :public ListaSimple
{
public:
	CList_Enemigos() {}
	~CList_Enemigos() {}
	void Crear_Enemigos()
	{
		for (int i = 0; i < 4; i++)
		{
			CEnemigo*nuevo = new CEnemigo();
			nuevo->Cambiar_tipo(1);
			(nuevo->Retornar_tipo() == 1) ? nuevo->Cambiar_Direccion(Der) : nuevo->Cambiar_Direccion(Aba);
			addend(nuevo);
		}
	}

	void Mostrar_Enemigos(System::Drawing::Graphics ^g, System::Drawing::Image ^img, int**Matriz)
	{
		//for (int i = 0; i < Tamano(); i++)
		((CEnemigo*)getAt(0))->Mostrar(g, img, Matriz);
		((CEnemigo*)getAt(1))->Mostrar(g, img, Matriz);
		((CEnemigo*)getAt(2))->Mostrar(g, img, Matriz);		
		((CEnemigo*)getAt(3))->Mostrar(g, img, Matriz);
		Ubicar_Separados(Matriz);
	}

	void Ubicar_Separados(int**Matriz)
	{
		for (int i = 0; i < Tamano(); i++)
		{
			for (int j = 0; j < Tamano(); j++)
			{
				if (i != j && Colision_de_Enemigos(getAt(i), getAt(j)) == true && getAt(i)->Retornar_tipo()==1 && getAt(j)->Retornar_tipo() == 1)
				{
					((CEnemigo*)getAt(j))->Cambiar_Ubicado(false);
					((CEnemigo*)getAt(j))->Ubicado_Iz_De(Matriz);
				}
			}
		}
	}

	bool Colision_de_Enemigos(CBase * obj1, CBase * obj2)
	{

		System::Drawing::Rectangle Canon1 = System::Drawing::Rectangle(obj1->Retornar_x(), obj1->Retornar_y(), obj1->Retornar_ancho(), obj1->Retornar_alto());
		System::Drawing::Rectangle Canon2 = System::Drawing::Rectangle(obj2->Retornar_x(), obj2->Retornar_y(), obj2->Retornar_ancho(), obj2->Retornar_alto());

		return Canon1.IntersectsWith(Canon2);
	}

};








#endif // !_Lista_Enemigos_H_
