#pragma once
#include"Jugador.h"
#include"Ambulancia.h"
#include"Arreglo_Asintomaticos.h"
#include"Arreglo_Saludables.h"
#include"Arreglo_Protestantes.h"
#include"Policia.h"

using namespace System::Windows::Forms;
class Juego_Principiante {
	Jugador* jugador;
	Ambulancia* ambu;
	Policia* poli;
	Arreglo_Asintomaticos* ene;
	Arreglo_Saludables* salu;
	Arreglo_Protestantes* pro;

	int puntos;
	int tiempo;
	int cont;
	int cont1;
	clock_t inicio;

	int cool_down_asi;
	int cool_down_salu;
	bool rojo;
	bool verde;


	int pos_saludable;
	int pos_asinto;
	int capturados;


public:
	Juego_Principiante(int tiempo_inicial, int vidas) {
	
		cool_down_asi = 0;
		cool_down_salu = 0;
	
		jugador = new Jugador(vidas);
		ambu = new Ambulancia();
		poli = new Policia();
	
		ene = new Arreglo_Asintomaticos();
		salu = new Arreglo_Saludables();
		pro = new Arreglo_Protestantes();
		tiempo = tiempo_inicial;

		pos_saludable = 0;
		cont = 0;
		cont1 = 0;
		puntos = 0;
		capturados = 0;
		pro->agregar_protestantes(4);
	}

	~Juego_Principiante() {
		jugador = nullptr;
		ambu = nullptr;
		poli = nullptr;
		ene = nullptr;
		salu = nullptr;
		pro = nullptr;
	
	}

	void GuardarTodo() {
		jugador->GuardarTodo();
		ambu->GuardarTodo();
		poli->GuardarTodo();
		ene->guardarTodo();
		salu->guardarTodo();
		pro->guardarTodo();
	}
	void mostrar_Protestantes(Graphics^ g, Bitmap^ img) {
		pro->mostrar_Protestantes(g,img);
	}
	void mover_protestantes(int ancho1) {
		pro->mover_protestantes(ancho1);
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//1.- GENERAL
	

	int getPuntos() {
		return puntos;

	}

	int getContador() {
		return cont;
	}
	int getContador1() {
		return cont1;
	}
	int getvidasJugador() {
		return jugador->getVidas();
	}
	int getCapturados() {
		return capturados;
	}
	int Tiempo() {


		if ((double(clock() - inicio) / CLOCKS_PER_SEC) >= 1)
		{
			cool_down_asi++;
			cool_down_salu++;
			tiempo--;
			inicio = clock();
		}

		return tiempo;

	}
	void Tiempo_asintomatico() {

		if (cool_down_asi == 3) {
			cont++;
			ene->agregar_asintomatico(1);
		}
		if (cool_down_asi == 3) {
			cool_down_asi = 0;

		}

	}

	void Tiempo_saludable() {
		if (cool_down_salu == 3) {
			cont1++;
			salu->agregar_Saludable(1);
		}
		if (cool_down_salu == 3) {
			cool_down_salu = 0;

		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//2.-JUGADOR
	void disparar(double fx, double fy) {
		jugador->agregar_bala(fx,fy);
	}
	


	void Mostrar_jugador(Graphics^ g, Bitmap^ img, Bitmap^ bala) {

		jugador->Mostrar(g, img);
		//2.disparar mostrar
		jugador->mostrar_bala(g,bala);
	}

	void Mover_jugador(Keys key, int ancho, int alto) {

		if (key == Keys::Up) {
			jugador->Mover(Direccion::Arriba, ancho, alto);
		}
		else if (key == Keys::Down) {
			jugador->Mover(Direccion::Abajo, ancho, alto);
		}
		else if (key == Keys::Right) {
			jugador->Mover(Direccion::Derecha, ancho, alto);
		}
		else if (key == Keys::Left) {
			jugador->Mover(Direccion::Izquierda, ancho, alto);
		}

	}


	//3.- asintomatico
	void mover_asintomatico(int ancho1,int alto1) {
		for (int i = 0; i < ene->getcantidad_asintomatico(); ++i) {
			if (ene->getAsintomatico(i)->getX() - 1 > jugador->getX()) {
				ene->getAsintomatico(i)->Mover(Direccion::Izquierda, ancho1,alto1);

			}
			else if (ene->getAsintomatico(i)->getX() < jugador->getX()) {
				ene->getAsintomatico(i)->Mover(Direccion::Derecha, ancho1, alto1);

			}
			else if (ene->getAsintomatico(i)->getY() - 1 > jugador->getY()) {
				ene->getAsintomatico(i)->Mover(Direccion::Arriba, ancho1, alto1);
			}
			else if (ene->getAsintomatico(i)->getY() < jugador->getY()) {
				ene->getAsintomatico(i)->Mover(Direccion::Abajo, ancho1, alto1);
			}

			jugador->mover_bala(ancho1,alto1);
		}
	}
	void mostrar_asintomatico(Graphics^ g, Bitmap^ img,Bitmap^b) {
		ene->mostrar_asintomatico(g, img,b);
	}



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//4.-Saludable
	void mover_Saludable(int ancho1, int alto1) {
		for (int i = 0; i < salu->getcantidad_saludable(); ++i) {
			salu->getSaludable(i)->Mover(ancho1, alto1, 1);
		
		}
	}
	void mostrar_Saludable(Graphics^ g, Bitmap^ img) {
		salu->mostrar_Saludable(g, img);
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//5.- AMBULANCIA
	void Mostrar_ambulancia1(Graphics^ g, Bitmap^ img) {
		ambu->mostrar_ambulnacia(g, img);
	}

	void Mover_ambulncia1(int ancho_form,int alto_form, int pos) {

		if (ene->getAsintomatico(pos)->getX() >= ambu->getX() + 2) {
			ambu->mover_ambulancia(Direccion::Derecha, ancho_form,alto_form);

		}
		else if (ene->getAsintomatico(pos)->getX() + 2 <= ambu->getX() - 2) {
			ambu->mover_ambulancia(Direccion::Izquierda, ancho_form, alto_form);

		}
		else if (ene->getAsintomatico(pos)->getY() >= ambu->getY()) {
			ambu->mover_ambulancia(Direccion::Abajo, ancho_form, alto_form);
		}
		else if (ene->getAsintomatico(pos)->getY() <= ambu->getY()) {
			ambu->mover_ambulancia(Direccion::Arriba, ancho_form, alto_form);
		}



	}

	void colisionambulancia_asi(Graphics^ g, Bitmap^ img,int ancho_form,int alto_form) {
		Rectangle asinto;
		Rectangle ambulancia;
		if (getRojo() == true) {
			Mostrar_ambulancia1(g, img);
			Mover_ambulncia1(ancho_form,alto_form, pos_asinto);
			ambulancia = Rectangle(ambu->getX(), ambu->getY(), ambu->getAncho(), ambu->getAlto());
			asinto = Rectangle(ene->getAsintomatico(getPos_Asinotmatico())->getX(), ene->getAsintomatico(getPos_Asinotmatico())->getY(), ene->getAsintomatico(getPos_Asinotmatico())->getAncho(), ene->getAsintomatico(getPos_Asinotmatico())->getAlto());

			if (ambulancia.IntersectsWith(asinto)) {
				rojo = false;
				capturados++;
				ene->eliminar_asintomatico(pos_asinto);
				ambu->setXY();
			}
		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//6.- Policia

	void Mostrar_Policia(Graphics^ g, Bitmap^ img) {
		poli->mostrar_Policia(g, img);
	}


	void Mover_Policia(int ancho1, int alto1, int pos) {

		if (salu->getSaludable(pos)->getX() > poli->getX()) {
			poli->mover_Policia(Direccion::Derecha, ancho1, alto1);

		}
		
		else if (salu->getSaludable(pos)->getY() > poli->getY()) {
			poli->mover_Policia(Direccion::Abajo, ancho1, alto1);
		}
		else if (salu->getSaludable(pos)->getY() < poli->getY()) {
			poli->mover_Policia(Direccion::Arriba, ancho1, alto1);
		}

	}
	bool getVerde() {
		return verde;
	}
	int getSaludable() {
		return pos_saludable;
	}
	int getPos_Asinotmatico() {
		return pos_asinto;
	}
	bool getRojo() {
		return rojo;
	}
	void cambiar_rojo(Graphics^ g, Bitmap^ img) {
		if (getRojo() == true) {
			ene->getAsintomatico(getPos_Asinotmatico())->setMostrar(g, img);
		}
	}
	void cambiar_verde(Graphics^ g, Bitmap^ img) {
		if (getVerde() == true) {
			salu->getSaludable(getSaludable())->setMostar(g, img);
		}
	}
	void colision_policia_saludable(Graphics^ g, Bitmap^ img, int ancho1,int alto1) {
		Rectangle saludable;
		Rectangle policia;


		if (getVerde() == true) {
			Mostrar_Policia(g, img);
			Mover_Policia(ancho1,alto1, pos_saludable);
			policia = Rectangle(poli->getX(), poli->getY(), poli->getAncho(), poli->getAlto());
			saludable = Rectangle(salu->getSaludable(getSaludable())->getX(), salu->getSaludable(getSaludable())->getY(), salu->getSaludable(getSaludable())->getAncho(), salu->getSaludable(getSaludable())->getAlto());

			if (policia.IntersectsWith(saludable)) {

				verde = false;
				capturados++;


				salu->eliminar_Saludable(pos_saludable);
				poli->setXY();
			}
		}

	}



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//7.- COLISONES
	void colision_jugador_asi() {
		Rectangle juga;
		Rectangle Asinto;
		for (int i = 0; i < ene->getcantidad_asintomatico(); ++i) {
			juga = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());
			Asinto = Rectangle(ene->getAsintomatico(i)->getX(), ene->getAsintomatico(i)->getY(), ene->getAsintomatico(i)->getAncho(), ene->getAsintomatico(i)->getAlto());
			if (juga.IntersectsWith(Asinto)) {
				jugador->restarvida();
			}
		}
	}
	void colision_jugador_salu() {
		Rectangle juga;
		Rectangle saludab;
		for (int i = 0; i < salu->getcantidad_saludable(); ++i) {
			juga = Rectangle(jugador->getX(), jugador->getY(), jugador->getAncho(), jugador->getAlto());
			saludab = Rectangle(salu->getSaludable(i)->getX(), salu->getSaludable(i)->getY(), salu->getSaludable(i)->getAncho(), salu->getSaludable(i)->getAlto());
			if (juga.IntersectsWith(saludab)) {
				jugador->restarvida();
			}
		}
	}


	void colision_balas_jugador_saludable() {
		Rectangle bala;
		Rectangle saludable;
		Bala* BALA;
		for (int b = 0; b < jugador->getCantidad_Balas(); ++b) {
			BALA = jugador->getBala(b);

			bala = Rectangle(BALA->getX(), BALA->getY(), BALA->getAncho(), BALA->getAlto());
			for (int sa = 0; sa < salu->getcantidad_saludable(); ++sa) {
				saludable = Rectangle(salu->getSaludable(sa)->getX(), salu->getSaludable(sa)->getY(), salu->getSaludable(sa)->getAncho(), salu->getSaludable(sa)->getAlto());


				if (bala.IntersectsWith(saludable)) {
					verde = true;

					puntos += 10;
					jugador->eliminar_bala(b--);
					pos_saludable = sa;
				}

			}

		}


	}
	void colision_balas_jugador_asi() {

		Rectangle bala;//jugador

		Rectangle enemy;
		Bala* BALA;

		for (int b = 0; b < jugador->getCantidad_Balas(); ++b)
		{
			BALA = jugador->getBala(b);

			bala = Rectangle(BALA->getX(), BALA->getY(), BALA->getAncho(), BALA->getAlto());
			for (int zelda = 0; zelda < ene->getcantidad_asintomatico(); ++zelda)
			{

				enemy = Rectangle(ene->getAsintomatico(zelda)->getX(), ene->getAsintomatico(zelda)->getY(), ene->getAsintomatico(zelda)->getAncho(), ene->getAsintomatico(zelda)->getAlto());
				if (bala.IntersectsWith(enemy))
				{
					rojo = true;
					pos_asinto = zelda;
					jugador->eliminar_bala(b--);

					puntos += 10;

				}


			}

		}


	}



};