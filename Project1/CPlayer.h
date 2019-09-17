#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#include"CSpriteh.h"

class CPersonaje
{
protected:
	CSprite * imagen;

	short x, y, ancho, alto, si, sc, indiceX, indiceY;
	bool encendido = false;

public:
	CPersonaje(short _x, short _y, short _ancho, short _alto, short _SI, short _SC, short _indiceX, short _indiceY)
	{
		this->x = _x;
		this->y = _y;
		this->ancho = _ancho;
		this->alto = _alto;
		this->si = _SI;
		this->sc = _SC;
		this->indiceX = _indiceX;
		this->indiceY = _indiceY;
	}
	~CPersonaje()
	{
		delete this->imagen;
	}
	Point getPosicion() {
		return this->imagen->getPosicion();
	}

	void dibujar(BufferedGraphics^ _buffer, Bitmap^ _imagen) {


		this->imagen = new CSprite(Rectangle(x, y, ancho, alto), si, sc, indiceX, indiceY);
		this->imagen->dibujar(_buffer, _imagen);
	}


	short getX() {
		return this->x;
	}

	short getY() {
		return this->y;
	}



	short getIndiceX() {
		return this->indiceX;
	}

	short getIndiceY() {
		return this->indiceY;
	}

	void setAncho(short _ancho) {
		this->ancho = _ancho;
	}
	void setAlto(short _alto) {
		this->alto = _alto;
	}

	void setX(short _x) {
		this->x = _x;
	}

	void setY(short _y) {
		this->y = _y;
	}

	short getSC() {
		return this->sc;
	}

	void setSC(short _sc) {
		this->sc = _sc;
	}


	void setSI(short _si) {
		this->si = _si;
	}


	short getSI() {
		return this->si;
	}

	void setIndiceX(short _indiceX) {
		this->indiceX = _indiceX;
	}

	void setIndiceY(short _indiceY) {
		this->indiceY = _indiceY;
	}

	bool getEncendido() {

		return this->encendido;
	}

	void setEncendido(bool _a) {
		this->encendido = _a;
	}


	Rectangle getArea() {

		return Rectangle(x, y, ancho, alto);

	}


};

#endif // !__CPLAYER_H__

