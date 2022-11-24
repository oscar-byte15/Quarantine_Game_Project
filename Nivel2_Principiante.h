#pragma once
#include"Juego_nivel2_Principiante.h"
namespace Cuarentenagame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Nivel2_Principiante
	/// </summary>
	public ref class Nivel2_Principiante : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		BufferedGraphicsContext^ bfc;
		BufferedGraphics^ bf;
		Bitmap^ nivel2;
		Bitmap^ ladron;
		Bitmap^ juga;
		Bitmap^ saludable;
		Bitmap^ asi;
		Bitmap^ bala;
		Bitmap^ balajuga;
		Juego_nivel2_Principiante* juegop_2;
		int x, y;
		int total_enemys;
		int ancho_form, alto_form;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblvidas;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lbltiempo;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ lblpuntos;
	private: System::Windows::Forms::Label^ lblvidas_ladron;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ lblrobados;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	public:
		Nivel2_Principiante(int tiempo,int vidas)
		{
			InitializeComponent();
			Random j;
			g = this->CreateGraphics();
			bfc = BufferedGraphicsManager::Current;
			bf = bfc->Allocate(g, this->ClientRectangle);
			juegop_2 = new Juego_nivel2_Principiante(tiempo,vidas);
			nivel2 = gcnew Bitmap("imagenes/san_miguel.png");
			saludable = gcnew Bitmap("imagenes/saludable.png");
			asi = gcnew Bitmap("imagenes/asintomatico.png");
			juga = gcnew Bitmap("imagenes/jugador.png");
			ladron = gcnew Bitmap("imagenes/ladron.png");
			bala = gcnew Bitmap("imagenes/energy.png");
			balajuga = gcnew Bitmap("imagenes/blanco.png");
			x = y = 0;
			total_enemys = j.Next(4,8);
			ancho_form = this->Width;
			alto_form = this->Height;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Nivel2_Principiante()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
	private:
		

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
			this->lblvidas = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lbltiempo = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lblpuntos = (gcnew System::Windows::Forms::Label());
			this->lblvidas_ladron = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->lblrobados = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Nivel2_Principiante::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(48, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(319, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MUNDO RESPONSABLE";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(43, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(194, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"VIDAS_JUGADOR";
			// 
			// lblvidas
			// 
			this->lblvidas->AutoSize = true;
			this->lblvidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblvidas->Location = System::Drawing::Point(260, 74);
			this->lblvidas->Name = L"lblvidas";
			this->lblvidas->Size = System::Drawing::Size(28, 29);
			this->lblvidas->TabIndex = 2;
			this->lblvidas->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(387, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 25);
			this->label3->TabIndex = 1;
			this->label3->Text = L"TIEMPO";
			// 
			// lbltiempo
			// 
			this->lbltiempo->AutoSize = true;
			this->lbltiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbltiempo->Location = System::Drawing::Point(514, 78);
			this->lbltiempo->Name = L"lbltiempo";
			this->lbltiempo->Size = System::Drawing::Size(28, 29);
			this->lbltiempo->TabIndex = 3;
			this->lbltiempo->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(620, 82);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(102, 25);
			this->label5->TabIndex = 1;
			this->label5->Text = L"PUNTOS";
			// 
			// lblpuntos
			// 
			this->lblpuntos->AutoSize = true;
			this->lblpuntos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblpuntos->Location = System::Drawing::Point(757, 78);
			this->lblpuntos->Name = L"lblpuntos";
			this->lblpuntos->Size = System::Drawing::Size(28, 29);
			this->lblpuntos->TabIndex = 4;
			this->lblpuntos->Text = L"0";
			// 
			// lblvidas_ladron
			// 
			this->lblvidas_ladron->AutoSize = true;
			this->lblvidas_ladron->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblvidas_ladron->Location = System::Drawing::Point(1067, 82);
			this->lblvidas_ladron->Name = L"lblvidas_ladron";
			this->lblvidas_ladron->Size = System::Drawing::Size(43, 29);
			this->lblvidas_ladron->TabIndex = 5;
			this->lblvidas_ladron->Text = L"15";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(873, 86);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(172, 25);
			this->label6->TabIndex = 1;
			this->label6->Text = L"VIDAS LADRON";
			// 
			// lblrobados
			// 
			this->lblrobados->AutoSize = true;
			this->lblrobados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblrobados->Location = System::Drawing::Point(1380, 78);
			this->lblrobados->Name = L"lblrobados";
			this->lblrobados->Size = System::Drawing::Size(28, 29);
			this->lblrobados->TabIndex = 6;
			this->lblrobados->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Red;
			this->label7->Location = System::Drawing::Point(1227, 82);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(119, 25);
			this->label7->TabIndex = 1;
			this->label7->Text = L"ROBADOS";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label4->Location = System::Drawing::Point(630, 130);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(241, 52);
			this->label4->TabIndex = 7;
			this->label4->Text = L"OBJETIVO: 500 PTS-\r\nMATAR LADRON";
			// 
			// Nivel2_Principiante
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1782, 785);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lblrobados);
			this->Controls->Add(this->lblvidas_ladron);
			this->Controls->Add(this->lblpuntos);
			this->Controls->Add(this->lbltiempo);
			this->Controls->Add(this->lblvidas);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Nivel2_Principiante";
			this->Text = L"Nivel2_Principiante";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2_Principiante::Nivel2_Principiante_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Nivel2_Principiante::Nivel2_Principiante_MouseClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Nivel2_Principiante::Nivel2_Principiante_MouseDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {


		bf->Graphics->DrawImage(nivel2, 0, 0, Rectangle(x, y, 1350, 699), GraphicsUnit::Pixel);
		
		juegop_2->Mostrar_jugador(bf->Graphics,juga,balajuga);


		if (juegop_2->getContador() < total_enemys) {
			juegop_2->Tiempo_asintomatico();
		}
		if (juegop_2->getContador1() < total_enemys) {
			juegop_2->Tiempo_saludable();
		}

		juegop_2->mostrar_asintomatico(bf->Graphics, asi,bala);
		juegop_2->mover_asintomatico(ancho_form,alto_form);

		juegop_2->mostrar_Saludable(bf->Graphics,saludable );
		juegop_2->mover_Saludable(ancho_form,alto_form);

		juegop_2->mostar_ladron(bf->Graphics,ladron);
		juegop_2->mover_ladron(ancho_form,alto_form);
		juegop_2->colision_jugador_asi();
		juegop_2->colision_balasjugador_ladron();
		juegop_2->colision_ladron_jugador();
		juegop_2->colsion_ladron_saludable();
		juegop_2->colision_balas_jugador_asi();
		bf->Render(g);

		int robados= juegop_2->getRobados();
		int vidas = juegop_2->getVidas_Jugador();
		int tiempo = juegop_2->getTiempo();
		int puntos = juegop_2->getPuntos();
		int vidas_ladron = juegop_2->getVidas_Ladron();
		lblvidas->Text = vidas.ToString();
		lblpuntos->Text = puntos.ToString();
		lbltiempo->Text = tiempo.ToString();
		lblvidas_ladron->Text = vidas_ladron.ToString();
		lblrobados->Text = robados.ToString();
		if (vidas <= 0||tiempo<=0) {
			timer1->Enabled = false;
			MessageBox::Show("PERDISTE");
			this->Close();
		}
		else if (puntos >= 500) {
			timer1->Enabled = false;
			MessageBox::Show("GANASTE");
			this->Close();
		}
		else if (vidas_ladron <= 0) {
			timer1->Enabled = false;
			MessageBox::Show("GANASTE");
			this->Close();
		}
		else if (robados == total_enemys) {
			timer1->Enabled = false;
			MessageBox::Show("PERDISTE");
			this->Close();
		}

	}
	private: System::Void Nivel2_Principiante_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juegop_2->Mover_jugador(e->KeyCode,ancho_form,alto_form);

		/*if (e->KeyCode == Keys::Space) {
			juegop_2->disparar();
		}*/
		if (e->KeyCode == Keys::G) {
			juegop_2->GuardarTodo();
		}

	}
private: System::Void Nivel2_Principiante_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {


}
private: System::Void Nivel2_Principiante_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	juegop_2->disparar(e->X,e->Y);
}
};
}
