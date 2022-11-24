#pragma once
#include"Entidad.h"
#include<iostream>

using namespace System;
class Bala :public Entidad {

	int m;
public:
	Bala(int x, int y, int dx, int dy) {
		Random j;
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;

		m = j.Next(1, 5);
		System::Threading::Thread::Sleep(4);
		/*alto = 10;
		ancho = 30;*/
		columna = fila = 0;
	}

	~Bala() {}
	void mostrar(Graphics^ g, Bitmap^img) {
		alto = img->Height / 1;
		ancho = img->Width / 1;
		Rectangle molde = Rectangle(columna*ancho,fila*alto,ancho,alto);
	/*	Brush^ br = gcnew SolidBrush(Color::Transparent);*/
		switch (m) {
		case 1:g->DrawString("Protegete", gcnew Font("Calibri", 14), Brushes::Black, x,  y+10); break;
		case 2:g->DrawString("Cuidate", gcnew Font(  "Calibri", 14), Brushes::Black, x , y+10 ); break;
		case 3:g->DrawString("Lavate ", gcnew Font(  "Calibri", 14), Brushes::Black, x , y+10 ); break;
		case 4: g->DrawString("Quedate", gcnew Font( "Calibri", 14), Brushes::Black, x,  y+10 ); break;
		}
		//img->MakeTransparent(img->GetPixel(0,0));
		g->DrawImage(img,x,y,molde,GraphicsUnit::Pixel);
		/*g->FillRectangle(br, x, y, ancho, alto);*/
		columna++;
		if (columna == 1) {
			columna = 0;
		}

	}
	void mover() {
		x += dx;
		y += dy;
	}

};