#pragma once
#include"Avanzado.h"
#include"Principiante.h"
#include"Anivel2.h"
#include"Nivel2_Principiante.h"
namespace Cuarentenagame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Cuarentena
	/// </summary>
	public ref class Cuarentena : public System::Windows::Forms::Form
	{
	public:
		Cuarentena(void)
		{
			InitializeComponent();
			mapa = gcnew Bitmap("imagenes/menuprincipal.png");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Cuarentena()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private:
		Bitmap^ mapa;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbxtiempo;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbxvida;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btnAvanzado;
	private: System::Windows::Forms::Button^ btnPrincipiante;
	private: System::Windows::Forms::Label^ label6;






	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbxtiempo = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbxvida = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnAvanzado = (gcnew System::Windows::Forms::Button());
			this->btnPrincipiante = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 50);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Introduce tiempo \r\nen segundos";
			// 
			// tbxtiempo
			// 
			this->tbxtiempo->Location = System::Drawing::Point(210, 21);
			this->tbxtiempo->Name = L"tbxtiempo";
			this->tbxtiempo->Size = System::Drawing::Size(110, 22);
			this->tbxtiempo->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Blue;
			this->label2->Location = System::Drawing::Point(1196, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(181, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Numero de vidas:";
			// 
			// tbxvida
			// 
			this->tbxvida->Location = System::Drawing::Point(1383, 21);
			this->tbxvida->Name = L"tbxvida";
			this->tbxvida->Size = System::Drawing::Size(100, 22);
			this->tbxvida->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(1083, 685);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(327, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"DISPARO: PRESIONA \"SPACE\"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(25, 702);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(432, 25);
			this->label4->TabIndex = 5;
			this->label4->Text = L"MOVIMIENTO: TECLAS DIRECCIONALES";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(599, 784);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(348, 24);
			this->label5->TabIndex = 6;
			this->label5->Text = L"CREATED BY Oscar De la Cruz Jara";
			// 
			// btnAvanzado
			// 
			this->btnAvanzado->Location = System::Drawing::Point(30, 741);
			this->btnAvanzado->Name = L"btnAvanzado";
			this->btnAvanzado->Size = System::Drawing::Size(494, 109);
			this->btnAvanzado->TabIndex = 7;
			this->btnAvanzado->Text = L"AVANZADO";
			this->btnAvanzado->UseVisualStyleBackColor = true;
			this->btnAvanzado->Click += gcnew System::EventHandler(this, &Cuarentena::btnAvanzado_Click);
			// 
			// btnPrincipiante
			// 
			this->btnPrincipiante->Location = System::Drawing::Point(1021, 731);
			this->btnPrincipiante->Name = L"btnPrincipiante";
			this->btnPrincipiante->Size = System::Drawing::Size(483, 119);
			this->btnPrincipiante->TabIndex = 8;
			this->btnPrincipiante->Text = L"PRINCIPIANTE";
			this->btnPrincipiante->UseVisualStyleBackColor = true;
			this->btnPrincipiante->Click += gcnew System::EventHandler(this, &Cuarentena::btnPrincipiante_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(595, 717);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(352, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"PRESIONA \"G\" GUARDAR DATOS";
			// 
			// Cuarentena
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1532, 1055);
			this->Controls->Add(this->btnPrincipiante);
			this->Controls->Add(this->btnAvanzado);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbxvida);
			this->Controls->Add(this->tbxtiempo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Cuarentena";
			this->Text = L"Cuarentena";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Cuarentena::Cuarentena_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cuarentena_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		g->DrawImage(mapa, 0, 0, Rectangle(0, 0, 1200, 852), GraphicsUnit::Pixel);

	}


private: System::Void btnAvanzado_Click(System::Object^ sender, System::EventArgs^ e) {


	if (tbxtiempo->Text != "" && tbxvida->Text != "")
	{
	
		Avanzado^ esce1 = gcnew Avanzado(Convert::ToInt32(tbxtiempo->Text), Convert::ToInt32(tbxvida->Text));
		esce1->ShowDialog();
		
		
		Anivel2^ esce2 = gcnew Anivel2(Convert::ToInt32(tbxtiempo->Text), Convert::ToInt32(tbxvida->Text));

		if (esce1->getGanaste() == true) {
			
			esce1->Hide();
			esce2->Show();
			

		}

	}
	


}
private: System::Void btnPrincipiante_Click(System::Object^ sender, System::EventArgs^ e) {
		if (tbxtiempo->Text != "" && tbxvida->Text != "")
	{
		Principiante^ princi = gcnew Principiante(Convert::ToInt32(tbxtiempo->Text), Convert::ToInt32(tbxvida->Text));
		princi->ShowDialog();
		Nivel2_Principiante^ nivel2 = gcnew Nivel2_Principiante(Convert::ToInt32(tbxtiempo->Text), Convert::ToInt32(tbxvida->Text));
		
		if (princi->getGanaste() == true) {
			princi->Hide();
			nivel2->Show();
		}




}


}

};
}
