#pragma once
#include"Controladora.h"
namespace FireWar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Jueguito
	/// </summary>
	public ref class Jueguito : public System::Windows::Forms::Form
	{
		Bitmap ^ bmpSolido = gcnew Bitmap("imagenes\\bmpSolido.png");
		Bitmap ^bmpDes = gcnew Bitmap("imagenes\\bmpDestruible.png");
		Bitmap ^bmpSuelo = gcnew Bitmap("imagenes\\bmpSuelo.png");
		Bitmap ^bmpjugador = gcnew Bitmap("imagenes\\bmpjugador.png");
		Bitmap ^bmpJbomba = gcnew Bitmap("imagenes\\bomba.png");
		Image ^bmpVida = gcnew Bitmap("imagenes\\vida.png");
	private: System::Windows::Forms::Timer^  timer1;

		CDriver * obDriver = new CDriver();
	public:
		Jueguito(void)
		{
			///transparencia
			((Bitmap^)bmpVida)->MakeTransparent(((Bitmap^)bmpVida)->GetPixel(0, 0));
			bmpjugador->MakeTransparent(bmpjugador->GetPixel(0, 0));
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Jueguito()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Jueguito::timer1_Tick);
			// 
			// Jueguito
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"Jueguito";
			this->Text = L"Jueguito";
			this->Load += gcnew System::EventHandler(this, &Jueguito::Jueguito_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Jueguito::Jueguito_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Jueguito::Jueguito_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);

		obDriver->dibujar(buffer->Graphics, bmpSuelo, bmpSolido, bmpDes, bmpjugador, bmpVida);
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void Jueguito_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		obDriver->CambiarNivel();
	}
	private: System::Void Jueguito_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch (e->KeyCode)
		{
		case Keys::Up:

			obDriver->getoJugador()->setDirecciones(Direccion::Arriba);
			break;
		case Keys::Down:

			obDriver->getoJugador()->setDirecciones(Direccion::Abajo);
			break;
		case Keys::Left:
			obDriver->getoJugador()->setDirecciones(Direccion::Izquierda);
			break;
		case Keys::Right:
			obDriver->getoJugador()->setDirecciones(Direccion::Derecha);
			break;
		default:
			break;
		}
	}
	private: System::Void Jueguito_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch (e->KeyCode)
		{
		case Keys::Space:
			//obDriver->add_bomba();
			break;
		default:
			obDriver->getoJugador()->setDirecciones(Direccion::Ninguno);
			break;
		}
	}
};
}
