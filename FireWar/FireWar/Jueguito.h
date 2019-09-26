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
		Bitmap ^bmpSolido = gcnew Bitmap("imagenes\\bmpSolido.png");
		Bitmap ^bmpDes = gcnew Bitmap("imagenes\\bmpDestruible.png");
		Bitmap ^bmpSuelo = gcnew Bitmap("imagenes\\bmpSuelo.png");
		Bitmap ^bmpjugador = gcnew Bitmap("imagenes\\bmpjugador.png");
		Bitmap ^bmpJbomba = gcnew Bitmap("imagenes\\bomba.png");
		Bitmap ^bmpVida = gcnew Bitmap("imagenes\\vida.png");
		Bitmap ^bmpSlime = gcnew Bitmap("imagenes\\slimebmp_PQ.png");
		Bitmap ^bmpBala = gcnew Bitmap("imagenes\\power2.png");
	private: System::Windows::Forms::Timer^  timer1;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

		CDriver * obDriver = new CDriver();
	public:
		Jueguito(void)
		{
			///transparencia
			((Bitmap^)bmpVida)->MakeTransparent(((Bitmap^)bmpVida)->GetPixel(0, 0));
			((Bitmap^)bmpJbomba)->MakeTransparent(((Bitmap^)bmpJbomba)->GetPixel(0, 0));
			((Bitmap^)bmpjugador)->MakeTransparent(((Bitmap^)bmpjugador)->GetPixel(0, 0));
		    ((Bitmap^)bmpBala)->MakeTransparent(((Bitmap^)bmpBala)->GetPixel(0, 0));
			
			





			
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Jueguito::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Jueguito::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Russo One", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(665, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Presiona \"R\" \r\npara guardar";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(778, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(54, 50);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// Jueguito
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(924, 749);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Jueguito";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Fire War";
			this->Load += gcnew System::EventHandler(this, &Jueguito::Jueguito_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Jueguito::Jueguito_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Jueguito::Jueguito_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);

		obDriver->dibujar(buffer->Graphics, bmpSuelo, bmpSolido, bmpDes, bmpjugador, bmpVida, bmpSlime,bmpBala);
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

			obDriver->GetJugador()->setDirecciones(Direccion::Arriba);
			break;
		case Keys::Down:

			obDriver->GetJugador()->setDirecciones(Direccion::Abajo);
			break;
		case Keys::Left:
			obDriver->GetJugador()->setDirecciones(Direccion::Izquierda);
			break;
		case Keys::Right:
			obDriver->GetJugador()->setDirecciones(Direccion::Derecha);
			break;
		case Keys::Space:
			if (obDriver->GetJugador()->Retornar_vida() > 0)
			{
				obDriver->GetJugador()->Disparar();
			}
			
			break;
		case Keys::R:
			obDriver->Guardar_Informacion(); break;
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
			obDriver->GetJugador()->setDirecciones(Direccion::Ninguno);
			break;
		}
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	
}
};
}
