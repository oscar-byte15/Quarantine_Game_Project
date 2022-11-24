#pragma once
#include"Juego_nivel2_Avanzado.h"
#include<ctime>
namespace Cuarentenagame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Anivel2
	/// </summary>
	public ref class Anivel2 : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		Bitmap^ miraflores;
		Bitmap^ ladron;
		Bitmap^ residente;
		Bitmap^ jugador;
		Bitmap^ asinto;
		Bitmap^ rojo;
		Juego_Nivel2_Avanzado* juego2;
		Bitmap^ bala;
		Bitmap^ balajuga;
		BufferedGraphicsContext^ bfc;
		BufferedGraphics^ bf;
		int x, y;
		int ancho_form,alto_form;
		int total_enemigos;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lbltiempo;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblpuntos;
	private: System::Windows::Forms::Label^ lblcapturado;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ lblvidas_ladron;
	private: System::Windows::Forms::Label^ label6;


	private: System::Windows::Forms::Label^ lblvidas;
	public:
		Anivel2(int tiempo, int vidas)
		{
			Random j;
			InitializeComponent();

			g = this->CreateGraphics();
			bfc = BufferedGraphicsManager::Current;
			bf = bfc->Allocate(g, this->ClientRectangle);
			juego2 = new Juego_Nivel2_Avanzado(tiempo, vidas);
			asinto = gcnew Bitmap("imagenes/asintomatico.png");
			jugador = gcnew Bitmap("imagenes/jugador.png");
			miraflores = gcnew Bitmap("imagenes/Miraflores.png");
			ladron = gcnew Bitmap("imagenes/ladron.png");
			residente = gcnew Bitmap("imagenes/protestantes.png");
			rojo = gcnew Bitmap("imagenes/rojo1.png");

			bala = gcnew Bitmap("imagenes/energy.png");
			balajuga = gcnew Bitmap("imagenes/blanco.png");
			x = y = 0;
			ancho_form = this->Width;
			alto_form = this->Height;
			total_enemigos = j.Next(4, 6);
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Anivel2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer2;
	protected:

	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

	public: int getTotal_Enemigos() { return total_enemigos; }
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbltiempo = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lblvidas = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblpuntos = (gcnew System::Windows::Forms::Label());
			this->lblcapturado = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lblvidas_ladron = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &Anivel2::timer2_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(49, 9);
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
			this->label2->Location = System::Drawing::Point(39, 49);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"TIEMPO";
			// 
			// lbltiempo
			// 
			this->lbltiempo->AutoSize = true;
			this->lbltiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbltiempo->Location = System::Drawing::Point(162, 49);
			this->lbltiempo->Name = L"lbltiempo";
			this->lbltiempo->Size = System::Drawing::Size(27, 29);
			this->lbltiempo->TabIndex = 2;
			this->lbltiempo->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(282, 52);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(194, 25);
			this->label4->TabIndex = 1;
			this->label4->Text = L"VIDAS_JUGADOR";
			// 
			// lblvidas
			// 
			this->lblvidas->AutoSize = true;
			this->lblvidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblvidas->Location = System::Drawing::Point(509, 55);
			this->lblvidas->Name = L"lblvidas";
			this->lblvidas->Size = System::Drawing::Size(27, 29);
			this->lblvidas->TabIndex = 3;
			this->lblvidas->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(635, 53);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(102, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"PUNTOS";
			// 
			// lblpuntos
			// 
			this->lblpuntos->AutoSize = true;
			this->lblpuntos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblpuntos->Location = System::Drawing::Point(763, 48);
			this->lblpuntos->Name = L"lblpuntos";
			this->lblpuntos->Size = System::Drawing::Size(28, 29);
			this->lblpuntos->TabIndex = 5;
			this->lblpuntos->Text = L"0";
			// 
			// lblcapturado
			// 
			this->lblcapturado->AutoSize = true;
			this->lblcapturado->Font = (gcnew System::Drawing::Font(L"Calibri", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblcapturado->ForeColor = System::Drawing::Color::Blue;
			this->lblcapturado->Location = System::Drawing::Point(634, 123);
			this->lblcapturado->Name = L"lblcapturado";
			this->lblcapturado->Size = System::Drawing::Size(257, 33);
			this->lblcapturado->TabIndex = 6;
			this->lblcapturado->Text = L"LADRON CAPTURADO";
			this->lblcapturado->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(889, 53);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(178, 25);
			this->label5->TabIndex = 7;
			this->label5->Text = L"VIDAS_LADRON";
			// 
			// lblvidas_ladron
			// 
			this->lblvidas_ladron->AutoSize = true;
			this->lblvidas_ladron->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblvidas_ladron->Location = System::Drawing::Point(1116, 51);
			this->lblvidas_ladron->Name = L"lblvidas_ladron";
			this->lblvidas_ladron->Size = System::Drawing::Size(38, 26);
			this->lblvidas_ladron->TabIndex = 8;
			this->lblvidas_ladron->Text = L"20";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label6->Location = System::Drawing::Point(1231, 48);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(241, 52);
			this->label6->TabIndex = 9;
			this->label6->Text = L"OBJETIVO: 500 PTS-\r\nMATAR LADRON";
			// 
			// Anivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1371, 913);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->lblvidas_ladron);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lblcapturado);
			this->Controls->Add(this->lblpuntos);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblvidas);
			this->Controls->Add(this->lbltiempo);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(1580, 960);
			this->MinimumSize = System::Drawing::Size(1200, 47);
			this->Name = L"Anivel2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Anivel2";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Anivel2::Anivel2_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Anivel2::Anivel2_MouseClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Anivel2::Anivel2_MouseDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {


		bf->Graphics->DrawImage(miraflores, 0, 0, Rectangle(x, y, 1183, 760), GraphicsUnit::Pixel);

		juego2->Mostrar_jugador(bf->Graphics, jugador,balajuga);
		if (juego2->getContador() < getTotal_Enemigos()) {
			juego2->Tiempo_asintomatico();

		}
		


		juego2->mostrar_ciudadano(bf->Graphics, residente);
		juego2->Mover_Ciudadanos(ancho_form);

		juego2->Mostrar_Asintomatico(bf->Graphics,asinto,bala);
		juego2->mover_asintomatico(ancho_form,alto_form);
		

		juego2->mostar_ladron(bf->Graphics,ladron);
		juego2->mover_ladron(this->Width, this->Height,1);
	
	
		juego2->colision_balasjugador_ladron();
		juego2->colision_ladron_ciudadanos();
		juego2->colision_balas_asintomaticoxjugador();
		juego2->colision_balas_jugador_asi();
		juego2->cambiar_rojo(bf->Graphics,rojo);
		
		bf->Render(g);//mostrar en el g(graficador del formulario)
		

		int tiempo = juego2->getTiempo();
		int vidas = juego2->getVidas();
		int puntos = juego2->getPuntos();
		int vidas_ladron = juego2->getVidas_Ladron();
		lblpuntos->Text = puntos.ToString();
		lbltiempo->Text = tiempo.ToString();
		lblvidas->Text = vidas.ToString();
		lblvidas_ladron->Text = vidas_ladron.ToString();
		if (tiempo <= 0){
			timer2->Enabled = false;
			MessageBox::Show("PERDISTE");
			this->Close();
		}
		else if(vidas<=0){
			timer2->Enabled = false;
			MessageBox::Show("PERDISTE");
			this->Close();
		}
		else if(puntos>=500){
			timer2->Enabled = false;
			MessageBox::Show("GANASTE EL JUEGO");
			this->Close();
		}
		else if (juego2->Terminar_por_Robados() == true) {
			timer2->Enabled = false;
			MessageBox::Show("PERDISTE");
			this->Close();
		}
		 if(vidas_ladron <=0){
			timer2->Enabled = false;
			MessageBox::Show("GANASTE EL JUEGO");
			this->Close();
		}

	}
	private: System::Void Anivel2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego2->Mover_jugador(e->KeyCode, ancho_form,alto_form);
		/*if (e->KeyCode == Keys::Space) {
			juego2->disparar();
		}*/

		if (e->KeyCode == Keys::G) {
			juego2->GuardarTodo();
		}

	}


	private: System::Void Anivel2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
	}
private: System::Void Anivel2_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	juego2->disparar(e->X,e->Y);

}
};
}
