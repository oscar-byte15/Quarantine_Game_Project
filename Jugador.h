#pragma once
#include"Entidad.h"
#include"Arreglo_BalaJugador.h"
#include<ctime>
#include<fstream>
using namespace System;
class Jugador :public Entidad {
private:
	
	Arreglo_Bala_Jugador* balas;
	Direccion direccion;
	int vidas;
public:
	Jugador(int vidas) {
		Random j;
		x = 100;
		y = 290;
	
		this->vidas = vidas;
		dx = dy = 11;
		fila = columna = 0;
		balas = new Arreglo_Bala_Jugador();

		c_filas = 4;
		c_columnas = 5;
		
		direccion = Direccion::Izquierda;
	}
	~Jugador() {
		delete balas;
	}


	Bala*getBala(int pos) {
		return balas->getBala(pos);
	 }
	int getVidas() {
		return vidas;
	}
	void restarvida() {
		vidas--;
	}
	void agregar_bala(double fx,double fy) {
		balas->agregar_bala(/*direccion*/x,y,fx,fy,ancho,alto);
	}
	void mostrar_bala(Graphics^ g,Bitmap^img) {
		balas->mostrar_bala(g,img);
	}
	void mover_bala(int ancho1,int alto1) {
		balas->mover_bala();
	
	}
	
	void eliminar_bala(int pos) {
		balas->eliminar_bala(pos);
	}
	int getCantidad_Balas() {
		return balas->getCantidad_Balas();
	}
	


	void Mostrar(Graphics^ g, Bitmap^ img) {
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
	void setVidas(int v) { vidas = v; }
	void Mover(Direccion direccion, int ancho1,int alto1) {

		switch (direccion) {

		case Direccion::Arriba:
			if (y - dy > 0)
				y -= dy;

			this->direccion = Direccion::Arriba;
			fila = 2;
			break;
		case Direccion::Abajo:
			if (y + alto + dy < alto1)
				y += dy;
			this->direccion = Direccion::Abajo;
			fila = 3;
			break;

		case Direccion::Derecha:
			if (x + ancho + dx < ancho1)
				x += dx;
			this->direccion = Direccion::Derecha;
			fila = 1;
			break;

		case Direccion::Izquierda:
			if (x - dx > 0)
				x -= dx;
			this->direccion = Direccion::Izquierda;
			fila = 0;
			break;
		}
	}
	void GuardarTodo() {
		std::ofstream archivo("Jugador1.txt");

		archivo << x << " " << y << " " <<balas->getCantidad_Balas() <<" "<< dx << " " << dy <<" "<<vidas<< std::endl;
		archivo.close();
	}


};