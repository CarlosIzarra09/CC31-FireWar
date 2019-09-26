#include "CList.h"
#ifndef _LIFE_H_
#define _LIFE_H_
#include "CList.h"
#include "Vida.h"

template<typename T>
class Life :public ListaSimple<T>
{
public:
	Life(){}
	~Life(){}
	void Agregar_objetos()
	{
		int y = 15;
		for (int i = 0; i < 3; i++)
		{
			Vida*obj = new Vida();
			obj->Cambiar_x(860);
			obj->Cambiar_ancho(50);
			obj->Cambiar_alto(50);
			obj->Cambiar_y(y);
			addend(obj);
			y += 55;
		}
	}

	void Mostrar_objetos(System::Drawing::Graphics ^g, System::Drawing::Image ^img)
	{
		for(int i = 0; i < Tamano();i++)
			getAt(i)->Mostrar(g, img);
		

	}


};






#endif // !

