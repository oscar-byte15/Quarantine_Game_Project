#pragma once
#include"Entidad.h"
using namespace System;
class Ladron :public Entidad {
private:
	Direccion direccion;
public:
	Ladron() {
		Random j;
		x = j.Next(450, 590);
		System::Threading::Thread::Sleep(30);
		y = j.Next(200, 360);
		System::Threading::Thread::Sleep(30);
		dx = dy = 25;
		fila = columna = 0;
		c_filas = 4;
		c_columnas = 4;
	}
	void setLadronDXY() {
		dx = 0;
		dy = 0;
	}
	void mostrar_Ladron(Graphics^ g, Bitmap^ img) {
		alto = img->Height / c_filas;
		ancho = img->Width / c_columnas;

		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		g->DrawString("Voy a robarte", gcnew Font("Arial", 14), Brushes::White, x + 2, y + 2);
		img->MakeTransparent(img->GetPixel(0, 0));
		columna++;
		if (columna == c_columnas) {
			columna = 0;
		}
	}

	void mover_Ladron(int ancho1, int alto1, int index) {

		if (index == 1) {
			if (y + alto + dy > alto1 || y < 0) dy *= -1;

			if (dy > 0) {
				fila = 0;
			}
			else fila = 3;

			y += dy;
		}
		else {
			if (x + ancho + dx > ancho1 || x < 0) { dx *= -1; }

			if (dx > 0) {
				fila = 2;
			}
			else fila = 1;
			x += dx;
		}

		columna++;
		if (columna == 4) {
			columna = 0;
		}

	}
	

	void GuardarTodo() {
		std::ofstream archivo("Ladron1.txt");

		archivo << x << " " << y << " " << dx << " " << dy << std::endl;
		archivo.close();
	}

};