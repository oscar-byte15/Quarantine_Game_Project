#pragma once
#include"Entidad.h"
#include"Arreglo_Balas_Asinto.h"
using namespace System;
class Asintomatico :public Entidad {
private:

	Direccion direccion;
	Arreglo_Balas_Asinto* balas;
public:
	Asintomatico() {
		Random j;
		x = j.Next(200, 1000);
		System::Threading::Thread::Sleep(40);
		y = j.Next(200, 680);
		System::Threading::Thread::Sleep(40);
		dx = 5;
	
		dy = 5;
	
		fila = columna = 0;
		balas = new Arreglo_Balas_Asinto();

	}
	~Asintomatico() {
		delete balas;
	}

	void setDxs() {
		dx = 0;
		dy = 0;
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		alto = img->Height / 4;
		ancho = img->Width / 3;
		
		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		img->MakeTransparent(img->GetPixel(0, 0));
		columna++;
		if (columna == 3) {
			columna = 0;
		}
	}
	void setMostrar(Graphics^ g, Bitmap^ img) {
		Mostrar(g, img);
	}
	void Mover(Direccion direccion, int ancho1,int alto1) {

		switch (direccion) {

		case Direccion::Arriba:
			if (y - dy > 0)
				y -= dy;
			this->direccion = Direccion::Arriba;
			fila = 3;
			break;
		case Direccion::Abajo:
			if (y + alto + dy < alto1)
				y += dy;
			this->direccion = Direccion::Abajo;
			fila = 0;
			break;

		case Direccion::Derecha:
			if (x + ancho + dx < ancho1)
				x += dx;
			this->direccion = Direccion::Derecha;
			fila = 2;
			break;

		case Direccion::Izquierda:
			if (x - dx > 0)
				x -= dx;
			this->direccion = Direccion::Izquierda;
			fila = 1;
			break;
		}
	}
	void agregar_Bala() {
		balas->agregar_Bala(direccion,x,y,ancho,alto);
	}
	void eliminar_bala(int pos) {
		balas->eliminar_bala(pos);
	}
	void mostrar_balaene(Graphics^ g,Bitmap^img) {
		balas->mostrar_balaene(g,img);
	}
	void moverbala_ene() {
		balas->moverbala_ene();
	}
	int getCantBalasEne() {
		return balas->getCantBalasEne();
	}
	Balaenemigo* getBalita(int i) {
		return balas->getBalita(i);
	}


};