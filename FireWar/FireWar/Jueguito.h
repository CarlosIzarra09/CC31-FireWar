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
		Image ^bmpSolido = gcnew Bitmap("imagenes\\bmpSolido.png");
		Image ^bmpDes = gcnew Bitmap("imagenes\\bmpDestruible.png");
		Image ^bmpSuelo = gcnew Bitmap("imagenes\\bmpSuelo.png");
		Image ^bmpjugador = gcnew Bitmap("imagenes\\bmpjugador.png");
		Image ^bmpJbomba = gcnew Bitmap("imagenes\\bomba.png");
		Image ^bmpVida = gcnew Bitmap("imagenes\\vida.png");
		Image ^bmpSlime = gcnew Bitmap("imagenes\\slimebmp_PQ.png");
	private: System::Windows::Forms::Timer^  timer1;

		CDriver * obDriver = new CDriver();
	public:
		Jueguito(void)
		{
			///transparencia
			((Bitmap^)bmpVida)->MakeTransparent(((Bitmap^)bmpVida)->GetPixel(0, 0));
			((Bitmap^)bmpJbomba)->MakeTransparent(((Bitmap^)bmpJbomba)->GetPixel(0, 0));
			((Bitmap^)bmpjugador)->MakeTransparent(((Bitmap^)bmpjugador)->GetPixel(0, 0));
		//	((Bitmap^)bmpSlime)->MakeTransparent(((Bitmap^)bmpSlime)->GetPixel(0, 0));
			
			





			
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
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
			this->ClientSize = System::Drawing::Size(924, 749);
			this->Name = L"Jueguito";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Fire War";
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

		obDriver->dibujar(buffer->Graphics, bmpSuelo, bmpSolido, bmpDes, bmpjugador, bmpVida,bmpSlime);
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
