#pragma once
#include"Entidad.h"
using namespace System;
class Policia :public Entidad {
	Direccion direccion;
public:
	Policia() {
		Random j;
		x = j.Next(50, 90);
		System::Threading::Thread::Sleep(30);
		y = j.Next(500, 590);
		System::Threading::Thread::Sleep(30);
		dx = dy = 20;
		fila = columna = 0;
		c_filas=4;
		c_columnas=9;
	}
	void setXY() {
		x = 65;
		y = 590;
	}
	int X0() {
		return x += 0;
	}
	int Y0() {
		return y += 0;
	}
	void mostrar_Policia(Graphics^ g, Bitmap^ img) {
		alto = img->Height / c_filas;
		ancho = img->Width / c_columnas;

		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		img->MakeTransparent(img->GetPixel(0, 0));
		columna++;
		if (columna == c_columnas) {
			columna = 0;
		}
	}

	void mover_Policia(Direccion direccion, int ancho1, int alto1) {

		switch (direccion) {

		case Direccion::Arriba:
			if (y - dy > 0)
				y -= dy;

			this->direccion = Direccion::Arriba;
			fila = 0;
			break;
		case Direccion::Abajo:
			if (y + alto + dy < alto1)
				y += dy;
			this->direccion = Direccion::Abajo;
			fila = 2;
			break;

		case Direccion::Derecha:
			if (x + ancho + dx < ancho1)
				x += dx;
			this->direccion = Direccion::Derecha;
			fila = 3;
			break;

		case Direccion::Izquierda:
			if (x - dx > 0)
				x -= dx;
			this->direccion = Direccion::Izquierda;
			fila = 1;
			break;
		}
	}

	void GuardarTodo() {
		std::ofstream archivo("Policia1.txt");

		archivo << x << " " << y << " " << dx << " " << dy << std::endl;
		archivo.close();
	}



};