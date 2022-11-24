#pragma once
#include"BalaEnemigos1.h"
class Arreglo_Bala_Saludable {
private:
	BalaEnemigos1** balaene1;
	int cant;
public:
	Arreglo_Bala_Saludable() {

		cant = 0;
		balaene1 = new BalaEnemigos1 * [cant];
	}

	void agregar_Bala(int index,int dy,int dx,int x,int y,int ancho,int alto) {
		BalaEnemigos1** aux = new BalaEnemigos1 * [cant + 1];

		for (int i = 0; i < cant; ++i)

			aux[i] = balaene1[i];

		int dx1 = 0, dy1 = 0;
	
		if (index == 1) {
			if (dy > 0) {
				dy1 += 20;
			}
			else {
				dy1 -= 20;
			}
		}
		else {
			if (dx > 0) {
				dx1 += 20;
			}
			else {
				dx1 -= 20;
			}
		}


		aux[cant] = new BalaEnemigos1(x + ancho / 2, y + alto / 2, dx1, dy1);

		balaene1 = aux;
		cant++;


	}


	void eliminar_bala(int pos) {
		BalaEnemigos1** aux = new BalaEnemigos1 * [cant - 1];
		delete balaene1[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = balaene1[i];
		for (int i = pos; i < cant - 1; ++i)
			aux[i] = balaene1[i + 1];


		cant--;
		balaene1 = aux;
	}
	void mostrar_balaene(Graphics^ g) {
		for (int i = 0; i < cant; ++i) {

			balaene1[i]->mostrar(g);
		}
	}
	void moverbala_ene() {
		for (int i = 0; i < cant; ++i) {

			balaene1[i]->mover();
		}
	}
	BalaEnemigos1* getBalita1(int i) {
		return balaene1[i];
	}

	int getCantBalasEne1() {
		return cant;
	}


};