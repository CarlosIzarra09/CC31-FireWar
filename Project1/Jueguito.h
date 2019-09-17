#pragma once
#include"Controladora.h"
namespace Project1 {

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
	public:
		Bitmap ^ bmpSolido = gcnew Bitmap("imagenes\\bmpSolido.png");
		Bitmap^bmpDes = gcnew Bitmap("imagenes\\bmpDestruible.png");
		Bitmap^bmpSuelo = gcnew Bitmap("imagenes\\bmpSuelo.png");
		Bitmap^bmpjugador = gcnew Bitmap("imagenes\\bmpjugador.png");
		Bitmap ^bmpJbomba = gcnew Bitmap("imagenes\\bomba.png");

		CDriver * obDriver = new CDriver();
		Jueguito(void)
		{
			bmpjugador->MakeTransparent(bmpjugador->GetPixel(0, 0));
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
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

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
			this->ClientSize = System::Drawing::Size(471, 357);
			this->Name = L"Jueguito";
			this->Text = L"Jueguito";
			this->Load += gcnew System::EventHandler(this, &Jueguito::Jueguito_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Jueguito::MantenerTecla);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Jueguito::preionatecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Jueguito::ultimatecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);
		obDriver->dibujar(buffer->Graphics, bmpSuelo,bmpsolido,bmpEx, bmomb, bmpDes);

		obDriver->dibujar(buffer->Graphics, bmpSuelo, bmpSolido, bmpDes,bmpjugador,bmpboba,bmpExplosion);
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void Jueguito_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		obDriver->CambiarNivel();
	}
	private: System::Void MantenerTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
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
	private: System::Void preionatecla(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{

	}

private: System::Void ultimatecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
{
	switch (e->KeyCode)
	{
	case Keys::Space:
		obDriver->add_bomba();
		break;
	default:
		obDriver->getoJugador()->setDirecciones(Direccion::Ninguno);
		break;
	}
}
};
}
