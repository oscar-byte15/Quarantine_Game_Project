#pragma once
#include"Balas_Enemigos.h"
class Arreglo_Balas_Asinto {
private:
	Balaenemigo** balaene;
	int cant;

public:
	Arreglo_Balas_Asinto() {

		cant = 0;
		balaene = new Balaenemigo * [cant];
	}
	void agregar_Bala(Direccion direccion,int x, int y,int ancho,int alto) {
		Balaenemigo** aux = new Balaenemigo * [cant + 1];

		for (int i = 0; i < cant; ++i)

			aux[i] = balaene[i];
		System::Threading::Thread::Sleep(10);
		int dx = 0, dy = 0;
		//son nuevos para que no confunda con el dx y dy del jugador
		switch (direccion) {
		case Direccion::Arriba: dy -= 19;
			break;
		case Direccion::Abajo:dy += 19;
			break;
		case Direccion::Derecha:dx += 19;
			break;
		case Direccion::Izquierda:dx -= 19;
			break;

		}

		aux[cant] = new Balaenemigo(x + ancho / 2, y + alto / 2, dx, dy);

		balaene = aux;
		cant++;


	}
	void eliminar_bala(int pos) {
		Balaenemigo** aux = new Balaenemigo * [cant - 1];
		delete balaene[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = balaene[i];
		for (int i = pos; i < cant - 1; ++i)
			aux[i] = balaene[i + 1];


		cant--;
		balaene = aux;
	}

	void mostrar_balaene(Graphics^ g,Bitmap^img) {
		for (int i = 0; i < cant; ++i) {

			balaene[i]->mostrar(g,img);
		}
	}
	void moverbala_ene() {
		for (int i = 0; i < cant; ++i) {

			balaene[i]->mover();
		}
	}
	Balaenemigo* getBalita(int i) {
		return balaene[i];
	}

	int getCantBalasEne() {
		return cant;
	}

};