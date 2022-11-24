#pragma once
#include"Entidad.h"
using namespace System;
class Protestantes :public Entidad {
private:
	int mensaje;
public:
	Protestantes(int dx, int dy) {
		Random j;
		x = j.Next(190, 1000);
		System::Threading::Thread::Sleep(30);
		y = j.Next(50, 80);
		System::Threading::Thread::Sleep(5);
		columna = fila = 0;
		this->dx = dx;
		this->dy = dy;
		mensaje = j.Next(1, 3);
	}
	void setDXY() {
		x = 200;
		y = 100;
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		alto = img->Height / 4;
		ancho = img->Width / 3;
		img->MakeTransparent(img->GetPixel(0, 0));
		Rectangle molde = Rectangle(ancho * columna, fila * alto, ancho, alto);
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		switch (mensaje) {
		case 1:g->DrawString("Necesito Trabajar", gcnew Font("Arial", 14), Brushes::Yellow, x + 2, y + 2); break;
		case 2:g->DrawString("Quiero mi bono", gcnew Font("Arial", 14), Brushes::Yellow, x + 2, y + 2); break;
		}


	}

	void Mover(int ancho1) {

		if (x + ancho + dx > ancho1 || x < 0) { dx *= -1; setDXY(); }

		if (dx > 0) {
			fila = 2;
		}
		else fila = 1;
		x += dx;


		columna++;
		if (columna == 3) {
			columna = 0;
		}

	}
};