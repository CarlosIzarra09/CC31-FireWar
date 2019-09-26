#include "CList.h"
#ifndef _LIFE_H_
#define _LIFE_H_
#include "CList.h"
#include "Vida.h"


template<typename T>
class Life :public ListaSimple<T>
{

public:
	Life() {}
	~Life() {}


	void Mostrar_objetos(System::Drawing::Graphics ^g, System::Drawing::Image ^img)
	{
		for (int i = 0; i < Tamano(); i++)
			getAt(i)->Mostrar(g, img);
	}

	void Eliminar_Elementos()
	{
		for (int i = 0; i < Tamano(); i++)
		{
				if (getAt(i)->Retornar_desaparecer() == true)
			{
				DeletePos(i);
			}
		}
	}

};






#endif // !

