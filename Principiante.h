#pragma once
#include"Juego_Principiante.h"
namespace Cuarentenagame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Principiante
	/// </summary>
	public ref class Principiante : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
	private: System::Windows::Forms::Timer^ timer1;
		   Bitmap^ fondo1;
		   Bitmap^ ate;
		   Bitmap^ juga;
		   Bitmap^ asi;
		   Bitmap^ ambulancia;
		   Bitmap^ saludable;
		   Bitmap^ policia;
		   Bitmap^ rojo;
		   Bitmap^ verde;
		   Bitmap^ pro;
		   Bitmap^ bala;
		   Bitmap^ balajuga;
		   BufferedGraphicsContext^ bfc;
		   BufferedGraphics^ bf;

		   bool ganaste;
		   int ancho_form, alto_form;
		   Juego_Principiante* juego_p;
		   int x, y;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label2;
		   int total_enemys;
	public:
		Principiante(int tiempo, int vidas)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			bfc = BufferedGraphicsManager::Current;
			bf = bfc->Allocate(g, this->ClientRectangle);
			juego_p = new Juego_Principiante(tiempo, vidas);
			ate = gcnew Bitmap("imagenes/ate.png");
			fondo1 = gcnew Bitmap("imagenes/Miraflores.png");
			juga = gcnew Bitmap("imagenes/jugador.png");
			ambulancia = gcnew Bitmap("imagenes/ambulancia.png");
			asi = gcnew Bitmap("imagenes/asintomatico.png");
			saludable = gcnew Bitmap("imagenes/saludable.png");
			policia = gcnew Bitmap("imagenes/policia.png");
			rojo = gcnew Bitmap("imagenes/rojo1.png");
			verde = gcnew Bitmap("imagenes/verde1.jpg");
			pro = gcnew Bitmap("imagenes/protestantes.png");
			bala = gcnew Bitmap("imagenes/energy.png");
			balajuga = gcnew Bitmap("imagenes/blanco.png");
			x = y = 0;
			total_enemys = 3;
			ancho_form = this->Width;
			alto_form = this->Height;
			ganaste = false;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Principiante()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;




	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ lblvidas;
	private: System::Windows::Forms::Label^ lblpuntos;
	private: System::Windows::Forms::Label^ lbltiempo;
	private: System::ComponentModel::IContainer^ components;
	public: int getTotal_Enemigos() { return total_enemys; }
	public: bool getGanaste() { return ganaste; }
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->lblvidas = (gcnew System::Windows::Forms::Label());
			this->lblpuntos = (gcnew System::Windows::Forms::Label());
			this->lbltiempo = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(78, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"VIDAS";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(399, 75);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(123, 29);
			this->label6->TabIndex = 0;
			this->label6->Text = L"PUNTOS";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Red;
			this->label7->Location = System::Drawing::Point(739, 75);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(114, 29);
			this->label7->TabIndex = 0;
			this->label7->Text = L"TIEMPO";
			// 
			// lblvidas
			// 
			this->lblvidas->AutoSize = true;
			this->lblvidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblvidas->Location = System::Drawing::Point(187, 75);
			this->lblvidas->Name = L"lblvidas";
			this->lblvidas->Size = System::Drawing::Size(28, 29);
			this->lblvidas->TabIndex = 1;
			this->lblvidas->Text = L"0";
			// 
			// lblpuntos
			// 
			this->lblpuntos->AutoSize = true;
			this->lblpuntos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblpuntos->Location = System::Drawing::Point(538, 75);
			this->lblpuntos->Name = L"lblpuntos";
			this->lblpuntos->Size = System::Drawing::Size(28, 29);
			this->lblpuntos->TabIndex = 2;
			this->lblpuntos->Text = L"0";
			// 
			// lbltiempo
			// 
			this->lbltiempo->AutoSize = true;
			this->lbltiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbltiempo->Location = System::Drawing::Point(876, 75);
			this->lbltiempo->Name = L"lbltiempo";
			this->lbltiempo->Size = System::Drawing::Size(28, 29);
			this->lbltiempo->TabIndex = 3;
			this->lbltiempo->Text = L"0";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Principiante::timer1_Tick);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Blue;
			this->label8->Location = System::Drawing::Point(31, 23);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(345, 29);
			this->label8->TabIndex = 4;
			this->label8->Text = L"MUNDO IRRESPONSABLE";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(979, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(306, 52);
			this->label2->TabIndex = 5;
			this->label2->Text = L"OBJETIVO: 500 PTS-\r\nMATAR MITAD ENEMIGOS";
			// 
			// Principiante
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 846);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->lbltiempo);
			this->Controls->Add(this->lblpuntos);
			this->Controls->Add(this->lblvidas);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->Name = L"Principiante";
			this->Text = L"Principiante";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Principiante::Principiante_KeyDown);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Principiante::Principiante_MouseDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		

		bf->Graphics->DrawImage(ate, 0, 0, Rectangle(x, y, 1600, 742), GraphicsUnit::Pixel);
		juego_p->Mostrar_jugador(bf->Graphics, juga,balajuga);

		if (juego_p->getContador() < total_enemys) {
			juego_p->Tiempo_asintomatico();
		}
		if (juego_p->getContador1() < total_enemys) {
			juego_p->Tiempo_saludable();
		}

		juego_p->mostrar_asintomatico(bf->Graphics, asi,bala);
		juego_p->mover_asintomatico(ancho_form,alto_form);


		juego_p->colisionambulancia_asi(bf->Graphics, ambulancia,ancho_form,alto_form);


		juego_p->mostrar_Saludable(bf->Graphics, saludable);
		juego_p->mover_Saludable(ancho_form,alto_form);
		juego_p->colision_jugador_salu();
		juego_p->colision_jugador_asi();
		juego_p->colision_policia_saludable(bf->Graphics, policia,ancho_form,alto_form);
	
		//colision balas
		juego_p->colision_balas_jugador_asi();
		juego_p->colision_balas_jugador_saludable();
		//cambio de skin
		juego_p->cambiar_rojo(bf->Graphics, rojo);
		juego_p->cambiar_verde(bf->Graphics, verde);

		juego_p->mostrar_Protestantes(bf->Graphics, pro);
		juego_p->mover_protestantes(ancho_form);
		bf->Render(g);//mostrar en el g(graficador del formulario)
	
		int tiempo = juego_p->Tiempo();
		int puntos = juego_p->getPuntos();
		int vidas = juego_p->getvidasJugador();
		lbltiempo->Text = tiempo.ToString();
		lblvidas->Text = vidas.ToString();
		lblpuntos->Text = puntos.ToString();


		if (vidas <= 0 || tiempo <= 0) {

			timer1->Enabled = false;
			MessageBox::Show("PERDISTE");
			this->Close();
		}

		if (puntos >= 500 || juego_p->getCapturados() == getTotal_Enemigos()) {
			ganaste = true;
			timer1->Enabled = false;
			this->Close();

		}
	}
	private: System::Void Principiante_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego_p->Mover_jugador(e->KeyCode, ancho_form,alto_form);

	/*	if (e->KeyCode == Keys::Space) {
			juego_p->disparar();
		}*/

		if (e->KeyCode == Keys::G) {
			juego_p->GuardarTodo();
		}

	}

	/*private: System::Void Principiante_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		juego_p->disparar(e->X,e->Y);
	}*/
private: System::Void Principiante_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	juego_p->disparar(e->X,e->Y);

}
};
}
