#pragma once
#include"Bala_Jugador.h"
class Arreglo_Bala_Jugador {
private:
	Bala** bala;
	int cant;

public:
	Arreglo_Bala_Jugador() {

		cant = 0;
		bala = new Bala * [cant];

	}
	Bala* getBala(int i) {
		return bala[i];
	}
	int getCantidad_Balas() {
		return cant;
	}
	
	void agregar_bala(/*Direccion direccion,*/ int x, int y,double fx,double fy,int ancho,int alto) {
		//ancho y alto del jugador
		Bala** aux = new Bala * [cant + 1];
		for (int i = 0; i < cant; ++i)
			aux[i] = bala[i];
		x = x + ancho / 2;
		y = y + (alto / 2);
		double c1 = fx - x;
		double c2 = fy - y;
		double hipo = Math::Sqrt((c1 * c1) + (c2 * c2));
		double V = 40;
		double constante = V / hipo;
		double dx = constante * c1;
		double dy = constante * c2;
		/*int dx = 0, dy = 0;
		switch (direccion) {
		case Direccion::Arriba: dy -= 20;
			break;
		case Direccion::Abajo:dy += 20;
			break;
		case Direccion::Derecha:dx += 20;
			break;
		case Direccion::Izquierda:dx -= 20;
			break;

		}*/

		aux[cant] = new Bala(x,y, dx, dy);



		bala = aux;
		cant++;
	}
	void eliminar_bala(int pos) {
		Bala** aux = new Bala * [cant - 1];
		delete bala[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = bala[i];
		for (int i = pos; i < cant - 1; ++i)
			aux[i] = bala[i + 1];

		bala = aux;
		cant--;

	}

	void mostrar_bala(Graphics^ g,Bitmap^img) {
		for (int i = 0; i < cant; ++i) {
			bala[i]->mostrar(g,img);
		}
	}



	void mover_bala() {

		for (int i = 0; i < cant; ++i) {
			bala[i]->mover();
		}


	}



};