#pragma once
#include"Juego.h"
#include<ctime>
namespace Cuarentenagame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Resumen de Avanzado
	/// </summary>
	public ref class Avanzado : public System::Windows::Forms::Form
	{
	public:
		Avanzado(int tiempo, int vida)
		{
			InitializeComponent();
			vidas = vida;
			tiempo1 = tiempo;
			Random j;
			g = this->CreateGraphics();
			bfc = BufferedGraphicsManager::Current;
			bf = bfc->Allocate(g, this->ClientRectangle);
			juego = new Juego(tiempo, vida);

			juga = gcnew Bitmap("imagenes/jugador.png");
			asi = gcnew Bitmap("imagenes/asintomatico.png");
			saludable = gcnew Bitmap("imagenes/saludable.png");
			ambulancia = gcnew Bitmap("imagenes/ambulancia.png");
			miraflores = gcnew Bitmap("imagenes/Miraflores.png");
			policia = gcnew Bitmap("imagenes/policia.png");
			rojo = gcnew Bitmap("imagenes/rojo1.png");
			verde = gcnew Bitmap("imagenes/verde1.jpg");
			san_juan = gcnew Bitmap("imagenes/san_juan.png");
			bala = gcnew Bitmap("imagenes/monedas.png");
			variable = gcnew SoundPlayer("imagenes/song277.wav");
			balajuga = gcnew Bitmap("imagenes/blanco.png");
			total_enemys = j.Next(4, 7);
			System::Threading::Thread::Sleep(3);
			x = 0;
			y = 0;
			ancho_form = this->Width;
			alto_form = this->Height;
			
			ganaste = false;
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Avanzado()
		{
			if (components)
			{
				delete components;
			}
		}
	internal: System::Windows::Forms::Timer^ timer1;
	protected:


	private:

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

	private:
		Graphics^ g;
		Bitmap^ miraflores;
		Bitmap^ juga;
		Bitmap^ rojo;
		Bitmap^ verde;
		Bitmap^ asi;
		Bitmap^ saludable;
		Bitmap^ ambulancia;
		Bitmap^ policia;
		Bitmap^ san_juan;
		Bitmap^ bala;
		Bitmap^ balajuga;
		BufferedGraphicsContext^ bfc;
		BufferedGraphics^ bf;
		SoundPlayer^ variable;

		Juego* juego;
		int x, y, total_enemys;
		int ancho_form, alto_form;
		int vidas, tiempo1;

		bool ganaste;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblpuntos;
	private: System::Windows::Forms::Label^ lbltiempo;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::Label^ lblvida;

	public: bool getGanaste() {
		return ganaste;
	}

	public: int getTotal_Enemigos() {
	
		return total_enemys;
	}
	public: void Abrir(int tiempo_inicial, int vidas) {
		juego->Reset(tiempo_inicial,vidas);
		juego->GuardarTodo();
	}
#pragma region Windows Form Designer generated code
		  /// <summary>
		  /// Método necesario para admitir el Diseñador. No se puede modificar
		  /// el contenido de este método con el editor de código.
		  /// </summary>
		  void InitializeComponent(void)
		  {
			  this->components = (gcnew System::ComponentModel::Container());
			  this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			  this->label1 = (gcnew System::Windows::Forms::Label());
			  this->label2 = (gcnew System::Windows::Forms::Label());
			  this->label3 = (gcnew System::Windows::Forms::Label());
			  this->lblpuntos = (gcnew System::Windows::Forms::Label());
			  this->lbltiempo = (gcnew System::Windows::Forms::Label());
			  this->lblvida = (gcnew System::Windows::Forms::Label());
			  this->label4 = (gcnew System::Windows::Forms::Label());
			  this->label5 = (gcnew System::Windows::Forms::Label());
			  this->SuspendLayout();
			  // 
			  // timer1
			  // 
			  this->timer1->Enabled = true;
			  this->timer1->Tick += gcnew System::EventHandler(this, &Avanzado::timer1_Tick);
			  // 
			  // label1
			  // 
			  this->label1->AutoSize = true;
			  this->label1->BackColor = System::Drawing::Color::Transparent;
			  this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->label1->ForeColor = System::Drawing::Color::Red;
			  this->label1->Location = System::Drawing::Point(79, 71);
			  this->label1->Name = L"label1";
			  this->label1->Size = System::Drawing::Size(84, 26);
			  this->label1->TabIndex = 0;
			  this->label1->Text = L"VIDAS";
			  // 
			  // label2
			  // 
			  this->label2->AutoSize = true;
			  this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->label2->ForeColor = System::Drawing::Color::Red;
			  this->label2->Location = System::Drawing::Point(502, 22);
			  this->label2->Name = L"label2";
			  this->label2->Size = System::Drawing::Size(109, 26);
			  this->label2->TabIndex = 0;
			  this->label2->Text = L"PUNTOS";
			  // 
			  // label3
			  // 
			  this->label3->AutoSize = true;
			  this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->label3->ForeColor = System::Drawing::Color::Red;
			  this->label3->Location = System::Drawing::Point(770, 22);
			  this->label3->Name = L"label3";
			  this->label3->Size = System::Drawing::Size(101, 26);
			  this->label3->TabIndex = 0;
			  this->label3->Text = L"TIEMPO";
			  // 
			  // lblpuntos
			  // 
			  this->lblpuntos->AutoSize = true;
			  this->lblpuntos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->lblpuntos->Location = System::Drawing::Point(632, 22);
			  this->lblpuntos->Name = L"lblpuntos";
			  this->lblpuntos->Size = System::Drawing::Size(27, 29);
			  this->lblpuntos->TabIndex = 4;
			  this->lblpuntos->Text = L"0";
			  // 
			  // lbltiempo
			  // 
			  this->lbltiempo->AutoSize = true;
			  this->lbltiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->lbltiempo->Location = System::Drawing::Point(896, 22);
			  this->lbltiempo->Name = L"lbltiempo";
			  this->lbltiempo->Size = System::Drawing::Size(27, 29);
			  this->lbltiempo->TabIndex = 5;
			  this->lbltiempo->Text = L"0";
			  // 
			  // lblvida
			  // 
			  this->lblvida->AutoSize = true;
			  this->lblvida->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->lblvida->Location = System::Drawing::Point(196, 68);
			  this->lblvida->Name = L"lblvida";
			  this->lblvida->Size = System::Drawing::Size(27, 29);
			  this->lblvida->TabIndex = 6;
			  this->lblvida->Text = L"0";
			  // 
			  // label4
			  // 
			  this->label4->AutoSize = true;
			  this->label4->BackColor = System::Drawing::Color::Transparent;
			  this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->label4->ForeColor = System::Drawing::Color::Blue;
			  this->label4->Location = System::Drawing::Point(44, 19);
			  this->label4->Name = L"label4";
			  this->label4->Size = System::Drawing::Size(330, 29);
			  this->label4->TabIndex = 7;
			  this->label4->Text = L"MUNDO IRRESPONSABLE";
			  // 
			  // label5
			  // 
			  this->label5->AutoSize = true;
			  this->label5->BackColor = System::Drawing::Color::Transparent;
			  this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				  static_cast<System::Int32>(static_cast<System::Byte>(64)));
			  this->label5->Location = System::Drawing::Point(1049, 9);
			  this->label5->Name = L"label5";
			  this->label5->Size = System::Drawing::Size(248, 78);
			  this->label5->TabIndex = 8;
			  this->label5->Text = L"OBJETIVO: 500 PTS -\r\nMATAR MITAD\r\n   ENEMIGOS";
			  // 
			  // Avanzado
			  // 
			  this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			  this->ClientSize = System::Drawing::Size(1371, 1055);
			  this->Controls->Add(this->label5);
			  this->Controls->Add(this->label4);
			  this->Controls->Add(this->lblvida);
			  this->Controls->Add(this->lbltiempo);
			  this->Controls->Add(this->lblpuntos);
			  this->Controls->Add(this->label3);
			  this->Controls->Add(this->label2);
			  this->Controls->Add(this->label1);
			  this->Name = L"Avanzado";
			  this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			  this->Text = L"Avanzado";
			  this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			  this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Avanzado::Avanzado_KeyDown);
			  this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Avanzado::Avanzado_MouseDown);
			  this->ResumeLayout(false);
			  this->PerformLayout();

		  }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		

		bf->Graphics->DrawImage(san_juan, 0, 0, Rectangle(x, y, san_juan->Width, san_juan->Height), GraphicsUnit::Pixel);
		juego->Mostrar_jugador(bf->Graphics, juga,balajuga);
		if (juego->getContador() < getTotal_Enemigos()) {
			juego->Tiempo_asintomatico();

		}
		if (juego->getContador1() < getTotal_Enemigos()) {
			juego->Tiempo_saludable();

		}
		juego->mostrar_asintomatico(bf->Graphics, asi,bala);
		juego->mover_asintomatico(ancho_form,alto_form);


		juego->mostrar_Saludable(bf->Graphics, saludable);
		juego->mover_Saludable(ancho_form,alto_form);

		juego->colision_balas_jugador_asi();
		juego->colision_balas_jugador_saludable();


		juego->colision_balas_asintomaticoxjugador();
		juego->colison_balas_desaludable_ajugador();


		juego->colisionambulancia_asi(bf->Graphics, ambulancia,ancho_form,alto_form);
		juego->colision_policia_saludable(bf->Graphics, policia,ancho_form,alto_form);

	

		juego->cambiar_rojo(bf->Graphics, rojo);
		juego->cambiar_verde(bf->Graphics, verde);

		juego->colision_jugador_asi();
		juego->colision_jugador_salu();
		

	


		bf->Render(g);
		if (juego->getSonido() == true) {
			variable->PlayLooping();
		}
		else {
			variable->Stop();
		}

		int puntos = juego->getPuntos();
		lblpuntos->Text = puntos + "";

		if (juego->getCapturados() == getTotal_Enemigos() || puntos >= 500) {
			timer1->Enabled = false;
			ganaste = true;
			
	
			this->Hide();
		}
		int v = juego->getvidasJugador();
		lblvida->Text = v + "";
		if (v == 0) {
			timer1->Enabled = false;
			MessageBox::Show("Perdiste");
		}


		int t = juego->Tiempo();
		lbltiempo->Text = t.ToString();
		if (t == 0) {
			timer1->Enabled = false;
			MessageBox::Show("Perdiste");
		}


	


	}
	private: System::Void Avanzado_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		juego->Mover_jugador(e->KeyCode, ancho_form,alto_form);
		
		/*if (e->KeyCode == Keys::Space) {
		
			juego->disparar();
			
		}*/
		
		

		if (e->KeyCode == Keys::G) {
			juego->GuardarTodo();

		}
		if (e->KeyCode == Keys::R) {
			juego->Reset(tiempo1,vidas);
			juego->GuardarTodo();
		}

		//if (e->KeyCode == Keys::C) {
		//	/*timer1->Enabled = false;
		//	this->Close();*/
		//	variable->PlayLooping();
		//}
		//else {
		//	variable->Stop();
		//}

	}


	
private: System::Void Avanzado_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	juego->disparar(e->X,e->Y);
}
};
}
