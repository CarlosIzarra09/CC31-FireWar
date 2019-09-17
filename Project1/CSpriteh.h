#pragma once

using namespace System::Drawing;

class CImagen
{
protected:
	Rectangle areaDibujo;
public:
	CImagen(Rectangle _areaDibujo) 
	{
		this->areaDibujo = _areaDibujo;
	}
	Rectangle getArea() { return this->areaDibujo; }
	Point getPosition() { return this->areaDibujo.Location; }
	void setPosicion(Point _origen) { this->areaDibujo.Location = _origen; }
	void hacerTransparente(Bitmap^ _imagen)
	{
		Color color = _imagen->GetPixel(0, 0);
		_imagen->MakeTransparent(color);
	}
	virtual void dibujar(BufferedGraphics^ _buffer, Bitmap^ _imagen)
	{
		_buffer->Graphics->DrawImage(_imagen, this->areaDibujo);
	}
};

class CSprite :public CImagen
{
	short indiceX = 0;
	short indiceY;
	short nroSI = 1;
	short nroSC = 1;

public:
	CSprite(Rectangle _areaDibujo, short _nroSI, short _nroSC, short _indiceX, short _indiceY) : CImagen(_areaDibujo) {
		this->nroSI = _nroSI;
		this->nroSC = _nroSC;
		this->indiceX = _indiceX;
		this->indiceY = _indiceY;
	}
	virtual void dibujar(BufferedGraphics^ _buffer, Bitmap^ _imagen) override {
		Rectangle recorte = obtenerRecorte(_imagen);
		_buffer->Graphics->DrawImage(_imagen, this->areaDibujo, recorte, GraphicsUnit::Pixel);



	}

	void setIndiceX(short _indiceX) {
		this->indiceX = _indiceX;
	}

	short getIndiceX() {
		return this->indiceX;
	}


	short getSC() {
		return this->nroSC;
	}

	void setSC(short _sc) {
		this->nroSC = _sc;
	}


	void setSI(short _si) {
		this->nroSI = _si;
	}


	short getSI() {
		return this->nroSI;
	}


private:
	Rectangle obtenerRecorte(Bitmap^ _imagen) {
		short Ancho = _imagen->Width / nroSI;
		short Alto = _imagen->Height;
		short x = Ancho * indiceX;
		short y = Alto / 10;
		return Rectangle(x, y, Ancho, Alto);
	}
};
