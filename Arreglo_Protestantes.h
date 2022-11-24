#pragma once
#include"Protestantes.h"
#include<fstream>
class Arreglo_Protestantes{
private:
	Protestantes** pro;
	int cant_pro;
public:
	Arreglo_Protestantes(){
		cant_pro = 0;
		pro = new Protestantes * [cant_pro];
	}
	void agregar_protestantes(int n) {
		for (int m = 0; m < n; ++m) {
			Protestantes** tmp = new Protestantes * [cant_pro + 1];
			for (int i = 0; i < cant_pro; ++i)
				tmp[i] = pro[i];
			tmp[cant_pro] = new Protestantes(15, 15);
			pro = tmp;
			cant_pro++;


		}
	}
	int getCantidad_Protestantes() {
		return cant_pro;
	}
	Protestantes* getProtestante(int pos){
		return pro[pos];
	}

	void mostrar_Protestantes(Graphics^ g, Bitmap^ img) {
		for (int i = 0; i < cant_pro; ++i) {
			pro[i]->Mostrar(g, img);
		}
	}

	void mover_protestantes(int ancho1) {
		for (int i = 0; i < cant_pro; ++i) {
			pro[i]->Mover(ancho1);
		}
	}
	void eliminar_ciudadano(int pos) {
		Protestantes** aux = new Protestantes * [cant_pro - 1];
		delete pro[pos];
		for (int j = 0; j < pos; ++j)
			aux[j] = pro[j];

		for (int i = pos; i < cant_pro - 1; ++i)
			aux[i] = pro[i + 1];

		cant_pro--;
		pro = aux;

	}

	void guardarTodo() {
		std::ofstream archivo("Protestante1.txt");

		for (int i = 0; i < cant_pro; ++i) {

			archivo << pro[i]->getX() << " " << pro[i]->getY() << " " << pro[i]->getDX() << " " << pro[i]->getDY() <<" "<< getCantidad_Protestantes()<< std::endl;
		}
		archivo.close();
	}




};