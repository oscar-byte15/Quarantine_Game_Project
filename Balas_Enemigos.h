#pragma once
#include"Entidad.h"
using namespace System;
class Balaenemigo :public Entidad {
public:
	Balaenemigo(int x, int y, int dx, int dy) {
		Random j;
		/*Bitmap^ img = gcnew Bitmap("imagenes/energy.jpg");*/
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
	
		/*ancho = alto = 18;*/
	/*	ancho = img->Width / 1;
		alto = img->Height / 1;*/
		columna = fila = 0;
	}

	~Balaenemigo() {}
	void mostrar(Graphics^ g,Bitmap^img) {
		
		alto = img->Height / 2;
		ancho = img->Width / 3;

		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho*1.5, alto*1.5);
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
	/*	img->MakeTransparent(img->GetPixel(1, 1));*/
		columna++;
		if (columna == 3) {
			columna = 0;
		}
	/*	Brush^ br = gcnew SolidBrush(Color::Red);

		g->FillEllipse(br, x, y, ancho, alto);*/

	}
	void mover() {
		x += dx;
		if (dx>0) {
			fila = 0;
		}
		else {
			fila = 1;
		}
		y += dy;
		
	}

};