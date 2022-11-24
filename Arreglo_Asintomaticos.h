#pragma once
#include"Asintomatico.h"
#include<fstream>
class Arreglo_Asintomaticos {
private:
	Asintomatico** ene;
	int cant_asintomatico;

public:
	Arreglo_Asintomaticos(){
		cant_asintomatico = 0;
		ene = new Asintomatico * [cant_asintomatico];
	}
	int getcantidad_asintomatico() {
		return cant_asintomatico;
	}
	Asintomatico*getAsintomatico(int pos){
		return ene[pos];
	}
	void agregar_asintomatico(int n) {

		for (int m = 0; m < n; ++m) {
			Asintomatico** tmp = new Asintomatico * [cant_asintomatico + 1];
			for (int i = 0; i < cant_asintomatico; ++i)
				tmp[i] = ene[i];
			tmp[cant_asintomatico] = new Asintomatico();
			ene = tmp;
			cant_asintomatico++;


		}
	}
	void eliminar_asintomatico(int pos) {
		Asintomatico** aux = new Asintomatico * [cant_asintomatico - 1];
		delete ene[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = ene[i];
		for (int i = pos; i < cant_asintomatico - 1; ++i)
			aux[i] = ene[i + 1];


		cant_asintomatico--;
		ene = aux;
	}
	void mostrar_asintomatico(Graphics^ g, Bitmap^ img, Bitmap^b) {
		for (int i = 0; i < cant_asintomatico; ++i) {
			ene[i]->Mostrar(g, img);
			
			ene[i]->mostrar_balaene(g,b);

		}
	}

	void guardarTodo() {
		std::ofstream archivo("Asintomatico1.txt");

		for (int i = 0; i < cant_asintomatico; ++i) {

			archivo << ene[i]->getX() << " " << ene[i]->getY() << " " << ene[i]->getCantBalasEne() << " " << ene[i]->getDX() << " " << ene[i]->getDY() <<" "<< getcantidad_asintomatico()<< std::endl;
		}
		archivo.close();
	}
	

};
