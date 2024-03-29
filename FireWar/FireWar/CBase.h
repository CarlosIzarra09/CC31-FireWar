#ifndef __Base_H__
#define __Base_H__

class CBase
{
protected:
	int x, y, dx, dy, ancho, alto, indice_X, indice_Y,vida;
	int Tipo;
	bool desaparecer;

public:
	CBase() { desaparecer = false; }
	~CBase(){}
	void Cambiar_x(int nuevo) { x = nuevo; }
	void Cambiar_y(int nuevo) { y = nuevo; }
	void Cambiar_dx(int nuevo) { dx = nuevo; }
	void Cambiar_dy(int nuevo) { dy = nuevo; }
	void Cambiar_alto(int nuevo) { alto = nuevo; }
	void Cambiar_ancho(int nuevo) { ancho = nuevo; }
	void Cambiar_tipo(int nuevo) { Tipo = nuevo; }
	void Cambiar_vida(int nuevo) { vida = nuevo; }
	void Cambiar_desaparecer(bool nuevo) { desaparecer = nuevo; }

	int Retornar_x() { return x; }
	int Retornar_y() { return y; }
	int Retornar_dx() { return dx; }
	int Retornar_dy() { return dy; }
	int Retornar_alto() { return alto; }
	int Retornar_ancho() { return ancho; }
	int Retornar_tipo() { return Tipo; }
	int Retornar_vida() { return vida; }
	bool Retornar_desaparecer() {return desaparecer; }

	virtual void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Image ^img) {} // POR QUE TODAS LAS CLASES SE TIENEN QUE MOSTRAR
	virtual void Mover(System::Drawing::Graphics ^g) {}

};









#endif
