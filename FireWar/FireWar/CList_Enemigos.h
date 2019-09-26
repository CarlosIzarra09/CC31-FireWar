#ifndef _Lista_Enemigos_H_
#define _Lista_Enemigos_H_
#include "CList.h"
#include "CEnemigo_1.h"

template <typename T>
class CList_Enemigos :public ListaSimple<T>
{
public:
	CList_Enemigos() {}
	~CList_Enemigos() {}
	void Crear_Enemigos()
	{
		for (int i = 0; i < 2; i++)
		{
			///
			CEnemigo*nuevo = new CEnemigo();
			nuevo->Cambiar_tipo(2);
			CEnemigo*nuevo2 = new CEnemigo();
			nuevo2->Cambiar_tipo(1);
			nuevo->Cambiar_Direccion(Aba);
		    nuevo2->Cambiar_Direccion(Der);
			addend(nuevo);
			addend(nuevo2);
		}
	}

	void Mostrar_Enemigos(System::Drawing::Graphics ^g, System::Drawing::Image ^img, int**Matriz)
	{
		for (int i = 0; i < Tamano(); i++)
		((CEnemigo*)getAt(i))->Mostrar(g, img, Matriz);
		
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
					((CEnemigo*)getAt(j))->Cambiar_Fila_Columna();
					((CEnemigo*)getAt(j))->Ubicado_Iz_De(Matriz);
				}

				if (i != j && Colision_de_Enemigos(getAt(i), getAt(j)) == true && getAt(i)->Retornar_tipo() == 2 && getAt(j)->Retornar_tipo() == 2)
				{
					((CEnemigo*)getAt(j))->Cambiar_Ubicado(false);
					((CEnemigo*)getAt(j))->Cambiar_Fila_Columna();
					((CEnemigo*)getAt(j))->Ubicado_Arr_Abaj(Matriz);
				}



			}
		}
	}

	bool Colision_de_Enemigos(T * obj1, T * obj2)
	{

		System::Drawing::Rectangle Canon1 = System::Drawing::Rectangle(obj1->Retornar_x(), obj1->Retornar_y(), obj1->Retornar_ancho(), obj1->Retornar_alto());
		System::Drawing::Rectangle Canon2 = System::Drawing::Rectangle(obj2->Retornar_x(), obj2->Retornar_y(), obj2->Retornar_ancho(), obj2->Retornar_alto());

		return Canon1.IntersectsWith(Canon2);
	}

};








#endif // !_Lista_Enemigos_H_

