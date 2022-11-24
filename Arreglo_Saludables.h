#pragma once
#include"Saludable.h"
#include<fstream>
#include<iostream>
class Arreglo_Saludables{
private:
	Saludable** salu;
	int cant_saludable;

public:
	Arreglo_Saludables(){
		cant_saludable = 0;
		salu = new Saludable * [cant_saludable];
	}
	int getcantidad_saludable() {
		return cant_saludable;
	}
	Saludable* getSaludable(int pos) {
		return salu[pos];
	}
	void mostrar_Saludable(Graphics^ g, Bitmap^ img) {
		for (int i = 0; i < cant_saludable; ++i) {
			salu[i]->Mostrar(g, img);

			salu[i]->mostrar_balaene(g);
		}
	}
	void agregar_Saludable(int n) {
		Random j;
		for (int m = 0; m < n; ++m) {
			Saludable** tmp = new Saludable * [cant_saludable + 1];
			for (int i = 0; i < cant_saludable; ++i)
				tmp[i] = salu[i];
			tmp[cant_saludable] = new Saludable(j.Next(800, 1000), j.Next(200, 300));
			System::Threading::Thread::Sleep(30);
			salu = tmp;
			cant_saludable++;


		}
	}
	void eliminar_Saludable(int pos) {
		Saludable** aux = new Saludable * [cant_saludable - 1];
		delete salu[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = salu[i];
		for (int i = pos; i < cant_saludable - 1; ++i)
			aux[i] = salu[i + 1];


		cant_saludable--;
		salu = aux;
	}

	void guardarTodo() {
		std::ofstream archivo("Saludable1.txt");
		
		for (int i = 0; i < cant_saludable; ++i) {
			
			archivo << salu[i]->getX() << " " << salu[i]->getY() << " " << salu[i]->getCantBalasEne1() << " " << salu[i]->getDX() << " " << salu[i]->getDY() << " " << getcantidad_saludable()<<  std::endl;
		}
		archivo.close();
	}


};