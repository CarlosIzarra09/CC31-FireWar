#ifndef _Lista_bala_H
#define _Lista_bala_H
#include "CList.h"
#include"CEscenario.h"
#include "CBala.h"

template <typename T>
class Lista_Bala :public ListaSimple<T>
{
private:
	System::Drawing::Rectangle Cuerpo_Bala;
	

public:
	Lista_Bala() {}
	~Lista_Bala() {}
	

	void Mostrar_Balas(System::Drawing::Graphics ^g, System::Drawing::Image ^img, int **matriz)
	{
		for (int i = 0; i < Tamano(); i++)
		{
			getAt(i)->Mostrar(g, img);
			getAt(i)->Mover();
		}
		validarMovimiento_Bala(matriz);
		Eliminar_Elementos();
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


	void validarMovimiento_Bala(int **matriz)
	{
		int X, Y = 0;
		for (int i = 0; i < fil; i++)
		{
			X = 0;
			for (int j = 0; j < col; j++)
			{
				Rectangle c1 = Rectangle(X, Y, 50, 50);
				if (matriz[i][j] == 1 || matriz[i][j] == 3)
				{

					for (int k = 0; k < Tamano(); k++)
					{
						Cuerpo_Bala = System::Drawing::Rectangle(getAt(k)->Retornar_x(), getAt(k)->Retornar_y(), 25, 25);
						if (Cuerpo_Bala.IntersectsWith(c1))
						{
							getAt(k)->Cambiar_desaparecer(true);
							if(matriz[i][j] == 3)matriz[i][j] =2;
						}
						

					}
					


				}
				X += 50;
			}
			Y += 50;
		}

	}




};


#endif // !_vector_bala_H

