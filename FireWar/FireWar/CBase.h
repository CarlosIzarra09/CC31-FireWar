#ifndef __Base_H__
#define __Base_H__

class CBase
{
protected:
	int x, y, dx, dy, ancho, alto, indice_X, indice_Y;

public:
	CBase(){}
	~CBase(){}
	void Cambiar_x(int nuevo) { x = nuevo; }
	void Cambiar_y(int nuevo) { y = nuevo; }
	void Cambiar_dx(int nuevo) { dx = nuevo; }
	void Cambiar_dy(int nuevo) { dy = nuevo; }
	void Cambiar_alto(int nuevo) { alto = nuevo; }
	void Cambiar_ancho(int nuevo) { ancho = nuevo; }
	

	int Retornar_x() { return x; }
	int Retornar_y() { return y; }
	int Retornar_dx() { return dx; }
	int Retornar_dy() { return dy; }
	int Retornar_alto() { return alto; }
	int Retornar_ancho() { return ancho; }
	

	virtual void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Image ^img) {} // POR QUE TODAS LAS CLASES SE TIENEN QUE MOSTRAR
	virtual void Mover(System::Drawing::Graphics ^g) {}

};









#endif
