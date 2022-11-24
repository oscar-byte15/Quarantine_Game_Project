#pragma once
#include"Entidad.h"
using namespace System;
class BalaEnemigos1 :public Entidad {
public:
	BalaEnemigos1(int x, int y, int dx, int dy) {
		Random j;
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		ancho = alto = 18;
	}

	~BalaEnemigos1() {}
	void mostrar(Graphics^ g) {
		Brush^ br = gcnew SolidBrush(Color::DarkGreen);

		g->FillEllipse(br, x, y, ancho, alto);

	}
	void mover() {
		x += dx;
		y += dy;
	}

};