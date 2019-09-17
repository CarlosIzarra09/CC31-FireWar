#pragma once
#ifndef __ESCENARIO_H__
#define __ESCENARIO_H__
#include<ctime>
#include<stdlib.h>
#define fil 15
#define col 17
using namespace System::Drawing;
class CEsenario
{

private:
	int **matriz;
public:
	CEsenario()
	{
		matriz = new int *[fil];
	}
	~CEsenario();
	void generaMatriz() {
		for (int i = 0; i < fil; i++)
		{
			matriz[i] = new int[col];
		}
		for (int i = 0; i < fil; i++)
			for (int j = 0; j < col; j++)
			{
				if (i == 0 || j == 0 || i == fil-1 || j == col-1)
					matriz[i][j] = 1;
				else
				{
					if (i % 2 == 0 && j % 2 == 0)
					{
						matriz[i][j] = 1;
					}
					else
					{
						if ((i == 1 && (j == 1 || j == 2)) || (j == 1 && i == 2) || (i == fil - 2 && (j == col - 3 || j == col - 2)) || (i == fil - 3 && j == col - 2))
							matriz[i][j] = 0;
						else
						{
							matriz[i][j] = rand() % 2 + 2;
						}
					}
				}

			}
		{

		}
	}
	void PintarBase(Graphics^g, Bitmap^bmpBase)
	{
		int X, Y = 0;
		for (int i = 0; i < fil; i++)
		{
			X = 0;
			for (int j = 0; j < col; j++)
			{
				if (matriz[i][j] == 0|| matriz[i][j]==2)
					g->DrawImage(bmpBase, X, Y, 50, 50);
				X += 50;
			}
			Y += 50;
		}
		
	}
	void PintarMatriz(Graphics^g, Bitmap^bmpSolido, Bitmap^bmpDestruible)
	{
		int X, Y = 0;
		for (int i = 0; i < fil; i++)
		{
			X = 0;
			for (int j = 0; j < col; j++)
			{
				if (matriz[i][j] == 1)
					g->DrawImage(bmpSolido, X, Y, 50, 50);
				else
				{
					if (matriz[i][j] == 3)
						g->DrawImage(bmpDestruible, X, Y, 50, 50);
				}
				X += 50;
			}
			Y += 50;
		}

	}
	int **getMatriz()
	{
		return matriz;
	}
};
#endif // !_ESCENARIO__
