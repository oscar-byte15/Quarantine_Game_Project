#pragma once
#include"Entidad.h"
#include"Arreglo_Bala_Saludable.h"
using namespace System;
class Saludable :public Entidad {
private:
	
	Direccion direccion;
	Arreglo_Bala_Saludable* balas;
public:
	Saludable(int x, int y) {
		
		this->x = x;
		this->y = y;
		balas = new Arreglo_Bala_Saludable();
		dx = 12;
		dy = 12;
		fila = columna = 0;
		
		c_filas = 4;
		c_columnas = 4;
	
	}
	~Saludable() {
		delete balas;
	}
	
	void setDxs() {
		dx = 0;
		dy = 0;
	}
	void setXY() {
		x = 400;
		y = 200;
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		alto = img->Height / c_filas;
		ancho = img->Width / c_columnas;
	
		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);

		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		g->DrawString("COMPRO COMIDA", gcnew Font("Arial", 10), Brushes::DarkBlue, x + 6, y - 3);
		img->MakeTransparent(img->GetPixel(0, 0));

	}
	
	void setMostar(Graphics^ g, Bitmap^ img) {
		Mostrar(g, img);
	}
	void Mover(int ancho1,int alto1, int index) {
		if (index == 1) {
			if (y + alto + dy > alto1-100 || y < 0+100) dy *= -1;

			if (dy > 0) {
				fila = 0;
			}
			else fila = 3;

			y += dy;
		}
		else {
			if (x + ancho + dx > ancho1-100 || x < 0) { dx *= -1; setXY(); }

			if (dx > 0) {
				fila = 2;
			}
			else fila = 1;
			x += dx;
		}

		columna++;
		if (columna == c_columnas) {
			columna = 0;
		}

	}
	void agregar_Bala(int index) {
		balas->agregar_Bala(index,dy,dx,x,y,ancho,alto);
	
	}
	void eliminar_bala(int pos) {
		balas->eliminar_bala(pos);
	}
	void mostrar_balaene(Graphics^ g) {
		balas->mostrar_balaene(g);
	}
	void moverbala_ene() {
		balas->moverbala_ene();
	}
	int getCantBalasEne1() {
		return balas->getCantBalasEne1();
	}
	BalaEnemigos1* getBalita1(int i) {
		return balas->getBalita1(i);
	}

};